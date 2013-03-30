//
//  Camera.h
//  GamJam2013
//
//  Created by Arthur GUIBERT on 26/01/13.
//
//

#ifndef __GamJam2013__Camera__
#define __GamJam2013__Camera__

class Camera
{
public:
    Camera(float velocity, float damping);
    ~Camera();
    
    void update();
    void shake(float x, float y);
    
    void setTarget(cocos2d::CCPoint p);
    bool isTargetEnabled() { return targetEnabled; }
    
    cocos2d::CCPoint getPosition();
    cocos2d::CCPoint getOffset();
    
protected:
    void updatePosition();
    void updateShake();
    
protected:
    cocos2d::CCPoint position;
    cocos2d::CCPoint offset;
    cocos2d::CCPoint speed;
    cocos2d::CCPoint target;
    
    float velocity;
    float damping;
    float epsilon;
    float easing;
    
    bool targetEnabled;
};


#endif /* defined(__GamJam2013__Camera__) */
