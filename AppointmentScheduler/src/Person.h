// Created by Will on 11/22/2023

#include <string>
#include <iostream>

#ifndef APPOINTMENTS_PERSON_H
#define APPOINTMENTS_PERSON_H

class Person {
private:
    std::string first_name_;
    std::string last_name_;
    std::string phone_;
public:
    Person(std::string firstname, std::string lastname, std::string phone) : first_name_(firstname), last_name_(lastname), phone_(phone) {}
    std::string GetFirstName() { this->SetFirstName(first_name_); return first_name_;}
    std::string GetLastName() { this->SetLastName(last_name_); return last_name_;}
    std::string GetPhone() { this->SetPhone(phone_); return phone_;}
    void SetFirstName(std::string firstname);
    void SetLastName(std::string lastname);
    void SetPhone(std::string phone);
    bool operator==(Person& person) const;
    friend std::ostream& operator<<(std::ostream& out, Person& person);
};

#endif //APPOINTMENTS_PERSON_H
