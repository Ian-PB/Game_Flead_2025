#pragma once

#include "raylib.h"
#include "stdio.h"

#include "../include/ParticleSpawner.h"

class Projectile
{
public:
    Projectile(Vector3 t_pos, Vector3 t_targetPos);
    void draw();
    void update();

    
    bool isActive() { return active; }
    
private:
    void moveToTarget();
    void hit();

    bool active = false;
    bool explode = false;

    Vector3 position;
    float radius = 0.1f;
    float speed = 0.1f;

    Vector3 targetPos;
};