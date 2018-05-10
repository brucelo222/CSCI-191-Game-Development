#include "Inputs.h"
#include <iostream>

Inputs::Inputs()
{
    //ctor
    _mouseCoords.x = 0.0;
    _mouseCoords.y = 0.0;
}

Inputs::~Inputs()
{
    //dtor
}

void Inputs::keyPressed(Player* player)
{
    switch(_wParam)
    {
    case VK_LEFT:


        player->setDirection(LEFT);
        if(player->isJump==false){
        player->setAction(RUNL);
            if(player->leftStop!=true){
            player->setPosition(player->getPosition().x -0.1, player->getPosition().y);
            }
        }
        else{
             player->setAction(JUMPLEFT);

        }
    break;
    case VK_RIGHT:

        player->setDirection(RIGHT);
        if(player->isJump==false){
        player->setAction(RUNR);
            if(player->rightStop!=true){
        player->setPosition(player->getPosition().x + 0.1, player->getPosition().y);
            }
        }
        else{
            player->setAction(JUMPRIGHT);
        }
    break;
    case 0x58:
        if (player->getDirection() == RIGHT)
        {
            player->setAction(ATKR);
        }
        else
        {
            player->setAction(ATKL);
            player->setAttacking(true);
        }
    break;
    case VK_SPACE:
        player->setAction(STANDR);
        player->setAttacking(true);
    break;
    case 0X26:
        player->setAction(JUMP);

        //player->setPosition(player->getPosition().x, player->getPosition().y+0.1);
    //std::cout<<"jump"<<std::endl;
    break;
    case 0x57:
        player->setPosition(player->getPosition().x, player->getPosition().y+0.4);
    default:break;

    }

}

void Inputs::keyReleased(Player* player)
{
    /*if(player->getAttacking()==true)
    {

    }
    else if(player->getDirection() == RIGHT)
    {
        player->setAction(STANDR);
    }
    else if(player->getDirection() == LEFT)
    {
        player->setAction(STANDL);
    }
    else
    {
       player->setAction(STANDR);
    }*/
switch(_wParam)
    {
    case VK_LEFT:


        player->setDirection(LEFT);
        if(player->isJump==false){
        player->setAction(STANDL);
        }
        else{
             player->setAction(FREEFALL);

        }
    break;
    case VK_RIGHT:

        player->setDirection(RIGHT);
        if(player->isJump==false){
        player->setAction(STANDR);
        }
        else{
            player->setAction(FREEFALL);
        }
    break;


    case 0X26:
        player->setAction(FREEFALL);

        //player->setPosition(player->getPosition().x, player->getPosition().y+0.1);
    //std::cout<<"jump"<<std::endl;
    break;

    case 0x57:
        player->setAction(STANDL);
    default:break;

}
}

void Inputs::setMouseCoords(Player* player, float x, float y)
{
   		_mouseCoords.x = x;
		_mouseCoords.y = y;
}

void Inputs::mouseEvent(Player* player, float x, float y)
{
    _mouseCoords.x = x;
    _mouseCoords.y = y;

        switch(_wParam)
        {
            case MK_LBUTTON:
               // player->setPosition(x,y);
                //std::cout<<"left mouse button"<<std::endl;
            break;


        }
}

