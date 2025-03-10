#include "Sword.hpp"
#include "ItemDefinitions.hpp"
#include "Graphics.hpp"
#include <string>

/**
 * @brief Sword Class extends item
*/
Sword::Sword(string name, string description, int x, int y, bool active, int hbWidth, int hbHeight, int damage, int range, Graphics *graphics) : Item(name, description, x, y, active, hbWidth, hbHeight, graphics) {
        this->damage = damage;
        this->range = range;
            //setHbox(100,100); //testing
            
}

        

/**
 * @brief Getter for sword damage
 * @return int value for damage
*/
int Sword::getDamage() {
    return damage;
}

/**
 * @brief Getter for sword range
 * @return int value for range
*/
int Sword::getRange() {
    return range;
}

/**
 * @brief Setter for sword damage
 * @param int value for damage
*/
void Sword::setDamage(int x) {
    damage = x;
}

/**
 * @brief Setter for sword range
 * @param int value for range
*/
void Sword::setRange(int x) {
    range = x;
}

/**
 * @brief Prototype for collision with player
 * @return string
*/

/**
 * @brief Prototype for sword attack
*/
void Sword::attack() {
    cout << "You attacked with the " << itemName << " for " << getDamage() << " damage." << endl;
}

