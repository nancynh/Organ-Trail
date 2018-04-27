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
#include "Playable.hpp"
#include "Equipment.hpp"
#include "Vehicles.hpp"

class Group {
private:
    std::vector<Playable*> players_in_group_;
    std::vector<Equipment> inventory_; // Maybe change this to a map?
    Vehicle* current_vehicle_;
    int food_amount_;
    int water_amount_;
    int medicine_amount_;
    int money_;
public:
    Group();
    Group(Vehicle* current_vehicle, int food_amount, int water_amount, int medicine_amount, int money);
    
    static int const kMaxNumPlayers = 5;
    
    /* Gives the information of the group.
     * @return a string of information on the group.
     */
    std::string StatInfo();

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
    
    /* Adds a player to the group.
     * @param player - the player to be added into the group
     */
    void AddPlayer(Playable *player);
    
    /* Removes a player from the group.
     * @param player - the player to be removed from the group
     */
    void RemovePlayer(Playable *player);
    
    void AddFood(int amount);
    void AddWater(int amount);
    void AddMedicine(int amount);
    void AddMoney(int amount);
    void RemoveFood(int amount);
    void RemoveWater(int amount);
    void RemoveMedicine(int amount);
    void RemoveMoney(int amount);
    
    std::vector<Playable*> get_players_in_group();
    std::vector<Equipment> get_inventory();
    Vehicle* get_current_vehicle();
    int get_food_amount();
    int get_water_amount();
    int get_medicine_amount();
    int get_money();
    void set_current_vehicle(Vehicle* vehicle);
    void set_food_amount(int amount);
    void set_water_amount(int amount);
    void set_meicine_amount(int amount);
    void set_money(int amount);
};

#endif /* Group_hpp */
