#include "Pyramid.h"
#include <glut.h>

void Pyramid::Draw()
{
	DrawPyramid();
}

void Pyramid::DrawPyramid()
{

	glPushMatrix();
		glTranslatef(XPos, YPos, ZPos);
		glScalef(XScale, YScale, ZScale);
		glColor3f(RCol, GCol, BCol);
	
		DrawFront();
		DrawBack();
		DrawLeft();
		DrawRight();

	glPopMatrix();
}

void Pyramid::DrawFront()
{
	glPushMatrix();
	glBegin(GL_TRIANGLES);

	glVertex3f(0.0, 0.0, 0.0);
	glVertex3f(5.0, 10.0, -5.0);
	glVertex3f(10.0, 0.0, 0.0);

	glEnd();
	glPopMatrix();
}

void Pyramid::DrawBack()
{
	glPushMatrix();
	glBegin(GL_TRIANGLES);

	glVertex3f(0.0, 0.0, -10.0);
	glVertex3f(5.0, 10.0, -5.0);
	glVertex3f(10.0, 0.0, -10.0);

	glEnd();
	glPopMatrix();
}

void Pyramid::DrawLeft()
{
	glPushMatrix();
	glBegin(GL_TRIANGLES);

	glVertex3f(0.0, 0.0, 0.0);
	glVertex3f(5.0, 10.0, -5.0);
	glVertex3f(0.0, 0.0, -10.0);

	glEnd();
	glPopMatrix();
}

void Pyramid::DrawRight()
{
	glPushMatrix();
	glBegin(GL_TRIANGLES);

	glVertex3f(10.0, 0.0, 0.0);
	glVertex3f(5.0, 10.0, -5.0);
	glVertex3f(10.0, 0.0, -10.0);

	glEnd();
	glPopMatrix();
}