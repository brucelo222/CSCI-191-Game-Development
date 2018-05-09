#ifndef SCENE_H
#define SCENE_H

#include "string"

#include "Texture.h"
#include "Enemy.h"
#include "Player.h"

#include <vector>

//temp
#include "Graphics.h"


class Scene
{
    public:
        Scene();
        virtual ~Scene();

        void Init(Player*, char*);
        void Draw(Player*,int,int);
        void Update(Player*);

        void initBackground(char*);
        void drawBackground(int, int);
        void initPlayer(Player*);
        void drawPlayer(Player*);
        void initEnemies();
        void drawEnemies();

        vector<Enemy*> getEnemies(){return _enemies;};
        void setNumEnemies(int size)
        {
        numEnemies = size;
        for (int i = 0; i <numEnemies; i++)
            {
                _enemies.push_back(new Enemy);
            }
        };

    private:
        //create a background class with struct that contains background textures, middle, fore, background
        Texture *_backgroundTexture = new Texture();
        Graphics *_shape = new Graphics();
        //array of enemies
        //create a data class that has level data
        int numEnemies;
        vector<Enemy*> _enemies;
};

#endif // SCENE_H
