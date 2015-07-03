//
//  Texture.cpp
//  plane
//
//  Created by Ryan Lai on 15/5/19.
//  Copyright (c) 2015年 Ryan Lai. All rights reserved.
//

#include "Texture.h"

sf::Texture Texture::HERO;
sf::Texture Texture::ENEMY;
sf::Texture Texture::ENEMY_DOWN_1;
sf::Texture Texture::ENEMY_DOWN_2;
sf::Texture Texture::ENEMY_DOWN_3;
sf::Texture Texture::ENEMY_DOWN_4;
sf::Texture Texture::BULLET;
sf::Texture Texture::BULLET1;
sf::Texture Texture::SKY;
sf::Texture Texture::HERO_BROWUP_1;
sf::Texture Texture::HERO_BROWUP_2;
sf::Texture Texture::HERO_BROWUP_3;
sf::Texture Texture::HERO_BROWUP_4;

void Texture::load(){
    HERO.loadFromFile("hero1.png");
    ENEMY.loadFromFile("enemy1.png");
    ENEMY_DOWN_1.loadFromFile("enemy1_down1.png");
    ENEMY_DOWN_2.loadFromFile("enemy1_down2.png");
    ENEMY_DOWN_3.loadFromFile("enemy1_down3.png");
    ENEMY_DOWN_4.loadFromFile("enemy1_down4.png");
    HERO_BROWUP_1.loadFromFile("hero_blowup_n1.png");
    HERO_BROWUP_2.loadFromFile("hero_blowup_n2.png");
    HERO_BROWUP_3.loadFromFile("hero_blowup_n3.png");
    HERO_BROWUP_4.loadFromFile("hero_blowup_n4.png");
    BULLET.loadFromFile("bullet1.png");
    BULLET1.loadFromFile("bullet2.png");
    SKY.loadFromFile("background.png");
}