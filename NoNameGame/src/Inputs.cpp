#include "Inputs.h"
#include <player.h>

Inputs::Inputs()
{
    //ctor
   prev_Mouse_X =0;
   prev_Mouse_Y =0;
   Mouse_Translate=0;
   Mouse_Roatate=0;
}

Inputs::~Inputs()
{
    //dtor
}
void Inputs::keyEnv(parallax* plx, float speed)
{
    switch(wParam)
    {
        case VK_LEFT:
       //     plx->Xmin -=speed;
       //     plx->Xmax -=speed;
            break;

        case VK_RIGHT:
         //   plx->Xmin +=speed;
          //  plx->Xmax +=speed;
            break;

         case VK_UP:
          //  plx->Ymin -=speed;
          //  plx->Ymax -=speed;
            break;

        case VK_DOWN:
          //  plx->Ymin +=speed;
          //  plx->Ymax +=speed;
            break;

    }
}


void Inputs::keyPressed(Model* Mdl)
{
    switch(wParam)
    {
    case VK_LEFT:
        Mdl->RotateX +=1.0;
        break;

    case VK_RIGHT:
        Mdl->RotateX -=1.0;
        break;

    case VK_DOWN:
        Mdl->RotateY -=1.0;
        break;

    case VK_UP:
        Mdl->RotateY +=1.0;
        break;

    case VK_ADD:
        Mdl->Zoom +=1.0;
        break;

    case VK_SUBTRACT:
        Mdl->Zoom -=1.0;
        break;
    }
}


/***** Player Key is Up ***/
void Inputs::keyUp(player* ply)
{
    ply->actionTrigger = 0;
   // if(ply->actionTrigger == 2){
   // ply->actionTrigger = 3;
   // }

    //else if (ply->actionTrigger == 1){
      //  ply->actionTrigger = 0;
    //}


        //ply->isJump = false;




    switch(wParam)
    {

      /* case 0x41://A
       ply->actionTrigger = 3;
        break;

          case 0x44://D
       ply->actionTrigger = 0;
        break;*/


    case VK_RIGHT:

        //ply->isJump = false;

        if((ply->getPlyPosY() > ply->jpGround) && (ply->isJump == false)){
         ply->jpVelo += ply->gravity;

        }
        if(ply->mY == ply->jpGround){
            ply->jpVelo = 0.0;
           ply->mY = ply->jpGround;
        }


        break;


       default:break;
    }
}

/************Player input Pressed*******/
void Inputs::keyPressed(player* ply)
{
    switch(wParam)
    {
        case 0x41://A
       ply->actionTrigger = 2;
        //ply->mX-= ply->xSpeed;
       // ply->maxMX-= ply->xSpeed;
        break;

/*     case VK_LEFT:
       ply->actionTrigger = 2;
        //ply->mX-= ply->xSpeed;
       // ply->maxMX-= ply->xSpeed;
        break;*/

    case 0x44://D
       ply->actionTrigger = 1;
        //ply->mX+= ply->xSpeed;
       // ply->maxMX+= ply->xSpeed;
        break;

        case VK_RIGHT:
        ply->actionTrigger = 4;


        break;

    case VK_DOWN:
         ply->actionTrigger = 5;

        break;

    case VK_UP:

        break;

    case VK_ADD:

        break;

    case VK_SUBTRACT:

        break;
    }
}


void Inputs::keyUP()
{

  switch (wParam)
            {
                default:
                break;
            }
}

void Inputs::mouseEventDown(Model *Model, double x,double y)
{
        prev_Mouse_X =x;
        prev_Mouse_Y =y;

   switch (wParam)
            {
                case MK_LBUTTON:
                        Mouse_Roatate = true;
                    break;

                case MK_RBUTTON:
                     Mouse_Translate =true;
                    break;
                case MK_MBUTTON:

                    break;

                default:
                    break;
            }
}

 void Inputs::mouseEventUp()
 {
    Mouse_Translate =false;
    Mouse_Roatate =false;
 }

void Inputs::mouseWheel(Model *Model,double Delta)
{
    Model->Zoom += Delta/100;
}

void Inputs::mouseMove(Model *Model,double x,double y)
{
      if(Mouse_Translate)
      {
       Model->Xpos += (x-prev_Mouse_X)/100;
       Model->Ypos -= (y-prev_Mouse_Y)/100;

       prev_Mouse_X =x;
       prev_Mouse_Y =y;
      }

      if(Mouse_Roatate)
      {
        Model->RotateY += (x-prev_Mouse_X)/3;
        Model->RotateX += (y-prev_Mouse_Y)/3;

        prev_Mouse_X =x;
        prev_Mouse_Y =y;
      }
}
void Inputs::keyPressed(skyBox* sky)
{
    switch(wParam)
    {
     case VK_LEFT:
       sky->RotateY += 0.5;
        break;

    case VK_RIGHT:
       sky->RotateY -= 0.5;
        break;

    case VK_DOWN:
         sky->RotateX += 0.5;
        break;

    case VK_UP:
         sky->RotateX -= 0.5;
        break;
    }
}

void Inputs::mouseMove(skyBox* sky, double x, double y)
{

        sky->RotateY += (x-prev_Mouse_X)/3;
        sky->RotateX += (y-prev_Mouse_Y)/3;

        prev_Mouse_X =x;
        prev_Mouse_Y =y;

}

void Inputs::keySound(sounds* snds)
{
    switch(wParam){
    case VK_SPACE:
        snds->playSound("sfx/");
        break;



    }

}
