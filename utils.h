#ifndef RTMIDI_TEST_UTILS_H
#define RTMIDI_TEST_UTILS_H

#include <boost/utility/binary.hpp>
#include <cstddef>
#include <vector>

/*
 * Inline functions should be defined in headers
 * http://stackoverflow.com/questions/16574113/cmake-linking-error-undefined-reference-to
 */

inline bool isNoteOnMessage(unsigned char midiByte) {
    return ((midiByte & BOOST_BINARY( 11110000 )) == BOOST_BINARY (10010000));
}

inline bool isNoteOffMessage(unsigned char midiByte) {
    return ((midiByte & BOOST_BINARY( 11110000 )) == BOOST_BINARY (10000000));
}

inline bool isNoteMessage(unsigned char midiByte) {
    return isNoteOnMessage(midiByte) || isNoteOffMessage(midiByte);
}

template<typename T, size_t N>
std::vector<T> arrayToVector(const T (&w)[N]){
    return std::vector<T>(w, w+N);
}

#endif //RTMIDI_TEST_UTILS_H
