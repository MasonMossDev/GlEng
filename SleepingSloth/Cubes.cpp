#include "Cubes.h"
#include <glut.h>


void Cubes::Draw()
{
	DrawCube();
}

void Cubes::DrawCube()
{
	glPushMatrix();
	glTranslatef	( XPos, YPos, ZPos );
	glScalef		( XScale, YScale, ZScale );
	glColor3f		( RCol, GCol, BCol );

	glBegin(GL_TRIANGLE_STRIP);

	int x = 0;
	int y = 0;

	glVertex3f(0, 0, 0);
	glVertex3f(10, 0, 0);

	for (int i = 0; i < 51; i++)
	{
		if (i % 2 > 0)
		{
			x += 10;
			y += 1;
		}
		else
		{
			x = 0;
		}
		glVertex3f(x, y, 0);
	}

	


	glEnd();
	glPopMatrix();

	
}