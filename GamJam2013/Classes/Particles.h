//
//  Particles.h
//  GamJam2013
//
//  Created by Arthur GUIBERT on 27/01/13.
//
//

#ifndef __GamJam2013__Particles__
#define __GamJam2013__Particles__

struct ParticleDef
{
    ParticleDef();
    
    cocos2d::CCPoint position;
    cocos2d::CCPoint speed;
    cocos2d::CCPoint acceleration;
    
    cocos2d::ccColor3B color;
    cocos2d::ccColor3B targetColor;
    
    float friction;
    float groundFriction;
    float radius;
    float bounce;
    
    float scale;
    float deltaScale;
    
    float opacity;
    float deltaOpacity;
    
    float angle;
    float deltaAngle;
    
    int life;
    int animationOffset;
    
    bool colliding;
    bool changeColor;
};

struct Particle
{
    ~Particle();
    
    cocos2d::CCSprite* sprite;
    
    cocos2d::CCPoint position;
    cocos2d::CCPoint speed;
    cocos2d::CCPoint acceleration;
    
    float friction;
    
    Animation* anim;
    
    cocos2d::ccColor3B color;
    cocos2d::ccColor3B targetColor;
    
    float scale;
    float deltaScale;
    
    float opacity;
    float deltaOpacity;
    
    float angle;
    float deltaAngle;
    
    float life;
    float frameCount;
    float duration;
    
    int animationOffset;
    
    bool colliding;
    bool changeColor;
};

class Particles
{
public:
    Particles();
    ~Particles();
    
    void init(cocos2d::CCNode* parent, int maxParticles, int zOrder);
    void update(float dt = 1.0f);
    
    void add(cocos2d::CCSpriteFrame* spriteFrame, ParticleDef &def);
    void add(Animation* animation, ParticleDef &def);
    
    void setBoundingBox(int x, int y, int w, int h);
    
    void setVisible(bool visible);
    
    void setCallbackFunction(const std::function<void (Particle*)> &callback);
    void disableCallbackFunction();
    
protected:
    Particle* add(ParticleDef &def);
    
protected:
    // Batchnode
    cocos2d::CCSpriteBatchNode* batch;
    
    // Particles pool
    Particle* particle;
    int maxParticles;
    
    // Collision
    cocos2d::CCRect rect;
    
    // Callbacks
    bool useCallback;
    std::function<void (Particle*)> callback;
};


#endif /* defined(__GamJam2013__Particles__) */
