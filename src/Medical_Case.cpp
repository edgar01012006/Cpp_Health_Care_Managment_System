#include "../include/Medical_Case.hpp"

std::ostream& operator<<(std::ostream& out, const Medical_Case& src) {
    out << src.m_diagnose << src.m_medication << src.m_treatment;
}