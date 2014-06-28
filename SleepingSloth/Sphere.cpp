#include "Sphere.h"
#include <glut.h>


void Sphere::Draw()
{
	DrawSphere();
}

void Sphere::DrawSphere()
{

	glPushMatrix();
	glTranslatef(XPos, YPos, ZPos);
	glScalef(XScale, YScale, ZScale);
	glColor3f(RCol, GCol, BCol);

	GLUquadricObj *qobj;
	qobj = gluNewQuadric();
	gluQuadricDrawStyle(qobj, GLU_FILL);
	glNewList(1, GL_COMPILE); 
	gluSphere(qobj, 13.0, 40, 40);
	glEndList();

	glCallList(1);
	glPopMatrix();
}