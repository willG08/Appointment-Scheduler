// Created by Will on 11/22/2023

#include "Pet.h"
#include <iostream>
#include <string>
#include <algorithm>

void Pet::SetName(std::string names) {
    std::string name = names;
    std::transform(name.begin(), name.end(), name.begin(), ::tolower);
    name[0] = std::toupper(name[0]);
    name_ = name;
}

bool Pet::operator == (Pet& pet) const {
    if (name_ == pet.name_ && type_ == pet.type_ && owner_ == pet.owner_) {
        std::cout << "Equal!" << std::endl;
        return true;
    } else {
        std::cout << "Not Equal!" << std::endl;
        return false;
    }
}

std::ostream& operator<<(std::ostream& out, Pet& pet){
    out << pet.name_ << " " << pet.type_ << " " << pet.owner_;

    return out;
}