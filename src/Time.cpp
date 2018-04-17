//
//  Time.cpp
//  final-project-nancynh
//
//  Created by Nancy Hong on 4/16/18.
//

#include "Time.hpp"

Time::Time() {
    this->current_season_ = SPRING;
    this->day_ = 1;
    this->hour_ = 0;
}

Time::Time(int day, int hour) {
    this->day_ = day;
    this->hour_ = hour;
}

Time::Time(Seasons season, int day, int hour) {
    this->current_season_ = season;
    this->day_ = day;
    this->hour_ = hour;
}

void Time::AdvanceTime(int hours) {
    
}

void Time::AdvanceTime(int hours, int days) {
    
}

void Time::ConvertTime() {
    
}
Time Time::ConvertTimeToHours() {
    return;
}

Seasons Time::get_current_season() {
    
}

int Time::get_day() {
    
}

int Time::get_hour() {
    
}
