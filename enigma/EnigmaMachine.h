#pragma once
#include <string>

class EnigmaMachine {
    public:
        EnigmaMachine();  // You could add config params later
        std::string encode(const std::string& input);
        std::string decode(const std::string& input);
    };