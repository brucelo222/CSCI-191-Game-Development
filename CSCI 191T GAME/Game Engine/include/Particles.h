#ifndef PARTICLES_H
#define PARTICLES_H

#include <Vector.h>
#include <math.h>
#include <stdlib.h>
#include <iostream>

#define MAX_DROPS 1000
#define GRAVITY -0.001

using namespace std;

class Particles
{
    public:
        Particles();
        virtual ~Particles();

    typedef struct
    {
        bool alive;
        float xpos;
        float ypos;
        float zpos;
        float xDir;
        float yDir;
        float mass;
    }particle;

    particle drops[MAX_DROPS];

    int NumDrops;
    void draw();
    void lifeTime();
    void generateParticles(Vec2);
    double dRand();

    private:
};

#endif // PARTICLES_H
