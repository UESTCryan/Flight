//
//  main.cpp
//  plane
//
//  Created by Ryan Lai on 15/5/21.
//  Copyright (c) 2015年 Ryan Lai. All rights reserved.
//
#include <SFML/Audio.hpp>
#include <SFML/Graphics.hpp>
#include <fstream>
#include <iostream>
#include "Sprite.h"
#include "Hero.h"
#include "Load.h"
#include "Sky.h"
#include <unistd.h>
#include "Award.h"
int main(){
    restart://重新开始
    sf::RenderWindow window(sf::VideoMode(480, 800), L"Thunder Raid - 打飞机");//主窗体创建
    Load::loading();//文件加载
    window.setFramerateLimit(60);//帧率设置
    sf::Event event,event_over;
    sf::Music Fire;
    sf::Font font;
    Fire.openFromFile("bullet.ogg");
    sf::Sprite setBackground(Load::SKY);//背景
    Hero hero;//创建我的飞机
    Sky * sky = Sky::getInstance();
    sky->setWindow(&window);
    sky->add(&hero);
    sky->myHero=&hero;
    sky->resetScore();//清零得分
    int times = 0;//计数器，用于控制敌机出现频率
    int times_award = 0;
    window.draw(hero);//显示我的飞机
    ifstream input("record.txt");//读取纪录
    input>>hero.record;
    while(window.isOpen()){
        times++;
        times_award++;
        
        times %= 50;
        times_award %= 500;
        
        if(times == 49){
            Enemy * enemy;
            enemy = new Enemy ;
        }//每累加50次 生成一架敌机
        
        if(times_award == 499){
            Award * award;
            award = new Award;
        }
        while(window.pollEvent(event)){
            if(event.type == sf::Event::Closed || (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Escape) || sky->myHero->getLife() <= 0){
                input.close();
                ofstream output("record.txt");
                output<<hero.record;
                window.close();//退出游戏
            }
            if(event.type == sf::Event::KeyPressed){
                if(event.key.code == sf::Keyboard::Left && hero.heroX>=10)
                    hero.heroX -= 20;
                if(event.key.code == sf::Keyboard::Right && hero.heroX<=370)
                    hero.heroX += 20;
                if(event.key.code == sf::Keyboard::Up && hero.heroY>=5)
                    hero.heroY -= 20;
                if(event.key.code == sf::Keyboard::Down && hero.heroY<=580)
                    hero.heroY += 20;
                //操作我的飞机
                if(event.key.code == sf::Keyboard::Space)
                    Fire.play(),hero.fire();
                //控制我的飞机开火
            }
            hero.setPosition(hero.heroX,hero.heroY);//更新我的飞机坐标
        }
        window.clear();
        window.draw(setBackground);
        sky->refresh();        
        //更新状态
    }
    if(!sky->myHero->getLife()){
        
        sf::RenderWindow gameOverWindow(sf::VideoMode(300, 80), L"Game Over!");
        font.loadFromFile("sansation.ttf");
        sf::Text text("Game Over!", font, 50);
        text.setPosition(30, 0);
        gameOverWindow.draw(text);
        gameOverWindow.display();
        sleep(3);
        gameOverWindow.close();
        goto restart;
        //生命用完 重新开始游戏
        /*window.pollEvent(event_over);
        sf::Sprite game_over(Load::GAME_OVER);
        while (event_over.type != sf::Event::KeyPressed) {
            window.draw(game_over);
            sleep(3);
        }
        goto restart;*/

    }
    return 0;
}
//STARUML