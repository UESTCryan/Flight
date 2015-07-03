//
//  Hero.h
//  plane
//
//  Created by Ryan Lai on 15/5/19.
//  Copyright (c) 2015年 Ryan Lai. All rights reserved.
//
#ifndef __plane__Hero__
#define __plane__Hero__
#include "Sprite.h"
#include <stdio.h>

class Hero:public Sprite{
public:
    Hero();
    void fire();//开火
    int getLife();//获得生命值
    void heartBeat();//动画
    void LifePlus();//加生命值
    void LifeSub();//减生命值
    int state;//我的飞机状态， 0为正常 其它为被击中
    float heroX,heroY;//我的飞机坐标
    int record;//我的记录
    int bullet_type;//子弹类型
private:
    int life;//生命值
};

#endif