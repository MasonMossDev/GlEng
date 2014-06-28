#include "Circles.h"
#include <glut.h>


void Circles::Draw()
{
	DrawCircle();
}

void Circles::DrawCircle( )
{

	glPushMatrix();
	glTranslatef(XPos, YPos, ZPos);
	glScalef(XScale, YScale, ZScale);
	glColor3f(RCol, GCol, BCol);

	GLfloat twicePi = 2.0 * 3.14159265;

	glBegin(GL_TRIANGLE_FAN);
	glVertex3f(0, 0, 0);
	for (int i = 0; i <= 50; i++)
	{
		glVertex3f(0 + (10 * cos(i * twicePi / 50)), 10 + (10 * sin(i * twicePi / 50)), 0);
	}

	glEnd();
	glPopMatrix();
}