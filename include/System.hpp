#ifndef SYSTEM_HPP
#define SYSTEM_HPP

#include <vector>
#include <string>
#include "Doctor.hpp"
#include "Patient.hpp"

class System {
    public:
        System(); // maybe default
        System(const System& other) = delete;
        System(System&& other) = delete;
        ~System();
        void add_doctor(const std::string& name, const std::string& specz, size_t yoe, const std::string& contact);
        void remove_doctor(size_t did);
        void add_patient(const std::string& name, Gender gender, const std::string& dob, const std::string& contact, Condition condition);
        void remove_patient(size_t pid);
        Doctor* find_doctor(size_t did) const;
        Patient* find_patient(size_t pid) const;
        // void display(); // dont know its use for now
    private:
        std::vector<Doctor*> m_doctors;
        std::vector<Patient*> m_patients;
};

#endif /* SYSTEM_HPP */