cmake_minimum_required (VERSION 3.10)
project (Global_illumination)

include_directories(include)
link_directories(include)

file(GLOB SOURCES "src/*.cpp")


add_executable(GIProgram ${SOURCES})