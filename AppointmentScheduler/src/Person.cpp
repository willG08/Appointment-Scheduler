// Created by Will on 11/22/2023

#include "Person.h"
#include <iostream>
#include <string>
#include <algorithm>

void Person::SetFirstName(std::string firstname){
    std::transform(firstname.begin(), firstname.end(), firstname.begin(), ::tolower);
    firstname[0] = std::toupper(firstname[0]);
    first_name_ = firstname;
}

void Person::SetLastName(std::string lastname){
    std::transform(lastname.begin(), lastname.end(), lastname.begin(), ::tolower);
    lastname[0] = std::toupper(lastname[0]);
    last_name_ = lastname;
}

void Person::SetPhone(std::string phone){
    if(phone.find("-") != std::string::npos) {
        phone_ = phone;
    }
    else{
        phone_ = phone.substr(0, 3) + "-" + phone.substr(3, 3) + "-" + phone.substr(6, 4);
    }
}

bool Person::operator==(Person& person) const {
    if (first_name_ == person.first_name_ && last_name_ == person.last_name_ && phone_ == person.phone_) {
        std::cout << "Equal!" << std::endl;
        return true;
    } else {
        std::cout << "Not Equal!" << std::endl;
        return false;
    }
}

std::ostream& operator<<(std::ostream& out, Person& person) {
    out << person.first_name_ << " " << person.last_name_ << " " << person.phone_ << std::endl;

    return out;
}
