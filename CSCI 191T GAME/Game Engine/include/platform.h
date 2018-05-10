#ifndef PLATFORM_H
#define PLATFORM_H

#include "Graphics.h"

class platform
{
    public:
        platform();
        virtual ~platform();

        void initPlatform(float,float,float,float);
        void drawPlatform(float,float);

        float yTop;
        float yBottom;
        float xRight;
        float xLeft;

        Graphics *_shape = new Graphics();

    private:
};

#endif // PLATFORM_H
