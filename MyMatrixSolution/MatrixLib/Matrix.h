#pragma once
#include "Generator.h"
#include <string>
#include <memory>
#include <sstream>
#include <stdexcept>
#include <initializer_list>
#include <algorithm>

namespace miit::algebra {

template <typename T>
class Matrix {
private:
    std::unique_ptr<T[]> data;
    size_t size;

public:
    explicit Matrix(size_t size);
    Matrix(const T* values, size_t size);
    explicit Matrix(std::initializer_list<T> list);
    Matrix(const Matrix& other);
    Matrix& operator=(const Matrix& other);
    Matrix(Matrix&& other) = default;
    Matrix& operator=(Matrix&& other) = default;
    ~Matrix() = default;

    T& operator[](size_t index);
    const T& operator[](size_t index) const;

    size_t getSize() const;

    void fill(size_t count, Generator& gen);

    std::string toString() const;

    friend std::ostream& operator<<(std::ostream& os, const Matrix& m) {
        os << m.toString();
        return os;
    }
};

template <typename T>
Matrix<T>::Matrix(size_t size) : size(size), data(nullptr) {
    if (size == 0) {
      data = nullptr;
    } else {
    data = std::make_unique<T[]>(size);
    }
}

template <typename T>
Matrix<T>::Matrix(const T* values, size_t size)
    : size(size), data(std::make_unique<T[]>(size)) {
    if (size == 0) {
        throw std::invalid_argument("Matrix size must be greater than 0");
    }
    for (size_t i = 0; i < size; ++i) {
        data[i] = values[i];
    }
}

template <typename T>
Matrix<T>::Matrix(const Matrix& other)
    : size(other.size), data(std::make_unique<T[]>(other.size)) {
    for (size_t i = 0; i < size; ++i) {
        data[i] = other.data[i];
    }
}

template <typename T>
Matrix<T>& Matrix<T>::operator=(const Matrix& other) {
    if (this != &other) {
        size = other.size;
        data = std::make_unique<T[]>(other.size);
        for (size_t i = 0; i < size; ++i) {
            data[i] = other.data[i];
        }
    }
    return *this;
}

template <typename T>
T& Matrix<T>::operator[](size_t index) {
    if (index >= size) {
        throw std::out_of_range("Index out of range");
    }
    return data[index];
}

template <typename T>
const T& Matrix<T>::operator[](size_t index) const {
    if (index >= size) {
        throw std::out_of_range("Index out of range");
    }
    return data[index];
}

template <typename T>
size_t Matrix<T>::getSize() const {
    return size;
}

template <typename T>
void Matrix<T>::fill(size_t count, Generator& gen) {
    if (count > size) {
        throw std::out_of_range("Fill count exceeds matrix size");
    }
    for (size_t i = 0; i < count; ++i) {
        data[i] = static_cast<T>(gen.generate());
    }
}

template <typename T>
std::string Matrix<T>::toString() const {
    std::ostringstream oss;
    oss << "[ ";
    for (size_t i = 0; i < size; ++i) {
        oss << data[i] << " ";
    }
    oss << "]";
    return oss.str();
}

template <typename T>
Matrix<T>::Matrix(std::initializer_list<T> list)
    : size(list.size()), data(std::make_unique<T[]>(list.size())) {
    std::copy(list.begin(), list.end(), data.get());
}

} 
