

from setuptools import setup, Extension
import pybind11

setup(
    name="enigma",
    version="0.1",
    ext_modules=[
        Extension("enigma", sources=["enigma_wrapper.cpp", "enigma.cpp"],
                  include_dirs=[pybind11.get_include()])
    ],
    install_requires=["pybind11"],
)