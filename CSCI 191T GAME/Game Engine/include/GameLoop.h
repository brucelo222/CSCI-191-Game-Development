#ifndef GAMELOOP_H
#define GAMELOOP_H

#include "Inputs.h"
#include "Player.h"
#include "Camera2D.h"
#include "Timer.h"
#include "Collision.h"

#include "Scene.h"
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

        Graphics* _shape = new Graphics();
        Camera2D* _camera = new Camera2D();
        Particles *p = new Particles();
        Collision *_collision = new Collision();
        Scene *_level1 = new Scene();



};

#endif // GAMELOOP_H
