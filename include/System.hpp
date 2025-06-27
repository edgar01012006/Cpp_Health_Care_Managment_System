#ifndef SYSTEM_HPP
#define SYSTEM_HPP

#include <vector>
#include <string>
#include <ostream>
#include <ctime>
#include <fstream>
#include "Doctor.hpp"
#include "Patient.hpp"

class System {
    public:
        System() = default;
        System(const System& other) = delete;
        System(System&& other) = delete;
        ~System();
        friend std::ostream& operator<<(std::ostream& out, const System& src);
        bool is_doctor(size_t did) const;
        bool is_patient(size_t pid) const;
        bool is_patient_of_doctor(size_t pid, size_t did) const;
        /* The next 3 find functions assume that passed argument(s) are valid */
        size_t find_doctor_index(size_t pid) const;
        size_t find_patient_index(size_t pid) const;
        size_t find_patient_of_doctor_index(size_t pid, size_t did) const;
        void add_doctor(const std::string& name, const std::string& specz, size_t yoe, const std::string& contact);
        void remove_doctor(size_t did);
        void add_patient(const std::string& name, Gender gender, const std::string& dob, const std::string& contact, Condition condition);
        void remove_patient(size_t pid);
        Doctor* find_doctor(size_t did) const;
        Patient* find_patient(size_t pid) const;
        void assign_patient_to_doctor(size_t pid, size_t did);
        void give_medical_case_to_patient(size_t pid, size_t did);
        void generate_report(size_t pid);
        //tests
        size_t doctors_count() const;
        size_t patients_count() const;
    private:
        void save_report(size_t pid);
        std::vector<Doctor*> m_doctors;
        std::vector<Patient*> m_patients;
};

#endif /* SYSTEM_HPP */