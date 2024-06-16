#include "Transform.h"

void Transform::translate(float& x, float& y, float dx, float dy)
{
	x += dx;
	y += dy;
}

void Transform::rotateClockwise(float& angle, float da)
{
	angle += da;
}

void Transform::scale(float& width, float& height, float scaleFactor)
{
	width *= scaleFactor;
	height *= scaleFactor;
}