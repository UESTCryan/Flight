//
//  Load.cpp
//  plane
//
//  Created by Ryan Lai on 15/5/21.
//  Copyright (c) 2015年 Ryan Lai. All rights reserved.
//

#include "Load.h"
#include <SFML/Audio.hpp>
#include <SFML/Graphics.hpp>
sf::Music bgm;
sf::Texture Load::HERO;
sf::Texture Load::ENEMY;
sf::Texture Load::ENEMY_DOWN_1;
sf::Texture Load::ENEMY_DOWN_2;
sf::Texture Load::ENEMY_DOWN_3;
sf::Texture Load::ENEMY_DOWN_4;
sf::Texture Load::BULLET;
sf::Texture Load::BULLET1;
sf::Texture Load::SKY;
sf::Texture Load::AWARD;
sf::Texture Load::GAME_OVER;
sf::Texture Load::HERO_BLOWUP_1;
sf::Texture Load::HERO_BLOWUP_2;
sf::Texture Load::HERO_BLOWUP_3;
sf::Texture Load::HERO_BLOWUP_4;

void Load::loading(){
    bgm.openFromFile("BGM.ogg");//背景音乐加载
    bgm.play();
    HERO.loadFromFile("hero1.png");
    ENEMY.loadFromFile("enemy1.png");
    ENEMY_DOWN_1.loadFromFile("enemy1_down1.png");
    ENEMY_DOWN_2.loadFromFile("enemy1_down2.png");
    ENEMY_DOWN_3.loadFromFile("enemy1_down3.png");
    ENEMY_DOWN_4.loadFromFile("enemy1_down4.png");
    HERO_BLOWUP_1.loadFromFile("hero_blowup_n1.png");
    HERO_BLOWUP_2.loadFromFile("hero_blowup_n2.png");
    HERO_BLOWUP_3.loadFromFile("hero_blowup_n3.png");
    HERO_BLOWUP_4.loadFromFile("hero_blowup_n4.png");
    BULLET.loadFromFile("bullet1.png");
    BULLET1.loadFromFile("bullet2.png");
    AWARD.loadFromFile("ufo1.png");
    GAME_OVER.loadFromFile("game_over.png");
    SKY.loadFromFile("background.png");//图片文件加载
}