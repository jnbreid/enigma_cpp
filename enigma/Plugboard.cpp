#include "Plugboard.h"


Plugboard::Plugboard(const std::vector<int>& connections) 
    : permutation_(connections) { 
}

int Plugboard::swap(int input) const {
    return permutation_[input];
}