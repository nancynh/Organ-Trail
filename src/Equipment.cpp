//
//  Equipment.cpp
//  final-project-nancynh
//
//  Created by Nancy Hong on 4/16/18.
//

#include "Equipment.hpp"

bool Equipment::Is_Broken() {
    return condition_ == 0.0;
}

int Equipment::CalculatePrice() {
    return price_ * condition_;
}

std::string Equipment::get_name() {
    return name_;
}

int Equipment::get_condition() {
    return condition_;
}

int Equipment::get_price() {
    return price_;
}

void Equipment::set_condition(int condition) {
    condition_ = condition;
}

bool operator==(const Equipment& lhs, const Equipment& rhs) {
    return lhs.name_ == rhs.name_
            && lhs.condition_ == rhs.condition_
            && lhs.price_ == rhs.price_;
}
