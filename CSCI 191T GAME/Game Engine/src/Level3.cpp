#include "Level3.h"

Level3::Level3()
{
    //ctor
}

Level3::~Level3()
{
    //dtor
}

void Level3::Init(Player *player, char* fileName)
{
    setNumComods(10);
    initBackground(fileName);
    initPlayer(player);
    initEnemies();

    stg1_platform1->initPlatform(-6.0,-7.0,30.0,-30.0);

    platforms[0] = stg1_platform1;
}

void Level3::Draw(Player *player)
{
    drawBackground(50,15);
    drawPlayer(player);
    drawEnemies();
    //Draw(player,50,15);
}
