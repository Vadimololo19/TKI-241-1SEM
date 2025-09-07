#include <iostream>
#include <memory>
#include <cmath>
#include <stdexcept>
#include <limits>
#include <cstdlib>    
#include <ctime>     
#include <climits>   

using ArrayPtr = std::unique_ptr<int[]>;

/**
 * @brief Функция выбора метода заполнения массива пользователем
 */
void fill_array(int command, int* array, int low_value, int high_value, size_t size_array);

/**
 * @brief Функция заполнения массива вручную
 */
void fill_by_input(int* array, size_t size_array);

/**
 * @brief Функция заполнения массива случайными числами
 */
void fill_by_random(int* array, int low_value, int high_value, size_t size_array);

/**
 * @brief Функция вывода массива
 */
void print_array(const int* array, size_t size_array);

/**
 * @brief Функция ввода значения пользователем
 */
int input();

/**
 * @brief Функция получения положительного значения
 */
size_t get_above_zero_value();

/**
 * @brief Проверка интервала: low <= high
 */
void check_interval(int low_value, int high_value);

/**
 * @brief Создание массива через unique_ptr
 */
ArrayPtr create_array(size_t size_array);

/**
 * @brief Копирование массива в новый unique_ptr
 */
ArrayPtr copy_array(const int* src, size_t size_array);

/**
 * @brief Задание 1: заменить минимальный положительный элемент на 0
 */
void task1(int* arr, size_t size_array);

/**
 * @brief Задание 2: отфильтровать элементы по условию
 */
ArrayPtr task2(const int* arr1, size_t size_array1, size_t& out_size);

/**
 * @brief Задание 3: преобразование по правилу
 */
void task3(int* arr, size_t size_array);

/**
 * @brief Получение нового размера для задания 2
 */
size_t get_new_size(const int* arr, size_t size_array);

/**
 * @brief Проверка: первая и последняя цифры чётные
 */
bool check_digits(int value);

enum TaskCommand {
    FILL_RANDOM = 1,
    FILL_INPUT
};

int main() {
        std::srand(static_cast<unsigned int>(std::time(nullptr)));

        std::cout << "Enter command (1 - random, 2 - input), size, low, high: ";
        int command = input();
        size_t size_array = get_above_zero_value();
        int low_value = input();
        int high_value = input();
        check_interval(low_value, high_value);

        ArrayPtr arr = create_array(size_array);
        fill_array(command, arr.get(), low_value, high_value, size_array);
        std::cout << "Original array: ";
        print_array(arr.get(), size_array);

        ArrayPtr arr1 = copy_array(arr.get(), size_array);
        task1(arr1.get(), size_array);
        std::cout << "task1: ";
        print_array(arr1.get(), size_array);

        size_t task2_size = get_new_size(arr.get(), size_array);
        ArrayPtr arr2 = task2(arr.get(), size_array, task2_size);
        std::cout << "task2: ";
        print_array(arr2.get(), task2_size);

        ArrayPtr arr3 = copy_array(arr.get(), size_array);
        task3(arr3.get(), size_array);
        std::cout << "task3: ";
        print_array(arr3.get(), size_array);

        return 0;
}

int input() {
    int value;
    if (!(std::cin >> value)) {
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        throw std::runtime_error("Input error: invalid integer");
    }
    return value;
}

size_t get_above_zero_value() {
    int input_val = input();
    if (input_val <= 0) {
        throw std::runtime_error("Size must be greater than zero");
    }
    return static_cast<size_t>(input_val);
}

void check_interval(int low_value, int high_value) {
    if (low_value > high_value) {
        throw std::runtime_error("Interval error: low_value > high_value");
    }
}

void fill_array(int command, int* array, int low_value, int high_value, size_t size_array) {
    switch (static_cast<TaskCommand>(command)) {
        case FILL_RANDOM:
            fill_by_random(array, low_value, high_value, size_array);
            break;
        case FILL_INPUT:
            fill_by_input(array, size_array);
            break;
        default:
            throw std::runtime_error("Command error: invalid command");
    }
}

void fill_by_input(int* array, size_t size_array) {
    std::cout << "Enter " << size_array << " integers: ";
    for (size_t i = 0; i < size_array; ++i) {
        array[i] = input();
    }
}

void fill_by_random(int* array, int low_value, int high_value, size_t size_array) {
    int range = high_value - low_value + 1;
    for (size_t i = 0; i < size_array; ++i) {
        array[i] = std::rand() % range + low_value;
    }
}

void print_array(const int* array, size_t size_array) {
    std::cout << "[ ";
    for (size_t i = 0; i < size_array; ++i) {
        std::cout << array[i] << " ";
    }
    std::cout << "]\n";
}

ArrayPtr create_array(size_t size_array) {
    if (size_array == 0) {
        throw std::runtime_error("Cannot create array of size 0");
    }
    return ArrayPtr(new int[size_array]());
}

ArrayPtr copy_array(const int* src, size_t size_array) {
    ArrayPtr dest = create_array(size_array);
    for (size_t i = 0; i < size_array; ++i) {
        dest[i] = src[i];
    }
    return dest;
}

void task1(int* arr, size_t size_array) {
    int min_positive = INT_MAX;
    int min_index = -1;

    for (size_t i = 0; i < size_array; ++i) {
        if (arr[i] > 0 && arr[i] < min_positive) {
            min_positive = arr[i];
            min_index = static_cast<int>(i);
        }
    }

    if (min_index != -1) {
        arr[min_index] = 0;
    }
}

size_t get_new_size(const int* arr, size_t size_array) {
    size_t count = 0;
    for (size_t i = 0; i < size_array; ++i) {
        if (check_digits(arr[i])) {
            ++count;
        }
    }
    return count;
}

bool check_digits(int value) {
    int n = std::abs(value);  

    int last_digit = n % 10;
    int first_digit = n;
    while (first_digit >= 10) {
        first_digit /= 10;
    }

    return (first_digit % 2 == 0) && (last_digit % 2 == 0);
}

ArrayPtr task2(const int* arr1, size_t size_array1, size_t& out_size) {
    out_size = get_new_size(arr1, size_array1);
    if (out_size == 0) {
        return nullptr;
    }

    ArrayPtr arr2 = create_array(out_size);
    size_t idx = 0;
    for (size_t i = 0; i < size_array1 && idx < out_size; ++i) {
        if (check_digits(arr1[i])) {
            arr2[idx++] = arr1[i];
        }
    }
    return arr2;
}

void task3(int* arr, size_t size_array) {
    for (size_t i = 0; i < size_array; ++i) {
        if (i >= 2 && i <= 11) { 
            arr[i] = -static_cast<int>(std::pow(arr[i], 2));
        } else {
            arr[i] = arr[i] - 1;
        }
    }
}
