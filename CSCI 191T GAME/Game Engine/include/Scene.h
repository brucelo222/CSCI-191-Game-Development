#ifndef SCENE_H
#define SCENE_H

#include "string"

#include "Texture.h"
#include "Enemy.h"
#include "Comodo.h"
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

        vector<Enemy*> getHellHounds(){return _Hounds;};
        void setNumHellHounds(int size)
        {
        numHellHounds = size;
        for (int i = 0; i < numHellHounds; i++)
            {
                _Hounds.push_back(new Enemy);
            }
        };

        vector<Comodo*> getComodos(){return _Comodo;};
        void setNumComods(int size)
        {
        numComodos = size;
        for (int i = 0; i <numComodos; i++)
            {
                _Comodo.push_back(new Comodo);
            }
        };

    private:
        //create a background class with struct that contains background textures, middle, fore, background
        Texture *_backgroundTexture = new Texture();
        Graphics *_shape = new Graphics();
        //array of enemies
        //create a data class that has level data
        int numHellHounds;
        int numComodos;
        vector<Enemy*> _Hounds;
        vector<Comodo*> _Comodo;
};

#endif // SCENE_H
