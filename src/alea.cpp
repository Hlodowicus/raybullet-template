#include "include/alea.hpp"

Vector3 Alea::RandomVEC3(int p) {
    return Vector3{
        .x = (float)GetRandomValue(0, p),
        .y = (float)GetRandomValue(1, p),
        .z = (float)GetRandomValue(0, p)
    };
}

Color Alea::RandomColor() {
    return Color{
        (unsigned char)GetRandomValue(0, 255),
        (unsigned char)GetRandomValue(0, 255),
        (unsigned char)GetRandomValue(0, 255),
        255
    };
}