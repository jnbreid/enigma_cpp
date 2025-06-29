# Enigma Simulator

A C++ implementation of the Enigma cipher machine, integrated with Python via [Pybind11](https://github.com/pybind/pybind11). 
Unlike the original, this version supports **fully customizable rotors, reflectors, and plugboards**, allowing for alphabets larger than the traditional 26 letters — including extended symbol sets such as all printable ASCII characters (as demonstrated in the demo notebook).

## Features

- Fully customizable rotors, reflectors, and plugboards  
  Supports arbitrary character sets, including all printable ASCII characters.

- Python integration via Pybind11  
  Enables interactive use from Python scripts or Jupyter notebooks.

- Interactive demo notebook  
  Demonstrates encryption, configuration, and extended alphabet usage.

## Installation

Make sure you have CMake and Pybind11 installed. Then, build the module by running:

```bash
mkdir build && cd build
cmake ..
make
```

## Demo

Check out [*demo.ipynb*](demo.ipynb) for an interactive walkthrough and showcase of functionalities.


## License

This project is licensed under a [GPL-3.0 license](LICENSE).
