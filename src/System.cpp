#include "../include/System.hpp"

System::~System() {
    for (size_t i = 0; i < m_doctors.size(); ++i) {
        delete m_doctors[i];
    }
    for (size_t i = 0; i < m_patients.size(); ++i) {
        delete m_patients[i];
    }
}

std::ostream& operator<<(std::ostream& out, const System& src) {
    for (size_t i = 0; i < src.m_doctors.size(); ++i) {
        out << *(src.m_doctors[i]) << std::endl;
    }
    for (size_t i = 0; i < src.m_patients.size(); ++i) {
        out << *(src.m_patients[i]) << std::endl;
    }
    return out;
}

bool System::is_doctor(size_t did) const {
    for (size_t i = 0; i < m_doctors.size(); ++i) {
        if (m_doctors[i]->get_did() == did) {
            return true;
        }
    }
    return false;
}

bool System::is_patient(size_t pid) const {
    for (size_t i = 0; i < m_patients.size(); ++i) {
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
    for (size_t i = 0; i < m_doctors[d_index]->get_dpids_size(); ++i) {
        if (m_doctors[d_index]->get_dpid(i) == pid) {
            return true;
        }
    }
    return false;
}

size_t System::find_doctor_index(size_t did) const {
    for (size_t i = 0; i < m_doctors.size(); ++i) {
        if (m_doctors[i]->get_did() == did) {
            return i;
        }
    }
    return 0;
}

size_t System::find_patient_index(size_t pid) const {
    for (size_t i = 0; i < m_patients.size(); ++i) {
        if (m_patients[i]->get_pid() == pid) {
            return i;
        }
    }
    return 0;
}

size_t System::find_patient_of_doctor_index(size_t pid, size_t did) const {
    size_t d_index = find_doctor_index(did);
    for (size_t i = 0; i < m_doctors[d_index]->get_dpids_size(); ++i) {
        if (m_doctors[d_index]->get_dpid(i) == pid) {
            return i;
        }
    }
    return 0;
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
    for (size_t i = 0; i < m_doctors.size(); ++i) {
        if (is_patient_of_doctor(pid, m_doctors[i]->get_did()) == true) {
            m_doctors[i]->unassign_patient(pid);
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

void System::generate_report(size_t pid) {
    std::cout << *(find_patient(pid));
    std::cout << "* Medical History *" << std::endl; find_patient(pid)->print_medical_history(); std::cout << std::endl;
    save_report(pid);
}

void System::save_report(size_t pid) {
    if (is_patient(pid) == false) {
        return;
    }
    time_t now = time(NULL);
    struct tm *local = localtime(&now);
    std::string file_name = find_patient(pid)->get_pname() + std::to_string(1900 + local->tm_year) + "_" + std::to_string(1 + local->tm_mon)+ "_" + std::to_string(local->tm_mday);
    std::ofstream file("../generated_reports/" + file_name + ".txt");
    if (!file.is_open()) {
        std::cout << "Failed to open";
        return;
    }
    file << "* Medical History *" << std::endl;
    find_patient(pid)->print_medical_history(file);
}