#include "Item.hpp"
#include "Definitions.hpp"

/**
 * Item class represents an item
 * This class is extended to different types of items
*/




/**
 * Constructor for item
 * @param name for identification
 * @param description for information
 * @param x and y for positions
 * @param active if item to be shown
 * @param graphics to use for rendering
*/
Item::Item(string name, string description, int x, int y, bool active, Graphics *graphics) {
    itemName = name;
    itemDescription = description;
    posX = x;
    posY = y;
    isActive = active;
    isPickedUp = false;
    //sets variables for hitbox size
    hbHt = 50;
    hbWid = 50;
    //makes a 20px square hibox
    hbox = {HitBoxPos(x,hbWid),HitBoxPos(y,hbHt),hbWid,hbHt};
    this->graphics = graphics;
    sprite = spriteMap[name]; //auto sword for now
    

};

/**
 * @brief consturctor
 * @param hbWidth, hbHeight for custom hitbox size
*/
Item::Item(string name, string description, int x, int y, bool active, int hbWidth, int hbHeight, Graphics *graphics) {
    Item(name,  description,  x,  y, active, graphics);
    //scales hitbox
    hbox = {HitBoxPos(x,hbWidth),HitBoxPos(y,hbHeight),hbWidth,hbHeight};
    hbHt = hbHeight;
    hbWid = hbWidth;
    itemName = name;
    itemDescription = description;
    posX = x;
    posY = y;
    isActive = active;
    isPickedUp = false;
    //sets variables for hitbox size
    hbHt = 50;
    hbWid = 50;
    //makes a 20px square hibox
    this->graphics = graphics;
    sprite = spriteMap[name]; //auto sword for now
    
};

/**
 * @brief Helper function to calculate hit box
 * @param x and y position and hitbox size
 * @return SDL_Rect for hitbox
*/
SDL_Rect calcHitBox(int px, int py, int hbWidth, int hbHeight) {
    SDL_Rect temp = {HitBoxPos(px,hbWidth),HitBoxPos(py,hbHeight),hbWidth,hbHeight};
    return temp;

}

/**
 * @brief Getter for item name
 * @return string itemname
*/
string Item::getItemName() {
    return itemName;
}

/**
 * @brief Getter for hit box
 * @return SDL_Rect
*/
SDL_Rect Item::getHbox() {
    return hbox;
}

/**
 * @brief Set custom hitbox size
 * @param height and width of hbox
*/
void Item::setHbox(int hbWidth, int hbHeight) {
    
    
    hbWid = hbWidth;
    hbHt = hbHeight;
    //std::cerr << "Item: h " << hbHt << " w " << hbWid << " x " << posX << " y " << posY << " hw " << hbWidth << " hh " << hbHeight << "\n";
    updHboxPos();
}

/**
 * @brief Updates hitbox according to position 
*/
void Item::updHboxPos() {
    hbox = {HitBoxPos(posX,hbWid),HitBoxPos(posY,hbHt),hbWid,hbHt};
}

/**
 * @brief Getter for position x
 * @return int x
*/
int Item::getPosX() {
    return posX;
    
}

/**
 * @brief Getter for position y
 * @return int y
*/
int Item::getPosY() {
    return posY;

}

/**
 * @brief Setter for Item name
 * @param string name to be changed into
*/
void Item::setItemName(string name) {
    itemName = name;
}

/**
 * @brief Setter for Item description
 * @param description
*/
void Item::setItemDescription(string description) {
    itemDescription = description;
}

/**
 * @brief Setter for xposition 
 * @param int x
*/
void Item::setPosX(int x) {
    posX = x;
    updHboxPos();
}

/**
 * @brief Setter for y position
 * @param int y
*/
void Item::setPosY(int y) {

    posY = y;
    updHboxPos();
}

/**
 * @brief Getter for if active
 * @return bool value
*/
bool Item::getActive() {
    return isActive;
}

/**
 * @brief Setter for isActive
 * @param bool value to be set
*/
void Item::setActive(bool active) {
    isActive = active;
}

/**
 * @brief Use Item
*/
void Item::use() {
    cout << "You used the " << itemName << endl;

}

/**
 * @brief Pick up item prototype
*/
void Item::pickUp() {
    if (isPickedUp) {
        cout << "You already picked up the " << itemName << endl;
    } else {
        cout <<"You picked up the " << itemName << endl;
        isPickedUp = true;
    }
    
}
/**
 * @brief Drop item prototype
*/
void Item::drop() {
    if (isPickedUp) {
        cout << "You dropped the " << itemName << endl;
        isPickedUp = false;
    } else {
        cout << "You can't drop the " << itemName << " because you haven't picked it up yet" << endl;
    }
}

/**
 * @brief Getter for description
 * @return string description
*/
string Item::getInformation() {
    return itemDescription;
}

/**
 * @brief Renders sprite 
 * For now just fixed sprite for prototype
*/
void Item::draw() {
    graphics->renderSprite("objects", posX, posY, sprite);
}
 
