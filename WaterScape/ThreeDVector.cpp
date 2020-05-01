#include "ThreeDVector.h"

ThreeDVector::ThreeDVector()
{
}

ThreeDVector::ThreeDVector(float x, float y, float z)
{
	this->x = x;
	this->y = y;
	this->z = z;
}

ThreeDVector::~ThreeDVector()
{
}

ThreeDVector ThreeDVector::operator+(ThreeDVector vector)
{
	return ThreeDVector(vector.x + this->x, vector.y + this->y, vector.z + this->z);
}

ThreeDVector ThreeDVector::operator-(ThreeDVector vector)
{
	return ThreeDVector(vector.x - this->x, vector.y - this->y, vector.z - this->z);
}

ThreeDVector ThreeDVector::operator*(float value)
{
	return ThreeDVector();
}

ThreeDVector ThreeDVector::operator/(float value)
{
	return ThreeDVector();
}

float ThreeDVector::getX()
{
	return this->x;
}

float ThreeDVector::getY()
{
	return this->y;
}

float ThreeDVector::getZ()
{
	return this->z;
}
