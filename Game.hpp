#ifndef GAME_HPP
#define GAME_HPP

#include "MainWindow.hpp"
#include "Input.hpp"
#include "Player.hpp"
#include "Graphics.hpp"
#include "Inventory.hpp"
#include "HealthPotion.hpp"
#include "Enemy.hpp"
#include "Tile.hpp"

#include <thread>
#include <chrono>
#include <queue>
//#include "Sword.hpp"
// Include other necessary headers

/**
 * Game loop header file
*/

/**
 * Game loop class prototype
*/
class Game {
public:
    /**
     * Constructor prototype
    */
    Game();

    /**
     * Destructor prototype
    */
    ~Game();

    //functions
    void titleScreen();
    /**
     * Game loop runner prototype
    */
    void run();

    void addEnemy(Enemy* enemy);

    void wallPush(SDL_Rect player, std::vector<SDL_Rect> walls);

    void loadLevel(std::string fn);

    void drawItem(unsigned int metadata, int x, int y) ;

    bool isEnemyDead() ;

    

    /**
     * Death screen prototype
    */
    void lossScreen();  
    void victoryScreen();
    void enemyHandler();
    //int getPly();
    //int getPlx();
private:
    MainWindow mainWindow;
    Input input;
    Player player;
    Enemy enemy = Enemy(200, 500, 30, 1, 10, 10, 'l', false, 1000);
    int swordDamage;
    //Sword seiba; 
    Graphics* graphics;
    void checkInput(bool itemInt);
    bool isRunning = true;
    bool itemInt = false;
    Inventory *mapInventory;
    Inventory *playerInventory;
    Item *target;   //targettted by player
    void resetGame();
    bool toggleInventory;
    bool toggleOn;
    bool toggleCurr;
    bool enemySpawn;
    std::vector<Enemy*> enemies;
    const std::vector<Player*> playerVector; //allows for code reuse for wall collisions and prevents more than 1 player in vector
    int equippedItem;
    bool pauseOn;
    bool togglePause;
    bool levelCleared;

    //level flag
    bool levelLoaded;

    
    
    //array for grid
    //Tile tileGrid[rows][cols];
    std::vector<std::vector<Tile*>> tileGridV;
    std::vector<SDL_Rect> currentWalls;
    //std::queue<std::string> levelQueue;

    //vector containing all levels
    std::queue<std::string> levelList;

};

#endif
