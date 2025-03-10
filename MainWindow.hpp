#ifndef MAINWINDOW_HPP
#define MAINWINDOW_HPP
#include <SDL2/SDL.h>

/**
 * @brief Main window header file
*/

/**
 * @brief Main window prototype
*/
class MainWindow{
    public:
    SDL_Window* window = nullptr;
    SDL_Renderer* renderer = nullptr;

    /**
     * @brief Constructor prototype
     * @param width width of window
     * @param height height of window
    */
    MainWindow(int width, int height);

    /**
     * @brief Destructor prototype
    */
    ~MainWindow();

    /**
     * @brief Renderer getter prototype
    */
    SDL_Renderer* getRenderer() const {return renderer;}
};


#endif 