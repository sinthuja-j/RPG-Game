
#include "Game.hpp"
#include <vector>
#include "Sword.hpp"
#include "Collisions.hpp"
#include "Definitions.hpp"
//#include "Tile.hpp"
#include <fstream>
#include <sstream>

const int FPS = 60;
const int frameDelay = 1000 / FPS;
int screenWidth = 800;
int screenHeight = 600;
Uint32 frameStart;
int frameTime;
const int healAmount = 30;
const int shieldAmount = 50;

/**
 * Game class: handles all game logic
*/



/**
 * Constructor
 * @param screen height and width
 * loads up sprites into graphics and links renderer with mainwindow
 * @var playerVector to point to player allowing for wall collision reuse
 * @var levelList list of levels once you hit a level change tile
*/
Game::Game() : mainWindow(screenWidth, screenHeight) , playerVector({&player})  { //window initialization with desired size
    IMG_Init(IMG_INIT_PNG);
    SDL_Renderer* renderer = mainWindow.getRenderer();
    graphics = new Graphics(renderer);
    graphics->loadSprite("objects", "RPG_Items_Free/objects.png");
    graphics->loadSprite("overworld", "Overworld.png");
    graphics->loadSprite("character", "character.png");
    graphics ->loadSprite("moreObjects", "moreObjects.png");
    graphics->loadSprite("inventory", "RPG_Items_Free/Inventory.png");
    graphics->loadSprite("enemyIdle", "Idle/blue.png");
    graphics ->loadSprite("blueDeath", "blueDeath.png");
    graphics->loadSprite("pause", "RPG_Items_Free/Pause.png");
    graphics->loadSprite("highlight", "RPG_Items_Free/Highlight.png");
    //initializes level clear flag
    levelCleared = false;
    //initializes grid vector
    tileGridV.resize(16,std::vector<Tile*>(12)); 
    //has loaded level flag
    levelLoaded = false;
    //has spawned flag
    enemySpawn = false;
    //initializes current walls vector
    currentWalls = std::vector<SDL_Rect>();
    //list of level names vector
    //levelList({"level_1.lvl", "level_2.lvl", "level_3.lvl", "level_4.lvl"});
    //levelList.push("level_1.lvl");
    //levelList.push("level_2.lvl");
    //levelList.push("level_3.lvl");
    //levelList.push("level_4.lvl");
    
}


/**
 * @author Alan 
 * Level Loader
 * @brief
 * Loads level files with unsigned int metadata, and initializes the grid of Tiles that have wall geometry and enemy spawns
 * @param fn Filename
 * .lvl file inspired by .ply
*/
void Game::loadLevel(std::string fn) {
    //clears current walls
    if (!currentWalls.empty()) {
        currentWalls.clear();
    }
    //clears current enemies
    if (!enemies.empty()) {
        enemies.clear();
    }
    //resets enemy cleared flag
    levelCleared = false;

    //clears map of items
    mapInventory->clearInventory();

    //file load flag
    bool start = false;

    //
    enemySpawn = false;
    unsigned int posx = 0, posy = 0, row = 0, col = 0, read = 0;
    int maxx = 16, maxy = 12;
    std::string line;
    

    //reads level file
    std::ifstream lvlStream(fn, std::ios::in);
    
    //reads file ignoring file comments
    if (lvlStream.is_open()) {
        
        while (lvlStream) {
            std::getline(lvlStream, line);
            std::stringstream ss(line);
            
            //starts reading file after begin header
            if (line == "--BEGIN--\n" || line == "--BEGIN--") {
				start = true;
                std::getline(lvlStream, line);
			}
            //end of level file
            else if (line == "--END--\n" || line == "--END--") {
                start = false;
            }
            

            //checks if level data
            if (start) {
                for (int i = 0; i < maxx; i++) {
                        //gets line from level file
                        ss >> read;
                        //debug print
                        //std:: cerr <<  "cc: " << i << " " << row << " read:" << read  <<  "\n";
                        //std:: cerr <<  "c50: " << i << " r " << row << " read:" << read  <<  "\n";

                        //initializes tile
                        tileGridV[i][row] = new Tile(read,(i*50),(row*50));
                        std:: cerr <<  "math: i50: " << i*50<< " r50 " << row*50 << " read:" << read  <<  "\n";
                        //tileGrid[i][row].tile_load(read,col*50,row*50);

                        

                        Tile k = *tileGridV[i][row];

                        //gets wall hitbox
                        std::vector<SDL_Rect> w = k.get_wallhb();

                        //pushes wall hitbox into current level walls
                        for (int vv = 0; vv < w.size(); vv++) {
                            currentWalls.push_back(w[vv]);
                        }

                        //spawns enemies on map
                        tileGridV[i][row]->spawnEnemy(enemies);

                        //tileGridV[i][row]->spawnItem(mapInventory, graphics);
                        unsigned int itemMetaData = tileGridV[i][row]->get_item_data();
                        if (itemMetaData > 0) drawItem(itemMetaData, tileGridV[i][row]->getX()+10,tileGridV[i][row]->getY()+10);

                        //mapInventory->drawItems();

                        std::cerr << "freebird" << static_cast <int> (tileGridV[i][row]->getX()) << "b\n";

                        //tileGridV[i][row]->tile_draw(mainWindow.getRenderer());
                        
                        //col++;
                        
                    
                }
                row++;
            }

            

            

        }
    }
    else {
        std::cerr << "Error: " << fn << "Level File not found\n";
        std::cerr << "Developers: NOTE No level geometry and spawns due to missing file.\n";
        
    }
}


/**
 * Doxygen comments for run()
 * @brief
 * Main game loop, handles all game logic
 * @author Aidan
 * @author Jaree
 * @author Chase
 * 
 * 
 * 
*/
void Game::run(){
    mapInventory = new Inventory(false);
    int count = 0;
    playerInventory = new Inventory(true);
    toggleInventory = false;
    toggleOn = false;
    toggleCurr = false;
    equippedItem = 0;
    pauseOn = false;
    togglePause = false;

    
    int playerCount = 0;
    //addEnemy(&enemy);
    while(isRunning){
    
        //enemyHandler();
        frameStart = SDL_GetTicks();
        input.update();
        SDL_Event event;
        while(SDL_PollEvent(&event)){ //user exits
        if(event.type == SDL_QUIT){
            isRunning = false;
        }
        

        }

        if(player.getHealth() <= 0){
            lossScreen(); // Call your LossScreen function here
            break; // Exit the game loop
        }
    checkInput(itemInt);

    //pauseToggle ***MAKE SURE IT STAYS HERE AS IT DOESNT RUN OUTSIDE OF HERE***
    if (togglePause) {
        std::cout << "paused " << toggleOn << endl;

        if (!playerCount) {
            SDL_Rect background = {0,0,600,400};
            graphics->renderSprite("pause", 100, 100, background);
            graphics->update();
            playerCount++;
        }
        continue;
    }
    if (playerCount) {
        playerCount--;
    }

    graphics->clear();
    enemyHandler();
    //victoryScreen();

        SDL_Rect* pl, * env;
        SDL_Rect grassRec = {0,0,10,10};
        for(int i =0; i <=screenWidth;i+=10){
            for(int j=20; j<= screenHeight; j+=10){ //j set to 20 to have black bar on top for UI stuff
            graphics->renderSprite("overworld",i,j, grassRec);
            }
        }
        // SDL_Rect waterRec = {0,20,10,10};
        // for(int i =0; i <=20;i+=10){
        //     for(int j=20; j<= screenHeight; j+=10){ //j set to 20 to have black bar on top for UI stuff
        //     graphics->renderSprite("overworld",i,j, waterRec);
        //     }
        // }

        // for(int i =20; i <=screenWidth;i+=10){
        //     for(int j=screenHeight -20; j<= screenHeight; j+=10){ //j set to 20 to have black bar on top for UI stuff
        //     graphics->renderSprite("overworld",i,j, waterRec);
        //     }
        // }



        //Front: 0,0,16,32
        //Right: 0,32,16,32
        //Back: 0,64,16,32
        //Left: 0,96,16,32
        
        SDL_Rect charRecFront = {0,64,16,32};
        SDL_Rect charRecRight = {0,32,16,32};
        SDL_Rect charRecBack = {0,0,16,32};
        SDL_Rect charRecLeft = {0,96,16,32};
        SDL_Rect charRecFrontAttack = {104,160,16,32};
        SDL_Rect charRecBackAttack = {104,128,16,32};
        SDL_Rect charRecRightAttack = {104,192,16,32};
        SDL_Rect charRecLeftAttack = {104,224,16,32};
        SDL_Rect enemyRect = {28,0, 50, 32};
        SDL_Rect enemyBlueDeath = {500,0, 50, 32};
        std::string direction = player.getDirection();
        if (direction == "up") {
            if (player.getAnimation() == "idle") {
                graphics->renderSprite("character",player.getDrawX(),player.getDrawY(),charRecFront);
            }else if (player.getAnimation() == "attack") {
                graphics->renderSprite("character",player.getDrawX(), player.getDrawY(), charRecFrontAttack);
            }
        }
        else if (direction == "down") {
            if (player.getAnimation() == "idle") {
                graphics->renderSprite("character",player.getDrawX(),player.getDrawY(),charRecBack);
            } else if (player.getAnimation() == "attack") {
                graphics->renderSprite("character",player.getDrawX(), player.getDrawY(), charRecBackAttack);
            }
        }
        else if (direction == "left") {
            if (player.getAnimation() == "idle") {
                graphics->renderSprite("character",player.getDrawX(),player.getDrawY(),charRecLeft);
            } else if  (player.getAnimation() == "attack") {
                graphics->renderSprite("character",player.getDrawX(), player.getDrawY(), charRecLeftAttack);
            }
            
        }
        else if (direction == "right") {
            if (player.getAnimation() == "idle") {    if (togglePause) {
        if (!input.isKeyDown(SDL_SCANCODE_P)) {
            pauseOn = false;
        }
    }
                graphics->renderSprite("character",player.getDrawX(),player.getDrawY(),charRecRight);
            } else if  (player.getAnimation() == "attack") {
                graphics->renderSprite("character",player.getDrawX(), player.getDrawY(), charRecRightAttack);
            }
        }

        
        

    // Set the draw color to blue for the player hitbox
        SDL_SetRenderDrawColor(mainWindow.getRenderer(), 0, 0, 255, 255);

    // Gets player hitbox
        SDL_Rect playerRect = player.getPlHbox();
        //SDL_RenderDrawRect(mainWindow.getRenderer(), &playerRect);

    // Set the draw color back to white
        //SDL_SetRenderDrawColor(mainWindow.getRenderer(), 255, 255, 255, 255);

        //creates collision class
        Collisions c;
        //-- Tile Test --
        
        //loads first level
        if (!levelLoaded) {
            //loadLevel("level_testing.lvl");
            levelLoaded = true;
            levelCleared = false;

            //resets level stack
            levelList.push("level_1.lvl");
            levelList.push("level_2.lvl");
            levelList.push("level_3.lvl");
            levelList.push("level_4.lvl");


            std::string nextLvl = levelList.front();
            levelList.pop();
            loadLevel(nextLvl);
        }

        //test draw
        //-- Draw Walls
        if (levelLoaded){
            for (int i = 0 ;i < tileGridV.size(); i++) {
                for (int j = 0 ;j < 12; j++) {
                    //std::cerr << i <<  " " << j << "\n";
                    //if (tileGridV[i][j]->get_wallhb().size() < 0) {
                    std::vector<SDL_Rect> box = tileGridV[i][j]->get_wallhb();
                    tileGridV[i][j]->tile_draw(mainWindow.getRenderer());

                    for (const auto& rect : box) {
                        SDL_SetRenderDrawColor(mainWindow.getRenderer(), 128, 128, 128, 255);
                SDL_RenderFillRect(mainWindow.getRenderer(), &rect);
            }



                    //tileGridV[i][j]->spawnEnemy(enemies);
                    //if (!box.empty()) {
                    //    for (int k = 0; k < box.size(); k++) {
                    //        SDL_RenderDrawRect(mainWindow.getRenderer(), &box[k]);
                    //    }
                    //} 
                    

                    //}
                    //for (int k = 0; k < box.size();k++) {
                    //    SDL_RenderDrawRect(mainWindow.getRenderer(), &box[i]);
                    //}
                }
            }

            
        }
        SDL_SetRenderDrawColor(mainWindow.getRenderer(), 0, 0, 0, 255); // Black
                SDL_Rect topBarRect = {0, 0, screenWidth, 20}; 
                SDL_RenderFillRect(mainWindow.getRenderer(), &topBarRect);

                SDL_Rect healthOutline = {25,0,100,20};
        SDL_SetRenderDrawColor(mainWindow.getRenderer(), 255, 0, 0, 255);
        SDL_RenderDrawRect(mainWindow.getRenderer(), &healthOutline);
        SDL_Rect healthFill = {25,0,player.getHealth(),20};
        SDL_SetRenderDrawColor(mainWindow.getRenderer(), 255, 0, 0, 255);
        SDL_RenderFillRect(mainWindow.getRenderer(), &healthFill);
        SDL_SetRenderDrawColor(mainWindow.getRenderer(), 0, 0, 0, 255);
        SDL_Rect heart = {60,0,20,20};

        SDL_Rect shieldOutline = {155,0,50,20};
        SDL_SetRenderDrawColor(mainWindow.getRenderer(), 0, 191, 255, 255);
        SDL_RenderDrawRect(mainWindow.getRenderer(), &shieldOutline);
        SDL_Rect shieldFill = {155,0,player.getShield(),20};
        SDL_SetRenderDrawColor(mainWindow.getRenderer(), 0, 191, 255, 255);
        SDL_RenderFillRect(mainWindow.getRenderer(), &shieldFill);
        SDL_SetRenderDrawColor(mainWindow.getRenderer(), 0, 0, 0, 255);
        SDL_Rect shield = {20,0,30,20};
        SDL_SetRenderDrawColor(mainWindow.getRenderer(), 255, 0, 0, 255);
        //check rectangles and print
        //primitive wall collision
        for (int kk = 0; kk < currentWalls.size(); kk++) {
                //std::cerr << "rect " << kk << " h: " << currentWalls[kk].h << " w: " << currentWalls[kk].w << " x: " << currentWalls[kk].x << " y: " << currentWalls[kk].y << "\n";
                //SDL_RenderDrawRect(mainWindow.getRenderer(), &currentWalls[kk]);

                //c.wallCollision(playerVector, currentWalls);
                c.wallCollision(enemies,currentWalls);
                c.wallCollision(player,currentWalls,input);
                

            }

        //-- End --

        int px, py;
        px = player.getX();
        py = player.getY();
        
        mapInventory->drawItems();
        //collisions require hitboxes
        frameTime = SDL_GetTicks() - frameStart;
        if(frameTime < frameDelay){
            SDL_Delay(frameDelay - frameTime);
        }

        //player rectangle
        SDL_Rect tempRect = player.getPlHbox();


        

        //player.sizePlHbox(200,200);
        //SDL_Rect tempRect2 = player.getPlHbox();s
        //moved down to account for
        graphics->renderSprite("moreObjects",0,0,heart);
        graphics->renderSprite("objects",120,0,shield);

        
        if (!enemySpawn) {
            tileGridV[5][5]->spawnEnemy(enemies);
            enemySpawn = true;
        }

        /**
         * Enemy Draw
        */
        for (int ee = 0; ee < enemies.size(); ee++) {
             //std::cerr << "dx: " << enemies[ee]->getDrawX() << " dy " << enemies[ee]->getDrawY() << "\n";
             Enemy * en = enemies[ee];
            SDL_Rect ehb = en->getEhbox();
            //std::cerr << "ehx: " << ehb.x << " dy " << ehb.y << " dw " << ehb.w << " dh " << ehb.h << "\n";
            if(en->getHealth()>0){
                //-12 -3 centers this on this only
                graphics->renderSprite("enemyIdle", en->getDrawX()-12, en->getDrawY()-3, enemyRect);
                //SDL_RenderDrawRect(mainWindow.getRenderer(), &ehb); //debug draws enemy hitbox
            }else if (en->getHealth() <= 0){
                if (!en->isDead()) {
                    en->onDeath(true); 
                    }
                //enemy.onDeath(true);
                en->setDamage(0);
                if(SDL_GetTicks() - en->getDeathTime() < 1000) {
                graphics->renderSprite("blueDeath", en->getDrawX(), en->getDrawY(), enemyBlueDeath);
                //delete enemy somehow
                levelCleared = isEnemyDead();
                
                
            }
            }
            if(en->isDead() == false){
                en->move(player);
            }
            else if (en->isDead()) {
                
            }

        }
        

                
        if (toggleInventory) {
            playerInventory->displayInventory(graphics,equippedItem);    //draw inventory over everything
        }
        if (!input.isKeyDown(SDL_SCANCODE_Q)) toggleOn = false;

        graphics->update();

        target = mapInventory->checkCollision(tempRect);
        
       
        //checks for victory conditions of empty level queue and level cleared
        if (levelList.empty() && levelCleared) {
            victoryScreen();
        }

    }   
}

/**
 * Enemy Handler
 * @brief
 * Handles enemy collision with player, and player attack
 * @author Aidan
 * @author Jaree
 * @author Chase
 * 
*/
void Game::enemyHandler() {
    if (enemies.size() == 0) levelCleared = true;
    Collisions c;
    for (auto it = enemies.begin();it != enemies.end();++it) {
        if (c.detectCollisionHB((*it)->getEhbox(), player.getPlHbox())) {
            if (!(*it)->isDead()) {
                if (player.getShield() > 0) {
                    player.setShield(player.getShield()>=10 ? player.getShield()-(*it)->getDamage():0);
                } else {
                    player.setHealth(player.getHealth()-(*it)->getDamage());
                }
                if (player.getAnimation() == "attack") {
                // If so, reduce the enemy's health by the player's attack damage
                int newHealth = (*it)->getHealth() - swordDamage;
                (*it)->setHealth(newHealth);
                }
                
                std::cout << "enemy attacked" << endl;
            }
        }
    }
}

/**
 * Checks input of user and handles it
 * @param itemInt for testing of collision
*/
void Game::checkInput(bool itemInt){
    if (input.isKeyDown(SDL_SCANCODE_P)) {
        std::cout << "pressed p " << toggleOn << endl;
        if (!pauseOn) { 
            togglePause = !togglePause;
            pauseOn = true;
        }
    }
    if (!input.isKeyDown(SDL_SCANCODE_P)) {
        pauseOn = false;
    }
    if (togglePause) {
        return;
    }
    if(input.isKeyDown(SDL_SCANCODE_W)){
        player.moveUp();
        player.setDirection("up");
        cout << player.getDirection() << endl;
         if(player.getY() <= 20){
            //player.setY(screenHeight - 28); //hacky way
            player.push(0,(player.getPlayerVel())); //pushes at player speed TODO: outboard this to the tile func or wall stuff
        }
    }
     if(input.isKeyDown(SDL_SCANCODE_A)){
        player.moveLeft();
        player.setDirection("left");
        cout << player.getDirection() << endl;
        if(player.getX() <= 0){
            //player.setX(40); old
            player.push((player.getPlayerVel()),0);
        }
    }
     if(input.isKeyDown(SDL_SCANCODE_S)){
        player.moveDown();
        player.setDirection("down");
        cout << player.getDirection() << endl;
         if(player.getY() >= screenHeight){
            //player.setY(screenHeight - 50); //was 50
            player.push(0,-(player.getPlayerVel())); //pushes at player speed TODO: outboard this to the tile func or wall stuff
        }
    }
    if(input.isKeyDown(SDL_SCANCODE_D)){
        player.moveRight();
        player.setDirection("right");
        cout << player.getDirection() << endl;
        //level transition right side
        if(player.getX() >= screenWidth){
            //level cleared, move to next room
            if (levelList.size() > 0 && levelCleared) {
                player.setX(0 + 16);
                std::string nextLvl = levelList.front();
                levelList.pop();
                loadLevel(nextLvl);
            }
            //locks player in map if enemies are still around or if map queue is empty for final room
            //right wall solid
            else {
                if(player.getX() >= screenWidth){
                    //player.setX(40); old
                    player.push(-(player.getPlayerVel()),0);
                }
            }
        }
    }
    //This is just for testing purposes, testing the health bar
    /*
    if (input.isKeyDown(SDL_SCANCODE_L)) {
        player.setHealth(player.getHealth() - 1);
    }*/

    //pick up item
    if (input.isKeyDown(SDL_SCANCODE_E)) {
        if (target != nullptr) {    //move item from map to player inventory
            if (playerInventory->getItems().empty() && !(target->getItemName() == "healthPotion")) {
                player.equipItem(target);
                equippedItem = 1;
            }
            if (target->getItemName() == "sword") {
                playerInventory->addItem(mapInventory->removeItem(target));
            } else if (target->getItemName() == "healthPotion") {
                if((player.getHealth()+ 30) < 100) {
                    player.setHealth(player.getHealth() + healAmount);
                    mapInventory->removeItem(target);
                }
                else if (player.getHealth() < 100) {
                    player.setHealth(player.getHealth() + (100 - player.getHealth()));
                    mapInventory->removeItem(target);
                }
                
                
            }else if (target->getItemName() == "shield") {
                player.setShield(player.getShield() + shieldAmount);
                mapInventory->removeItem(target);
        }
    }
    }
    //Use healing item to heal player
    
    //drop item
    if (input.isKeyDown(SDL_SCANCODE_X)) {
        //playerInventory->removeItem(player.equip())
    }

    //while inventory is open, allow user to select between items
    if (toggleInventory) {
    if (input.isKeyDown(SDL_SCANCODE_1) && playerInventory->getItems().size() > 0){
            //player.equip(item1)
            player.equipItem(playerInventory->getItems().at(0));
            equippedItem = 1;
            cout << player.getActiveItem() << endl;
        }
        if (input.isKeyDown(SDL_SCANCODE_2) && playerInventory->getItems().size() > 1) {
            //player.equip(item2)
            player.equipItem(playerInventory->getItems().at(1));
            equippedItem = 2;
            cout << player.getActiveItem() << endl;
        }
        if (input.isKeyDown(SDL_SCANCODE_3) && playerInventory->getItems().size() > 2) {
            //player.equip(item3)
            player.equipItem(playerInventory->getItems().at(2));
            equippedItem = 3;
            cout << player.getActiveItem() << endl;
        }
        if (input.isKeyDown(SDL_SCANCODE_4) && playerInventory->getItems().size() > 3) {
            //player.equip(item4)
            player.equipItem(playerInventory->getItems().at(3));
            equippedItem = 4;
            cout << player.getActiveItem() << endl;
        }
        if (input.isKeyDown(SDL_SCANCODE_5) && playerInventory->getItems().size() > 4) {
            //player.equip(item5)
            player.equipItem(playerInventory->getItems().at(4));
            equippedItem = 5;
            cout << player.getActiveItem() << endl;
        }
    }

    //Display the items in your inventory
    if (toggleCurr = input.isKeyDown(SDL_SCANCODE_Q)) {
        //Show items in inventory
        if (toggleCurr & !toggleOn) toggleInventory = !toggleInventory;
        toggleOn = toggleCurr;
    }


    // Player attacks
    if (input.isKeyDown(SDL_SCANCODE_SPACE)) {
        if (player.getActiveItem() == "sword") {
            player.attack();
        }
        cout << player.getAnimation() << endl;
        cout << "Test" << endl;
    }
    if (!input.isKeyDown(SDL_SCANCODE_SPACE)){
        player.setAnimation("idle");
    }



}
/**
 * The first method called from main, creates the starting screen before the player clicks enter
 * @author Chase
*/
void Game::titleScreen(){
    SDL_Renderer* renderer = mainWindow.getRenderer();
    if(!renderer){
        std::cerr << "error rendering titleScreen" << std::endl;
        return;
    }
    SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
    SDL_RenderClear(renderer);
    graphics-> loadSprite("title", "titleScreen.png"); //loads png of a title screen
    SDL_Rect titleRec = {0, 0, 800, 600}; //rect created the size of desired part of png to render
    graphics->renderSprite("title", 0, 0, titleRec); //renders a titleRec sized part of the titleScreen.png at desired part of window
    SDL_RenderPresent(renderer);
    input.update();
    bool needInput = true;
    SDL_Event event;

    while (needInput) {
        while (SDL_PollEvent(&event)) {
            //player quits via X on top of window
            if (event.type == SDL_QUIT) {
                needInput = false;
                isRunning = false;
                
            }
            //if player presses the main enter button, run() method is called so the main game begins
            if (input.isKeyDown(SDL_SCANCODE_RETURN)) {
                needInput = false;
                run();
            }
        }
    }
}

/**
 * @brief Draws an item on the map
 * @author Jaree
*/
void Game::drawItem(unsigned int metadata, int x, int y) {

    //Item item;
       
    if (metadata == 1) {
        Sword * item = new Sword("sword", "test", x, y, false, 30, 30, 10, 10, graphics);
        mapInventory->addItem(item);

    } else if (metadata == 2) {
        Item * item = new Item("shield", "test", x, y, false, 30, 30, graphics);
        mapInventory->addItem(item);


    } else if (metadata == 3) {
        HealthPotion * item = new HealthPotion("healthPotion", "test", x, y, true,30,30,20, graphics); //healthPotion creation
        mapInventory->addItem(item);
    }
    
    //mapInventory->addItem(&item);
    // mapInventory->drawItems();  //may not need
}
/**
 * @brief called when player dies, displays loss screen
 * @authors Chase, Aidan
*/
void Game::lossScreen() {
    SDL_Renderer* renderer = mainWindow.getRenderer();
    if(!renderer){
        std::cerr << "error rendering lossScreen" << std::endl;
        return;
    }
    SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
    SDL_RenderClear(renderer);
    graphics-> loadSprite("youDied", "youDied.jpg"); //loads jpg of a loss screen
    SDL_Rect youDiedRec = {350, 300, 560, 175}; //rect created the size of desired part of png to render
    graphics->renderSprite("youDied", 100, 50, youDiedRec); //renders a youDiedRec sized part of the youDied.jpg at desired part of window
    SDL_RenderPresent(renderer);
    bool needInput = true;
    SDL_Event event;

    while (needInput) {
        while (SDL_PollEvent(&event)) {
            //player quits via x button on window
            if (event.type == SDL_QUIT) {
                needInput = false;
                isRunning = false;
                
            }
            if (input.isKeyDown(SDL_SCANCODE_R)) {
                needInput = false;
                resetGame(); //player restarts game
            }
        }
    }
    run();
}

/**
 * @brief victoryScreen() is called when win condition is met
 * @author Chase
*/
void Game::victoryScreen() {
    SDL_Renderer* renderer = mainWindow.getRenderer();
    if(!renderer){
        std::cerr << "error rendering VictoryScreen" << std::endl;
        return;
    }
    SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
    SDL_RenderClear(renderer);
    graphics-> loadSprite("victory", "victory.png"); //loads png of a victory screen
    SDL_Rect victoryRec = {0, -75, 450, 250}; //rect created the size of desired part of png to render
    graphics->renderSprite("victory", 150, 50, victoryRec); //renders a victoryRec sized part of the victory.png at desired part of window
    cout << "You has slain the foul creatures as the legends foretold!\nThe world has been saved because of your bravery!\nYour actions will be recounted through the ages!" << endl;
    SDL_RenderPresent(renderer);
    bool needInput = true; //used to get player to quit or restart
    SDL_Event event;

    while (needInput) {
        while (SDL_PollEvent(&event)) {
            //player quits via x button on window
            if (event.type == SDL_QUIT) {
                needInput = false;
                isRunning = false;
                
            }
            if (input.isKeyDown(SDL_SCANCODE_R)) {
                needInput = false;
                resetGame(); //player restarts game
            }
        }
    }
    run();
}
/**
 * @brief resetGame() is called when the player chooses to reset the game
 * @author Aidan
 */
void Game::resetGame() {
    //allows game loop to reload in game loop starting sequence
    levelCleared = false;
    
    //resets player values
    player.setX(400);
    player.setY(400);
    player.updPlHbox();
    isRunning = true;
    player.setDirection("down");
    player.setHealth(100);
    player.clearItem();

    //clears level list
    while (!levelList.empty()) levelList.pop();
    


    //tells game to use the load level on game loop
    //prevents nasty bug of items not spawning on respawn
    levelLoaded = false; 

}


/**
* @brief addEnemy() adds an enemy to the game
*/
void Game::addEnemy(Enemy* enemy) {
    enemies.push_back(enemy);
}


/**
 * @brief isEnemyDead() checks if all enemies are dead
*/

bool Game::isEnemyDead() {
    for (int i = 0; i <enemies.size(); i++) {
        //if health is 0 == false else true
        if (enemies[i]->getHealth() > 0) return false;
        
    }
    return true;
}


//Deconstructor
Game::~Game(){
    delete graphics;
    IMG_Quit();
}