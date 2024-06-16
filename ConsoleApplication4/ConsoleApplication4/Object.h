#ifndef OBJECT_H
#define OBJECT_H

#include <GLFW/glfw3.h>

class Object {
public:
	Object(float x, float y, float width, float height, float r, float g, float b);
	virtual ~Object() {}

	
		void draw();
	void translate(float dx, float dy);
	void rotate(float angle); // 시계방향 회전
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
	const float gravity = 9800.1f; // 중력 가속도 (m/s^2)
};

class Ground : public Object {
public:
	Ground(float x, float y, float width, float height);
};

class Obstacle : public Object {
public:
	Obstacle(float x, float y, float width, float height, float speed); // 생성자에 speed 추가
	void move(float deltaTime);
	void setPosition(float newX, float newY); // setPosition 함수 선언

private:
	float speed; // 장애물의 이동 속도
};

#endif // OBJECT_H