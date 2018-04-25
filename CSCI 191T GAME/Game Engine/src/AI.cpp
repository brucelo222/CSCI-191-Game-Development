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
    if (playerPOS.length(playerPOS,enemyPOS) <= 3)
    {
        setState(CHASE);
        //cout<<"chase"<<endl;
    }
    else
    {
        setState(IDLE);
           //     cout<<"idle"<<endl;
    }
return;
}


