
#define STAGES_H

#include <SOIL.h>
#include <GL/gl.h>
#include "Texture.h"
class stages
{
    public:
        stages();
        virtual ~stages();

        void stagesInit(char*, float, float, float,float);
        void draw();
        float x;
        float y;
        float xSize;
        float ySize;
        Texture* stage1 = new Texture();
    private:

};
