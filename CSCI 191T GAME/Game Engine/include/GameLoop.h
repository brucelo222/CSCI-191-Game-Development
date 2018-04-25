#ifndef GAMELOOP_H
#define GAMELOOP_H

#include "Graphics.h"
#include "Inputs.h"
#include "Player.h"
#include "Camera2D.h"
#include "Enemy.h"

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



};

#endif // GAMELOOP_H
