#include "platformCollision.h"
#include <iostream>
platformCollision::platformCollision()
{
    //ctor
}

platformCollision::~platformCollision()
{
    //dtor
}
int platformCollision::collision(Player * ply, platform * plf){


     float plyX=ply->getPosition().x;

    float plyY=ply->getPosition().y;
    float pTop=plyY+0.285;
    float pBottom=plyY-0.285;
    float pLeft=plyX-0.15;
    float pRight=plyX+0.15;

    if(pBottom<=plf->yTop&&pBottom>=plf->yTop-0.4){

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
