#ifndef HOSPITALSYSTEM_H
#define HOSPITALSYSTEM_H

#include "Patient.h"
#include "Doctor.h"
#include "Staff.h"
#include <vector>
#include <stack>
#include <string>

class HospitalSystem {
    std::vector<Patient> patients;
    std::vector<Doctor> doctors;
    std::vector<Staff> staff;

    std::stack<std::string> undoStack;

    int nextPatientId = 1;
    int nextDoctorId = 1;
    int nextStaffId = 1;

    void loadAll();
    void saveAll();

    void loadPatients();
    void savePatients();
    void loadDoctors();
    void saveDoctors();
    void loadStaff();
    void saveStaff();

    void addPatient();
    void viewPatients();
    void addDoctor();
    void viewDoctors();
    void addStaff();
    void viewStaff();

    void bookAppointment();
    void viewAppointments();

    void undo();

public:
    HospitalSystem();
    void mainLoop();
};

#endif
