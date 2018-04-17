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
#include "Playable.hpp"

class Location {
    
private:
    std::string name;
    
    // How far the place stretches for
    int distance_;
    
    // The items players can find in the area
    std::vector<Equipment> scavenge_items_;
    
public:
    Location(int distance);
    
    /* Players can scavange the area for equipment, food, water, and medicine.
     * @param character - the player to scavange the area
     */
    void Scavenge(Playable character);
    
    /* Players can kill zombies in the area. This will also add to the player's kill count.
     * @param player - the player who is killing the zombies
     */
    void KillZombies(Playable player);

    std::string get_name();
    int get_distance();
    std::vector<Equipment> get_scavenge_items();
};

#endif /* Location_hpp */
