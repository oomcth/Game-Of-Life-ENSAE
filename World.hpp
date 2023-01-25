//
//  World.hpp
//  Game Of Life
//
//
//

#ifndef World_hpp
#define World_hpp

#include <stdio.h>
#include "Tile.hpp"
#include "map.hpp"

//header files arn't commented

class World{
    
public:
    World(int cols, int rows);
    
    void newWorld(int cols, int rows, World *world);
    void Update();
    void Clear();
    
    int x_size;
    int y_size;
    int prev_dark_count;
    int next_dark_count;
    Map *map;
    Tile **prev_dark_tiles;
    
private:
    
    Tile **next_dark_tiles;
    int64_t loop = 0;    
    
};
#endif /* World_hpp */
