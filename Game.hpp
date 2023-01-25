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
    
private:
    bool isRunning;
    bool clicked = true;
    bool playing = true;
    bool transposed = false;
    int loopUpdate = 600;
    int loop = 0;
    SDL_Window *window;
    Painter *painter;
    World *world;
    SDL_Renderer *renderer;
    Drawer *drawer;

};
#endif /* Game_hpp */
