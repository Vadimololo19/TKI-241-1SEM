#include "Patient.h"

Patient::Patient(
    const std::string& name,
    const std::string& surname,
    const std::string& patronymic,
    const std::string& policyNumber
) : Person(name, surname, patronymic), policyNumber(policyNumber) {}

const std::string& Patient::getPolicyNumber() const { return policyNumber; }

std::string Patient::getInfo() const {
    return "Patient: " + surname + " " + name + " " + patronymic + " | Policy: " + policyNumber;
}
