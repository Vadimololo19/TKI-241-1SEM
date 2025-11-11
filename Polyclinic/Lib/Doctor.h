#pragma once
#include "Person.h"
#include <string>

class Doctor : public Person {
private:
    std::string specialty;
    std::string cabinet;

public:
    Doctor(
        const std::string& name = "",
        const std::string& surname = "",
        const std::string& patronymic = "",
        const std::string& specialty = "",
        const std::string& cabinet = ""
    );

    const std::string& getSpecialty() const;
    const std::string& getCabinet() const;

    std::string getInfo() const override;
};
