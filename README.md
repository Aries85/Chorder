# Chorder

## Prerequisites
Install following Conan.io packages:
- https://github.com/Aries85/conan-rtmidi
- https://github.com/Aries85/conan-tclap

with command `conan export demo/testing` in each package's directory.

### Mac OS
Install XCode to have all necessary header files.

## Building
In main application directory run following command: `conan install --build TCLAP RtMidi`. This will build conan dependencies from source and then application itself.
