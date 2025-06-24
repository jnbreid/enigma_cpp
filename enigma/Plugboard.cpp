// SPDX-License-Identifier: MIT
// Copyright (c) 2025 Jon Breid

#include "Plugboard.h"

Plugboard::Plugboard(const std::vector<int>& connections) 
    : permutation_(connections) { 
}

Plugboard::Plugboard() {}

int Plugboard::swap(int input) const {   
    return permutation_[input];
}