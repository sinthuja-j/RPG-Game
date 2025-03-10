#include <iostream> 
#include "Input.hpp"

/**
 * Input Class
 * handles all user input 
 * @author Chase
*/

/**
 * @brief updates key state
*/
void Input::update() {
    currentKeyStates = SDL_GetKeyboardState(NULL);
}

/**
 * checks if key is pressed
 * @return bool value for press
*/
bool Input::isKeyDown(SDL_Scancode key) {
    //std::cout << "Player walks up." << std::endl;
    return currentKeyStates[key] == 1;
    
}
