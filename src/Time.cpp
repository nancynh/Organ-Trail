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
    hour_ += hours;
    ConvertTime();
}

void Time::AdvanceTime(int hours, int days) {
    hour_ += hours;
    day_ += days;
    ConvertTime();
}

void Time::ConvertTime() {
    int const kNumHours = 24;
    if (hour_ > kNumHours) {
        day_ += hour_ / kNumHours;
        hour_ = hour_ % kNumHours;
    }
    if (day_ > kNumDaysInSeason) {
        day_ = day_ % kNumDaysInSeason;
        changeSeason();
    }
}

Time Time::ConvertTimeToHours() {
    int const kNumHours = 24;
    int hours = kNumHours * day_ + hours;
    return Time(0, hours);
}

void Time::changeSeason() {
    if (current_season_ == SPRING) {
        current_season_ = SUMMER;
    } else if (current_season_ == SUMMER) {
        current_season_ = FALL;
    } else if (current_season_ == FALL) {
        current_season_ == WINTER;
    } else {
        current_season_ = SPRING;
    }
}

std::string Time::to_string() {
    std::string output = "Day " + std::to_string(day_) + " of ";
    if (current_season_ == SPRING) {
        output += "Spring";
    } else if (current_season_ == SUMMER) {
        output += "Summer";
    } else if (current_season_ == FALL) {
        output += "Fall";
    } else {
        output += "Winter";
    }
    return output + "\n";
}

Time::Seasons Time::get_current_season() {
    return current_season_;
}

int Time::get_day() {
    return day_;
}

int Time::get_hour() {
    return hour_;
}
