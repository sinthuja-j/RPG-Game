#include "Inventory.hpp"

/**
 * @brief Inventory class
 * a bucket of items that can be added to, removed from and drawn as well as collision handle
 * @author Aidan
 * @author Jaree
*/

/**
 * @brief Constructor: only creates object
*/
Inventory::Inventory(bool cap) {
    this->cap = cap;    //temporarily set cap at 4
}

/**
 * @brief Add item to inventory
 * @param *Item type to be added to items
*/
void Inventory::addItem(Item* item) {
    if (cap && items.size() > 4) {
        std::cout << "Inventory Full";
    } else {
        items.push_back(item);
        std::cout << "Added " << item->getItemName() << " to inventory\n";
    }
}

/**
 * @brief Removes item from Inventory
 * @return if match, returns *Item to callerSS
*/
Item* Inventory::removeItem(Item* item) {
    for (auto it = items.begin();it != items.end();++it) {
        if ((*it)->getItemName() == item->getItemName()) {
            Item* temp = *it;
            items.erase(it);
            return (temp);
        }
    }
    return nullptr;
}

/**
 * @brief Draws Items using graphics ***NOT FOR PLAYER***
*/
void Inventory::drawItems() {
    for (auto it = items.begin(); it != items.end();++it) {
        (*it)->draw();
    }
}

/**
 * @brief Checks Collisions with @param plHBOX and all hit boxes of items
 * @return if collision, return Item*
*/
Item* Inventory::checkCollision(SDL_Rect plHBOX) {
    Collisions c;
    for (auto it = items.begin(); it != items.end();++it) {
        if (c.detectCollisionHB((*it)->getHbox(), plHBOX)) {
            return (*it);
        };
    };
    return nullptr;
}

/**
 * @brief Displays Inventory
 * @param graphics
 * @param index
*/
void Inventory::displayInventory(Graphics *graphics, int index) {
    SDL_Rect background = {0, 0, 400, 150};
    graphics->renderSprite("inventory", 200, 25, background);
    int x[] = {258, 325, 392, 460, 523};
    int i = 0;
  
    for (auto it = items.begin(); it != items.end(); ++it) {
        (*it)->setPosX(x[i]);
        (*it)->setPosY(112);
        (*it)->draw();
        if (index>0) {
            if (index==i+1) {
                SDL_Rect highlight{0,0,50,50};
                graphics->renderSprite("highlight", x[i]-17, 95,highlight);
            }
        }
        ++i;

    }
}

/**
 * @brief Checks if item is in inventory
 * @param itemName
 * @return true if item is in inventory
 * @return false if item is not in inventory
*/
bool Inventory::hasItem(std::string itemName) {
    for (auto it = items.begin(); it != items.end(); ++it) {
        if (((*it)->getItemName() == itemName)) {
            return true;
        }
    }
    return false;
}

/**
 * @brief Clears Inventory
 *
*/
void Inventory::clearInventory() {
    items.clear();
}

/**
 * @brief Getter for items
 * @return vector<Item*> items
*/
std::vector<Item*> Inventory::getItems() {
    return items;
}