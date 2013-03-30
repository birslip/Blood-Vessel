//
//  NumberLabel.cpp
//  GamJam2013
//
//  Created by Arthur GUIBERT on 27/01/13.
//
//

#include "cocos2d.h"
#include "Utils.h"
#include "NumberLabel.h"

using namespace cocos2d;

NumberLabel::NumberLabel()
{
    CCLayer::init();
    
    color = ccWHITE;
    width = 0;
    monospaced = false;
    monospacedSize = CCSize(0,0);
    align = ALIGN_LEFT;
    offsetEffect = 0;
    minDigitCount = 1;
}

NumberLabel::~NumberLabel()
{
    sprite.clear();
}

NumberLabel* NumberLabel::create(int number, const char *prefix)
{
    NumberLabel *pRet = new NumberLabel();
    if(pRet && pRet->initWithNumber(number, prefix))
    {
        pRet->autorelease();
        return pRet;
    }
    CC_SAFE_DELETE(pRet);
    return NULL;
}

bool NumberLabel::initWithNumber(int number, const char *prefix)
{
    for(int i=0;i<10;i++)
    {
        std::string str = prefix + toString(i);
        str += ".png";
        digitFrame[i] = CCSpriteFrameCache::sharedSpriteFrameCache()->spriteFrameByName(str.c_str());
        
        if(digitFrame[i] == NULL)
        {
            return false;
        }
        
        str.clear();
    }
    
    setNumber(number);
    
    return true;
}

void NumberLabel::setNumber(int number)
{
    for(CCSprite* s : sprite)
    {
        removeChild(s, true);
    }
    
    sprite.clear();
    
    width = 0;
    
    if(number == 0)
    {
        CCSprite* s = CCSprite::createWithSpriteFrame(digitFrame[0]);
        addChild(s);
        sprite.push_back(s);
        
        if(monospaced)
        {
            width += monospacedSize.width;
        }
        else
        {
            width += s->getTextureRect().size.width + 1;
        }
    }
    else
    {
        while(number > 0)
        {
            int digit = number % 10;
            
            CCSprite* s = CCSprite::createWithSpriteFrame(digitFrame[digit]);
            addChild(s);
            sprite.push_back(s);
            
            if(monospaced)
            {
                width += monospacedSize.width;
            }
            else
            {
                width += s->getTextureRect().size.width + 1;
            }
            
            number /= 10;
        }
    }
    
    // Fill with 0
    if(sprite.size() < minDigitCount)
    {
        for(int i = 0;i<minDigitCount - sprite.size() + 1;i++)
        {
            CCSprite* s = CCSprite::createWithSpriteFrame(digitFrame[0]);
            addChild(s);
            sprite.push_back(s);
            
            if(monospaced)
            {
                width += monospacedSize.width;
            }
            else
            {
                width += s->getTextureRect().size.width + 1;
            }
        }
    }
    
    int x = 0;
    
    for(int i=0;i<sprite.size();i++)
    {
        switch (align)
        {
            case ALIGN_LEFT:
                sprite[i]->setPosition(ccp(width / 2 + x + 0.05, 0 + 0.05));
                break;
                
            case ALIGN_RIGHT:
                sprite[i]->setPosition(ccp(-width / 2 + x + 0.05, 0 + 0.05));
                break;
                
            default:
                sprite[i]->setPosition(ccp(x + 0.05, 0 + 0.05));
                break;
        }
        
        if((i&1) && offsetEffect != 0)
        {
            sprite[i]->setPositionY(offsetEffect);
        }
        
        
        if(monospaced)
        {
            x -= monospacedSize.width;
        }
        else
        {
            x -= sprite[i]->getTextureRect().size.width + 1;
        }
    }
    
    setColor(color);
    m_tContentSize.width = width;
    m_tContentSize.height = digitFrame[0]->getOriginalSize().height;
}

void NumberLabel::setColor(cocos2d::ccColor3B color)
{
    for(CCSprite* s : sprite)
    {
        s->setColor(color);
    }
    
    this->color = color;
}

void NumberLabel::setOpacity(unsigned char opacity)
{
    for(CCSprite* s : sprite)
    {
        s->setOpacity(opacity);
    }
}

void NumberLabel::setAnchorPoint(cocos2d::CCPoint anchor)
{
    for(CCSprite* s : sprite)
    {
        s->setAnchorPoint(anchor);
    }
}

void NumberLabel::setMonospaced(bool value)
{
    monospaced = value;
}

void NumberLabel::setCharacterSize(cocos2d::CCSize size)
{
    monospacedSize = size;
}
