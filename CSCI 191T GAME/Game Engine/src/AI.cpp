#include "AI.h"

#include <iostream>

using namespace std;


AI::AI()
{
    //ctor
    _currentState = IDLE;
}

AI::~AI()
{
    //dtor
}

void AI::aiManager(Vec2 playerPOS, Vec2 enemyPOS)
{
    // set AI state
    if (playerPOS.length(playerPOS,enemyPOS) <= 3 && playerPOS.length(playerPOS,enemyPOS) >= .75)
    {
        setState(CHASE);
    }
    else if(playerPOS.length(playerPOS,enemyPOS) <= 1)
    {
        setState(ATTACK);
    }
    else
    {
        setState(IDLE);
    }
return;
}


