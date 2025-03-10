#ifndef INPUT_HPP
#define INPUT_HPP

#include <SDL.h>

/**
 * @brief Input class header
*/

/**
 * @brief Input class prototype
 * May be redundant
*/
class Input {
public:
    /**
     * @brief prototype for the input update function
    */
    void update();

    /**
     * @brief prototype for detecting keypress
     * @param key for detecting key type 
    */
    bool isKeyDown(SDL_Scancode key);
private:
    const Uint8* currentKeyStates = nullptr;
};

#endif
