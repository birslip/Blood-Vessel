//
//  TitleScreen.cpp
//  GamJam2013
//
//  Created by Arthur GUIBERT on 26/01/13.
//
//

#include "SimpleAudioEngine.h"
#include "Game.h"

using namespace cocos2d;

TitleScreen::TitleScreen()
{
    CCLayer::init();
    
    background = CCSprite::createWithSpriteFrameName("gui_mainmenu_bkg.png");
    background->setAnchorPoint(ccp(0,0));
    background->getTexture()->setAliasTexParameters();
    addChild(background);
    
    button[0] = new Button("gui_start_button_UP.png", "gui_start_button_OVER.png", CCSize(100,22));
    button[0]->setPosition(ccp(80,160));
    addChild(button[0]);
    
    button[1] = new Button("gui_credits_button_UP.png", "gui_credits_button_OVER.png", CCSize(100,22));
    button[1]->setPosition(ccp(63,137));
    addChild(button[1]);
    
    button[2] = new Button("gui_help_button_UP.png", "gui_help_button_OVER.png", CCSize(32,22));
    button[2]->setPosition(ccp(129,137));
    addChild(button[2]);
    
    transition = new Transition();
    addChild(transition);
    
    credits = CCSprite::createWithSpriteFrameName("gui_credits.png");
    credits->setPosition(ccp(80,120));
    credits->setScale(0);
    addChild(credits);
    
    help = CCSprite::createWithSpriteFrameName("gui_help.png");
    help->setPosition(ccp(80,120));
    help->setScale(0);
    addChild(help);
    
    playCount = -1;
    creditsDisplayed = false;
    creditsScaleTarget = 0;
    creditsScale = 0;
    helpDisplayed = false;
    helpScaleTarget = 0.0f;
    helpScale = 0.0f;
    
    
    CocosDenshion::SimpleAudioEngine::sharedEngine()->preloadEffect( CCFileUtils::sharedFileUtils()->fullPathFromRelativePath("Music/select.wav") );
    
    CocosDenshion::SimpleAudioEngine::sharedEngine()->setEffectsVolume(1);
}


TitleScreen::~TitleScreen()
{
    
}

void TitleScreen::update(float dt)
{
    if(playCount == 30)
    {
        game()->startGame();
        return;
    }
    
    transition->update();
    
    creditsScale += (creditsScaleTarget - creditsScale) * 0.25f;
    credits->setScale(creditsScale);
    
    helpScale += (helpScaleTarget - helpScale) * 0.25f;
    help->setScale(helpScale);

    
    if(creditsDisplayed)
    {
        if(finger.newPress)
        {
            creditsDisplayed = false;
            creditsScaleTarget = 0.0f;
            transition->fade(0);
        }
    }
    else if(helpDisplayed)
    {
        if(finger.newPress)
        {
            helpDisplayed = false;
            helpScaleTarget = 0.0f;
            transition->fade(0);
        }
    }
    else if(creditsScale < 0.2 && helpScale < 0.2)
    {
        for(int i=0;i<3;i++)
        {
            button[i]->update();
        }
        
        if(playCount >= 0)
        {
            playCount++;
            
            
        }
        else
        {
            if(button[0]->getState() == Button::RELEASED && finger.released)
            {
                playCount = 0;
                transition->fade(255);
                CocosDenshion::SimpleAudioEngine::sharedEngine()->playEffect( CCFileUtils::sharedFileUtils()->fullPathFromRelativePath("Music/select.wav") );
            }
            else if(button[1]->getState() == Button::RELEASED && finger.released)
            {
                transition->fade(128);
                creditsDisplayed = true;
                creditsScale = 0.0f;
                creditsScaleTarget = 1.0f;
                CocosDenshion::SimpleAudioEngine::sharedEngine()->playEffect( CCFileUtils::sharedFileUtils()->fullPathFromRelativePath("Music/select.wav") );
            }
            else if(button[2]->getState() == Button::RELEASED && finger.released)
            {
                transition->fade(128);
                helpDisplayed = true;
                helpScale = 0.0f;
                helpScaleTarget = 1.0f;
                CocosDenshion::SimpleAudioEngine::sharedEngine()->playEffect( CCFileUtils::sharedFileUtils()->fullPathFromRelativePath("Music/select.wav") );
            }
        }
    }
}

void TitleScreen::playButtonPressed(cocos2d::CCObject *sender)
{
    
}