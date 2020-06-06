#include "WaterScape.h"
#include <stdio.h>
#include <stdlib.h>
#include <GL/gl.h>
#include <GL/glut.h>
#include <windows.h>
#include <math.h>
#include <corecrt_math_defines.h>

#define MOUSE_SENSIVITY 10

float xpos = 0, ypos = 0, zpos = 0, xrot = 0, yrot = 0, angle = 0.0;

GLuint texture;

char keyStates[256];

GLuint cubelist;

float positionz[10];
float positionx[10];

float lastx = 0, lasty = 0;

WaterScape::WaterScape()
{
}

WaterScape::~WaterScape()
{
	
}

extern "C" {  //Tell Windows to use the nvidea graphics card instead of the integrated graphics card
	_declspec(dllexport) DWORD NvOptimusEnablement = 0x00000001;
}

void cubePositions(void) { //set the positions of the cubes

	for (int i = 0; i < 10; i++)
	{
		positionz[i] = rand() % 5 + 5;
		positionx[i] = rand() % 5 + 5;
	}
}

void cube() {
	cubelist = glGenLists(1);
	glNewList(cubelist, GL_COMPILE);

	for (int i = 0; i < 100; i++){
		glPushMatrix();
		glTranslated(-positionx[i + 1] * 9, 0, -positionz[i + 1] * 9); 
		glRotatef(angle, 1.0, 0.0, 0.0);
		glRotatef(angle, 0.0, 1.0, 0.0);
		glRotatef(angle, 0.0, 0.0, 1.0);
		glPushMatrix();

		glColor3f(0.0, 1.0, 0.0);
		glutSolidTeapot(2);
		glPopMatrix();
	}
	glEndList();
}

void camera(void) {
	glRotatef(xrot, 1.0, 0.0, 0.0);
	glRotatef(yrot, 0.0, 1.0, 0.0);
	glTranslated(-xpos, -ypos, -zpos);
}

void WaterScape::init(int argc, char** argv)
{
	glutInit (&argc, argv);
	cubePositions();
	//glutInitDisplayMode(GLUT_DOUBLE | GLUT_DEPTH);
	//glutGameModeString("1920×1080:32@75");
	//glutEnterGameMode();
    glutInitDisplayMode (GLUT_DOUBLE);
    glutInitWindowSize (SCREEN_WIDTH, SCREEN_HEIGHT);
    glutInitWindowPosition (SCREEN_POS_X, SCREEN_POS_Y);
    glutCreateWindow ("WaterScape 2");
    glutDisplayFunc (display);
    glutIdleFunc (display);
    glutReshapeFunc (reshape);
	glutPassiveMotionFunc(mouseMovement);
	glutKeyboardFunc(keyPressed);
	cube();
    glutMainLoop ();
}

void WaterScape::keyOperations()
{
	if (keyStates['w']) {

	}
	else if (keyStates['a']) {

	}
	else if (keyStates['s']) {

	}
	else if (keyStates['d']) {

	}
}

void WaterScape::display()
{
	glClearColor(1.0, 1.0, 1.0, 1.0);
	glClear(GL_COLOR_BUFFER_BIT);
	glLoadIdentity();
	gluLookAt(0.0, 0.0, 5.0, 0.0, 0.0, 0.0, 0.0, 1.0, 0.0);
	texture = LoadTexture("texture.raw", 256, 256);
	glEnable(GL_TEXTURE_2D);
	glEnable(GL_TEXTURE_GEN_S);
	glEnable(GL_TEXTURE_GEN_T);
	glDeleteTextures(1, &texture);
	glLoadIdentity();
	camera();
	glCallList(cubelist);
	glutSwapBuffers();
	updateFps();
	angle += 0.05;
}

void WaterScape::reshape(int width, int height) {
	glViewport(0, 0, (GLsizei)width, (GLsizei)height); 
	glMatrixMode(GL_PROJECTION); 
	glLoadIdentity(); 
	gluPerspective(60, (GLfloat)width / (GLfloat)height, 1.0, 100.0); 
	glMatrixMode(GL_MODELVIEW); 
}

void WaterScape::keyPressed(unsigned char key, int x, int y)
{
    if (key=='x')
    {
    xrot += 1;
    if (xrot >360) xrot -= 360;
    }

    if (key=='z')
    {
    xrot -= 1;
    if (xrot < -360) xrot += 360;
    }

    if (key=='w')
    {
    float xrotrad, yrotrad;
    yrotrad = (yrot / 180 * M_PI);
    xrotrad = (xrot / 180 * M_PI);
    xpos += float(sin(yrotrad)) ;
    zpos -= float(cos(yrotrad)) ;
    ypos -= float(sin(xrotrad)) ;
    }

    if (key=='s')
    {
    float xrotrad, yrotrad;
    yrotrad = (yrot / 180 * M_PI);
    xrotrad = (xrot / 180 * M_PI);
    xpos -= float(sin(yrotrad));
    zpos += float(cos(yrotrad)) ;
    ypos += float(sin(xrotrad));
    }

    if (key=='d')
    {
		float yrotrad;
		yrotrad = (yrot / 180 * 3.141592654f);
		xpos += float(cos(yrotrad)) * 0.2;
		zpos += float(sin(yrotrad)) * 0.2;
    }

    if (key=='a')
    {
		float yrotrad;
		yrotrad = (yrot / 180 * 3.141592654f);
		xpos -= float(cos(yrotrad)) * 0.2;
		zpos -= float(sin(yrotrad)) * 0.2;
    }

	if (key == 'q')
	{
		glutLeaveGameMode();
		exit(0);
	}
}

void WaterScape::keyUp(unsigned char key, int x, int y)
{
	keyStates[key] = false;
}

GLuint WaterScape::LoadTexture(const char* filename, int width, int height)
{
	GLuint texture;
	unsigned char* data;
	FILE* file;

	file = fopen(filename, "rb");
	if (file == NULL) {
		return 0;
	}

	data = (unsigned char*)malloc(width * height * 3);
	fread(data, width * height * 3, 1, file);
	fclose(file);

	glGenTextures(1, &texture); 
	glBindTexture(GL_TEXTURE_2D, texture); 
	glTexEnvf(GL_TEXTURE_ENV, GL_TEXTURE_ENV_MODE, GL_MODULATE);
	glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR_MIPMAP_LINEAR);
	glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR_MIPMAP_LINEAR);
	glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
	glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);

	gluBuild2DMipmaps(GL_TEXTURE_2D, 3, width, height, GL_RGB, GL_UNSIGNED_BYTE, data);
	free(data);

	return texture;
}

void WaterScape::updateFps()
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

void WaterScape::mouseMovement(int x, int y) {
	int diffx = x-lastx;
	int diffy = y-lasty;
	lastx = x;
	lasty = y; 
	xrot += ((float)diffy / MOUSE_SENSIVITY);
	yrot += ((float)diffx / MOUSE_SENSIVITY);
}