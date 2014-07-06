#include <math.h>
#include <glut.h>
#include <gl.h>
#include <glu.h>
#include <stdio.h>
#include <stdlib.h>
#include "ObjectList.h"
#include "render.h"
#include <iostream>
#include <string>
#include <stdlib.h>
#include <sstream>
#include "XmlSerializer.h"

ObjectList* objStorageList;
static GLint ObjectDisplayList;

void quit( ) {}


void processKeyboard( unsigned char key , int x , int y )
{
	printf( "key: %d\n" , key );
	if ( key == '`' )
	{
		string objType;
		float xCoord , yCoord , zCoord , rCol , gCol , bCol , xScale , yScale , zScale;

		cout << "Enter the object Type to create: ";
		cin >> objType;
		cout << "Please enter the following attributes: " << endl;
		cout << "X Coordinate: ";
		cin >> xCoord;
		cout << "Y Coordinate: ";
		cin >> yCoord;
		cout << "Z Coordinate: ";
		cin >> zCoord;
		cout << "X Scale: ";
		cin >> xScale;
		cout << "Y Scale: ";
		cin >> yScale;
		cout << "Z Scale: ";
		cin >> zScale;
		cout << "Red Value: ";
		cin >> rCol;
		cout << "Green Value: ";
		cin >> gCol;
		cout << "Blue Value: ";
		cin >> bCol;

		ObjectFactory *newObj = ObjectFactory::create( objType );
		newObj->SetValues( xCoord , yCoord , zCoord , xScale , yScale , zScale , rCol , gCol , bCol );
		objStorageList = ObjectList::GetInstance( );
		objStorageList->AddObject( newObj );

	}
	if ( key == 'L' || key == 'l' )
	{
		objStorageList = ObjectList::GetInstance( );
		XmlSerializer serializer( XmlSerializer::ModeRead );
		serializer.LoadFromXml( *objStorageList );
	}
	if ( key == 'S' || key == 's' )
	{
		objStorageList = ObjectList::GetInstance( );

		if ( objStorageList != nullptr )
		{
			XmlSerializer serializer( XmlSerializer::ModeWrite );
			serializer.WriteToXml( objStorageList );
		}
	}
	if ( key == 'Z' || key == 'z' )
	{
		objStorageList = ObjectList::GetInstance( );
		if ( objStorageList->Size( ) != 0 )
		{
			ObjectFactory::PopTopOfNameList( );
			objStorageList->RemoveTopOfList( );
		}

	}
}

void picked( GLuint name , int sw )
{
	printf( "my name = %d in %d\n" , name , sw );
}


void init( camera *cam )
{


	cam->pos[0] = 1.5;
	cam->pos[1] = 3.75;
	cam->pos[2] = 3;

	cam->lookAt[0] = 1.5;
	cam->lookAt[1] = 1.75;
	cam->lookAt[2] = 0;

	cam->lookUp[0] = 0;
	cam->lookUp[1] = 1;
	cam->lookUp[2] = 0;

}


void DrawGrid( )
{
	glPushMatrix( );
	glBegin( GL_LINES );
	glColor3f( 0 , 0 , 1 );
	for ( int i = -25; i <= 25; i++ )
	{
		glVertex3f( i , 0.0 , 25 );
		glVertex3f( i , 0.0 , -25 );

		glVertex3f( -25 , 0.0 , i );
		glVertex3f( 25 , 0.0 , i );
	}

	glEnd( );
	glPopMatrix( );
}


GLuint createDL( )
{
	GLuint ObjectDrawList;

	// Create the id for the list
	ObjectDrawList = glGenLists( 1 );

	glNewList( ObjectDrawList , GL_COMPILE );
	if ( objStorageList != nullptr )
	{
		for ( int i = 0; i < objStorageList->Size( ); i++ )
		{
			objStorageList->GetObjectFactoryItem( i )->Draw( );
		}
	}
	glEndList( );

	return( ObjectDrawList );
}


void initScene( int argc , char **argv )
{

	glEnable( GL_DEPTH_TEST );
	ObjectDisplayList = createDL( );
}



void draw( )
{
	// Draw ground
	DrawGrid( );

	// Draw 4 SnowMen
	if ( objStorageList != nullptr )
	{
		for ( int i = 0; i < objStorageList->Size( ); i++ )
		{
			glPushMatrix( );
			glPushName( i + 1 );
			objStorageList->GetObjectFactoryItem( i )->Draw( );

			glPopName( );
			glPopMatrix( );
		}
	}
}




