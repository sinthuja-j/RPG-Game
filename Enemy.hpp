#ifndef ENEMY_HPP
#define ENEMY_HPP
#include "Player.hpp"
#include <iostream>

/**
 * Enemy header file
*/

/**
 * Enemy class prototype
 * Subclass of player
*/
class Enemy : public Player {
    public:
    /**
     * Constructor prototype
    */
    Enemy(int posX, int posY, int health, int damage, int hitboxWid, int hitboxHt, char enemyDir, bool _isDead, Uint32 deathTime);

    /**
     * Destructor prototype
    */
    ~Enemy();

    /**
     * Prototype for getting health value
    */
    int getHealth();

    /**
     * Prototype for setting health value
    */
    void setHealth(int health);

    /**
     * Prototype getter for damage
    */
    int getDamage();

    /**
     * damage setter prototype
     * @param damage int
    */
    void setDamage(int damage);

    /**
     * Prototype setters and getters for enemy direction?
    */
    char getEnemyDir();


    /**
     * Prototype setter for enemyDir
     * @param enemyDir char
    */
    void setEnemyDir(char enemyDir);

    /**
     * Prototype setters and getters for X and Y position
    */
    int getPosX();

    /**
     * Prototype setter for posX
     * @param posX for x coordinate
    */
    void setPosX(int posX);
    int getPosY();
    /**
     * Prototype setter for posX
     * @param posY for y coordinate
    */
    void setPosY(int posY);

    /**
     * Prototype for enemy movement
     * @param player so the enemy moves towards player
    */
    void move(Player& player);

    /**
     * Prototype for enemy death
    */
    void onDeath(bool dead);

    bool isDead();
     /**
     * Prototype setter for _isDead
     * @param dead bool for dead value
    */
    void setDead(bool dead);
    Uint32 getDeathTime();
   
    /**
     * Prototype for sizeEhbox 
     * @param hitboxWid
     * @param hitbboxHt
    */
   void sizeEhbox(int hitboxWid, int hitboxHt);
    /**
     * Prototype for updateEhbox
    */
   void updateEhbox();
   /**
     * getter prototype for getEhbox
    */
   SDL_Rect getEhbox();

    protected:
    int  damage, enemyDir;
    bool _isDead;
    Uint32 deathTime;
    SDL_Rect ehbox;

};

#endif