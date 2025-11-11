#include "Appointment.h"
#include "Doctor.h"
#include "Patient.h"
#include <iomanip>
#include <sstream>

Appointment::Appointment(
    std::shared_ptr<Doctor> doctor,
    std::shared_ptr<Patient> patient,
    std::time_t dateTime
) : doctor(doctor), patient(patient), dateTime(dateTime) {}

std::string Appointment::getInfo() const {
    std::tm* tmInfo = std::localtime(&dateTime);
    char buffer[64];
    std::strftime(buffer, sizeof(buffer), "%d.%m.%Y %H:%M", tmInfo);
    return "Registration: " + patient->getSurname() + " to " + doctor->getSurname() + " (" + doctor->getSpecialty() + ") — " + std::string(buffer);
}
