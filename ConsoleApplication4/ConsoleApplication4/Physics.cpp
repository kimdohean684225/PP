#include "Physics.h"
#include "Object.h" // Object Ŭ���� ��� ������ include �ؾ� ��

void Physics::ApplyGravity(float& velocityY, float gravity, float deltaTime) {
    velocityY -= gravity * deltaTime;
}

bool Physics::AABB(const Object& obj1, const Object& obj2) {
    // �浹 ���θ� AABB (Axis-Aligned Bounding Box)�� �����ϴ� �ڵ� ����
    float left1 = obj1.getX();
    float right1 = obj1.getX() + obj1.getWidth();
    float bottom1 = obj1.getY();
    float top1 = obj1.getY() + obj1.getHeight();

    
        float left2 = obj2.getX();
    float right2 = obj2.getX() + obj2.getWidth();
    float bottom2 = obj2.getY();
    float top2 = obj2.getY() + obj2.getHeight();

    // �浹 ���� �˻�
    if (right1 >= left2 && left1 <= right2 && top1 >= bottom2 && bottom1 <= top2) {
        return true; // �浹
    }
    return false; // �浹���� ����
}