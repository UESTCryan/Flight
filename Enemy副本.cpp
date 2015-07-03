//
//  Enemy.cpp
//  plane
//
//  Created by Ryan Lai on 15/5/19.
//  Copyright (c) 2015年 Ryan Lai. All rights reserved.
//

#include "Enemy.h"
#include "Load.h"
#include "Sky.h"
#include <SFML/Audio.hpp>
#include <SFML/Graphics.hpp>
Enemy::Enemy(){
    setTexture(Load::ENEMY);
    time_to_fire = 0;
    state = 0;
    enemyX = rand()%430+10;
    enemyY = 0;
    setPosition(enemyX,enemyY);
    Sky::getInstance()->add(this);
    Sky::getInstance()->addEnemy(this);
    level = Sky::getInstance()->getScore()/10;
}

void Enemy::fire(){
    sf::Vector2f pos = getPosition();
    Bullet* bullet = new Bullet(pos.x+28,pos.y+40);
    bullet->owner_is_hero=0;
    Sky::getInstance()->add(bullet);
    Sky::getInstance()->addEnemyBullet(bullet);
}

void Enemy::heartBeat(){
    float speed = 3 + level;
    move(0,speed);
    enemyY += speed;
    ++time_to_fire %= 50;
    switch (state) {
        case 1:
            setTexture(Load::ENEMY_DOWN_1),state++;
            break;
        case 2:
            setTexture(Load::ENEMY_DOWN_2),state++;
            break;
        case 3:
            setTexture(Load::ENEMY_DOWN_3),state++;
            break;
        case 4:
            setTexture(Load::ENEMY_DOWN_4);
        default:
            if(time_to_fire == 49)
                fire();
            return;
            break;
    }
}