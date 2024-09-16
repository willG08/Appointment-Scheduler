// Created by Will on 11/22/2023

#include "GroomingAppointment.h"

#ifndef APPOINTMENTS_HAIRCUT_H
#define APPOINTMENTS_HAIRCUT_H

class HaircutAppointment: public GroomingAppointment {
private:
    double haircut_price_;
public:
    HaircutAppointment(Person groomer, Pet client, std::string date, std::string time, double grooming_price, double haircut_price):
    GroomingAppointment(Person(groomer), Pet(client), date, time, grooming_price), haircut_price_(haircut_price){}
    double GetHaircutPrice() const {return haircut_price_;}
    void SetHaircutPrice(double haircut_price);
    double GetBill() const;
    void Display(std::ostream& out);
};

#endif //APPOINTMENTS_HAIRCUT_H
