//
//  Outskirts.hpp
//  final-project-nancynh
//
//  Created by Nancy Hong on 4/16/18.
//

#ifndef Outskirts_hpp
#define Outskirts_hpp

#include <stdio.h>
#include "Location.hpp"

class Outskirts : public Location {
private:
    
public:
    /* The player can obtain food. */
    void Gather_Food(Group& group);  // maybe add hunting, gathering herbs/berries, or fishing method too. if time, implement in a mini-game for each
    
    /* The player can get some water. */
    void Get_Water(Group& group);
    
};

#endif /* Outskirts_hpp */
