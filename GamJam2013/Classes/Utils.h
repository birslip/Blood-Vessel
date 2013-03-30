//
//  Utils.h
//  GamJam2013
//
//  Created by Arthur GUIBERT on 26/01/13.
//
//

#ifndef __GamJam2013__Utils__
#define __GamJam2013__Utils__

double getTime();
std::string pathToLocalFile(std::string fileBase, std::string extension);

inline cocos2d::CCPoint operator+(cocos2d::CCPoint v, cocos2d::CCPoint w)
{
    return ccp(
               v.x + w.x,
               v.y + w.y
               );
}

inline cocos2d::CCPoint operator-(cocos2d::CCPoint v, cocos2d::CCPoint w)
{
    return ccp(
               v.x - w.x,
               v.y - w.y
               );
}

inline cocos2d::CCPoint operator*(cocos2d::CCPoint v, cocos2d::CCPoint w)
{
    return ccp(
               v.x * w.x,
               v.y * w.y
               );
}

inline cocos2d::CCPoint operator*(cocos2d::CCPoint v, double w)
{
    return ccp(
               v.x * w,
               v.y * w
               );
}

inline cocos2d::CCPoint operator*(double w, cocos2d::CCPoint v)
{
    return v*w;
}

inline cocos2d::CCPoint operator/(cocos2d::CCPoint v, cocos2d::CCPoint w)
{
    return cocos2d::CCPoint (
                             v.x / w.x,
                             v.y / w.y
                             );
}

inline cocos2d::CCPoint operator/(cocos2d::CCPoint v, double w)
{
    return cocos2d::CCPoint (
                             v.x / w,
                             v.y / w
                             );
}

inline cocos2d::CCPoint operator/(double w, cocos2d::CCPoint v)
{
    return cocos2d::CCPoint (
                             w / v.x,
                             w / v.y
                             );
}

inline cocos2d::CCPoint& operator+=( cocos2d::CCPoint& a, const cocos2d::CCPoint b )
{
    a = a + b;
    return a;
}

inline cocos2d::CCPoint& operator-=( cocos2d::CCPoint& a, const cocos2d::CCPoint b )
{
    a = a + b;
    return a;
}

inline cocos2d::CCPoint& operator*=( cocos2d::CCPoint& a, const float factor )
{
    a = a * factor;
    return a;
}

inline cocos2d::CCPoint& operator/=( cocos2d::CCPoint& a, const float factor )
{
    a = a / factor;
    return a;
}

inline bool isPointInRect(cocos2d::CCPoint p, cocos2d::CCRect rect)
{
    return (p.x >= rect.origin.x && p.x <= rect.origin.x + rect.size.width
            && p.y >= rect.origin.y && p.y <= rect.origin.y + rect.size.height);
}

template<class T>
std::string toString(T item) {
    std::ostringstream oss;
    oss << item;
    return std::string(oss.str());
}



#endif /* defined(__GamJam2013__Utils__) */
