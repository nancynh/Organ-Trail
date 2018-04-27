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
        OUTSKIRTS,
        CITY,
        END
    };
    
private:
    ofxTextBlock game_text_;
    std::string user_input_;
    ofTrueTypeFont game_font_;
    ofImage start_bg_;
    ofImage forest_bg_;
    ofImage country_bg_;
    ofImage city_bg_;
    
    bool showStatus = FALSE;
    
    GameState current_state_ = START;
    int const kMaxDistance = 2098;  // (miles)
    int distance_left_;
    double equipment_decay_;
    Time current_time_;
    Group group;
    
    void removeSpaces();
    void toLowercase();
    void input();
    
    void drawStatus();
    void drawUserInput();
    void drawStartScreen();
    void drawOutskirtsScreen();
    void drawCityScreen();
    void drawEndScreen();
    
    void setupGroup();
    void setupPlayer(std::string name);
    
    // Every action takes a random amount of hours to do
    void TimePass();
    void Scavenge();
    
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
