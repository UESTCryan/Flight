//
//  Texture.h
//  plane
//
//  Created by Ryan Lai on 15/5/19.
//  Copyright (c) 2015年 Ryan Lai. All rights reserved.
//


#ifndef __plane__Texture__
#define __plane__Texture__

#include <SFML/Graphics.hpp>
#include "Texture.h"

class Texture{
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
    static sf::Texture HERO_BROWUP_1;
    static sf::Texture HERO_BROWUP_2;
    static sf::Texture HERO_BROWUP_3;
    static sf::Texture HERO_BROWUP_4;
    
    
    static void load();
};

#endif