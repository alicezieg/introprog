cmake_minimum_required(VERSION 3.5)

project(NameintheBox LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_executable(NameintheBox main.cpp)

install(TARGETS NameintheBox
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR})
