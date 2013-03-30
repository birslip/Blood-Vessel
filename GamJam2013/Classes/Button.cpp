//
//  Button.cpp
//  GameJam2013
//
//  Created by Arthur GUIBERT on 25/01/13.
//
//

#include "Game.h"

using namespace cocos2d;

Button::Button(std::string normalSpriteName, std::string pressedSpriteName, cocos2d::CCSize size)
{
    CCLayer::init();
    
    frame[0] = CCSpriteFrameCache::sharedSpriteFrameCache()->spriteFrameByName(normalSpriteName.c_str());
    frame[1] = CCSpriteFrameCache::sharedSpriteFrameCache()->spriteFrameByName(pressedSpriteName.c_str());
    
    sprite = CCSprite::createWithSpriteFrame(frame[0]);
    addChild(sprite);
    
    this->size = size;
    
    state = NORMAL;
}

Button::~Button()
{
    
}

void Button::update()
{
    auto touches = game()->getTouches();
    
    CCRect rect;
    rect.origin = CCNode::getPosition() - ccp(size.width / 2, size.height / 2);
    rect.size = size;
    
    int oldState = state;
    
    state = NORMAL;
    
    for(auto i=touches.begin();i!=touches.end();i++)
    {
        if(i->second.held && isPointInRect(i->second.position, rect))
        {
            state = PRESSED;
        }
    }
    
    if(state == PRESSED && oldState == NORMAL)
    {
        state = NEWLY_PRESSED;
    }
    else if(state == NORMAL && oldState == PRESSED)
    {
        state = RELEASED;
    }
    
    sprite->setDisplayFrame(state ? frame[1] : frame[0]);
}

int Button::getState()
{
    return state;
}