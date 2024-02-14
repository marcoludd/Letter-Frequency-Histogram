# CMakeList.txt : CMake project for Letter Frequency Histogram, include source and define
# project specific logic here.
#
# Add source to this project's executable.
add_executable (CMakeTarget "letter_frequency.cpp" "letter_frequency.h"
        resource/COPYING
        resource/README)
if (CMAKE_VERSION VERSION_GREATER 3.12)
  set_property(TARGET CMakeTarget PROPERTY CXX_STANDARD 20)
endif()

# TODO: Add tests and install targets if needed.
