# Enigma Simulator

A C++ simulation of the historic Enigma cipher machine, integrated with Python via [Pybind11](https://github.com/pybind/pybind11). Encode and decode messages interactively from a Python interface or Jupyter notebook.

## Installation

Make sure you have CMake and Pybind11 installed. Then build the module:

```bash
mkdir build && cd build
cmake ..
make