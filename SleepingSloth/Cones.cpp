#include "Cones.h"
#include <glut.h>

void Cones::Draw()
{
	DrawCone();
}

void Cones::DrawCone()
{

	glPushMatrix();
	glTranslatef(XPos, YPos, ZPos);
	glScalef(XScale, YScale, ZScale);
	glColor3f(RCol, GCol, BCol);

	GLfloat twicePi = 2.0 * 3.14159265;

	glBegin(GL_TRIANGLE_FAN);
	glVertex3f(0, 10, 0);
	for (int i = 0; i <= 50; i++)
	{
		glColor3f(0, 0, 1);
		glVertex3f(0 + (10 * cos(i * twicePi / 50)), 10 + (10 * sin(i * twicePi / 50)), 10);
	}

	glEnd();
	glPopMatrix();
}