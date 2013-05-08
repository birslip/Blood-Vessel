//
//  Camera.cpp
//  GamJam2013
//
//  Created by Arthur GUIBERT on 26/01/13.
//
//

#include "Game.h"

using namespace cocos2d;

Camera::Camera(float velocity, float damping)
    : velocity(velocity), damping(damping)
{
    speed = ccp(0,0);
    position = ccp(0,0);
    target = ccp(0,0);
    offset = ccp(0,0);
    epsilon = 0.2;
    easing = 0.25;
    targetEnabled = false;
}

Camera::~Camera()
{
    
}

void Camera::update()
{
    if(targetEnabled)
    {
        updatePosition();
    }
    
    updateShake();
}

void Camera::updatePosition()
{
    CCPoint diff = target - position;
    
    position += diff * easing;
    
    if(ccpLength(diff) < epsilon)
    {
        targetEnabled = false;
        position = target;
    }
}

void Camera::updateShake()
{
    speed.x = speed.x * damping - offset.x * velocity;
    offset.x += speed.x;
    
    if (fabs(speed.x) < epsilon)
    {
        speed.x = 0;
        offset.x = 0;
    }
    
    speed.y = speed.y * damping - offset.y * velocity;
    offset.y += speed.y;
    
    if (fabs(speed.y) < epsilon)
    {
        speed.y = 0;
        offset.y = 0;
    }
}

void Camera::shake(float x, float y)
{
    speed.x = x;
    speed.y = y;
    offset = ccp(0,0);
}

void Camera::setTarget(cocos2d::CCPoint p)
{
    target = p;
    targetEnabled = true;
}

cocos2d::CCPoint Camera::getPosition()
{
    return position + offset;
}

cocos2d::CCPoint Camera::getOffset()
{
    return offset;
}