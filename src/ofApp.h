//
// Created by Nancy Hong on 4/15/18.
//

#ifndef PROJECT_OFAPP_H
#define PROJECT_OFAPP_H

#include <vector>
#include "Character.hpp"
#include "Time.hpp"
#include "Location.hpp"

class ofApp {
    
private:
    int const kMaxDistance = 2098;  // (miles)
    int distance_left_;
    double equipment_decay_;
    
public:
    void Update();
    void Runner();
};


#endif //PROJECT_OFAPP_H
