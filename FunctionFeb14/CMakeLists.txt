cmake_minimum_required(VERSION 3.5)

project(FunctionFeb14 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_executable(FunctionFeb14 main.cpp)

install(TARGETS FunctionFeb14
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR})
