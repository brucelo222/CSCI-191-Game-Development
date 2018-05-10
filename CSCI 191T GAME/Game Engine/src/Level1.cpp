#include "Level1.h"
#include "iostream"
Level1::Level1()
{
    //ctor
}

Level1::~Level1()
{
    //dtor
}

void Level1::Init(Player *player, char* fileName)
{
    setNumComods(20);
    initBackground(fileName);
    initPlayer(player);
    initEnemies();
    initGoal("images/entrance.png",18,-5);

}

void Level1::Draw(Player *player)
{
    drawBackground(50,15);
    drawPlayer(player);
    drawEnemies();
    drawGoal();
}
