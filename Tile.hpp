//
//  Tile.hpp
//  Game Of Life
//
//
//

#ifndef Tile_hpp
#define Tile_hpp

//header files aren't commented

#include <stdio.h>

class Tile{
public:
    Tile();
    
    void Create(int64_t loop);
    void Kill(int64_t loop);
    void Toggle();
    void Draw();
    
    int x, y;
    int alive = 0;
    int Alive(int loop);
    int64_t updated = -1;
    bool lastState;
    bool fixed = false;
    
};
#endif /* Tile_hpp */
