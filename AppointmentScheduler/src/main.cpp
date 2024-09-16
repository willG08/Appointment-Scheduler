// Created by Will on 11/22/2023

#include <iostream>
#include "Appointment.h"
#include "GroomingAppointment.h"
#include "HaircutAppointment.h"
#include "DateTime.h"
#include "Scheduler.h"
#include "Person.h"
#include "Pet.h"

#include <string>

using namespace std;

int main() {
    DateTime d("03/06/2023");
    std::cout << d.GetDate() << std::endl;

    while(true) {
        //    Create Menu
        std::cout << "What would you like to do?" << "\n" <<
                  "1. See List of Groomers" << "\n" <<
                  "2. See all Days with Appointments" << "\n" <<
                  "3. See Appointments with a certain date" << "\n" <<
                  "4. Filter Appointments with a specific groomer and date" << "\n" <<
                  "5. See All Appointments" << "\n" <<
                  "6. Exit" << std::endl;

        char choice;
        cin >> choice;
        cin.ignore();

        Scheduler s("../../data/appointments.csv");
        //Create Switch
        switch (choice) {
            case '1': {
                std::set<std::string> appointmentGroomers = s.GetGroomers();
                for (const std::string &groomer: appointmentGroomers) {
                    std::cout << groomer << std::endl;
                }
                std::cout << std::endl;
                break;
            }
            case '2': {
                std::set<std::string> appointmentDates = s.GetAppointmentDates();
                for (const std::string &date: appointmentDates) {
                    std::cout << date << std::endl;
                }
                std::cout << std::endl;
                break;
            }
            case '3': {
                std::cout << "What date would you like to choose from the choices above?" << std::endl;
                std::string(choice_Date);
                std::getline(std::cin, choice_Date);
                auto dates = s.GetAppointmentsByDate(choice_Date);
                for (const auto& appointment : dates) {
//                    std::cout << *appointment << std::endl;
                    appointment->Display(std::cout);
                }
                break;
            }
            case '4': {
                std::cout << "What is the first name of the groomer you would like to choose from the choices above?" << std::endl;
                std::string(choice_first);
                std::getline(std::cin, choice_first);
                std::cout << "What is the last name of the groomer you would like to choose from the choices above?" << std::endl;
                std::string(choice_last);
                std::getline(std::cin, choice_last);
                std::cout << "What date would you like to choose from the choices above?" << std::endl;
                std::string(choice_Date);
                std::getline(std::cin, choice_Date);
                auto filter = s.Filter(choice_first, choice_last, choice_Date);
                for (const auto& appointment : filter) {
                    std::cout << *appointment << std::endl;
                }
                break;
            }
            case '5': {
                auto appointments = s.GetAppointments();
                for (const auto& appointment : appointments) {
                    std::cout << *appointment << std::endl;
                }
                break;
            }
            case '6': {
                exit(0);
            }
        }

    }
//    Practicing Funcions
//    DateTime d("3/6/2023");
//
//    d.SetDate("7/8/2023");
//    d.SetTime("15:45 am");
//
//    std::cout << d.GetDate() << std::endl;
//
//
//    std::cout << d;
//
//    Person p("Will", "G", "9999");
//
//    p.SetFirstName("Bill");
//    p.SetLastName("Jobs");
//    p.SetPhone("9823337777");
//
//    Person p2("Boss", "Bottleson", "8796543210");
//
//    p == p2;
//
//    p2.SetFirstName("Bill");
//    p2.SetLastName("Jobs");
//    p2.SetPhone("9823337777");
//
//
//    p == p2;
//
//    std::cout << p2 << std::endl;
//
//    Pet pet1("Harrison", "Ford", "333444555567", "Spike", "Lizard");
//
//
//    std::cout << pet1 << std::endl;
//
//    std::cout << pet1.GetType()  << std::endl;
//
//
//    GroomingAppointment GA(p, pet1, "1-1-1998", "19:00 am", 12);
//    GA.Display(std::cout);
//    std::cout << std::endl;
//
//    HaircutAppointment HA(p, pet1, "1-10-1998", "13:00 am", 15, 25);
//    HA.Display(std::cout);
//    std::cout << std::endl;
//
//    Scheduler s("../../data/appointments.csv");
//    s.GetAppointments();
//
//    auto appointments = s.GetAppointments();
//    for (const auto& appointment : appointments) {
//        std::cout << *appointment << std::endl;
//    }
//
//    std::set<std::string> appointmentDates = s.GetAppointmentDates();
//    for (const std::string& date : appointmentDates) {
//        std::cout << date << std::endl;
//    }
//    std::cout << std::endl;
//
//    std::set<std::string> appointmentGroomers = s.GetGroomers();
//    for (const std::string& groomer : appointmentGroomers) {
//        std::cout << groomer << std::endl;
//    }
//
//    std::cout << std::endl;
//
//    auto dates = s.GetAppointmentsByDate("7-6-2023");
//    for (const auto& appointment : dates) {
//        std::cout << *appointment << std::endl;
//    }
//
//    std::cout << "FILTER" <<std::endl;
//    auto filter = s.Filter("Katy", "Perry", "7-6-2023");
//    for (const auto& appointment : filter) {
//        std::cout << *appointment << std::endl;
//    }

    return 0;
}