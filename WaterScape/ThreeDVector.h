#pragma once
class ThreeDVector
{
public:

	ThreeDVector();
	ThreeDVector(float x, float y, float z);
	~ThreeDVector();

	ThreeDVector operator+(ThreeDVector vector);
	ThreeDVector operator-(ThreeDVector vector);
	ThreeDVector operator*(float value);
	ThreeDVector operator/(float value);

	float getX();
	float getY();
	float getZ();

private:
	float x = 0, y = 0, z = 0;

};

