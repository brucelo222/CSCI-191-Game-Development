#ifndef TITLE_H
#define TITLE_H

#include "Scene.h"
#include "GameObject.h"

class Title : public Scene
{
    public:
        Title();
        virtual ~Title();

        void Init();
        void Draw(Player*);

    private:
       GameObject _buttons[3];
};

#endif // TITLE_H
