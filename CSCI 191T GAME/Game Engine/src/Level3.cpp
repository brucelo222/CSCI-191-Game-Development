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
}

void Level3::Draw(Player *player)
{
    drawBackground(50,15);
    drawPlayer(player);
    drawEnemies();
    //Draw(player,50,15);
}
