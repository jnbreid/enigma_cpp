#pragma once
#include <string>

class Enigma {
public:
    Enigma();  // Constructor
    std::string encode(const std::string& input);  // Encode method
    std::string decode(const std::string& input);  // Decode method
};