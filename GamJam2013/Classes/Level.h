//
//  Level.h
//  GameJam2013
//
//  Created by Arthur GUIBERT on 25/01/13.
//
//

#ifndef __GamJam2013__Level__
#define __GamJam2013__Level__

class Stripes;
class Stars;
class Transition;
class Particles;

enum LayerDepth
{
    Z_BACKGROUND = 0,
    Z_STRIPES,
    Z_STARS,
    Z_SHIP,
    Z_INTERFACE,
    Z_TRANSITION
};

class Level : public cocos2d::CCLayer
{
public:
    Level();
    ~Level();
    
    virtual void update(float dt);
    
    double getElapsedTime() { return elapsedTime; }
    
    cocos2d::CCSprite* getStripeSprite();
    
    void setCurrentStripeType(int type)
    {
        currentStripeType = type;
    }
    void setCurrentStripeId(int i)
    {
        if(i != currentStripeId)
            stripeCount++;
        
        currentStripeId = i;
    }
    
    int getNewlyPressedColor();
    int getPressedColor() { return currentColor; }
    
    int getLife() { return life; }
    int getFramecount() { return frameCount; }
    
    bool shoudHideNoise(int value);
    
    void emitParticles(cocos2d::ccColor3B color);
    
protected:
    void updateCurrentPressedColor();
    void updateStripes();
    
protected:
    Transition* transition;
    Camera* camera;
    Stars* stars;
    Particles* particles;
    
    Stripes* stripes[12];
    
    Button* button[3];
    
    cocos2d::ccColor3B color[7];
    
    Animation* shipAnim;
    Animation* shipShaking;
    Animation* alienIdle;
    Animation* alienScreaming;
    Animation* screenAnim;
    Animation* explosionAnim;
    
    cocos2d::CCSprite* background;
    cocos2d::CCSprite* screenBackground;
    cocos2d::CCSprite* screenOverlay;
    cocos2d::CCSprite* ship;
    
    cocos2d::CCLayerColor* flash;
    
    std::vector<cocos2d::CCSprite*> spritePool;
    int spritePoolIndex;
    
    double journeyStartTime;
    
    double startTime;
    double elapsedTime;
    
    int oldStripeType;
    int oldPressedColor;
    int newlyPressedCount;
    int currentColor;
    int currentStripeType;
    int currentStripeId;
    int oldStripeId;
    int newlyPressedColor;
    int invincibiltyCount;
    int frameCount;
    int patternCount;
    int stripeCount;
    int stripeBase;
    
    std::map<int,bool> hiddenStripe;
    
    int shipShakeAnimCount;
    int shipExplosionCount;
    
    int alienScreamAnimCount;
    
    int currentTrack;
    int lastTrack;
    int nextTrack;
    
    int life;
    bool hasGoodColor;
    int validationCount;
    int validationThreshold;
    
    bool noiseHidden;
};

#endif /* defined(__GameJam2013__Level__) */
