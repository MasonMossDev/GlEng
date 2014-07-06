#include "ModesMenu.h"
#include <glut.h>

ModesMenu::ModesMenu( )
{

}

void ModesMenu::Draw( )
{
	
	DrawViewMenu( );
	
	DrawEditMenu( );

	DrawWalkMenu( );
}

void ModesMenu::DrawEditMenu( )
{
	glPushMatrix( );
	
		glTranslatef( 0.04 , 2.12 , 0.0 );
		glBegin( GL_QUADS);
		glColor3f( 0.2 , 0.1 , 0.8 );
			glVertex2f( -0.04 , -0.04);
			glVertex2f( -0.04 , 1.04 );
			glVertex2f( 0.0 , 1.04 );
			glVertex2f( 0.0 , -0.04 );

			glVertex2f( -0.04 , -0.04 );
			glVertex2f( -0.04 , 0.0 );
			glVertex2f( 1.04 ,  0.0 );
			glVertex2f( 1.04 , -0.04 );

			glVertex2f( 1.0 , -0.04 );
			glVertex2f( 1.0 , 1.04 );
			glVertex2f( 1.04 , 1.04 );
			glVertex2f( 1.04 , -0.04 );

			glVertex2f( -0.04 , 1.0 );
			glVertex2f( -0.04 , 1.04 );
			glVertex2f( 1.04 , 1.04 );
			glVertex2f( 1.04 , 1.0 );
		glEnd( );
	
		glBegin( GL_QUADS );
		glColor4f( 0.2 , 0.1 , 0.8, 0.4 );
			glVertex2f( 0 , 0 );
			glVertex2f( 0 , 1 );
			glVertex2f( 1 , 1 );
			glVertex2f( 1 , 0 );
	
		glEnd( );
	glPopMatrix( );
}

void ModesMenu::DrawViewMenu( )
{
	glPushMatrix( );
	
	glTranslatef( 0.04 , 1.08 , 0.0 );
		glBegin( GL_QUADS);

		glColor3f( 0.2 , 0.1 , 0.8 );
			glVertex2f( -0.04 , -0.04);
			glVertex2f( -0.04 , 1.04 );
			glVertex2f( 0.0 , 1.04 );
			glVertex2f( 0.0 , -0.04 );

			glVertex2f( 1.0 , -0.04 );
			glVertex2f( 1.0 , 1.04 );
			glVertex2f( 1.04 , 1.04 );
			glVertex2f( 1.04 , -0.04 );

		glEnd( );
	
		glBegin( GL_QUADS );
		glColor4f( 0.2 , 0.1 , 0.8 , 0.4 );
			glVertex2f( 0 , 0 );
			glVertex2f( 0 , 1 );
			glVertex2f( 1 , 1 );
			glVertex2f( 1 , 0 );
	
		glEnd( );
	glPopMatrix( );
}

void ModesMenu::DrawWalkMenu( )
{
	glPushMatrix( );
		glTranslatef( 0.04 , 0.04 , 0.0 );
		glBegin( GL_QUADS);
		glColor3f( 0.2 , 0.1 , 0.8 );
			glVertex2f( -0.04 , -0.04);
			glVertex2f( -0.04 , 1.04 );
			glVertex2f( 0.0 , 1.04 );
			glVertex2f( 0.0 , -0.04 );

			glVertex2f( -0.04 , -0.04 );
			glVertex2f( -0.04 , 0.0 );
			glVertex2f( 1.04 ,  0.0 );
			glVertex2f( 1.04 , -0.04 );

			glVertex2f( 1.0 , -0.04 );
			glVertex2f( 1.0 , 1.04 );
			glVertex2f( 1.04 , 1.04 );
			glVertex2f( 1.04 , -0.04 );

			glVertex2f( -0.04 , 1.0 );
			glVertex2f( -0.04 , 1.04 );
			glVertex2f( 1.04 , 1.04 );
			glVertex2f( 1.04 , 1.0 );
		glEnd( );
	
		glBegin( GL_QUADS );
		glColor4f( 0.2 , 0.1 , 0.8 , 0.4 );
			glVertex2f( 0 , 0 );
			glVertex2f( 0 , 1 );
			glVertex2f( 1 , 1 );
			glVertex2f( 1 , 0 );
	
		glEnd( );
	glPopMatrix( );
}