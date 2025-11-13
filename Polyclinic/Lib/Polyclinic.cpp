#include "Polyclinic.h"
#include "Doctor.h"
#include "Appointment.h"
#include <string>

void Polyclinic::addDoctor(std::shared_ptr<Doctor> doctor) {
    doctors.push_back(doctor);
}

void Polyclinic::addAppointment(std::shared_ptr<Appointment> appointment) {
    appointments.push_back(appointment);
}

const std::vector<std::shared_ptr<Doctor>>& Polyclinic::getDoctors() const {
    return doctors;
}

const std::vector<std::shared_ptr<Appointment>>& Polyclinic::getAppointments() const {
    return appointments;
}

std::string Polyclinic::getInfo() const {
    std::string result = "Polyclinic\n";
    
    result += "Doctors (" + std::to_string(doctors.size()) + "):\n";
    for (const auto& doc : doctors) {
        result += "- " + doc->getInfo() + "\n";
    }

    result += "\nAppointment (" + std::to_string(appointments.size()) + "):\n";
    for (const auto& app : appointments) {
        result += "- " + app->getInfo() + "\n";
    }

    return result;
}
