#include "generators.h"

int RandomGenerator::generate() const {
    std::random_device randomDevice;
    std::mt19937 generator(randomDevice());
    std::uniform_int_distribution<int> distribution(0, INT32_MAX);
    return distribution(generator);
}

int RandomGenerator::generate(int min, int max) const {
    std::random_device randomDevice;
    std::mt19937 generator(randomDevice());
    std::uniform_int_distribution<int> distribution(min, max);
    return distribution(generator);
}