//
//  Bullet.h
//  plane
//
//  Created by Ryan Lai on 15/5/19.
//  Copyright (c) 2015年 Ryan Lai. All rights reserved.
//

#ifndef __plane__Bullet__
#define __plane__Bullet__

#include "Sprite.h"
#include <SFML/Audio.hpp>
#include <SFML/Graphics.hpp>
class Bullet:public Sprite{
public:
    Bullet(float x, float y);
    void heartBeat();//动画
    bool owner_is_hero;//0为我的飞机的子弹，1为敌机的子弹
    float bulletX,bulletY;//子弹坐标
};
#endif
