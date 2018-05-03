//
//  Playable.hpp
//  final-project-nancynh
//
//  Created by Nancy Hong on 4/16/18.
//

#ifndef Playable_hpp
#define Playable_hpp

#include <stdio.h>
#include "Character.hpp"

class Player {
    public : enum CharacterType {
        BANKER,
        HUNTER,
        CARPENTER,
        DOCTOR,
        REGULAR_JOE
    };
    
private:
    int const kMaxHealth = 100;
    int health_;
    std::string name_;
    int hunger_level_;
    int thirst_level_;
    int kill_count_;
    CharacterType type_;
    
public:
    
    // The point at which the player will starve to death, decreases by 20 everyday
    static int const kMaxHunger = 100;
    
    // The point at which the player will die of thirst, decreases by 10 everyday
    static int const kMaxThirst = 30;
    
    Player();
    Player(std::string name, CharacterType type);
    
    /* Players can reduce the damaged done to their equipment.
     * @param equipment - the thing to reduce the damage to
     */
    void Fix(Equipment equipment);
    
    /* Players can heal other characters given that they have enough medicine.
     * @param character - the character to be healed
     * @param medicine - the amount of medicine the group has
     */
    void Heal(Player* character, int medicine);
    
    /* Players will be able to kill other characters, both zombies and the living.
     * @param character - the person to be killed
     */
    void Kill(Character character); // Left it as a generic character if player really wanted to kill someone in their own party, a zombie, or a NPC
    
    /* The player eats a certain amount of food.
     * @param amount - how much the player will eat
     */
    void Eat(int amount);
    
    /* The player drinks a certain amount of water.
     * @param amount - how much the player will drink
     */
    void Drink(int amount);
    
    /* Checks if the character is dead or not.
     * @return true is player's health > 0, false otherwise
     */
    bool IsDead();
    
    /* Checks if the player is dead from starvation or not
     * @return true, if the player's hunger level matches starvation level
     */
    bool IsStarving();
    
    /* Checks if the player is dead from dehydration or not
     * @return true, if the player's thirst level matches thirst dehydration level
     */
    bool IsDehydrated();
    
    /* Gives the information on the player.
     * @return a string of information on the player.
     */
    std::string Stats();
    
    int get_health() const;
    std::string get_name() const;
    int get_hunger_level() const;
    int get_thrist_level() const;
    int get_kill_count() const;
    CharacterType get_character_type() const;
    void set_health(int health);
    void set_kill_count(int amount);
    void set_character_type(CharacterType type);
    
    // take out later
    void set_hunger_level(int level);
    void set_thrist_level(int level);
    
    friend bool operator==(const Player& lhs, const Player& rhs);
};

#endif /* Playable_hpp */
