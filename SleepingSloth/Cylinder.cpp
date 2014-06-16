#include "Cylinder.h"
#include <glut.h>
#include <math.h>
void Cylinder::Draw()
{
	DrawCylinder();
}

void Cylinder::DrawCylinder()
{

	glPushMatrix();
	glTranslatef(XPos, YPos, ZPos);
	glScalef(XScale, YScale, ZScale);
	glColor3f(RCol, GCol, BCol);

	glBegin(GL_QUAD_STRIP);
	for (int i = 0; i < 361; i++)
	{
		glVertex3f(cos(i), 0, sin(i));
		glVertex3f(cos(i), 25, sin(i));

	}
	glEnd();
	glPopMatrix();
}