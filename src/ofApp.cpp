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
    
    start_bg_.load("test4.png");
    setup_type_bg_.load("setup-type-bg.png");
    forest_bg_.load("full_pixel_art_forest_bg.png");
    country_bg_.load("country-platform-bg.png");
    city_bg_.load("skill-desc-bg.png");
    end_bg_.load("glacial-mountains-bg.png");
    ration_bg_.load("ration-bg.png");
    message_bg_.load("message-bg.png");
    
    distance_left_ = kMaxDistance;
    current_state_ = START;
    previous_state_ = OUTSKIRTS;
}

void ofApp::runner() {
    // not an og function. added this in myself
}

void ofApp::update() {
    if (distance_left_ == 0) {
        previous_state_ = END;
        current_state_ = END;
    } if (current_state_ != RATION && current_state_ != START && current_state_ != SETUP_TYPE) {
        if (distance_left_ % kCityLocation <= kCitySize) {
            current_state_ = CITY;
        } else {
            current_state_ = OUTSKIRTS;
        }
    }
    
    // TODO - somehow make them eat and drink one a day,
    // group.Eat(food_ration_amount);
    // group.Drink(water_ration_amount);
}

void ofApp::reset() {
    
}

void ofApp::draw() {
    if (current_state_ == START) {
        drawStartScreen();
    } else if (current_state_ == SETUP_TYPE) {
        drawSetupTypeScreen();
    } else if (current_state_ == OUTSKIRTS) {
        drawOutskirtsScreen();
    } else if (current_state_ == CITY) {
        drawCityScreen();
    } else if (current_state_ == END) {
        drawEndScreen();
    } else if (current_state_ == RATION) {
        drawRation();
    }
    
    if (showStatus) {
        drawStatus();
    }
    if (displayMessage) {
        drawMessage();
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
    }
    user_input_.append (1, (char) key);
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
        return;
    }
    if (current_state_ == SETUP_TYPE) {
        setupType();
        return;
    }
    
    // do the actions for ration
    if (current_state_ == RATION) {
        showStatus = false;
        rationInput();
    }
    
    showStatus = true;  // once implement in buy/sell system, may have to get rid of this
    displayMessage = false;
    if (user_input_ == "scavenge") {
        Scavenge();
        return;
    } else if (user_input_ == "kill zombies") { // TODO - implement this in better
        int random_kill = rand() % 20;
        group.get_players_in_group()[0]->set_kill_count(group.get_players_in_group()[0]->get_kill_count() + random_kill);
        return;
    } else if (user_input_ == "rest") {
        Rest();
        return;
    } else if (user_input_ == "eat") {
        Eat();
        return;
    } else if (user_input_ == "drink") {
        Drink();
        return;
    } else if (user_input_ == "travel") {
        Travel();
        return;
    } else if (user_input_ == "ration") {
        Ration();
        return;
    }

    if (current_state_ == OUTSKIRTS) {
        if (user_input_ == "gather food") {
            GatherFood();
            return;
        } else if (user_input_ == "gather water") {
            GatherWater();
            return;
        }
    }
    if (current_state_ == CITY) {
        if (user_input_ == "buy") {
            
        } else if (user_input_ == "sell") {
            
        }
    }
}

void ofApp::drawStatus() {
    std::string stats = current_time_.to_string() + group.StatInfo()
                        + "\nDistance Left: " + std::to_string(distance_left_) + " miles";
    game_font_.drawString(stats, ofGetWidth() * kTextWidth, ofGetHeight() * kTextHeight);
}

void ofApp::drawMessage() {
    message_bg_.draw(0, ofGetHeight() * .20);
    game_text_.setText(message);
    game_text_.wrapTextArea(ofGetWidth() * 0.7, ofGetHeight() * 0.25);
    game_text_.drawCenter(ofGetWidth() * .5, ofGetHeight() * .25);
}

void ofApp::drawUserInput() {
    ofSetColor(225, 225, 225);
    game_font_.drawString(user_input_,  ofGetWidth() * kTextWidth, ofGetHeight() * 0.98);
}

void ofApp::drawStartScreen() {
    start_bg_.draw(0, 0);
    std::string instructions;
    if (group.get_players_in_group().size() == 0) {
        instructions = "Please type in your name: ";
    } else if (group.get_players_in_group().size() != Group::kMaxNumPlayers) {
        instructions = "Please type in your other group member's \nname: ";
    }
    game_font_.drawString(instructions, ofGetWidth() * kTextWidth, ofGetHeight() * kTextHeight);
}

void ofApp::drawSetupTypeScreen() {
    setup_type_bg_.draw(0, 0);
    std::string instructions = "Type in your character class:\n1. banker (money++)    2. hunter (food+ water+)\n3. doctor (medicine++)  4. regular joe (no perks)";
    game_font_.drawString(instructions, ofGetWidth() * kTextWidth, ofGetHeight() * kTextHeight);
}

void ofApp::drawOutskirtsScreen() {
    country_bg_.draw(0,0);
    
}

void ofApp::drawCityScreen() {
    city_bg_.draw(0, 0);

}

void ofApp::drawEndScreen() {
    end_bg_.draw(0, 0);
    std::string end_text = "Congratulations! You survived and made it to Alaska!";
    game_text_.setText(end_text);
    game_text_.wrapTextArea(ofGetWidth() * 0.90, ofGetHeight() * 0.30);
    game_text_.draw(ofGetWidth() * kTextWidth, ofGetHeight());
}

void ofApp::drawRation() {
    ration_bg_.draw(0, 0);
    std::string text = "How much food should each person get?\n1-4: Saves food, but people will be hungry\n5-9: Sufficient, enough to get by\n10+: Very filling, but wastes a lot of food";
    game_font_.drawString(text, ofGetWidth() * kTextWidth, ofGetHeight() * 0.75);
}

void ofApp::setupGroup() {  // Hard-coded this in, maybe will be able to use JSON for C++ or something??
    group.set_food_amount(kStartFood);
    group.set_water_amount(kStartWater);
    
    setupPlayer(user_input_);
    
    if (group.get_players_in_group().size() == Group::kMaxNumPlayers) {
        current_state_ = SETUP_TYPE;
        previous_state_ = START;
    }
}

void ofApp::setupPlayer(std::string name) {
    Playable* player = new Playable(name, Playable::CharacterType::REGULAR_JOE); /** TEST IF THIS WORKS */
    group.AddPlayer(player);
}

void ofApp::setupType() {
    const int kBonus = 50;
    if (user_input_ == "banker") {
        group.get_main_player()->set_character_type(Playable::CharacterType::BANKER);
        group.AddMoney(kBonus);
        current_state_ = RATION;
        previous_state_ = OUTSKIRTS;
    } else if (user_input_ == "hunter") {
        group.get_main_player()->set_character_type(Playable::CharacterType::HUNTER);
        group.AddFood(kBonus / 2);
        group.AddWater(kBonus / 2);
        current_state_ = RATION;
        previous_state_ = OUTSKIRTS;
    } else if (user_input_ == "doctor") {
        group.get_main_player()->set_character_type(Playable::CharacterType::DOCTOR);
        group.AddMedicine(kBonus);
        current_state_ = RATION;
        previous_state_ = OUTSKIRTS;
    } else if (user_input_ == "regular joe") {
        group.get_main_player()->set_character_type(Playable::CharacterType::REGULAR_JOE);
        current_state_ = RATION;
        previous_state_ = OUTSKIRTS;
    }
}

void ofApp::rationInput() { // TODO - ration water and food separetly
    int ration_amount = std::stoi(user_input_);
    if (ration_amount * group.get_players_in_group().size() > group.get_food_amount() || ration_amount < 0) {
        displayMessage = true;
        message = "You don't have enough food to ration " + user_input_ + " for each person";
        return; // is this the right way to re-ask for input???
    }
    displayMessage = false;
    current_state_ = previous_state_;
    food_ration_amount = ration_amount;
    water_ration_amount = ration_amount;    // change this obviously
}

void ofApp::TimePass() {
    int hours = rand() % 12 + 3;
    current_time_.AdvanceTime(hours);
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

void ofApp::Rest() {
    int kSleepTime = 8;
    current_time_.AdvanceTime(kSleepTime, 0);
    current_time_.ConvertTime();
}

void ofApp::Eat() {
    if (group.get_food_amount() < food_ration_amount) {
        displayMessage = true;
        message = "There's not enough food to eat :(";
        return;
    }
    group.Eat(food_ration_amount);
    TimePass();
}

void ofApp::Drink() {
    if (group.get_water_amount() < water_ration_amount) {
        displayMessage = true;
        message = "There's not enough water to drink :(";
        return;
    }
    group.Drink(water_ration_amount);
    TimePass();
}

void ofApp::GatherFood() {
    int food_amount = rand() % 50 + 10;
    group.AddFood(food_amount);
    TimePass();
}

void ofApp::GatherWater() {
    int water_amount = rand() % 25 + 5;
    group.AddWater(water_amount);
    TimePass();
}

void ofApp::Travel() {
    int amountTravel = rand() % 5 + 1;
    int travel_time = amountTravel * 3;
    distance_left_ -= amountTravel;
    
    if (group.get_current_vehicle()) {
        travel_time /= group.get_current_vehicle()->get_speed();
    }
    
    current_time_.AdvanceTime(travel_time, 0);
    current_time_.ConvertTime();
}

void ofApp::Ration() {
    previous_state_ = current_state_;
    current_state_ = RATION;
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


