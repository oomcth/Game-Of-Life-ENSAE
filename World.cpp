//
//  World.cpp
//  Game Of Life
//
//
//

#include "World.hpp"
#include "Tile.hpp"
#include <iostream>

// World updates the Map and stores data about it.

// create a world of given size
World::World(int cols, int rows){
    x_size = cols;
    y_size = rows;
    map = new Map(cols, rows);
    
    prev_dark_tiles = new Tile*[x_size * y_size];
    next_dark_tiles = new Tile*[x_size * y_size];
    prev_dark_count = 0;
    next_dark_count = 0;
}

// change the world size
void World::newWorld(int cols, int rows, World *world)
{
    std::cout  << (cols < x_size and rows < y_size) << std::endl;
    if(cols < x_size and rows < y_size){
        x_size = rows;
        y_size = cols;
    }else{
        x_size = cols;
        y_size = rows;
        
        if(map->tiles.size() < cols or map->tiles[0].size() < rows){
            map->extend(cols, rows);
        }
    }
}

// update the world
void World::Update(){
    
    loop++;
    next_dark_count = 0;
    for(int i = 0; i < prev_dark_count; i++){
        if(prev_dark_tiles[i]->updated != loop){
            int count = map->neighbours(prev_dark_tiles[i]->x, prev_dark_tiles[i]->y, loop);
            // std::cout << count << prev_dark_tiles[i].x << "\n";
            if(prev_dark_tiles[i]->Alive(loop) == 1){
                if(count != 2 and count != 3){
                    //prev_dark_tiles[i].Kill(loop);
                    map->Get_Tile(prev_dark_tiles[i]->x, prev_dark_tiles[i]->y).Kill(loop);
                }
                else{
                    next_dark_tiles[next_dark_count] = prev_dark_tiles[i];
                    next_dark_count++;
                }
            }
            else{
                if(count == 3){
                    prev_dark_tiles[i]->Create(loop);
                    next_dark_tiles[next_dark_count] = prev_dark_tiles[i];
                    next_dark_count++;
                }
            }
        }
    }
    
    for(int i = 0; i < prev_dark_count; i++){
        int** temp = map->Get_neighbours(prev_dark_tiles[i]->x, prev_dark_tiles[i]->y);
        for(int j = 0; j < 24;j++){
            if(map->Get_Tile(temp[j][0], temp[j][1]).updated != loop){
                int count = map->neighbours(temp[j][0], temp[j][1], loop);
                if(count == 3 and !map->Get_Tile(temp[j][0], temp[j][1]).Alive(loop)){
                    map->Get_Tile(temp[j][0], temp[j][1]).Create(loop);
                    next_dark_tiles[next_dark_count] = &map->Get_Tile(temp[j][0], temp[j][1]);
                    next_dark_count++;
                }
            }
        }
        
        for(int o = 0; o < 8; o++){
            delete temp[o];
        }
        delete temp;
    }

    prev_dark_count = next_dark_count;
    prev_dark_tiles = next_dark_tiles;

}

// clear the map
//ie. kill all the tiles
void World::Clear(){
    map->Clear();
    prev_dark_count = 0;
}
