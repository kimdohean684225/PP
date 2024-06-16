#include "Physics.h"
#include "Object.h" // Object 클래스 헤더 파일을 include 해야 함

void Physics::ApplyGravity(float& velocityY, float gravity, float deltaTime) {
    velocityY -= gravity * deltaTime;
}

bool Physics::AABB(const Object& obj1, const Object& obj2) {
    // 충돌 여부를 AABB (Axis-Aligned Bounding Box)로 검출하는 코드 구현
    float left1 = obj1.getX();
    float right1 = obj1.getX() + obj1.getWidth();
    float bottom1 = obj1.getY();
    float top1 = obj1.getY() + obj1.getHeight();

    
        float left2 = obj2.getX();
    float right2 = obj2.getX() + obj2.getWidth();
    float bottom2 = obj2.getY();
    float top2 = obj2.getY() + obj2.getHeight();

    // 충돌 여부 검사
    if (right1 >= left2 && left1 <= right2 && top1 >= bottom2 && bottom1 <= top2) {
        return true; // 충돌
    }
    return false; // 충돌하지 않음
}