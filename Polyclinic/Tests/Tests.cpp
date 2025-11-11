#include <gtest/gtest.h>
#include "../Lib/Doctor.h"
#include "../Lib/Patient.h"

TEST(PersonTest, DoctorInfo) {
    Doctor d("Alexey", "Ivanov", "Sergeevich", "Terapist", "205");
    std::string info = d.getInfo();
    EXPECT_NE(info.find("Ivanov A.S."), std::string::npos);
    EXPECT_NE(info.find("Terapist"), std::string::npos);
}

TEST(PersonTest, PatientInfo) {
    Patient p("Ivan", "Sidorov", "Petrovich", "123-456-789");
    std::string info = p.getInfo();
    EXPECT_NE(info.find("Sidorov Ivan Petrovich"), std::string::npos);
    EXPECT_NE(info.find("123-456-789"), std::string::npos);
}
