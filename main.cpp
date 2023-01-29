#include <iostream>
#include <thread>
#include <math.h>
#include "World.hpp"
#include <SDL2/SDL.h>
#include "Game.hpp"
#include <chrono>
#include <thread>

using namespace std::this_thread;
using namespace std::chrono;

int main(int argc, const char * argv[]) {
    // insert code here...
    // std::this_thread::sleep_for(10s);
    
    World world(20, 20);
    
    Game *game = new Game();
    
    game->init("Game Of Life", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 800, 600, false, world);
    
    while(game->running()){
        game->handleEvent();
        game->update();
        game->render();
        sleep_for(microseconds(16));
    }
    
    game->clean();
    
    return 0;
}

