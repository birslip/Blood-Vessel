//
//  Stars.cpp
//  GamJam2013
//
//  Created by Arthur GUIBERT on 26/01/13.
//
//

#include "Game.h"

using namespace cocos2d;

Stars::Stars()
{
    // Parallax effect layer :)
    CCLayer::init();
    
    sprite[0][0] = CCSprite::createWithSpriteFrameName("scenario_stars_pattern_01.png");
    sprite[0][1] = CCSprite::createWithSpriteFrameName("scenario_stars_pattern_01.png");
    
    sprite[1][0] = CCSprite::createWithSpriteFrameName("scenario_stars_pattern_02.png");
    sprite[1][1] = CCSprite::createWithSpriteFrameName("scenario_stars_pattern_02.png");
    
    sprite[2][0] = CCSprite::createWithSpriteFrameName("scenario_stars_pattern_03.png");
    sprite[2][1] = CCSprite::createWithSpriteFrameName("scenario_stars_pattern_03.png");
    
    for(int i=0;i<3;i++)
    {
        sprite[i][0]->setAnchorPoint(ccp(0,0));
        sprite[i][1]->setAnchorPoint(ccp(0,0));
        addChild(sprite[i][0]);
        addChild(sprite[i][1]);
    }
    
    velocity[2] = 2.0;
    velocity[1] = 1.5;
    velocity[0] = 1;
    
    frameCount = 0;
}


Stars::~Stars()
{
    
}

void Stars::update()
{
    for(int i=0;i<3;i++)
    {
        int position = ((int)(frameCount * velocity[i])) % (int)sprite[i][0]->getTextureRect().size.height;
        
        sprite[i][0]->setPositionY(-position + sprite[i][0]->getTextureRect().size.height);
        sprite[i][1]->setPositionY(-position + sprite[i][0]->getTextureRect().size.height * 2);
        
    }
    
    frameCount++;
}