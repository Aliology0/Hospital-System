#include "Person.h"
#include <sstream>

Person::Person() {}
Person::Person(int id, const string &name, int age, const string &gender, const string &phone)
    : id(id), name(name), age(age), gender(gender), phone(phone) {}

Person::~Person() {}

int Person::getId() const { return id; }
string Person::getName() const { return name; }
void Person::setName(const string &n) { name = n; }
void Person::setAge(int a) { age = a; }
void Person::setGender(const string &g) { gender = g; }
void Person::setPhone(const string &p) { phone = p; }

string Person::toFileString() const {
    ostringstream oss;
    oss << id << "|" << name << "|" << age << "|" << gender << "|" << phone;
    return oss.str();
}
