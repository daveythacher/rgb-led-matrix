cmake_minimum_required(VERSION 3.16)
add_library(linux_x64 SHARED)

target_include_directories(linux_x64 PUBLIC
    ../../../lib/include/
    ../../../include/
    ../../../../external/FTDI/FTDI_D2XX/Linux/x64/)

target_link_directories(linux_x64 PUBLIC
    ../../../../external/FTDI/FTDI_D2XX/Linux/x64/build)

target_compile_options(linux_x64 PRIVATE
    -Wall
    -Werror
    -O3
)

target_link_libraries(linux_x64
    RGB_Matrix
    SIMD_PORTABLE
    ftd2xx
    pthread)

find_package(Qt6 REQUIRED COMPONENTS Core)
set(CMAKE_AUTOMOC ON) 
set(CMAKE_AUTORCC ON) 
set(CMAKE_AUTOUIC ON)

qt_add_executable(linux_x64-daemon
    ../../main.cpp)

target_compile_options(linux_x64-daemon PRIVATE
    -Wall
    -Werror
    -O3
)

target_link_libraries(linux_x64-daemon PRIVATE
    linux_x64
    Qt6::Core)
