//
//  Hero.cpp
//  plane
//
//  Created by Ryan Lai on 15/5/19.
//  Copyright (c) 2015年 Ryan Lai. All rights reserved.
//

#include "Hero.h"
#include "Load.h"
#include "Bullet.h"
#include "Sky.h"
Hero::Hero(){
    life = 3;
    setTexture(Load::HERO);
    setPosition(190, 590);
    heroX = 190;
    heroY = 590;
    state = 0;
    level = 0;
}

int Hero::getLife(){
    return life;
}

void Hero::heartBeat(){
    switch (state) {
        case 0:
            setTexture(Load::HERO);
            break;
        case 5:
            setTexture(Load::HERO_BLOWUP_1),state++;
            break;
        case 15:
            setTexture(Load::HERO_BLOWUP_2),state++;
            break;
        case 20:
            setTexture(Load::HERO_BLOWUP_3),state++;
            break;
        case 25:
            setTexture(Load::HERO_BLOWUP_4),state++;
            break;
        default:
            ++state %= 25;
            break;
    }
}

void Hero::LifeSub(){
    life--;
}

void Hero::LifePlus(){
    life++;
}

void Hero::fire(){
    sf::Vector2f pos = getPosition();
    if(bullet_type == 0){
        Bullet* bullet = new Bullet(pos.x+50,pos.y+30);
        Sky::getInstance()->add(bullet);
        Sky::getInstance()->addMyBullet(bullet);
    }
    
    if(bullet_type == 1){
        Bullet* bullet = new Bullet(pos.x+50,pos.y+30);
        Sky::getInstance()->add(bullet);
        Sky::getInstance()->addMyBullet(bullet);
        
        bullet = new Bullet(pos.x+15,pos.y+30);
        Sky::getInstance()->add(bullet);
        Sky::getInstance()->addMyBullet(bullet);
        
        bullet = new Bullet(pos.x+80,pos.y+30);
        Sky::getInstance()->add(bullet);
        Sky::getInstance()->addMyBullet(bullet);
    }
    
    
    
}





