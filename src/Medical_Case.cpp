#include "../include/Medical_Case.hpp"

Medical_Case::Medical_Case(const std::string& diagnose, const std::string& treatment, const std::string& medication) 
    : m_diagnose {diagnose}, m_treatment {treatment}, m_medication {medication} {
    //empty;
}

Medical_Case::Medical_Case(const Medical_Case& other) {
    this->m_diagnose = other.m_diagnose;
    this->m_treatment = other.m_treatment;
    this->m_medication = other.m_medication;
}

Medical_Case& Medical_Case::operator=(const Medical_Case& other) {
    if (this == &other) {
        return *this;
    }
    this->m_diagnose = other.m_diagnose;
    this->m_treatment = other.m_treatment;
    this->m_medication = other.m_medication;
    return *this;
}

Medical_Case::Medical_Case(Medical_Case&& other) {
    this->m_diagnose = std::move(other.m_diagnose);
    this->m_treatment = std::move(other.m_treatment);
    this->m_medication = std::move(other.m_medication);
}

Medical_Case& Medical_Case::operator=(Medical_Case&& other) {
    if (this == &other) {
        return* this;
    }
    this->m_diagnose = std::move(other.m_diagnose);
    this->m_treatment = std::move(other.m_treatment);
    this->m_medication = std::move(other.m_medication);
    return *this;
}

std::ostream& operator<<(std::ostream& out, const Medical_Case& src) {
    out << "Diagnose: "  << src.m_diagnose << std::endl;
    out << "Treatment: " << src.m_treatment << std::endl;
    out << "Medication: " << src.m_medication << std::endl;
    return out;
}

std::istream& operator>>(std::istream& in, Medical_Case& src) {
    std::cout << "Enter Diagnose: ";
    in >> src.m_diagnose;
    std::cout << "Enter Treatment: ";
    in >> src.m_treatment;
    std::cout << "Enter Medication: ";
    in >> src.m_medication;
    return in;
}