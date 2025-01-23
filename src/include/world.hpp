#ifndef WORLD_HPP
#define WORLD_HPP

#include "btBulletCollisionCommon.h"
#include "btBulletDynamicsCommon.h"

class World {
    public:
    //init de bullet
    btBroadphaseInterface* broadphase;
    btDefaultCollisionConfiguration* collisionConfiguration;
    btCollisionDispatcher* dispatcher;
    btSequentialImpulseConstraintSolver* solver;
    btDiscreteDynamicsWorld* dynamicsWorld;

    World(float gravX, float gravY, float gravZ);
    ~World();
    void AddBody(btRigidBody* rb);
    void RemoveBody(btRigidBody* rb);
};

class Ground {
    public:
    btCollisionShape* shape;
    btDefaultMotionState* motionState;
    
    btRigidBody* rigidBody;
    

    Ground();
    ~Ground();
};

#endif