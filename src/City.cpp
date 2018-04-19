//
//  City.cpp
//  final-project-nancynh
//
//  Created by Nancy Hong on 4/16/18.
//

#include "City.hpp"

void City::BuyItem(Equipment item, Group& group) {
    
    // the group doesn't have enough moola to even buy the product, probs should print something out to indicate this later
    if (item.get_price() > group.get_money()) {
        return;
    }
    
    group.set_money(group.get_money() - item.get_price());
    group.AddEquipment(item);
}

void City::BuyMultipleItems(Equipment item, int amount, Group& group) {
    for (int i = 0; i < amount; i++) {
        BuyItem(item, group);
    }
}

void City::SellItem(Equipment item, Group& group) {
    
    // the group doesn't have enough the item to sell, probs should print something out to indicate this later
    if (!group.InInventory(item)) {
        return;
    }
    
    group.set_money(group.get_money() + item.CalculatePrice());
    group.RemoveEquipment(item);
}

void City::SellMultipleItems(Equipment item, int amount, Group& group) {
    for (int i = 0; i < amount; i++) {
        SellItem(item, group);
    }
}

Character City::LookForSurvivors(Group& group) {    // TODO - implement in later
    
    // Can't add new members to the group b/c already at the max number
    if (group.get_players_in_group().size() == Group::kMaxNumPlayers) {
        return Character;
    }
}

std::vector<Character> City::get_character_list() {
    return character_list;
}

std::vector<Equipment> City::get_items_for_sale() {
    return items_for_sale_;
}
