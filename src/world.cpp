#include "include/world.hpp"

World::World(float gravX, float gravY, float gravZ) {
    //init de bullet
    broadphase = new btDbvtBroadphase();
    collisionConfiguration = new btDefaultCollisionConfiguration();
    dispatcher = new btCollisionDispatcher(collisionConfiguration);
    solver = new btSequentialImpulseConstraintSolver();
    dynamicsWorld = new btDiscreteDynamicsWorld(dispatcher, broadphase, solver, collisionConfiguration);

    //config du monde physique
    dynamicsWorld->setGravity(btVector3(gravX, gravY, gravZ));
}

World::~World() {
    delete dynamicsWorld;
    delete solver;
    delete dispatcher;
    delete collisionConfiguration;
    delete broadphase;
}

void World::AddBody(btRigidBody* rb) {
    dynamicsWorld->addRigidBody(rb);
}

void World::RemoveBody(btRigidBody* rb) {
    dynamicsWorld->removeRigidBody(rb);
}

Ground::Ground() {
    shape = new btStaticPlaneShape(btVector3(0, 1, 0), 1);
    motionState = new btDefaultMotionState(btTransform(btQuaternion(0, 0, 0, 1), btVector3(0, -1, 0)));
    btRigidBody::btRigidBodyConstructionInfo groundRigidBodyCI(0, motionState, shape, btVector3(0, 0, 0));
    rigidBody = new btRigidBody(groundRigidBodyCI);
    rigidBody->setRestitution(0.6f);
}

Ground::~Ground() {
    delete rigidBody->getMotionState();
    delete rigidBody;
    delete shape;
}