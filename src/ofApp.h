//
// Created by Nancy Hong on 4/15/18.
//

#ifndef PROJECT_OFAPP_H
#define PROJECT_OFAPP_H

#pragma once
#include <vector>
#include <algorithm>
#include <cstdlib>
#include "ofxTextSuite.h"
#include "ofMain.h"
#include "Group.hpp"
#include "Time.hpp"
#include "Location.hpp"

class ofApp : public ofBaseApp {
    
    // This represents the current state of the game
    enum GameState {
        START,
        SETUP_TYPE,
        OUTSKIRTS,
        CITY,
        RATION,
        END
    };
    
private:
    ofxTextBlock game_text_;
    std::string user_input_;
    ofTrueTypeFont game_font_;
    ofImage start_bg_;
    ofImage setup_type_bg_;
    ofImage forest_bg_;
    ofImage country_bg_;
    ofImage city_bg_;
    ofImage end_bg_;
    ofImage ration_bg_;
    ofImage message_bg_;
    
    double const kTextWidth = 0.03;
    double const kTextHeight = 0.75;
    
    bool showStatus = false;
    bool displayMessage = false;
    bool setup_done = false;
    std::string message;
    
    GameState current_state_;
    GameState previous_state_;
    int const kMaxDistance = 2098;  // (miles)
    int const kCityLocation = 200;
    int const kCitySize = 20;
    int const kStartFood = 30;
    int const kStartWater = 30;
    double const equipment_decay_ = 0.1;
    int distance_left_;
    Time current_time_;
    Group group;
    int food_ration_amount = 3;
    int water_ration_amount = 5;
    
    void removeSpaces();
    void toLowercase();
    void input();
    
    void drawStatus();
    void drawMessage();
    void drawUserInput();
    void drawStartScreen();
    void drawSetupTypeScreen();
    void drawOutskirtsScreen();
    void drawCityScreen();
    void drawEndScreen();
    void drawRation();
    
    void setupGroup();
    void setupPlayer(std::string name);
    void setupType();
    void rationInput();
    
    // Every action takes a random amount of hours to do
    void TimePass();
    void Scavenge();
    void Rest();
    void Eat();
    void Drink();
    void GatherFood();
    void GatherWater();
    void Travel();
    void Ration();
    
public:
    ofApp();
    void setup();
    void update();
    void runner();
    void reset();
    void draw();
    void keyPressed(int key);
    void keyReleased(int key);
    void mouseMoved(int x, int y );
    void mouseDragged(int x, int y, int button);
    void mousePressed(int x, int y, int button);
    void mouseReleased(int x, int y, int button);
    void mouseEntered(int x, int y);
    void mouseExited(int x, int y);
    void windowResized(int w, int h);
};


#endif //PROJECT_OFAPP_H
