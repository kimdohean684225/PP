// Object.h 파일은 수정하지 않고, Object.cpp 파일의 Obstacle 클래스 수정 예시

#include <GLFW/glfw3.h>
#include <iostream>

#include "Object.h"  // Object.h 헤더 파일을 include

// Object 클래스의 멤버 함수 정의

Object::Object(float x, float y, float width, float height, float r, float g, float b)
    : x(x), y(y), width(width), height(height), r(r), g(g), b(b)
{}

void Object::draw()
{
    glColor3f(r, g, b);
    glBegin(GL_QUADS);
    glVertex2f(x, y);
    glVertex2f(x + width, y);
    glVertex2f(x + width, y + height);
    glVertex2f(x, y + height);
    glEnd();
}

void Object::translate(float dx, float dy)
{
    x += dx;
    y += dy;
}

void Object::rotate(float angle)
{
    // 시계방향으로 회전
    // OpenGL에서는 회전 각도가 라디안 단위로 설정됨
    // 간단히 degree를 radian으로 변환
    float radian = angle * 3.14159f / 180.0f;
    glTranslatef(x + width / 2, y + height / 2, 0.0f);
    glRotatef(-angle, 0.0f, 0.0f, 1.0f); // 시계방향
    glTranslatef(-(x + width / 2), -(y + height / 2), 0.0f);
}

void Object::scale(float scaleFactor)
{
    width *= scaleFactor;
    height *= scaleFactor;
}

// Player 클래스의 멤버 함수 정의

Player::Player(float x, float y, float size)
    : Object(x, y, size, size, 1.0f, 0.0f, 0.0f), velocityY(0.0f)
{}

// Player 클래스의 jump() 함수와 updatePhysics() 함수 수정 예시

void Player::jump()
{
    std::cout << "점프 함수 호출됨!" << std::endl;

    // 땅에 닿아 있는 경우에만 점프
    if (y == 100.0f) {
        std::cout << "플레이어 점프!" << std::endl;
        velocityY = 2800.0f; // 적절한 초기 점프 속도 설정 (필요에 따라 조정)
    }
    else {
        std::cout << "점프 불가: y = " << y << std::endl;
    }
}



void Player::updatePhysics(float deltaTime)
{
    // 중력 적용
    velocityY -= gravity * deltaTime;

    // 위치 업데이트
    y += velocityY * deltaTime;

    // 플레이어가 땅에 닿은 경우
    if (y <= 100.0f) {
        y = 100.0f; // 위치를 땅 레벨로 고정
        velocityY = 0.0f; // 속도 초기화
    
    }
}

bool Player::checkCollisionWith(Object* other)
{
    // AABB 충돌 검사
    return !(x + width < other->getX() ||
        other->getX() + other->getWidth() < x ||
        y + height < other->getY() ||
        other->getY() + other->getHeight() < y);
}


// Ground 클래스의 멤버 함수 정의

Ground::Ground(float x, float y, float width, float height)
    : Object(x, y, width, height, 1.0f, 0.78f, 0.06f) // 황색 설정 (R:255, G:200, B:15)
{}

// Obstacle 클래스의 멤버 함수 정의

Obstacle::Obstacle(float x, float y, float width, float height, float speed)
    : Object(x, y, width, height, 0.0f, 1.0f, 0.0f), speed(speed)
{}

void Obstacle::move(float deltaTime)
{
    x -= speed * deltaTime;
}

// setPosition 메서드 구현
void Obstacle::setPosition(float newX, float newY)
{
    x = newX;
    y = newY;
}
