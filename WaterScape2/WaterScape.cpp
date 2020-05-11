#include "WaterScape.h"

bool* keyStates = new bool[256];
bool movingUp = true;
float yLocation = 0.0f;
float yRotationAngle = 0.8f;
GLfloat angle = 0.0;

GLfloat redDiffuseMaterial[] = { 1.0, 0.0, 0.0 };
GLfloat whiteSpecularMaterial[] = { 1.0, 1.0, 1.0 };
GLfloat greenEmissiveMaterial[] = { 0.0, 1.0, 0.0 };

GLfloat whiteSpecularLight[] = { 1.0, 1.0, 1.0 };
GLfloat blackAmbientLight[] = { 0.0, 0.0, 0.0 };
GLfloat whiteDiffuseLight[] = { 1.0, 1.0, 1.0 };

GLfloat blankMaterial[] = { 0.0, 0.0, 0.0 };
GLfloat mShininess[] = { 10 }; 

bool diffuse = false;
bool emissive = false;
bool specular = false;

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
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glLoadIdentity();
	glLightfv(GL_LIGHT0, GL_SPECULAR, whiteSpecularLight);
	glLightfv(GL_LIGHT0, GL_AMBIENT, blackAmbientLight);
	glLightfv(GL_LIGHT0, GL_DIFFUSE, whiteDiffuseLight);
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
	if (key == 's')
	{
		if (specular == false)
		{
			specular = true;
			glMaterialfv(GL_FRONT_AND_BACK, GL_SPECULAR,
				whiteSpecularMaterial);
			glMaterialfv(GL_FRONT_AND_BACK, GL_SHININESS, mShininess);
		}
		else if (specular == true)
		{
			specular = false;
			glMaterialfv(GL_FRONT_AND_BACK, GL_SPECULAR, blankMaterial);
			glMaterialfv(GL_FRONT_AND_BACK, GL_SHININESS,
				blankMaterial);
		}
	}

	if (key == 'd')
	{
		if (diffuse == false)
		{
			diffuse = true;
			glMaterialfv(GL_FRONT_AND_BACK, GL_DIFFUSE,
				redDiffuseMaterial);
		}
		else if (diffuse == true)
		{
			diffuse = false;
			glMaterialfv(GL_FRONT_AND_BACK, GL_DIFFUSE, blankMaterial);
		}
	}

	if (key == 'e')
	{
		if (emissive == false)
		{
			emissive = true;
			glMaterialfv(GL_FRONT_AND_BACK, GL_EMISSION,
				greenEmissiveMaterial);
		}
		else if (emissive == true)
		{
			emissive = false;
			glMaterialfv(GL_FRONT_AND_BACK, GL_EMISSION, blankMaterial);
		}
	}
}


void WaterScape::keyUp(unsigned char key, int x, int y)
{
	keyStates[key] = false;
}