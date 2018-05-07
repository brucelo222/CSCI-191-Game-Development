#ifndef GAMELOOP_H
#define GAMELOOP_H

#include "Inputs.h"
#include "Player.h"
#include "Camera2D.h"
#include "Enemy.h"
#include "Timer.h"
#include "Collision.h"

//remove texture after scene classes are made.
#include "Texture.h"
#include "Particles.h"

#include <windows.h>
#include <GL/glut.h>

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
        //screen size variables
        float _screenHeight;
        float _screenWidth;

        //variables for fps limiter
        const int FPS = 60;
        const int frameDelay = 1000 / FPS;

        clock_t frameStart;
        int frameTime;
        Timer *_fpsTimer = new Timer();

        Inputs *_input = new Inputs();
        Player *_player = new Player();
        //replace texture pointers with texture manager pointer that loads all game textures
        //replace background texture in a scene class, the is inherited from by every scene
        Texture *_backgroundTexture = new Texture();
        //end of texture pointers
        Graphics* _shape = new Graphics();
        Camera2D* _camera = new Camera2D();
        Enemy* _enemies[20];
        Enemy* _enemy = new Enemy();
        Particles *p = new Particles();
        Collision *_collision = new Collision();



};

#endif // GAMELOOP_H
