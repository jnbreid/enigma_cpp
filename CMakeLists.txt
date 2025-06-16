

project(enigma)

find_package(pybind11 CONFIG REQUIRED)

pybind11_add_module(enigma enigma/bindings.cpp enigma/enigma.cpp)