
#include "utils.h"
#include <stdexcept>

AlphabetMapper::AlphabetMapper(const std::string& alphabet) {
    for (int i = 0; i < static_cast<int>(alphabet.size()); ++i) {
        char c = alphabet[i];
        char_to_index_[c] = i;
        index_to_char_.push_back(c);
    }
}

int AlphabetMapper::charToIndex(char c) const {
    // todo: add conditions for bigger alphabet
    // c = toupper(c);
    std::unordered_map<char, int>::const_iterator it = char_to_index_.find(c);
    // characters that are not in the alphabet are returned as -1 to ignore them
    if (it == char_to_index_.end())
        return -1;
    return it->second;
}

char AlphabetMapper::indexToChar(int i) const {
    if (i < 0 || i >= static_cast<int>(index_to_char_.size()))
        throw std::out_of_range("Index out of range");
    return index_to_char_[i];
}

int AlphabetMapper::size() const {
    return static_cast<int>(index_to_char_.size());
}

Rotor loadRotorFromAlphabetString(const std::string& wiringString, const int rotorPosition, const char notchPos, const AlphabetMapper& mapper) {
    if (static_cast<int>(wiringString.size()) != mapper.size()) {
        throw std::invalid_argument("Wiring string size must match alphabet size.");
    }

    std::vector<int> permutation;
    permutation.reserve(mapper.size());

    for (char c : wiringString) {
        int index = mapper.charToIndex(c);
        if (index == -1) {
            throw std::invalid_argument("Invalid character found in wiring string.");
        }
        permutation.push_back(index);
    }

    int notchPosition = mapper.charToIndex(notchPos);

    return Rotor(permutation, rotorPosition, notchPosition);
}


Reflector loadReflectorFromalphabetString(const std::string& wiringString, const AlphabetMapper& mapper) {
    if (static_cast<int>(wiringString.size()) != mapper.size()) {
        throw std::invalid_argument("Wiring string size must match alphabet size.");
    }

    std::vector<int> permutation;
    permutation.reserve(mapper.size());

    for (char c : wiringString) {
        int index = mapper.charToIndex(c);
        if (index == -1) {
            throw std::invalid_argument("Invalid character found in wiring string.");
        }
        permutation.push_back(index);
    }

    return Reflector(permutation);
}