#include "../include/Doctor.hpp"

size_t Doctor::m_did_count = 0;

Doctor::Doctor(const std::string& name, const std::string specz, size_t yoe, const std::string& contact)
    : m_did {m_did_count++}, m_name {name}, m_specz {specz}, m_yoe {yoe}, m_contact {contact} {
    //empty
}

std::ostream& operator<<(std::ostream& out, const Doctor& src) {
    out << "Doctor ID: " << src.m_did << std::endl;
    out << "Name: " << src.m_name << std::endl;
    out << "Specialization: " << src.m_specz << std::endl;
    out << "Years of experience: " << src.m_yoe << std::endl;
    out << "Contact: " << src.m_contact << std::endl;
    return out;
}

void Doctor::assign_patient(size_t pid) {
    m_pids.push_back(pid);
}

void Doctor::unassign_patient(size_t pid) {
    for (size_t i = 0; i < m_pids.size(); ++i) {
        if (pid == m_pids[i]) {
            m_pids.erase(m_pids.begin() + i);
            return;
        }
    }
}

Medical_Case Doctor::give_medical_case(size_t pid) {
    Medical_Case med_case;
    for (size_t i = 0; i < m_pids.size(); ++i) {
        if (pid == m_pids[i]) {
            std::cin >> med_case;
            return med_case;
        }
    }
    return med_case;
}

size_t Doctor::get_did() const {
    return m_did;
}

size_t Doctor::get_dpids_size() const {
    return m_pids.size();
}

size_t Doctor::get_dpid(size_t cnt) const {
    return m_pids[cnt];
}