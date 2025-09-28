#include "IStreamGenerator.h"

namespace miit::algebra {
IStreamGenerator::IStreamGenerator(std::istream& in) : in(in) {}

int IStreamGenerator::generate() {
    int value;
    in >> value;
    return value;
}
}
