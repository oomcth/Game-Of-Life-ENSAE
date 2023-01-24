//
//  Painter.hpp
//  Game Of Life
//
//
//

#ifndef Painter_hpp
#define Painter_hpp

#include <stdio.h>
#include "World.hpp"
#include <SDL2/SDL.h>
#include "Drawer.hpp"
#include <string>
#include "item.hpp"

//header files arn't commented

class Painter{
    
public:
    
    Painter();
    ~Painter();
    
    void init(World *world, Drawer *drawer, int w, int h);
    void drawDrawer(SDL_Renderer *renderer, Drawer *drawer);
    void drawWorld(SDL_Renderer *renderer, Drawer *drawer, bool transposed);
    void drawItem(SDL_Renderer * renderer, item item, int x, int y, bool transposed);
    void drawRect(int x, int y, int w, int h, SDL_Renderer *renderer, bool filled, bool red);
    
    int xFromWorld(int x);
    int yFromWorld(int y);
    int width;
    int height;
    int xmargin = 100;
    World *world;
    Drawer *drawer;
    
};

#endif /* Painter_hpp */
