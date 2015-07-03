//
//  Sky.h
//  plane
//
//  Created by Ryan Lai on 15/5/19.
//  Copyright (c) 2015年 Ryan Lai. All rights reserved.
//


#ifndef __plane__Sky__
#define __plane__Sky__
#include <SFML/Graphics.hpp>
#include <vector>
#include <unordered_set>
#include "Sprite.h"
#include "Bullet.h"
#include "Enemy.h"
#include "Hero.h"
#include "Award.h"
#include <set>

using namespace std;

class Sky{
public:
    static Sky* getInstance();
    Sky();
    sf::RenderWindow * getwindow();
    void setWindow(sf::RenderWindow * );//获取窗体
    void add(Sprite *);//增加物件
    void addMyBullet(Bullet *);//增加我的子弹
    void addEnemyBullet(Bullet *);//增加敌机的子弹
    void addEnemy(Enemy *);//增加敌机
    void addAward(Award *);//增加敌机
    void refresh();//刷新
    int getScore();//get分数
    void resetScore();//清零分数
    Hero * myHero;//指向我的飞机的指针
private:
    unordered_set<Sprite *> sprites;//物件集合
    unordered_set<Enemy *> enemies;//敌机集合
    unordered_set<Award *> awards;//奖励集合
    unordered_set<Bullet *> myBullets;//我的子弹集合
    unordered_set<Bullet *> enemyBullets;//敌机子弹集合
    sf::RenderWindow * myWindow;//指向窗体的指针
    static Sky* instance;
    int score;//得分
    void clear();//清除物件，如被击中的敌机、击中的子弹以及超出边界的子弹和敌机
};

#endif