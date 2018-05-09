#ifndef GAMELOOP_H
#define GAMELOOP_H

#include "Inputs.h"
#include "Player.h"
#include "Camera2D.h"
#include "Timer.h"
#include "Collision.h"
#include "Title.h"
#include "Level1.h"
#include "Level2.h"

#include "Particles.h"

#include <windows.h>
#include <GL/glut.h>

enum GameState{PLAY,QUIT};
enum SceneState{TITLE,LEVEL1,LEVEL2};

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
        SceneState sceneState;
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
        Title *_title = new Title();
        Level1 *_level1 = new Level1();
        Level2 *_level2 = new Level2();
};

#endif // GAMELOOP_H
