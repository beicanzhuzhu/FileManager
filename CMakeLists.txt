cmake_minimum_required(VERSION 3.25)
project(FileManager)

set(CMAKE_CXX_STANDARD 17)

include_directories(headers)

add_executable(FileManager src/main.cpp src/tinyxml2.cpp src/file_operation.cpp headers/file_operation.h headers/FileError.h src/FileError.cpp src/File.cpp headers/File.h)
target_link_libraries(FileManager -lpdcurses)
