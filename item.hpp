//
//  item.hpp
//  Game_Of_Life_ENSAE
//
//
//

#ifndef item_hpp
#define item_hpp

#include <stdio.h>
#include <string>

//header files arn't commented

class item{
  
public:
    std::string name = "error";
    int** tiles;
    int w;
    int h;
};

class line : public item{
public:
    line();
};

class cannon : public item{
public:
    cannon();
};

class slider : public item{
public:
    slider();
};

class launcher : public item{
public:
    launcher();
};

#endif /* item_hpp */
