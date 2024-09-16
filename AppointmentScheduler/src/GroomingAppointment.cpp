// Created by Will on 11/22/2023

#include "GroomingAppointment.h"
#include <iomanip>

void GroomingAppointment::SetGroomingPrice(double grooming_price){
    if(grooming_price < 0){
        grooming_price_ = 0;
    }
    else {
        grooming_price_ = grooming_price;
    }
}

void GroomingAppointment::Display(std::ostream& out){
    out << "Time: " << date_time_ << "\nClient: " << client_.GetName() << "\nGroomer: " << groomer_
    << std::fixed << std::setprecision(2) << "Price: " << "$" << grooming_price_ << std::endl;
}