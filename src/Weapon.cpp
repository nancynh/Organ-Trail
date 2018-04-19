//
//  Weapon.cpp
//  final-project-nancynh
//
//  Created by Nancy Hong on 4/17/18.
//

#include "Weapon.hpp"

Weapon::Weapon(std::string name, double condition, int price, int attack, int defense, int accuracy) {
    this->name_ = name;
    this->condition_ = condition;
    this->price_ = price;
    this->attack_ = attack;
    this->defense_ = defense;
    this->accuracy_ = accuracy;
}

int Weapon::get_attack() {
    return attack_;
}

int Weapon::get_defense() {
    return defense_;
}

double Weapon::get_accuracy() {
    return accuracy_;
};
