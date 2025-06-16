
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
    std::unordered_map<char, int>::const_iterator it = char_to_index_.find(c);
    if (it == char_to_index_.end())
        throw std::invalid_argument(std::string("Char not found: ") + c);
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