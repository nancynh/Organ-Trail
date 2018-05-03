//
//  Location.hpp
//  final-project-nancynh
//
//  Created by Nancy Hong on 4/16/18.
//

#ifndef Location_hpp
#define Location_hpp

#include <stdio.h>
#include <vector>
#include "Equipment.hpp"
#include "Player.hpp"
#include "Group.hpp"

class Location {
    
protected:
    std::string name_;
    
    // How far the place stretches for
    int distance_;
    
    // The items players can find in the area
    std::vector<Equipment> scavenge_items_;
    
public:
    Location(std::string name, int distance);

    std::string get_name();
    int get_distance();
    std::vector<Equipment> get_scavenge_items();
};

#endif /* Location_hpp */
