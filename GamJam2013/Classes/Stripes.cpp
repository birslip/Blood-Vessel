//
//  Stripes.cpp
//  GameJam2013
//
//  Created by Arthur GUIBERT on 25/01/13.
//
//

#include "Game.h"

using namespace cocos2d;

Stripes::Stripes(Level* level)
{
    parent = level;
    ratio = 0.04;
    currentType = -1;
    offset = ccp(0,144);
    length = 0;
    viewLength = 20000;
    
    color[0] = ccRED;
    color[1] = ccBLUE;
    color[2] = ccYELLOW;
    color[3] = {255,0,255};
    color[4] = ccORANGE;
    color[5] = ccGREEN;
    color[6] = ccWHITE;
    
    stripeFrame[0] = CCSpriteFrameCache::sharedSpriteFrameCache()->spriteFrameByName("stripe.png");
    stripeFrame[1] = CCSpriteFrameCache::sharedSpriteFrameCache()->spriteFrameByName("ge_noise_belt_01.png");
    
    noise = new Animation("ge_noise_belt_01:3,ge_noise_belt_02:3,ge_noise_belt_03:3,ge_noise_belt_04:3");
}

Stripes::~Stripes()
{
    list.clear();
}

void Stripes::update(double timeOffset)
{
    currentType = -1;
    
    double t = parent->getElapsedTime() + timeOffset;
    
    for(int i=0;i<list.size();i++)
    {
        float l;
            
        if(i == list.size() - 1)
        {
            l = length - list[i].startTime;
        }
        else
        {
            l = list[i + 1].startTime - list[i].startTime;
        }
        
        bool shipOnStripe = false;
        
        if(list[i].startTime <= t && list[i].startTime + l >= t)
        {
            currentType = list[i].type;
            currentId = i;
            parent->setCurrentStripeType(currentType);
            parent->setCurrentStripeId(currentId);
            shipOnStripe = true;
        }
        
        if(list[i].startTime > t - length && length < t + viewLength)
        {
            CCSprite* sprite = parent->getStripeSprite();
            
            if(sprite == NULL)
                break;
            
            sprite->setVisible(true);
            sprite->setPositionY((list[i].startTime - t) * ratio + offset.y);
        
            if(shipOnStripe)
            {
                sprite->setOpacity(255);
            }
            else if(parent->getLife() <= 3)
            {
                sprite->setOpacity(160 - (4 -parent->getLife()) * 24);
            }
            else
            {
                sprite->setOpacity(160);
            }
            
            sprite->setScaleY((l * ratio - 2)/ 12.0f);
            
            if(list[i].type < NOISE)
            {
                if(list[i].type == parent->getNewlyPressedColor() && shipOnStripe)
                {
                    sprite->setColor(ccWHITE);
                }
                else
                {
                    sprite->setColor(color[list[i].type]);
                }
                
                sprite->setDisplayFrame(stripeFrame[0]);
            }
            else if(list[i].type == NOISE)
            {
                noise->animate(sprite, parent->getFramecount());
                
                if(parent->shoudHideNoise(i))
                {
                    sprite->setVisible(false);
                }
                
                CCRect rect = sprite->getTextureRect();
                rect.size.height = (l * ratio - 2);
                sprite->setTextureRect(rect);
                sprite->setScale(1);
                sprite->setColor(ccWHITE);
            }
        }
    }
}

void Stripes::add(Stripe s)
{
    list.push_back(s);
}