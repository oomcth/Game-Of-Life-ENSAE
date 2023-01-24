//
//  Tile.hpp
//  Game Of Life
//
//
//

#ifndef Tile_hpp
#define Tile_hpp

//header files arn't commented

#include <stdio.h>

class Tile{
public:
    Tile();
    int x, y;
    int Alive(int loop);
    int64_t updated = -1;
    bool lastState;
    void Create(int64_t loop);
    void Kill(int64_t loop);
    void Toggle();
    void Draw();
    bool fixed = false;
    int alive = 0;
    
};
#endif /* Tile_hpp */
