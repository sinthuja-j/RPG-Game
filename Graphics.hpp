#ifndef GRAPHICS_HPP
#define GRAPHICS_HPP

#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include<string>
#include<map>

/**
 * Graphics header file
*/

/**
 * Struct of a sprite
 * for SDL2_Image
*/
struct Sprite{
    SDL_Texture* texture;
    int width;
    int height;
};

/**
 * Graphics class prototype
*/
class Graphics{
public:
    /**
     * constructor prototype
     * @param renderer an SDL renderer for rendering
    */
    Graphics(SDL_Renderer* renderer);

    /**
     * destructor prototype
    */
    ~Graphics();

   /**
     * prototype for loading a sprite into memory
     * @param name defines variable for sprite
     * @param filepath path for the file
    */
    void loadSprite(const std::string& name, const std::string& filepath);

    /**
     * prototype for rendering a sprite from memory
     * @param name the name variable used to define what you are rendering
     * @param x the x position of the sprite
     * @param y the y position of the sprite
     * @param myRect the SDL_Rect that the sprite will be rendered on
    */
    void renderSprite(const std::string& name, int x, int y, SDL_Rect myRect);

    /**
     * prototype for updating renderer
    */
    void update();

    /**
     * prototype for clearing renderer
    */
    void clear();

private:
    SDL_Renderer* renderer;
    std::map<std::string, Sprite> spriteMap;

};

#endif