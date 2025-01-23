#ifndef GEOMETRY3_HPP
#define GEOMETRY3_HPP

#include "raylib.h"
#include "raymath.h"
#include "rlgl.h"

#include "btBulletDynamicsCommon.h"
#include "btBulletDynamicsCommon.h"

class Cube {
    public:
    //affichage
    Vector3 position, scale, rotationAxis;
    float rotationAngle;

    float matrix[16];


    //physique
    btCollisionShape* shape;
    btDefaultMotionState* motionState;
    btScalar mass;

    btRigidBody* rigidBody;

    btTransform trans;

    Cube(Vector3 pos);
    ~Cube();
    void Update();
    void Draw();
};

class Sphere {
    public:
    btScalar radius;
    btCollisionShape* shape;
    btDefaultMotionState* motionState;

    btScalar mass;
    btVector3 inertia;
    
    btRigidBody* rigidBody;

    btTransform trans;
    Vector3 pos;
    Color color;

    Sphere();
    ~Sphere();
    void Update();
    void Draw();
};

#endif