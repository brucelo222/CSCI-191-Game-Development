#ifndef SCENE_H
#define SCENE_H

#include "string"

#include "Texture.h"
#include "Enemy.h"
#include "Comodo.h"
#include "Player.h"
#include "Vector.h"
#include "platform.h"
#include "Particles.h"

#include <vector>

//temp
#include "Graphics.h"
#include "GameObject.h"

class Scene
{
    public:
        Scene();
        virtual ~Scene();

        void Init(Player*, char*);
        void Draw(Player*,int,int);
        void Update(Player*);

        void initGoal(char*,float,float);
        void drawGoal();
        void initBackground(char*);
        void drawBackground(int, int);
        void initPlayer(Player*);
        void drawPlayer(Player*);
        void initEnemies();
        void drawEnemies();
        void drawPlatforms(platform*);
        void drawParticles(Vec2);

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

        vector<platform*> getPlatforms(){return _Platforms;};
        void setNumPlatforms(int size)
        {
        numPlatforms = size;
        for (int i = 0; i <numPlatforms; i++)
            {
                _Platforms.push_back(new platform);
            }
        };
        GameObject *_goal = new GameObject();
        Vec2 startPOS;
        void setInitialPOS(Player* player){player->setPosition(startPOS.x,startPOS.y);};
        bool spawn;
    private:
        //create a background class with struct that contains background textures, middle, fore, background
        Texture *_backgroundTexture = new Texture();
        Graphics *_shape = new Graphics();
        //array of enemies
        int numHellHounds;
        int numComodos;
        int numPlatforms;
        vector<platform*> _Platforms;
        vector<Enemy*> _Hounds;
        vector<Comodo*> _Comodo;
};

#endif // SCENE_H
