#ifndef AGENT_H
#define AGENT_H

#include <Vector.h>

#include "Graphics.h"
#include "Timer.h"
#include "Hitbox.h"

enum Direction{LEFT,RIGHT};
enum Action{RUNR,RUNL,STANDR,STANDL,ATKR,ATKL,JMPR,JMPL};

class Agent
{
    public:
        Agent();
        virtual ~Agent();

        virtual void Init() = 0;
        void Draw(float, float);
        void Collision(Vec2);

        void setPosition(float x, float y){ this->_Position.x = x; this->_Position.y = y;};
        Vec2 getPosition(){return _Position;};

        void setPrevPosition(float x, float y){ this->_prevPOS.x = x; this->_prevPOS.y = y;};
        Vec2 getPrevPosition(){return _prevPOS;};

        void setDirection(Direction newDir){ this->_dir = newDir;};
        Direction getDirection(){return _dir;};

        void setAction(Action action){this->actionTrigger = action;};
        Action getAction(){return this->actionTrigger;};

        void setAttacking(bool toggle){this->isAttacking = toggle;};
        bool getAttacking(){return this->isAttacking;};

        void setVelocity(float x, float y){ this->_Velocity.x = x; this->_Velocity.y = y;};
        Vec2 getVelocity(){return _Velocity;};

        void setMaxSpeed(float x, float y){ this->_maxSpeed.x = x; this->_maxSpeed.y = y;};
        Vec2 getMaxSpeed(){return _maxSpeed;};

        void setAceleration(float x, float y){ this->_Acceleration.x = x; this->_Acceleration.y=y;};
        Vec2 getAceleration(){return _Acceleration;};

        void setHealth(int hp){health = hp;};
        int getHealth(){return health;};

        float Accelerate();
        float Decelerate();

        Timer *T = new Timer();
        Hitbox *_hitbox = new Hitbox();
        Hitbox *_hurtbox = new Hitbox();
        int runspeed;
        float atkDistance;
        float width, height;
        bool isObjectLive;

    private:
        int health;
        Vec2 _prevPOS;
        Vec2 _Position;
        Direction _dir;
        Action actionTrigger;
        Graphics *_shape = new Graphics();
        bool isAttacking;

        Vec2 _Velocity;
        Vec2 _maxSpeed;
        Vec2 _Acceleration;
};

#endif // AGENT_H
