#ifndef COLLISIONS_H
#define COLLISIONS_H
#include <vector>
#include <SDL2/SDL.h>
#include "Player.hpp"
#include "Enemy.hpp"

/**
 * Collisions header file
 * @author Alan Kuang
*/

/**
 * Collisions class prototype
*/
class Collisions {
    public:
    /**
     * Constructor prototype
    */
    Collisions();

    /**
     * Destructor
    */
    ~Collisions();

    /**
     * Detect Collision Hitbox
     * @param entity1 first hitbox
     * @param entity2 second hitbox
    */
    bool detectCollisionHB(const SDL_Rect & entity1, const SDL_Rect & entity2);

    /**
     * wall collision enemy
    */
    void wallCollision(const std::vector<Enemy*> & p, const std::vector<SDL_Rect> & wall);

    /**
     * @overload wall collision for player
    */
    void wallCollision(Player & p, const std::vector<SDL_Rect> & wall, Input & in);

    
    private:
    int entityx, entityy,
    entityw,entityh; //old and deprecated
    

    protected:
};

#endif