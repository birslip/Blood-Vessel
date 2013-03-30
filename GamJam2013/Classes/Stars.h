//
//  Stars.h
//  GamJam2013
//
//  Created by Arthur GUIBERT on 26/01/13.
//
//

#ifndef __GamJam2013__Stars__
#define __GamJam2013__Stars__

class Stars : public cocos2d::CCLayer
{
public:
    Stars();
    ~Stars();
    
    void update();
    
protected:
    cocos2d::CCSprite* sprite[3][2];
    
    float velocity[3];
    
    int frameCount;
};

#endif /* defined(__GamJam2013__Stars__) */
