#pragma once
#include <vector>
#include <string>

namespace miit::algebra {

class Matrix {
private:
    std::vector<int> data;

public:
    explicit Matrix(size_t size);
    Matrix(const std::vector<int>& values);
    Matrix(const Matrix& other);
    ~Matrix() = default;

    int& operator[](size_t index);
    const int& operator[](size_t index) const;

    std::string toString() const;
    size_t getSize() const;

    void fill(size_t count, class Generator& gen);

    friend std::ostream& operator<<(std::ostream& os, const Matrix& m);
};

}

