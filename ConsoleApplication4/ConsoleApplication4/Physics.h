#ifndef PHYSICS_H
#define PHYSICS_H

#include "Object.h"

class Physics {
public:
	static void ApplyGravity(float& velocityY, float gravity, float deltaTime);
	static bool AABB(const Object& obj1, const Object& obj2);
};

#endif // PHYSICS_H