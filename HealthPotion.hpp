
#ifndef HEALTHPOTION_HPP
#define HEALTHPOTION_HPP
//#include "Item.hpp"
#include "ItemDefinitions.hpp"
/**
 * Header file for HealthPotion class
*/


/**
 * HealthPotion class prototype
*/
class HealthPotion: public Item {
    public:
        /**
         * Prototype for constructor
         * @param name name of potion
         * @param description description of potion
         * @param x x position of potion
         * @param y y position of potion
         * @param active is potion active?
         * @param restorePower amount the potion can heal player
         * @param graphics graphics renderer
        */
        HealthPotion(string name, string description, int x, int y, bool active,int hbWidth, int hbHeight, int restorePower, Graphics *graphics) : Item(name, description, x, y, active, graphics) {
            this->restorePower = restorePower;
            
        }
        void use() override {
            absorb();
        }

        /**
         * Prototype for absorb
        */
        void absorb();

        /**
         * Prototype getters and setters for restorePower
         * @param x health restoring value
        */
        int getRestorePower();
        void setRestorePower(int x);


        /**
         * Prototype for on collide description
         * TODO: unimplemented
        */
        std::string OnCollideDescription(const SDL_Rect &player);

    private:
        int restorePower;
};
#endif