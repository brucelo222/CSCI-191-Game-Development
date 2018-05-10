#include "platformCollision.h"
#include <iostream>

using namespace std;
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
    float pTop=plyY+0.2;
    float pBottom=plyY-0.2;
    float pLeft=plyX-0.1;
    float pRight=plyX+0.1;

   // cout<<"playerx "<<pBottom<<" "<<plyX<<endl;
    //cout<<"playery "<<pBottom<<" "<<plyY<<endl;
    //cout<<"platformT "<<plf->yTop<<endl;
    //cout<<"platformL "<<plf->xLeft<<endl;
    //cout<<"platformB "<<plf->yBottom<<endl;
    //cout<<"platformR "<<plf->xRight<<endl;

    if(pBottom<=plf->yTop&&pBottom>=plf->yTop-0.4){

            if((pRight<=plf->xLeft&&pLeft<=plf->xLeft)||(pRight>=plf->xRight&&pLeft>=plf->xRight)){
                return 0;
                //cout<<"made it\n";
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
