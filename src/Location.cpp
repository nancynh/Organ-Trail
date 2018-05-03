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

std::string Location::get_name() {
    return name_;
}

int Location::get_distance() {
    return distance_;
}

std::vector<Equipment> Location::get_scavenge_items() {
    
}
