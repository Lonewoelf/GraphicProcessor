#include "WaterScape.h"
#include <stdio.h>
#include <stdlib.h>

GLfloat angle = 0.0;

GLfloat dlr = 1.0;
GLfloat dlg = 1.0;
GLfloat dlb = 1.0;

GLfloat alr = 1.0;
GLfloat alg = 1.0;
GLfloat alb = 1.0;

GLfloat lx = 0.0;
GLfloat ly = 0.0;
GLfloat lz = 1.0;
GLfloat lw = 0.0;

GLfloat density = 0.3f;

GLfloat fogColor[4] = { 1.0, 1.0, 1.0, 1.0 };

GLuint texturegl;

char keyStates[256];

void square();
void cube();

WaterScape::WaterScape()
{
}

WaterScape::~WaterScape()
{
	glDeleteTextures(1, &texturegl);
}

void WaterScape::init(int argc, char** argv)
{
	glutInit(&argc, argv); 
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGBA | GLUT_DEPTH);
	glutInitWindowSize(SCREEN_WIDTH, SCREEN_HEIGHT);
	glutInitWindowPosition(SCREEN_POS_X, SCREEN_POS_Y);
	glutCreateWindow("WaterScape");

	glutDisplayFunc(display); 
	glutReshapeFunc(reshape);
	glutKeyboardFunc(keyPressed);
	glutKeyboardUpFunc(keyUp);

	glEnable(GL_DEPTH_TEST); 
	glEnable(GL_LIGHTING); 
	glEnable(GL_LIGHT0);
	glEnable(GL_LIGHT1); 
	glShadeModel(GL_SMOOTH); 
	glEnable(GL_FOG);

	glFogi(GL_FOG_MODE, GL_EXP2);
	glFogfv(GL_FOG_COLOR, fogColor);
	glFogf(GL_FOG_DENSITY, density);
	glHint(GL_FOG_HINT, GL_DONT_CARE);

	texturegl = LoadTexture("texture.raw", 256, 256);

	glutMainLoop();
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
	glClearColor(0.0, 0.0, 0.0, 1.0);
	glClear(GL_COLOR_BUFFER_BIT);
	glLoadIdentity();
	glEnable(GL_TEXTURE_2D);
	gluLookAt(0.0, 0.0, 5.0, 0.0, 0.0, 0.0, 0.0, 1.0, 0.0);
	square();
	glutSwapBuffers();
	angle++;

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
	if (key == 'r') {
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

	int size = width * height * 3;

	//The following code will read in our RAW file
	file = fopen(filename, "r");
	if (file == NULL) {
		return 0; \
	}

	std::cout << "Inside RAW" << std::endl;
	data = (unsigned char*)malloc(size);
	fread(data, size, 1, file);
	std::cout << data;
	fclose(file);

	glGenTextures(1, &texture);
	glBindTexture(GL_TEXTURE_2D, texture);
	glTexEnvf(GL_TEXTURE_ENV, GL_TEXTURE_ENV_MODE, GL_MODULATE);
	glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
	glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
	glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
	glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, width, height, 0, GL_RGB, GL_UNSIGNED_BYTE, data);
	free(data);

	return texture;
}

void cube() {
	glFogf(GL_FOG_START, 1);
	glRotatef(angle, 1.0, 0.0, 0.0);
	glRotatef(angle, 0.0, 1.0, 0.0);
	glRotatef(angle, 0.0, 0.0, 1.0);
	glColor3f(1.0, 1.0, 0.0);
	glutSolidCube(2);
	glFogf(GL_FOG_END, 10);
}

void square() {
		glBindTexture(GL_TEXTURE_2D, texturegl);
		glRotatef(angle, 1.0f, 1.0f, 1.0f);
		glBegin(GL_QUADS);
		glTexCoord2d(0.0, 0.0); glVertex2d(-1.0, -1.0);
		glTexCoord2d(1.0, 0.0); glVertex2d(+1.0, -1.0);
		glTexCoord2d(1.0, 1.0); glVertex2d(+1.0, +1.0);
		glTexCoord2d(0.0, 1.0); glVertex2d(-1.0, +1.0);
		glEnd();
}