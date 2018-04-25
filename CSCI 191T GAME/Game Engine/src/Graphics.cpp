#include "Graphics.h"

#include <GL/gl.h>

Graphics::Graphics()
{
    //ctor
}

Graphics::~Graphics()
{
    //dtor
}

void Graphics::drawQuad(float width, float height, float Layer, Color color)
{
    glColor4f(color.r, color.g, color.b, color.a);
	glBegin(GL_QUADS);

    glTexCoord2f(0.0f, 0.0f);
	glVertex3f(-width * 0.5f, +height * 0.5f, Layer);
	glTexCoord2f(0.0f, 1.0f);
	glVertex3f(-width * 0.5f, -height * 0.5f, Layer);
	glTexCoord2f(1.0f, 1.0f);
	glVertex3f(+width * 0.5f, -height * 0.5f, Layer);
	glTexCoord2f(1.0f, 0.0f);
	glVertex3f(+width * 0.5f, +height * 0.5f, Layer);

	glEnd();
}


void Graphics::drawTriangle(float width, float height, float Layer, Color color)
{
    glColor4f(color.r, color.g, color.b, color.a);
    glDisable(GL_LIGHTING);
	glBegin(GL_TRIANGLES);

	glVertex3f(-width, -height, Layer);
	glVertex3f(+width, -height, Layer);
	glVertex3f(width-width,height, Layer);
    glEnable(GL_LIGHTING);
	glEnd();
}
