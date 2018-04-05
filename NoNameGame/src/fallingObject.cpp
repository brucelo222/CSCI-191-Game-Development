#include "fallingObject.h"
#include <timer.h>
#include <textureLoader.h>
#include <cmath>
#include <player.h>


timer *fallT = new timer();


textureLoader rock;


fallingObject::fallingObject()
{
    verticies[0].x = 0.0;verticies[0].y = 0.0;verticies[0].z = -1.0;
    verticies[1].x = 1.0;verticies[1].y = 0.0;verticies[1].z = -1.0;
    verticies[2].x = 1.0;verticies[2].y = 1.0;verticies[2].z = -1.0;
    verticies[3].x = 0.0;verticies[3].y = 1.0;verticies[3].z = -1.0;



    xPos = (rand()%10)-5; //left 0.0
    yPos = (rand()%2)+3;//top 2.0
    maxObjectX= 1.0;//right
    maxObjectY = -4.0; //bottom
    objectSpeedX = 0.0;
    objectSpeedY = 0.06;




}

fallingObject::~fallingObject()
{
    //dtor
}


void fallingObject::drawFallObject()
{
    rockTex->binder();
    glBegin(GL_QUADS);

    glTexCoord2f(0.0,1.0);
    glVertex3f(verticies[0].x,verticies[0].y,verticies[0].z);

    glTexCoord2f(1.0,1.0);
    glVertex3f(verticies[1].x,verticies[1].y,verticies[1].z);

    glTexCoord2f(1.0,0.0);
    glVertex3f(verticies[2].x,verticies[2].y,verticies[2].z);

    glTexCoord2f(0.0,0.0);
    glVertex3f(verticies[3].x,verticies[3].y,verticies[3].z);

    glEnd();


}

void fallingObject::fallingObjectInit(char *FileName)
{
 glEnable(GL_BLEND);
    glBlendFunc(GL_SRC_ALPHA,GL_ONE_MINUS_SRC_ALPHA);

    this->rockTex->binder();
    this->rockTex->bindTexture(FileName);



    //rock[0].bindTexture("images/rock.png");

}
void fallingObject::fallingObjectUpdate()
{

       glPushMatrix();
       glTranslated(xPos,yPos,-1.0);
       rock.binder();
       drawFallObject();
       glPopMatrix();

        yPos = yPos - objectSpeedY;
        if(yPos < maxObjectY)
            yPos = (rand()%2)+3;


  }





