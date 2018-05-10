#ifndef LEVEL2_H
#define LEVEL2_H

#include "Player.h"
#include "Scene.h"


class Level2 : public Scene
{
    public:
        Level2();
        virtual ~Level2();

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

    protected:

    private:
};

#endif // LEVEL2_H
