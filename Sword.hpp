
#ifndef SWORD_HPP
#define SWORD_HPP
//#include "Item.hpp"
#include "ItemDefinitions.hpp"
#include "Graphics.hpp"
#include <string>

/**
 * Header file for sword class
*/


/**
 * Sword class prototype
*/
class Sword: public Item {
    public:
        /**
         * Prototype for constructor
         * @param name name of sword 
         * @param description description of sword
         * @param x x position of sword
         * @param y y position of sword
         * @param active is sword being used?
         * @param damage how much damage will the sword do
         * @param range how far will the sword strike
         * @param graphics graphics renderer
        */
        
        /**
         * @brief Prototype for sword use
        */
        void use() override {
            attack();
        }

        /**
         * @brief Prototype for attack
        */
        Sword(string name, string description, int x, int y, bool active, int hbWidth, int hbHeight, int damage, int range, Graphics *graphics);
        void attack();

        /**
         * @brief Prototype getters and setters for damage and range
         * @param x damage value or range value
        */
        int getDamage();
        int getRange();
        void setDamage(int x);
        void setRange(int x);

    protected:
        int damage;
        int range;
};
#endif