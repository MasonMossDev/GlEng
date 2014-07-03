#include <glut.h>
#include <iostream>
#include <math.h>
#include <ctime>
#include <string>
#include <stdlib.h>
#include <sstream>
#include "tinyxml2.h"
#include "ObjectList.h"
#include "Circles.h"
#include "Cones.h"
#include "Cubes.h"
#include "Cylinder.h"
#include "Sphere.h"
#include "ObjectFactory.h"
#include "XmlSerializer.h"

//Selection Buffer
#define SelBufferSize 512

//Window size
static int MainWindow;
static int Border = 6, H = 600, W = 350;

//Picking Stuff
#define RENDER	1
#define SELECT	2
#define BUFSIZE 1024
GLuint SelectBuf[BUFSIZE];
GLuint Hits;
int Mode = RENDER;
int CursorX, CursorY;

using namespace std;
using namespace tinyxml2;

double VerticalAngle = -20.0f;
bool MouseActive = false;
int InitY;
unsigned char buttonVal;
Cubes cube2;
XMLDocument* Doc;
XMLElement* root;
ObjectFactory* Object;
bool Rotate = false;
int RotDir = -1;
double Rot_Angle = 0.0f;
double cameraZ = -150.0f;
clock_t RotStartTime;
ObjectList* objStorageList;
int PointX = 0;
int PointY = 0;
int PointXTemp = 0;
int PointYTemp = 0;


void TestDrawing( )
{
	if ( objStorageList != nullptr )
	{
		for ( int i = 0; i < objStorageList->Size( ); i++ )
		{
			objStorageList->GetObjectFactoryItem( i )->Draw( );
		}
	}


	/*	ObjectFactory *Circ1 = ObjectFactory::create("Circles");
		Circ1->SetValues( 0, 0, 0, 1, 1, 1, 0, 0.1, 0.5 );
		Circ1->Draw();

		ObjectFactory *Cube1 = ObjectFactory::create("Cubes");
		Cube1->SetValues( 0, 0, 20, 1, 1, 1, 1, 0, 1 );
		Cube1->Draw();

		ObjectFactory *Cone1 = ObjectFactory::create("Cones");
		Cone1->SetValues(0, 0, 40, 1, 1, 1, 1, 0, 0);
		Cone1->Draw();

		ObjectFactory *Cy1 = ObjectFactory::create("Cylinder");
		Cy1->SetValues(0, 0, 120, 5, 1, 5, 1, 0, 0);
		Cy1->Draw();

		ObjectFactory *Sphere1 = ObjectFactory::create("Sphere");
		Sphere1->SetValues(0, 5, -40, 1, 1, 1, 0, 0.1, 0.5);
		Sphere1->Draw();

		Circles circle1;
		ObjectFactory * Obj1 = &circle1;
		Obj1->SetValues( 0, 0, 60, 1, 1, 1, 0, 0.1, 1 );
		circle1.DrawCircle( );

		Cones Cone2;
		ObjectFactory* Obj3 = &Cone2;
		Obj3->SetValues(0, 0, 100, 1, 1, 1, 0, 1, 0);
		Cone2.DrawCone();

		Sphere Sphere2;
		ObjectFactory* Obj5 = &Sphere2;
		Obj5->SetValues(0, 5, 140, 1, 1, 1, 0, 1, 0);
		Obj5->Draw();

		Cylinder Cy2;
		ObjectFactory* Obj4 = &Cy2;
		Obj4->SetValues(0, 0, -20, 1, 1, 1, 0, 1, 0);
		Cy2.DrawCylinder();*/
}

void initRendering( )
{
	glEnable( GL_DEPTH_TEST );
}

void handleResize( int w , int h )
{
	float ratio;


	glViewport( 0 , 0 , w , h );
	glMatrixMode( GL_PROJECTION );
	glLoadIdentity( );
	gluPerspective( 45 , (double)w / (double)h , 1.0 , 1500 );
	glMatrixMode( GL_MODELVIEW );
	glLoadIdentity( );

}

void DrawGrid( )
{
	glPushMatrix( );
	glBegin( GL_LINES );

	for ( int i = -50; i <= 50; i++ )
	{
		glVertex3f( i , 0.0 , 50.0 );
		glVertex3f( i , 0.0 , -50.0 );

		glVertex3f( -50.0 , 0.0 , i );
		glVertex3f( 50.0 , 0.0 , i );
	}

	glEnd( );
	glPopMatrix( );
}
void DrawScene( )
{
	glEnable( GL_BLEND | GL_DEPTH_BUFFER_BIT );
	glBlendFunc( GL_SRC_ALPHA , GL_ONE_MINUS_DST_ALPHA );
	glClearColor( 0.0 , 0.0 , 0.0 , 0.0 );
	glClear( GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT );
	glMatrixMode( GL_MODELVIEW );
	glLoadIdentity( );

	gluLookAt( 0.0 , 0.0 , cameraZ , 1.0 , 1.0 , 1.0 , 0.0 , 3.0 , 0.0 );
	glRotatef( VerticalAngle , 1.0 , 0.0 , 0.0 );
	glRotatef( Rot_Angle , 0.0 , 1.0 , 0.0 );

	//Drawing Function is below
	TestDrawing( );

	glColor3f( 0.2 , 0.0 , 1.0 );
	DrawGrid( );
	///////////////////////////

	glutSwapBuffers( );
}

#define CUBE 1
#define FLOOR 2
void renderInSelectionMode( )
{
	glInitNames( );
	glPushName( FLOOR );
	DrawGrid( );
	glPopName( );
	objStorageList = ObjectList::GetInstance( );
	for ( int i = 0; i < objStorageList->Size( ); i++ )
	{
		glPushMatrix( );
		glPushName( i );
		objStorageList->GetObjectFactoryItem( i )->Draw( );
		glPopName( );
		glPopMatrix( );
	}


}

void keyboardFunc(unsigned char btn, int w, int h)
{

	if ( btn == 'z' || btn == 'Z' )
	{
		buttonVal = 'Z';
	}
	if ( btn == 'c' || btn == 'C' )
	{
		objStorageList = ObjectList::GetInstance( );
		if ( objStorageList->Size( ) != 0 )
		{
			ObjectFactory::PopTopOfNameList( );
			objStorageList->RemoveTopOfList( );
		}

	}

	if (btn == 'L' || btn == 'l')
	{		
		objStorageList = ObjectList::GetInstance();
		XmlSerializer serializer( XmlSerializer::ModeRead );
		serializer.LoadFromXml( *objStorageList );
	}
	if ( btn == 'S' || btn == 's' )
	{
		objStorageList = ObjectList::GetInstance();

		if (objStorageList != nullptr)
		{
			XmlSerializer serializer(XmlSerializer::ModeWrite);
			serializer.WriteToXml(objStorageList);
		}
	}
	//Stop and start the rotation
	if ( ( btn == 'R' ) || ( btn == 'r' ) )
	{
		Rotate = !Rotate;
		if (Rotate) {
			RotStartTime = clock();
		}
	}
	//Change the dirrection of rotation
	if ( ( btn == 'X' ) || ( ( btn == 'x' ) && ( Rotate ) ) )
	{
		RotDir = -RotDir;
	}

	if ( btn == '`' )
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
		newObj->SetValues( xCoord , yCoord , zCoord , xScale , yScale , zScale , rCol , gCol , bCol);
		objStorageList = ObjectList::GetInstance( );
		objStorageList->AddObject( newObj );

	}

	if ( btn == 27 )
	{
		exit( 0 );
	}
}

//Code to zoom in and out of the scene
void zoom( double zoomAmount )
{
	cameraZ += zoomAmount;
}

void specialKeys( int key , int w , int h )
{
	if ( key == GLUT_KEY_UP )
	{
		zoom( 1.0 );
	}
	if ( key == GLUT_KEY_DOWN )
	{
		zoom( -1.0 );
	}
}

void rotate( double deltaTheta )
{
	Rot_Angle += deltaTheta;
	while ( Rot_Angle >= 360.0 )
	{
		Rot_Angle -= 360.0;
	}
	while ( Rot_Angle < 0.0 )
	{
		Rot_Angle += 360.0;
	}
}

void IdleFunc( )
{
	if ( Rotate )
	{
		double deltaTheta = 36.0* ( clock( ) - RotStartTime ) / CLOCKS_PER_SEC * RotDir;
		rotate( deltaTheta );
		RotStartTime = clock( );
	}
	glutPostRedisplay( );
}

//Beginning of mouse functions///////////////////////////////////////////////////////
//Camera Angles of the scene controlled by the mouse
void ChangeViewingAngle( double deltaView )
{
	VerticalAngle += deltaView;
	if ( VerticalAngle > 180.0 )
		VerticalAngle = 180;
	if ( VerticalAngle < -180 )
		VerticalAngle = -180;
}

void GetOGLPos( int &x , int &y )
{
	double xP = x / (double)600
		* ( 600 - 0 ) + 0;
	double yP = ( 1 - y / (double)600 )
		* ( 600 - 0 ) + 0;
}
GLuint selectBuf[512];

void MouseFunc( int button , int state , int x , int y )
{

	if ( ( button == GLUT_LEFT_BUTTON ) && ( state == GLUT_DOWN ) )
	{
		MouseActive = true;
		InitY = y;
	}
	else
	{
		MouseActive = false;
	}
}


void MouseMove( int x , int y )
{
	if ( !MouseActive )
	{
		return;
	}


	if ( buttonVal == 'Z' )
	{



		PointX = PointXTemp - 296;
		PointY = -( PointYTemp - 300 ) - 16;

		GLint viewport[4]; //var to hold the viewport info
		GLdouble modelview[16]; //var to hold the modelview info
		GLdouble projection[16]; //var to hold the projection matrix info
		GLdouble winX , winY , winZ; //variables to hold screen x,y,z coordinates
		GLdouble worldX , worldY , worldZ; //variables to hold world x,y,z coordinates

		glGetDoublev( GL_MODELVIEW_MATRIX , modelview ); //get the modelview info
		glGetDoublev( GL_MODELVIEW_MATRIX , projection ); //get the projection matrix info
		glGetIntegerv( GL_VIEWPORT , viewport ); //get the viewport info


		if ( PointY < -100 )
		{
			int i = 5;
		}

		if ( objStorageList != nullptr )
		{
			for ( int i = 0; i < objStorageList->Size( ); i++ )
			{
				ObjectFactory *obj = objStorageList->GetObjectFactoryItem( i );
				worldX = -50;
				worldY = 0;
				worldZ = 0;
				winX = 0;
				winY = 0;
				winZ = 0;
				gluUnProject( worldX , worldY , worldZ , modelview , projection , viewport , &winX , &winY , &winZ );
				if ( PointX >= obj->BottomLeftFront.x  &&  PointY >= obj->BottomLeftFront.y )
				{
					if ( PointX <= obj->BottomRightFront.x  &&  PointY >= obj->BottomRightFront.y )
					{
						if ( PointX >= obj->TopLeftFront.x  &&  PointY <= obj->TopLeftFront.y )
						{
							if ( PointX <= obj->TopRightFront.x && PointY <= obj->TopRightFront.y )
							{
								int x = 5;
								ObjectFactory *cube = objStorageList->GetObjectFactoryItem( i );
								x = 4;
							}
						}
					}
				}
			}
		}
	}
	else
	{
		ChangeViewingAngle( ( InitY - y )*0.5 );
		InitY = y;
	}



}



//End of mouse functions/////////////////////////////////////////////////////////////

int main( int argc , char **argv )
{
	glutInit( &argc , argv );
	glutInitDisplayMode( GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH );
	glutInitWindowSize( 600 , 600 );
	glutInitWindowPosition( 200 , 200 );
	glutCreateWindow( "Ice Cube Engine" );
	initRendering( );

	glutDisplayFunc( DrawScene );
	glutReshapeFunc( handleResize );
	glutIdleFunc( IdleFunc );
	glutKeyboardFunc( keyboardFunc );
	glutSpecialFunc( specialKeys );
	glutMouseFunc( MouseFunc );
	glutMotionFunc( MouseMove );
	glutKeyboardFunc( keyboardFunc );

	glutMainLoop( );

	return 0;
}