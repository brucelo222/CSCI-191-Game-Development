#ifndef AI_H
#define AI_H

#include "Vector.h"


class AI
{
    public:
        AI();
        virtual ~AI();

        enum State{IDLE,PATROL,CHASE};

        void aiManager(Vec2, Vec2);


        State getState(){return _currentState;};
        void setState(State state){_currentState = state;};
    private:
        State _currentState;
};

#endif // AI_H
