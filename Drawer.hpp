//
//  Drawer.hpp
//  Game_Of_Life_ENSAE
//
//
//

#ifndef Drawer_hpp
#define Drawer_hpp

//header files aren't commented

#include <stdio.h>
#include "item.hpp"
#include <vector>

class Drawer{
    
public:
    Drawer();
    
    std::vector<item> items;
    int target = 0;
};


#endif /* Drawer_hpp */
