//
//  Transition.h
//  GamJam2013
//
//  Created by Arthur GUIBERT on 26/01/13.
//
//

#ifndef __GamJam2013__Transition__
#define __GamJam2013__Transition__

class Transition : public cocos2d::CCLayer
{
public:
    Transition();
    ~Transition();
    
    void update();
    
    void fade(float value);
    
protected:
    cocos2d::CCLayerColor* overlay;
    
    float opacity;
    float target;
    float velocity;
};

#endif /* defined(__GamJam2013__Transition__) */
