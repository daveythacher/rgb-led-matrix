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

add_subdirectory(test)
