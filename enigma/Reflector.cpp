// SPDX-License-Identifier: MIT
// Copyright (c) 2025 Jon Breid

#include "Reflector.h"

Reflector::Reflector(const std::vector<int>& permutation) 
    : permutation_(permutation) { 
}

Reflector::Reflector() {}

int Reflector::reflect(int input) const {
    return permutation_[input];
}