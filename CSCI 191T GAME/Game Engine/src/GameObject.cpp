#include "GameObject.h"

GameObject::GameObject()
{
    //ctor
    _hitbox->active = true;
    _Position.x = 0;
    _Position.y = 0;
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

    this->_Position.x = x;
    this->_Position.y = y;
    _hitbox->init(_Position,1.0,1.0);
}

void GameObject::Draw(float width, float height)
{
    _object->binder();
    _hitbox->update(_Position);
    glTranslated(_Position.x,_Position.y,-2.0);
    _shape->drawQuad(width,height,-1.0,Color(1.0,1.0,1.0,1.0));
}

