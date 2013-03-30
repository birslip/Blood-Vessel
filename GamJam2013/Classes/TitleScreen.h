//
//  TitleScreen.h
//  GamJam2013
//
//  Created by Arthur GUIBERT on 26/01/13.
//
//

#ifndef __GamJam2013__TitleScreen__
#define __GamJam2013__TitleScreen__

class TitleScreen : public cocos2d::CCLayer
{
public:
    TitleScreen();
    ~TitleScreen();
    
    virtual void update(float dt);
    
protected:
    void playButtonPressed(cocos2d::CCObject* sender);
    void helpButtonPressed(cocos2d::CCObject* sender);
    void creditsButtonPressed(cocos2d::CCObject* sender);
    
protected:
    cocos2d::CCSprite* background;
    cocos2d::CCSprite* credits;
    cocos2d::CCSprite* help;
    
    Button* button[3];
    
    Transition* transition;
    
    int playCount;
    
    float creditsScale;
    float creditsScaleTarget;
    float helpScale;
    float helpScaleTarget;
    
    bool creditsDisplayed;
    bool helpDisplayed;
};

#endif /* defined(__GamJam2013__TitleScreen__) */
