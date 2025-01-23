#ifndef PLAYER_HPP
#define PLAYER_HPP

#include "raylib.h"
#include "raymath.h"

class Player {
    public:
    Camera3D cam;
    Vector3 movement;
    Vector3 rotation;
    float zoom;
    float speed;
    float mouse_sens;

    Player();
    void Update();
    void Control();
};

#endif