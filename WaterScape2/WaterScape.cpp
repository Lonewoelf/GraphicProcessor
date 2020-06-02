#include "WaterScape.h"
#include <stdio.h>
#include <stdlib.h>
#include <GL/gl.h>
#include <GL/glut.h>
#include <windows.h>

GLfloat angle = 0.0;

GLuint texture;

char keyStates[256];

void cube();
void cub2();


WaterScape::WaterScape()
{
}

WaterScape::~WaterScape()
{
	
}

void WaterScape::init(int argc, char** argv)
{
	glutInit (&argc, argv);
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_DEPTH);
	glutGameModeString("1920×1080:32@75");
	glutEnterGameMode();
    glutInitDisplayMode (GLUT_DOUBLE);
    //glutInitWindowSize (SCREEN_WIDTH, SCREEN_HEIGHT);
    //glutInitWindowPosition (SCREEN_POS_X, SCREEN_POS_Y);
    //glutCreateWindow ("WaterScape 2");
    glutDisplayFunc (display);
    glutIdleFunc (display);
    glutReshapeFunc (reshape);
	glutKeyboardFunc(keyPressed);
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
	cube();
	cub2();
	glDeleteTextures(1, &texture);
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
/*	if (key == 'r') {
		dlr = 1.0; //change light to red
		dlg = 0.0;
		dlb = 0.0;
	}
	if (key == 'g') {
		dlr = 0.0; //change light to green
		dlg = 1.0;
		dlb = 0.0;
	}
	if (key == 'b') {
		dlr = 0.0; //change light to blue
		dlg = 0.0;
		dlb = 1.0;
	}
	if (key == 'w') {
		ly += 10.0; //move the light up
	}
	if (key == 's') {
		ly -= 10.0; //move the light down
	}
	if (key == 'a') {
		lx -= 10.0; //move the light left
	}
	if (key == 'd') {
		lx += 10.0; //move the light right
	}*/

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
		fprintf(stderr, "\nFPS: %d\n\n", (int)framesPerSecond);
		framesPerSecond = 0;
	}
}

void cube() {
	glPushMatrix(); //set where to start the current object transformations
	glTranslatef(1, 0, 0); //move cube1 to the right
	glRotatef(angle, 1.0, 0.0, 0.0);
	glRotatef(angle, 0.0, 1.0, 0.0);
	glRotatef(angle, 0.0, 0.0, 1.0);
	glColor3f(0.0, 0.0, 1.0); //change cube1 to red
	glutSolidCube(1);
	glPopMatrix(); //end the current object transformations
}

void cub2() {
	glPushMatrix(); //set where to start the current object transformations
	glTranslatef(0, 1, 0); //move cube1 to the right
	glRotatef(angle, 1.0, 0.0, 0.0);
	glRotatef(angle, 0.0, 1.0, 0.0);
	glRotatef(angle, 0.0, 0.0, 1.0);
	glColor3f(1.0, 0.0, 0.0); //change cube1 to red
	glutSolidCube(1);
	glPopMatrix(); //end the current object transformations
}