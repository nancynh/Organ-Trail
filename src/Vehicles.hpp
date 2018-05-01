//
//  Vehicles.hpp
//  final-project-nancynh
//
//  Created by Nancy Hong on 4/17/18.
//

#ifndef Vehicles_hpp
#define Vehicles_hpp

#include <stdio.h>
#include "Equipment.hpp"

class Vehicle : public Equipment {
private:
    double speed_;
    int cargo_;
    
public:
    Vehicle(std::string name, double condition, int price, double speed, int cargo);
    double get_speed();
    int get_cargo();
};
#endif /* Vehicles_hpp */





