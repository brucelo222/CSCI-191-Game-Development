#ifndef INPUTS_H
#define INPUTS_H

#include "Vector.h"
#include "Player.h"
#include <Graphics.h>

#include <windows.h>
#include <GL/gl.h>

class Inputs
{
    public:
        Inputs();
        virtual ~Inputs();
        void keyPressed(Player *);
        void keyReleased(Player *);

        void setMouseCoords(Player *,float,float);
        void mouseEvent(Player *,float,float);

        void setWPARAM(WPARAM wParam){_wParam = wParam;};

    private:

       Vec2 _mouseCoords;
       WPARAM _wParam;
};

#endif // INPUTS_H
