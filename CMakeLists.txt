cmake_minimum_required(VERSION 3.21)

project(pqp-python)

find_package(Python COMPONENTS Interpreter Development REQUIRED)
find_package(pybind11 CONFIG REQUIRED)

pybind11_add_module(_pqp src/pqp_python.cpp src/Build.cpp src/BV.cpp src/PQP.cpp src/TriDist.cpp)

include_directories(include)
target_link_libraries(_pqp PRIVATE pybind11::headers)

install(TARGETS _pqp DESTINATION pqp)