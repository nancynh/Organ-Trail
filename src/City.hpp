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
    std::vector<Player> character_list;
    std::vector<Equipment> items_for_sale_;
    
public:
    
    /* The user buys an item at the city they're at.
     * @param item - which equipment they want to buy
     * @param group - the group who is buying the goods
     */
    void BuyItem(Equipment item, Group& group);
    
    /* The user buys multiple items at the city they're at.
     * @param item - which equipment they want to buy
     * @param amount - how much the user wants to buy
     * @param group - the group who is buying the goods
     */
    void BuyMultipleItems(Equipment item, int amount, Group& group);
    
    /* The user sells an item at the city they're at.
     * @param item - which equipment they want to sell
     * @param group - the player who is selling the goods
     */
    void SellItem(Equipment item, Group& group);
    
    /* The user sells multiple items at the city they're at.
     * @param item - which equipment they want to sell
     * @param amount - how much the user wants to sell
     * @param group - the player who is selling the goods
     */
    void SellMultipleItems(Equipment item, int amount, Group& group);
    
    std::vector<Equipment> get_items_for_sale();
};

#endif /* City_hpp */
