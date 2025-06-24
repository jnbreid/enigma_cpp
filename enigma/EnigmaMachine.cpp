// SPDX-License-Identifier: MIT
// Copyright (c) 2025 Jon Breid

#include "EnigmaMachine.h"
#include "presets/RotorPresets.h"
#include "presets/ReflectorPresets.h"
#include "EnigmaMachine.h"
#include "RotorAssembly.h"
#include "utils.h"
#include "Reflector.h"
#include "Plugboard.h"

#include <stdexcept>
#include <string>

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
    // decoding follows same process as encoding
    return encode(input); 
}

void EnigmaMachine::setPlugboard(const std::string& plug) {
    plugboard_ = loadPlugboardFromString(plug, alphabetMapper_);
}

void EnigmaMachine::setReflector(const std::string& wiring) {
    if (wiring == "B" || wiring == "C") {
        reflector_ = loadReflectorFromAlphabetString(
            ReflectorPresets::STANDARD_REFLECTORS.at(wiring),
            alphabetMapper_);
    } else {
        reflector_ = loadReflectorFromAlphabetString(wiring, alphabetMapper_);
    }
}

void EnigmaMachine::setRotors(const std::vector<std::string>& names, 
                              const std::vector<int>& positions) {
    if (names.size() != positions.size()) {
        throw std::invalid_argument("Names and positions must match.");
    }

    std::vector<Rotor> rotors;

    for (int i = 0; i < names.size(); i++) {
        const auto& preset = RotorPresets::STANDARD_ROTORS.at(names[i]);
        rotors.emplace_back(
            loadRotorFromAlphabetString(preset.wiring, positions[i], preset.notch, alphabetMapper_)
        );
    }

    rotorassembly_ = RotorAssembly(rotors);
}

void EnigmaMachine::setCustomRotors(const std::vector<std::string>& wirings,
                                    const std::vector<char>& notchPositions,
                                    const std::vector<int>& startPositions) {
    if (wirings.size() != notchPositions.size() || wirings.size() != startPositions.size()) {
        throw std::invalid_argument("Wiring, notch, and start position lists must be the same size.");
    }

    std::vector<Rotor> rotors;

    for (int i = 0; i < wirings.size(); i++) {
        rotors.emplace_back(
            loadRotorFromAlphabetString(wirings[i], startPositions[i], notchPositions[i], alphabetMapper_)
        );
    }

    rotorassembly_ = RotorAssembly(rotors);
}

void EnigmaMachine::setCustomAlphabet(const std::string& alphabet) {
    alphabetMapper_ = AlphabetMapper(alphabet);
    plugboard_ = loadPlugboardFromString("", alphabetMapper_);
}

void EnigmaMachine::setRotorPositions(const std::vector<int>& positions) {
    rotorassembly_.setRotorPositions(positions);
}