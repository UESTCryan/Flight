//
//  Award.cpp
//  My Plane
//
//  Created by Ryan Lai on 15/6/2.
//  Copyright (c) 2015年 Ryan Lai. All rights reserved.
//

#include "Award.h"
#include "Sky.h"
#include "Load.h"
#include <SFML/Graphics.hpp>
Award::Award(){
    setTexture(Load::AWARD);//设置纹理
    AwardX = rand()%430+10;
    AwardY = 0;
    setPosition(AwardX,AwardY);
    Sky::getInstance()->add(this);
    Sky::getInstance()->addAward(this);

}

void Award::heartBeat(){
    float speed = 4;
    move(0,speed);
    AwardY += speed;
}