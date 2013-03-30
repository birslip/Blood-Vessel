//
//  EndScreen.h
//  GamJam2013
//
//  Created by Arthur GUIBERT on 26/01/13.
//
//

#ifndef __GamJam2013__EndScreen__
#define __GamJam2013__EndScreen__

class EndScreen : public cocos2d::CCLayer
{
public:
    EndScreen(int score);
    ~EndScreen();
    
    virtual void update(float dt);
    
    
protected:
    Transition* transition;
    
    cocos2d::CCSprite* sprite;
    
    int retryCount;
    
};


#endif /* defined(__GamJam2013__EndScreen__) */
