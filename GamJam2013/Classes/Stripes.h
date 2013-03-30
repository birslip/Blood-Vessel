//
//  Stripes.h
//  GameJam2013
//
//  Created by Arthur GUIBERT on 25/01/13.
//
//

#ifndef __GamJam2013__Stripes__
#define __GamJam2013__Stripes__

enum StripeType
{
    RED = 0,
    BLUE,
    YELLOW,
    PURPLE,
    ORANGE,
    GREEN,
    NOISE
};

struct Stripe
{
    double startTime;
    
    int type;
};

class Stripes
{
public:
    Stripes(Level* level);
    ~Stripes();
    
    void update(double timeOffset);
    
    void add(Stripe s);
    
    int getCurrentStripeType() { return currentType; }
    int getCurrentStripeId() { return currentId; }
    
    void setLength(double value) { length = value; }
    double getLength() { return length; }
    
protected:
    Level* parent;
    cocos2d::CCSpriteFrame* stripeFrame[2];
    std::vector<Stripe> list;
    cocos2d::ccColor3B color[7];
    cocos2d::CCPoint offset;
    Animation* noise;
    
    int currentType;
    int currentId;
    
    double ratio;
    double length;
};

#endif /* defined(__GameJam2013__Stripes__) */
