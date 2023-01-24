//
//  Map.cpp
//  Game Of Life
//
//
//

#include "Map.hpp"
#include "tile.hpp"
#include <iostream>

// Map is the class that is used for manipulating tiles.

// creates an instance of MAP and a grid of tiles which is the main object manipulated by the class MAP.
Map::Map(int rows, int cols)
{
    tiles.resize(rows+2);
    for (auto& row : tiles)
    {
        row.resize(cols+2);
    }
    
    for(int i = 0; i < rows;i++){
        for(int j = 0; j < cols; j++){
            tiles[i+1][j+1] = new Tile();
            tiles[i+1][j+1]->x = i;
            tiles[i+1][j+1]->y = j;
        }
    }
    
    for(int i = 0; i < cols + 2; i++){
        tiles[i][0] = new Tile();
        tiles[i][cols + 1] = new Tile();
        tiles[i][0]->fixed = true;
        tiles[i][cols+1]->fixed = true;
    }
    for(int i = 0; i < rows + 2; i++){
        tiles[0][i] = new Tile();
        tiles[rows + 1][i] = new Tile();
        tiles[0][i]->fixed = true;
        tiles[rows + 1][i]->fixed = true;
    }
    
    
}

// extends the grid of tiles.
void Map::extend(int rows, int cols)
{
    int tempx = tiles.size() - 2;
    int tempy = tiles[0].size() - 2;
    if(rows > tempx){
        tiles.resize(rows +2);
    }
    if(cols > tempy){
        for (auto& row : tiles)
        {
            row.resize(cols+2);
        }
    }
    
    for(int i = 1; i < tempy + 2; i++){
        tiles[i][tempy + 1] = new Tile();
        tiles[i][tempy + 1]->fixed = false;
        tiles[i][tempy + 1]->x = i - 1;
        tiles[i][tempy + 1]->y = tempy;
    }
    for(int i = 1; i < tempx + 2; i++){
        tiles[tempx + 1][i] = new Tile();
        tiles[tempx + 1][i]->fixed = true;
        tiles[tempx + 1][i]->x = tempx;
        tiles[tempx + 1][i]->y = i - 1;
    }
    
    for(int i = tempx + 1; i < rows;i++){
        for(int j = tempy + 1; j < cols; j++){
            tiles[i+1][j+1] = new Tile();
            tiles[i+1][j+1]->x = i;
            tiles[i+1][j+1]->y = j;
        }
    }
    for(int i = tempx + 1; i < rows;i++){
        for(int j = 0; j < tempy + 1; j++){
            tiles[i+1][j+1] = new Tile();
            tiles[i+1][j+1]->x = i;
            tiles[i+1][j+1]->y = j;
        }
    }
    
    for(int i = 0; i < tempx + 1;i++){
        for(int j = tempy + 1; j < cols; j++){
            tiles[i+1][j+1] = new Tile();
            tiles[i+1][j+1]->x = i;
            tiles[i+1][j+1]->y = j;
        }
    }
    
    for(int i = 0; i < cols + 2; i++){
        tiles[i][0] = new Tile();
        tiles[i][cols + 1] = new Tile();
        tiles[i][0]->fixed = true;
        tiles[i][cols+1]->fixed = true;
    }
    for(int i = 0; i < rows + 2; i++){
        tiles[0][i] = new Tile();
        tiles[rows + 1][i] = new Tile();
        tiles[0][i]->fixed = true;
        tiles[rows + 1][i]->fixed = true;
    }
    

}

// return the tile with the whished coordonates.
Tile& Map::Get_Tile(int x, int y){
    if(x > -1 and x < tiles.size() + 1 and y > -1 and y < tiles[0].size())
    {
        return *tiles[x+1][y+1];
    }
    else
    {
        Tile temp = Tile();
        return temp;
    }
}

// returns how many alive neigbors a tiles has.
int Map::neighbors(int x, int y, int loop){
    return Get_Tile(x+1, y+1).Alive(loop) + Get_Tile(x+1, y).Alive(loop) + Get_Tile(x+1, y-1).Alive(loop) + Get_Tile(x, y-1).Alive(loop) + Get_Tile(x-1, y-1).Alive(loop) + Get_Tile(x-1, y).Alive(loop) + Get_Tile(x-1, y+1).Alive(loop) + Get_Tile(x, y+1).Alive(loop);
}

// return an array of a tile's neighbors.
int** Map::Get_neighbors(int x, int y){
    int** r = 0;
    r = new int*[24];
    for(int temp = 0; temp<24;temp++){
        r[temp] = new int[2];
    }
    
    if(x == 0){
        x = 1;
        tiles[x+1][y+1]->alive = 0;
    }
    if(y <= 1){
        y = 1;
        tiles[x+1][y+1]->alive = 0;
    }
    if(x == tiles.size()-3){
        x = tiles.size()-4;
        tiles[x+1][y+1]->alive = 0;
    }
    if(y == tiles[0].size()-3){
        y = tiles[0].size()-4;
        tiles[x+1][y+1]->alive = 0;
    }
    
    r[0][0] = tiles[x+2][y+2]->x; r[0][1] = tiles[x+2][y+2]->y;
    r[1][0] = tiles[x+2][y+1]->x; r[1][1] = tiles[x+2][y+1]->y;
    r[2][0] = tiles[x+2][y]->x; r[2][1] = tiles[x+2][y]->y;
    r[3][0] = tiles[x+1][y]->x; r[3][1] = tiles[x+1][y]->y;
    r[4][0] = tiles[x][y]->x; r[4][1] = tiles[x][y]->y;
    r[5][0] = tiles[x][y+1]->x; r[5][1] = tiles[x][y+1]->y;
    r[6][0] = tiles[x][y+2]->x; r[6][1] = tiles[x][y+2]->y;
    r[7][0] = tiles[x+1][y+2]->x; r[7][1] = tiles[x+1][y+2]->y;
    r[8][0] = tiles[x+3][y+3]->x; r[8][1] = tiles[x+3][y+3]->y;
    r[23][0] = tiles[x+3][y+2]->x; r[23][1] = tiles[x+3][y+2]->y;
    r[9][0] = tiles[x+3][y+1]->x; r[9][1] = tiles[x+3][y+1]->y;
    r[10][0] = tiles[x+3][y]->x; r[10][1] = tiles[x+3][y]->y;
    r[11][0] = tiles[x+3][y-1]->x; r[11][1] = tiles[x+3][y-1]->y;
    r[12][0] = tiles[x+2][y-1]->x; r[12][1] = tiles[x+2][y-1]->y;
    r[13][0] = tiles[x+1][y-1]->x; r[13][1] = tiles[x+1][y-1]->y;
    r[14][0] = tiles[x][y-1]->x; r[14][1] = tiles[x][y-1]->y;
    r[15][0] = tiles[x-1][y-1]->x; r[15][1] = tiles[x-1][y-1]->y;
    r[16][0] = tiles[x-1][y]->x; r[16][1] = tiles[x-1][y]->y;
    r[17][0] = tiles[x-1][y+1]->x; r[17][1] = tiles[x-1][y+1]->y;
    r[18][0] = tiles[x-1][y+2]->x; r[18][1] = tiles[x-1][y+2]->y;
    r[19][0] = tiles[x-1][y+3]->x; r[19][1] = tiles[x-1][y+3]->y;
    r[20][0] = tiles[x][y+3]->x; r[20][1] = tiles[x][y+3]->y;
    r[21][0] = tiles[x+1][y+3]->x; r[21][1] = tiles[x+1][y+3]->y;
    r[22][0] = tiles[x+2][y+3]->x; r[22][1] = tiles[x+2][y+3]->y;
    
    return r;
}

// Clears the grid of tile.
// ie. kill them all.
void Map::Clear(){
    for(auto& vect : tiles){
        for(auto& tile : vect){
            tile->alive = 0;
            tile->updated = -10;
            
        }
    }
}
