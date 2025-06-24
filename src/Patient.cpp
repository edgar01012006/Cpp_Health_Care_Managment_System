#include "../include/Patient.hpp"

size_t Patient::m_pid_count = 0;

Patient::Patient(const std::string& name, Gender gender, const std::string& dob, const std::string& contact, Condition condition) 
    : m_pid {m_pid_count++}, m_name {name}, m_gender {gender}, m_dob {dob}, m_contact {contact}, m_condition {condition} {
    //empty
}

Patient::~Patient() {
    //empty
}

std::string gender_to_string(Gender gender) {
    switch (gender) {
        case Gender::MALE: return "Male";
        case Gender::FEMALE: return "Female";
    }
    return "Unknown";
}

std::string condition_to_string(Condition condition) {
    switch (condition) {
        case Condition::UNKNOWN: return "UNKNOWN";
        case Condition::STABLE: return "STABLE";
        case Condition::CRITICAL: return "CRITICAL";
        case Condition::RECOVERING: return "RECOVERING";
        case Condition::DISCHARGED: return "DISCHARGED";
    }
    return "Unknown";
}

std::ostream& operator<<(std::ostream& out, const Patient& src) {
    out << "ID: " << src.m_pid << std::endl;
    out << "Name: " << src.m_name << std::endl;
    out << "Gender: " << gender_to_string(src.m_gender) << std::endl;
    out << "Date of Birth: " << src.m_dob << std::endl;
    out << "Contact: " << src.m_contact << std::endl;
    out << "Condition: " << condition_to_string(src.m_condition) << std::endl;
    return out;
}

void Patient::add_Medical_Case(const Medical_Case& med_case) {
    m_med_cases.push_back(med_case);
}

size_t Patient::get_pid() const {
    return m_pid;
}