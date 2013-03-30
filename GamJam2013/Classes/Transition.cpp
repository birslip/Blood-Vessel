//
//  Transition.cpp
//  GamJam2013
//
//  Created by Arthur GUIBERT on 26/01/13.
//
//

#include "Game.h"

using namespace cocos2d;

Transition::Transition()
{
    CCLayer::init();
    
    opacity = 255;
    target = 0;
    velocity = 0.1;
    
    overlay = CCLayerColor::create({0,0,0,255});
    addChild(overlay);
}

Transition::~Transition()
{
   
    
}

void Transition::update()
{
    opacity += (target - opacity) * velocity;
    
    if(opacity < 5)
    {
        overlay->setVisible(false);
    }
    else
    {
        overlay->setVisible(true);
        overlay->setOpacity(opacity);
    }
}

void Transition::fade(float value)
{
    target = value;
}