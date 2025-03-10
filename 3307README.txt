README
******
This application is a simulation of a game representing the current process of our work.

Authors: Chase Campbell, Sinthuja Jeevarajhan, Jareeullah Khan, Alan Kuang, Aidan Vannoord
REQUIRED LIBRARIES AND THIRD PARTY TOOLS
****************************************
This code requires you to have SDL2 installed, as well as other SDL2 extensions, such as SDL_image, 
BUILDING THE CODE
*****************
To begin, run the following command: g++ -o myGame main.cpp Game.cpp MainWindow.cpp Input.cpp Tile.cpp Item.cpp Player.cpp Graphics.cpp Sword.cpp Enemy.cpp Collisions.cpp Inventory.cpp HealthPotion.cpp `sdl2-config --cflags --libs` -lSDL2_image -lSDL2
Or: Simply say "make", as there is a makefile included in creating the program.
RUNNING THE CODE
****************
To run this program: 
./myGame

HOW TO PLAY
*********************
- When you run the program you will be confronted with a title screen, press the enter key to play as displayed.

- You will then be able to move the player around the map using arrow keys, on the top you will notice two bars, one representing health, and the other representing shield.

- You will see a sword placed in the first room, walk over it and press 'e' to add it to your inventory, press 'q' to view inventory, then press '1' (as displayed) to equip
the sword item. Press 'q' again to leave the inventory menu.

- You can then enter other rooms to find items like the shield which will fill your shield bar and make damage taken prioritize the shield until it is drained.

-You will also find health potions which will restore health if you are below 100 health, it will restore a specific amount of health and if you're health is full,
you won't be able to pick it up, and if 100-current health is less than the potions healing amount, it will just restore you to 100, so you cannot go over.

- Enemies will generate in certain rooms which will chase the player, if the player losses all health, the player dies and the game over screen will generate,
you can press 'r' to restart the game from this screen. 

- Assuming you have the sword equipped, the player is able to press the space bar to attack the enemies, be careful, because the player will likely take damage being so close
try not to have too much health drained.

- If the player manages to kill all the enemies that are generated, the win condition is triggered and the game will be complete, you can press 'r' from here to restart as well.

- Mouse-click the X button on the top of the window at any time to quit. 

- Press 'p' while playing to pause the game and press it again to unpause. 
	

NOTE: There is a bug at times after you edit your level, or select make where the enemies will not take damage,
to fix this, simply terminate the program a few times until you see the enemy die when you attack it with a sword.

HIERARCHY OF BRANCHES
*********************

master
|
development
|
dev_branch


LEGACY
*********************

 
Version Control Information
Branches function:
The master branch is for known good code. No memory leaks, crashes, and no obvious bugs. It is there for redundancy, in case we hit a brick wall so that we don’t have to spend time backtracking through versions. 
Merging practices for master (stable):
Only merge development branch with the master branch.

The development branch is where all the code is aggregated.. You fetch from the development branch when you are developing the parts of the code to get latest parts. 
Merging practices for development:
You merge the dev_branch with the development branches after dev_branch ideally when it is bug-free and hits a functional milestone for a bigger class, i.e. completed a method update() in the class Game. Or is functionally complete with smaller classes i.e. finish Input class then merge.

The dev_branch is where specific class(es) are being developed, subbranches of the development branch, there are 5 branches dev_Audio_Visual, dev_Env_Logic, dev_Player_Logic, dev_Map, and dev_Game. 
Categories:
dev_Audio_Visual: Sound and Graphics classes.
dev_Game: Game class, Config Class, and MainWindow class.
dev_Env_Logic: Enemy Class, Item Class and any other enemy or map logic classes.
dev_Player_Logic: Player class, Input Class, and anything regarding the player.
dev_Map: Map class.

Best practices is to avoid merging excessively, you do not want to risk in development code in the development branch wreaking havoc when other people are developing and testing. 
Ideally only merge with at least one other person watching. I.e. not at 4am when everyone is asleep.
Ideally use fetch request to get the latest from the development branch onto the dev_branch.
To avoid merge conflicts I have structured the subbranches dev_branch for specific features and classes


CURRENT: Version Control Information
Refer to legacy for context, master branch is stable and development branch is for in development code, the dev_branches are static subbranches for experimentations i.e. if we hit a dead end.
Remember to merge dev_branches when testing out new features