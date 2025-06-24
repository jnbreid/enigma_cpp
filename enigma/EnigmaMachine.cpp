
#include "EnigmaMachine.h"
#include "presets/RotorPresets.h"
#include "presets/ReflectorPresets.h"
#include "EnigmaMachine.h"
#include "RotorAssembly.h"
#include "utils.h"
#include "Reflector.h"
#include "Plugboard.h"


EnigmaMachine::EnigmaMachine()
    : alphabetMapper_("ABCDEFGHIJKLMNOPQRSTUVWXYZ"),
      rotorassembly_({
          loadRotorFromAlphabetString(
              RotorPresets::STANDARD_ROTORS.at("I").wiring,
              0,
              RotorPresets::STANDARD_ROTORS.at("I").notch,
              alphabetMapper_),
          loadRotorFromAlphabetString(
              RotorPresets::STANDARD_ROTORS.at("II").wiring,
              0,
              RotorPresets::STANDARD_ROTORS.at("II").notch,
              alphabetMapper_),
          loadRotorFromAlphabetString(
              RotorPresets::STANDARD_ROTORS.at("III").wiring,
              0,
              RotorPresets::STANDARD_ROTORS.at("III").notch,
              alphabetMapper_)
      }),
      reflector_(
          loadReflectorFromAlphabetString(
              ReflectorPresets::STANDARD_REFLECTORS.at("B"),
              alphabetMapper_)),
      plugboard_(loadPlugboardFromString("AB CD EF GH IJ KL MN OP", alphabetMapper_)) {}


std::string EnigmaMachine::encode(const std::string& input) {
    rotorassembly_.resetRotors();

    std::string output;

    for (char c : input) {
        int index = alphabetMapper_.charToIndex(c);
        if (index == -1) continue;

        index = plugboard_.swap(index);
        index = rotorassembly_.forwardTransform(index);
        index = reflector_.reflect(index);
        index = rotorassembly_.backwardTransform(index);
        index = plugboard_.swap(index);

        rotorassembly_.rotateRotors();

        output += alphabetMapper_.indexToChar(index);
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