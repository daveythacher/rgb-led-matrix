add_subdirectory(CFG)
add_subdirectory(IO)
add_subdirectory(Panel)
add_subdirectory(Exception)
add_subdirectory(Mapper)
add_subdirectory(Frame)
add_subdirectory(ThreadPool)
add_subdirectory(Logger)

add_library(RGB_Matrix INTERFACE)

target_sources(RGB_Matrix INTERFACE
    RGBMatrix.cpp)

target_link_libraries(RGB_Matrix INTERFACE
    Exception
    ThreadPool
    Mapper
    CFG
    IO
    Panel
    Frame
    Logger)