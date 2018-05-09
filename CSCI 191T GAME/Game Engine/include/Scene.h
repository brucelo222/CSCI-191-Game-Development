#ifndef SCENE_H
#define SCENE_H

#include "string"

#include "Texture.h"
#include "Enemy.h"
#include "Player.h"

//temp
#include "Graphics.h"


class Scene
{
    public:
        Scene();
        virtual ~Scene();

        void Init(Player*);
        void Draw(Player*);
        void Update(Player*);

        void initBackground();
        void drawBackground();
        void initPlayer(Player*);
        void drawPlayer(Player*);
        void initEnemies();
        void drawEnemies();

        Enemy *getEnemies(){return _enemies;};

    private:
        //create a background class with struct that contains background textures, middle, fore, background
        Texture *_backgroundTexture = new Texture();
        Graphics *_shape = new Graphics();
        //array of enemies
        //create a data class that has level data
        int numEnemies = 100;
        Enemy _enemies[100];
};

#endif // SCENE_H
