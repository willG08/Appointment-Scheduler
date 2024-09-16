// Created by Will on 11/22/2023

#include "HaircutAppointment.h"
#include "GroomingAppointment.h"
#include <iomanip>

void HaircutAppointment::SetHaircutPrice(double haircut_price){
    if(haircut_price < 0){
        haircut_price_ = 0;
    }
    else{
        haircut_price_ = haircut_price;
    }
}

double HaircutAppointment::GetBill() const{
    double price = haircut_price_ + GetGroomingPrice();
    return price;
}

void HaircutAppointment::Display(std::ostream& out){
    out << "Time: " << date_time_ << "\nClient: " << client_.GetName() << "\nGroomer: " << groomer_
        << std::fixed << std::setprecision(2) << "Price: " << "$" << GetBill() << std::endl;
}