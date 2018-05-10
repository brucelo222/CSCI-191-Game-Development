#include "Parallax.h"
#include <texture.h>



Parallax::Parallax()
{
    //ctor
    Xmax= 1.0f;
    Ymax= 0.0f;
    Xmin= 0.0f;
    Ymin= 1.0f;
}

Parallax::~Parallax()
{
    //dtor
}

void Parallax::drawSquare(float width, float height)
{
    glColor3f(1.0,1.0,1.0);
    this->bTex->binder();
    glBegin(GL_POLYGON);
        glTexCoord2f(Xmin,Ymin);
        glVertex3f(-width/height,-1,-8.0f);

        glTexCoord2f(Xmax,Ymin);
        glVertex3f(width/height,-1,-8.0f);

        glTexCoord2f(Xmax,Ymax);
        glVertex3f(width/height,1,-8.0f);

        glTexCoord2f(Xmin,Ymax);
        glVertex3f(-width/height,1,-8.0f);
     glEnd();
}

void Parallax::parallaxInit(char *FileName)
{
//glEnable(GL_BLEND);
  //  glBlendFunc(GL_SRC_ALPHA,GL_ONE_MINUS_SRC_ALPHA);
   this->bTex->binder();
   this->bTex->bindTexture(FileName);

}

void Parallax::scroll(bool Auto, string dir, float speed)
{
    if(Auto){

        if(dir == "up")
        {
           Ymin -=speed;
           Ymax -=speed;
        }
        if(dir == "down")
        {
           Ymin +=speed;
           Ymax +=speed;
        }
        if(dir == "left")
        {
           Xmin -=speed;
           Xmax -=speed;
        }
        if(dir == "right")
        {
           Xmin +=speed;
           Xmax +=speed;
        }
    }
}
