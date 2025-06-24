
#include "RotorAssembly.h"

RotorAssembly::RotorAssembly(const std::vector<Rotor>& rotors) : rotors_(rotors) {}

RotorAssembly::RotorAssembly() {}

int RotorAssembly::forwardTransform(int input) {
    for (int i = 0; i < rotors_.size(); i++) {
        input = rotors_[i].forwardTransform(input);
    }
    return input;
}

int RotorAssembly::backwardTransform(int input) {
    for (int i = 0; i < rotors_.size(); i++) {
        input = rotors_[rotors_.size()-1-i].reverseTransform(input);
    }
    return input;
}

void RotorAssembly::rotateRotors() {
    bool rotateNext = true;
    for (Rotor& rotor : rotors_) {
        if (rotateNext) {
            rotor.rotate();
        }
    }
}

void RotorAssembly::resetRotors() {
    for (int i = 0; i < rotors_.size(); i++) {
        rotors_[i].resetRotorPosition();
    }
}