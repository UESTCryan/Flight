//
//  Award.h
//  My Plane
//
//  Created by Ryan Lai on 15/6/2.
//  Copyright (c) 2015年 Ryan Lai. All rights reserved.
//

#ifndef __My_Plane__Award__
#define __My_Plane__Award__

#include <stdio.h>
#include "Sprite.h"
#include <SFML/Audio.hpp>
#include <SFML/Graphics.hpp>
class Award:public Sprite{
public:
    Award();
    void heartBeat();//动画
    float AwardX,AwardY;//奖励坐标
};
#endif /* defined(__My_Plane__Award__) */
