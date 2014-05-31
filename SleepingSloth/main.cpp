#include <glut.h>
#include <iostream>
#include <math.h>
#include <ctime>
#include <stdlib.h>
#include "Circles.h"

double VerticalAngle = -20.0f;
bool MouseActive = false;
int InitY;

bool Rotate = false;
int RotDir = -1;
double Rot_Angle = 0.0f;
double cameraZ = -30.0f;
clock_t RotStartTime;


void TestDrawing()
{

	Circles circle1;
	ObjectMorpher * Obj1 = &circle1;
	Obj1->SetValues(0, 0, 0, 1, 1, 1, 1, 0, 0);
	circle1.DrawCircle(1);
}

void initRendering()
{
	glEnable(GL_DEPTH_TEST);
}

void handleResize(int w, int h)\
{
	glViewport(0, 0, w, h);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluPerspective(45.0, (double)w / (double)h, 1.0, 1500);
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();

}

void DrawScene()
{
	glEnable(GL_BLEND | GL_DEPTH_BUFFER_BIT);
	glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_DST_ALPHA);
	glClearColor(0.0, 0.0, 0.0, 0.0);
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();

	gluLookAt(0.0, 0.0, cameraZ, 1.0, 1.0, 1.0, 0.0, 3.0, 0.0);
	glRotatef(VerticalAngle, 1.0, 0.0, 0.0);
	glRotatef(Rot_Angle, 0.0, 1.0, 0.0);

	//Drawing Function is below
	TestDrawing();
	///////////////////////////

	glutSwapBuffers();
}

void keyboardFunc(unsigned char btn, int w, int h)
{
	//Stop and start the rotation
	if ((btn == 'R') || (btn == 'r'))
	{
		Rotate = !Rotate;
		if (Rotate) {
			RotStartTime = clock();
		}
	}
	//Change the dirrection of rotation
	if ((btn == 'X') || ((btn == 'x') && (Rotate)))
	{
		RotDir = -RotDir;
	}

	if (btn == 27)
	{
		exit(0);
	}
}

//Code to zoom in and out of the scene
void zoom(double zoomAmount)
{
	cameraZ += zoomAmount;
}

void specialKeys(int key, int w, int h)
{
	if (key == GLUT_KEY_UP)
	{
		zoom(1.0);
	}
	if (key == GLUT_KEY_DOWN)
	{
		zoom(-1.0);
	}
}

void rotate(double deltaTheta)
{
	Rot_Angle += deltaTheta;
	while (Rot_Angle >= 360.0)
	{
		Rot_Angle -= 360.0;
	}
	while (Rot_Angle < 0.0)
	{
		Rot_Angle += 360.0;
	}
}

void IdleFunc()
{
	if (Rotate)
	{
		double deltaTheta = 36.0* (clock() - RotStartTime) / CLOCKS_PER_SEC * RotDir;
		rotate(deltaTheta);
		RotStartTime = clock();
	}
	glutPostRedisplay();
}

//Beginning of mouse functions///////////////////////////////////////////////////////
//Camera Angles of the scene controlled by the mouse
void ChangeViewingAngle(double deltaView)
{
	VerticalAngle += deltaView;
	if (VerticalAngle > 180.0)
		VerticalAngle = 180;
	if (VerticalAngle < -180)
		VerticalAngle = -180;
}

void MouseFunc(int button, int state, int x, int y)
{
	if ((button == GLUT_LEFT_BUTTON) && (state == GLUT_DOWN))
	{
		MouseActive = true;
		InitY = y;
	}
	else
	{
		MouseActive = false;
	}
}

void MouseMove(int x, int y)
{
	if (!MouseActive)
	{
		return;
	}
	ChangeViewingAngle((InitY - y)*0.5);
	InitY = y;
}

//End of mouse functions/////////////////////////////////////////////////////////////

int main(int argc, char **argv)
{
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);
	glutInitWindowSize(600, 600);
	glutInitWindowPosition(200, 200);
	glutCreateWindow("Ice Cube Engine");
	initRendering();

	glutDisplayFunc(DrawScene);
	glutReshapeFunc(handleResize);
	glutIdleFunc(IdleFunc);
	glutKeyboardFunc(keyboardFunc);
	glutSpecialFunc(specialKeys);
	glutMouseFunc(MouseFunc);
	glutMotionFunc(MouseMove);

	glutMainLoop();
	return 0;
}