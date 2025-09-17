#include "Patient.h"
#include <sstream>
#include <stdexcept>
#include <vector>
#include <string>

using namespace std;

static vector<string> splitStr(const string &s, char delim) {
    vector<string> res;
    string token;
    istringstream ss(s);
    while (getline(ss, token, delim)) res.push_back(token);
    return res;
}

Patient::Patient() {}
Patient::Patient(int id, const string &name, int age, const string &gender, const string &phone, const string &mh)
    : Person(id,name,age,gender,phone), medicalHistory(mh) {}

void Patient::setMedicalHistory(const string &s) { medicalHistory = s; }
string Patient::getMedicalHistory() const { return medicalHistory; }

string Patient::toFileString() const {
    return Person::toFileString() + "|" + medicalHistory;
}

Patient Patient::fromFileString(const string &line) {
    auto t = splitStr(line, '|');
    if (t.size() < 6) throw runtime_error("Bad patient record");
    return Patient(stoi(t[0]), t[1], stoi(t[2]), t[3], t[4], t[5]);
}
