#pragma once
#include "generators.h"
#include <gtest/gtest.h>
#include <gmock/gmock.h>

class MockRandomGenerator: public RandomGenerator {
public:
    MOCK_CONST_METHOD2(generate, int(int, int));
};

class Random {
public:
    explicit Random(RandomGenerator* generator);
    int getRandomNumber() const;
    int getRandomNumber(int min, int max) const;
private:
    RandomGenerator* randomGenerator;
};