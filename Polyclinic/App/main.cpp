#include <iostream>
#include <vector>
#include <memory>
#include <ctime>
#include "../Lib/Doctor.h"
#include "../Lib/Patient.h"
#include "../Lib/Polyclinic.h"
#include "../Lib/Appointment.h"

int main() {
    auto drIvanov = std::make_shared<Doctor>("Alexey", "Ivanov", "Sergeevich", "Terapist", "205");
    auto drPetrova = std::make_shared<Doctor>("Maria", "Petrova", "Dmitrievna", "Surgeon", "312");
    auto patSidorov = std::make_shared<Patient>("Ivan", "SIdorov", "Petrovich", "123-456-789");
    auto patKuznetsova = std::make_shared<Patient>("Anna", "Shimenuk", "OLegovna", "987-654-321");

    std::time_t now = std::time(nullptr);
    auto app1 = std::make_shared<Appointment>(drIvanov, patSidorov, now + 3600);
    auto app2 = std::make_shared<Appointment>(drPetrova, patKuznetsova, now + 7200);

    Polyclinic clinic;
    clinic.addDoctor(drIvanov);
    clinic.addDoctor(drPetrova);
    clinic.addAppointment(app1);
    clinic.addAppointment(app2);

    std::cout << clinic.getInfo();

    return 0;  
}
