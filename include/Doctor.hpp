#ifndef DOCTOR_HPP
#define DOCTOR_HPP

#include <string>
#include <vector>
#include <ostream>
#include "Medical_Case.hpp"

class Doctor {
    public:
        Doctor(const std::string& name, const std::string specz, size_t yoe, const std::string& contact);
        Doctor(const Doctor& other) = delete;
        Doctor(Doctor&& other) = delete;
        ~Doctor() = default;
        friend std::ostream& operator<<(std::ostream& out, const Doctor& src);
        void assign_patient(size_t pid);
        void unassign_patient(size_t pid);
        Medical_Case give_medical_case(size_t pid);
        size_t get_did() const; // doctor id
        size_t get_dpids_size() const; // doctor's patients size
        size_t get_dpid(size_t cnt) const; // doctor's patient id
    private:
        static size_t m_did_count;
        size_t m_did; // doctor id
        std::string m_name;
        std::string m_specz; // specialization
        size_t m_yoe; // years of experience
        std::string m_contact;
        std::vector<size_t> m_pids; // patients id's
};

#endif /* DOCTOR_HPP */