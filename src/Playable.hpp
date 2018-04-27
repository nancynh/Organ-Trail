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

class Playable : public Character {
    public : enum CharacterType {
        BANKER,
        HUNTER,
        CARPENTER,
        DOCTOR,
        REGULAR_JOE
    };
    
private:
    
    // The point at which the player will starve to death, decreases by 20 everyday
    int const kMaxHunger = 100;
    
    // The point at which th eplayer will die of thirst, decreases by 10 everyday
    int const kMaxThirst = 30;
    int hunger_level_;
    int thirst_level_;
    int kill_count_;
    CharacterType type_;
    
public:
    Playable();
    Playable(std::string name, CharacterType type);
    Playable(int health, std::string name, std::string age);
    Playable(int health, std::string name, std::string age, int kill_count, CharacterType type);
    Playable(int health, std::string name, std::string race, std::string age, std::string gender, int kill_count, CharacterType type);   // For customization purposes -> might take out later depending on time?
    
    /* Players keep watch of their own stuff to make sure no one steals it. */
    void KeepWatch();
    
    /* Players can reduce the damaged done to their equipment.
     * @param equipment - the thing to reduce the damage to
     */
    void Fix(Equipment equipment);
    
    /* Players can heal other characters given that they have enough medicine.
     * @param character - the character to be healed
     * @param medicine - the amount of medicine the group has
     */
    void Heal(Character character, int medicine);
    
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
    
    int get_hunger_level() const;
    int get_thrist_level() const;
    int get_kill_count() const;
    CharacterType get_character_type() const;
    void set_kill_count(int amount);
    
    friend bool operator==(const Playable& lhs, const Playable& rhs);
};

#endif /* Playable_hpp */
