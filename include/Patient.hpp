#ifndef PATIENT_HPP
#define PATIENT_HPP

#include <string>
#include <vector>
#include <ostream>
#include "Medical_Case.hpp"

enum class Gender { 
    MALE,
    FEMALE 
};

enum class Condition {
    UNKNOWN,
    STABLE,
    CRITICAL,
    RECOVERING,
    DISCHARGED
};

class Patient {
    public:
        Patient(const std::string& name, Gender gender, const std::string& dob, const std::string& contact, Condition condition);
        Patient(const Patient& other) = delete;
        Patient(Patient&& other) = delete;
        ~Patient();
        friend std::ostream& operator<<(std::ostream& out, const Patient& src);
        void add_Medical_Case(const Medical_Case& med_case);
        size_t get_pid() const;
    private:
        static size_t m_pid_count;
        size_t m_pid; // patient id
        std::string m_name;
        Gender m_gender;
        std::string m_dob; // date of birth; could replace with chrono library year_month_day later;
        std::string m_contact;
        Condition m_condition;
        std::vector<Medical_Case> m_med_cases;
};

std::string gender_to_string(Gender gender);
std::string condition_to_string(Condition condition);

#endif /* PATIENT_HPP */