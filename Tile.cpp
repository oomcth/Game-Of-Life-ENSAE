//
//  Tile.cpp
//  Game Of Life
//
//
//

#include "Tile.hpp"

// A tile is the core object of the game.

Tile::Tile(){
    
}

// return the state (alive) of the tile at last update.
int Tile::Alive(int loop){
    if(loop == updated){
        if(alive == 0){
            return 1;
        }
        else{
            return 0;
        }
    }
    else{
        return alive;
    }
}

// kill a tile.
void Tile::Kill(int64_t loop){
    alive = 0;
    updated = loop;
}

// make a tile alive.
void Tile::Create(int64_t loop){
    alive = 1;
    updated = loop;
}

// change a Tile's alive state.
void Tile::Toggle(){
    alive = !alive;
}
