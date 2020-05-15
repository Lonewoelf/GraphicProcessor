#include "WaterScape.h"

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

char keyStates[256];

WaterScape::WaterScape()
{
}

WaterScape::~WaterScape()
{
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
	glClearColor(1.0, 1.0, 1.0, 1.0);
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glLoadIdentity();
	GLfloat DiffuseLight[] = { dlr, dlg, dlb };
	GLfloat AmbientLight[] = { alr, alg, alb };
	glLightfv(GL_LIGHT0, GL_DIFFUSE, DiffuseLight);
	glLightfv(GL_LIGHT1, GL_AMBIENT, AmbientLight);
	GLfloat LightPosition[] = { lx, ly, lz, lw };
	glLightfv(GL_LIGHT0, GL_POSITION, LightPosition);
	gluLookAt(0.0, 0.0, 5.0, 0.0, 0.0, 0.0, 0.0, 1.0, 0.0);
	glRotatef(angle, 1.0, 0.0, 0.0);
	glRotatef(angle, 0.0, 1.0, 0.0);
	glRotatef(angle, 0.0, 0.0, 1.0);
	glColor3f(1.0, 1.0, 0.0);
	glutSolidCube(2);
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