#include "../include/game.h"
#include "../include/Globals.h"

Game::Game()
{
    printf("Game Initialized!\n");
}

Game::~Game()
{
    // Use to free resources
}

void Game::update() 
{
    input();

    player.update();

    for (int i = 0; i < currentObjectAmount; i++)
    {
        objects[i]->update();
    }
}

void Game::draw() 
{
    DrawText("Hello, Raylib Starter Kit!", 190, 180, 20, DARKBLUE);

    player.draw();

    for (int i = 0; i < currentObjectAmount; i++)
    {
        objects[i]->draw();
    }
}

void Game::input()
{
    if (IsMouseButtonPressed(MOUSE_BUTTON_LEFT))
    {
        if (!player.isGrappleActive())
        {
            for (int i = 0; i < currentObjectAmount; i++)
            {
                if (CheckCollisionPointCircle(GetMousePosition(), objects[i]->getPos(), objects[i]->getRadius()))
                {
                    player.shootGrapple(objects[i]);
                }
            }
        }
        else
        {
            player.releaseGrapple();
        }
    }

    if (IsMouseButtonPressed(MOUSE_BUTTON_RIGHT))
    {
        objects.push_back(std::make_shared<Object>(GetMousePosition()));
        currentObjectAmount++;
    }
}



bool Game::CircleCollisions(int t_r1, int t_r2, Vector2 pos1, Vector2 pos2)
{
    // Calculate the squared distance between the two positions
    double distanceSquared = std::pow(pos2.x - pos1.x, 2) + std::pow(pos2.y - pos1.y, 2);
    
    // Calculate the squared sum of the radii
    int radiusSum = t_r1 + t_r2;
    double radiusSumSquared = std::pow(radiusSum, 2);
    
    // Check if the distance squared is less than or equal to the squared radius sum
    return distanceSquared <= radiusSumSquared;
}