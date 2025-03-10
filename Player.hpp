#ifndef PLAYER_HPP
#define PLAYER_HPP

#include <iostream>
#include <SDL2/SDL.h>
#include <string>
#include <map>
#include <vector>
#include "Input.hpp"
#include "Item.hpp"


/**
 * @brief Player header file
*/


/**
 * @brief Player class prototype
*/
class Player {
private:


std::string animation = "idle";


public:
    /**
     * @brief constructor prototype
     */
    Player(int health = 100, int shield = 0,int x=400,int y=400);
    /**
     * @brief destructor prototype
    */
    ~Player();

    /**
     * @brief Prototypes for setters and getters for player health
     * @param x desired health of player
    */
    int getHealth();
    void setHealth(int x);
    int getShield();
    void setShield(int x);
    /**
     * @brief sprite direction
     * @return string direction
    */
    std::string getDirection();

    /**
     * @brief setter for sprite direction
     * @param dir desired direction
    */
    void setDirection(std::string dir);

    /**
     * @brief X and Y directions
     * Required for collisions, or else may phase thru walls
    */
    std::string getXDirection();
    std::string getYDirection();

    /**
     * @brief Prototyps for player movements
    */
    void moveUp();
    void moveDown();
    void moveLeft();
    void moveRight();

    /**
     * Prototypes for setters and getters for X
     * @param desired x or y position
    */
    void setX(int);
    int getX();
    void setY(int);
    int getY();

    /**
     * @brief Use these values for drawing player sprites
     * as x and y are tl corner
    */
    int getDrawX();
    int getDrawY();

    /**
     * @brief Prototype for resizing player hitbox
     * @param wid width of hitbox
     * @param ht height of hitbox
    */
    void sizePlHbox(int wid, int ht);

    /**
     * @brief Prototype for updating player hitbox
     * updates player hitbox after any change
    */
    void updPlHbox();

    /**
     * @brief Prototype getter for player hitbox
     * @returns player hitbox for collision detection
    */ 
    SDL_Rect getPlHbox();
    
    /**
     * @brief Prototype for picking up item
    */
    void pickUpItem();
    /**
     * @brief Prototype setter for animation
    */
    void setAnimation(std::string anim);
    /**
     * @brief Prototype getter for animation
    */
   std::string getAnimation();
   /**
    * @brief Prototype for player attack
   */
  void attack();
    
    /**
     * @brief Prototype for pushing player
     * nums
     * + right
     * - left
    */
    void push(int x,int y);

    /**
     * @brief Wall collision push
     * call when player hitbox collides with walls
    */


    /**
     * @brief Editing player veloctiy values
    */
    int getPlayerVel();
    void setPlayerVel(int v);

    void equipItem(Item* item);
    string getActiveItem();
    void clearItem();

    /**
     * @brief Functions for getting Collision detection functions
    */
    string getXDir();
    string getYDir();

protected:
    int x, y, health, shield;
    //hitbox
    SDL_Rect plHbox;

    int hbWid, hbHt;
    Item* activeItem = nullptr;
    int velocity; //how fast the player moves
    static const std::map<std::string, int> dir;
    int spriteWid, spriteHt;
    SDL_Point front; //a point that is in front of the player, helps with collision det
    std::string direction = "down"; //sprite direction, may be redundant
    //for collision detection
    std::string XDirection;
    std::string YDirection;
};

#endif
