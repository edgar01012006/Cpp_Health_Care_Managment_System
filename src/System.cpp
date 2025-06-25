#include "../include/System.hpp"

System::~System() {
    for (int i = 0; i < m_doctors.size(); ++i) {
        delete m_doctors[i];
    }
    for (int i = 0; i < m_patients.size(); ++i) {
        delete m_patients[i];
    }
}

std::ostream& operator<<(std::ostream& out, const System& src) {
    for (int i = 0; i < src.m_doctors.size(); ++i) {
        std::cout << src.m_doctors[i] << std::endl;
    }
    for (int i = 0; i < src.m_patients.size(); ++i) {
        std::cout << src.m_patients[i] << std::endl;
    }
}

bool System::is_doctor(size_t did) const {
    for (int i = 0; i < m_doctors.size(); ++i) {
        if (m_doctors[i]->get_did() == did) {
            return true;
        }
    }
    return false;
}

bool System::is_patient(size_t pid) const {
    for (int i = 0; i < m_patients.size(); ++i) {
        if (m_patients[i]->get_pid() == pid) {
            return true;
        }
    }
    return false;
}

bool System::is_patient_of_doctor(size_t pid, size_t did) const {
    if (is_patient(pid) == false) {
        return false;
    }
    else if (is_doctor(did) == false) {
        return false;
    }
    size_t d_index = find_doctor_index(did);
    for (int i = 0; i < m_doctors[d_index]->get_dpids_size(); ++i) {
        if (m_doctors[d_index]->get_dpid(i) == pid) {
            return true;
        }
    }
    return false;
}

size_t System::find_doctor_index(size_t did) const {
    for (int i = 0; i < m_doctors.size(); ++i) {
        if (m_doctors[i]->get_did() == did) {
            return i;
        }
    }
}

size_t System::find_patient_index(size_t pid) const {
    for (int i = 0; i < m_patients.size(); ++i) {
        if (m_patients[i]->get_pid() == pid) {
            return i;
        }
    }
}

size_t System::find_patient_of_doctor_index(size_t pid, size_t did) const {
    size_t d_index = find_doctor_index(did);
    for (int i = 0; i < m_doctors[d_index]->get_dpids_size(); ++i) {
        if (m_doctors[d_index]->get_dpid(i) == pid) {
            return i;
        }
    }
}

void System::add_doctor(const std::string& name, const std::string& specz, size_t yoe, const std::string& contact) {
    m_doctors.push_back(new Doctor(name, specz, yoe, contact));
}

void System::remove_doctor(size_t did) {
    if (is_doctor(did) == false) {
        return;
    }
    size_t d_index = find_doctor_index(did);
    delete m_doctors[d_index];
    m_doctors.erase(m_doctors.begin() + d_index);
}

void System::add_patient(const std::string& name, Gender gender, const std::string& dob, const std::string& contact, Condition condition) {
    m_patients.push_back(new Patient(name, gender, dob, contact, condition));
}

void System::remove_patient(size_t pid) {
    if (is_patient(pid) == false) {
        return;
    }
    for (int i = 0; i < m_doctors.size(); ++i) {
        if (is_patient_of_doctor(pid, m_doctors[i]->get_did()) == true) {
            m_doctors[i]->unassign_patient(find_patient_of_doctor_index(pid, m_doctors[i]->get_did()));
        }
    }
    size_t p_index = find_patient_index(pid);
    delete m_patients[p_index];
    m_patients.erase(m_patients.begin() + p_index);
}

Doctor* System::find_doctor(size_t did) const {
    if (is_doctor(did) == false) {
        std::cout << "No doctor exists with " << did << " ID" << std::endl;
        return nullptr;
    }
    return m_doctors[find_doctor_index(did)];
}

Patient* System::find_patient(size_t pid) const {
    if (is_patient(pid) == false) {
        std::cout << "No patient exists with " << pid << " ID" << std::endl;
        return nullptr;
    }
    return m_patients[find_patient_index(pid)];
}

void System::assign_patient_to_doctor(size_t pid, size_t did) {
    if (is_patient(pid) == false) {
        return;
    }
    else if (is_doctor(did) == false) {
        return;
    }
    else if (is_patient_of_doctor(pid, did) == true) {
        return;
    }
    m_doctors[find_doctor_index(did)]->assign_patient(pid);
}

void System::give_medical_case_to_patient(size_t pid, size_t did) {
    if (is_patient_of_doctor(pid, did) == false) {
        return;
    }
    m_patients[find_patient_index(pid)]->add_Medical_Case(m_doctors[find_doctor_index(did)]->give_medical_case(pid));
}

