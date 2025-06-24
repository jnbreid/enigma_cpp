// SPDX-License-Identifier: MIT
// Copyright (c) 2025 Jon Breid

#pragma once
#include <vector>

class Reflector {
public:
    Reflector(const std::vector<int>& wiring);
    Reflector();

    int reflect(int input) const;  

private:
    std::vector<int> permutation_;
};