//
//  Game.hpp
//  Game_Of_Life_ENSAE
//
//
//

#ifndef Game_hpp
#define Game_hpp
#include <SDL2/SDL.h>
#include "Painter.hpp"
#include <stdio.h>
#include "Drawer.hpp"

//header files arn't commented

class Game{
    
public:
    Game();
    ~Game();
    
    void init(const char* title, int xpos, int ypos, int width, int height, bool fullscreen, World world);
    
    void handleEvent();
    void update();
    void render();
    void clean();
    
    bool running() {return isRunning;}
    
    int loopUpdate = 600;
    
    bool playing = true;
    
    int loop = 0;
    Painter *painter;
    World *world;
    bool isRunning;
    SDL_Window *window;
    SDL_Renderer *renderer;
    bool clicked = true;
    bool transposed = false;
    Drawer *drawer;
};
#endif /* Game_hpp */
