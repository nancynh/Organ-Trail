//
//  Character.cpp
//  final-project-nancynh
//
//  Created by Nancy Hong on 4/16/18.
//

#include "Character.hpp"

Character::Character() {

}

bool Character::IsDead() const {
    return health_ <= 0;
}

int Character::get_health() const {
    return health_;
}

std::string Character::get_name() const {
    return name_;
}

std::string Character::get_race() const {
    return race_;
}

std::string Character::get_age() const {
    return age_;
}

std::string Character::get_gender() const {
    return gender_;
}

void Character::set_health(int health) {
    health_ = health;
}
