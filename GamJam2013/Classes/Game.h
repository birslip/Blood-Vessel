//
//  Game.h
//  GamJam2013
//
//  Created by Arthur GUIBERT on 26/01/13.
//
//

#ifndef __GamJam2013__Game__
#define __GamJam2013__Game__

#include "cocos2d.h"
#include "Utils.h"
#include "NumberLabel.h"
#include "Camera.h"
#include "Animation.h"
#include "Button.h"
#include "Level.h"
#include "Stripes.h"
#include "Stars.h"
#include "Transition.h"
#include "TitleScreen.h"
#include "EndScreen.h"
#include "Particles.h"

struct TouchInformation
{
    cocos2d::CCPoint position;
    cocos2d::CCPoint lastPosition;
    
    bool released;
    bool newPress;
    bool held;
    bool enabled;
    
    bool oldHeldValue;
    
    struct
    {
        float x,y,z;
    } acceleration;
    
    unsigned int touchId;
};

extern TouchInformation finger;

class Game : public cocos2d::CCLayer
{
public:
    Game();
    ~Game();
    
    virtual bool init();
    virtual void update(float dt);
    
    void reset();
    void startGame();
    void ending(int score);
    void menu();
    
    // Touches
    virtual void registerWithTouchDispatcher();
    
    virtual void ccTouchesBegan(cocos2d::CCSet *touches, cocos2d::CCEvent *event);
    virtual void ccTouchesMoved(cocos2d::CCSet *touches, cocos2d::CCEvent *event);
    virtual void ccTouchesEnded(cocos2d::CCSet *touches, cocos2d::CCEvent *event);
    virtual void ccTouchesCancelled(cocos2d::CCSet *touches, cocos2d::CCEvent *event);
    virtual void didAccelerate(cocos2d::CCAcceleration* pAccelerationValue);
    
    void updateTouches();
    std::map<unsigned int, TouchInformation> getTouches() { return touch; }
    
protected:
    cocos2d::CCLayer* currentStage;
    
    cocos2d::CCPoint touchOffset;
    
    // Pixel love <3
    float scaleFactor;
    
    cocos2d::CCSprite* sprite;
    cocos2d::CCRenderTexture *rt;
    
    // Multitouch
    std::map<unsigned int, TouchInformation> touch;
};


Game* game();


#endif /* defined(__GamJam2013__Game__) */
