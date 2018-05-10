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

    protected:

    private:
};

#endif // LEVEL2_H
