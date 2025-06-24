#pragma once
#include <unordered_map>
#include <vector>
#include <string>

#include "Rotor.h"
#include "Reflector.h"
#include "Plugboard.h"

// class to map the used alphabet to integers that are used internally in the 
// enigma machine. (simulation of human pressing a letter in keyboard)
class AlphabetMapper {
public:
    AlphabetMapper(const std::string& alphabet);

    int charToIndex(char c) const;
    char indexToChar(int i) const;
    int size() const;

private:
    std::unordered_map<char, int> char_to_index_;
    std::vector<char> index_to_char_;
};

Rotor loadRotorFromAlphabetString(const std::string& wiringString, const int rotorPosition, const char notchPos, const AlphabetMapper& mapper);

Reflector loadReflectorFromAlphabetString(const std::string& wiringString, const AlphabetMapper& mapper);

Plugboard loadPlugboardFromPairs(const std::vector<std::pair<char, char>>& pairs, const AlphabetMapper& mapper);

Plugboard loadPlugboardFromString(const std::string& connections, const AlphabetMapper& mapper);
