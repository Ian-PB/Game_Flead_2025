#ifndef PLAYER_H
#define PLAYER_H

#include "raylib.h"
#include "stdio.h"
#include <math.h>
#include <memory>

#include "../include/Grapple.h"

class Player
{
public:
    Player();

    void update(Vector2 t_stickDir);
    void draw();

    Vector2& getPos() { return position; }

    // Grapple commands
    Grapple getGrapple() { return grapple; }
    void shootGrapple(std::shared_ptr<Object> t_target) { grapple.shoot(t_target, this->position); }
    void releaseGrapple(Vector2 t_releaseDir) { grapple.release(t_releaseDir); }

private:
    const int RADIUS = 50;

    Vector2 position;

    void screenWrapping();

    // Movement
    void move();
    void controllerMovement(Vector2 t_stickDir);
    void capSpeed();
    const float SPEED = 0.25;
    const int MAX_SPEED = 6;
    Vector2 velocity;
    const float FRICTION = 0.9f;

    Grapple grapple;
};

#endif // PLAYER_H