//
//  Map.hpp
//  Game Of Life
//
//
//

#ifndef Map_hpp
#define Map_hpp

#include <stdio.h>
#include <vector>
#include "Tile.hpp"

//header files arn't commented

class Map
{
public:
    
    Map(int rows, int cols);
    
    void extend(int rows, int cols);
    void Clear();
    
    Tile& Get_Tile(int x, int y);
    int neighbors(int x, int y, int loop);
    int** Get_neighbors(int x, int y);
    std::vector<std::vector<Tile*>> tiles;
    
};

#endif /* Map_hpp */
