//
// Created by Nancy Hong on 4/15/18.
//

#include "ofApp.h"

ofApp::ofApp() {
    
}

void ofApp::setup() {
    ofSetWindowTitle("CS 126 Final Project");
    ofSetBackgroundColor(0, 0, 0);
    user_input_ = "";
    
    game_text_.init("m5x7.ttf", 45);
    game_text_.setColor(225, 225, 225, 225);
    game_text_.setText("");
    game_text_.wrapTextArea(ofGetWidth() * 0.95, ofGetHeight() * 0.3);

    game_font_.load("m5x7.ttf", 45);
    
    start_bg_.load("test4.png");                   // organtrail.png
    forest_bg_.load("test1.png");    // full_pixel_art_forest_bg.png
    country_bg_.load("country-platform-bg.png");        //images are too small - TODO
    city_bg_.load("test3.png");                 // skill-desc-bg.png                too small, need to fix later
}

void ofApp::runner() {
    // not an og function. added this in myself
}

void ofApp::update() {
    if (current_state_ == START) {
        
    }
}

void ofApp::reset() {
    
}

void ofApp::draw() {
    if (current_state_ == START) {
        drawStartScreen();
    } else if (current_state_ == OUTSKIRTS) {
        drawOutskirtsScreen();
    } else if (current_state_ == CITY) {
        drawCityScreen();
    } else if (current_state_ == END) {
        drawEndScreen();
    }
    //game_font_.drawString("testttt",  ofGetWidth() * .05 , ofGetHeight() * .75);
    
    //game_text_.setText("any dialgoue and story text goes here :)");
    game_text_.wrapTextArea(ofGetWidth() * 0.95, ofGetHeight() * 0.30);
    game_text_.draw(ofGetWidth() * 0.05, ofGetHeight());
    
    if (showStatus) {
        drawStatus();
    }
    
    drawUserInput();
}

void ofApp::keyPressed(int key) {
    if (key == OF_KEY_BACKSPACE && user_input_.size() > 0) {
        user_input_ = user_input_.substr(0, user_input_.size() - 1);
        return;
    } else if (key == OF_KEY_RETURN && user_input_.size() > 0) {
        input();    // need to check if you're at the beginning of the game then take the input
        user_input_ = "";
        return;
    } /*else if (key == ' ') {
        continue;   // Joan said  is not good... figure out how to rewrite this
    } */
    
    //int lower_key = tolower(key);
    
    user_input_.append (1, (char)key);
}

void ofApp::removeSpaces() {
    for (int i = 0; i < user_input_.size() - 1; i++) {
        if (user_input_.at(i) == ' ' && user_input_.at(i + 1) == ' ') {
            user_input_ = user_input_.substr(i) + user_input_.substr(i + 1);
        }
    }
    if (user_input_.at(0) == ' ') {
        user_input_ = user_input_.substr(1);
    }
    if (user_input_.at(user_input_.size() - 1) == ' ') {
        user_input_ = user_input_.substr(user_input_.size() - 1);
    }
}

void ofApp::input() {
    //removeSpaces(); // DOES NOT LIKE THIS
    
    // do the actions for the start
    if (current_state_ == START) {
        setupGroup();
    }
    
    // do the actions that you can do anywhere
    if (user_input_ == "status") {
        showStatus = TRUE;
        return;
    } else {
        showStatus = FALSE;
    }
    
    if (user_input_ == "scavenge") {
        Scavenge();
        return;
    } else if (user_input_ == "kill zombies") {
        int random_kill = rand() % 20;
        group.get_players_in_group()[0]->set_kill_count(group.get_players_in_group()[0]->get_kill_count() + random_kill);
        return;
    }
    
    if (current_state_ == OUTSKIRTS) {
        // do the actions for the outskirts
        return;
    }
    if (current_state_ == CITY) {
        // do the actions for city;
        return;
    }
    
    if (user_input_ == "city") {
        current_state_ = CITY;
    } else if (user_input_ == "outskirts") {
        current_state_ = OUTSKIRTS;
    }
    

    
    // current_state_ = START;
}

void ofApp::drawStatus() {
    std::string stats = current_time_.to_string() + group.StatInfo();
    ofSetColor(0, 0, 0);
    game_font_.drawString(stats, ofGetWidth() * 0.03, ofGetHeight() * 0.05);
}

void ofApp::drawUserInput() {
    ofSetColor(225, 225, 225);
    game_font_.drawString(user_input_,  ofGetWidth() * .05 , ofGetHeight() * .80);
}

void ofApp::drawStartScreen() {
    start_bg_.draw(0, 0);
    std::string instructions = "Type in your name: ";
    game_text_.setText(instructions);
}

void ofApp::drawOutskirtsScreen() {
    country_bg_.draw(0,0);
    game_font_.drawString(":(", ofGetWidth() * .05 , ofGetHeight() * .80);
}

void ofApp::drawCityScreen() {
    city_bg_.draw(0, 0);

}

void ofApp::drawEndScreen() {
    forest_bg_.draw(0, 0);  // change this later to the end screen

}

void ofApp::setupGroup() {
    vector<std::string> names_list;
    names_list.push_back("Nancy");
    names_list.push_back("Joan");
    names_list.push_back("Vivek");
    names_list.push_back("Jesse");
    names_list.push_back("Eric");
    
    for (int i = 0; i < Group::kMaxNumPlayers; i++) {
        setupPlayer(names_list[i]);
    }
}

void ofApp::setupPlayer(std::string name) {
    Playable* player = new Playable(user_input_, Playable::CharacterType::REGULAR_JOE); /** TEST IF THIS WORKS */
    group.AddPlayer(player);
    delete(player);
}

void ofApp::TimePass() {
    int hours = rand() % 12 + 3;
    current_time_.AdvanceTime(0, hours);
    current_time_.ConvertTime();
}

void ofApp::Scavenge() {
    int water_amount = rand() % 10;
    int food_amount = rand() % 20;
    int money_amount = rand() % 30;
    int medicine_amount = rand() % 5;
    group.AddWater(water_amount);
    group.AddFood(food_amount);
    group.AddMoney(money_amount);
    group.AddMedicine(medicine_amount);
    TimePass();
}






//---------------------------------------------------

void ofApp::keyReleased(int key) {
    
}

void ofApp::mouseMoved(int x, int y ) {
    
}

void ofApp::mouseDragged(int x, int y, int button) {
    
}

void ofApp::mousePressed(int x, int y, int button) {
    
}

void ofApp::mouseReleased(int x, int y, int button) {
    
}

void ofApp::mouseEntered(int x, int y) {
    
}

void ofApp::mouseExited(int x, int y) {
    
}

void ofApp::windowResized(int w, int h) {
    
}


