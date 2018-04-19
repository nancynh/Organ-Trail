//
//  Outskirts.cpp
//  final-project-nancynh
//
//  Created by Nancy Hong on 4/16/18.
//

#include "Outskirts.hpp"


void Outskirts::Gather_Food(Group& group) {
    int const kMaxRange = 20;
    int amount_found = rand() * kMaxRange;
    group.set_food_amount(group.get_food_amount() + amount_found);
}

void Outskirts::Get_Water(Group& group) {
    int const kMaxRange = 20;
    int amount_found = rand() * kMaxRange;
    group.set_water_amount(group.get_water_amount() + amount_found);
}
