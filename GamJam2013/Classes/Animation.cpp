//
//  Animation.cpp
//  touchandpop
//
//  Created by Arthur GUIBERT on 08/10/12.
//
//

#include <regex.h>
#include "cocos2d.h"
#include "Animation.h"

using namespace cocos2d;

std::vector<std::string> &split(const std::string &s, char delim, std::vector<std::string> &elems)
{
    std::stringstream ss(s);
    std::string item;
    while(std::getline(ss, item, delim))
    {
        elems.push_back(item);
    }
    return elems;
}

std::vector<std::string> split(const std::string &s, char delim)
{
    std::vector<std::string> elems;
    return split(s, delim, elems);
}

Animation::~Animation()
{
    frameList.clear();
}

Animation::Animation(std::string str)
{
    std::vector<std::string> result = split(str, ',');
    
    for(int i=0;i<result.size();i++)
    {
        std::vector<std::string> r = split(result[i], ':');
        
        if(r.size() > 1)
        {
            CCSpriteFrame* f = NULL;
            
            // * means blank frame
            if(r[0] != "*")
            {
                std::string frameName = r[0] + ".png";
                f = CCSpriteFrameCache::sharedSpriteFrameCache()->spriteFrameByName(frameName.c_str());
            }
            
            for (int j=0; j<atoi(r[1].c_str()); j++)
            {
                frameList.push_back(f);
            }
        }
    }
}

void Animation::animate(cocos2d::CCSprite *sprite, int frame)
{
    if(frame < 0)
    {
        // To be safe...
        frame = 0;
    }
    
    CCSpriteFrame* f = frameList[frame % frameList.size()];
    
    if(f)
    {
        sprite->setVisible(true);
        sprite->setDisplayFrame(f);
    }
    else
    {
        sprite->setVisible(false);
    }
}

cocos2d::CCSpriteFrame* Animation::getSpriteFrame(int n)
{
    return frameList[n % frameList.size()];
}