
#include <pybind11/pybind11.h>
#include "enigma.h"

namespace py = pybind11;

PYBIND11_MODULE(enigma, m) {
    py::class_<Enigma>(m, "Enigma")
        .def(py::init<>())
        .def("encode", &Enigma::encode)
        .def("decode", &Enigma::decode);
}