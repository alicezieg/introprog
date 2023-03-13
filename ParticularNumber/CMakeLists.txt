cmake_minimum_required(VERSION 3.5)

project(ParticularNumber LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_executable(ParticularNumber main.cpp)

install(TARGETS ParticularNumber
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR})
