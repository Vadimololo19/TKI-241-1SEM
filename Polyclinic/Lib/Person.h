#pragma once
#include <string>

class Person {
protected:
    std::string name;
    std::string surname;
    std::string patronymic;

public:
    Person(const std::string& name = "", const std::string& surname = "", const std::string& patronymic = "");
    virtual ~Person() = default;

    const std::string& getName() const;
    const std::string& getSurname() const;
    const std::string& getPatronymic() const;

    virtual std::string getInfo() const = 0;
};
