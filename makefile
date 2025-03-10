myGame: *.cpp
	g++ -o myGame main.cpp Game.cpp MainWindow.cpp Input.cpp Tile.cpp Item.cpp Player.cpp Graphics.cpp Sword.cpp Enemy.cpp Collisions.cpp Inventory.cpp HealthPotion.cpp `sdl2-config --cflags --libs` -lSDL2_image -lSDL2

clean:
	rm myGame
