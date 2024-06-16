// Object.h ������ �������� �ʰ�, Object.cpp ������ Obstacle Ŭ���� ���� ����

#include <GLFW/glfw3.h>
#include <iostream>

#include "Object.h"  // Object.h ��� ������ include

// Object Ŭ������ ��� �Լ� ����

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
    // �ð�������� ȸ��
    // OpenGL������ ȸ�� ������ ���� ������ ������
    // ������ degree�� radian���� ��ȯ
    float radian = angle * 3.14159f / 180.0f;
    glTranslatef(x + width / 2, y + height / 2, 0.0f);
    glRotatef(-angle, 0.0f, 0.0f, 1.0f); // �ð����
    glTranslatef(-(x + width / 2), -(y + height / 2), 0.0f);
}

void Object::scale(float scaleFactor)
{
    width *= scaleFactor;
    height *= scaleFactor;
}

// Player Ŭ������ ��� �Լ� ����

Player::Player(float x, float y, float size)
    : Object(x, y, size, size, 1.0f, 0.0f, 0.0f), velocityY(0.0f)
{}

// Player Ŭ������ jump() �Լ��� updatePhysics() �Լ� ���� ����

void Player::jump()
{
    std::cout << "���� �Լ� ȣ���!" << std::endl;

    // ���� ��� �ִ� ��쿡�� ����
    if (y == 100.0f) {
        std::cout << "�÷��̾� ����!" << std::endl;
        velocityY = 2800.0f; // ������ �ʱ� ���� �ӵ� ���� (�ʿ信 ���� ����)
    }
    else {
        std::cout << "���� �Ұ�: y = " << y << std::endl;
    }
}



void Player::updatePhysics(float deltaTime)
{
    // �߷� ����
    velocityY -= gravity * deltaTime;

    // ��ġ ������Ʈ
    y += velocityY * deltaTime;

    // �÷��̾ ���� ���� ���
    if (y <= 100.0f) {
        y = 100.0f; // ��ġ�� �� ������ ����
        velocityY = 0.0f; // �ӵ� �ʱ�ȭ
    
    }
}

bool Player::checkCollisionWith(Object* other)
{
    // AABB �浹 �˻�
    return !(x + width < other->getX() ||
        other->getX() + other->getWidth() < x ||
        y + height < other->getY() ||
        other->getY() + other->getHeight() < y);
}


// Ground Ŭ������ ��� �Լ� ����

Ground::Ground(float x, float y, float width, float height)
    : Object(x, y, width, height, 1.0f, 0.78f, 0.06f) // Ȳ�� ���� (R:255, G:200, B:15)
{}

// Obstacle Ŭ������ ��� �Լ� ����

Obstacle::Obstacle(float x, float y, float width, float height, float speed)
    : Object(x, y, width, height, 0.0f, 1.0f, 0.0f), speed(speed)
{}

void Obstacle::move(float deltaTime)
{
    x -= speed * deltaTime;
}

// setPosition �޼��� ����
void Obstacle::setPosition(float newX, float newY)
{
    x = newX;
    y = newY;
}
