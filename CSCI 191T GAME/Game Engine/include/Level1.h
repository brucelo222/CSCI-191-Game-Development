#ifndef LEVEL1_H
#define LEVEL1_H

#include "Player.h"
#include "Scene.h"

class Level1 : public Scene
{
    public:
        Level1();
        virtual ~Level1();

        void Init(Player*, char*);
        void Draw(Player*);

        platform *stg1_platform1=new platform;
        platform *stg1_platform2=new platform;
        platform *stg1_platform3=new platform;
        platform *stg1_platform4=new platform;
        platform *stg1_platform5=new platform;
        platform *stg1_platform6=new platform;
        platform *stg1_platform7=new platform;
        platform *stg1_platform8=new platform;

        platform *platforms[8];



    private:

};

#endif // LEVEL1_H
