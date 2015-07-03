//
//  Load.h
//  plane
//
//  Created by Ryan Lai on 15/5/21.
//  Copyright (c) 2015年 Ryan Lai. All rights reserved.
//

#ifndef __plane__Load__
#define __plane__Load__
#include <SFML/Graphics.hpp>

class Load{
public:
    static sf::Texture HERO;
    static sf::Texture ENEMY;
    static sf::Texture ENEMY_DOWN_1;
    static sf::Texture ENEMY_DOWN_2;
    static sf::Texture ENEMY_DOWN_3;
    static sf::Texture ENEMY_DOWN_4;
    static sf::Texture BULLET;
    static sf::Texture BULLET1;
    static sf::Texture SKY;
    static sf::Texture AWARD;
    static sf::Texture HERO_BLOWUP_1;
    static sf::Texture HERO_BLOWUP_2;
    static sf::Texture HERO_BLOWUP_3;
    static sf::Texture HERO_BLOWUP_4;
    static sf::Texture GAME_OVER;
    static void loading();//加载文件
};

#endif