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
        RATION_FOOD,
        RATION_WATER,
        BUY_ITEM,
        BUY_AMOUNT,
        SELL_ITEM,
        SELL_AMOUNT,
        HEAL_PERSON,
        HEAL_AMOUNT,
        DEAD,
        PLAYER_STATS,
        KILL_PLAYER,
        END
    };
    
private:
    ofxTextBlock game_text_;
    std::string user_input_;
    std::string previous_input_;
    ofTrueTypeFont game_font_;
    ofImage screenshot_;
    ofImage start_bg_;
    ofImage setup_type_bg_;
    ofImage forest_bg_;
    ofImage country_bg_;
    ofImage city_bg_;
    ofImage end_bg_;
    ofImage ration_food_bg_;
    ofImage ration_water_bg_;
    ofImage message_bg_;
    ofImage market_bg_;
    ofImage heal_bg_;
    ofImage dead_bg_;
    
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
    int const kStartMoney = 20;
    int const kStartMedicine = 10;
    double const equipment_decay_ = 0.1;
    int distance_left_;
    Time current_time_;
    int current_hours_;
    int user_hunger_level_;
    int user_thirst_level_;
    int group_hunger_level_;
    int group_thirst_level_;
    Group group;
    
    int food_ration_amount;
    int water_ration_amount;
    int food_buy_price = 14;
    int water_buy_price = 9;
    int medicine_buy_price = 25;
    int food_sell_price = 7;
    int water_sell_price = 4;
    int medicine_sell_price = 15;
    
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
    void drawRationFood();
    void drawRationWater();
    void drawBuyItem();
    void drawBuyAmount();
    void drawSellItem();
    void drawSellAmount();
    void drawHealPerson();
    void drawHealAmount();
    void drawDead();
    void drawPlayerStats();
    void drawKillPlayer();
    
    void setupGroup();
    void setupPlayer(std::string name);
    void setupType();
    
    void TimePass();
    void Scavenge();
    void Rest();
    void Eat();
    void Drink();
    void KillZombies();
    void GatherFood();
    void GatherWater();
    void Travel();
    void Ration();
    void RationFood();
    void RationWater();
    void Buy();
    void Sell();
    void BuyItem();
    void SellItem();
    void BuyAmount();
    void SellAmount();
    void Heal();
    void HealPerson();
    void HealAmount();
    void Kill();
    void KillPlayer();
    bool findInGroup(std::string name);
    void Dead();
    void Help();
    void PlayerStats();
    void ShowPlayerStats();
    void IncreaseHungerThirstLevel();
    void GroupRation();
    void ChangePrice();
    void DeathCheck();
        
public:
    ofApp();
    void setup();
    void update();
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
