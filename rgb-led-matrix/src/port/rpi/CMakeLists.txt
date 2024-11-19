add_library(rpi SHARED)

set(CMAKE_C_COMPILER /opt/pi/tools/arm-bcm2708/arm-linux-gnueabihf/bin/arm-linux-gnueabihf-gcc)
set(CMAKE_CXX_COMPILER /opt/pi/tools/arm-bcm2708/arm-linux-gnueabihf/bin/arm-linux-gnueabihf-g++)

target_include_directories(rpi PUBLIC
    ../../../lib/include/
    ../../../include/
    ../../../../external/FTDI/FTDI_D2XX/Linux/ARMv6_hard-float/)

target_link_directories(rpi PUBLIC
    ../../../../external/FTDI/FTDI_D2XX/Linux/ARMv6_hard-float/build)

target_compile_options(rpi PRIVATE
    -Wall
    -Werror
   -O3
)

target_link_libraries(rpi
    RGB_Matrix
    SIMD_ARM
    ftd2xx
    pthread)

add_executable(rpi-daemon
    ../../main.cpp)

target_compile_options(rpi-daemon PRIVATE
    -Wall
    -Werror
    -O3
)

target_link_libraries(rpi-daemon
    rpi)
