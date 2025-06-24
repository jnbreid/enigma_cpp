#include <pybind11/pybind11.h>
#include <pybind11/stl.h> 

#include "EnigmaMachine.h"

namespace py = pybind11;

PYBIND11_MODULE(enigma, m) {
    py::class_<EnigmaMachine>(m, "EnigmaMachine")
        .def(py::init<>())
        .def("encode", &EnigmaMachine::encode)
        .def("decode", &EnigmaMachine::decode)
        .def("set_plugboard", &EnigmaMachine::setPlugboard)
        .def("set_reflector", &EnigmaMachine::setReflector)
        .def("set_rotors", &EnigmaMachine::setRotors)
        .def("set_custom_rotors", &EnigmaMachine::setCustomRotors)
        .def("set_custom_alphabet", &EnigmaMachine::setCustomAlphabet)
        .def("set_rotor_positions", &EnigmaMachine::setRotorPositions);
}