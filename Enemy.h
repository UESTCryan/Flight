//
//  Enemy.h
//  plane
//
//  Created by Ryan Lai on 15/5/19.
//  Copyright (c) 2015年 Ryan Lai. All rights reserved.
//

#ifndef __plane__Enemy__
#define __plane__Enemy__
#include "Sprite.h"
#include <stdio.h>
class Enemy:public Sprite{
public:
    Enemy();
    void heartBeat();//动画
    void fire();//开火
    int state;//敌机状态，0为正常，其它为被击中
    float enemyX,enemyY;//敌机坐标
private:
    int time_to_fire;//累加器，用于控制敌机发射子弹
};

#endif