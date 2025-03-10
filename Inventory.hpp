#ifndef INVENTORY_HPP
#define INVENTORY_HPP

#include <vector>
#include <iostream>
#include "Item.hpp"
#include "Collisions.hpp"
#include "Graphics.hpp"

/**
 * Inventory Header
*/

/**
 * Inventory Header class
*/
class Inventory {
    public:
        /**
         * @brief Constructor prototype
        */
        Inventory(bool cap);

        /**
         * @brief Prototype for adding an item
         * @param item takes an Item object
        */
        void addItem(Item* item);

        /**
         * @brief Prototype for removing an item
         * @param item takes an Item object
        */
        Item* removeItem(Item* item);

        /**
         * @brief Prototype for rendering on items in inventory on screen
        */
        void drawItems();

        /**
         * @brief Prototype for checking collisions
         * @param plHBOX takes an SDL_Rect
        */
        Item* checkCollision(SDL_Rect plHBOX);

        /**
         * brief Prototype for checking if item is in inventory
         * @param itemName takes a string
        */
        bool hasItem(std::string itemName);

        /**
         * @brief Prototype for displaying inventory
         * @param graphics takes a Graphics object
         * @param index takes an int
        */
        void displayInventory(Graphics *graphics, int index);
        /**
         * @brief Prototype for clearing inventory
        */
        void clearInventory();
        /**
         * @brief Prototype for getting items
        */
        std::vector<Item*> getItems();
    private:
        std::vector<Item*> items;
        bool cap;
};

#endif