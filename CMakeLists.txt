cmake_minimum_required(VERSION 3.24)
project(ILogger)

include_directories(include)

file(GLOB SRC src/*.cpp)

add_executable(${PROJECT_NAME} ${SRC} test/main.cpp)
