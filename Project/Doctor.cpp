#include "Doctor.h"
#include <sstream>
#include <stdexcept>
#include <algorithm>

using namespace std;

static vector<string> splitStr(const string &s, char delim) {
    vector<string> res;
    string token;
    istringstream ss(s);
    while (getline(ss, token, delim)) res.push_back(token);
    return res;
}

static string joinStr(const vector<string>& parts, char delim) {
    string out;
    for (size_t i=0;i<parts.size();++i) {
        out += parts[i];
        if (i+1<parts.size()) out.push_back(delim);
    }
    return out;
}

Doctor::Doctor() {}
Doctor::Doctor(int id, const string &name, int age, const string &gender, const string &phone,
               const string &spec, const vector<string> &slots)
    : Person(id,name,age,gender,phone), specialization(spec), timeSlots(slots) {}

string Doctor::getSpecialization() const { return specialization; }
const vector<string>& Doctor::getTimeSlots() const { return timeSlots; }
void Doctor::addTimeSlot(const string &s) { timeSlots.push_back(s); }
bool Doctor::hasSlot(const string &s) const {
    return find(timeSlots.begin(), timeSlots.end(), s) != timeSlots.end();
}

string Doctor::toFileString() const {
    string slots = joinStr(timeSlots, ';');
    return Person::toFileString() + "|" + specialization + "|" + slots;
}

Doctor Doctor::fromFileString(const string &line) {
    auto t = splitStr(line, '|');
    if (t.size() < 7) throw runtime_error("Bad doctor record");
    vector<string> slots = t[6].empty() ? vector<string>() : splitStr(t[6], ';');
    return Doctor(stoi(t[0]), t[1], stoi(t[2]), t[3], t[4], t[5], slots);
}
