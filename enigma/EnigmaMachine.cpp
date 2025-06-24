
#include "EnigmaMachine.h"
#include "presets/RotorPresets.h"
#include "presets/ReflectorPresets.h"

EnigmaMachine::EnigmaMachine() : alphabetMapper_("ABCDEFGHIJKLMNOPQRSTUVWXYZ") {
    using namespace RotorPresets;
    using namespace ReflectorPresets;

    const auto& r1 = STANDARD_ROTORS.at("I");
    const auto& r2 = STANDARD_ROTORS.at("II");
    const auto& r3 = STANDARD_ROTORS.at("III");

    Rotor rotor1 = loadRotorFromAlphabetString(r1.wiring, 0, r1.notch, alphabetMapper_);
    Rotor rotor2 = loadRotorFromAlphabetString(r2.wiring, 0, r2.notch, alphabetMapper_);
    Rotor rotor3 = loadRotorFromAlphabetString(r3.wiring, 0, r3.notch, alphabetMapper_);

    rotorassembly_ = RotorAssembly({rotor1, rotor2, rotor3});

    std::string reflectorString = STANDARD_REFLECTORS.at("B");

    reflector_ = loadReflectorFromalphabetString(reflectorString, alphabetMapper_);

    std::string plug = "AB CD EF";
    plugboard_ = loadPlugboardFromString(plug, alphabetMapper_);
}

std::string EnigmaMachine::encode(const std::string& input) {
    std::string output;

    for (char c : input) {
        int index = alphabetMapper_.charToIndex(c);
        if (index == -1) continue;

        c = plugboard_.swap(c);
        c = rotorassembly_.forwardTransform(c);
        c = reflector_.reflect(c);
        c = rotorassembly_.backwardTransform(c);
        c = plugboard_.swap(c);

        rotorassembly_.rotateRotors();

        output += c;
    }

    return output;  
}

std::string EnigmaMachine::decode(const std::string& input) {
    // decoding follows same process
    return encode(input); 
}

void EnigmaMachine::setPlugboard(const std::string& plug) {
    plugboard_ = loadPlugboardFromString(plug, alphabetMapper_);
}