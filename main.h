#ifndef RTMIDI_TEST_MAIN_H
#define RTMIDI_TEST_MAIN_H

#define NUMBER_OF_CHORDS 35

#include <array>
#include "utils.h"

enum chordTypes {
    MAJOR,
    MINOR,
    MAJOR7,
    MINOR7,
    MAJOR_MAJ_7,
    MINOR_MAJ_7,
    MAJOR_7_FLAT_5,
    MAJOR_7_SHARP_5,
    MINOR_7_FLAT_5,
    MAJOR_7_FLAT_9,
    MAJOR_FLAT_5,
    POWER,
    MAJOR_6,
    MINOR_6,
    MAJOR_69,
    MAJOR_9,
    MAJOR_9_FLAT_5,
    MAJOR_9_SHARP5,
    MINOR_9,
    MAJOR_MAJ_9,
    MAJOR_ADD_9,
    MAJOR_7_SHARP_9,
    MAJOR_11,
    MINOR_11,
    MAJOR_13,
    MAJOR_MAJ_13,
    MAJOR_SUS2,
    MAJOR_SUS4,
    MAJOR_7_SUS4,
    MAJOR_9_SUS4,
    DIMINISHED,
    HALF_DIMINISHED,
    DIMINISHED_7,
    AUGMENTED
};

int chord_major [] = {0, 4, 7};
int chord_minor [] = {0, 3, 7};
int chord_major_7 [] = {0, 4, 7, 10};
int chord_minor_7 [] = {0, 3, 7, 10};
int chord_major_maj_7 []= {0, 4, 7, 11};
int chord_minor_maj_7 [] = {0, 3, 7, 11};
int chord_major_7_flat_5 [] = {0, 4, 6, 10};
int chord_major_7_sharp_5 [] = {0, 4, 8, 10};
int chord_minor_7_flat_5 [] = {0, 3, 6, 10};
int chord_major_7_flat_9 [] = {0, 4, 7, 10, 13}; // maybe sort next to MAJOR7
int chord_major_flat_5 [] = {0, 4, 6}; // maybe next to MAJOR
int chord_power [] = {0, 7, 12};
int chord_major_6 [] = {0, 4, 7, 9};
int chord_minor_6 [] = {0, 3, 7, 9};
int chord_major_69 [] = {0, 4, 7, 9, 14};
int chord_major_9 [] = {0, 4, 7, 10, 14};
int chord_major_9_flat_5 [] = {0, 4, 6, 11, 14};
int chord_major_9_sharp_5 [] = {0, 4, 8, 14};
int chord_minor_9 [] = {0, 3, 7, 10, 14};
int chord_major_maj_9 [] = {0, 4, 7, 11, 14};
int chord_major_add_9 [] = {0, 4, 7, 14};
int chord_major_7_sharp_9 [] = {0, 4, 7, 10, 15};
int chord_major_11 [] = {0, 4, 7, 10, 14, 17};
int chord_minor_11 [] = {0, 3, 7, 10, 14, 17};
int chord_major_13 [] = {0, 10, 14, 17, 21};
int chord_major_maj_13 [] = {0, 7, 11, 14, 16, 21};
int chord_major_sus2 [] = {0, 2, 7};
int chord_major_sus4 [] = {0, 5, 7};
int chord_major_7_sus4 [] = {0, 5, 7, 10};
int chord_major_9_sus4 [] = {0, 5, 7, 10, 14};
int chord_diminished [] = {0, 3, 6};
int chord_half_diminished [] = {0, 3, 6, 10};
int chord_diminished_7 [] = {0, 3, 6, 9};
int chord_augmented [] = {0, 4, 8};

std::vector<int> vec_chord_major = arrayToVector(chord_major);
std::vector<int> vec_chord_minor = arrayToVector(chord_minor);
std::vector<int> vec_chord_major_7 = arrayToVector(chord_major_7);
std::vector<int> vec_chord_minor_7 = arrayToVector(chord_minor_7);
std::vector<int> vec_chord_major_maj_7 = arrayToVector(chord_major_maj_7);
std::vector<int> vec_chord_minor_maj_7 = arrayToVector(chord_minor_maj_7);
std::vector<int> vec_chord_major_7_flat_5 = arrayToVector(chord_major_7_flat_5);
std::vector<int> vec_chord_major_7_sharp_5 = arrayToVector(chord_major_7_sharp_5);
std::vector<int> vec_chord_minor_7_flat_5 = arrayToVector(chord_minor_7_flat_5);
std::vector<int> vec_chord_major_7_flat_9 = arrayToVector(chord_major_7_flat_9); // maybe sort next to MAJOR7
std::vector<int> vec_chord_major_flat_5 = arrayToVector(chord_major_flat_5); // maybe next to MAJOR
std::vector<int> vec_chord_power = arrayToVector(chord_power);
std::vector<int> vec_chord_major_6 = arrayToVector(chord_major_6);
std::vector<int> vec_chord_minor_6 = arrayToVector(chord_minor_6);
std::vector<int> vec_chord_major_69 = arrayToVector(chord_major_69);
std::vector<int> vec_chord_major_9 = arrayToVector(chord_major_9);
std::vector<int> vec_chord_major_9_flat_5 = arrayToVector(chord_major_9_flat_5);
std::vector<int> vec_chord_major_9_sharp_5 = arrayToVector(chord_major_9_sharp_5);
std::vector<int> vec_chord_minor_9 = arrayToVector(chord_minor_9);
std::vector<int> vec_chord_major_maj_9 = arrayToVector(chord_major_maj_9);
std::vector<int> vec_chord_major_add_9 = arrayToVector(chord_major_add_9);
std::vector<int> vec_chord_major_7_sharp_9 = arrayToVector(chord_major_7_sharp_9);
std::vector<int> vec_chord_major_11 = arrayToVector(chord_major_11);
std::vector<int> vec_chord_minor_11 = arrayToVector(chord_minor_11);
std::vector<int> vec_chord_major_13 = arrayToVector(chord_major_13);
std::vector<int> vec_chord_major_maj_13 = arrayToVector(chord_major_maj_13);
std::vector<int> vec_chord_major_sus2 = arrayToVector(chord_major_sus2);
std::vector<int> vec_chord_major_sus4 = arrayToVector(chord_major_sus4);
std::vector<int> vec_chord_major_7_sus4 = arrayToVector(chord_major_7_sus4);
std::vector<int> vec_chord_major_9_sus4 = arrayToVector(chord_major_9_sus4);
std::vector<int> vec_chord_diminished = arrayToVector(chord_diminished);
std::vector<int> vec_chord_half_diminished = arrayToVector(chord_half_diminished);
std::vector<int> vec_chord_diminished_7 = arrayToVector(chord_diminished_7);
std::vector<int> vec_chord_augmented = arrayToVector(chord_augmented);

std::vector<int> chords [NUMBER_OF_CHORDS] = {
        vec_chord_major,
        vec_chord_minor,
        vec_chord_major_7,
        vec_chord_minor_7,
        vec_chord_major_maj_7,
        vec_chord_minor_maj_7,
        vec_chord_major_7_flat_5,
        vec_chord_major_7_sharp_5,
        vec_chord_minor_7_flat_5,
        vec_chord_major_7_flat_9,
        vec_chord_major_flat_5,
        vec_chord_power,
        vec_chord_major_6,
        vec_chord_minor_6,
        vec_chord_major_69,
        vec_chord_major_9,
        vec_chord_major_9_flat_5,
        vec_chord_major_9_sharp_5,
        vec_chord_minor_9,
        vec_chord_major_maj_9,
        vec_chord_major_add_9,
        vec_chord_major_7_sharp_9,
        vec_chord_major_11,
        vec_chord_minor_11,
        vec_chord_major_13,
        vec_chord_major_maj_13,
        vec_chord_major_sus2,
        vec_chord_major_sus4,
        vec_chord_major_7_sus4,
        vec_chord_major_9_sus4,
        vec_chord_diminished,
        vec_chord_half_diminished,
        vec_chord_diminished_7,
        vec_chord_augmented
}  ;

#endif //RTMIDI_TEST_MAIN_H
