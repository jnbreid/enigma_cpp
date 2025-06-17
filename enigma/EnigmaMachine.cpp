
#include "EnigmaMachine.h"

EnigmaMachine::EnigmaMachine() {
    // Init rotorassembly, reflector, plugboard
}

std::string EnigmaMachine::encode(const std::string& input) {
    std::string output;

    for (char c : input) {
        int index = alphabetMapper_.charToIndex(c);
        if (index == 0) continue;

        output += c;
    }

    return output;  
}

std::string EnigmaMachine::decode(const std::string& input) {
    // 
    return encode(input); 
}