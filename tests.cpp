#include "tests.h"

Random::Random(RandomGenerator* generator): randomGenerator(generator) {}

int Random::getRandomNumber() const {
    return randomGenerator->generate();
}

int Random::getRandomNumber(int min, int max) const {
    return randomGenerator->generate(min, max);
}

TEST(ValidBehaviour, RandomNumber) {
    MockRandomGenerator mockGenerator;
    Random random(&mockGenerator);
    EXPECT_CALL(mockGenerator, generate(0, 100))
            .Times(5)
            .WillOnce(testing::Return(10))
            .WillOnce(testing::Return(20))
            .WillRepeatedly(testing::Return(30));
    EXPECT_EQ(10, random.getRandomNumber(0, 100));
    EXPECT_EQ(20, random.getRandomNumber(0, 100));
    EXPECT_EQ(30, random.getRandomNumber(0, 100));
    EXPECT_EQ(30, random.getRandomNumber(0, 100));
    EXPECT_EQ(30, random.getRandomNumber(0, 100));
}

TEST(RandomBehaviour, RandomNumber) {
    MockRandomGenerator mockGenerator;
    Random random(&mockGenerator);
    ON_CALL(mockGenerator, generate(0, 10)).WillByDefault(testing::Return(-1));
    EXPECT_CALL(mockGenerator, generate(0, 10))
            .Times(testing::AtMost(3));
    int one = random.getRandomNumber(),
        two = random.getRandomNumber();
    EXPECT_NE(one, two);
    EXPECT_EQ(random.getRandomNumber(0, 10), -1);
    EXPECT_EQ(random.getRandomNumber(0, 10), -1);
    EXPECT_EQ(random.getRandomNumber(0, 10), -1);
    EXPECT_CALL(mockGenerator, generate(1, 5))
            .Times(5)
            .WillOnce(testing::Return(1))
            .WillOnce(testing::Return(2))
            .WillOnce(testing::Return(3))
            .WillOnce(testing::Return(4))
            .WillOnce(testing::Return(5));
    EXPECT_EQ(random.getRandomNumber(1, 5), 1);
    EXPECT_EQ(random.getRandomNumber(1, 5), 2);
    EXPECT_EQ(random.getRandomNumber(1, 5), 3);
    EXPECT_EQ(random.getRandomNumber(1, 5), 4);
    EXPECT_EQ(random.getRandomNumber(1, 5), 5);
}

TEST(InvalidBehaviour, RandomNumber) {
    MockRandomGenerator mockGenerator;
    Random random(&mockGenerator);
    EXPECT_CALL(mockGenerator, generate(10, 0))
            .WillOnce(testing::Throw(std::invalid_argument("Incorrect arguments")));
    EXPECT_THROW(random.getRandomNumber(10, 0), std::invalid_argument);
}