README
******
This application is a simulation of a game representing the current process of our work.

Authors: Chase Campbell, Sinthuja Jeevarajhan, Jareeullah Khan, Alan Kuang, Aidan Vannoord
REQUIRED LIBRARIES AND THIRD PARTY TOOLS
****************************************
This code requires you to have SDL2 installed, as well as other SDL2 extensions, such as SDL_image, 
BUILDING THE CODE
*****************
To begin, run the following command: g++ -o myGame main.cpp Game.cpp MainWindow.cpp Input.cpp Item.cpp Player.cpp Graphics.cpp Sword.cpp `sdl2-config --cflags --libs` -lSDL2_image
Or: Simply say "make", as there is a makefile included in creating the program.
RUNNING THE CODE
****************
To run this program: 
./myGame


USING THE APPLICATION
*********************

For right now, we have a simulation of how the player works, showcasing movement, picking up items, colliding with objects, and player boundaries.
We also have the presence of items disappearing after the player picks them up, and the logic when the player dies.

Use the WASD keys to move around.
Hold space bar to decrease health (This is just to test the health bar, and creating a gameover screen, and stopping the game).
Press E to pick up an item (This will be 	

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