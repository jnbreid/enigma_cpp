#include "Rotor.h"
#include <stdexcept>

Rotor::Rotor(const std::vector<int>& permutation, int startPos) 
    : position_(startPos) {
    
    permutationSize_ = permutation.size();

    for (int i = 0; i < permutation.size(); ++i) {
        forwardMap_[permutation[i]] = i;
        reverseMap_[i] = permutation[i];
    }
}

int Rotor::forwardTransform(int input) {
    // simulating rotation by addint rotation index (position_)
    int index = (input + position_) % permutationSize_;
    return forwardMap_[index];
}

int Rotor::reverseTransform(int input) {
    int index = (input + position_) % permutationSize_;
    return reverseMap_[index];
}

void Rotor::rotate() {
    position_ = (position_ + 1) % permutationSize_;
}