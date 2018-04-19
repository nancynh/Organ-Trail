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
class Character {
protected:
    int const kMaxHealth = 100;
    int health_;
    std::string name_;
    std::string race_;  // Customization purposes only
    std::string age_;           // Customization purposes only
    std::string gender_;    // Customization purposes only
    
public:
    /* Checks if the character is dead or not.
     * @return true is player's health > 0, false otherwise
     */
    bool Is_Dead();         // maybe use an enum status, like: alive, dead, zombie, (and maybe busy working?)
    int get_health();
    std::string get_name();
    std::string get_race();
    std::string get_age();
    std::string get_gender();
    void set_health(int health);
    
};
#include <stdio.h>

#endif /* Character_hpp */
