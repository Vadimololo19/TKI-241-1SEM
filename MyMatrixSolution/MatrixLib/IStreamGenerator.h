#pragma once
#include "Generator.h"
#include <iostream>

namespace miit::algebra {

template <typename T>
class IStreamGenerator : public Generator<T> {
    std::istream& in;
public:
    explicit IStreamGenerator(std::istream& in = std::cin);
    T generate() override;
};

template <typename T>
IStreamGenerator<T>::IStreamGenerator(std::istream& in) : in(in) {}

template <typename T>
T IStreamGenerator<T>::generate() {
    T value;
    in >> value;
    return value;
}

}
