#ifndef DOCTOR_H
#define DOCTOR_H

#include "Person.h"
#include <vector>
#include <queue>
#include <unordered_map>

class Doctor : public Person {
    string specialization;
    std::vector<string> timeSlots;

public:
    std::unordered_map<string, std::queue<int>> slotQueues;

    Doctor();
    Doctor(int id, const string &name, int age, const string &gender, const string &phone,
           const string &spec, const std::vector<string> &slots);

    string getSpecialization() const;
    const std::vector<string>& getTimeSlots() const;
    void addTimeSlot(const string &s);
    bool hasSlot(const string &s) const;

    string toFileString() const override;
    static Doctor fromFileString(const string &line);
};

#endif
