cmake_minimum_required(VERSION 3.21)
project(FileManager)

set(CMAKE_CXX_STANDARD 11)

add_subdirectory(tinyxml)

add_executable(FileManager main.cpp
        file_class/FileError.cpp
        file_class/FileError.h
        file_class/FileManager.h
        file_class/FileManager.cpp)

target_link_libraries(FileManager TinyXml)

SET(EXECUTABLE_OUTPUT_PATH ${PROJECT_SOURCE_DIR}/build)
