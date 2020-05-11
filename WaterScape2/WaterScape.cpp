#include "WaterScape.h"

bool* keyStates = new bool[256];
bool movingUp = true;
float yLocation = 0.0f;
float yRotationAngle = 0.8f;

WaterScape::WaterScape()
{
}

WaterScape::~WaterScape()
{
}

void WaterScape::init(int argc, char** argv)
{
	glutInit(&argc, argv); 
	glutInitDisplayMode(GLUT_SINGLE);
	glutInitWindowSize(SCREEN_WIDTH, SCREEN_HEIGHT);
	glutInitWindowPosition(SCREEN_POS_X, SCREEN_POS_Y);
	glutCreateWindow("WaterScape");

	glutDisplayFunc(display); 
	glutReshapeFunc(reshape);
	glutKeyboardFunc(keyPressed);
	glutKeyboardUpFunc(keyUp);

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

	keyOperations();

	glClearColor(1.0f, 0.0f, 0.0f, 1.0f); 
	glClear(GL_COLOR_BUFFER_BIT); 
	glLoadIdentity(); 

	glTranslatef(0.0f, 0.0f, -5.0f);

	glTranslatef(0.0f, yLocation, 0.0f);

	glRotatef(yRotationAngle, 0.0f, 1.0f, 0.0f);

	glutWireCube(2.0f);

	glFlush();

	if (movingUp) {
		yLocation -= 0.05f;
	}
	else {
		yLocation += 0.05f;
	}

	if (yLocation < -3.0f) {
		movingUp = false;
	}
	else if (yLocation > 3.0f) {
		movingUp = true;
		yRotationAngle += 0.05f;
	}
	if (yRotationAngle > 360.0f) {
		yRotationAngle -= 360.0f;
	}

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
	keyStates[key] = true;
}

void WaterScape::keyUp(unsigned char key, int x, int y)
{
	keyStates[key] = false;
}