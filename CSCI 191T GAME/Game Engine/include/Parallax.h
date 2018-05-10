#ifndef PARALLAX_H
#define PARALLAX_H

#include <iostream>
#include <string.h>
#include <gl/gl.h>
#include <windows.h>
#include <Texture.h>
using namespace std;

class Parallax
{
    public:
        Parallax();
        virtual ~Parallax();
        void drawSquare(float,float);
        void parallaxInit(char *);
        void scroll(bool,string,float);

        Texture* bTex = new Texture();

        float Xmax,Ymax,Xmin,Ymin;
    protected:

    private:
};

#endif // PARALLAX_H
