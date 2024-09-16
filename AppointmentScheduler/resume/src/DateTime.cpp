// Created by Will on 11/22/2023

#include "DateTime.h"
#include <sstream>
#include <string>
#include <iomanip>

DateTime::DateTime(std::string date, std::string time){
    SetDate(date);
    SetTime(time);
}


void DateTime::SetDate(std::string date) {
    char delimiter = '-';
    if (date.find('/') != std::string::npos) {
        delimiter = '/';
    }

    std::stringstream ss(date);
    std::string first, second, third;

    getline(ss, first, delimiter);
    getline(ss, second, delimiter);
    getline(ss, third);

    month_ = stoi(first);
    day_ = stoi(second);
    year_ = stoi(third);

    std::string zero = "0";
    if(month_ < 10) {
        first = zero + std::to_string(month_);
    }

    if(day_ < 10) {
        second = zero + std::to_string(day_);
    }

    date_ = first + "/" + second + "/" + third;
}

void DateTime::SetTime(std::string time){
    std::stringstream ss(time);
    std::string hours, minutes, meridiem;

    getline(ss, hours, ':');
    getline(ss, minutes, ' ');
    getline(ss, meridiem);

    hours_ = stoi(hours);
    mins_ = stoi(minutes);
    meridiem_ = meridiem;

    if (hours_ > 12){
        hours_ -= 12;
        meridiem_ = "pm";
    }

    hours = std::to_string(hours_);

    time_ = hours + ":" + minutes + meridiem_;

}

std::ostream& operator<<(std::ostream& out, DateTime& dateTime) {
    out << dateTime.date_ << " " << dateTime.time_;
    return out;
}