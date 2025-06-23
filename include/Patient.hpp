#ifndef PATIENT_HPP
#define PATIENT_HPP

#include <string>
#include <vector>

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
    private:
        static size_t m_pid_count;
        size_t m_pid; // patient id
        std::string m_name;
        Gender m_gender;
        std::string m_dob; // date of birth; could replace with chrono library year_month_day later;
        std::string m_contact;
        Condition m_condition;
        // std::vector<MemoryDiagnoses> m_diagnoses; /* Implement Later! */
};

#endif /* PATIENT_HPP */