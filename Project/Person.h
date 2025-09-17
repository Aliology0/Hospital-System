#ifndef PERSON_H
#define PERSON_H

#include <string>
using namespace std;

class Person {
protected:
    int id;
    string name;
    int age;
    string gender;
    string phone;

public:
    Person();
    Person(int id, const string &name, int age, const string &gender, const string &phone);
    virtual ~Person();

    int getId() const;
    string getName() const;
    void setName(const string &n);
    void setAge(int a);
    void setGender(const string &g);
    void setPhone(const string &p);

    virtual string toFileString() const;
};

#endif
