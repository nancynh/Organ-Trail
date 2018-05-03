//
// Created by Nancy Hong on 4/15/18.
//

#include "ofApp.h"

ofApp::ofApp() {
    
}

void ofApp::setup() {
    ofSetWindowTitle("Organ Trail");
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
    ration_food_bg_.load("ration-bg.png");
    ration_water_bg_.load("ration-water-bg.png");
    message_bg_.load("message-bg.png");
    market_bg_.load("market-bg.png");
    heal_bg_.load("heal-bg.png");
    dead_bg_.load("dead-bg.png");
    
    distance_left_ = kMaxDistance;
    current_state_ = START;
    previous_state_ = OUTSKIRTS;
}

void ofApp::update() {
    if (distance_left_ == 0) {
        previous_state_ = END;
        current_state_ = END;
    } if (current_state_ == CITY || current_state_ == OUTSKIRTS) {
        showStatus = true;
        if (distance_left_ % kCityLocation <= kCitySize) {
            current_state_ = CITY;
        } else {
            current_state_ = OUTSKIRTS;
        }
    } else {
        showStatus = false;
    }
    
    int kHoursInDay = 24;
    if (current_hours_ / kHoursInDay > 0) {
        current_hours_ = current_hours_ % kHoursInDay;

        // Group eats their respective rations
        GroupRation();
        
        // Change the price randomly in the market
        ChangePrice();
        
        // Checks if anyone has died yet
        DeathCheck();
    }
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
    } else if (current_state_ == RATION_FOOD) {
        drawRationFood();
    } else if (current_state_ == RATION_WATER) {
        drawRationWater();
    } else if (current_state_ == BUY_ITEM) {
        drawBuyItem();
    } else if (current_state_ == BUY_AMOUNT) {
        drawBuyAmount();
    } else if (current_state_ == SELL_ITEM) {
        drawSellItem();
    } else if (current_state_ == SELL_AMOUNT) {
        drawSellAmount();
    } else if (current_state_ == HEAL_PERSON) {
        drawHealPerson();
    } else if (current_state_ == HEAL_AMOUNT) {
        drawHealAmount();
    } else if (current_state_ == KILL_PLAYER) {
        drawKillPlayer();
    } else if (current_state_ == DEAD) {
        drawDead();
    } else if (current_state_ == PLAYER_STATS) {
        drawPlayerStats();
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
        input();
        user_input_ = "";
        return;
    } else if (key == OF_KEY_TAB) {
        screenshot_.grabScreen(0, 0, ofGetWidth(), ofGetHeight());
        screenshot_.save("SCREENSHOT.png");
    }
    user_input_.append (1, (char) key);
}

void ofApp::input() {
    if (current_state_ == START) {
        setupGroup();
        return;
    } else if (current_state_ == SETUP_TYPE) {
        setupType();
        return;
    } else if (current_state_ == RATION_FOOD) {
        RationFood();
        return;
    } else if (current_state_ == RATION_WATER) {
        RationWater();
        return;
    } else if (current_state_ == BUY_ITEM) {
        BuyItem();
        return;
    } else if (current_state_ == BUY_AMOUNT) {
        BuyAmount();
        return;
    } else if (current_state_ == SELL_ITEM) {
        SellItem();
        return;
    } else if (current_state_ == SELL_AMOUNT) {
        SellAmount();
        return;
    } else if (current_state_ == HEAL_PERSON) {
        HealPerson();
        return;
    } else if (current_state_ == HEAL_AMOUNT) {
        HealAmount();
        return;
    } else if (current_state_ == KILL_PLAYER) {
        KillPlayer();
        return;
    } else if (current_state_ == PLAYER_STATS) {
        ShowPlayerStats();
        return;
    } else if (current_state_ == DEAD) {
        Dead();
        return;
    }
    
    if (previous_input_ == "help" || previous_input_ == "not found") {
        displayMessage = false;
    }
    
    if (user_input_ == "scavenge") {
        Scavenge();
        return;
    } else if (user_input_ == "kill zombies") {
        KillZombies();
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
    } else if (user_input_ == "heal") {
        Heal();
        return;
    } else if (user_input_ == "kill") {
        Kill();
        return;
    } else if (user_input_ == "help") {
        Help();
        previous_input_ = "help";
        return;
    } else if (user_input_ == "player stats") {
        PlayerStats();
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
            Buy();
        } else if (user_input_ == "sell") {
            Sell();
        }
    }
}

void ofApp::drawStatus() {
    std::string stats = current_time_.to_string() +
                        "          Distance Left: " + std::to_string(distance_left_) + "\n"
                        + group.StatInfo()
                        + "\nHunger: " + std::to_string(user_hunger_level_)
                        + " / 100" + "          Thirst: " + std::to_string(user_thirst_level_) + " / 30";
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

void ofApp::drawRationFood() {
    ration_food_bg_.draw(0, 0);
    std::string text = "How much food should each person get?\n1-4: Saves food, but people will be hungry\n5-9: Sufficient, enough to get by\n10+: Very filling, but wastes a lot of food";
    game_font_.drawString(text, ofGetWidth() * kTextWidth, ofGetHeight() * kTextHeight);
}

void ofApp::drawRationWater() {
    ration_water_bg_.draw(0, 0);
    std::string text = "How much water should each person get?\n1-2: Saves water, but people will be thristy\n3-4: Sufficient, enough to get by\n5+: Hydrated, but wastes a lot of water";
    game_font_.drawString(text, ofGetWidth() * kTextWidth, ofGetHeight() * kTextHeight);
}

void ofApp::drawBuyItem() {
    market_bg_.draw(0,0);
    std::string text = "What would you like to buy?\nFood: $" + std::to_string(food_buy_price)
                        + "     Water: $" + std::to_string(water_buy_price)
                        + "\nMedicine: $" + std::to_string(medicine_buy_price);
    game_font_.drawString(text, ofGetWidth() * kTextWidth, ofGetHeight() * kTextHeight);
}

void ofApp::drawBuyAmount() {
    market_bg_.draw(0,0);
    std::string text = "How much " + previous_input_ + " do you want to buy?";
    game_font_.drawString(text, ofGetWidth() * kTextWidth, ofGetHeight() * kTextHeight);
}

void ofApp::drawSellItem() {
    market_bg_.draw(0, 0);
    std::string text = "What would you like to sell?\nFood: $" + std::to_string(food_sell_price)
                        + "     Water: $" + std::to_string(water_sell_price)
                        + "\nMedicine: $" + std::to_string(medicine_sell_price);
    game_font_.drawString(text, ofGetWidth() * kTextWidth, ofGetHeight() * kTextHeight);
}

void ofApp::drawSellAmount() {
    market_bg_.draw(0, 0);
    std::string text = "How much " + previous_input_ + " do you want to sell?";
    game_font_.drawString(text, ofGetWidth() * kTextWidth, ofGetHeight() * kTextHeight);
}

void ofApp::drawHealPerson() {
    heal_bg_.draw(0, 0);
    std::string text = "Who do you want to heal?";
    game_font_.drawString(text, ofGetWidth() * kTextWidth, ofGetHeight() * kTextHeight);
}

void ofApp::drawHealAmount() {
    heal_bg_.draw(0, 0);
    std::string text = "How much medicine do you want to use to heal " + previous_input_;
    game_font_.drawString(text, ofGetWidth() * kTextWidth, ofGetHeight() * kTextHeight);
}

void ofApp::drawKillPlayer() {
    start_bg_.draw(0, 0);
    std::string text = "Who do you want to kill?";
    game_font_.drawString(text, ofGetWidth() * kTextWidth, ofGetHeight() * kTextHeight);
}

void ofApp::drawDead() {
    dead_bg_.draw(0, 0);
    std::string text = "You died from " + previous_input_ + "!\nGame over.";
    game_font_.drawString(text, ofGetWidth() * kTextWidth, ofGetHeight() * kTextHeight);
}

void ofApp::drawPlayerStats() {
    start_bg_.draw(0, 0);
    std::string text = "Who's stats do you want to see?";
    game_font_.drawString(text, ofGetWidth() * kTextWidth, ofGetHeight() * kTextHeight);
}

void ofApp::setupGroup() {
    group.set_food_amount(kStartFood);
    group.set_water_amount(kStartWater);
    group.set_money(kStartMoney);
    group.set_meicine_amount(kStartMedicine);
    
    setupPlayer(user_input_);
    
    if (group.get_players_in_group().size() == Group::kMaxNumPlayers) {
        current_state_ = SETUP_TYPE;
        previous_state_ = START;
    }
}

void ofApp::setupPlayer(std::string name) {
    Player* player = new Player(name, Player::CharacterType::REGULAR_JOE);
    group.AddPlayer(player);
}

void ofApp::setupType() {
    const int kBonus = 50;
    if (user_input_ == "banker") {
        group.get_main_player()->set_character_type(Player::CharacterType::BANKER);
        group.AddMoney(kBonus);
        current_state_ = RATION_FOOD;
        previous_state_ = OUTSKIRTS;
    } else if (user_input_ == "hunter") {
        group.get_main_player()->set_character_type(Player::CharacterType::HUNTER);
        group.AddFood(kBonus / 2);
        group.AddWater(kBonus / 2);
        current_state_ = RATION_FOOD;
        previous_state_ = OUTSKIRTS;
    } else if (user_input_ == "doctor") {
        group.get_main_player()->set_character_type(Player::CharacterType::DOCTOR);
        group.AddMedicine(kBonus);
        current_state_ = RATION_FOOD;
        previous_state_ = OUTSKIRTS;
    } else if (user_input_ == "regular joe") {
        group.get_main_player()->set_character_type(Player::CharacterType::REGULAR_JOE);
        current_state_ = RATION_FOOD;
        previous_state_ = OUTSKIRTS;
    }
}

void ofApp::GroupRation() {
    int const kBonus = 3;
    int hunger = 8;
    int thirst = 3;
    
    if (current_time_.get_current_season() == Time::WINTER) {
        hunger += kBonus;
    } else if (current_time_.get_current_season() == Time::SUMMER) {
        thirst += kBonus;
    }
    
    if (group.get_food_amount() == 0) {
        user_hunger_level_ += hunger;
        group_hunger_level_ += hunger;
    } else {
        group.Eat(food_ration_amount);
        user_hunger_level_ += hunger - food_ration_amount;
        group_hunger_level_ += hunger - food_ration_amount;
    }
    if (group.get_water_amount() == 0) {
        user_thirst_level_ += thirst;
        group_thirst_level_ += thirst;
    } else {
        group.Drink(water_ration_amount);
        user_thirst_level_ += thirst - water_ration_amount;
        group_thirst_level_ += thirst - water_ration_amount;
    }
    
    if (user_thirst_level_ < 0) {
        user_thirst_level_ = 0;
    }
    if (group_thirst_level_ < 0) {
        group_thirst_level_ = 0;
    }
    if (user_hunger_level_ < 0) {
        user_hunger_level_ = 0;
    }
    if (group_hunger_level_ < 0) {
        group_hunger_level_ = 0;
    }
}

void ofApp::ChangePrice() {
    if (current_state_ == CITY) {
        
        // These numbers are just the ranges of prices for the goods
        food_buy_price = rand() % 20 + 14;
        water_buy_price = rand() % 13 + 7;
        medicine_buy_price = rand() % 35 + 25;
        
        food_sell_price = rand() % 9 + 5;
        water_sell_price = rand() % 5 + 1;
        medicine_sell_price = rand() % 18 + 10;
    }
}

void ofApp::DeathCheck() {
    if (user_hunger_level_ >= Player::kMaxHunger) {
        current_state_ = DEAD;
        previous_input_ = "starvation";
    } else if (user_thirst_level_ >= Player::kMaxThirst) {
        current_state_ = DEAD;
        previous_input_ = "dehydration";
    } else if (group.get_main_player()->get_health() <= 0) {
        current_state_ = DEAD;
        previous_input_ = "poor health";
    } else if (group_hunger_level_ >= Player::kMaxHunger) {
        displayMessage = true;
        message = "Congrats. Everyone but you died from starvation. You didn't follow the rations, did you?";
        previous_input_ = "not found";
        group.RemoveAllGroupMembers();
    } else if (group_thirst_level_ >= Player::kMaxThirst) {
        displayMessage = true;
        message = "Congrats. Everyone but you died from dehydration. You didn't follow the rations, did you?";
        previous_input_ = "not found";
        group.RemoveAllGroupMembers();
    } else {
        for (int i = 1; i < group.get_players_in_group().size(); i++) {
            if (group.get_players_in_group()[i]->get_health() <= 0) {
                displayMessage = true;
                message = group.get_players_in_group()[i]->get_name() + " died from poor health. Why didn't you heal them?";
                previous_input_ = "not found";
                group.RemovePlayer(group.get_players_in_group()[i]);
                break;
            }
        }
    }
}

void ofApp::RationFood() {
    int ration_amount = std::stoi(user_input_);
    if (ration_amount * group.get_players_in_group().size() > group.get_food_amount() || ration_amount < 0) {
        displayMessage = true;
        message = "You don't have enough food to ration " + user_input_ + " for each person";
        return;
    }
    displayMessage = false;
    current_state_ = RATION_WATER;
    food_ration_amount = ration_amount;
}

void ofApp::RationWater() {
    int ration_amount = std::stoi(user_input_);
    if (ration_amount * group.get_players_in_group().size() > group.get_water_amount() || ration_amount < 0) {
        displayMessage = true;
        message = "You don't have enough water to ration " + user_input_ + " for each person";
        return;
    }
    displayMessage = false;
    current_state_ = previous_state_;
    water_ration_amount = ration_amount;
}

void ofApp::TimePass() {
    int hours = rand() % 12 + 3;
    current_time_.AdvanceTime(hours);
    current_time_.ConvertTime();
    current_hours_ += hours;
}

void ofApp::Scavenge() {
    int water_amount = rand() % 7;
    int food_amount = rand() % 13;
    int money_amount = rand() % 10;
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
    current_hours_ += kSleepTime;
}

void ofApp::Eat() {
    if (group.get_food_amount() < food_ration_amount) {
        displayMessage = true;
        message = "There's not enough food for you to eat\n(Change the rations to be able to eat the leftovers)";
        return;
    } else if (group.get_food_amount() < 0) {
        displayMessage = true;
        message = "There's not enough food for you to eat";
        return;
    }
    group.get_main_player()->Eat(food_ration_amount);
    group.RemoveFood(food_ration_amount);
    TimePass();
}

void ofApp::Drink() {
    if (group.get_water_amount() < water_ration_amount || group.get_water_amount() < 0) {
        displayMessage = true;
        message = "There's not enough water for you to drink\n(Change the rations to be able to drink the leftovers)";
        return;
    }  else if (group.get_water_amount() < 0) {
        displayMessage = true;
        message = "There's not enough water for you to drink";
        return;
    }
    group.get_main_player()->Drink(water_ration_amount);
    group.RemoveWater(water_ration_amount);
    TimePass();
}

void ofApp::KillZombies() {
    int random_kill = rand() % 20;
    group.get_main_player()->set_kill_count(group.get_main_player()->get_kill_count() + random_kill);
    displayMessage = true;
    message = "You killed " + std::to_string(random_kill) + " zombies";
    previous_input_ = "not found";
    
    // Randomly does damage to one player in the group
    int index = rand() % group.get_players_in_group().size();
    int damage = rand() % 13 + 1;
    group.DecreaseHealth(index, damage); 
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
    current_hours_ += travel_time;
}

void ofApp::Ration() {
    previous_state_ = current_state_;
    current_state_ = RATION_FOOD;
}

void ofApp::Buy() {
    previous_state_ = current_state_;
    current_state_ = BUY_ITEM;
}

void ofApp::Sell() {
    previous_state_ = current_state_;
    current_state_ = SELL_ITEM;
}

void ofApp::BuyItem() {
    if (user_input_ != "food" && user_input_ != "water" && user_input_ != "medicine") {
        displayMessage = true;
        message = "You can't buy " + user_input_;
        return;
    }
    displayMessage = false;
    current_state_ = BUY_AMOUNT;
    previous_input_ = user_input_;
}

void ofApp::BuyAmount() {
    int amount = std::stoi(user_input_);
    int cost = -1;
    
    if (previous_input_ == "food") {
        displayMessage = true;
        message = "gimme food fam!";
        cost = amount * food_buy_price;
    } else if (previous_input_ == "water") {
        displayMessage = true;
        message = "h2o w go!";
        cost = amount * water_buy_price;
    } else if (previous_input_ == "medicine") {
        displayMessage = true;
        message = "i need drugs!";
        cost = amount * medicine_buy_price;
    }
    
    if (amount < 0) {
        displayMessage = true;
        message = "You can't buy " + user_input_ + " " + previous_input_;
        return;
    } else if (cost > group.get_money() || cost < 0) {
        displayMessage = true;
        message = "You don't have enough money to buy " + user_input_ + " " + previous_input_;
        return;
    }

    if (previous_input_ == "food") {
        group.AddFood(amount);
    } else if (previous_input_ == "water") {
        group.AddWater(amount);
    } else if (previous_input_ == "medicine") {
        group.AddMedicine(amount);
    }
    group.RemoveMoney(cost);
    displayMessage = false;
    current_state_ = previous_state_;
    
    if (amount != 0) {
        TimePass();
    }
}

void ofApp::SellItem() {
    if (user_input_ != "food" && user_input_ != "water" && user_input_ != "medicine") {
        displayMessage = true;
        message = "You can't sell " + user_input_;
        return;
    }
    displayMessage = false;
    current_state_ = SELL_AMOUNT;
    previous_input_ = user_input_;
}

void ofApp::SellAmount() {
    int amount = std::stoi(user_input_);
    int cost = -1;
    
    if (previous_input_ == "food") {
        cost = amount * food_sell_price;
    } else if (previous_input_ == "water") {
        cost = amount * water_sell_price;
    } else if (previous_input_ == "medicine") {
        cost = amount * medicine_sell_price;
    }
    
    if (amount < 0) {
        displayMessage = true;
        message = "You can't sell " + user_input_ + " " + previous_input_;
        return;
    } else if ((previous_input_ == "food" && amount > group.get_food_amount())
               || (previous_input_ == "water" && amount > group.get_water_amount())
               || (previous_input_ == "medicine" && amount > group.get_medicine_amount())
               || cost < 0) {
        displayMessage = true;
        message = "You don't have " + user_input_ + " " + previous_input_ + " to sell";
        return;
    }
    
    if (previous_input_ == "food") {
        group.RemoveFood(amount);
    } else if (previous_input_ == "water") {
        group.RemoveWater(amount);
    } else if (previous_input_ == "medicine") {
        group.RemoveMedicine(amount);
    }
    group.AddMoney(cost);
    displayMessage = false;
    current_state_ = previous_state_;
    
    if (amount != 0) {
        TimePass();
    }
}

void ofApp::Heal() {
    previous_state_ = current_state_;
    current_state_ = HEAL_PERSON;
}

void ofApp::HealPerson() {
    bool name_found = findInGroup(user_input_);
    if (!name_found && user_input_ != "myself") {
        displayMessage = true;
        message = user_input_ + " is not in your group";
        return;
    }
    if (user_input_ == "myself") {
        previous_input_ = "0";
    }
    displayMessage = false;
    current_state_ = HEAL_AMOUNT;
}

void ofApp::HealAmount() {
    int amount = std::stoi(user_input_);
    if (amount < 0) {
        displayMessage = true;
        message = "You can't use " + user_input_ + " medicine";
        return;
    } else if (amount > group.get_medicine_amount()) {
        displayMessage = true;
        message = "You don't have " + user_input_ + " medicine";
        return;
    }
    
    Player* heal_player = group.get_players_in_group()[std::stoi(previous_input_)];
    group.get_main_player()->Heal(heal_player, amount);
    
    displayMessage = false;
    current_state_ = previous_state_;
    group.RemoveMedicine(amount);
    
    if (amount != 0) {
        TimePass();
    }
}

void ofApp::Kill() {
    previous_state_ = current_state_;
    current_state_ = KILL_PLAYER;
}

void ofApp::KillPlayer() {
    bool name_found = findInGroup(user_input_);
    if (!name_found && user_input_ != "myself") {
        displayMessage = true;
        message = user_input_ + " is not in your group";
        return;
    }
    if (user_input_ == group.get_main_player()->get_name() || user_input_ == "myself") {
        previous_input_ = "killing yourself (wow was the\nZombie Apocalpyse too much for you?)";
        current_state_ = DEAD;
        displayMessage = false;
        return;
    }
    group.RemovePlayer(group.get_players_in_group()[std::stoi(previous_input_)]);
    displayMessage = true;
    message = "You killed " + user_input_ + "! ... you seem to have a lot more food now though.";
    group.AddFood(100);
    previous_input_ = "not found";
    current_state_ = previous_state_;
}

bool ofApp::findInGroup(std::string name) {
    for (int i = 0; i < group.get_players_in_group().size(); i++) {
        if (group.get_players_in_group()[i]->get_name() == name) {
            previous_input_ = std::to_string(i);
            return true;
        }
    }
    return false;
}

void ofApp::Dead() {
    displayMessage = true;
    message = "You can't continue the game. Please restart.";
}

void ofApp::Help() {
    displayMessage = true;
    message = "You can: scavenge, kill zombies, rest, eat, drink, travel, ration, player stats, ";
    if (current_state_ == CITY) {
        message += "heal, buy, and sell";
    } else if (current_state_ == OUTSKIRTS) {
        message += "heal, gather food, and gather water";
    } else {
        message += " and heal";
    }
}

void ofApp::PlayerStats() {
    previous_state_ = current_state_;
    current_state_ = PLAYER_STATS;
}

void ofApp::ShowPlayerStats() {
    bool name_found = findInGroup(user_input_);
    if (!name_found) {
        displayMessage = true;
        message = user_input_ + " is not in your group";
        return;
    }
    displayMessage = true;
    message = group.get_players_in_group()[std::stoi(previous_input_)]->Stats();
    if (user_input_ == group.get_main_player()->get_name()) {
        message = "Hunger: " + std::to_string(user_hunger_level_)
        + " / 100" + " Thirst: " + std::to_string(user_thirst_level_) + " / 30";
    } else {
        message = "Hunger: " + std::to_string(group_hunger_level_)
        + " / 100" + " Thirst: " + std::to_string(group_thirst_level_) + " / 30";
    }
    previous_input_ = "not found";
    current_state_ = previous_state_;
}

void ofApp::IncreaseHungerThirstLevel() {
    int hunger = 8;
    int thirst = 3;
    user_hunger_level_ += hunger;
    user_thirst_level_ += thirst;
    group_hunger_level_ += hunger;
    group_thirst_level_ += thirst;
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


