#include "include/player.hpp"

Player::Player() {
    cam = {
        .position = Vector3{-60.0f, 33.0f, 1.0f},
        .target = Vector3{0.0f, 2.0f, 0.0f},
        .up = Vector3{0.0f, 2.0f, 0.0f},
        .fovy = 60.0f,
        .projection = CAMERA_PERSPECTIVE
    };

    movement = Vector3Zero();
    rotation = Vector3Zero();
    zoom = 0.0f;
    speed = 18.0f;
    mouse_sens = .2f;
}

void Player::Update() {
    Control();
    UpdateCameraPro(&cam, movement, rotation, zoom);
}

void Player::Control() {
    if(IsKeyDown(KEY_W)) movement.x = 1 * speed * GetFrameTime();
    else if(IsKeyDown(KEY_S)) movement.x = -1 * speed * GetFrameTime();
    else movement.x = 0;
    if(IsKeyDown(KEY_D)) movement.y = 1 * speed * GetFrameTime();
    else if(IsKeyDown(KEY_A)) movement.y = -1 * speed * GetFrameTime();
    else movement.y = 0;
    if(IsKeyDown(KEY_SPACE)) movement.z = 1 * speed * GetFrameTime();
    else if(IsKeyDown(KEY_C)) movement.z = -1 * speed * GetFrameTime();
    else movement.z = 0;

    if(IsKeyDown(KEY_LEFT_SHIFT)) speed = 36.0f;
    else speed = 18.0f;

    rotation.x = GetMouseDelta().x * mouse_sens;
    rotation.y = GetMouseDelta().y * mouse_sens;
}