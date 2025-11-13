#pragma once
#include "Person.h"
#include <string>

class Patient : public Person {
private:
    std::string policyNumber;

public:
    Patient(
        const std::string& name = "",
        const std::string& surname = "",
        const std::string& patronymic = "",
        const std::string& policyNumber = ""
    );

    const std::string& getPolicyNumber() const;

    std::string getInfo() const override;
};
