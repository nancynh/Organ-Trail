//
//  Weapon.hpp
//  final-project-nancynh
//
//  Created by Nancy Hong on 4/17/18.
//

#ifndef Weapon_hpp
#define Weapon_hpp

#include <stdio.h>
#include "Equipment.hpp"

class Weapon : public Equipment {
private:
    int attack_;
    int defense_;   // If create an armour class as well then get rid of this
    double accuracy_;
    
public:
    Weapon(std::string name_, int durability_, int damage_taken_, int price_, int attack_, int defense_, int accuracy_);
    int get_attack();
    int get_defense();
    double get_accuracy();
};

#endif /* Weapon_hpp */
