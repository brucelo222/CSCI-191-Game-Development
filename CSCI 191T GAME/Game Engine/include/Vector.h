#ifndef VECTOR_H
#define VECTOR_H

#include <math.h>

using namespace std;

struct Vec3
{
    Vec3() : x(0.f), y(0.f), z(0.f) {}
    float x;
    float y;
    float z;
};

struct Vec2
{
    Vec2() : x(0.f), y(0.f) {}
	Vec2(float x, float y) : x(x), y(y) {}
    float x;
    float y;

    float length(Vec2 EnemyPOS, Vec2 PlayerPOS){return sqrt(pow((EnemyPOS.x - PlayerPOS.x), 2) + pow((EnemyPOS.y - PlayerPOS.y), 2));};
};


#endif // VECTOR_H
