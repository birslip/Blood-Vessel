//
//  NumberLabel.h
//  GamJam2013
//
//  Created by Arthur GUIBERT on 27/01/13.
//
//

#ifndef __GamJam2013__NumberLabel__
#define __GamJam2013__NumberLabel__

class NumberLabel : public cocos2d::CCLayer
{
public:
    NumberLabel();
    ~NumberLabel();
    
    static NumberLabel* create(int number, const char* prefix);
    
    bool initWithNumber(int number, const char* prefix);
    
    int getLabelWidth() { return width; }
    
    void setNumber(int number);
    void setColor(cocos2d::ccColor3B color);
    void setOpacity(unsigned char opacity);
    void setAnchorPoint(cocos2d::CCPoint anchor);
    
    void setMonospaced(bool value);
    void setCharacterSize(cocos2d::CCSize size);
    
    void setAlign(int value) { align = value; }
    void setOffsetEffectValue(int value) { offsetEffect = value; }
    
    void setMinDigitCount(int value) { minDigitCount = value; }
    
    enum
    {
        ALIGN_LEFT = 0,
        ALIGN_CENTER,
        ALIGN_RIGHT
    };
    
protected:
    cocos2d::ccColor3B color;
    cocos2d::CCSpriteFrame* digitFrame[10];
    
    cocos2d::CCSize monospacedSize;
    
    std::vector<cocos2d::CCSprite*> sprite;
    
    int width;
    int align;
    int offsetEffect;
    int minDigitCount;
    
    bool monospaced;
    
};


#endif /* defined(__GamJam2013__NumberLabel__) */
