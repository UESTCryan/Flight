//
//  Sprite.h
//  plane
//
//  Created by Ryan Lai on 15/5/19.
//  Copyright (c) 2015年 Ryan Lai. All rights reserved.
//

#ifndef __plane__Sprite__
#define __plane__Sprite__

#include <SFML/Graphics.hpp>

class Sprite:public sf::Sprite{
public:
    virtual void heartBeat()=0;//动画
    int level;
};

#endif