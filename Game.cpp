//
//  Game.cpp
//  Game_Of_Life_ENSAE
//
//
//

#include "Game.hpp"
#include <iostream>
#include "World.hpp"

// Game is the main class of the project, its here that all the other classes are manipulated.

Game::Game(){
    
}

// initalise the class's parameters
// in particular, launch SQL
void Game::init(const char* title, int xpos, int ypos, int width, int height, bool fullscreen, World world){
    
    drawer = new Drawer();
    
    int flags = 0;
    if(fullscreen){
        flags = SDL_WINDOW_FULLSCREEN;
    }
    
    if(SDL_Init(SDL_INIT_EVERYTHING) == 0)
    {
        std::cout << "SubSystem initialised" << std::endl;
        
        window = SDL_CreateWindow(title, xpos, ypos, width, height, flags);
        if (window){
            std::cout << "window created" << std::endl;
        }
        
        renderer = SDL_CreateRenderer(window, -1, 0);
        if(renderer){
            SDL_SetRenderDrawColor(renderer, 255, 0, 255, 255);
            std::cout << "render created" << std::endl;
        }
        isRunning =true;
        
        this->world = &world;
        
        painter = new Painter();
        painter->init(&world, drawer, width, height);
        
    }
    else{
        isRunning = false;
    }
}

// handle user's inputs
void Game::handleEvent(){
    SDL_Event event;
    SDL_PollEvent(&event);
    switch (event.type) {
        case SDL_QUIT:
            isRunning = false;
            break;
    case SDL_MOUSEBUTTONDOWN:
            
            int x, y;
            SDL_GetMouseState(&x, &y);
            
            if(event.button.button == SDL_BUTTON_LEFT){
                if(!clicked){
                    double temp1 = double(painter->width)/double(world->x_size);
                    double temp2 = double(painter->height)/double(world->y_size);
                    if(x > painter->xmargin){
                        world->map->Get_Tile(int((x-painter->xmargin)/temp1), int(double(y)/temp2)).Toggle();
                        world->map->Get_Tile(int((x-painter->xmargin)/temp1), int(y/temp2) ).updated = -1;
                        world->prev_dark_tiles[world->prev_dark_count] = &(world->map->Get_Tile(int((x-painter->xmargin)/temp1), int(y/temp2)));
                        world->prev_dark_count++;
                    }
                }
                else{
                    
                    if(x > painter->xmargin and drawer->items[drawer->target].w < world->x_size + 2 and drawer->items[drawer->target].h < world->y_size + 2){
                        double temp1 = double(painter->width)/double(world->x_size);
                        double temp2 = double(painter->height)/double(world->y_size);
                        int temp3 = int(double(x-painter->xmargin)/temp1);
                        int temp4 = int(double(y)/temp2);
                        int mx = std::max(0, temp3);
                        int my = std::max(0,temp4);
                        if(!transposed){
                            if(mx+drawer->items[drawer->target].w > world->x_size){
                                mx = world->x_size - drawer->items[drawer->target].w;
                            }
                            if(my+drawer->items[drawer->target].h > world->y_size){
                                my = world->y_size - drawer->items[drawer->target].h;
                            }
                            for(int w = 0; w < drawer->items[drawer->target].w;w++){
                                for(int h = 0; h < drawer->items[drawer->target].h;h++){
                                    if (drawer->items[drawer->target].tiles[w][h] == 1){
                                        world->map->tiles[mx+w + 1][my+h + 1]->alive = true;
                                        world->prev_dark_tiles[world->prev_dark_count] = world->map->tiles[mx+w + 1][my+h + 1];
                                        world->prev_dark_count++;
                                    }
                                }
                            }
                        }
                        else{
                            
                            if(mx+drawer->items[drawer->target].h > world->x_size){
                                mx = world->x_size - drawer->items[drawer->target].h;
                            }
                            if(my+drawer->items[drawer->target].w > world->y_size){
                                my = world->y_size - drawer->items[drawer->target].w;
                            }
                            for(int w = 0; w < drawer->items[drawer->target].w;w++){
                                for(int h = 0; h < drawer->items[drawer->target].h;h++){
                                    if (drawer->items[drawer->target].tiles[w][h] == 1){
                                        world->map->tiles[mx+h + 1][my+w + 1]->alive = true;
                                        world->prev_dark_tiles[world->prev_dark_count] = world->map->tiles[mx+h + 1][my+w + 1];
                                        world->prev_dark_count++;
                                    }
                                }
                            }
                        }
                    }
                    
                    
                    clicked = false;
                    drawer->target = -1;
                }
                
                // drawRect(0, 60 + 50 * i, 40, 40, renderer, true, drawer->target == i);
                float tempy = (y-60)/50;
                if(x < 40){
                    if(tempy < drawer->items.size()){
                        drawer->target = tempy;
                        clicked = true;
                    }
                }
            }
            break;
        case SDL_KEYDOWN:
            if(event.key.keysym.sym == SDLK_SPACE){
                playing = !playing;
                loop = 0;
            }
            if(event.key.keysym.sym == SDLK_t){
                transposed = !transposed;
            }
            if(event.key.keysym.sym == SDLK_1){
                world->newWorld(2*world->x_size, 2*world->y_size, world);
            }
            if(event.key.keysym.sym == SDLK_2){
                world->newWorld(int(world->x_size/2), int(world->y_size/2), world);
            }
            if(event.key.keysym.sym == SDLK_ESCAPE){
                world->Clear();
            }
            if(event.key.keysym.sym == SDLK_n){
                world->Update();
                loop = 0;
            }
            if(event.key.keysym.sym == SDLK_UP){
                loopUpdate = int(loopUpdate * 0.9);
                loop = 0;
            }
            if(event.key.keysym.sym == SDLK_DOWN){
                loopUpdate = int(loopUpdate * 1.1);
                loop = 0;
            }
            break;
        default:
            break;
    }
}

// update world
void Game::update(){
    
    if(loop == loopUpdate && playing){
        world->Update();
        loop = 0;
    }
    
    loop++;
}

// render the screen
void Game::render(){
    SDL_RenderClear(renderer);
    painter->drawWorld(renderer, drawer, transposed);
    painter->drawDrawer(renderer, drawer);
    SDL_RenderPresent(renderer);
}

// quit SQL and the game
void Game::clean(){
    painter->~Painter();
    SDL_DestroyWindow(window);
    SDL_DestroyRenderer(renderer);
    SDL_Quit();
    std::cout << "game cleared" << std::endl;
}

