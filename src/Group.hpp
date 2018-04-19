//
//  Group.hpp
//  final-project-nancynh
//
//  Created by Nancy Hong on 4/17/18.
//

#ifndef Group_hpp
#define Group_hpp

#include <stdio.h>
#include <vector>
#include "Character.hpp"
#include "Equipment.hpp"
#include "Vehicles.hpp"

class Group {
private:
    std::vector<Character> players_in_group_;
    std::vector<Equipment> inventory_; // Maybe change this to a map?
    Vehicle current_vehicle_;
    int food_amount_;
    int water_amount_;
    int medicine_amount_;
    int money_;
public:
    static int const kMaxNumPlayers = 5;

    /* Removes the equipment from the list of items the group has
     * @param item - the thing to be removed
     */
    void RemoveEquipment(Equipment item);  // TODO - Maybe change this to a string later?
    
    /* Adds a piece of equipment to the group's inventory
     * @param item - the thing to be added
     */
    void AddEquipment(Equipment item);
    
    /* Checks if the item exists in the group's inventory or not.
     * @param item - the item to look for
     * @return true if found, false otherwise
     */
    bool InInventory(Equipment item);
    
    std::vector<Character> get_players_in_group();
    std::vector<Equipment> get_inventory();
    Vehicle get_current_vehicle();
    int get_food_amount();
    int get_water_amount();
    int get_medicine_amount();
    int get_money();
    void set_current_vehicle(Vehicle vehicle);
    void set_food_amount(int amount);
    void set_water_amount(int amount);
    void set_meicine_amount(int amount);
    void set_money(int amount);
};

#endif /* Group_hpp */
