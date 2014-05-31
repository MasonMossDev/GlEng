#include "Cubes.h"
#include <glut.h>

void Cubes::DrawCube()
{
	glTranslatef	( XPos, YPos, ZPos );
	glScalef		( XScale, YScale, ZScale );
	glColor3f		( RCol, GCol, BCol );
	
}