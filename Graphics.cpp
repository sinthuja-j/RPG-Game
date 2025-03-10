#include "Graphics.hpp"
#include <iostream>

/**
 * @brief
 * Graphics:
 * This is an important class for GUI aspects of the game. Covers functionality like sprite loading, rendering, updating, and clearing
 * @author Chase
*/

/**
*Graphics constructor, class used to generate graphics for the game
*@param renderer and SDL_Renderer which is the SDL feature allowing graphics rendering
*/
Graphics::Graphics(SDL_Renderer* renderer): renderer(renderer){}

/**
* @brief Graphics Destructor, used to clean up memory and prevent memory leaks
*/
Graphics::~Graphics(){
    for(auto&pair : spriteMap){
        SDL_DestroyTexture(pair.second.texture);
    }
}
/**
* @brief loadSprite: This method loads a sprite into memory, so that it can be rendered when needed,
* oftentimes, an entire spritemap image is loaded in, and users will choose specific parts of 
* the loaded image to render
* @param name a string used to call the sprite image what you want 
* @param filepath a string representing the path to find the image you want to load
*/
void Graphics::loadSprite(const std:: string&name, const std::string& filepath){
    SDL_Texture* texture = IMG_LoadTexture(renderer, filepath.c_str());
    if(texture == nullptr){
        std::cout << "Unable to load texture" << std::endl;
        return;
    }
    SDL_SetTextureBlendMode(texture,SDL_BLENDMODE_BLEND); //this is for dealing with transparency 
    int width, height;
    SDL_QueryTexture(texture, NULL, NULL, &width, &height);
    Sprite sprite = {texture,width, height}; //sprite has associated image, width and height
    spriteMap[name] = sprite;
}

/**
*@brief renderSprite: This method is what specifically deals with placing images on the screen
*@param name a string used to define what sprite you are rendering
*@param x the x position of the sprite
*@param y the y position of the sprite
*@param myRect the part of the image you are rendering useful for sprite maps,
*you must make a SDL_Rect of desired size to pass into the method, if your image is
*a singular sprite, you just make the rectangle, the parameters of the whole image.
*/
void Graphics::renderSprite(const std::string& name, int x, int y, SDL_Rect myRect){
    // if (name=="NOT") {
    //     SDL_SetRenderDrawColor(renderer, 255,255,255,255);
    //     SDL_RenderFillRect(renderer, &myRect);
    //     std::cout << "HELLO" << std::endl;

    // } else {
    auto it = spriteMap.find(name);
    if(it!= spriteMap.end()){
        SDL_Rect destinationRec = {x,y,myRect.w, myRect.h};
        if(SDL_RenderCopy(renderer, it->second.texture, &myRect, &destinationRec) != 0){
            std::cout << "Unable to render sprite" << std::endl;
        }
    }
    
}
/**
* @brief update: repeatedly called to continuously update the graphics as the game runs
*/
void Graphics::update(){
    SDL_RenderPresent(renderer);
}
/**
* @brief clears the renderer, used when u want to begin rendering new things
*/
void Graphics::clear(){
    SDL_RenderClear(renderer);
}

