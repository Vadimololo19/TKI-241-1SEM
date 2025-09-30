#pragma once
#include "Generator.h"
#include <random>

namespace miit::algebra {

template <typename T>
class RandomGenerator : public Generator<T> {
    std::uniform_int_distribution<T> distribution;
    std::mt19937 generator;
public:
    RandomGenerator(T min, T max);
    T generate() override;
};

template <typename T>
RandomGenerator<T>::RandomGenerator(T min, T max)
    : generator(std::random_device{}()), distribution(min, max) {}

template <typename T>
T RandomGenerator<T>::generate() {
    return distribution(generator);
}

} 
