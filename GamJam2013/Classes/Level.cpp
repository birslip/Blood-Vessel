//
//  Level.cpp
//  GameJam2013
//
//  Created by Arthur GUIBERT on 25/01/13.
//
//

#include "SimpleAudioEngine.h"
#include "Game.h"

using namespace cocos2d;
using namespace CocosDenshion;

struct ColorWithButton {
    bool state[3];
    int color;
};

ColorWithButton colorWithButton[] =
{
    {1,0,0, RED},
    {0,1,0, YELLOW},
    {0,0,1, BLUE},
    {1,1,0, ORANGE},
    {0,1,1, GREEN},
    {1,0,1, PURPLE}
};

const char* trackList[] =
{
    "Music/music_loop_easy_01.wav",
    "Music/music_loop_easy_02.wav",
    "Music/music_loop_easy_03.wav",
    
    "Music/music_loop_medium_01.wav",
    "Music/music_loop_medium_02.wav",
    "Music/music_loop_medium_03.wav",
    
    "Music/music_loop_hard_01.wav",
    "Music/music_loop_hard_02.wav",
    "Music/music_loop_hard_03.wav",
    
    
    "Music/music_loop_easy_04.wav",
    "Music/music_loop_medium_04.wav",
    "Music/music_loop_medium_05.wav",
};

Level::Level()
{
    CCLayer::init();
    
    camera = new Camera(0.96, 0.7);
    
    // Easy 01
    stripes[0] = new Stripes(this);
    stripes[0]->add({0,BLUE});
    stripes[0]->add({1325,RED});
    stripes[0]->add({2658,YELLOW});
    stripes[0]->add({3991,BLUE});
    stripes[0]->setLength(5325);
    
    // Easy 02
    stripes[1] = new Stripes(this);
    stripes[1]->add({0,BLUE});
    stripes[1]->add({1333,RED});
    stripes[1]->add({2667,YELLOW});
    stripes[1]->add({3983,GREEN});
    stripes[1]->setLength(5325);
    
    // Easy 03
    stripes[2] = new Stripes(this);
    stripes[2]->add({0,BLUE});
    stripes[2]->add({505,GREEN});
    stripes[2]->add({1333,BLUE});
    stripes[2]->add({2667,RED});
    stripes[2]->add({4009,BLUE});
    stripes[2]->setLength(5325);
    
    // Medium 01
    stripes[3] = new Stripes(this);
    stripes[3]->add({0,BLUE});
    stripes[3]->add({662,BLUE});
    stripes[3]->add({1325,BLUE});
    stripes[3]->add({2000,ORANGE});
    stripes[3]->add({2667,GREEN});
    stripes[3]->add({3332,BLUE});
    stripes[3]->add({3991,BLUE});
    stripes[3]->add({4622,GREEN});
    stripes[3]->setLength(5325);
    
    // Medium 02
    stripes[4] = new Stripes(this);
    stripes[4]->add({0,BLUE});
    stripes[4]->add({662,GREEN});
    stripes[4]->add({1325,RED});
    stripes[4]->add({2000,GREEN});
    stripes[4]->add({2667,YELLOW});
    stripes[4]->add({3332,GREEN});
    stripes[4]->add({3991,BLUE});
    stripes[4]->add({4622,BLUE});
    stripes[4]->setLength(5325);
    
    // Medium 03
    stripes[5] = new Stripes(this);
    stripes[5]->add({0,BLUE});
    stripes[5]->add({662,GREEN});
    stripes[5]->add({1325,PURPLE});
    stripes[5]->add({2000,GREEN});
    stripes[5]->add({2667,YELLOW});
    stripes[5]->add({3332,PURPLE});
    stripes[5]->add({3991,YELLOW});
    stripes[5]->add({4622,BLUE});
    stripes[5]->setLength(5325);
    
    // Hard 01
    stripes[6] = new Stripes(this);
    stripes[6]->add({0,BLUE});
    stripes[6]->add({310,BLUE});
    stripes[6]->add({662,GREEN});
    stripes[6]->add({1000,ORANGE});
    stripes[6]->add({2000,PURPLE});
    stripes[6]->add({2329,BLUE});
    stripes[6]->add({2667,ORANGE});
    stripes[6]->add({3000,BLUE});
    stripes[6]->add({3332,GREEN});
    stripes[6]->add({3991,YELLOW});
    stripes[6]->add({4622,BLUE});
    stripes[6]->setLength(5325);
    
    // Hard 02
    stripes[7] = new Stripes(this);
    stripes[7]->add({0,BLUE});
    stripes[7]->add({310,BLUE});
    stripes[7]->add({662,GREEN});
    stripes[7]->add({1000,BLUE});
    stripes[7]->add({1301,ORANGE});
    stripes[7]->add({2329,BLUE});
    stripes[7]->add({2667,RED});
    stripes[7]->add({3000,BLUE});
    stripes[7]->add({3332,BLUE});
    stripes[7]->add({3655,YELLOW});
    stripes[7]->add({3991,ORANGE});
    stripes[7]->add({4658,BLUE});
    stripes[7]->add({5327,BLUE});
    stripes[7]->add({5602,YELLOW});
    stripes[7]->add({5900,PURPLE});
    stripes[7]->add({6306,YELLOW});
    stripes[7]->add({6600,ORANGE});
    stripes[7]->add({7632,BLUE});
    stripes[7]->add({8000,PURPLE});
    stripes[7]->add({8300,RED});
    stripes[7]->add({8659,BLUE});
    stripes[7]->add({9000,YELLOW});
    stripes[7]->add({9316,PURPLE});
    stripes[7]->add({10000,ORANGE});
    stripes[7]->setLength(10666);

    // Hard 03
    stripes[8] = new Stripes(this);
    stripes[8]->add({0,RED});
    stripes[8]->add({310,RED});
    stripes[8]->add({662,YELLOW});
    stripes[8]->add({1000,BLUE});
    stripes[8]->add({1301,ORANGE});
    stripes[8]->add({1636,GREEN});
    stripes[8]->add({2000,PURPLE});
    stripes[8]->add({2667,ORANGE});
    stripes[8]->add({3000,BLUE});
    stripes[8]->add({3332,RED});
    stripes[8]->add({3655,PURPLE});
    stripes[8]->add({3991,ORANGE});
    stripes[8]->add({4247,GREEN});
    stripes[8]->add({4658,BLUE});
    stripes[8]->setLength(5325);

    // Easy 04
    stripes[9] = new Stripes(this);
    stripes[9]->add({0,BLUE});
    stripes[9]->add({505,GREEN});
    stripes[9]->add({1333,NOISE});
    stripes[9]->add({3332,GREEN});
    stripes[9]->add({4000,BLUE});
    stripes[9]->setLength(5325);
    
    // Medium 04
    stripes[10] = new Stripes(this);
    stripes[10]->add({0,BLUE});
    stripes[10]->add({1325,PURPLE});
    stripes[10]->add({2000,RED});
    stripes[10]->add({2667,NOISE});
    stripes[10]->add({3991,BLUE});
    stripes[10]->setLength(5325);

    // Medium 05
    stripes[11] = new Stripes(this);
    stripes[11]->add({0,BLUE});
    stripes[11]->add({662,YELLOW});
    stripes[11]->add({1325,YELLOW});
    stripes[11]->add({2000,RED});
    stripes[11]->add({2667,BLUE});
    stripes[11]->add({3332,GREEN});
    stripes[11]->add({3991,NOISE});
    stripes[11]->setLength(5325);
    
    
    for(int i=0;i<128;i++)
    {
        CCSprite* s = CCSprite::createWithSpriteFrameName("stripe.png");
        s->setVisible(false);
        s->setPositionX(80);
        s->setAnchorPoint(ccp(0.5,0));
        addChild(s, Z_STRIPES);
        spritePool.push_back(s);
    }
    
    stars = new Stars();
    addChild(stars,Z_STARS);

    color[0] = ccRED;
    color[1] = ccBLUE;
    color[2] = ccYELLOW;
    color[3] = {255,0,255};
    color[4] = ccORANGE;
    color[5] = ccGREEN;
    color[6] = ccWHITE;
    
    screenBackground = CCSprite::createWithSpriteFrameName("scenario_aline_screens_idle_01.png");
    screenBackground->setAnchorPoint(ccp(0,0));
    addChild(screenBackground,Z_INTERFACE);
    
    screenOverlay = CCSprite::createWithSpriteFrameName("ge_health_01.png");
    screenOverlay->setAnchorPoint(ccp(0,0));
    screenOverlay->setVisible(false);
    addChild(screenOverlay,Z_INTERFACE);
    
    background = CCSprite::createWithSpriteFrameName("scenario_alien_bkg.png");
    background->setAnchorPoint(ccp(0,0));
    addChild(background, Z_INTERFACE);
    
    background->getTexture()->setAliasTexParameters();
    
    button[0] = new Button("ge_heart_red_UP.png", "ge_heart_red_OVER.png", CCSize(48, 48));
    button[0]->setPosition(ccp(80, 58));
    addChild(button[0], Z_INTERFACE);
    
    button[1] = new Button("ge_heart_yellow_UP.png", "ge_heart_yellow_OVER.png", CCSize(48, 48));
    button[1]->setPosition(ccp(108, 20));
    addChild(button[1], Z_INTERFACE);
    
    button[2] = new Button("ge_heart_blue_UP.png", "ge_heart_blue_OVER.png", CCSize(48, 48));
    button[2]->setPosition(ccp(52, 20));
    addChild(button[2], Z_INTERFACE);
    
    ship = CCSprite::createWithSpriteFrameName("scenario_ship_still_01.png");
    ship->setPosition(ccp(80,144));
    addChild(ship, Z_SHIP);
    
    particles = new Particles();
    particles->init(this, 64, Z_STARS);
    
    flash = CCLayerColor::create({255,255,255,255});
    flash->setVisible(false);
    addChild(flash, Z_INTERFACE);
    
    transition = new Transition();
    addChild(transition, Z_TRANSITION);
    
    shipAnim = new Animation("scenario_ship_still_01:5,scenario_ship_still_02:5,scenario_ship_still_03:5,scenario_ship_still_04:5");
    shipShaking = new Animation("scenario_ship_shake_01:5,scenario_ship_shake_02:5,scenario_ship_shake_03:5,scenario_ship_shake_04:5,scenario_ship_shake_05:5,scenario_ship_shake_06:10,scenario_ship_shake_07:5,scenario_ship_shake_08:5");
    explosionAnim = new Animation("scenario_ship_explode_01:5,scenario_ship_explode_02:5,scenario_ship_explode_03:5,scenario_ship_explode_04:5,scenario_ship_explode_05:5,scenario_ship_explode_06:5,scenario_ship_explode_07:5");
    
    alienIdle = new Animation("scenario_alien_idle_01:10,scenario_alien_idle_02:10,scenario_alien_idle_03:10,scenario_alien_idle_04:10,scenario_alien_idle_05:10");
    alienScreaming = new Animation("scenario_alien_screaming_01:6,scenario_alien_screaming_02:6");
    
    screenAnim = new Animation("scenario_aline_screens_idle_01:5,scenario_aline_screens_idle_02:5,scenario_aline_screens_idle_03:5,scenario_aline_screens_idle_04:5");
    
    startTime = -1;
    shipShakeAnimCount = -1;
    oldStripeType = -1;
    currentColor = -1;
    shipExplosionCount = -1;
    newlyPressedCount = -1;
    hasGoodColor = false;
    validationCount = 0;
    validationThreshold = 2;
    frameCount = 0;
    currentTrack = 0;
    lastTrack = 0;
    nextTrack = 1;
    spritePoolIndex = 0;
    life = 4;
    invincibiltyCount = 60 * 3;
    noiseHidden = false;
    patternCount = 0;
    alienScreamAnimCount = -1;
    
    //Audio::sharedAudio()->preloadSounds();
    
    for(int i=0;i<9;i++)
    {
        SimpleAudioEngine::sharedEngine()->preloadEffect( CCFileUtils::sharedFileUtils()->fullPathFromRelativePath(trackList[i]) );
    }
    
    SimpleAudioEngine::sharedEngine()->preloadEffect( CCFileUtils::sharedFileUtils()->fullPathFromRelativePath("Music/fx_ship_explosion.wav") );
    
    SimpleAudioEngine::sharedEngine()->setEffectsVolume(1);
    
    journeyStartTime = getTime();
}

Level::~Level()
{
    delete stripes[0];
    delete particles;
}

cocos2d::CCSprite* Level::getStripeSprite()
{
    CCSprite* s = NULL;
    if(spritePoolIndex < spritePool.size())
    {
        s = spritePool[spritePoolIndex];
        spritePoolIndex++;
    }
    
    return s;
}

void Level::update(float dt)
{
    camera->update();
    transition->update();
    particles->update();
    
    if(shipExplosionCount >= 0)
    {
        // Explosion
        explosionAnim->animate(ship, shipExplosionCount);
        
        if(shipExplosionCount == 0)
        {
            SimpleAudioEngine::sharedEngine()->playEffect(CCFileUtils::sharedFileUtils()->fullPathFromRelativePath("Music/fx_ship_explosion.wav"));
            
        }
        
        if((shipExplosionCount >= 0 && shipExplosionCount <= 2) || (shipExplosionCount >= 8 && shipExplosionCount <= 10) || (shipExplosionCount >= 18 && shipExplosionCount <= 20))
        {
            flash->setVisible(true);
        }
        else
        {
            flash->setVisible(false);
        }
        
        shipExplosionCount++;
        
        if(shipExplosionCount >= explosionAnim->getFrameCount())
        {
            ship->setVisible(false);
            SimpleAudioEngine::sharedEngine()->stopAllEffects();
            transition->fade(255);
            
            
            if(shipExplosionCount == explosionAnim->getFrameCount() + 60)
            {
                game()->ending((float)frameCount / 60.0f);
                
                return;
            }
        }
    }
    else if(shipShakeAnimCount >= 0)
    {
        // Shake
        shipShaking->animate(ship,shipShakeAnimCount);
        
        shipShakeAnimCount--;
        
        if(shipShakeAnimCount == shipShaking->getFrameCount())
        {
            shipShakeAnimCount = -1;
        }
    }
    else
    {
        // Idle
        shipAnim->animate(ship,frameCount);
    }
    
    if(invincibiltyCount >= 0)
    {
        if((invincibiltyCount / 3) % 2 == 0)
        {
            ship->setVisible(false);
        }
        else
        {
            ship->setVisible(true);
        }
        
        invincibiltyCount--;
        
        if(invincibiltyCount < 0)
        {
            ship->setVisible(true);
        }
    }
    
    ship->setPosition(ccp(80,148) + camera->getPosition());
    
    if(shipShakeAnimCount >= 0)
    {
        alienScreaming->animate(background, frameCount);
    }
    else if(alienScreamAnimCount >= 0)
    {
        alienScreaming->animate(background, frameCount);
        
        alienScreamAnimCount--;
    }
    else
    {
        alienIdle->animate(background, frameCount);
    }
       
    screenAnim->animate(screenBackground, frameCount);
    
    if(life > 0)
    {
        stars->update();
        
        updateStripes();
    }
    
    for(int i=0;i<3;i++)
    {
        button[i]->update();
    }
    
    updateCurrentPressedColor();
    
    if(newlyPressedCount >= 0)
    {
        newlyPressedCount--;
    }
    
    if(oldPressedColor != currentColor)
    {
        newlyPressedCount = 5;
        
        if(currentColor == currentStripeType)
        {
            emitParticles(color[currentColor]);
        }
        
        oldPressedColor = currentColor;
    }
    
    if(elapsedTime >= stripes[currentTrack]->getLength())
    {
        startTime = -1;
    }
    
    if(startTime < 0)
    {
        lastTrack = currentTrack;
        currentTrack = nextTrack;
        
        if(patternCount < 3)
        {
            nextTrack = rand() % 6;
        }
        else if(patternCount < 6)
        {
            nextTrack = 2 + rand() % 4;
        }
        else
        {
            if(rand()&1)
            {
                nextTrack = 9 + rand() % 3;
            }
            else
            {
                nextTrack = rand() % 12;
            }
            
        }
        
        patternCount++;
        validationCount = 0;
        stripeBase = stripeCount;
        
        startTime = getTime();
        if(currentTrack < 12)
        {
            SimpleAudioEngine::sharedEngine()->playEffect(CCFileUtils::sharedFileUtils()->fullPathFromRelativePath(trackList[currentTrack]));
        }
    }
    
    elapsedTime = getTime() - startTime;
    
    frameCount++;
    
}

void Level::updateStripes()
{
    // Update stripes
    spritePoolIndex = 0;
    
    stripes[lastTrack]->update(stripes[lastTrack]->getLength());
    stripes[currentTrack]->update(0);
    stripes[nextTrack]->update(-stripes[currentTrack]->getLength());
    
    for(int i = spritePoolIndex;i<spritePool.size();i++)
    {
        spritePool[i]->setVisible(false);
    }
    
    //printf("Current stripe = %d %d\n",currentStripeType, currentColor);
    
    if(currentStripeType >= 0)
    {
        if(currentColor == currentStripeType)
        {
            validationCount++;
            SimpleAudioEngine::sharedEngine()->setEffectsVolume(0.5);
        }
        else
        {
            camera->shake(rand() % 3, rand() % 3);
            SimpleAudioEngine::sharedEngine()->setEffectsVolume(0.5);
        }
    }
    
    if(currentColor >= 0)
    {
        screenBackground->setColor(color[currentColor]);
    }
    else
    {
        screenBackground->setColor(ccWHITE);
    }
    
    if(invincibiltyCount < 0)
    {
        if(currentStripeType != oldStripeType || currentStripeId != oldStripeId)
        {
            
            if(validationCount >= validationThreshold)
            {
                printf("win\n");
            }
            else
            {
                life--;
                
                if(life == 0)
                {
                    shipExplosionCount = 0;
                }
                else
                {
                    shipShakeAnimCount = 0;
                    invincibiltyCount = 60;
                    
                    screenOverlay->setVisible(true);
                    
                    if(life == 3)
                    {
                        screenOverlay->setDisplayFrame(CCSpriteFrameCache::sharedSpriteFrameCache()->spriteFrameByName("ge_health_01.png"));
                    }
                    else if(life == 2)
                    {
                        screenOverlay->setDisplayFrame(CCSpriteFrameCache::sharedSpriteFrameCache()->spriteFrameByName("ge_health_02.png"));
                    }
                    else if(life == 1)
                    {
                        screenOverlay->setDisplayFrame(CCSpriteFrameCache::sharedSpriteFrameCache()->spriteFrameByName("ge_health_03.png"));
                    }
                }
            }
            
            currentColor = -1;
            validationCount = 0;
        }
    }
    
    oldStripeType = currentStripeType;
    oldStripeId = currentStripeId;
}

int Level::getNewlyPressedColor()
{
    if(newlyPressedCount >= 0 && currentStripeType == currentColor)
    {
        return currentColor;
    }
    
    return -1;
}

void Level::updateCurrentPressedColor()
{
    for(int i=0;i<sizeof(colorWithButton) / sizeof(ColorWithButton);i++)
    {
        if(((button[0]->getState() == Button::PRESSED) ==  colorWithButton[i].state[0])
           && ((button[1]->getState() == Button::PRESSED) ==  colorWithButton[i].state[1])
           && ((button[2]->getState() == Button::PRESSED) ==  colorWithButton[i].state[2]))
        {
            oldPressedColor = currentColor;
            currentColor = colorWithButton[i].color;
            
            break;
        }
    }
    
    if((finger.acceleration.x > 1 || finger.acceleration.y > 1 || finger.acceleration.z > 1) && currentStripeType == NOISE)
    {
        oldPressedColor = currentColor;
        currentColor = NOISE;
        noiseHidden = true;
        alienScreamAnimCount = 8;
        hiddenStripe[stripeBase + currentStripeId] = true;
    }
}

void Level::emitParticles(cocos2d::ccColor3B color)
{
    CCSpriteFrame* f = CCSpriteFrameCache::sharedSpriteFrameCache()->spriteFrameByName("ge_particles.png");
    ParticleDef def;
    
    def.position = ship->getPosition();
    def.acceleration = ccp(0,0);
    def.friction = 0.98f;
    
    int particleCount = 24;
    
    for(int i=0;i<particleCount;i++)
    {
        def.speed = ccp(rand() % 1000 - 500, rand() % 1000 - 500) / 200.0f;
        def.life = 20 + rand() % 20;
        def.scale = (0.3 + (float)(rand() % 1000) / 500.0f) / 2.5f;
        def.deltaScale = -def.scale / def.life;
        def.angle = rand() % 360;
        def.deltaAngle = rand() % 32 - 16;
        
        if(i&1)
        {
            def.color = color;
        }
        else
        {
            def.color = ccWHITE;
        }
        
        particles->add(f, def);
    }
    
}

bool Level::shoudHideNoise(int value)
{
    return noiseHidden;
}
