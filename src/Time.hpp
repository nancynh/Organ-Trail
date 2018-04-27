//
//  Time.hpp
//  final-project-nancynh
//
//  Created by Nancy Hong on 4/16/18.
//

#ifndef Time_hpp
#define Time_hpp

#include <stdio.h>
#include <string>

class Time {
    public : enum Seasons {
        SPRING,
        SUMMER,
        FALL,
        WINTER
    };
    
private:
    int const kNumDaysInSeason = 30;
    Seasons current_season_;
    int day_;
    int hour_; // Might get rid of this, maybe only allow for each person to do one action for the day so can get rid of hours
    
public:
    Time();
    Time(int day, int hour);
    Time(Seasons season, int day, int hour);
    
    /* Advances the time by a number of hours.
     * @param hours - the amount of time the user wants to advance by
     */
    void AdvanceTime(int hours);
    
    /* Advances the time by a number of days and hours.
     * @param time - the amount of time the user wants to advance by
     */
    void AdvanceTime(int days, int hours);
    
    /* Changes the time to the correct format. */
    void ConvertTime();
    
    /* Converts the number of days that have passed into the number of hours
     * @return a Time object that's just in hours
     */
    Time ConvertTimeToHours();
    
    /* Changes the season to the one that follows after it. */
    void changeSeason();
    
    std::string to_string();
    
    Seasons get_current_season();
    int get_day();
    int get_hour();
};

#endif /* Time_hpp */
