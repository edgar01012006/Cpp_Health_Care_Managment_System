#include <gtest/gtest.h>
#include "../include/System.hpp"

TEST(SystemTest, PatientsCount) {
    System system;
    system.add_patient("Josh", Gender::MALE, "05/07/2000", "Josh@gmail.com", Condition::STABLE);
    system.add_patient("Anna", Gender::FEMALE, "03/08/1995", "Anna@gmail.com", Condition::RECOVERING);
    EXPECT_EQ(system.patients_count(), 2);
}

TEST(SystemTest, DoctorsCount) {
    System system;
    system.add_doctor("Emily", "Cardiology", 15, "emily@hospital.com");
    system.add_doctor("Michael", "Neurology", 20, "michael@hospital.com");
    EXPECT_EQ(system.doctors_count(), 2);
}

TEST(SystemTest, AssignPatientsToDoctor) {
    System system;
    system.add_patient("Josh", Gender::MALE, "05/07/2000", "Josh@gmail.com", Condition::STABLE);
    system.add_patient("Anna", Gender::FEMALE, "03/08/1995", "Anna@gmail.com", Condition::RECOVERING);
    system.add_doctor("Emily", "Cardiology", 15, "emily@hospital.com");
    system.add_doctor("Michael", "Neurology", 20, "michael@hospital.com");
    system.assign_patient_to_doctor(2, 2);
    system.assign_patient_to_doctor(3, 3);
    EXPECT_TRUE(system.is_patient_of_doctor(2, 2));
    EXPECT_TRUE(system.is_patient_of_doctor(3, 3));
    EXPECT_FALSE(system.is_patient_of_doctor(2, 3));
}

TEST(SystemTest, AddMedicalCaseForPatient) {
    System system;
    system.add_patient("Anna", Gender::FEMALE, "03/08/1995", "Anna@gmail.com", Condition::RECOVERING);
    system.add_doctor("Michael", "Neurology", 20, "michael@hospital.com");
    system.assign_patient_to_doctor(4, 4); // Anna->Michael
    Medical_Case med_case("Flu", "Rest and hydration", "Paracetamol");
    system.find_patient(4)->add_Medical_Case(med_case);
    EXPECT_EQ(system.find_patient(4)->get_med_cases_count(), 1);
}


