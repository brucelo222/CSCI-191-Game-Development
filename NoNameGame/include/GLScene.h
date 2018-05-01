#ifndef GLSCENE_H
#define GLSCENE_H

#include <windows.h>
#include <parallax.h>
#include <fallingObject.h>
#include <stage1.h>

#include<gl/gl.h>
#include<iostream>
#include "collider.h"
#include "platform.h"
using namespace std;

class GLScene
{
    public:
        GLScene();
        virtual ~GLScene();
        GLint initGL();
        GLint drawGLScene();
        GLvoid resizeGLScene(GLsizei, GLsizei);

        int setStage;

        bool init;

        parallax* stg1_1 = new parallax();
        parallax* stg1 = new parallax();
        parallax* fog = new parallax ();
        parallax* fog2 = new parallax();
        parallax* stg1_2 = new parallax();

        fallingObject *fRock = new fallingObject();// xpos and ypos
        fallingObject *fRock1 = new fallingObject();
        fallingObject *fRock2 = new fallingObject();
        fallingObject *fRock3 = new fallingObject();
        fallingObject *fRock4 = new fallingObject();
        fallingObject *fRock5 = new fallingObject();

        collider *collision= new collider();
        platform *s1plf1= new platform();
        platform *s1plf2= new platform();
        platform *s1plf3= new platform();
        platform *s1plf4= new platform();


        int windMsg(HWND,UINT, WPARAM,LPARAM);
        int platformCollide;
        int i;
        int collideSum;
         platform * platforms[4];

        WPARAM wParam;
        float screenHeight;
        float screenWidth;
    protected:

    private:
};

#endif // GLSCENE_H
