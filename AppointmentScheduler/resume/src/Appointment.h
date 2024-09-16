// Created by Will on 11/22/2023

#include "DateTime.h"
#include "Person.h"
#include "Pet.h"

#ifndef APPOINTMENTS_APPOINTMENT_H
#define APPOINTMENTS_APPOINTMENT_H
// : public Person, public Pet, public DateTime
class Appointment{
protected:
    Person groomer_;
    Pet client_;
    DateTime date_time_;
public:
    Appointment(Person groomer, Pet client, std::string date, std::string time): groomer_(groomer), client_(client),
    date_time_(date, time) {}
    virtual Person GetGroomer() const {return groomer_;}
    virtual Pet GetClient() const {return client_;}
    virtual DateTime GetDateTime() const {return date_time_;}
    virtual double GetBill() const = 0;
    virtual void Display(std::ostream& out);
    friend std::ostream& operator<<(std::ostream& out, Appointment& appointment);
};


#endif //APPOINTMENTS_APPOINTMENT_H
