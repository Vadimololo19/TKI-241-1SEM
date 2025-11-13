#pragma once
#include <vector>
#include <memory>
#include <string>

class Doctor;
class Appointment;

class Polyclinic {
private:
    std::vector<std::shared_ptr<Doctor>> doctors;
    std::vector<std::shared_ptr<Appointment>> appointments;

public:
    Polyclinic() = default;

    void addDoctor(std::shared_ptr<Doctor> doctor);
    void addAppointment(std::shared_ptr<Appointment> appointment);

    const std::vector<std::shared_ptr<Doctor>>& getDoctors() const;
    const std::vector<std::shared_ptr<Appointment>>& getAppointments() const;

    std::string getInfo() const;
};
