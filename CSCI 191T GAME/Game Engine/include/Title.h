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
};

#endif // TITLE_H
