#ifndef OBJECT_H
#define OBJECT_H

#include <GLFW/glfw3.h>

class Object {
public:
	Object(float x, float y, float width, float height, float r, float g, float b);
	virtual ~Object() {}

	
		void draw();
	void translate(float dx, float dy);
	void rotate(float angle); // �ð���� ȸ��
	void scale(float scaleFactor);

	float getX() const { return x; }
	float getY() const { return y; }
	float getWidth() const { return width; }
	float getHeight() const { return height; }
protected:
	float x, y;
	float width, height;
	float r, g, b;
};
class Player : public Object {
public:
	Player(float x, float y, float size);
	
	void updatePhysics(float deltaTime);
	void jump();

	void move(float deltaTime);
	bool checkCollisionWith(Object* other);
private:
	float velocityY;
	const float gravity = 9800.1f; // �߷� ���ӵ� (m/s^2)
};

class Ground : public Object {
public:
	Ground(float x, float y, float width, float height);
};

class Obstacle : public Object {
public:
	Obstacle(float x, float y, float width, float height, float speed); // �����ڿ� speed �߰�
	void move(float deltaTime);
	void setPosition(float newX, float newY); // setPosition �Լ� ����

private:
	float speed; // ��ֹ��� �̵� �ӵ�
};

#endif // OBJECT_H