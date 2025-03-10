#include "HealthPotion.hpp"

/**
 * @brief
 * HealthPotion Class extends item
 * Purpose: used for HealthPotion items, defines attributes, useful methods for healthPotion interaction
 * @author Chase
*/

/**
 * Getter for healthPotion restorePower
 * @return restorePower int value for health increase upon use
*/
int HealthPotion::getRestorePower() {
    return restorePower;
}


/**
 * @brief Setter for healthPotion restorePower
 * @param restorePower int value for health increase upon use
*/
void HealthPotion::setRestorePower(int x) {
    restorePower = x;
}


/**
 * @brief Prototype for collision with player
 * @param player SDL_Rect
 * @return string
*/
std::string HealthPotion::OnCollideDescription(const SDL_Rect & player) {

    return "";
}

/**
 * @brief Prototype for absorb
*/
void HealthPotion::absorb() {
    cout << "You absorbed " << itemName << " for " << getRestorePower() << " health." << endl;
}

