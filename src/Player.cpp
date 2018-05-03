//
//  Playable.cpp
//  final-project-nancynh
//
//  Created by Nancy Hong on 4/16/18.
//

#include "Player.hpp"

Player::Player() {
    this->name_ = "Chicken Joe";
    this->type_ = REGULAR_JOE;
    this->health_ = kMaxHealth;
    this->kill_count_ = 0;
    this->hunger_level_ = 0;
    this->thirst_level_ = 0;
}

Player::Player(std::string name, CharacterType type) {
    this->name_ = name;
    this->type_ = type;
    this->health_ = kMaxHealth;
    this->kill_count_ = 0;
    this->hunger_level_ = 0;
    this->thirst_level_ = 0;
}

void Player::Fix(Equipment equipment) {
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

void Player::Heal(Player* character, int medicine) {
    double const kBonus = 0.2;
    int new_health = character->get_health() + 5 * medicine;
    
    if (this->type_ == DOCTOR) {
        new_health += kMaxHealth * kBonus;
    }
    if (new_health > kMaxHealth) {
        new_health = kMaxHealth;
    }
    character->set_health(new_health);
}

void Player::Kill(Character character) {  // TODO - implement this in later
    
}

void Player::Eat(int amount) {
    hunger_level_ -= amount;
    if (hunger_level_ < 0) {
        hunger_level_ = 0;
    }
}

void Player::Drink(int amount) {
    thirst_level_ -= amount;
    if (thirst_level_ < 0) {
        thirst_level_ = 0;
    }
}

bool Player::IsDead() {
    return health_ <= 0;
}

bool Player::IsStarving() {
    return hunger_level_ >= kMaxHunger;
}

bool Player::IsDehydrated() {
    return thirst_level_ >= kMaxThirst;
}

std::string Player::Stats() {
    std::string info = "Name: " + name_ + " Type: ";
    if (type_ == BANKER) {
        info += "Banker";
    } else if (type_ == HUNTER) {
        info += "Hunter";
    } else if (type_ == DOCTOR) {
        info += "Doctor";
    } else {
        info += "Regular Joe";
    }
    
    info += " Health: " + std::to_string(health_) + " / " + std::to_string(kMaxHealth);
    return info;
}

int Player::get_health() const {
    return health_;
}

std::string Player::get_name() const {
    return name_;
}


int Player::get_hunger_level() const {
    return hunger_level_;
}

int Player::get_thrist_level() const {
    return thirst_level_;
}

int Player::get_kill_count() const {
    return kill_count_;
}

Player::CharacterType Player::get_character_type() const {
    return type_;
}

void Player::set_health(int health) {
    health_ = health;
}

void Player::set_kill_count(int amount) {
    kill_count_ = amount;
}

void Player::set_character_type(Player::CharacterType type) {
    type_ = type;
}

bool operator==(const Player& lhs, const Player& rhs) {
    return lhs.get_name() == rhs.get_name()
    && lhs.get_character_type() == rhs.get_character_type()
    && lhs.get_health() == rhs.get_health()
    && lhs.get_kill_count() == rhs.get_kill_count()
    && lhs.get_thrist_level() == rhs.get_thrist_level()
    && lhs.get_hunger_level() == rhs.get_hunger_level();
}

//take out
void Player::set_hunger_level(int level) {
    hunger_level_ = level;
}

void Player::set_thrist_level(int level) {
    thirst_level_ = level;
}

