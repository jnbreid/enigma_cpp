#pragma once
#include <vector>
#include <map>


class Rotor {
private:
    std::vector<int> forwardMap_;
    std::vector<int> reverseMap_;
    int position_;
    int permutationSize_;

public:
    Rotor(const std::vector<int>& permutation, int startPos);
    
    int forwardTransform(int input);
    int reverseTransform(int input);
    void rotate();
};