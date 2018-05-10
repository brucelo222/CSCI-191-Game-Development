#ifndef AGENT_H
#define AGENT_H
#include <Vector.h>
#include "Graphics.h"
#include "Timer.h"
enum Direction{LEFT,RIGHT};
enum Action{RUNR,RUNL,STANDR,STANDL,ATKR,ATKL,JUMP,JUMPLEFT,JUMPRIGHT,FREEFALL,UP};
class Agent
{
    public:
        Agent();
        virtual ~Agent();

        virtual void Init() = 0;
        void Draw();
        void Collision(Vec2);

        void setPosition(float x, float y){ this->_Position.x = x; this->_Position.y = y;};
        Vec2 getPosition(){return _Position;};

        void setDirection(Direction newDir){ this->_dir = newDir;};
        Direction getDirection(){return _dir;};

        void setAction(Action action){this->actionTrigger = action;};
        Action getAction(){return this->actionTrigger;};

        void setAttacking(bool toggle){this->isAttacking = toggle;};
        bool getAttacking(){return this->isAttacking;};

        Timer *T = new Timer();
        int runspeed;
    private:
        Vec2 _Position;
        Direction _dir;
        Action actionTrigger;
        Graphics *_shape = new Graphics();
        bool isAttacking;
};
#endif // AGENT_H
