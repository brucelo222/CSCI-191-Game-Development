#include "collider.h"
#include <iostream>
using namespace std;
collider::collider()
{
    //ctor
}

collider::~collider()

{
    //dtor
}
bool collider::checkCollision(player* ply, fallingObject* rock)
{
    float plyX=ply->mX;
    float plyY=ply->mY;
    float rockX=rock->xPos;
    float rockY=rock->yPos;

    //create AABB
    rockX=rockX-0.9;
    rockY=rockY-1.12;
    float pTop=plyY+0.625;
    float pBottom=plyY-0.625;
    float pLeft=plyX-0.23;
    float pRight=plyX+0.23;

    float rockTop=rockY+0.39;
    float rockBottom=rockY-0.39;
    float rockLeft=rockX-0.36;
    float rockRight=rockX+0.21;

    if(plyX>rockX){

    if(pLeft<=rockRight){
            if(plyY<rockY){
             if(pTop>=rockBottom){
            return true;
             }
        }
        if(plyY>rockY){
             if(pBottom<=rockTop){
            return true;
             }

            }
        }

    }
    else if(plyX<rockX){
     if(pRight>=rockLeft){

        if(plyY<rockY){
             if(pTop>=rockBottom){
            return true;
             }
        }
        if(plyY>rockY){
             if(pBottom<=rockTop){
            return true;
             }

            }
        }
    }

        return false;
}
int collider::platformCollision(player * ply, platform * plf){
     float plyX=ply->mX;
    float plyY=ply->mY;
    float pTop=plyY+0.625;
    float pBottom=plyY-0.625;
    float pLeft=plyX-0.23;
    float pRight=plyX+0.23;

    if(pBottom<=plf->yTop&&pBottom>=plf->yTop-0.2){

            if((pRight<=plf->xLeft&&pLeft<=plf->xLeft)||(pRight>=plf->xRight&&pLeft>=plf->xRight)){
                return 0;
            }
            else if(pRight>=plf->xLeft){
                return 1;
            }
            else if(pLeft<=plf->xRight){
                return 1;
            }

    }
    else if(pRight>=plf->xLeft&&pBottom<plf->yTop&&pLeft<plf->xLeft){
             if(plf->yBottom==-20.0){
            return 0;
        }
        return 2;
    }
    else if(pLeft<=plf->xRight&&pBottom<plf->yTop&&pRight>plf->xRight){
         if(plf->yBottom==-20.0){
            return 0;
         }
      return 4;
   }

    return 0;
}
