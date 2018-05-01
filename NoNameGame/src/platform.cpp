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
