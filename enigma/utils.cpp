
#include "utils.h"

#include <stdexcept>
#include <sstream>

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
    if (i < 0 || i >= index_to_char_.size())
        throw std::out_of_range("Index out of range: " + std::to_string(i));
    return index_to_char_[i];
}

int AlphabetMapper::size() const {
    return index_to_char_.size();
}

Rotor loadRotorFromAlphabetString(const std::string& wiringString, const int rotorPosition, const char notchPos, const AlphabetMapper& mapper) {
    if (wiringString.size() != mapper.size()) {
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


Reflector loadReflectorFromAlphabetString(const std::string& wiringString, const AlphabetMapper& mapper) {
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

Plugboard loadPlugboardFromPairs(const std::vector<std::pair<char, char>>& pairs, const AlphabetMapper& mapper) {
    int size = mapper.size();
    std::vector<int> permutation(size);

    for (int i = 0; i < size; i++) {
        permutation[i] = i;
    }

    for (const auto& pair: pairs) {
        int x = mapper.charToIndex(pair.first);
        int y = mapper.charToIndex(pair.second);

        permutation[x] = y;
        permutation[y] = x;
    }

    return Plugboard(permutation);
}

Plugboard loadPlugboardFromString(const std::string& connections, const AlphabetMapper& mapper) {
    std::vector<std::pair<char, char>> pairs;

    std::istringstream stream(connections);
    std::string token;

    while (stream >> token) {
        if (token.size() !=2) {
            throw std::invalid_argument("Each switch must contain a pair of letters.");
        }

        char x = token[0];
        char y = token[1];
        pairs.emplace_back(x,y);
    }

    return loadPlugboardFromPairs(pairs, mapper);
}
