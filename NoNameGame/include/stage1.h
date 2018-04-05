#ifndef STAGE1_H
#define STAGE1_H

#include <parallax.h>
#include <GLScene.h>


class stage1 : public parallax
{
    public:
        stage1();
        virtual ~stage1();

        void initStage();
        void drawStage();


       parallax* stgstart = new parallax();
        float screenHeight;
        float screenWidth;

    protected:

    private:
};

#endif // STAGE1_H
