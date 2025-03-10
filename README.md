Action RPG in C++
This 2D adventure RPG, inspired by The Legend of Zelda, is built entirely in C, focusing on efficient game mechanics, dynamic interactions, and strategic combat. Players take control of Jerry, navigating through diverse environments, battling AI-driven enemies, and collecting items to progress.

Key Features:
- Developed in C++ for optimized performance, memory management, and real-time processing.
- Sprite-based rendering system to create visually engaging environments.
- Real-time movement and combat mechanics, with smooth keyboard input handling.
- AI-driven enemies that spawn dynamically, adapting to different difficulty levels.
- Interactive gameplay elements, such as item pickups (swords, keys) to aid progression.
- Robust user interface, including start, victory, and death screens for tracking progress.
Future Enhancements:
- Additional levels and expanded maps for greater exploration.
- More items, including health potions and keys, to enhance gameplay mechanics.
- A health system and life counter to provide real-time player status.
- By leveraging C++’s low-level control and efficiency, this game delivers a fast and immersive experience while showcasing structured programming, memory management, and algorithmic design. 🚀🎮


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
