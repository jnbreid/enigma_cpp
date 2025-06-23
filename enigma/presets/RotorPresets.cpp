#include "RotorPresets.h"

namespace RotorPresets {

const std::unordered_map<std::string, RotorDefinition> STANDARD_ROTORS = {
    {"I",   {"EKMFLGDQVZNTOWYHXUSPAIBRCJ", 'Q'}},
    {"II",  {"AJDKSIRUXBLHWTMCQGZNPYFVOE", 'E'}},
    {"III", {"BDFHJLCPRTXVZNYEIWGAKMUSQO", 'V'}},
    {"IV",  {"ESOVPZJAYQUIRHXLNFTGKDCMWB", 'J'}},
    {"V",   {"VZBRGITYUPSDNHLXAWMJQOFECK", 'Z'}}
};

}