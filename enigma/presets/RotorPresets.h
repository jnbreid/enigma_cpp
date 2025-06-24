// SPDX-License-Identifier: MIT
// Copyright (c) 2025 Jon Breid

#pragma once
#include <string>
#include <unordered_map>

namespace RotorPresets {
    struct RotorDefinition {
        std::string wiring;
        char notch;
    };

    extern const std::unordered_map<std::string, RotorDefinition> STANDARD_ROTORS;
}