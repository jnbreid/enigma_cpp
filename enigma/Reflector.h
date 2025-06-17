#pragma once
#include <vector>

class Reflector {
public:
    Reflector(const std::vector<int>& wiring);

    int reflect(int input) const;  

private:
    std::vector<int> permutation_;
};