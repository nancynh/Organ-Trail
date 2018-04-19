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
    this->type_ = REGULAR;
}

Playable::Playable(int health, std::string name, std::string age) {
    this->health_ = health;
    this->name_ = name;
    this->age_ = age;
}

Playable::Playable(int health, std::string name, std::string age, int kill_count, CharacterType type) {
    this->health_ = health;
    this->name_ = name;
    this->age_ = age;
    this->kill_count_ = kill_count;
    this->type_ = type;
}

Playable::Playable(int health, std::string name, std::string race, std::string age, std::string gender, int kill_count, CharacterType type) {
    this->health_ = health;
    this->name_ = name;
    this->age_ = age;
    this->race_ = race;
    this->gender_ = gender;
    this->kill_count_ = kill_count;
    this->type_ = type;
}

void Playable::KeepWatch() {    // TODO - implement this in later
    
}

void Playable::Fix(Equipment equipment) {
    double const kBonus = 0.2;
    double new_condition = equipment.get_condition() + 0.1;
    
    if (this->type_ == CARPENTER) {
        new_condition += kBonus;
    }
    if (new_condition > 1) {
        new_condition = 1;
    }
    equipment.set_condition(new_condition);
}

void Playable::Heal(Character character, int medicine) {
    double const kBonus = 0.2;
    int new_health = character.get_health() + 10;
    
    if (this->type_ == DOCTOR) {
        new_health += kMaxHealth * kBonus;
    }
    if (new_health > kMaxHealth) {
        new_health = kMaxHealth;
    }
    character.set_health(new_health);
}

void Playable::Kill(Character character) {  // TODO - implement this in later
    
}

void Playable::Eat(int amount) {
    hunger_level_ -= amount;
    if (hunger_level_ < 0) {
        hunger_level_ = 0;
    }
    // decreases the total amount of food in teh group as well
}

void Playable::Drink(int amount) {
    thirst_level_ -= amount;
    if (thirst_level_ < 0) {
        thirst_level_ = 0;
    }
    // decreases the total amount of water in the group as well
}

int Playable::get_hunger_level() {
    return hunger_level_;
}

int Playable::get_thrist_level() {
    return thirst_level_;
}

int Playable::get_kill_count() {
    return kill_count_;
}

Playable::CharacterType Playable::get_character_type() {
    return type_;
}


void Playable::set_kill_count(int amount) {
    kill_count_ = amount;
}

