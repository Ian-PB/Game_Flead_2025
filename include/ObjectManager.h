#pragma once

#include "raylib.h"
#include "stdio.h"
#include <vector>
#include <memory>

#include "../include/Object.h"
#include "../include/Player.h"

class ObjectManager
{
public:
    void setObjects();
    std::shared_ptr<Object> findClosestToPlayer(Player t_player);

    void draw();
    void update();

private:
    std::vector<std::shared_ptr<Object>> objects;

    float pointToPointDist(Vector2 t_p1, Vector2 t_p2) { return sqrt(((t_p2.x - t_p1.x) * (t_p2.x - t_p1.x)) + ((t_p2.y - t_p1.y) * (t_p2.y - t_p1.y))); }
};