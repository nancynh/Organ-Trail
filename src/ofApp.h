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
    
    /* Passes time in the game by a random amount */
    void TimePass();
    
    /* The player collects a random amount of food, water, and medicine */
    void Scavenge();
    
    /* The player rests, this passes 8 hours */
    void Rest();
    
    /* The player eats some food */
    void Eat();
    
    /* The player drinks some water*/
    void Drink();
    
    /* The player kills a random amount of zombies and it deals
     * a random amount of damage to a random player */
    void KillZombies();
    
    /* The player gets a random amount of food */
    void GatherFood();
    
    /* The player gets a random amount of water */
    void GatherWater();
    
    /* The player travels a random distance */
    void Travel();
    
    /* Starts the rationing procress */
    void Ration();
    
    /* Puts in how much food the game should ration out to the group */
    void RationFood();
    
    /* Puts in how much water the game should ration out to the group */
    void RationWater();
    
    /* Allows the user to start the buying procress */
    void Buy();
    
    /* Allows the user to start the selling procress */
    void Sell();
    
    /* The user specifies what they want to buy */
    void BuyItem();
    
    /* The user specifies what they want to sell */
    void SellItem();
    
    /* The user specifies how much they want to buy */
    void BuyAmount();
    
    /* The user specifies how much they want to sell */
    void SellAmount();
    
    /* The user starts the process to heal a player */
    void Heal();
    
    /* The user specifies who they want to heal */
    void HealPerson();
    
    /* The user specifies how much medicine they want to use */
    void HealAmount();
    
    /* The user starts the process to kill a player */
    void Kill();
    
    /* The user specifies who they want to kill */
    void KillPlayer();
    
    /* Finds the person in the group
     * @param name - the name of the person to be found
     * @return true if found, false otherwise
     */
    bool findInGroup(std::string name);
    
    /* Starts the process if someone's dead */
    void Dead();
    
    /* Gives the user commands that they can do */
    void Help();
    
    /* Starts the process to show they player's stats */
    void PlayerStats();
    
    /* Shows the specified player's stats */
    void ShowPlayerStats();
    
    /* Increases the gorup's hunger and thirst level */
    void IncreaseHungerThirstLevel();
    
    /* The group eats their rations for the day */
    void GroupRation();
    
    /* The prices in the market randomly changes */
    void ChangePrice();
    
    /* Checks if any of the players are dead yet */
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
