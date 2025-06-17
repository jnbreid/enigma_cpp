#pragma once
#include "Rotor.h"
#include <vector>

class RotorAssembly {
private:
    std::vector<Rotor> rotors_;

public:
    RotorAssembly(const std::vector<Rotor>& rotors);

    int forwardTransform(int input);
    int backwardTransform(int input);
    void rotateRotors();
};
