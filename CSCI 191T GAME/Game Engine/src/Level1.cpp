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
    setNumComods(5);
    setNumHellHounds(10);
    initBackground(fileName);
    initPlayer(player);
    initEnemies();
    initGoal("images/entrance.png",18,-5);
    stg1_platform1->initPlatform(-5.0,-7.0,3.0,-20.0);
    stg1_platform2->initPlatform(-2.6,-5.6,-5.9,-10.1);
    stg1_platform3->initPlatform(-1.6,-5.6,10,5.6);
    stg1_platform4->initPlatform(-4.0,-7.0,18,9);
   // stg1_platform5->initPlatform(-0.4,-20.0,-3.3,-5.3);

    //stg1_platform6->initPlatform(-2.1,-20.0,-1.0,-3.3);

    //stg1_platform7->initPlatform(-2.7,-8.0,3.2,1.2);
    //stg1_platform8->initPlatform(-3.7,-8.0,5.79999,3.9);

    platforms[0] = stg1_platform1;
    platforms[1] =  stg1_platform2;
    platforms[2] = stg1_platform3;
    platforms[3] =  stg1_platform4;
    platforms[4] = stg1_platform5;
    platforms[5] =  stg1_platform6;
    platforms[6] = stg1_platform7;
    platforms[7] =  stg1_platform8;
}

void Level1::Draw(Player *player)
{
    drawBackground(50,15);
    drawPlayer(player);
    drawEnemies();
    drawGoal();
    drawPlatforms(*platforms);
}
