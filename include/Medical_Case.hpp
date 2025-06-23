#ifndef MEDICAL_CASE_HPP
#define MEDICAL_CASE_HPP

#include <iostream>
#include <string>
#include <ostream>

class Medical_Case {
    public:
        Medical_Case(const std::string& diagnose, const std::string& treatment, const std::string& medication);
        Medical_Case(const Medical_Case& other);
        Medical_Case(Medical_Case&& other);
        ~Medical_Case() = default;
        friend std::ostream& operator<<(std::ostream& out, const Medical_Case& src);
    private:
        std::string m_diagnose;
        std::string m_treatment;
        std::string m_medication;
};

#endif /* MEDICAL_CASE_HPP */ 