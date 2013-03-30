//
//  EndScreen.cpp
//  GamJam2013
//
//  Created by Arthur GUIBERT on 26/01/13.
//
//

#include "Game.h"

using namespace cocos2d;

EndScreen::EndScreen(int score)
{
    CCLayer::init();
    
    sprite = CCSprite::createWithSpriteFrameName("gui_retry_OVER.png");
    sprite->setAnchorPoint(ccp(0,0));
    addChild(sprite);
    
    std::string str = toString(score);
    
    NumberLabel* label = NumberLabel::create(score, "gui_font_");
    label->setPosition(ccp(65,138));
    label->setAlign(NumberLabel::ALIGN_RIGHT);
    addChild(label);
    
    transition = new Transition();
    addChild(transition);
    
    retryCount = -1;
}

EndScreen::~EndScreen()
{
    
}

void EndScreen::update(float dt)
{
    
    if(retryCount == 30)
    {
        game()->menu();
            
        return;
    }
    
    transition->update();
    
    if(retryCount >= 0)
    {
        
        
        retryCount++;
    }
    else
    {
        if(finger.held)
        {
            sprite->setDisplayFrame(CCSpriteFrameCache::sharedSpriteFrameCache()->spriteFrameByName("gui_retry_OVER.png"));
        }
        else
        {
            sprite->setDisplayFrame(CCSpriteFrameCache::sharedSpriteFrameCache()->spriteFrameByName("gui_retry_UP.png"));
        }
        
        if(finger.released)
        {
            retryCount = 0;
            transition->fade(255);
        }
    }
    
}