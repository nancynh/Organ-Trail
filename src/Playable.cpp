//
//  Playable.cpp
//  final-project-nancynh
//
//  Created by Nancy Hong on 4/16/18.
//

#include "Playable.hpp"

Playable::Playable() {
    this->health_ = 10;
    this->name_ = "Chicken Joe";
    this->age_ = "Adult";
    this->kill_count_ = 0;
}

Playable::Playable(int health, std::string name, std::string age) {
    this->health_ = health;
    this->name_ = name;
    this->age_ = age;
}

Playable::Playable(int health, std::string name, std::string age, int kill_count) {
    this->health_ = health;
    this->name_ = name;
    this->age_ = age;
    this->kill_count_ = kill_count;
}

Playable::Playable(int health, std::string name, std::string race, std::string age, std::string gender, int kill_count) {
    this->health_ = health;
    this->name_ = name;
    this->age_ = age;
    this->race_ = race;
    this->gender_ = gender;
    this->kill_count_ = kill_count;
}

void Playable::KeepWatch() {
    
}

void Playable::Fix(Equipment equipment) {
    
}
void Playable::Heal(Character character, int medicine) {
    
}
void Playable::Kill(Character character) {
    
}
void Playable::Eat(int amount) {
    
}

void Playable::Drink(int amount) {
    
}

int Playable::get_hunger_level() {
    
}

int Playable::get_thrist_level() {
    
}
