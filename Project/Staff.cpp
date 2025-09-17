#include "Staff.h"
#include <sstream>
#include <stdexcept>
#include <vector>
using namespace std;

static vector<string> splitStr(const string &s, char delim) {
    vector<string> res;
    string token;
    istringstream ss(s);
    while (getline(ss, token, delim)) res.push_back(token);
    return res;
}

Staff::Staff() {}
Staff::Staff(int id, const string &name, int age, const string &gender, const string &phone, const string &role)
    : Person(id,name,age,gender,phone), role(role) {}

string Staff::getRole() const { return role; }
void Staff::setRole(const string &r) { role = r; }

string Staff::toFileString() const {
    return Person::toFileString() + "|" + role;
}

Staff Staff::fromFileString(const string &line) {
    auto t = splitStr(line, '|');
    if (t.size() < 6) throw runtime_error("Bad staff record");
    return Staff(stoi(t[0]), t[1], stoi(t[2]), t[3], t[4], t[5]);
}
