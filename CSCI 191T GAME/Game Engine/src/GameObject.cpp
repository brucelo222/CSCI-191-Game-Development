#include "GameObject.h"

GameObject::GameObject()
{
    //ctor
}

GameObject::~GameObject()
{
    //dtor
}

void GameObject::Init(char* fileName,float x, float y)
{
    glEnable(GL_BLEND);
    glBlendFunc(GL_SRC_ALPHA,GL_ONE_MINUS_SRC_ALPHA);//trans
    _object->bindTexture(fileName);

    _Position.x = x;
    _Position.y = y;
}

void GameObject::Draw(float width, float height)
{
    _object->binder();
    glTranslated(_Position.x,_Position.y,-2.0);
    _shape->drawQuad(width,height,-1.0,Color(1.0,1.0,1.0,1.0));
}

