#pragma once

#include "raylib.h"
#include "raymath.h"
#include "stdio.h"

class Planet
{
public:
    void init(Vector3 t_pos = {0.0f, 0.0f, -9.0f});

    void update();
    void draw();

private:    
    Model model;

    Vector3 position;

    float pitch = 0.0f;
    float roll = 0.0f;
    float yaw = 0.0f;

    float rotation = 0.0f;
};