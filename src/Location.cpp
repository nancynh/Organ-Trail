//
//  Location.cpp
//  final-project-nancynh
//
//  Created by Nancy Hong on 4/16/18.
//

#include "Location.hpp"

Location::Location(std::string name, int distance) {
    this->name_ = name;
    this->distance_ = distance;
}

void Location::Scavenge(Playable player) {     // TODO - not sure if I want to based it off the player or the group

}

void Location::KillZombies(Playable player) {  // TODO - not sure if I want to based it off the player or the group
    
}

std::string Location::get_name() {
    return name_;
}

int Location::get_distance() {
    return distance_;
}

std::vector<Equipment> Location::get_scavenge_items() {
    
}
