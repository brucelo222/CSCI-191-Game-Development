#include "Agent.h"

#include <GL/gl.h>

Agent::Agent()
{
    //ctor
}

Agent::~Agent()
{
    //dtor
}

void Agent::Draw()
{
    //glLoadIdentity();
    glTranslated(_Position.x,_Position.y,-1.0);
    _shape->drawQuad(1.5,1.5,-1.0,Color(1.0,1.0,1.0,1.0));
}
