#ifndef DOCTOR_HPP
#define DOCTOR_HPP

#include <string>

class Doctor {
    public:
        Doctor(const std::string& name, const std::string specz, size_t yoe, const std::string& contact);
        Doctor(const Doctor& other) = delete;
        Doctor(Doctor&& other) = delete;
        ~Doctor() = default;
    private:
        static size_t m_did_count;
        size_t m_did; // doctor id
        std::string m_name;
        std::string m_specz; // specialization
        size_t m_yoe; // years of experience
        std::string m_contact;
};

#endif /* DOCTOR_HPP */