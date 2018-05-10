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

    protected:

    private:
};

#endif // LEVEL3_H
