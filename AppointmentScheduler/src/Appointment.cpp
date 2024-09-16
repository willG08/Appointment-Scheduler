// Created by Will on 11/22/2023

#include "Appointment.h"
#include <iomanip>

void Appointment::Display(std::ostream& out){
    out << "Time: " << date_time_ << "\nClient: " << client_.GetName() << "\nGroomer: " << groomer_;
}

std::ostream& operator<<(std::ostream& out, Appointment& appointment) {
    out << "Time:    " << appointment.GetDateTime().GetDate() << " " << appointment.GetDateTime().GetTime() << "\n"
        << "Client:  " << appointment.GetClient().GetName() << "\n"
        << "Groomer: " << appointment.GetGroomer().GetFirstName() << " " << appointment.GetGroomer().GetLastName() << " " << appointment.GetGroomer().GetPhone() << "\n"
        << "Price:   $" << std::fixed << std::setprecision(2) << appointment.GetBill() << "\n\n";
    return out;
}