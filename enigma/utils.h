#pragma once
#include <unordered_map>
#include <vector>
#include <string>

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