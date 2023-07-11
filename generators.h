#pragma once
#include <random>

class RandomGenerator {
public:
    virtual int generate() const;
    virtual int generate(int min, int max) const;
};