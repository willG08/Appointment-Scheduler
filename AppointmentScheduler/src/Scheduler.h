// Created by Will on 11/22/2023

#include "HaircutAppointment.h"
#include "Appointment.h"
#include <vector>
#include <memory>
#include <set>

#ifndef APPOINTMENTS_SCHEDULER_H
#define APPOINTMENTS_SCHEDULER_H

class Scheduler{
private:
    std::vector<std::shared_ptr<Appointment>> appointments_;
public:
    Scheduler(std::string filename) {LoadAppointments(filename);}
    std::vector<std::shared_ptr<Appointment>> GetAppointments() {return appointments_;}
    std::set<std::string> GetAppointmentDates();
    std::set<std::string> GetGroomers();
    std::vector<std::shared_ptr<Appointment>> GetAppointmentsByDate(std::string date);
    void LoadAppointments(std::string filename);
    std::vector<std::shared_ptr<Appointment>> Filter(std::string groomer_firstname, std::string groomer_lastname, std::string date);
    friend std::ostream& operator<<(std::ostream& out, Scheduler& schedule);
};

#endif //APPOINTMENTS_SCHEDULER_H
