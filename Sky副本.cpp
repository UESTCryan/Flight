//
//  Sky.cpp
//  plane
//
//  Created by Ryan Lai on 15/5/19.
//  Copyright (c) 2015年 Ryan Lai. All rights reserved.
//
#include "Sky.h"
#include "Award.h"
#include <set>

sf::Music boom;
Sky* Sky::instance = nullptr;
sf::Font font;
sf::Text text("Score: ", font, 30);
sf::Text text_life("Life: ", font, 30);
sf::Text text_record("Record: ", font, 30);
sf::Text text_level("Level: ", font, 30);


Sky::Sky(){
    score = 0;
    boom.openFromFile("enemy1_down.ogg");//加载敌机爆炸音乐
    font.loadFromFile("sansation.ttf");//加载字体
}

Sky* Sky::getInstance(){
    if(!instance){
        instance = new Sky;
    }
    return instance;
}

void Sky::setWindow(sf::RenderWindow * t){
        myWindow = t;
}
sf::RenderWindow* Sky::getwindow(){
    return myWindow;
}

void Sky::resetScore(){
    score = 0;
}

int Sky::getScore(){
    return score;
}

void Sky::add(Sprite* sprite){
    sprites.insert(sprite);
}

void Sky::addMyBullet(Bullet * bullet){
    myBullets.insert(bullet);
}

void Sky::addEnemyBullet(Bullet * bullet){
    enemyBullets.insert(bullet);
}

void Sky::addEnemy(Enemy * enemy){
    enemies.insert(enemy);
}

void Sky::addAward(Award * award){
    awards.insert(award);
}

void Sky::refresh(){
    text.setPosition(300, 10);
    getwindow()->draw(text);
    text_life.setPosition(10, 10);
    getwindow()->draw(text_life);
    text_record.setPosition(285, 40);
    getwindow()->draw(text_record);
    text_level.setPosition(10, 40);
    getwindow()->draw(text_level);
    
    char k;
    k = getScore()/100+'0';
    sf::Text num1(k, font, 30);
    num1.setPosition(390, 10);
    getwindow()->draw(num1);
    char k1;
    k1 = (getScore()/10)%10+'0';
    sf::Text num2(k1, font, 30);
    num2.setPosition(410, 10);
    getwindow()->draw(num2);
    char k2;
    k2 = getScore()%10+'0';
    sf::Text num3(k2, font, 30);
    num3.setPosition(430, 10);
    getwindow()->draw(num3);
    
    text_life.setPosition(10, 10);
    char k3;
    k3 = myHero->getLife()+'0';
    sf::Text num4(k3, font, 30);
    num4.setPosition(80, 10);
    getwindow()->draw(num4);
    
    char k4;
    k4 = myHero->level+'0';
    sf::Text num5(k4, font, 30);
    num5.setPosition(100, 40);
    getwindow()->draw(num5);
    
    if(getScore()>=myHero->record){
        char k;
        k = getScore()/100+'0';
        sf::Text num1(k, font, 30);
        num1.setPosition(390, 40);
        getwindow()->draw(num1);
        char k1;
        k1 = (getScore()/10)%10+'0';
        sf::Text num2(k1, font, 30);
        num2.setPosition(410, 40);
        getwindow()->draw(num2);
        char k2;
        k2 = getScore()%10+'0';
        sf::Text num3(k2, font, 30);
        num3.setPosition(430, 40);
        getwindow()->draw(num3);
        myHero->record = getScore();
    }
    else{
        char k;
        k = myHero->record/100+'0';
        sf::Text num1(k, font, 30);
        num1.setPosition(390, 40);
        getwindow()->draw(num1);
        char k1;
        k1 = (myHero->record/10)%10+'0';
        sf::Text num2(k1, font, 30);
        num2.setPosition(410, 40);
        getwindow()->draw(num2);
        char k2;
        k2 = myHero->record%10+'0';
        sf::Text num3(k2, font, 30);
        num3.setPosition(430, 40);
        getwindow()->draw(num3);
        
    }
    int old_level = myHero->level;
    if(getScore()/10<=2)
        myHero->level = 1;
    if(2<getScore()/10 && getScore()/10<=5){
        myHero->level = 2;
    }
    if(getScore()/10>5)
        myHero->level = 3;
    //if(old_level != myHero->level)
    //    myHero->level_up = true;
    
  //  if(myHero->level_up){
        
   // }//  未完成
    
    
    
    clear();
    for(auto &sprite : sprites){
        sprite->heartBeat();
        myWindow->draw(*sprite);
    }
    myWindow->display();
}

void Sky::clear(){
    for(auto it_enemy = enemies.begin();it_enemy != enemies.end();++it_enemy){
        if((*it_enemy)->enemyY >= 800 || (*it_enemy)->state >= 4){
            sprites.erase(*it_enemy);
            enemies.erase(*it_enemy);
            continue;
        }
    }
    for(auto it_enemy = enemies.begin();it_enemy != enemies.end();++it_enemy){
        if( myHero->heroX >= (*it_enemy)->enemyX-80 && myHero->heroX  <= (*it_enemy)->enemyX+40 &&
            myHero->heroY >= (*it_enemy)->enemyY-90 && myHero->heroY  <= (*it_enemy)->enemyY+20 && (*it_enemy)->state == 0 &&myHero->state == 0) {
            (*it_enemy)->state++;
            myHero->state = 1;
            boom.play();
            myHero->LifeSub();
            continue;
        }
    }
    
    for(auto it_enemyBullet = enemyBullets.begin();it_enemyBullet != enemyBullets.end();++it_enemyBullet){
        if(  myHero->heroX >= (*it_enemyBullet)->bulletX-90 && myHero->heroX  <= (*it_enemyBullet)->bulletX &&
             myHero->heroY >= (*it_enemyBullet)->bulletY    && myHero->heroY  <= (*it_enemyBullet)->bulletY+10 && myHero->state == 0  ) {
            myHero->state = 1;
            myHero->LifeSub();
            sprites.erase(*it_enemyBullet);
            enemyBullets.erase(*it_enemyBullet);
            boom.play();
            continue;

        }
    }
    
    for(auto it_award = awards.begin();it_award != awards.end();++it_award){
        if(  myHero->heroX >= (*it_award)->AwardX-100 && myHero->heroX  <= (*it_award)->AwardX &&
           myHero->heroY >= (*it_award)->AwardY    && myHero->heroY  <= (*it_award)->AwardY+20 && myHero->state == 0  ) {
            //未完成
            
            
            sprites.erase(*it_award);
            awards.erase(*it_award);
            continue;
            
        }
    }
    
    
    
    
    for(auto it_bullet = myBullets.begin();it_bullet != myBullets.end();++it_bullet){
        if((*it_bullet)->bulletY<=-10){
            sprites.erase(*it_bullet);
            myBullets.erase(*it_bullet);
            continue;

        }
    }
    for(auto it_bullet = enemyBullets.begin();it_bullet != enemyBullets.end();++it_bullet){
        if((*it_bullet)->bulletY>=800){
            sprites.erase(*it_bullet);
            enemyBullets.erase(*it_bullet);
            continue;
            
        }
    }
    
    for(auto it_award = awards.begin();it_award != awards.end();++it_award){
        if((*it_award)->AwardY>=800){
            sprites.erase(*it_award);
            awards.erase(*it_award);
            continue;
            
        }
    }
    
    for(auto it_enemy = enemies.begin();it_enemy != enemies.end();++it_enemy){
        for(auto it_bullet = myBullets.begin();it_bullet != myBullets.end();++it_bullet){
            if( (*it_bullet)->bulletX >= (*it_enemy)->enemyX && (*it_bullet)->bulletX <= (*it_enemy)->enemyX+50 && (*it_bullet)->bulletY <= (*it_enemy)->enemyY+5 && (*it_enemy)->state == 0){
                score += 1;
                (*it_enemy)->state++;
                boom.play();
                sprites.erase(*it_bullet);
                myBullets.erase(it_bullet);
                continue;
            }
        }
    }
}
