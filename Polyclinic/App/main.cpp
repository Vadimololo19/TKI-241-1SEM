#include <iostream>
#include <vector>
#include <memory>
#include <ctime>
#include "../Lib/Doctor.h"
#include "../Lib/Patient.h"
#include "../Lib/Appointment.h"

int main() {
    auto drIvanov = std::make_shared<Doctor>("Alexey", "Ivanov", "Sergeevich", "Terapist", "205");
    auto drPetrova = std::make_shared<Doctor>("Maria", "Petrova", "Dmitrievna", "Surgeon", "312");
    auto patSidorov = std::make_shared<Patient>("Ivan", "SIdorov", "Petrovich", "123-456-789");
    auto patKuznetsova = std::make_shared<Patient>("Anna", "Shimenuk", "OLegovna", "987-654-321");

    std::vector<std::unique_ptr<Person>> people;
    people.push_back(std::make_unique<Doctor>(*drIvanov));
    people.push_back(std::make_unique<Doctor>(*drPetrova));
    people.push_back(std::make_unique<Patient>(*patSidorov));
    people.push_back(std::make_unique<Patient>(*patKuznetsova));

    std::cout << "Information about people(Doctors and patients)\n";
    for (const auto& person : people) {
        std::cout << person->getInfo() << "\n";
    }

    std::cout << "\nAppointment to doctors\n";
    std::time_t now = std::time(nullptr);
    std::time_t tomorrow = now + 24 * 3600;

    Appointment app1(drIvanov, patSidorov, tomorrow + 3600);
    Appointment app2(drPetrova, patKuznetsova, tomorrow + 7200);

    std::cout << app1.getInfo() << "\n";
    std::cout << app2.getInfo() << "\n";

    return 0;
}
