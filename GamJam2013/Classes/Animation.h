//
//  Animation.h
//  GameJam2013
//
//  Created by Arthur GUIBERT on 25/01/13.
//
//

#ifndef __GamJam2013__Animation__
#define __GamJam2013__Animation__

class Animation
{
public:
    ~Animation();
    Animation(std::string str);
    
    void animate(cocos2d::CCSprite* sprite, int frame);
    int getFrameCount() { return frameList.size(); }
    
    cocos2d::CCSpriteFrame* getSpriteFrame(int n);
    
protected:
    std::vector<cocos2d::CCSpriteFrame*> frameList;
};


#endif /* defined(__GameJam2013__Animation__) */
