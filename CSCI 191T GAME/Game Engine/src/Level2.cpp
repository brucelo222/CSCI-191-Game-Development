#include "Level2.h"

Level2::Level2()
{
    //ctor
}

Level2::~Level2()
{
    //dtor
}

void Level2::Init(Player *player, char* fileName)
{
    setNumComods(5);
    setNumHellHounds(5);
    initBackground(fileName);
    initPlayer(player);
    initEnemies();
    initGoal("images/entrance",18,0);

    stg1_platform1->initPlatform(-5.5,-7.0,20.0,-20.0);

    platforms[0] = stg1_platform1;
}

void Level2::Draw(Player *player)
{
    drawBackground(50,15);
    drawPlayer(player);
    drawEnemies();
    drawGoal();
}
