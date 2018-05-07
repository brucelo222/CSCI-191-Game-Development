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

void Agent::Draw(float width, float height)
{
    //glLoadIdentity();
    glTranslated(_Position.x,_Position.y,-1.0);
    _shape->drawQuad(width,height,-1.0,Color(1.0,1.0,1.0,1.0));
}

float Agent::Accelerate()
{
    setAceleration((getMaxSpeed().x - getVelocity().x)/2, 0);
    setVelocity((getVelocity().x + getAceleration().x),0);
    return getVelocity().x;
}

float Agent::Decelerate()
{
    setAceleration((0 - getVelocity().x)/2, 0);
    setVelocity((getVelocity().x + getAceleration().x),0);
    return getVelocity().x;
}

