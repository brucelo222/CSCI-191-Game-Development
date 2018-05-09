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

    protected:

    private:
};

#endif // LEVEL1_H
