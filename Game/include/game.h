#ifndef GAME_H
#define GAME_H

#include "raylib.h"
#include "stdio.h"
#include <vector>
#include <memory>

#include "../include/Controller.h"
#include "../include/SceneCamera.h"
#include "../include/PlanetSelector.h"
#include "../include/ObjectManager.h"
#include "../include/Projectile.h"


class Game
{
public:
    Game();
    ~Game();

    void initialize();
    void update();
    void draw();

private:
    void initializeShaders();

    void drawMiddleground();
    void drawBackground();

    void input();
    void mouseInput();
    void controllerInput();
    Controller controller;
    
    Player player;
    std::shared_ptr<Object> closestObjectToPlayer;

    // Reticle
    Texture2D reticle;

    
    bool CircleCollisions(int t_r1, int t_r2, Vector2 pos1, Vector2 pos2);

    ObjectManager objectManager;

    Texture2D backgroundTexture;
    Texture2D enemy;

    // Shaders
    float glowRadius = 15.0f;
    float glowIntensity = 1.0f;
    Shader blurHorizontal;
    Shader blurVertical;
    Shader combineShader;
    // Render textures for multi pass shaders
    RenderTexture2D targetScene;
    RenderTexture2D targetBlur1;
    RenderTexture2D targetBlur2;

    const Vector3 MIDDLEGROUND_POS = {0.0f, 0.0f, 1.0f};
    const Vector3 BACKGROUND_POS = {0.0f, 0.0f, -20.0f};
    const Vector3 PLANET_POS = {0.0f, 0.0f, -9.0f};
    
    // Billboard Textures
    RenderTexture2D background;
    RenderTexture2D middleground;
    RenderTexture2D foreground;

    PlanetSelector planetSelector;


    // Projectile testing
    std::vector<Projectile> projectiles;

    // Planet
    Planet planet;

    Vector2 mousePos;


    // Normalize to -1 to 1 range
    float normalizeSigned(float x, float t_min, float t_max) 
    {
        return 2 * (x - t_min) / (t_max - t_min) - 1;
    }
    Vector3 convertToMiddleCoords(Vector2 t_originalCoords);
    Vector2 convertToGameCoords(Vector2 t_originalCoords);
};

#endif // GAME_H