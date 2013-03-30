//
//  Game.cpp
//  GamJam2013
//
//  Created by Arthur GUIBERT on 26/01/13.
//
//

#include "Game.h"

using namespace cocos2d;

// Global
static Game* currentGame = NULL;

TouchInformation finger;

Game::Game()
{
    currentGame = this;
    
    CCSpriteFrameCache::sharedSpriteFrameCache()->addSpriteFramesWithFile("atlas.plist", "atlas.png");
}

Game::~Game()
{
    
}

bool Game::init()
{
    // Init layer
    CCLayer::init();
    
    // Init system
   
    scaleFactor = 1;
    
    
    // We render the game in a frame twice as small as the ipad screen and then scale it to fit
    CCSize size = CCDirector::sharedDirector()->getWinSizeInPixels();
   
    scaleFactor = 160.0f / size.width;
    
    if(size.width == 768)
    {
        // iPad!
        scaleFactor = 160.0f / 684.0f;
    }
    
    
    rt = CCRenderTexture::create(160, 240);
    rt->retain();
    sprite = CCSprite::createWithTexture(rt->getSprite()->getTexture());
    
    sprite->getTexture()->setAliasTexParameters();
    
    sprite->setAnchorPoint(ccp(0,0));
    sprite->setScale(1.0f / scaleFactor);
    sprite->setPosition(ccp(0,0));
    
    touchOffset = ccp(0,0);
    if(size.width == 768)
    {
        // Ipad
        sprite->setPositionX(768 / 2 - 684 / 2);
        touchOffset = ccp(768 / 2 - 684 / 2, 0) * (-1);
    }
    
    sprite->setFlipY(true);
    sprite->retain();
    addChild(sprite);
    
    currentStage = new TitleScreen();
    
    setAccelerometerEnabled(true);
    scheduleUpdate();
    setTouchEnabled(true);
    
    return true;
}


void Game::update(float dt)
{
    
    currentStage->update(dt);
    
    rt->beginWithClear(46.0 / 255.0f, 26.0f / 255.0f, 41.0f / 255.0f, 1);
        currentStage->visit();
    rt->end();
    
    finger.newPress = false;
    
    if(!finger.held && finger.oldHeldValue)
    {
        finger.released = true;
    }
    else
    {
        finger.released = false;
    }
    
    finger.oldHeldValue = finger.held;
}

void Game::reset()
{
    currentStage->removeAllChildrenWithCleanup(true);
    delete currentStage;
    currentStage = new Level();
}

void Game::ending(int score)
{
    currentStage->removeAllChildrenWithCleanup(true);
    delete currentStage;
    currentStage = new EndScreen(score);
}

void Game::startGame()
{
    currentStage->removeAllChildrenWithCleanup(true);
    delete currentStage;
    currentStage = new Level();
}

void Game::menu()
{
    currentStage->removeAllChildrenWithCleanup(true);
    delete currentStage;
    currentStage = new TitleScreen();
}

void Game::updateTouches()
{
    finger.held = false;
    
    for(auto i = touch.begin();i!=touch.end();i++)
    {
        finger = i->second;
    }
    
    for(auto i = touch.begin();i!=touch.end();i++)
    {
        i->second.lastPosition = i->second.position;
        i->second.newPress = false;
        i->second.released = false;
        
        if(!i->second.enabled)
        {
            touch.erase(i);
            break;
        }
    }
}

void Game::registerWithTouchDispatcher()
{
    CCDirector::sharedDirector()->getTouchDispatcher()->addStandardDelegate(this, 0);
}

void Game::ccTouchesBegan(cocos2d::CCSet *touches, cocos2d::CCEvent *event)
{
    int touchCount = 0;
    
    for(CCSetIterator i = touches->begin(); i != touches->end(); i ++)
    {
        CCTouch* t = (CCTouch*)(*i);
        CCPoint location = t->getLocationInView();
        location = CCDirector::sharedDirector()->convertToGL(location);
        
        location += touchOffset;
        
        TouchInformation f;
        f.newPress = true;
        f.lastPosition = location * scaleFactor;
        f.position = location * scaleFactor;
        f.held = true;
        f.released = false;
        f.enabled = true;
        
        touch[t->m_uID] = f;
        
        touchCount++;
    }
    
    updateTouches();
}

void Game::ccTouchesMoved(cocos2d::CCSet *touches, cocos2d::CCEvent *event)
{
    int touchCount = 0;
    
    for(CCSetIterator i = touches->begin(); i != touches->end(); i ++)
    {
        CCTouch* t = (CCTouch*)(*i);
        CCPoint location = t->getLocationInView();
        location = CCDirector::sharedDirector()->convertToGL(location);
        
        location += touchOffset;
        
        touch[t->m_uID].position = location * scaleFactor;
        touch[t->m_uID].held = true;
        touch[t->m_uID].newPress = false;
        touch[t->m_uID].released = false;
        touch[t->m_uID].enabled = true;
        
        touchCount++;
    }
    
    
    updateTouches();
}

void Game::ccTouchesEnded(cocos2d::CCSet *touches, cocos2d::CCEvent *event)
{
    int touchCount = 0;
    
    for(CCSetIterator i = touches->begin(); i != touches->end(); i ++)
    {
        CCTouch* t = (CCTouch*)(*i);
        CCPoint location = t->getLocationInView();
        location = CCDirector::sharedDirector()->convertToGL(location);
        
        location += touchOffset;
        
        touch[t->m_uID].position = location * scaleFactor;
        touch[t->m_uID].held = false;
        touch[t->m_uID].newPress = false;
        touch[t->m_uID].released = true;
        touch[t->m_uID].enabled = false;
        
        touchCount++;
    }
    
    updateTouches();
}

void Game::ccTouchesCancelled(cocos2d::CCSet *touches, cocos2d::CCEvent *event)
{
    int touchCount = 0;
    
    for(CCSetIterator i = touches->begin(); i != touches->end(); i ++)
    {
        CCTouch* t = (CCTouch*)(*i);
        CCPoint location = t->getLocationInView();
        location = CCDirector::sharedDirector()->convertToGL(location);
        
        location += touchOffset;
        
        touch[t->m_uID].position = location * scaleFactor;
        touch[t->m_uID].held = false;
        touch[t->m_uID].newPress = false;
        touch[t->m_uID].released = true;
        touch[t->m_uID].enabled = false;
        
        touchCount++;
    }
    
    updateTouches();
}

void Game::didAccelerate(CCAcceleration* pAccelerationValue)
{
    finger.acceleration.x = pAccelerationValue->x;
    finger.acceleration.y = pAccelerationValue->y;
    finger.acceleration.z = pAccelerationValue->z;
}

Game* game()
{
    return currentGame;
}