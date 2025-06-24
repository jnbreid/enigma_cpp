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
        void setReflector(const std::string& wiring);
        void setRotors(const std::vector<std::string>& names, 
                       const std::vector<int>& positions);
        void setRotorPositions(const std::vector<int>& positions);
        void setCustomRotors(const std::vector<std::string>& wirings,
                        const std::vector<char>& notchPositions,
                        const std::vector<int>& startPositions);
        void setCustomAlphabet(const std::string& alphabet);

    private:
        AlphabetMapper alphabetMapper_;
        RotorAssembly rotorassembly_;
        Reflector reflector_;
        Plugboard plugboard_;

        void setup();
};