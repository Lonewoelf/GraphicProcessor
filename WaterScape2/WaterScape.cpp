#include "WaterScape.h"

WaterScape::WaterScape()
{
}

WaterScape::~WaterScape()
{
}

void WaterScape::init(int argc, char** argv)
{
	glutInit(&argc, argv); // Initialize GLUT
	glutInitDisplayMode(GLUT_SINGLE); // Set up a basic display buffer (only single buffered for now)
	glutInitWindowSize(SCREEN_WIDTH, SCREEN_HEIGHT);
	glutInitWindowPosition(SCREEN_POS_X, SCREEN_POS_Y);
	glutCreateWindow("WaterScape");

	glutDisplayFunc(display); 
	glutReshapeFunc(reshape);
	glutKeyboardFunc(keyPressed);
	glutKeyboardUpFunc(keyUp);

	glutMainLoop();
}

void WaterScape::display()
{
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	drawScape();

	glFlush(); // Flush the OpenGL buffers to the window
}
void WaterScape::drawScape()
{
	glColor3d(0.1, 0.25, 0.5);

	glPushMatrix();
	glTranslated(0.0, 1.2, -6);
	glutSolidSphere(1, 50, 50);
	glPopMatrix();

	glColor3d(1.0, 1.0, 0.2);

	glPushMatrix();
	glTranslated(0.0, -1.2, -6);
	glutSolidSphere(1, 50, 50);
	glPopMatrix();

	glutSwapBuffers();
}
void WaterScape::reshape(int width, int height) {
	glViewport(0, 0, (GLsizei)width, (GLsizei)height); // Set our viewport to the size of our window
	glMatrixMode(GL_PROJECTION); // Switch to the projection matrix so that we can manipulate how our scene is viewed
	glLoadIdentity(); // Reset the projection matrix to the identity matrix so that we don't get any artifacts (cleaning up)
	gluPerspective(60, (GLfloat)width / (GLfloat)height, 1.0, 100.0); // Set the Field of view angle (in degrees), the aspect ratio of our window, and the new and far planes
	glMatrixMode(GL_MODELVIEW); // Switch back to the model view matrix, so that we can start drawing shapes correctly
}

void WaterScape::keyPressed(unsigned char key, int x, int y)
{
	if (key == 'w') {

	}
	else if (key == 'a') {

	}
	else if (key == 's') {

	}
	else if (key == 'd') {

	}
}

void WaterScape::keyUp(unsigned char key, int x, int y)
{
	if (key == 'w') {

	}
	else if (key == 'a') {

	}
	else if (key == 's') {

	}
	else if (key == 'd') {

	}
}
