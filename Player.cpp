#include "Player.hpp"
#include "Definitions.hpp"
#include "Collisions.hpp"



/**
 * @brief Player class represents a player
 * @authors Aidan, Jaree, Alan
*/

/**
 * @brief Player constructor initializes a player
 * @param health and position 
*/
Player::Player(int health, int shield,int x, int y) : health(health), shield(shield),x(x),y(y){
    //var init
    //if you need to change variables just change the numbers here and program will adjust accordingly
    //hitbox and sprite widths
    hbWid = 10;
    hbHt = 10;
    spriteWid = 16;
    spriteHt = 32;
    //makes move "speed" a variable
    velocity = 5; 
    //plHbox = {x+(hbWid/2),y+(hbHt/2),hbWid,hbHt};
    plHbox = {HitBoxPos(x,hbWid),HitBoxPos(y,hbHt),hbWid,hbHt};
    XDirection = "";
    YDirection = "";
    
}

/**
 * @brief Deconstructor
*/
Player::~Player() {
}

/**
 * @brief Getter for health
 * @return int value for health
*/
int Player::getHealth() {
    return health;
}

/**
 * @brief Setter for health
 * @param int value for health
*/
void Player::setHealth(int h) {
    health = h;
}

/**
 * @brief Setter for shield
 * @param int value for shield
*/
void Player::setShield(int s) {
    shield = s;
}

/**
 * @brief Getter for shield
 * @return int value for shield
*/
int Player::getShield() {
    return shield;
}

/**
 * @brief Moves player up
*/
void Player::moveUp() {
    YDirection = "up";
    y-=velocity;
    updPlHbox();
    
}

/**
 * @brief Moves player down
*/
void Player::moveDown() {
    YDirection = "down";
    y+=velocity;
    updPlHbox();
    
}

/**
 * @brief Moves player left
*/
void Player::moveLeft() {
    XDirection = "left";
    x-=velocity;
    updPlHbox();
    
}

/**
 * @brief Moves player right
*/
void Player::moveRight() {
    XDirection = "right";
    x+=velocity;
    updPlHbox();
    

}

/**
 * @brief Setter for x
 * @param int value for x
*/
void Player::setX(int x){
    this->x =x;
}

/**
 * @brief Getter for x
 * @return int value for x
*/
int Player:: getX(){
    //std::cout << x << std::endl;
    return x;
}

/**
 * @brief Setter for y
 * @param int value for y
*/
void Player::setY(int y){
    this->y =y;
}

/**
 * @brief Getter for y
 * @return int value for y
*/
int Player:: getY(){
    return y;
}

/**
 * @brief Getter for x direction
 * @return string value for x direction
*/
std::string Player::getXDir() {
    return XDirection;
}

/**
 * @brief Getter for y direction
 * @return string value for y direction
*/
std::string Player::getYDir(){
    return YDirection;
}


/***
 * @brief Set players hit box
 * @param height and width of hbox
*/
void Player::sizePlHbox(int wid, int ht) {
    //plHbox = {x+(wid/2),y+(ht/2),wid,ht};
    plHbox = {HitBoxPos(x,wid),HitBoxPos(y,ht),wid,ht};
    hbWid = wid;
    hbHt = ht;

}

/**
 * @brief Updates player hitbox
*/
void Player::updPlHbox() {
    //plHbox = {x+(hbWid/2),y+(hbHt/2),hbWid,hbHt};
    plHbox = {HitBoxPos(x,hbWid),HitBoxPos(y,hbHt),hbWid,hbHt};
    
}

/**
 * @brief Getter for player hitbox
 * @return SDL_Rect plhbox
*/
SDL_Rect Player::getPlHbox() {
    
    return plHbox;
}

/**
 * @brief Picks up item Prototype
*/
void Player::pickUpItem() {
    std::cout << "Player picks up item." << std::endl;
}

/**
 * @brief Setter for direction
 * @param string value for direction
*/
void Player::setDirection(std::string dir) {
    direction = dir;
}

/**
 * @brief Getter for direction
 * @return string value for direction
*/
std::string Player::getDirection() {
    return direction;
}

/**
 * @brief Setter for animation
 * @param string value for animation
*/

void Player::setAnimation(std::string anim) {
    animation = anim;
}

/**
 * @brief Getter for animation
 * @return animation string
*/
std::string Player::getAnimation() {
    return animation;
}

/**
 * @brief Player attack function
*/

void Player::attack() {
    setAnimation("attack");
}

/**
 * @brief Player push function
 * @param x how far you want to be pushed in the x direction
 * @param y how far you want to be pushed in the y direction
*/
void Player::push(int x, int y) {
    this->y += y;
    this->x += x;
    updPlHbox(); //do not remove
}

/**
 * @brief Use these for drawing model sprites rather than getX and getY
 * @author Alan
*/
int Player::getDrawX(){
    return HitBoxPos(x,spriteWid);
}
/**
 * @brief Use these for drawing model sprites rather than getX and getY
 * @author Alan
*/
int Player::getDrawY(){
    return HitBoxPos(y,spriteHt);
}


/**
 * @brief Player speed getter
*/

int Player::getPlayerVel() {
    return velocity;
}
/**
 * @brief Player speed setter
*/
void Player::setPlayerVel(int v) {
    velocity = v;
}

/**
 * @brief equip item
*/
void Player::equipItem(Item* item) {
    activeItem = item;
}

/**
 * @brief get active item
*/
string Player::getActiveItem() {
    if (activeItem == nullptr) {
        return "None";
    }
    return activeItem->getItemName();
}

/**
 * @brief clear item
*/
void Player::clearItem() {
    activeItem = nullptr;
}
