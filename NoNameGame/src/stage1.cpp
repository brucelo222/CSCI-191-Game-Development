#include "stage1.h"

stage1::stage1()
{
    //ctor
}

stage1::~stage1()
{
    //dtor
}
void stage1::initStage()
{
    this->stgstart->parallaxInit("image/stg1.png");

}

void stage1::drawStage()
{

    glPushMatrix();
    glScaled(3.33,3.33,1.0);
    stgstart->drawSquare(screenWidth,screenHeight);
    stgstart->scroll(false,"right",0.005); //True = Scroll
    glPopMatrix();

}
