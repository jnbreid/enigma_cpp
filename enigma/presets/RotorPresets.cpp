// SPDX-License-Identifier: MIT
// Copyright (c) 2025 Jon Breid

#include "RotorPresets.h"

namespace RotorPresets {

// configurations taken from "https://www.ciphermachinesandcryptology.com/en/enigmatech.htm" (accessed June 21, 2025)
const std::unordered_map<std::string, RotorDefinition> STANDARD_ROTORS = {
    {"I",   {"EKMFLGDQVZNTOWYHXUSPAIBRCJ", 'Q'}},
    {"II",  {"AJDKSIRUXBLHWTMCQGZNPYFVOE", 'E'}},
    {"III", {"BDFHJLCPRTXVZNYEIWGAKMUSQO", 'V'}},
    {"IV",  {"ESOVPZJAYQUIRHXLNFTGKDCMWB", 'J'}},
    {"V",   {"VZBRGITYUPSDNHLXAWMJQOFECK", 'Z'}}
};

}