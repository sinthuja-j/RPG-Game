#include "MainWindow.hpp"

/**
 * @brief Main Window Class houses the SDL Window
 * @author Chase
*/

/**
 * @brief Constructor for MainWindow initialization
 * @param width of window
 * @param height of window
*/
MainWindow::MainWindow(int width, int height) {
    SDL_Init(SDL_INIT_VIDEO);
    // Create Window
    window = SDL_CreateWindow("The Adventures of Jerry", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, width, height, SDL_WINDOW_SHOWN);
    // Create renderer
    renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);
}

/**
 * @brief Decontructor
*/
MainWindow::~MainWindow() {
    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
    SDL_Quit();
}