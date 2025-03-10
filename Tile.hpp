/**
 * @author Alan Kuang
 * Tile class prototype
*/
#ifndef TILE_HPP
#define TILE_HPP
#include <SDL2/SDL.h>
#include <map>
#include <vector>
#include "Graphics.hpp"
#include "Player.hpp"
#include "Enemy.hpp"
#include "Inventory.hpp"

//50x50px tiles

/** Walls
 * 0000 = empty
 * 0001 = top (1)
 * 0010 = right side (2)
 * 0100 = bottom (4)
 * 1000 = left side (8)
 * 1111 = box (15)
*/

struct TileData {
    unsigned int wall;
};


class Tile {
    public:
    /**
     * @param tilePtr pointer to tile object
     * void pointer because unsure what structure we want to pass thru
     * @param tlX top left X
     * @param tlY top left Y
     * because sdl draws from TL, and we don't want centered behaviour in thiss
    */
    //Tile(); //default constructor
    //Tile (int tlX, int tlY); //testing constructor
    Tile(unsigned int tileInfo, int tlX, int tlY); //constructor

    /** 
     * wall controls
     * Setters and getters for wall value
     * @param w bitwise representation of wall
    */
    void set_wall(unsigned int w);




    /**
     * getter for metadata
    */
    unsigned int get_data();

    /**
     * gets item metadata
    */
    unsigned int get_item_data();

    /**
     * setter for metadata
     * for Level Editor
     * @param md metadata
    */
    void set_data(unsigned int md);

    int getX();
    int getY();

    int getThickness();

    int getLength();

    std::vector<SDL_Rect> get_wallhb();

    
    void tile_draw(SDL_Renderer *renderer);

    /**
     * Spawns enemy into enemies container
    */
    void spawnEnemy(std::vector<Enemy*> & eList);


    private:
    unsigned int metadata = 0; //bitwise implemenation of data
    unsigned int numEnemies = 0; //num of enemies
    unsigned int itemID = 0; //what item is on this tile

    
    bool isSpawn; //flag for enemy spawn
    int x, y, spawnNum; //xpos ypos and number of enemies to spawn
    std::vector<SDL_Rect> hboxes; //hitboxes "SDL_Rect walls"
   


};

#endif