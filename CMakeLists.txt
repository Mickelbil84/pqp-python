cmake_minimum_required(VERSION 3.21)

project(pqp-python)

find_package(Python COMPONENTS Interpreter Development REQUIRED)
find_package(pybind11 CONFIG REQUIRED)

pybind11_add_module(pqp src/pqp_python.cpp)

include_directories(include)
target_link_libraries(pqp PRIVATE)

install(TARGETS pqp DESTINATION pqp)