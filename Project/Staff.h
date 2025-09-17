#ifndef STAFF_H
#define STAFF_H

#include "Person.h"

class Staff : public Person {
    string role;
public:
    Staff();
    Staff(int id, const string &name, int age, const string &gender, const string &phone, const string &role);

    string getRole() const;
    void setRole(const string &r);

    string toFileString() const override;
    static Staff fromFileString(const string &line);
};

#endif
