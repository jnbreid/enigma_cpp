#pragma once
#include <string>
#include "RotorAssembly.h"
#include "Reflector.h"
#include "Plugboard.h"
#include "utils.h"

class EnigmaMachine {
    public:
        EnigmaMachine();  
        std::string encode(const std::string& input);
        std::string decode(const std::string& input);

        void setPlugboard(const std::string& plug);

    private:
        AlphabetMapper alphabetMapper_;
        RotorAssembly rotorassembly_;
        Reflector reflector_;
        Plugboard plugboard_;

        void setup();
};