#include "platform.h"

platform::platform()
{
    //ctor
}

platform::~platform()
{
    //dtor
}

void platform::initPlatform(float top, float bottom, float right, float left)
{
    yTop=top;
    yBottom=bottom;
    xRight=right;
    xLeft=left;
}

void platform::drawPlatform(float width, float height)
{
    _shape->drawQuad(width,height,-1.0,Color(1.0,1.0,1.0,1.0));
}

