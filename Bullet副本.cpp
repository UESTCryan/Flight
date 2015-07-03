//
//  Bullet.cpp
//  plane
//
//  Created by Ryan Lai on 15/5/19.
//  Copyright (c) 2015年 Ryan Lai. All rights reserved.
//

#include "Bullet.h"
#include "Load.h"
#include <SFML/Graphics.hpp>
Bullet::Bullet(float x, float y){
    setTexture(Load::BULLET);//设置纹理
    setPosition(x, y);//设置子弹初始位置
    bulletX = x;
    bulletY = y;
    owner_is_hero = true;//标志子弹的拥有者
}

void Bullet::heartBeat(){
    float speed = -3;
    if(!owner_is_hero){
        speed = 5 + level;
        setTexture(Load::BULLET1);
    }
    move(0,speed);
    bulletY += speed;
}