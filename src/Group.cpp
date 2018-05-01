//
//  Group.cpp
//  final-project-nancynh
//
//  Created by Nancy Hong on 4/17/18.
//

#include "Group.hpp"

Group::Group() {
    this->current_vehicle_ = nullptr;
    this->food_amount_ = 0;
    this->water_amount_ = 0;
    this->medicine_amount_ = 0;
    this->money_ = 0;
}

Group::Group(Vehicle* current_vehicle, int food_amount, int water_amount, int medicine_amount, int money) {
    this->current_vehicle_ = current_vehicle;
    this->food_amount_ = food_amount;
    this->water_amount_ = water_amount;
    this->medicine_amount_ = medicine_amount;
    this->money_ = money;
}

std::string Group::StatInfo() {
    return "Food: " + std::to_string(food_amount_)
            + "           Water: " + std::to_string(water_amount_)
            + "\nMedicine: " + std::to_string(medicine_amount_)
            + "         Money: " + std::to_string(money_);
}

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

void Group::AddPlayer(Playable *player) {
    players_in_group_.push_back(player);
}


void Group::RemovePlayer(Playable *player) {
    for (int i = 0; i < players_in_group_.size(); i++) {
        if (*player == *players_in_group_[i]) {
            players_in_group_.erase(players_in_group_.begin() + i);
            delete(player);
            break;
        }
    }
}

void Group::Eat(int amount) {
    for (int i = 0; i < players_in_group_.size(); i++) {
        if (food_amount_ <= 0) {
            food_amount_ = 0;
            break;
        }
        
        players_in_group_[i]->Eat(amount);
        food_amount_ -= amount;
    }
}

void Group::Drink(int amount) {
    for (int i = 0; i < players_in_group_.size(); i++) {
        if (water_amount_ <= 0) {
            water_amount_ = 0;
            break;
        }
        
        players_in_group_[i]->Drink(amount);
        water_amount_ -= amount;
    }
}

void Group::AddFood(int amount) {
    food_amount_ += amount;
}

void Group::AddWater(int amount) {
    water_amount_ += amount;
}

void Group::AddMedicine(int amount) {
    medicine_amount_ += amount;
}

void Group::AddMoney(int amount) {
    money_ += amount;
}

void Group::RemoveFood(int amount) {
    food_amount_ -= amount;
}

void Group::RemoveWater(int amount) {
    water_amount_ -= amount;
}

void Group::RemoveMedicine(int amount) {
    medicine_amount_ -= amount;
}

void Group::RemoveMoney(int amount) {
    money_ -= amount;
}

Vehicle* Group::get_current_vehicle() {
    return current_vehicle_;
}

Playable* Group::get_main_player() {
    return players_in_group_[0];
}

std::vector<Playable*> Group::get_players_in_group() {
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

void Group::set_current_vehicle(Vehicle* vehicle) {
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

