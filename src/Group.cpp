//
//  Group.cpp
//  final-project-nancynh
//
//  Created by Nancy Hong on 4/17/18.
//

#include "Group.hpp"

void Group::RemoveEquipment(Equipment item) {
    for (int i = 0; i < inventory_.size(); i++) {
        if (item == inventory_[i]) {
            inventory_.erase(inventory_.begin() + i);
            break;
        }
    }
}

void Group::AddEquipment(Equipment item) {
    inventory_.push_back(item);
}

bool Group::InInventory(Equipment item) {
    for (int i = 0; i < inventory_.size(); i++) {
        if (item == inventory_[i]) {
            return true;
        }
    }
    return false;
}

Vehicle Group::get_current_vehicle() {
    return current_vehicle_;
}

std::vector<Character> Group::get_players_in_group() {
    return players_in_group_;
}

std::vector<Equipment> Group::get_inventory() {
    return inventory_;
}

int Group::get_food_amount() {
    return food_amount_;
}

int Group::get_water_amount() {
    return water_amount_;
}

int Group::get_medicine_amount() {
    return medicine_amount_;
}

int Group::get_money() {
    return money_;
}

void Group::set_current_vehicle(Vehicle vehicle) {
    current_vehicle_ = vehicle;
}


void Group::set_food_amount(int amount) {
    food_amount_ = amount;
}

void Group::set_water_amount(int amount) {
    water_amount_ = amount;
}

void Group::set_meicine_amount(int amount) {
    medicine_amount_ = amount;
}

void Group::set_money(int amount) {
    money_ = amount;
}

