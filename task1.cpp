#include <iostream>
#include <memory>
#include <cmath>
#include <stdexcept>
#include <limits>
#include <cstdlib>
#include <ctime>
#include <climits>

// Тип для умного указателя на массив, в общем сын маминой подргисс
using ArrayPtr = std::unique_ptr<int[]>;

class InputHandler {
public:
    static int input() {
        int value;
        if (!(std::cin >> value)) {
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            throw std::runtime_error("Input error: invalid integer");
        }
        return value;
    }

    static size_t getAboveZeroValue() {
        int inputVal = input();
        if (inputVal <= 0) {
            throw std::runtime_error("Size must be greater than zero");
        }
        return static_cast<size_t>(inputVal);
    }
};

class IntegerArray {
private:
    ArrayPtr data;
    size_t size;

public:
    explicit IntegerArray(size_t sz) : size(sz) {
        if (sz == 0) {
            throw std::runtime_error("Cannot create array of size 0");
        }
        data = ArrayPtr(new int[size]());
    }

    IntegerArray(const int* src, size_t sz) : size(sz) {
        if (sz == 0) {
            throw std::runtime_error("Cannot create array of size 0");
        }
        data = ArrayPtr(new int[size]);
        for (size_t i = 0; i < size; ++i) {
            data[i] = src[i];
        }
    }

    // Копирующий конструктор
    IntegerArray(const IntegerArray& other) : size(other.size) {
        data = ArrayPtr(new int[size]);
        for (size_t i = 0; i < size; ++i) {
            data[i] = other.data[i];
        }
    }

    IntegerArray& operator=(const IntegerArray& other) = delete; // Никаких присваиваний)))

    void fillRandom(int low, int high) {
        int range = high - low + 1;
        for (size_t i = 0; i < size; ++i) {
            data[i] = std::rand() % range + low;
        }
    }

    void fillFromInput() {
        std::cout << "Enter " << size << " integers: ";
        for (size_t i = 0; i < size; ++i) {
            data[i] = InputHandler::input();
        }
    }

    void print() const {
        std::cout << "[ ";
        for (size_t i = 0; i < size; ++i) {
            std::cout << data[i] << " ";
        }
        std::cout << "]\n";
    }

    int* get() { return data.get(); }
    const int* get() const { return data.get(); }
    size_t getSize() const { return size; }
};

class Task1 {
public:
    static void execute(IntegerArray& arr) {
        int minPositive = INT_MAX;
        int minIndex = -1;
        const int* data = arr.get();
        size_t size = arr.getSize();

        for (size_t i = 0; i < size; ++i) {
            if (data[i] > 0 && data[i] < minPositive) {
                minPositive = data[i];
                minIndex = static_cast<int>(i);
            }
        }

        if (minIndex != -1) {
            arr.get()[minIndex] = 0;
        }
    }
};

class Task2 {
private:
    static bool checkDigits(int value) {
        int n = std::abs(value);
        int lastDigit = n % 10;

        int firstDigit = n;
        while (firstDigit >= 10) {
            firstDigit /= 10;
        }

        return (firstDigit % 2 == 0) && (lastDigit % 2 == 0);
    }

    static size_t countValidElements(const int* arr, size_t size) {
        size_t count = 0;
        for (size_t i = 0; i < size; ++i) {
            if (checkDigits(arr[i])) {
                ++count;
            }
        }
        return count;
    }

public:
    static IntegerArray execute(const IntegerArray& src) {
        const int* data = src.get();
        size_t srcSize = src.getSize();
        size_t newSize = countValidElements(data, srcSize);

        if (newSize == 0) {
            throw std::runtime_error("No elements satisfy the condition for task2");
        }

        IntegerArray result(newSize);
        int* dest = result.get();
        size_t idx = 0;
        for (size_t i = 0; i < srcSize && idx < newSize; ++i) {
            if (checkDigits(data[i])) {
                dest[idx++] = data[i];
            }
        }
        return result;
    }
};

class Task3 {
public:
    static void execute(IntegerArray& arr) {
        int* data = arr.get();
        size_t size = arr.getSize();

        for (size_t i = 0; i < size; ++i) {
            if (i >= 2 && i <= 11) {
                data[i] = -static_cast<int>(std::pow(data[i], 2));
            } else {
                data[i] = data[i] - 1;
            }
        }
    }
};

enum FillCommand {
    FILL_RANDOM = 1,
    FILL_INPUT = 2
};

class ArrayFiller {
public:
    static void fill(IntegerArray& arr, int command, int low, int high) {
        switch (command) {
            case FILL_RANDOM:
                arr.fillRandom(low, high);
                break;
            case FILL_INPUT:
                arr.fillFromInput();
                break;
            default:
                throw std::runtime_error("Command error: invalid command");
        }
    }
};

void checkInterval(int low, int high) {
    if (low > high) {
        throw std::runtime_error("Interval error: low_value > high_value");
    }
}

int main() {
    std::srand(static_cast<unsigned int>(std::time(nullptr)));

    try {
        std::cout << "Enter command (1 - random, 2 - input), size, low, high: ";
        int command = InputHandler::input();
        size_t sizeArray = InputHandler::getAboveZeroValue();
        int lowValue = InputHandler::input();
        int highValue = InputHandler::input();
        checkInterval(lowValue, highValue);

        IntegerArray originalArray(sizeArray);
        ArrayFiller::fill(originalArray, command, lowValue, highValue);

        std::cout << "Original array: ";
        originalArray.print();

        {
            IntegerArray arr1(originalArray);
            Task1::execute(arr1);
            std::cout << "task1: ";
            arr1.print();
        }

        {
            try {
                IntegerArray arr2 = Task2::execute(originalArray);
                std::cout << "task2: ";
                arr2.print();
            } catch (const std::runtime_error&) {
                std::cout << "task2: No valid elements found.\n";
            }
        }

        {
            IntegerArray arr3(originalArray);
            Task3::execute(arr3);
            std::cout << "task3: ";
            arr3.print();
        }

    } catch (const std::exception& e) {
        std::cerr << "Error: " << e.what() << std::endl;
        return 1;
    }

    return 0;
}
