#include "Person.h"

Person::Person(const std::string& name, const std::string& surname, const std::string& patronymic)
    : name(name), surname(surname), patronymic(patronymic) {}

const std::string& Person::getName() const { return name; }
const std::string& Person::getSurname() const { return surname; }
const std::string& Person::getPatronymic() const { return patronymic; }
