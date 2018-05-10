#ifndef LEVEL3_H
#define LEVEL3_H

#include "Scene.h"

class Level3 : public Scene
{
    public:
        Level3();
        virtual ~Level3();

        void Init(Player*, char*);
        void Draw(Player*);

        platform *stg1_platform1=new platform;

        platform *platforms[1];

    private:
};

#endif // LEVEL3_H
