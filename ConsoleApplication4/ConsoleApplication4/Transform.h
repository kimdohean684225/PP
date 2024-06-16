#ifndef TRANSFORM_H
#define TRANSFORM_H

class Transform {
public:
	static void translate(float& x, float& y, float dx, float dy);
	static void rotateClockwise(float& angle, float da); // 시계방향 회전
	static void scale(float& width, float& height, float scaleFactor);
};

#endif // TRANSFORM_H