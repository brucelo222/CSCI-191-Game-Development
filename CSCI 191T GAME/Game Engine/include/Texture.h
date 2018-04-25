#ifndef TEXTURE_H
#define TEXTURE_H

#include <SOIL.h>
#include <GL/gl.h>

class Texture
{
    public:
        Texture();
        virtual ~Texture();

        void bindTexture(char*);
        void binder();

    private:
        unsigned char* image;
        int width, height;
        GLuint tex;
};

#endif // TEXTURE_H
