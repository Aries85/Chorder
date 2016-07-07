cmake_minimum_required(VERSION 3.5)
project(rtmidi_test)

# CONAN
if(EXISTS ${CMAKE_CURRENT_SOURCE_DIR}/conanbuildinfo.cmake) #Clion, with conanbuildinfo.cmake in build folder
    include(${CMAKE_CURRENT_SOURCE_DIR}/conanbuildinfo.cmake)
    #    include(conanbuildinfo.cmake)
else()
    include(${CMAKE_BINARY_DIR}/conanbuildinfo.cmake) # Not CLion
endif()
# END OF CONAN

conan_basic_setup()

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

set(SOURCE_FILES main.cpp main.h utils.h)
#set(SOURCE_FILES testmain.cpp)
add_executable(rtmidi_test ${SOURCE_FILES})

# must be placed after add_executable
target_link_libraries(rtmidi_test ${CONAN_LIBS})