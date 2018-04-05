#ifndef GLSCENE_H
#define GLSCENE_H

#include <windows.h>
#include <parallax.h>
#include <fallingObject.h>
#include <stage1.h>

#include<gl/gl.h>
#include<iostream>

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














        int windMsg(HWND,UINT, WPARAM,LPARAM);


        WPARAM wParam;
        float screenHeight;
        float screenWidth;
    protected:

    private:
};

#endif // GLSCENE_H
