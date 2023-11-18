cmake_minimum_required(VERSION 3.10)
project(Pirmoji)

include_directories(include)
file(GLOB SOURCES "src/*.cpp")

add_executable(Pirmoji ${SOURCES})
target_include_directories(Pirmoji PRIVATE include)



