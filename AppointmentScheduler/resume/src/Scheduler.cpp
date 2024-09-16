// Created by Will on 11/22/2023

#include "Person.h"
#include "Pet.h"
#include "Appointment.h"
#include "GroomingAppointment.h"
#include "HaircutAppointment.h"
#include "Scheduler.h"
#include <fstream>
#include <iostream>
#include <algorithm>
#include <iomanip>
#include <vector>
#include <string>

void Scheduler::LoadAppointments(std::string filename){
    std::ifstream in(filename);
    if (!in.is_open()) {
        std::cout << "Could not open file" << std::endl;
    }

    std::shared_ptr<Appointment> appointment;
    std::string line, choice, groomer_first_name, groomer_last_name, groomer_phone,owner_first_name,
    owner_last_name, owner_phone, pet_name, pet_type, g_price, h_price, date, time;
    double grooming_price, haircut_price;

    while (std::getline(in, line)) {
        std::stringstream ss(line);
        std::getline(ss, choice, ',');
        if(choice == "G"){
//            Get the variables from the file
            std::getline(ss, groomer_first_name, ',');
            std::getline(ss, groomer_last_name, ',');
            std::getline(ss, groomer_phone, ',');
            std::getline(ss, owner_first_name, ',');
            std::getline(ss, owner_last_name, ',');
            std::getline(ss, owner_phone, ',');
            std::getline(ss, pet_name, ',');
            std::getline(ss, pet_type, ',');
            std::getline(ss, g_price, ',');
            grooming_price = stod(g_price);
            std::getline(ss, date, ',');
            std::getline(ss, time, ',');

//            Assign variables to objects
            Person groomer(groomer_first_name, groomer_last_name, groomer_phone);
            Person owner(owner_first_name, owner_last_name, owner_phone);
            Pet pet(owner_first_name, owner_last_name, owner_phone, pet_name, pet_type);
            DateTime datetime1(date, time);

            std::shared_ptr<Appointment> appointment = std::make_shared<GroomingAppointment>(groomer, pet, date, time, grooming_price);
            appointments_.push_back(appointment);

        }

        else{
//            Get the variables from the file
            std::getline(ss, groomer_first_name, ',');
            std::getline(ss, groomer_last_name, ',');
            std::getline(ss, groomer_phone, ',');
            std::getline(ss, owner_first_name, ',');
            std::getline(ss, owner_last_name, ',');
            std::getline(ss, owner_phone, ',');
            std::getline(ss, pet_name, ',');
            std::getline(ss, pet_type, ',');
            std::getline(ss, g_price, ',');
            grooming_price = stod(g_price);
            std::getline(ss, h_price, ',');
            haircut_price = stod(h_price);
            std::getline(ss, date, ',');
            std::getline(ss, time, ',');

//            Assign variables to objects
            Person groomer(groomer_first_name, groomer_last_name, groomer_phone);
            Person owner(owner_first_name, owner_last_name, owner_phone);
            Pet pet(owner_first_name, owner_last_name, owner_phone, pet_name, pet_type);
            GroomingAppointment grooming1(groomer, pet, date, time, grooming_price);
            DateTime datetime1(date, time);
            std::shared_ptr<Appointment> appointment = std::make_shared<HaircutAppointment>(groomer, pet, date, time, grooming_price, haircut_price);
            appointments_.push_back(appointment);
        }
    }

    in.close();
}

std::set<std::string> Scheduler::GetAppointmentDates(){
    std::set<std::string> dates;
    for (const auto& appointment : appointments_) {
        std::string date = appointment->GetDateTime().GetDate();
        dates.insert(date);
    }
    return dates;
}

std::set<std::string> Scheduler::GetGroomers(){
    std::set<std::string> groomers;
    for (const auto& appointment : appointments_) {
        std::string name = appointment->GetGroomer().GetFirstName() + " " + appointment->GetGroomer().GetLastName();
        groomers.insert(name);
    }
    return groomers;
}

std::vector<std::shared_ptr<Appointment>> Scheduler::GetAppointmentsByDate(std::string date){
    //Filter Date
    char delimiter = '-';
    if (date.find('/') != std::string::npos) {
        delimiter = '/';
    }

    std::stringstream ss(date);
    std::string first, second, third;

    getline(ss, first, delimiter);
    getline(ss, second, delimiter);
    getline(ss, third);

    int month = stoi(first);
    int day = stoi(second);
    int year = stoi(third);

    std::string zero = "0";
    if(month < 10) {
        first = zero + std::to_string(month);
    }

    if(day < 10) {
        second = zero + std::to_string(day);
    }
    //filtered Date
    date = first + "/" + second + "/" + third;


    std::vector<std::shared_ptr<Appointment>> dates;
    for(auto i: appointments_) {
        if(i->GetDateTime().GetDate() == date){
            dates.push_back(i);
        }
    }
    return dates;
}

std::vector<std::shared_ptr<Appointment>> Scheduler::Filter(std::string groomer_firstname, std::string groomer_lastname, std::string date){
    //Filter Date
    char delimiter = '-';
    if (date.find('/') != std::string::npos) {
        delimiter = '/';
    }

    std::stringstream ss(date);
    std::string first, second, third;

    getline(ss, first, delimiter);
    getline(ss, second, delimiter);
    getline(ss, third);

    int month = stoi(first);
    int day = stoi(second);
    int year = stoi(third);

    std::string zero = "0";
    if(month < 10) {
        first = zero + std::to_string(month);
    }

    if(day < 10) {
        second = zero + std::to_string(day);
    }
    //filtered Date
    date = first + "/" + second + "/" + third;

    groomer_firstname[0] = std::toupper(groomer_firstname[0]);
    groomer_lastname[0] = std::toupper(groomer_lastname[0]);
    std::vector<std::shared_ptr<Appointment>> filtered_appointments;
    for(auto i: appointments_) {
        if (i->GetGroomer().GetFirstName() == groomer_firstname) {

            if (i->GetGroomer().GetLastName() == groomer_lastname){
                if(i->GetDateTime().GetDate() == date){
                    filtered_appointments.push_back(i);
                }

            }
        }

    }
    return filtered_appointments;
}

std::ostream& operator<<(std::ostream& out, Scheduler& schedule) {
   for (const auto& appointment : schedule.appointments_) {
        out << "Time:    " << appointment->GetDateTime().GetDate() << " " << appointment->GetDateTime().GetTime() << "\n"
           << "Client:  " << appointment->GetClient().GetName() << "\n"
           << "Groomer: " << appointment->GetGroomer().GetFirstName() << " " << appointment->GetGroomer().GetLastName() << " " << appointment->GetGroomer().GetPhone() << "\n"
           << "Price:   $" << std::fixed << std::setprecision(2) << appointment->GetBill() << "\n\n";
    }
    return out;
}


