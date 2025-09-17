#ifndef PATIENT_H
#define PATIENT_H

#include "Person.h"

class Patient : public Person {
    string medicalHistory;

public:
    Patient();
    Patient(int id, const string &name, int age, const string &gender, const string &phone, const string &mh);

    void setMedicalHistory(const string &s);
    string getMedicalHistory() const;

    string toFileString() const override;
    static Patient fromFileString(const string &line);
};

#endif
