cmake_minimum_required(VERSION 3.5)

project(VectorFunctionsFeb27 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_executable(VectorFunctionsFeb27 main.cpp)

install(TARGETS VectorFunctionsFeb27
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR})
