cmake_minimum_required(VERSION 3.24)
project(IVector)

include_directories(include)
file(GLOB SRC src/*.cpp)

add_executable(${PROJECT_NAME} ${SRC})