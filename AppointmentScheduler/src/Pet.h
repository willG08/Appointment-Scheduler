// Created by Will on 11/22/2023

#include "Person.h"
#include <algorithm>

#ifndef APPOINTMENTS_PET_H
#define APPOINTMENTS_PET_H

class Pet : public Person{
private:
    Person owner_;
    std::string name_;
    std::string type_;
public:
    Pet(const std::string owner_firstname, const std::string owner_lastname, const std::string owner_phone,
        const std::string pet_name,const std::string pet_type) :
        Person(owner_firstname,owner_lastname,owner_phone), owner_(owner_firstname, owner_lastname, owner_phone), name_(pet_name), type_(pet_type){}

    Person GetOwner() const {return owner_;}
    std::string GetName() { this->SetName(name_); return name_;}
    std::string GetType() const {return type_;}

    void SetName (std::string name);
    bool operator==(Pet& pet) const;
    friend std::ostream& operator<<(std::ostream& out, Pet& pet);
};

#endif //APPOINTMENTS_PET_H
