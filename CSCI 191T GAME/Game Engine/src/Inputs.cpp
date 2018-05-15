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

            case 0x48:
                sceneState->setScene(HELP);
            break;

            case VK_RETURN:
                sceneState->setScene(LEVEL1);
            break;
        }
    }

    if(sceneState->getScene() == PAUSE || sceneState->getScene() ==RETRY)
    {
        switch(_wParam)
        {
            case 0x52:
                sceneState->setScene(LEVEL1);
                player->setPosition(-18,-5);
                player->setHealth(100);
                player->isObjectLive = true;
                return;
            break;
            case VK_ESCAPE:
                sceneState->setScene(TITLE);
            break;
        }
    }

        if(sceneState->getScene() == LEVEL1 || sceneState->getScene() == LEVEL2 || sceneState->getScene() == LEVEL3)
        {
               switch(_wParam)
               {
            case VK_ESCAPE:
                sceneState->setScene(PAUSE);
                break;

            case VK_LEFT:
                player->setDirection(LEFT);
                if(player->isJump==false)
                {
                    player->setAction(RUNL);
                    if(player->leftStop!=true)
                    {
                        player->setPosition(player->getPosition().x -player->Accelerate(), player->getPosition().y);
                    }
                }
                else
                {
                     player->setAction(JUMPLEFT);

                }
               // player->setPosition(player->getPosition().x -0.1, player->getPosition().y);
            break;

            case VK_RIGHT:
                player->setDirection(RIGHT);
                if(player->isJump==false)
                {
                    cout<<player->rightStop<<endl;
                    player->setAction(RUNR);
                    if(player->rightStop!=true)
                    {
                        player->setPosition(player->getPosition().x + player->Accelerate(), player->getPosition().y);
                    }
                }
                else
                {
                    player->setAction(JUMPRIGHT);
                }
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
                player->setAction(JUMP);
            break;
               default:break;
            }
        }
}

void Inputs::keyReleased(Player* player)
{
    if(player->getAttacking()==true)
    {

    }
    switch(_wParam)
    {
        case VK_LEFT:

            player->setDirection(LEFT);
            if(player->isJump==false)
            {
                player->setAction(STANDL);
            }
            else
            {
                 player->setAction(FREEFALL);
            }
        break;
        case VK_RIGHT:

            player->setDirection(RIGHT);
            if(player->isJump==false)
            {
                player->setAction(STANDR);
            }
            else
            {
                player->setAction(FREEFALL);
            }
        break;


        case VK_SPACE:
            player->setAction(FREEFALL);
        break;

        default:
        break;
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

