#pragma once
#include "Generator.h"
#include <vector>
#include <string>
#include <sstream>

namespace miit::algebra {

template <typename T>
class Matrix {
private:
    std::vector<T> data;

public:
    explicit Matrix(size_t size);
    Matrix(const std::vector<T>& values);
    Matrix(const Matrix& other) = default;
    Matrix& operator=(const Matrix& other) = default;
    Matrix(Matrix&& other) = default;
    Matrix& operator=(Matrix&& other) = default;
    ~Matrix() = default;

    T& operator[](size_t index);
    const T& operator[](size_t index) const;

    std::string toString() const;
    size_t getSize() const;

    void fill(size_t count, class Generator<T>& gen);

    friend std::ostream& operator<<(std::ostream& os, const Matrix& m) {
        return os << m.toString();
    }
};

template <typename T>
Matrix<T>::Matrix(size_t size) : data(size) {}

template <typename T>
Matrix<T>::Matrix(const std::vector<T>& values) : data(values) {}

template <typename T>
T& Matrix<T>::operator[](size_t index) {
    return data.at(index);
}

template <typename T>
const T& Matrix<T>::operator[](size_t index) const {
    return data.at(index);
}

template <typename T>
std::string Matrix<T>::toString() const {
    std::ostringstream oss;
    oss << "[ ";
    for (const auto& x : data) {
        oss << x << " ";
    }
    oss << "]";
    return oss.str();
}

template <typename T>
size_t Matrix<T>::getSize() const {
    return data.size();
}

template <typename T>
void Matrix<T>::fill(size_t count, Generator<T>& gen) {
    if (count > data.size()) throw std::out_of_range("Fill count exceeds size");
    for (size_t i = 0; i < count; ++i) {
        data[i] = gen.generate();
    }
}

} 
