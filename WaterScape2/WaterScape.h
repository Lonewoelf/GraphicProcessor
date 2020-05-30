#pragma once

#include <iostream>
#include <GL/glew.h>
#include <GL/glut.h>

#define SCREEN_WIDTH 900
#define SCREEN_HEIGHT 700
#define SCREEN_POS_X 300
#define SCREEN_POS_Y 40

class WaterScape
{
public:
	WaterScape();
	~WaterScape();
	void init(int argc, char** argv);
	static void keyOperations();
	static void keyPressed(unsigned char key, int x, int y);
	static void keyUp(unsigned char key, int x, int y);
	static void display();
	static void reshape(int width, int height);


	static GLuint LoadTexture(const char* filename, int width, int height);
	
};