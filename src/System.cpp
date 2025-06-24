#include "../include/System.hpp"

System::~System() {
    for (int i = 0; i < m_doctors.size(); ++i) {
        delete m_doctors[i];
    }
    for (int i = 0; i < m_patients.size(); ++i) {
        delete m_patients[i];
    }
}

void System::add_doctor(const std::string& name, const std::string& specz, size_t yoe, const std::string& contact) {
    m_doctors.push_back(new Doctor(name, specz, yoe, contact));
}

void System::remove_doctor(size_t did) {
    for (int i = 0; i < m_doctors.size(); ++i) {
        if (m_doctors[i]->get_did() == did) {
            delete m_doctors[i];
            m_doctors.erase(m_doctors.begin() + i);
            return;
        }
    }
}

void System::add_patient(const std::string& name, Gender gender, const std::string& dob, const std::string& contact, Condition condition) {
    m_patients.push_back(new Patient(name, gender, dob, contact, condition));
}

void System::remove_patient(size_t pid) {
    for (int i = 0; i < m_doctors.size(); ++i) { // loop through all doctors
        for (int j = 0; j < m_doctors[i]->get_dpids_size(); ++j) { // loop through doctor's patients
            if (m_doctors[i]->get_dpid(j) == pid) { // if doctor's patient id equals to passed argument(pid)
                m_doctors[i]->unassign_patient(m_doctors[i]->get_dpid(j)); // unassign the patient
                break;
            }
        }
    }
}

Doctor* System::find_doctor(size_t did) const {
    for (int i = 0; i < m_doctors.size(); ++i) {
        if (m_doctors[i]->get_did() == did) {
            return m_doctors[i];
        }
    }
    std::cout << "No doctor exists with " << did << " ID" << std::endl;
    return nullptr;
}

Patient* System::find_patient(size_t pid) const {
    for (int i = 0; i < m_patients.size(); ++i) {
        if (m_patients[i]->get_pid() == pid) {
            return m_patients[i];
        }
    }
    std::cout << "No patient exists with " << pid << " ID" << std::endl;
    return nullptr;
}

void System::assign_patient_to_doctor(size_t pid, size_t did) {
    for (int i = 0; i < m_doctors.size(); ++i) {
        if (m_doctors[i]->get_did() == did) {
            for (int j = 0; i < m_doctors[i]->get_dpids_size(); ++j) {
                if (m_doctors[i]->get_dpid(j) == pid) {
                    m_doctors[i]->assign_patient(pid);
                    return;
                }
            }
            std::cout << "Doctor with " << did << " ID doesn't have a Patient by " << pid << " ID" << std::endl;
            return;
        }
    }
    std::cout << "Doctor with " << did << " ID doesn't exist" << std::endl;
}