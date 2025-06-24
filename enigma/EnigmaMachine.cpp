
#include "EnigmaMachine.h"
#include "presets/RotorPresets.h"
#include "presets/ReflectorPresets.h"
#include "utils.h"
#include "RotorAssembly.h"
#include "Reflector.h"
#include "Plugboard.h"

EnigmaMachine::EnigmaMachine()
    : alphabetMapper_("ABCDEFGHIJKLMNOPQRSTUVWXYZ"),
      rotorassembly_({
          loadRotorFromAlphabetString(RotorPresets::STANDARD_ROTORS.at("I").wiring, 0,
                                      RotorPresets::STANDARD_ROTORS.at("I").notch, alphabetMapper_),
          loadRotorFromAlphabetString(RotorPresets::STANDARD_ROTORS.at("II").wiring, 0,
                                      RotorPresets::STANDARD_ROTORS.at("II").notch, alphabetMapper_),
          loadRotorFromAlphabetString(RotorPresets::STANDARD_ROTORS.at("III").wiring, 0,
                                      RotorPresets::STANDARD_ROTORS.at("III").notch, alphabetMapper_)
      }),
      reflector_(loadReflectorFromAlphabetString(ReflectorPresets::STANDARD_REFLECTORS.at("B"), alphabetMapper_)),
      plugboard_(loadPlugboardFromString("AB CD EF", alphabetMapper_)) {
    
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