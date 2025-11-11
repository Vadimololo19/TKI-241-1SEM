#pragma once
#include <string>
#include <ctime>
#include <memory>

class Doctor;
class Patient;

class Appointment {
private:
    std::shared_ptr<Doctor> doctor;
    std::shared_ptr<Patient> patient;
    std::time_t dateTime;

public:
    Appointment(
        std::shared_ptr<Doctor> doctor,
        std::shared_ptr<Patient> patient,
        std::time_t dateTime
    );

    std::string getInfo() const;
};
