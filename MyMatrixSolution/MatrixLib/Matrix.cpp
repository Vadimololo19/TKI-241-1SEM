#include "Generator.h"
#include "Matrix.h"
#include <sstream>

namespace miit::algebra {

Matrix::Matrix(size_t size) : data(size) {
}

Matrix::Matrix(const std::vector<int>& values) : data(values) {
}

Matrix::Matrix(const Matrix& other) : data(other.data) {}

int& Matrix::operator[](size_t index) {
    return data.at(index);
}

const int& Matrix::operator[](size_t index) const {
    return data.at(index);
}

std::string Matrix::toString() const {
    std::ostringstream oss;
    oss << "[ ";
    for (int x : data) oss << x << " ";
    oss << "]";
    return oss.str();
}

size_t Matrix::getSize() const {
    return data.size();
}

void Matrix::fill(size_t count, Generator& gen) {
    if (count > data.size()) throw std::out_of_range("Fill count exceeds size");
    for (size_t i = 0; i < count; ++i) {
        data[i] = gen.generate();
    }
}

std::ostream& operator<<(std::ostream& os, const Matrix& m) {
    os << m.toString();
    return os;
}

}
