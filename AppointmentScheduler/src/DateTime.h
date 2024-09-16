// Created by Will on 11/22/2023

#ifndef DATE_TIME_H
#define DATE_TIME_H

#include <string>
#include <iostream>

class DateTime {
private:
    int year_;
    int month_;
    int day_;
    int hours_;
    int mins_;
    std::string meridiem_;
    std::string date_;
    std::string time_;

public:
    DateTime(std::string date, std::string time = "12:00 am");

    //Getters
    std::string GetDate() const {return date_;};
    std::string GetTime() const {return time_;};

    //Setters
    void SetDate(std::string date);
    void SetTime(std::string time);

    friend std::ostream& operator<<(std::ostream& out, DateTime& dateTime);
};


#endif //DATE_TIME_H
