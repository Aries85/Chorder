#include <iostream>
#include <RtMidi.h>
#include <tclap/CmdLine.h>
#include "main.h"
#include "utils.h"

using namespace std;

struct callback_data {
    RtMidiOut *midiOut;
    chordTypes currentChord = MAJOR;
    int outputChordTransposition = -12;
    int numberOfSubRoots = 1; // number of root notes below chord (each one is one octave lower)
    std::vector< std::vector<unsigned char> > notesTurnedOn;
};

void printListOfDevices() {
    RtMidiIn  *midiin = 0;
    RtMidiOut *midiout = 0;
    // RtMidiIn constructor
    try {
        midiin = new RtMidiIn();
    }
    catch ( RtMidiError &error ) {
        error.printMessage();
        exit( EXIT_FAILURE );
    }
    // Check inputs.
    unsigned int nPorts = midiin->getPortCount();
    std::cout <<  nPorts << " MIDI inputs available.\n";
    std::string portName;
    for ( unsigned int i=0; i<nPorts; i++ ) {
        try {
            portName = midiin->getPortName(i);
        }
        catch ( RtMidiError &error ) {
            error.printMessage();
            goto cleanup;
        }
        std::cout << "  Input Port #" << i << ": " << portName << '\n';
    }
    std::cout << std::endl << std::endl;

    // RtMidiOut constructor
    try {
        midiout = new RtMidiOut();
    }
    catch ( RtMidiError &error ) {
        error.printMessage();
        exit( EXIT_FAILURE );
    }
    // Check outputs.
    nPorts = midiout->getPortCount();
    std::cout << nPorts << " MIDI outputs available.\n";
    for ( unsigned int i=0; i<nPorts; i++ ) {
        try {
            portName = midiout->getPortName(i);
        }
        catch (RtMidiError &error) {
            error.printMessage();
            goto cleanup;
        }
        std::cout << "  Output Port #" << i << ": " << portName << '\n';
    }
    std::cout << '\n';
    // Clean up
    cleanup:
    delete midiin;
    delete midiout;
}

void midiInCallback(double deltatime, std::vector<unsigned char> *message, void *userData)
{

    unsigned int nBytes = message->size();

    /* for ( unsigned int i=0; i<nBytes; i++ )
        std::cout << "Byte " << i << " = " << (int)message->at(i) << ", ";
    if ( nBytes > 0 )
        std::cout << "stamp = " << deltatime << std::endl; */

    if (nBytes != 3) {
        // Note On message has 3 bytes
        return;
    }

    if (!isNoteMessage(message->at(0))) {
        return;
    }

    std::cout << "Note message" << std::endl;

    unsigned char noteEvent = message->at(0);
    unsigned char noteNumber = message->at(1);
    unsigned char noteVelocity = message->at(2);

    // TODO - set by size of chord array
    if (noteNumber < (NUMBER_OF_CHORDS + 1)) {
        return;
    }

    callback_data* callBackData = static_cast<callback_data *>(userData);

    std::cout << "Note number " << (int)noteNumber << std::endl;

    if (noteNumber < 75) {
        std::cout << "Chord selected: " << noteNumber - (NUMBER_OF_CHORDS + 1) << std::endl;
       callBackData->currentChord = static_cast<chordTypes>(noteNumber - (NUMBER_OF_CHORDS + 1));

        //std::cout << "Chord saved: " << callBackData->currentChord << std::endl;
    } else {
        /*
         * When chord has been changed during holding accord, it is necessary to mute notes from previous accord.
         * Iterate over all played notes and mute them
         */
        for (auto &&noteOnMidiMessage : callBackData->notesTurnedOn) {
            std::vector<unsigned char> messageToSend(noteOnMidiMessage); // keep original data
            messageToSend.at(0) = (messageToSend.at(0) & BOOST_BINARY(00001111)) | BOOST_BINARY(10000000); // change to note off
            callBackData->midiOut->sendMessage(&messageToSend);
        }



        std::vector< std::vector<unsigned char> > notesTurnedOn;
        std::vector< std::vector<unsigned char> > notesToSend;

        vector<int> &noteArray = chords[callBackData->currentChord];
        //std::cout << "Chord notes " << noteArray.size();
        for (auto &&noteDelta : noteArray) {
            std::vector<unsigned char> messagesToSend;
            messagesToSend.push_back(noteEvent); // keep original channel
            messagesToSend.push_back(noteNumber + noteDelta + callBackData->outputChordTransposition);
            messagesToSend.push_back(noteVelocity);

            notesToSend.push_back(messagesToSend);

            if (isNoteOnMessage(noteEvent)) {
                notesTurnedOn.push_back(messagesToSend);
            }
        }


        std::cout << "Sub roots: " << callBackData->numberOfSubRoots << std::endl;
        for (unsigned char i = 1; i <= callBackData->numberOfSubRoots; i++) {
            std::cout << "Subroot" << noteNumber + callBackData->outputChordTransposition - (12 * i) << std::endl;
            std::vector<unsigned char> messagesToSend;
            messagesToSend.push_back(noteEvent); // keep original channel
            messagesToSend.push_back(noteNumber + callBackData->outputChordTransposition - (12 * i));
            messagesToSend.push_back(noteVelocity);

            notesToSend.push_back(messagesToSend);

            if (isNoteOnMessage(noteEvent)) {
                notesTurnedOn.push_back(messagesToSend);
            }

        }

        // save notes for case when chord is changed during note hold
        callBackData->notesTurnedOn = notesTurnedOn;

        for (auto &&noteMidiMessage : notesToSend) {
            callBackData->midiOut->sendMessage(&noteMidiMessage);
        }

    }


}


int main(int argc, const char** argv) {

    /*std::cout << "\nProgram will continue after pressing Enter ... \n";
    char input;
    std::cin.get(input); */

    std::string version ("0.1");

    TCLAP::CmdLine cmd ("Chorder - chord deployer", ' ', version);

    TCLAP::SwitchArg argListDevices("l", "list-devices", "List available MIDI devices", cmd, false, NULL);
    TCLAP::ValueArg<int> argInputDevice("i", "input", "Input MIDI Device", false, -1, "number", cmd);
    TCLAP::ValueArg<int> argOutputDevice("o", "output", "Output MIDI Device", false, -1, "number", cmd);
    TCLAP::ValueArg<int> argSubRoots("s", "sub-roots", "Number of sub-roots", false, 2, "number", cmd);
    TCLAP::ValueArg<int> argChordTransposition("t", "chord-transposition", "Transposition of chord notes", false, -12, "number", cmd);

    if (argc < 2) {
        std::cout << "Incorrect parameters. For help run with -h parameter" << std::endl;
        return 0;
    }

    cmd.parse(argc, argv);

    if (cmd.getArgList().size() == 0) {
        std::cout << cmd.getMessage() << std::endl;

        return 0;
    }

    bool listDevices = argListDevices.getValue();
    int inputPort = argInputDevice.getValue();
    int outputPort = argOutputDevice.getValue();
    int subRoots = argSubRoots.getValue();
    int chordTransposition = argChordTransposition.getValue();

    if (listDevices) {
        printListOfDevices();
        return 0;
    }

    cout << "Selected input # " << inputPort << std::endl;
    cout << "Selected output # " << outputPort << std::endl;

    // parameters passed, let's do it!


    RtMidiIn *midiin = 0;
    RtMidiOut *midiout = 0;

    try {
        midiin = new RtMidiIn();
    }
    catch ( RtMidiError &error ) {
        error.printMessage();
        exit( EXIT_FAILURE );
    }

    try {
        midiout = new RtMidiOut();
    }
    catch ( RtMidiError &error ) {
        error.printMessage();
        exit( EXIT_FAILURE );
    }

    callback_data cb_data;
    cb_data.midiOut = midiout;
    cb_data.numberOfSubRoots = subRoots;
    cb_data.outputChordTransposition = chordTransposition;

    unsigned int numInputPorts = midiin->getPortCount();
    unsigned int numOutputPorts = midiout->getPortCount();

    bool invalidInput = false;

    if (inputPort > numInputPorts) {
        std::cerr << "Input port " << inputPort << " specified, but only " << numInputPorts << "available." << std::endl;
        invalidInput = true;
    }
    if (outputPort > numOutputPorts) {
        std::cerr << "Output port " << outputPort << " specified, but only " << numOutputPorts << "available." << std::endl;
        invalidInput = true;
    }

    if (invalidInput) {
        return 1;
    }


    std::vector<unsigned char> outputMessages;
    midiout->openPort(outputPort);
    midiin->openPort(inputPort);
    midiin->ignoreTypes(true, true, true);
    midiin->setCallback(&midiInCallback, &cb_data);


    std::cout << "\nReading MIDI input ... press <enter> to quit.\n";
    char input;
    std::cin.get(input);

    // Clean up
    cleanup:
    delete midiin;
    delete midiout;

    return 0;

    // TODO - handle exit signal and midi object allocation;
}