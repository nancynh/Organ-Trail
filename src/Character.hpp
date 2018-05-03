//
//  Character.hpp
//  final-project-nancynh
//
//  Created by Nancy Hong on 4/16/18.
//
#include <string>
#include "Equipment.hpp"

#ifndef Character_hpp
#define Character_hpp
class Character {   // maybe make this abstract??
protected:
    int const kMaxHealth = 100;
    int health_;
    std::string name_;
    std::string race_;  // Customization purposes only
    std::string age_;           // Customization purposes only
    std::string gender_;    // Customization purposes only
    
public:
    Character();
    
    /* Checks if the character is dead or not.
     * @return true is player's health > 0, false otherwise
     */
    bool IsDead() const;
    int get_health() const;
    std::string get_name() const;
    std::string get_race() const;
    std::string get_age() const;
    std::string get_gender() const;
    void set_health(int health);
    
};
#include <stdio.h>

#endif /* Character_hpp */
