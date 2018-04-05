#ifndef FALLINGOBJECT_H
#define FALLINGOBJECT_H

#include <Model.h>
#include <textureLoader.h>

typedef struct
{
   float x;
   float y;
   float z;
}vec2;

class fallingObject : public Model
{
    public:
        fallingObject();
        virtual ~fallingObject();

        float scalesize[3]={1.0,1.0,1.0};
        vec2 verticies[4];



        void drawFallObject();
        void fallingObjectInit(char* FileName);
        void fallingObjectUpdate();
        textureLoader* rockTex = new textureLoader();


        float xPos,yPos, maxObjectX,maxObjectY;
        float objectSpeedX,objectSpeedY;



    protected:

    private:
};

#endif // FALLINGOBJECT_H
