#include "Collisions.hpp"

#include "Definitions.hpp"
#include <iostream>

/**
 * Collision Class
 * @brief
 * Encompasses collisions between any two SDL_Rects.
 * @author Alan Kuang (akuang4)
*/

/**
 * constructor
*/
Collisions::Collisions() {

}

/**
 * destructor
*/
Collisions::~Collisions() {

}

/**
 * helper function
 * creates vector of corners and centre point
 * all corners and center SDL_Points are to be returned
 * @param r is a sdl rectangle to be "cornerized" 
 */
std::vector<SDL_Point> cornerizeRectangle(const SDL_Rect & r) {
    //top left
    SDL_Point tl = {r.x, r.y};
    //top right
    SDL_Point tr = {r.x+r.w, r.y};
    //centre
    //WARNING: if using positive w and h will have unexpected results as it would be going left instead of right
    //The reason why this is like this is because it worked perfectly back when the hitboxesd were broken.
    // --h == +h && --w == +w
    SDL_Point ctr = {HitBoxPos(r.x,-r.w),HitBoxPos(r.y,-r.h)}; 
    //bottom right
    SDL_Point br = {r.x+r.w, r.y+r.h};
    //bottom left
    SDL_Point bl = {r.x, r.y+r.h};

    std::vector<SDL_Point> v;
    v.push_back(tl);
    v.push_back(tr);
    v.push_back(ctr);
    v.push_back(bl);
    v.push_back(br);

    return v;

}



/**
 * detect collision hitbox class
 * @param entity1 is the first hitbox
 * @param entity2 is the second hitbox
*/
bool Collisions::detectCollisionHB(const SDL_Rect & entity1, const SDL_Rect & entity2) {

    //checks if rectangles intersect each other
    if(SDL_HasIntersection(&entity1,&entity2)) {
        return true;
    }

    else {
        //backup collision for hitboxes that encapsulate
        //checks if rectangle is inside another
        //if entitiy 1 is in entity 2
        std::vector<SDL_Point> ctest1 = cornerizeRectangle(entity1);
        for (int i = 0; i < ctest1.size(); i++) {
            SDL_Point tmp = ctest1[i];
            if (SDL_PointInRect(&tmp, &entity2)) {
                //std::cerr << "bCollision\n";
                //std::cerr << "i = " << i << " " <<  entity2.x << " " << entity2.y << " " << entity2.w << " " << entity2.h << " xywh\n";
                return true;
                
            }
        }
        //if entity 2 is in entity 1
        std::vector<SDL_Point> ctest2 = cornerizeRectangle(entity2);
        for (int i = 0; i < ctest2.size(); i++) {
            SDL_Point tmp = ctest2[i];
            if (SDL_PointInRect(&tmp, &entity1)) {
                //std::cerr << "cCollision\n";
                //std::cerr << "i = " << ctest2[i].x << " " << ctest2[i].y << " " << i << " " <<  entity2.x << " " << entity2.y << " " << entity2.w << " " << entity2.h << " xywh\n";
                return true;
                
            }
        }
        //if nothing intersects then it is not colliding
        return false;
    }
}

/**
 * wall collision loop for enemies
 * to call c.wallCollision(p, wall);
 * originally intended as a one method solution for player and enemy, but incompatible types
 * @param p vector of player or vector of enemy
 * @param wall vector of all wall rects
*/
void Collisions::wallCollision(const std::vector<Enemy*> & p, const std::vector<SDL_Rect> & wall) {
        //checks all enemies against all the walls
        for (int i = 0; i < wall.size(); i++) {
            for (int j = 0 ; j < p.size(); j++) {
                SDL_Rect elh = p[j]->getEhbox();
                //SDL_RenderDrawRect(mainWindow.getRenderer(), &sks);
                //no using unionrect unusual results
                //code still indev, may use this instead for enemy, and an input based soln for player
                if (detectCollisionHB(elh,wall[i])) {

                        //enemy
                        Player* pe = p[j];

                        if (p[j]->getXDir() == "left") {
                            p[j]->moveRight();     
                            p[j]->push((p[j]->getPlayerVel()+2), 0);
                            //p[i]->setPosX(p[i]->getPosX()+(p[i]->getPlayerVel()+2));
                            //p[i]->moveRight();
                            //p[i]->moveRight();
                            //std::cerr << "LLLL\n";
                        } 
                        else if (p[j]->getXDir() == "right") {
                            p[j]->moveLeft();                
                            //p[i]->moveLeft();
                            //p[i]->setPosX(p[i]->getPosX()-(p[i]->getPlayerVel()+2));
            
                            p[j]->push(-(p[j]->getPlayerVel()+2), 0);
                            //p[i]->moveLeft();
                            //std::cerr << "RRRR\n";
                        } 

                        if (p[j]->getYDir() == "up") {
                            p[j]->moveDown();   
                            p[j]->push(0,(p[j]->getPlayerVel()+2));
                            //p[i]->setPosY(p[i]->getPosX()+(p[i]->getPlayerVel()+2));
                            //p[i]->moveDown();
                            //p[i]->moveDown();
                        } 
                        else if (p[j]->getYDir() == "down") {
                            p[j]->moveUp();  
                            p[j]->push(0,-(p[j]->getPlayerVel()+2));
                            //p[i]->setPosY(p[i]->getPosX()-(p[i]->getPlayerVel()+2));
                            //p[i]->moveUp();
                            // p[i]->moveUp();
                        } 
                        
                    
                    
                    

                }
            }
        }
}

/**
 * Player Wall collisions
 * @param p player
 * @param wall all walls from game
 * @param in player input
*/
void Collisions::wallCollision(Player & p, const std::vector<SDL_Rect> & wall, Input & in) {
    SDL_Rect phb = p.getPlHbox();
    //checks all walls against player hitbox
    for (int i = 0; i < wall.size(); i++) {
        
        
        
        if(detectCollisionHB(phb,wall[i])) {
            //moves in opposite direction to prevent player from moving any further
            if(in.isKeyDown(SDL_SCANCODE_W)){
                //cerr<< "w\n";
                p.moveDown();
                //player.push(0,player.getPlayerVel());
            }
            if(in.isKeyDown(SDL_SCANCODE_S)){
                //cerr<< "s\n";
                p.moveUp();
                //player.push(0,-player.getPlayerVel());
            }
            if(in.isKeyDown(SDL_SCANCODE_A)){
                //cerr<< "a\n";
                p.moveRight();
                //player.push(player.getPlayerVel(),0);
                //cerr << player.getY() << endl;
            }
            if(in.isKeyDown(SDL_SCANCODE_D)){
                //cerr<< "d\n";
                p.moveLeft();
                //cerr << player.getY() << endl;
                //player.push(-player.getPlayerVel(),0);
                
            }
        }

    }
}