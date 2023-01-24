//
//  item.cpp
//  Game_Of_Life_ENSAE
//
//
//
#include <iostream>
#include <string>

#include "item.hpp"

// an item describes a tile pattern to be put in the map

line::line(){
    w = 3;
    h = 1;
    tiles = new int*[w];
    for (int i = 0; i < w; i++) {
         tiles[i] = new int[h];
    }
    tiles[0][0] = 1;
    tiles[1][0] = 1;
    tiles[2][0] = 1;
};

slider::slider(){
    w = 3;
    h = 3;
    tiles = new int*[w];
    for (int i = 0; i < w; i++) {
         tiles[i] = new int[h];
    }
    tiles[0][0] = 0;
    tiles[1][0] = 1;
    tiles[2][0] = 0;
    tiles[0][1] = 0;
    tiles[1][1] = 0;
    tiles[2][1] = 1;
    tiles[0][2] = 1;
    tiles[1][2] = 1;
    tiles[2][2] = 1;
};

cannon::cannon(){
    w = 2;
    h = 2;
    tiles = new int*[w];
    for (int i = 0; i < w; i++) {
         tiles[i] = new int[h];
    }
    tiles[0][0] = 1;
    tiles[1][0] = 1;
    tiles[0][1] = 1;
    tiles[1][1] = 1;
};

launcher::launcher(){
    w = 34;
    h = 21;
    tiles = new int*[w];
    for (int i = 0; i < w; i++) {
         tiles[i] = new int[h];
    }
    for(int i = 0; i < w;i++){
        for(int j = 0; j < h; j++){
            tiles[i][j] = 0;
        }
    }
    
    tiles[1][1] = 1;
    tiles[1][2] = 1;
    tiles[2][1] = 1;
    tiles[2][2] = 1;
    tiles[8][1] = 1;
    tiles[8][2] = 1;
    tiles[9][1] = 1;
    tiles[9][2] = 1;
    tiles[5][4] = 1;
    tiles[5][5] = 1;
    tiles[6][4] = 1;
    tiles[6][5] = 1;
    tiles[33][12] = 1;
    tiles[33][13] = 1;
    tiles[32][12] = 1;
    tiles[32][13] = 1;
    tiles[29][12] = 1;
    tiles[28][13] = 1;
    tiles[27][14] = 1;
    tiles[28][11] = 1;
    tiles[27][10] = 1;
    tiles[26][10] = 1;
    tiles[24][10] = 1;
    tiles[23][10] = 1;
    tiles[22][11] = 1;
    tiles[22][12] = 1;
    tiles[22][13] = 1;
    tiles[23][13] = 1;
    tiles[24][13] = 1;
    tiles[28][20] = 1;
    tiles[26][20] = 1;
    tiles[25][20] = 1;
    tiles[28][19] = 1;
    tiles[27][19] = 1;
    tiles[25][19] = 1;
    
}
