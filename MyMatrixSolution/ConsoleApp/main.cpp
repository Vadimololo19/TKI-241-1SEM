#include <iostream>
#include <memory>
#include "Matrix.h"
#include "RandomGenerator.h"
#include "IStreamGenerator.h"
#include "Task1Exercise.h"
#include "Task2Exercise.h"
#include "Task3Exercise.h"

using namespace miit::algebra;

enum { RANDOM = 1, INPUT = 2 };

int main() {
    try {
        int cmd, low, high;
        size_t size;

        std::cout << "Method (1-random, 2-input): ";
        std::cin >> cmd;
        std::cout << "Size: ";
        std::cin >> size;
        std::cout << "Low and high: ";
        std::cin >> low >> high;

        if (cmd != RANDOM && cmd != INPUT) throw std::runtime_error("Invalid method");
        if (low > high) throw std::runtime_error("Low > High");
        if (size == 0) throw std::runtime_error("Size <= 0");

        Matrix<int> original(size);
        std::unique_ptr<Generator> gen;

        if (cmd == RANDOM) {
            gen = std::make_unique<RandomGenerator>(low, high);
        } else {
            gen = std::make_unique<IStreamGenerator>(std::cin);
        }

        original.fill(size, *gen);

        std::cout << "Original: " << original << "\n";

        {
            Task1Exercise ex(original);
            ex.Task1();
            std::cout << "After Task1: " << ex.getMatrix() << "\n";
        }

        {
            Task2Exercise ex(original);
            ex.Task2();
        }

        {
            Task3Exercise ex(original);
            ex.Task3();
            std::cout << "After Task3: " << ex.getMatrix() << "\n";
        }

    } catch (const std::exception& e) {
        std::cerr << "Error: " << e.what() << "\n";
        return 1;
    }

    return 0;
}
