#ifndef ITEM_HPP
#define ITEM_HPP

#include <SDL2/SDL.h>
#include <iostream>
#include <string>
#include <map>
#include "Definitions.hpp"
#include "Graphics.hpp"

using namespace std;

/**
 * @brief Item header file
*/

/**
 * @brief Item class prototype
*/

class Item {
    public: 
        /**
         * Constructors Prototypes
         * @param name name of item
         * @param description description of item
         * @param x x position of the item
         * @param y y position of the item
         * @param active is item being used?
         * @param graphics graphics renderer
         * @param hbWidth hitbox width
         * @param hbHeight hitbox height
        */
        Item(string name, string description, int x, int y, bool active, Graphics *graphics);
        //overloaded constructor with specified hitbox size
        Item(string name, string description, int x, int y, bool active, int hbWidth, int hbHeight, Graphics *graphics);
        
        /**
         * @brief Prototype for getting item name
        */
        string getItemName();

        /**
         * @brief Prototype for getting information?
        */
        string getInformation();

        /**
         * @brief Prototype for getters and setters for x and y axes
        */
        int getPosX();
        int getPosY();

        /**
         * @brief Prototype for setter and getter for hitbox
         * @param hbWidth hitbox width
         * @param hbHeight hitbox height
        */
        SDL_Rect getHbox();
        void setHbox(int hbWidth, int hbHeight);
        
        /**
         * @brief Prototype for updating hitbox position
        */
        void updHboxPos();
        
        /**
         * @brief Prototype setters for name, description, x, and y
         * @param name item name
         * @param description item description
         * @param x x position of item
         * @param y y position of item
        */
        void setItemName(string name);
        void setItemDescription(string description);
        void setPosX(int x);
        void setPosY(int y);

        /**
         * @brief Prototype for using item
        */
        virtual void use();

        /**
         * @brief Prototype for pickup and drop item
        */
        void pickUp();
        void drop();

        /**
         * @brief Prototype for setter and getters for item active states
         * @param active item use boolean?
        */
        bool getActive();
        void setActive(bool active);

        /**
         * @brief Prototype for drawing function
        */
        void draw();
        
    protected:
        string itemName;
        string itemDescription;
        SDL_Rect hbox;
        int hbWid;
        int hbHt;
        int posX;
        int posY;
        bool isActive;
        bool isPickedUp;
        Graphics *graphics;
        SDL_Rect sprite;
        std::map<std::string, SDL_Rect> spriteMap = {
            {"sword", {0,0,30,30}},
            {"shield", {30,0,30,30}},
            {"key", {60,0,30,30}},
            {"healthPotion", {0,30,30,30}}
        };
    private:
        
};


#endif