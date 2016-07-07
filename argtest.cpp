#include <iostream>
#include "RtMidi.h"
#include "CmdLine.h"

using namespace std;

int main() {

    std::string version("0.1");

    TCLAP::CmdLine cmd = ("Chorder - chord deployer", ' ', version);


    TCLAP::ValueArg<std::string> nameArg("n","name","Name to print",true,"homer","string");
}
