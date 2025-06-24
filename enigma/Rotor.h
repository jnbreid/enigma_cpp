// SPDX-License-Identifier: MIT
// Copyright (c) 2025 Jon Breid

#pragma once
#include <vector>
#include <map>


class Rotor {
private:
    std::vector<int> forwardMap_;
    std::vector<int> reverseMap_;
    int initial_position_;
    int position_;
    int permutationSize_;
    int notchPosition_;

public:
    Rotor(const std::vector<int>& permutation, int startPos, int notchPos);
    
    int forwardTransform(int input);
    int reverseTransform(int input);
    bool rotate();
    void resetRotorPosition();
    void setRotorPosition(int position);
};