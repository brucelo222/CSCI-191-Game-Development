#ifndef GAMELOOP_H
#define GAMELOOP_H

#include "Graphics.h"
#include "Inputs.h"
#include "Player.h"
#include "Camera2D.h"
#include "Enemy.h"

#include "Texture.h"
#include "Particles.h"
#include "stages.h"
#include <windows.h>
#include <GL/glut.h>
#include "platform.h"
#include "platformCollision.h"

enum GameState{PLAY,QUIT};

class GameLoop
{
    public:
        GameLoop();
        virtual ~GameLoop();
        GLint Initialize();
        GLvoid resizeScreen(GLsizei, GLsizei);
        void Render();
        void Update();
        void winInputs(HWND,UINT, WPARAM,LPARAM);
        GLint gameLoop();

        GameState gameState;
    private:
        float _screenHeight;
        float _screenWidth;

        //Graphics *_shape = new Graphics();
        Inputs *_input = new Inputs();
        Player *_player = new Player();
        //replace texture pointers with texture manager pointer that loads all game textures
        Texture *_backgroundTexture = new Texture();
        Texture *_leftPlayer = new Texture();
        Texture *_rightPlayer = new Texture();
        //end of texture pointers
        Graphics* _shape = new Graphics();
        Camera2D* _camera = new Camera2D();
        Enemy* _enemy = new Enemy();
        Particles *p = new Particles();

        stages *stg1= new stages();
        stages* background=new stages();
        stages* background2=new stages();
        stages* background3=new stages();
        stages* background4=new stages();
        stages* background5=new stages();
        stages* background6=new stages();
        stages* background7=new stages();//8
        stages* platform2=new stages();
        stages* platform3=new stages();
        stages* platform4=new stages();
        stages* platform5=new stages();
        stages* platform6=new stages();
        stages* platform7=new stages();
        stages* platform8=new stages();//15

        stages* block= new stages();
        stages* block1= new stages();

        stages* p1=new stages();
        stages* p2=new stages();
        stages* p3=new stages();
        stages* p4=new stages();
        stages* p5=new stages();
        stages* p6=new stages();//23

        stages* p7=new stages();
        stages* p8=new stages();
        stages* p9=new stages();
        stages* p10=new stages();
        stages* p11=new stages();
        stages* p12=new stages();

        stages* bridge1=new stages();//30
        stages* bridge2=new stages();
        stages* bridge3=new stages();
        stages* bridge4=new stages();//33

        stages* stage1=new stages();//33
        stages* allPlatforms[33];
        int i;
        platform *stg1_platform1=new platform;
        platform *stg1_platform2=new platform;
        platform *stg1_platform3=new platform;
        platform *stg1_platform4=new platform;
        platform *stg1_platform5=new platform;
        platform *stg1_platform6=new platform;
        platform *stg1_platform7=new platform;
        platform *stg1_platform8=new platform;

        platformCollision * collision=new platformCollision();
        int collideSum;
        platform * platforms[8];
};

#endif // GAMELOOP_H
