// SPDX-License-Identifier: MIT
// Copyright (c) 2025 Jon Breid

#include "Rotor.h"

Rotor::Rotor(const std::vector<int>& permutation, int startPos, int notchPos) 
    : position_(startPos),  notchPosition_(notchPos), initial_position_(startPos) {
    
    permutationSize_ = permutation.size();

    forwardMap_.resize(permutationSize_);
    reverseMap_.resize(permutationSize_);

    for (int i = 0; i < permutation.size(); ++i) {
        forwardMap_[permutation[i]] = i;
        reverseMap_[i] = permutation[i];
    }
}

int Rotor::forwardTransform(int input) {
    // simulating rotation by addint rotation index befor map and removing it after (position_)
    int index = (input + position_) % permutationSize_;
    index = forwardMap_[index];
    return (index - position_ + permutationSize_) % permutationSize_;
}

int Rotor::reverseTransform(int input) {
    int index = (input + position_) % permutationSize_;
    index = reverseMap_[index];
    return (index - position_ + permutationSize_) % permutationSize_;
}

bool Rotor::rotate() {
    position_ = (position_ + 1) % permutationSize_;
    if (position_ == notchPosition_){
        return true;
    }
    return false;
}

void Rotor::resetRotorPosition() {
    position_ = initial_position_;
}

void Rotor::setRotorPosition(int position) {
    position_ = position;
}