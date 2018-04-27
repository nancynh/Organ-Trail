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
    
protected:
    std::string name_;
    double condition_;
    int price_;
    
public:
    Equipment();
    
    /* Checks if the equipment is broken or not.
     * @return true if condition is at 0%, false otherwise
     */
    bool IsBroken();
    
    /* Calculates how much the item costs based on how much it has been damaged.
     * The more damage done to the item, the less it costs from the base price.
     * @return the price of the equipment based on its condition
     */
    int CalculatePrice();
    
    std::string get_name();
    int get_condition();
    int get_price();
    void set_condition(int condition);
    
    friend bool operator==(const Equipment& lhs, const Equipment& rhs);
};

#endif /* Equipment_hpp */
