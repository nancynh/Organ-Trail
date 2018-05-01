//
//  Vehicles.cpp
//  final-project-nancynh
//
//  Created by Nancy Hong on 4/17/18.
//

#include "Vehicles.hpp"

Vehicle::Vehicle(std::string name, double condition, int price, double speed, int cargo) {
    this->name_ = name;
    this->condition_ = condition;
    this->price_ = price;
    this->speed_ = speed;
    this->cargo_ = cargo;
}

double Vehicle::get_speed() {
    return speed_;
}

int Vehicle::get_cargo() {
    return cargo_;
}
