cmake_minimum_required(VERSION 3.14)
project(Polyclinic VERSION 1.0 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(GTest REQUIRED)

set(LIB_SOURCES
  Lib/Person.cpp
  Lib/Doctor.cpp
  Lib/Patient.cpp
  Lib/Appointment.cpp
)

set(APP_SOURCES
  App/main.cpp
)

add_library(Lib ${LIB_SOURCES})

target_include_directories(Lib PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/lib)

add_executable(PolyclinicApp ${APP_SOURCES})
target_link_libraries(PolyclinicApp PRIVATE Lib)

add_subdirectory(Tests)
