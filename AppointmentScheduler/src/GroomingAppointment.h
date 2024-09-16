// Created by Will on 11/22/2023

#include "Appointment.h"

#ifndef APPOINTMENTS_GROOMING_H
#define APPOINTMENTS_GROOMING_H

class GroomingAppointment : public Appointment{
protected:
    double grooming_price_;
public:
    GroomingAppointment(Person groomer, Pet client, std::string date, std::string time, double grooming_price):
    Appointment(groomer, client, date, time) {SetGroomingPrice(grooming_price);}
    double GetGroomingPrice() const {return grooming_price_;}
    void SetGroomingPrice(double grooming_price);
    Person GetGroomer() const {return groomer_;}
    double GetBill() const {return grooming_price_;};
    void Display(std::ostream& out);
};

#endif //APPOINTMENTS_GROOMING_H
