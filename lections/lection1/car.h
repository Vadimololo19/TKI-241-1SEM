#pragma once
#include <iostream>
#include <string>

class Car {
    private:
        std::string brand;
        int year;
    public:
        Car(const std::string brand,const int year);
        Car();
        ~Car() = default;
        friend std::ostream& operator<<(std::ostream& out, const Car& car);
};

Car::Car() {}

Car::Car(const std::string brand, const int year) : brand(brand), year(year) {}

std::ostream& operator<<(std::ostream& out, const Car& car) {
    out << car.brand << " " << car.year;
    return out;
}


