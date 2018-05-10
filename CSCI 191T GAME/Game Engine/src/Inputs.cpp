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

void Inputs::keyPressed(Player* player, SceneManager* sceneState)
{
    if(sceneState->getScene() == TITLE)
    {
        switch(_wParam)
        {
            case VK_ESCAPE:
                exit(0);
            break;

            case 0x4E:
            break;

            case 0x48:
            break;

            case VK_RETURN:
            sceneState->setScene(LEVEL1);
            break;
        }
    }
    switch(_wParam)
    {
    case VK_LEFT:
        player->setAction(RUNL);
        player->setDirection(LEFT);
       // player->setPosition(player->getPosition().x -0.1, player->getPosition().y);
    break;
    case VK_RIGHT:
        player->setAction(RUNR);
        player->setDirection(RIGHT);
     //   player->setPosition(player->getPosition().x + 0.1, player->getPosition().y);
    break;
    case 0x58:
        player->setAttacking(true);
        if (player->getDirection() == RIGHT)
        {
            player->setAction(ATKR);
        }
        else
        {
            player->setAction(ATKL);
        }
    break;
    case VK_SPACE:
        if (player->getDirection() == RIGHT)
        {
            player->setAction(JMPR);
        }
        else
        {
            player->setAction(JMPL);
        }
    break;
       default:break;
    }
}

void Inputs::keyReleased(Player* player)
{
    if(player->getAttacking()==true)
    {

    }
    else if (player->getAttacking() == false)
    {
        if(player->getDirection() == RIGHT)
        {
            player->setAction(STANDR);
        }
        else if(player->getDirection() == LEFT)
        {
            player->setAction(STANDL);
        }
    }

    if(player->getDirection() == RIGHT)
    {
        player->setAction(STANDR);
    }
    else if(player->getDirection() == LEFT)
    {
        player->setAction(STANDL);
    }

    switch(_wParam)
    {
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
            break;


        }
}

