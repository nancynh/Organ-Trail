//
//  Equipment.hpp
//  final-project-nancynh
//
//  Created by Nancy Hong on 4/16/18.
//

#ifndef Equipment_hpp
#define Equipment_hpp

#include <stdio.h>
#include <string>
#include <vector>

class Equipment {
    
private:
    std::string name_;
    double condition_;
    int price_;
    
public:
    /* Checks if the equipment is broken or not.
     * @return true if condition is at 0%, false otherwise
     */
    bool Is_Broken();
    
    /* Removes the equipment from the list of items the player has. */
    void Remove_Equipment(std::vector<Equipment> &equipment_list);  // TODO - I think you use & and not * anyway, check later
    
    /* Calculates how much the item costs based on how much it has been damaged.
     * The more damage done to the item, the less it costs from the base price.
     * @return the price of the equipment based on its condition
     */
    int CalculatePrice();
    
    std::string get_name();
    int get_durability();
    int get_damage_taken();
    int get_price();
};

#endif /* Equipment_hpp */
