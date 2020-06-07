#include <GL/glew.h>
#include <GL/gl.h>
#include <GL/GLUT.h>

#include <math.h>
#include <corecrt_math_defines.h>

#include <windows.h>
#include <iostream>
#include <string.h>
#include <fstream>

#include <assert.h>

#include "HeightField.h"

#define SCREEN_WIDTH 1000
#define SCREEN_HEIGHT 750
#define SCREEN_POS_X 300
#define SCREEN_POS_Y 40
#define MOUSE_SENSIVITY 10

float xpos = 851.078, ypos = 351.594, zpos = 281.033, xrot = 758, yrot = 238, angle = 0.0;

float lastx, lasty;

float bounce;
float cScale = 1.0;

HeightField heightField;

extern "C" {  //Tell Windows to use the nvidea graphics card instead of the integrated graphics card
	_declspec(dllexport) DWORD NvOptimusEnablement = 0x00000001;
}

void camera(void) {
	int posX = (int)xpos;

	int posZ = (int)zpos;

	glRotatef(xrot, 1.0, 0.0, 0.0);
	glRotatef(yrot, 0.0, 1.0, 0.0);

	glTranslated(-xpos, -ypos, -zpos);
}

void updateFps()
{
	static float framesPerSecond = 0.0f;
	static float lastTime = 0.0f;
	float currentTime = GetTickCount() * 0.001f;
	++framesPerSecond;
	if (currentTime - lastTime > 1.0f)
	{
		lastTime = currentTime;
		system("CLS");
		std::cout << " FPS: " << (int)framesPerSecond << std::endl;
		framesPerSecond = 0;
	}
}

void display(void) {

	glClearColor(0.0, 0.0, 0.0, 1.0);
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	glLoadIdentity();
	camera();

	heightField.Render();

	updateFps();

	glutSwapBuffers();
}

void Init(void) {
	glEnable(GL_DEPTH_TEST);

	heightField.Create(" " , 1024, 1024);
}

void mouseMovement(int x, int y) {

	int diffx = x - lastx;
	int diffy = y - lasty;
	lastx = x;
	lasty = y;
	xrot += ((float)diffy / MOUSE_SENSIVITY);
	yrot += ((float)diffx / MOUSE_SENSIVITY);

}

void keyboard(unsigned char key, int x, int y) {

	if (key == 'w')
	{
		float xrotrad, yrotrad;

		yrotrad = (yrot / 180 * 3.141592654f);
		xrotrad = (xrot / 180 * 3.141592654f);

		xpos += float(sin(yrotrad)) * cScale;
		zpos -= float(cos(yrotrad)) * cScale;

		ypos -= float(sin(xrotrad));
		bounce += 0.04;

	}

	if (key == 's')
	{
		float xrotrad, yrotrad;

		yrotrad = (yrot / 180 * 3.141592654f);
		xrotrad = (xrot / 180 * 3.141592654f);

		xpos -= float(sin(yrotrad)) * cScale;
		zpos += float(cos(yrotrad)) * cScale;

		ypos += float(sin(xrotrad));
		bounce += 0.04;

	}

	if (key == 'd')
	{
		float yrotrad;

		yrotrad = (yrot / 180 * 3.141592654f);
		xpos += float(cos(yrotrad)) * cScale;

		zpos += float(sin(yrotrad)) * cScale;
	}

	if (key == 'a')
	{
		float yrotrad;

		yrotrad = (yrot / 180 * 3.141592654f);
		xpos -= float(cos(yrotrad)) * cScale;

		zpos -= float(sin(yrotrad)) * cScale;
	}

}

void reshape(int w, int h) {
	glViewport(0, 0, (GLsizei)w, (GLsizei)h);

	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluPerspective(60, (GLfloat)w / (GLfloat)h, 1.0, 1000.0);

	glMatrixMode(GL_MODELVIEW);
}

int main(int argc, char** argv) {

	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_DEPTH | GLUT_RGBA);

	glutInitWindowSize(SCREEN_WIDTH, SCREEN_HEIGHT);
	glutInitWindowPosition(SCREEN_POS_X, SCREEN_POS_Y);
	glutCreateWindow("WaterScape");

	Init();
	glutDisplayFunc(display);
	glutIdleFunc(display);

	glutReshapeFunc(reshape);
	glutKeyboardFunc(keyboard);
	glutPassiveMotionFunc(mouseMovement);

	glutMainLoop();
	return 0;
}