//
//  Particles.cpp
//  GamJam2013
//
//  Created by Arthur GUIBERT on 27/01/13.
//
//

//
//  Particles.cpp
//  magictouch
//
//  Created by Arthur on 16/11/2012.
//
//
#include <functional>
#include "cocos2d.h"
#include "Utils.h"
#include "Animation.h"
#include "Particles.h"

using namespace cocos2d;

ParticleDef::ParticleDef()
{
    position = ccp(0,0);
    speed = ccp(0,0);
    acceleration = ccp(0,0);
    
    color = ccWHITE;
    targetColor = ccWHITE;
    
    groundFriction = 1;
    friction = 1;
    radius = 0;
    bounce = 0;
    
    scale = 1;
    deltaScale = 0;
    
    opacity = 255;
    deltaOpacity = 0;
    
    angle = 0;
    deltaAngle = 0;
    
    life = -1;
    animationOffset = 0;
    
    colliding = false;
    changeColor = false;
}

Particle::~Particle()
{
    
}

Particles::Particles()
{
    maxParticles = 0;
    useCallback = false;
    rect = CCRectMake(0, 0, 0, 0);
}

Particles::~Particles()
{
    delete [] particle;
}

void Particles::init(cocos2d::CCNode *parent, int maxParticles, int zOrder)
{
    this->maxParticles = maxParticles;
    
    particle = new Particle[maxParticles];
    
    batch = CCSpriteBatchNode::create("atlas.png", maxParticles);
    parent->addChild(batch, zOrder);
    
    for(int i=0;i<maxParticles;i++)
    {
        // Init sprite
        particle[i].sprite = CCSprite::createWithSpriteFrameName("ge_particles.png");
        particle[i].sprite->setVisible(false);
        batch->addChild(particle[i].sprite);
        
        // Init physics
        particle[i].position = ccp(0,0);
        particle[i].speed = ccp(0,0);
        particle[i].acceleration = ccp(0,0);
        particle[i].friction = 1;
        
        // Set default parameters
        particle[i].anim = NULL;
        
        particle[i].color = ccWHITE;
        particle[i].targetColor = ccWHITE;
        
        particle[i].scale = 1;
        particle[i].deltaScale = 0;
        
        particle[i].opacity = 255;
        particle[i].deltaOpacity = 0;
        
        particle[i].angle = 0;
        particle[i].deltaAngle = 0;
        
        particle[i].life = -1;
        particle[i].frameCount = 0;
        particle[i].duration = 1;
        
        particle[i].animationOffset = 0;
        
        particle[i].colliding = false;
        particle[i].changeColor = false;
    }
}

void Particles::update(float dt)
{
    for(int i=0;i<maxParticles;i++)
    {
        if(particle[i].life >= 0)
        {
            if(useCallback)
            {
                (callback)(&particle[i]);
            }
            
            particle[i].speed *= particle[i].friction;
            particle[i].speed += particle[i].acceleration * dt;
            particle[i].position += particle[i].speed;
            
            
            particle[i].scale += particle[i].deltaScale * dt;
            particle[i].opacity += particle[i].deltaOpacity * dt;
            particle[i].angle += particle[i].deltaAngle * dt;
            
            if(particle[i].anim)
            {
                particle[i].anim->animate(particle[i].sprite, particle[i].frameCount + particle[i].animationOffset);
            }
            
            if(particle[i].changeColor)
            {
                ccColor3B c;
                float t = (particle[i].duration - particle[i].life) / particle[i].duration;
                c.r = particle[i].targetColor.r * t + (1.0f - t) * particle[i].color.r;
                c.g = particle[i].targetColor.g * t + (1.0f - t) * particle[i].color.g;
                c.b = particle[i].targetColor.b * t + (1.0f - t) * particle[i].color.b;
                
                particle[i].sprite->setColor(c);
            }
            
            particle[i].sprite->setOpacity(particle[i].opacity);
            particle[i].sprite->setScale(particle[i].scale);
            particle[i].sprite->setRotation(particle[i].angle);
            particle[i].sprite->setPosition(particle[i].position);
            
            particle[i].life -= dt;
            particle[i].frameCount += dt;
            
            if(particle[i].life < 0)
            {
                particle[i].sprite->setVisible(false);
            }
        }
    }
}

Particle* Particles::add(ParticleDef &def)
{
    for(int i=0;i<maxParticles;i++)
    {
        if(particle[i].life < 0)
        {
            particle[i].position = def.position;
            particle[i].speed = def.speed;
            particle[i].acceleration = def.acceleration;
            particle[i].friction = def.friction;
            
            particle[i].color = def.color;
            
            particle[i].scale = def.scale;
            particle[i].deltaScale = def.deltaScale;
            
            particle[i].opacity = def.opacity;
            particle[i].deltaOpacity = def.deltaOpacity;
            
            particle[i].angle = def.angle;
            particle[i].deltaAngle = def.deltaAngle;
            
            particle[i].life = def.life;
            particle[i].duration = def.life;
            particle[i].frameCount = 0;
            
            particle[i].animationOffset = def.animationOffset;
            
            particle[i].colliding = def.colliding;
            particle[i].changeColor = def.changeColor;
            
            particle[i].sprite->setColor(particle[i].color);
            particle[i].sprite->setPosition(particle[i].position);
            particle[i].sprite->setVisible(true);
            
            return &particle[i];
        }
    }
    
    return NULL;
}

void Particles::add(cocos2d::CCSpriteFrame *spriteFrame, ParticleDef &def)
{
    Particle* p = add(def);
    
    if(p)
    {
        p->sprite->setDisplayFrame(spriteFrame);
        p->anim = NULL;
    }
}

void Particles::add(Animation *animation, ParticleDef &def)
{
    Particle* p = add(def);
    
    if(p)
    {
        // Setting the first frame of the animation so as to avoid glitches
        animation->animate(p->sprite, 0);
        p->anim = animation;
    }
}

void Particles::setBoundingBox(int x, int y, int w, int h)
{
    rect = CCRectMake(x,y, w, h);
}

void Particles::setVisible(bool visible)
{
    batch->setVisible(visible);
}

void Particles::setCallbackFunction(const std::function<void (Particle *)> &callback)
{
    useCallback = true;
    this->callback = callback;
}

void Particles::disableCallbackFunction()
{
    useCallback = false;
}
