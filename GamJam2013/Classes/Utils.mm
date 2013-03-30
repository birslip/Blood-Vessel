//
//  Utils.cpp
//  GamJam2013
//
//  Created by Arthur GUIBERT on 26/01/13.
//
//

#include "SimpleAudioEngine.h"
#include "Game.h"

using namespace cocos2d;
using namespace CocosDenshion;

double getTime()
{
    NSTimeInterval t = [[NSDate date] timeIntervalSince1970];
    
    return t * 1000;
}

std::string pathToLocalFile(std::string fileBase, std::string extension)
{
    NSString* sBase = [NSString stringWithCString:fileBase.c_str() encoding:NSASCIIStringEncoding];
    NSString* sExt = [NSString stringWithCString:extension.c_str() encoding:NSASCIIStringEncoding];
    NSString* path = [[NSBundle mainBundle] pathForResource:sBase ofType:sExt];
    
    std::string result = [path cStringUsingEncoding:NSASCIIStringEncoding];
    return result;
}

void playSound(std::string soundName) {
    std::string path = pathToLocalFile(soundName, "wav");
    SimpleAudioEngine::sharedEngine()->playEffect(path.c_str());
}