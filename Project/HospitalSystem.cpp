#include "HospitalSystem.h"
#include <iostream>
#include <fstream>
#include <sstream>
#include <stdexcept>
#include <algorithm>
using namespace std;

// ---------------- Constructors ----------------
HospitalSystem::HospitalSystem() {
    loadAll();
}

// ---------------- File Handling ----------------
void HospitalSystem::loadAll() {
    loadPatients();
    loadDoctors();
    loadStaff();
}

void HospitalSystem::saveAll() {
    savePatients();
    saveDoctors();
    saveStaff();
}

// Patients
void HospitalSystem::loadPatients() {
    patients.clear();
    ifstream fin("patients.txt");
    string line;
    while (getline(fin, line)) {
        try {
            patients.push_back(Patient::fromFileString(line));
            nextPatientId = max(nextPatientId, patients.back().getId() + 1);
        } catch (...) {}
    }
}

void HospitalSystem::savePatients() {
    ofstream fout("patients.txt");
    for (auto &p : patients) fout << p.toFileString() << "\n";
}

// Doctors
void HospitalSystem::loadDoctors() {
    doctors.clear();
    ifstream fin("doctors.txt");
    string line;
    while (getline(fin, line)) {
        try {
            doctors.push_back(Doctor::fromFileString(line));
            nextDoctorId = max(nextDoctorId, doctors.back().getId() + 1);
        } catch (...) {}
    }
}

void HospitalSystem::saveDoctors() {
    ofstream fout("doctors.txt");
    for (auto &d : doctors) fout << d.toFileString() << "\n";
}

// Staff
void HospitalSystem::loadStaff() {
    staff.clear();
    ifstream fin("staff.txt");
    string line;
    while (getline(fin, line)) {
        try {
            staff.push_back(Staff::fromFileString(line));
            nextStaffId = max(nextStaffId, staff.back().getId() + 1);
        } catch (...) {}
    }
}

void HospitalSystem::saveStaff() {
    ofstream fout("staff.txt");
    for (auto &s : staff) fout << s.toFileString() << "\n";
}

// ---------------- Patients ----------------
void HospitalSystem::addPatient() {
    string name, gender, phone, mh;
    int age;
    cout << "Enter name: "; getline(cin, name);
    cout << "Enter age: "; cin >> age; cin.ignore();
    cout << "Enter gender: "; getline(cin, gender);
    cout << "Enter phone: "; getline(cin, phone);
    cout << "Enter medical history: "; getline(cin, mh);

    Patient p(nextPatientId++, name, age, gender, phone, mh);
    patients.push_back(p);
    undoStack.push("patient:" + to_string(p.getId()));
    savePatients();
    cout << "Patient added!\n";
}

void HospitalSystem::viewPatients() {
    for (auto &p : patients) {
        cout << p.getId() << " - " << p.getName() << " (" << p.getMedicalHistory() << ")\n";
    }
}

// ---------------- Doctors ----------------
void HospitalSystem::addDoctor() {
    string name, gender, phone, spec;
    int age;
    cout << "Enter name: "; getline(cin, name);
    cout << "Enter age: "; cin >> age; cin.ignore();
    cout << "Enter gender: "; getline(cin, gender);
    cout << "Enter phone: "; getline(cin, phone);
    cout << "Enter specialization: "; getline(cin, spec);

    Doctor d(nextDoctorId++, name, age, gender, phone, spec, {});
    doctors.push_back(d);
    undoStack.push("doctor:" + to_string(d.getId()));
    saveDoctors();
    cout << "Doctor added!\n";
}

void HospitalSystem::viewDoctors() {
    for (auto &d : doctors) {
        cout << d.getId() << " - " << d.getName() << " [" << d.getSpecialization() << "]\n";
    }
}

// ---------------- Staff ----------------
void HospitalSystem::addStaff() {
    string name, gender, phone, role;
    int age;
    cout << "Enter name: "; getline(cin, name);
    cout << "Enter age: "; cin >> age; cin.ignore();
    cout << "Enter gender: "; getline(cin, gender);
    cout << "Enter phone: "; getline(cin, phone);
    cout << "Enter role: "; getline(cin, role);

    Staff s(nextStaffId++, name, age, gender, phone, role);
    staff.push_back(s);
    undoStack.push("staff:" + to_string(s.getId()));
    saveStaff();
    cout << "Staff added!\n";
}

void HospitalSystem::viewStaff() {
    for (auto &s : staff) {
        cout << s.getId() << " - " << s.getName() << " (" << s.getRole() << ")\n";
    }
}

// ---------------- Appointments ----------------
void HospitalSystem::bookAppointment() {
    int pid, did;
    string slot;
    cout << "Enter patient ID: "; cin >> pid;
    cout << "Enter doctor ID: "; cin >> did;
    cin.ignore();
    cout << "Enter time slot: "; getline(cin, slot);

    auto pIt = find_if(patients.begin(), patients.end(), [&](auto &p){ return p.getId()==pid; });
    auto dIt = find_if(doctors.begin(), doctors.end(), [&](auto &d){ return d.getId()==did; });

    if (pIt==patients.end() || dIt==doctors.end()) {
        cout << "Invalid IDs\n"; return;
    }
    if (!dIt->hasSlot(slot)) {
        cout << "Slot not available\n"; return;
    }

    dIt->slotQueues[slot].push(pid);
    cout << "Appointment booked for " << pIt->getName() << " with Dr. " << dIt->getName() << " at " << slot << "\n";
}

void HospitalSystem::viewAppointments() {
    for (auto &d : doctors) {
        cout << "Doctor " << d.getName() << " (" << d.getSpecialization() << ")\n";
        for (auto &s : d.slotQueues) {
            cout << "  Slot " << s.first << ": ";
            auto q = s.second;
            while (!q.empty()) {
                int pid = q.front(); q.pop();
                auto pIt = find_if(patients.begin(), patients.end(), [&](auto &p){ return p.getId()==pid; });
                if (pIt != patients.end()) cout << pIt->getName() << " ";
            }
            cout << "\n";
        }
    }
}

// ---------------- Undo ----------------
void HospitalSystem::undo() {
    if (undoStack.empty()) {
        cout << "Nothing to undo\n"; return;
    }
    string last = undoStack.top(); undoStack.pop();
    stringstream ss(last);
    string type, idStr;
    getline(ss, type, ':'); getline(ss, idStr);
    int id = stoi(idStr);

    if (type=="patient") {
        patients.erase(remove_if(patients.begin(), patients.end(),
                                 [&](auto &p){return p.getId()==id;}), patients.end());
        savePatients();
        cout << "Undid add patient\n";
    } else if (type=="doctor") {
        doctors.erase(remove_if(doctors.begin(), doctors.end(),
                                [&](auto &d){return d.getId()==id;}), doctors.end());
        saveDoctors();
        cout << "Undid add doctor\n";
    } else if (type=="staff") {
        staff.erase(remove_if(staff.begin(), staff.end(),
                              [&](auto &s){return s.getId()==id;}), staff.end());
        saveStaff();
        cout << "Undid add staff\n";
    }
}

// ---------------- Main Menu ----------------
void HospitalSystem::mainLoop() {
    while (true) {
        cout << "\n--- Hospital Menu ---\n";
        cout << "1. Add Patient\n2. View Patients\n";
        cout << "3. Add Doctor\n4. View Doctors\n";
        cout << "5. Add Staff\n6. View Staff\n";
        cout << "7. Book Appointment\n8. View Appointments\n";
        cout << "9. Undo\n0. Exit\n> ";

        int ch; cin >> ch; cin.ignore();
        switch (ch) {
            case 1: addPatient(); break;
            case 2: viewPatients(); break;
            case 3: addDoctor(); break;
            case 4: viewDoctors(); break;
            case 5: addStaff(); break;
            case 6: viewStaff(); break;
            case 7: bookAppointment(); break;
            case 8: viewAppointments(); break;
            case 9: undo(); break;
            case 0: saveAll(); return;
            default: cout << "Invalid choice\n";
        }
    }
}
