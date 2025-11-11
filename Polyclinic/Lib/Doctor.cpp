#include "Doctor.h"
#include <string>

Doctor::Doctor(
    const std::string& name,
    const std::string& surname,
    const std::string& patronymic,
    const std::string& specialty,
    const std::string& cabinet
) : Person(name, surname, patronymic), specialty(specialty), cabinet(cabinet) {}

const std::string& Doctor::getSpecialty() const { return specialty; }
const std::string& Doctor::getCabinet() const { return cabinet; }

std::string Doctor::getInfo() const {
    return "Doctor: " + surname + " " + name[0] + "." + patronymic[0] + ". | SPeciality: " + specialty + " | Cabinet: " + cabinet;
}
