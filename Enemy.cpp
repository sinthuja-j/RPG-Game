#include "Enemy.hpp"


/**
 * @brief
 * Enemy class file
 * 
 * This class is used for enemy objects within the game, it defines all the attributes of what makes an enemy from health, positioning, hitboxes etc.
 * This class ensures modularity and makes it easy to create and render enemies from within the game class. 
*/

/**
 * @brief Enemy Constructor
 * @param posX and posY represent position on a map
 * @param health represent enemy health
 * @param damage represent damage enemy does to player on hit
 * @param hitboxWid represents the hitbox width of the enemy
 * @param hitboxHt represents the hitbox height of the enemy
 * @param enemyDir char representation of the enemy direction
 * @param _isDead bool representing whether or not the enemy is dead
 * @param deathTime death timer used for death animation
*/
Enemy::Enemy(int posX, int posY, int health, int damage, int hitboxWid, int hitboxHt, char enemyDir, bool _isDead, Uint32 deathTime) 
{   
    //deprecated
    //this->posX = posX;
    //this->posY = posY;
    //new
    this->x = posX;
    this->y = posY;

    this->health = health;
    this->damage = damage;
    this->enemyDir = enemyDir;
    this->hbHt = hitboxHt;
    this->hbWid = hitboxWid;
    //this->plHbox = {HitBoxPos(posX,hbWid),HitBoxPos(posY,hbHt),hbWid,hbHt};
    this->_isDead = _isDead;
    this->deathTime = deathTime;
    this->velocity = 1; //add as param later
    this->YDirection = "";
    this->XDirection = "";
    //ehbox = {HitBoxPos(posX,hitboxWid),HitBoxPos(posY,hitboxHt),hitboxWid,hitboxHt};
    plHbox = {HitBoxPos(posX,hitboxWid),HitBoxPos(posY,hitboxHt),hitboxWid,hitboxHt};
}
/*
* @brief Deconstructor for Enemy
*/
Enemy::~Enemy(){

}

/**
 * @brief Getter for enemy health value
 * @return health int value 
*/
int Enemy::getHealth(){
    return health;
}

/**
 * @brief Setter for enemy health value
 * @param health int value
*/
void Enemy::setHealth(int health){
    this->health = health;
}

/**
 * @brief Getter for damage 
 * @return damage int value
*/
int Enemy::getDamage(){
    return damage;
}

/**
 * @brief Setter for damage
 * @param damage int value
*/
void Enemy::setDamage(int damage){
    this->damage = damage;
}

/**
 * @brief Getter for enemy dir
 * @return enemydir char
*/
char Enemy::getEnemyDir(){
    return enemyDir;
}

/**
 * @brief Setter for enemy dir
 * @param enemydir char
*/
void Enemy::setEnemyDir(char enemyDir){
    this->enemyDir = enemyDir;
}

/**
 * @brief Getter for xpos
 * @return x int value
*/
int Enemy::getPosX(){
    return x;
}

/**
 * @brief Setter for xpos
 * @param posX
*/
void Enemy::setPosX(int posX){
    this->x = posX;
}

/**
 * @brief Getter for ypos
 * @return y int value
*/
int Enemy::getPosY(){
    return y;
}

/**
 * @brief Setter for ypos
 * @param y int value
*/
void Enemy::setPosY(int posY){
    this->y = posY;
}

/**
 * @brief getter for hitbox
 * @return plHbox
*/
SDL_Rect Enemy::getEhbox(){
    return plHbox;
}
/**
* @brief used for hitbox size
*@param wid int value for hitbox width
*@param ht int value for hitbox height
*/
void Enemy::sizeEhbox(int wid, int ht) {

    hbWid = wid;
    hbHt = ht;
    plHbox = {HitBoxPos(x,hbWid),HitBoxPos(y,hbHt),hbWid,hbHt};

}

/**
 * @brief updates the hitbox
*/
void Enemy::updateEhbox() {
    plHbox = {x,y,hbWid,hbHt};
    //print out the values
    
}

/**
 * @brief Moves enemy
 * @param player a Player type object
*/
void Enemy::move(Player& player){
    if (x < player.getX()) {
       // x += velocity;
       moveRight();
        this->XDirection = "right";
    } else if (x > player.getX()) {
        //x -= velocity;
        moveLeft();
        this->XDirection = "left";
    }
    if (y < player.getY()) {
        //y += velocity;
        moveDown();
        this->YDirection= "down";
    } else if (y > player.getY()) {
        //y -= velocity;
        moveUp();
        this->YDirection= "up";
    }
    //updateEhbox();
}

/**
 * @brief used when enemy is killed, sets _isDead to true, gets deathTime used for death animation
 * @param dead bool used to represent whether enemy is dead
*/
void Enemy::onDeath(bool dead){
    if (dead) {
        _isDead = true;
        deathTime = SDL_GetTicks();
    }
}
/**
 * @brief gets value of _isDead
 * @return _isDead 
*/
bool Enemy::isDead(){
    return _isDead;
}
/**
 * @brief setter for _isDead
 * @param dead bool for whether enemy is dead
*/
void Enemy::setDead(bool dead) {
    _isDead = dead;
}
/**
 * @brief gets enemy death time
 * @return deathTime Uint32 for when enemy dies, deadTime
 *  used to hold a specific image for set amount of time until 
 *  it disappears when enemy dies and stops rendering
*/
Uint32 Enemy::getDeathTime(){
    return deathTime;
}



