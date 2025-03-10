#include "Tile.hpp"
#include "Sword.hpp"
#include "HealthPotion.hpp"
#include "Graphics.hpp"
#include <iostream>

//size of tile and thickness of wall
//keep LENGTH at 50 because a lot of game logic is tied to LENGTH
#define THICKNESS 5 //ok to change
#define LENGTH 50 //do not change
/**
 * @brief
 * Modular Tile class
 * Encompasses Wall geometry loaded from Level file, enemy spawns and item spawns. Loads one unsigned integer from the
 * level file "metadata" which encodes all the data. The unsigned int is a 16 bit unsigned int. Designed to be modular
 * and flexible for expanding, which means that there are some functions not fully utilized
 * Metadata format
 * UINT FORMAT 0 0 0 0 1 0 0 0 0 0 1 1 0 0 0 0
 *             i i i i i t t t n n n e w w w w
 * Wall Direction:                     W S E N
 * u = unassigned e = enemy spawn w = wall n = num of enemies up to 7 in 1 tile i = item on tile 5 bit numerical item ID
 * t = enemy type 3 bit Enemy ID unused due to time constraints
 * @author Alan Kuang (akuang4)
*/



/**
 * Constructor
 * @param tileInfo unsigned int "metadata" from save file
 * @param tlX tile X top left corner position
 * @param tlY tile Y top left corner position
*/
Tile::Tile(unsigned int tileInfo, int tlX, int tlY) :x(tlX), y(tlY), metadata(tileInfo), hboxes() {
   
    std::cerr << "md " << metadata << " x " << tlX <<  " y " << tlY << "\n";
    

    /**
     * Draws walls
    */
    if ((metadata & 15) == 15) {
        SDL_Rect wall = {x,y,LENGTH,LENGTH};
        hboxes.push_back(wall);
    }
    else {
        //what this bitwise operators translates to is is there a wall on that side, if there is, draw that wall`
        //evaluates to if (true/1) or if(false/0) 
        //uses AND bitwise operators
        /**
         * westwall
         * @var metadata "w" bits
         */
        if ((metadata >> 3) & 1) {
            SDL_Rect wall = {x,y,THICKNESS,LENGTH};
            hboxes.push_back(wall);
        }
        //southwall
        if ((metadata >> 2) & 1) {
            
            SDL_Rect wall = {x,(y+LENGTH)-THICKNESS,LENGTH,THICKNESS};
            hboxes.push_back(wall);
        }
        //eastwall
        if ((metadata >> 1)  & 1) {
            
            SDL_Rect wall = {(x+LENGTH)-THICKNESS,y,THICKNESS,LENGTH};
            hboxes.push_back(wall);
        }
        //northwall
        if (metadata  & 1) {
            SDL_Rect wall = {x,y,LENGTH,THICKNESS};
            hboxes.push_back(wall);
        }
        

    }

    /**
     * Draws enemy
     * @var enemyMD enemy spawn flag "e" bit
    */
    //metadata 1 bit
    unsigned int enemyMD = metadata >> 4;
    //if is an enemy spawn
    if (enemyMD & 1) isSpawn = true;
    else isSpawn = false;

    
    
    /**
     * number of enemies 3 bits decimal
     * @var numEnemies number of enemies
    */
    numEnemies = (enemyMD >> 1) & 7;

    //item ID system
    //item metadata 5 bits decimal
    unsigned int itemMD = metadata >> 11;
    itemID = itemMD & 31;

    
    
    
}


/**
 * Tile Wall draw function
 * Testing function
 * @param renderer renderer for screen
*/
void Tile::tile_draw(SDL_Renderer *renderer) {
    //rgba
    //SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);
    for (int i = 0; i < hboxes.size();i++) {
        SDL_RenderDrawRect(renderer, &hboxes[i]);
    }
}

/**
 * Wall getter
 * Gets all wall hitboxes
*/
std::vector<SDL_Rect> Tile::get_wallhb() {
    
    return hboxes;
}

/**
 * Wall setter
 * @param w unsigned 4 bit int representing desired wall configuration
*/
void Tile::set_wall(unsigned int w) {
    //clears wall bits
    metadata = metadata >> 4;
    metadata = metadata << 4;
    //ORs the Wall
    metadata |= w;
}

/**
 * Metadata getter
*/
unsigned int Tile::get_data() {
    //std::cerr << "\nmdn " << metadata << " x " << x <<  " y " << y << "\n";
    return metadata;
}

/**
 * Item metadata getter
 * 
*/
unsigned int Tile::get_item_data() {
    return itemID;
}

/**
 * Setter for metadata
 * Intended for scrapped level editor
 * @param md 16 bit unsigned integer in the specified format
*/
void Tile::set_data(unsigned int md) {
    metadata = md;
}

/**
 * Getter for tile top left corner X
*/
int Tile::getX() {
    return x;
}

/**
 * Getter for tile top left corner Y
*/
int Tile::getY() {
    return y;
}

/**
 * Getter for thickness
*/
int Tile::getThickness() {
    return THICKNESS;
}

/**
 * Getter for length
*/
int Tile::getLength() {
    return LENGTH;
}
/**
 * Enemy spawner
 * 8 enemies can spawn from a tile MAX
 * bitwise 111 (7) = 8 enemies (MAX)
 * bitwise 000 (0) = 1 enemy (MIN)
 * @param eList enemy list from game loop
 */
void Tile::spawnEnemy(std::vector<Enemy*> & eList) {
    //checks if it is a spawn tile
    if (isSpawn) {
        //spawns enemy
        for (int i = 0; i < numEnemies; i++) {
            //note -LENGTH = --LENGTH = +LENGTH
            Enemy* newSlime = new Enemy(HitBoxPos(x,-LENGTH), HitBoxPos(y,-LENGTH), 30, 1, 20, 15, 'l', false, 1000);
            
            eList.push_back(newSlime);
        }
    }
}



