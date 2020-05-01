#pragma once

#include <iostream>
#include <GL/glew.h>
#include <GL/glut.h>

class WaterScape
{
public:
	WaterScape();
	~WaterScape();
	void init(int argc, char** argv);
	static void display();
};

