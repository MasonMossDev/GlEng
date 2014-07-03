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



	DrawFront();
	DrawLeft();
	DrawRight();
	DrawBack();
	DrawTop();
	DrawBottom();
	glPopMatrix();
	
}

void Cubes::DrawFront()
{
	glPushMatrix();

		glBegin(GL_TRIANGLE_STRIP);

		int x = 0;
		int y = 0;
		int z = 0;

			glVertex3f(0, 0, 0);
			glVertex3f(10, 0, 0);
			int num = (-10 * XScale) ;
			this->SetBottomLeftFront(num , 0, 0);
			this->SetTopLeftFront(num, 25 * YScale, 0);
			this->SetTopRightFront(0, 25 * YScale, 0);
			this->SetBottomRightFront(0, 0, 0);


			for (int i = 0; i < 26; i++)
			{
				if (i % 2 > 0)
				{
					x += 10;
				}
				else
				{
					x = 0;
				}
				if (i == 25)
				{
					y += 0;
				}
				else
				{
					y = i;
				}
				glVertex3f(x, y, 0);
			}



			x = 0;
			y = 0;
			z = 0;

		glEnd();

	glPopMatrix();

}
void Cubes::DrawLeft()
{
	glPushMatrix();

		glBegin(GL_TRIANGLE_STRIP);

		int x = 0;
		int y = 0;
		int z = 0;

			glVertex3f(0, 0, 0);
			glVertex3f(0, 0, 10);

			for ( int i = 0; i < 26; i++ )
			{
				if (i % 2 > 0)
				{
					z += 10;				
				}
				else
				{
					z = 0;
				}
				if (i == 25)
				{
					y += 0;
				}
				else
				{
					y = i;
				}

				glVertex3f(0, y, z);
			}

			x = 0;
			y = 0;
			z = 0;

		glEnd();

	glPopMatrix();
}
void Cubes::DrawRight()
{
	glPushMatrix();

	glBegin(GL_TRIANGLE_STRIP);

	int x = 0;
	int y = 0;
	int z = 0;

	glVertex3f(10, 0, 10);
	glVertex3f(10, 0, 0);
	

	for (int i = 0; i < 26; i++)
	{
		if (i % 2 == 0)
		{
			z = 10;
		}
		else
		{
			z = 0;
		}
		if (i == 25)
		{
			y += 0;
		}
		else
		{
			y = i;
		}
		glVertex3f(10, y, z);
	}

	x = 0;
	y = 0;
	z = 0;

	glEnd();

	glPopMatrix();
}
void Cubes::DrawBack()
{
	glPushMatrix();

	glBegin(GL_TRIANGLE_STRIP);

	int x = 0;
	int y = 0;
	int z = 0;

	glVertex3f(0, 0, 10);
	glVertex3f(10, 0, 10);

	for (int i = 0; i < 26; i++)
	{
		if (i % 2 > 0)
		{
			x += 10;
		}
		else
		{
			x = 0;
		}
		if (i == 25)
		{
			y += 0;
		}
		else
		{
			y = i;
		}

		glVertex3f(x, y, 10);
	}

	x = 0;
	y = 0;
	z = 0;

	glEnd();

	glPopMatrix();
}
void Cubes::DrawTop()
{
	glPushMatrix();

	glBegin(GL_TRIANGLE_STRIP);

	int x = 0;
	int y = 0;
	int z = 0;

	glVertex3f(0, 24, 0);
	glVertex3f(10, 24, 0);

	for (int i = 0; i < 12; i++)
	{
		if (i % 2 > 0)
		{
			x += 10;
		}
		else
		{
			x = 0;
		}
		if (i == 11)
		{
			z += 0;
		}
		else
		{
			z = i;
		}

		glVertex3f(x, 24, z);
	}
	x = 0;
	y = 0;
	z = 0;

	glEnd();

	glPopMatrix();
}
void Cubes::DrawBottom()
{
	glPushMatrix();

	glBegin(GL_TRIANGLE_STRIP);

	glVertex3f(0, 0, 0);
	glVertex3f(10, 0, 0);
	glVertex3f(0, 0, 10);
	glVertex3f(10, 0, 10);

	glEnd();

	glPopMatrix();
}