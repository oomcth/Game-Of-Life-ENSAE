//
//  Drawer.cpp
//  Game_Of_Life_ENSAE
//
//
//

#include "Drawer.hpp"

// the drawer is a list of rect at the left of the screen
// the user can pick a drawer's items and put it in the map

Drawer::Drawer(){
    items.resize(4);
    items[0] = line();
    items[1] = cannon();
    items[2] = slider();
    items[3] = launcher();
    
};
