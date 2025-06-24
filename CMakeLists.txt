# Copyright (c) 2025 Your Name
# SPDX-License-Identifier: MIT

project(enigma)

find_package(pybind11 CONFIG REQUIRED)

# Add your source files 
set(SOURCES
    enigma/EnigmaMachine.cpp
    enigma/Plugboard.cpp
    enigma/Rotor.cpp
    enigma/RotorAssembly.cpp
    enigma/Reflector.cpp
    enigma/utils.cpp
    enigma/presets/RotorPresets.cpp
    enigma/presets/ReflectorPresets.cpp
)

pybind11_add_module(enigma bindings.cpp ${SOURCES})

# add enigma/ to list of include paths
target_include_directories(enigma PRIVATE 
    ${CMAKE_CURRENT_SOURCE_DIR}/enigma
    ${CMAKE_CURRENT_SOURCE_DIR}/enigma/presets
)