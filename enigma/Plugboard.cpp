#include "Plugboard.h"


Plugboard::Plugboard(const std::vector<int>& connections) 
    : permutation_(connections) { 
}

Plugboard::Plugboard() {}

int Plugboard::swap(int input) const {

    
    
    return permutation_[input];
}