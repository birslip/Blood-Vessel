//
//  Button.h
//  GameJam2013
//
//  Created by Arthur GUIBERT on 25/01/13.
//
//

#ifndef __GamJam2013__Button__
#define __GamJam2013__Button__

class Button : public cocos2d::CCLayer
{
public:
    Button(std::string normalSpriteName, std::string pressedSpriteName, cocos2d::CCSize size);
    ~Button();
    
    void update();
    
    int getState();
    
    enum ButtonState
    {
        NORMAL = 0,
        NEWLY_PRESSED,
        PRESSED,
        RELEASED
    };
    
protected:
    cocos2d::CCSprite* sprite;
    cocos2d::CCSpriteFrame* frame[2];
    
    cocos2d::CCSize size;
    
    int state;
};

#endif /* defined(__GameJam2013__Button__) */
