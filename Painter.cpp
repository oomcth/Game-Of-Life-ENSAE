//
// Painter.cpp
// Game_of_life_ENSAE
//
//
//

#include "Painter.hpp"
#include <iostream>
#include <SDL2/SDL.h>
#include "Drawer.hpp"
#include <iterator>
#include <string>

//Painter is a class that is used to draw different items.


Painter::~Painter(){
    
}

// initialise the class parameter.
void Painter::init(World *world, Drawer *drawer, int w, int h){
    this->world = world;
    this->drawer = drawer;
    width = w - xmargin;
    height = h;
}

// draw a rect.
void Painter::drawRect(int x, int y, int w, int h, SDL_Renderer *renderer, bool filled, bool red){

    SDL_Rect rect;
    rect.x = x;
    rect.y = y;
    rect.w = w;
    rect.h = h;
    
    if(!red){
        SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);
    }
    else{
        SDL_SetRenderDrawColor(renderer, 255, 0, 0, 255);
    }
    if(filled){
        SDL_RenderFillRect(renderer, &rect);
    }
    else{
        SDL_RenderDrawRect(renderer, &rect);
    }

    SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);

    // SDL_RenderPresent(renderer);
}

// Draw the whole screen but the drawer.
void Painter::drawWorld(SDL_Renderer *renderer, Drawer *drawer, bool transposed){
    int temp1 = int(width/world->x_size);
    int temp2 = int(height/world->y_size);
    for(int i = 0; i < world->x_size;i++){
        for(int j = 0; j < world->y_size;j++){
            if (&world->map->Get_Tile(i, j) == nullptr) {
                std::cout << i << " " << j << std::endl;
            }
                if(world->map->Get_Tile(i, j).alive){
                    drawRect(xmargin + temp1 * i, temp2 * j, temp1, temp2, renderer, true, false);
                }
            
            if(world->map->Get_Tile(i, j).alive){
                drawRect(xmargin + temp1 * i, temp2 * j, temp1, temp2, renderer, true, false);
            }
        }
    }
    if(drawer->target != -1){
        int mx, my;
        SDL_GetMouseState(&mx, &my);
        if(mx > xmargin and mx < xmargin + width and my > 0 and my < height){
            drawItem(renderer, drawer->items[drawer->target], int((mx - xmargin)*world->x_size/width), int(my*world->y_size/height), transposed);
        }
    }
    if(drawer->target == -1){
        int mx, my;
        SDL_GetMouseState(&mx, &my);
        if(mx > xmargin and mx < xmargin + width and my > 0 and my < height){
            drawRect(xmargin + temp1 * int((mx - xmargin)*world->x_size/width), temp2 * int(my*world->y_size/height), temp1, temp2, renderer, true, true);
        }
    }
}

// Draw an item.
void Painter::drawItem(SDL_Renderer *renderer, item item, int x, int y, bool transposed){
    // std::cout << item.w << " " << item.h << std::endl;
    // std::cout<<x;
    int temp1 = int(width/world->x_size);
    int temp2 = int(height/world->y_size);
    if(drawer->items[drawer->target].w < world->x_size + 2 and drawer->items[drawer->target].h < world->y_size + 2)
    {
        if(!transposed){
            if(x+item.w > world->x_size){
                x = world->x_size - item.w;
            }
            if(y+item.h > world->y_size){
                y = world->y_size - item.h;
            }
            for(int w = 0; w < item.w;w++){
                for(int h = 0; h < item.h;h++){
                    if(item.tiles[w][h] == 1){
                        drawRect((x+w)*temp1 + xmargin, (y+h)*temp2, temp1, temp2, renderer, true, true);
                    }
                }
            }
        }
        else{
            if(x+item.h > world->x_size){
                x = world->x_size - item.h;
            }
            if(y+item.w > world->y_size){
                y = world->y_size - item.w;
            }
            for(int w = 0; w < item.w;w++){
                for(int h = 0; h < item.h;h++){
                    if(item.tiles[w][h] == 1){
                        drawRect((x+h)*temp1 + xmargin, (y+w)*temp2, temp1, temp2, renderer, true, true);
                    }
                }
            }
        }
    }
    
    
}

// draw the drawer.
void Painter::drawDrawer(SDL_Renderer *renderer, Drawer *drawer){
    for(int i = 0; i<drawer->items.size();i++){
        drawRect(0, 60 + 50 * i, 40, 40, renderer, true, drawer->target == i);
    }
}


