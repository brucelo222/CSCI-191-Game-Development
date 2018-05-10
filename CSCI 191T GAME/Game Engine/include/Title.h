#ifndef TITLE_H
#define TITLE_H

#include "Scene.h"
#include "GameObject.h"

class Title : public Scene
{
    public:
        Title();
        virtual ~Title();

        void Init(char*);
        void Draw(Player*);

    private:
       GameObject* _play = new GameObject();
       GameObject* _help = new GameObject();
       GameObject* _exit = new GameObject();
};

#endif // TITLE_H
