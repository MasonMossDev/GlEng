#include <glut.h>
#include <iostream>
#include <math.h>
#include <ctime>
#include <string>
#include <stdlib.h>
#include "ObjectList.h"
#include "tinyxml2.h"
#include <sstream>
#include <xstring>
using namespace std;
using namespace tinyxml2;

double VerticalAngle = -20.0f;
bool MouseActive = false;
int InitY;


XMLDocument* Doc;
XMLElement* root;
ObjectFactory* Object;
bool Rotate = false;
int RotDir = -1;
double Rot_Angle = 0.0f;
double cameraZ = -30.0f;
clock_t RotStartTime;
ObjectList* objStorageList;

void TestDrawing()
{
	if (objStorageList != nullptr)
	{
		for (int i = 0; i < objStorageList->Size(); i++)
		{
			objStorageList->GetObjectFactoryItem(i)->Draw();
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

	Cubes cube2;
	ObjectFactory * Obj2 = &cube2;
	Obj2->SetValues( 0, 0, 80, 1, 1, 1, 0, 1, 0 );
	cube2.DrawCube( );

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

void initRendering()
{
	glEnable(GL_DEPTH_TEST);
}

void handleResize(int w, int h)
{
	glViewport(0, 0, w, h);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluPerspective(45.0, (double)w / (double)h, 1.0, 1500);
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();

}

void DrawScene()
{
	glEnable(GL_BLEND | GL_DEPTH_BUFFER_BIT);
	glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_DST_ALPHA);
	glClearColor(0.0, 0.0, 0.0, 0.0);
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();

	gluLookAt(0.0, 0.0, cameraZ, 1.0, 1.0, 1.0, 0.0, 3.0, 0.0);
	glRotatef(VerticalAngle, 1.0, 0.0, 0.0);
	glRotatef(Rot_Angle, 0.0, 1.0, 0.0);

	//Drawing Function is below
	TestDrawing();
	///////////////////////////

	glutSwapBuffers();
}

void keyboardFunc(unsigned char btn, int w, int h)
{

	if (btn == 'L' || btn == 'l')
	{
		XMLDocument doc;
		doc.LoadFile("test.xml");

		XMLNode* decl = doc.FirstChild();
		
		XMLNode* root = decl->NextSibling();
		
		XMLNode* objParentNode = nullptr;
		
		for (objParentNode = root->FirstChild(); objParentNode; objParentNode = objParentNode->NextSibling())
		{
			XMLNode* typeNode = objParentNode->FirstChild();
			XMLElement* typeElement = typeNode->ToElement();
			const char * typeVal = typeElement->GetText();

			XMLNode* xCoordNode = typeNode->NextSibling()->FirstChild();
			XMLElement* xCoordElement = xCoordNode->ToElement();
			double xCoordVal = atof(xCoordElement->GetText());

			XMLNode* yCoordNode = xCoordNode->NextSibling();
			XMLElement* yCoordElement = yCoordNode->ToElement();
			double yCoordVal = atof(yCoordElement->GetText());

			XMLNode* zCoordNode = yCoordNode->NextSibling();
			XMLElement* zCoordElement = zCoordNode->ToElement();
			double zCoordVal = atof(zCoordElement->GetText());

			XMLNode* xScaleNode = typeNode->NextSibling()->NextSibling()->FirstChild();
			XMLElement* xScaleElement = xScaleNode->ToElement();
			double xScaleVal = atof(xScaleElement->GetText());

			XMLNode* yScaleNode = xScaleNode->NextSibling();
			XMLElement* yScaleElement = yScaleNode->ToElement();
			double yScaleVal = atof(yScaleElement->GetText());

			XMLNode* zScaleNode = yScaleNode->NextSibling();
			XMLElement* zScaleElement = zScaleNode->ToElement();
			double zScaleVal = atof(zScaleElement->GetText());

			XMLNode* rColNode = typeNode->NextSibling()->NextSibling()->NextSibling()->FirstChild();
			XMLElement* rColElement = rColNode->ToElement();
			double rColVal = atof(rColElement->GetText());

			XMLNode* gColNode = rColNode->NextSibling();;
			XMLElement* gColElement = gColNode->ToElement();
			double gColVal = atof(gColElement->GetText());

			XMLNode* bColNode = gColNode->NextSibling();;
			XMLElement* bColElement = bColNode->ToElement();
			double bColVal = atof(bColElement->GetText());

			ObjectFactory *newObj = ObjectFactory::create(typeVal);
			newObj->SetValues(xCoordVal, yCoordVal, zCoordVal, xScaleVal, yScaleVal, zScaleVal, rColVal, gColVal, bColVal);

			objStorageList = ObjectList::GetInstance();
			objStorageList->AddObject(newObj);
		}
	}
	if ( btn == 'S' || btn == 's' )
	{
		objStorageList = ObjectList::GetInstance();

		if (objStorageList != nullptr)
		{
			XMLDocument doc;
			XMLDeclaration *decl = doc.NewDeclaration();
			doc.InsertEndChild(decl);
			XMLNode *root = doc.NewElement( "ObjectFactoryList" );
			doc.InsertEndChild(root);
				
			for (int i = 0; i < objStorageList->Size(); i++)
			{

				XMLNode *objParentNode =	doc.NewElement("Object");
				XMLNode *objType =			doc.NewElement( "Type" );				
				XMLNode *objCoordinates =	doc.NewElement( "Coordinates" );
				XMLNode *objScale =			doc.NewElement( "Scale" );
				XMLNode *objColour =		doc.NewElement( "Colour" );

				XMLNode *objXcoord =		doc.NewElement( "XCoord" );
				XMLNode *objYcoord =		doc.NewElement( "YCoord" );
				XMLNode *objZcoord =		doc.NewElement( "ZCoord" );
					
				XMLNode *objXscale =		doc.NewElement( "XScale" );
				XMLNode *objYscale =		doc.NewElement( "YScale" );
				XMLNode *objZscale =		doc.NewElement( "ZScale" );

				XMLNode *objRcol =			doc.NewElement( "RCol" );
				XMLNode *objGcol =			doc.NewElement( "GCol" );
				XMLNode *objBcol =			doc.NewElement( "BCol" );

				stringstream xCoordStr, yCoordStr, zCoordStr, xScaleStr, yScaleStr, zScaleStr, rColStr, gColStr, bColStr;
					
				xCoordStr.str("");
				xCoordStr << objStorageList->GetObjectFactoryItem(i)->getXpos();

				yCoordStr.str("");
				yCoordStr << objStorageList->GetObjectFactoryItem(i)->getYpos();

				zCoordStr.str("");
				zCoordStr << objStorageList->GetObjectFactoryItem(i)->getZpos();

				xScaleStr.str("");
				xScaleStr << objStorageList->GetObjectFactoryItem(i)->getXscale();

				yScaleStr.str("");
				yScaleStr << objStorageList->GetObjectFactoryItem(i)->getYscale();

				zScaleStr.str("");
				zScaleStr << objStorageList->GetObjectFactoryItem(i)->getZscale();

				rColStr.str("");
				rColStr << objStorageList->GetObjectFactoryItem(i)->getRcol();

				gColStr.str("");
				gColStr << objStorageList->GetObjectFactoryItem(i)->getGcol();

				bColStr.str("");
				bColStr << objStorageList->GetObjectFactoryItem(i)->getBcol();

				XMLText *objTypeValue =		doc.NewText( objStorageList->GetObjectFactoryItem(i)->GetObjTypeName(i).c_str() );
				XMLText *objXcoordValue =	doc.NewText( xCoordStr.str().c_str() );
				XMLText *objYcoordValue =	doc.NewText( yCoordStr.str().c_str() );
				XMLText *objZcoordValue =	doc.NewText( zCoordStr.str().c_str() );
				XMLText *objXscaleValue =	doc.NewText( xScaleStr.str().c_str() );
				XMLText *objYscaleValue =	doc.NewText( yScaleStr.str().c_str() );
				XMLText *objZscaleValue =	doc.NewText( zScaleStr.str().c_str() );
				XMLText *objRcolValue =		doc.NewText( rColStr.str().c_str() );
				XMLText *objGcolValue =		doc.NewText( gColStr.str().c_str() );
				XMLText *objBcolValue =		doc.NewText( bColStr.str().c_str() );


				root->				InsertEndChild( objParentNode );
				objParentNode->		InsertEndChild(objType);
				objType->			InsertEndChild( objTypeValue );
				objParentNode->		InsertEndChild(objCoordinates);
				objParentNode->		InsertEndChild(objScale);
				objParentNode->		InsertEndChild(objColour);

				objCoordinates->	InsertEndChild( objXcoord );
				objXcoord->			InsertEndChild( objXcoordValue );

				objCoordinates->	InsertEndChild( objYcoord );
				objYcoord->			InsertEndChild( objYcoordValue );

				objCoordinates->	InsertEndChild( objZcoord );
				objZcoord->			InsertEndChild( objZcoordValue );

				objScale->			InsertEndChild( objXscale );
				objXscale->			InsertEndChild( objXscaleValue );

				objScale->			InsertEndChild( objYscale );
				objYscale->			InsertEndChild( objYscaleValue );

				objScale->			InsertEndChild( objZscale );
				objZscale->			InsertEndChild( objZscaleValue );

				objColour->			InsertEndChild( objRcol );
				objRcol->			InsertEndChild( objRcolValue );

				objColour->			InsertEndChild( objGcol );
				objGcol->			InsertEndChild( objGcolValue );

				objColour->			InsertEndChild( objBcol );
				objBcol->			InsertEndChild( objBcolValue );					
					
			}
			doc.SaveFile("test.xml");
		}
	}
	//Stop and start the rotation
	if ((btn == 'R') || (btn == 'r'))
	{
		Rotate = !Rotate;
		if (Rotate) {
			RotStartTime = clock();
		}
	}
	//Change the dirrection of rotation
	if ((btn == 'X') || ((btn == 'x') && (Rotate)))
	{
		RotDir = -RotDir;
	}

	if (btn == '`')
	{
		string objType;
		float xCoord, yCoord, zCoord, rCol, gCol, bCol, xScale, yScale, zScale;

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
		newObj->SetValues( xCoord, yCoord, zCoord, xScale, yScale, zScale, rCol, gCol, bCol );


		objStorageList = ObjectList::GetInstance();
		objStorageList->AddObject(newObj);

	}

	if (btn == 27)
	{
		exit(0);
	}
}

//Code to zoom in and out of the scene
void zoom(double zoomAmount)
{
	cameraZ += zoomAmount;
}

void specialKeys(int key, int w, int h)
{
	if (key == GLUT_KEY_UP)
	{
		zoom(1.0);
	}
	if (key == GLUT_KEY_DOWN)
	{
		zoom(-1.0);
	}
}

void rotate(double deltaTheta)
{
	Rot_Angle += deltaTheta;
	while (Rot_Angle >= 360.0)
	{
		Rot_Angle -= 360.0;
	}
	while (Rot_Angle < 0.0)
	{
		Rot_Angle += 360.0;
	}
}

void IdleFunc()
{
	if (Rotate)
	{
		double deltaTheta = 36.0* (clock() - RotStartTime) / CLOCKS_PER_SEC * RotDir;
		rotate(deltaTheta);
		RotStartTime = clock();
	}
	glutPostRedisplay();
}

//Beginning of mouse functions///////////////////////////////////////////////////////
//Camera Angles of the scene controlled by the mouse
void ChangeViewingAngle(double deltaView)
{
	VerticalAngle += deltaView;
	if (VerticalAngle > 180.0)
		VerticalAngle = 180;
	if (VerticalAngle < -180)
		VerticalAngle = -180;
}

void MouseFunc(int button, int state, int x, int y)
{
	if ((button == GLUT_LEFT_BUTTON) && (state == GLUT_DOWN))
	{
		MouseActive = true;
		InitY = y;
	}
	else
	{
		MouseActive = false;
	}
}

void MouseMove(int x, int y)
{
	if (!MouseActive)
	{
		return;
	}
	ChangeViewingAngle((InitY - y)*0.5);
	InitY = y;
}



//End of mouse functions/////////////////////////////////////////////////////////////

int main(int argc, char **argv)
{
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);
	glutInitWindowSize(600, 600);
	glutInitWindowPosition(200, 200);
	glutCreateWindow("Ice Cube Engine");
	initRendering();

	glutDisplayFunc(DrawScene);
	glutReshapeFunc(handleResize);
	glutIdleFunc(IdleFunc);
	glutKeyboardFunc(keyboardFunc);
	glutSpecialFunc(specialKeys);
	glutMouseFunc(MouseFunc);
	glutMotionFunc(MouseMove);
	glutKeyboardFunc(keyboardFunc);

	glutMainLoop();

	return 0;
}