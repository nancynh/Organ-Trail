//
//  Character.cpp
//  final-project-nancynh
//
//  Created by Nancy Hong on 4/16/18.
//

#include "Character.hpp"

bool Character::Is_Dead() {
    return health_ <= 0;
}

int Character::get_health() {
    return health_;
}

std::string Character::get_name() {
    return name_;
}

std::string Character::get_race() {
    return race_;
}

std::string Character::get_age() {
    return age_;
}

std::string Character::get_gender() {
    return gender_;
}

void Character::set_health(int health) {
    health_ = health;
}
