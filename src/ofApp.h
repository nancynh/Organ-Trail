//
// Created by Nancy Hong on 4/15/18.
//

#ifndef PROJECT_OFAPP_H
#define PROJECT_OFAPP_H

#include <vector>
#include "Character.hpp"
#include "Time.hpp"
#include "Location.hpp"

class ofApp {
    
private:
    int const kMaxNumPlayers = 5;
    int const kMaxDistance = 2098;  // (miles)
    std::vector<Character> players_in_group_;
    std::vector<Equipment> equipment_list_;
    Time current_time_;
    int distance_left_;
    int food_amount_;
    int water_amount_;
    int medicine_amount_;
    int money_;
    
public:
    void Update();
    void Runner();
};


#endif //PROJECT_OFAPP_H
