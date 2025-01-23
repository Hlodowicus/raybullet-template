#include "include/geometry3.hpp"

#include "include/alea.hpp"

Cube::Cube(Vector3 pos) : position(pos) {
    scale = Vector3{3.0, 3.0, 3.0};
    rotationAxis = Vector3Zero();
    rotationAngle = 0.0f;

    shape = new btBoxShape(btVector3(
        scale.x / 2,
        scale.y / 2,
        scale.z / 2
    ));
    motionState = new btDefaultMotionState(btTransform(btQuaternion(0, 0, 0, 1), btVector3(position.x, position.y, position.z)));
    mass = 1;
    btVector3 cubeInertia(0, 0, 0);
    shape->calculateLocalInertia(mass, cubeInertia);
    btRigidBody::btRigidBodyConstructionInfo cubeRigidBodyCI(mass, motionState, shape, cubeInertia);
    rigidBody = new btRigidBody(cubeRigidBodyCI);

    rigidBody->getMotionState()->getWorldTransform(trans);

    rigidBody->setFriction(1.0f);
    rigidBody->setRestitution(0.2f);
}

Cube::~Cube() {
    delete rigidBody->getMotionState();
    delete rigidBody;
    delete shape;
}

void Cube::Update() {
    
}

void Cube::Draw() {
    rigidBody->getMotionState()->getWorldTransform(trans);

    trans.getOpenGLMatrix(matrix);

    rlPushMatrix();
    rlMultMatrixf(matrix);
    rlScalef(scale.x, scale.y, scale.z);

    DrawCube(Vector3Zero(), 1, 1, 1, GRAY);
    DrawCubeWires(Vector3Zero(), 1, 1, 1, BLACK);

    rlPopMatrix();
}

Sphere::Sphere() {
    pos = Vector3{
        (float)GetRandomValue(-5, 5),
        (float)GetRandomValue(100, 300),
        (float)GetRandomValue(-5, 5)
    };

    radius = 1.0f;
    shape = new btSphereShape(radius);
    motionState = new btDefaultMotionState(
        btTransform(btQuaternion(0, 0, 0, 1), btVector3(pos.x, pos.y, pos.z))
    );

    mass = (float)GetRandomValue(1, 100) / 10;
    inertia = btVector3(0, 0, 0);
    shape->calculateLocalInertia(mass, inertia);

    btRigidBody::btRigidBodyConstructionInfo sphereRigidBodyCI(
        mass, motionState, shape, inertia
    );

    rigidBody = new btRigidBody(sphereRigidBodyCI);

    rigidBody->setRestitution(0.6f);
    rigidBody->setFriction(0.2f);

    color = Alea::RandomColor();
}

Sphere::~Sphere() {
    delete rigidBody->getMotionState();
    delete rigidBody;
    delete shape;
}

void Sphere::Update() {
    rigidBody->getMotionState()->getWorldTransform(trans);

    pos.x = trans.getOrigin().getX();
    pos.y = trans.getOrigin().getY();
    pos.z = trans.getOrigin().getZ();
}

void Sphere::Draw() {
    DrawSphereEx(pos, 1.0f, 5, 5, color);
}