#include "stages.h"

#include <GL/gl.h>
stages::stages()
{

}

stages::~stages()
{
    //dtor
}
void stages::stagesInit(char* image, float x1, float y1, float x2,float y2)
{
    x=x1;
    y=y1;
    xSize=x2;
    ySize=y2;
     glEnable(GL_BLEND);
    //glBlendFunc(GL_SRC_ALPHA,GL_ONE_MINUS_SRC_ALPHA);
    stage1[0].bindTexture(image);
      this->stage1->binder();
   this->stage1->bindTexture(image);
}
void stages::draw()
{
    glTranslated(x,y,0);
    this->stage1->binder();
    glBegin(GL_POLYGON);

    glTexCoord2f(0.0,1.0);
    glVertex3f(0.0f,0.0f,0.0f);

    glTexCoord2f(1.0,1.0);
    glVertex3f(xSize,0.0f,0.0f);

    glTexCoord2f(1.0,0.0);
    glVertex3f(xSize,ySize,0.0f);

    glTexCoord2f(0.0,0.0);
    glVertex3f(0.0f,ySize,0.0f);

    glEnd();
}

