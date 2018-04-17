//
//  City.hpp
//  final-project-nancynh
//
//  Created by Nancy Hong on 4/16/18.
//

#ifndef City_hpp
#define City_hpp

#include <stdio.h>
#include "Location.hpp"

class City : public Location {
    
private:
    std::vector<Character> character_list;
    std::vector<Equipment> items_for_sale_;
    
public:
    
    /* The user buys an item at the city they're at.
     * @param item - which equipment they want to buy
     */
    void BuyItem(Equipment item);
    
    /* The user buys multiple items at the city they're at.
     * @param item - which equipment they want to buy
     * @param amount - how much the user wants to buy
     */
    void BuyMultipleItems(Equipment item, int amount);
    
    /* The user sells an item at the city they're at.
     * @param item - which equipment they want to sell
     */
    void SellItem(Equipment item);
    
    /* The user sells multiple items at the city they're at.
     * @param item - which equipment they want to sell
     * @param amount - how much the user wants to sell
     */
    void SellMultipleItems(Equipment item, int amount);
    
    /* The user can look for surviviors that can join their group.
     * If they have the maximum of 5 people in their group, the survivor
     * cannot join the group.
     * @return the surivior that the user found
     */
    Character LookForSurvivors();
    
    std::vector<Character> get_character_list();
    std::vector<Equipment> get_items_for_sale();
};

#endif /* City_hpp */
