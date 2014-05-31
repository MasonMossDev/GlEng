#include "Circles.h"
#include <glut.h>
#include <math.h>

void Circles::DrawCircle( int amount )
{
	for (int i = 0; i < amount; i++)
	{
		glPushMatrix();
		glTranslatef(XPos, YPos, ZPos);
		glScalef(XScale, YScale, ZScale);
		glColor3f(RCol, GCol, BCol);

		GLfloat twicePi = 2.0 * 3.14159265;

		glBegin(GL_TRIANGLE_FAN);
		glVertex3f(0, 50, 50);
		for (int i = 0; i <= 150; i++)
		{
			if (i % 2 > 0)
			{
				glColor3f(1, 0, 0);
				glVertex3f(0 + (50 * cos(i * twicePi / 150)), 50 + (50 * sin(i * twicePi / 150)), 30);
			}
			else
			{
				glColor3f(0, 0, 1);
				glVertex3f(0 + (50 * cos(i * twicePi / 150)), 50 + (50 * sin(i * twicePi / 150)), 70);
			}
		}

		glEnd();
		glPopMatrix();
	}
}