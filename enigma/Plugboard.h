// SPDX-License-Identifier: MIT
// Copyright (c) 2025 Jon Breid

#pragma once
#include <vector>

class Plugboard {
public:
    Plugboard(const std::vector<int>& connections);

    Plugboard();

    int swap(int input) const;  

private:
    std::vector<int> permutation_;
};