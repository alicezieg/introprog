cmake_minimum_required(VERSION 3.5)

project(MultiplicationTable LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_executable(MultiplicationTable main.cpp)

install(TARGETS MultiplicationTable
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR})
