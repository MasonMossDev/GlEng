#include "ObjectFactory.h"
#include "Circles.h"
#include "Cones.h"
#include "Cubes.h"
#include "Cylinder.h"
#include "Sphere.h"
#include "Pyramid.h"

vector<string> ObjectFactory::ObjTypeName;

ObjectFactory * ObjectFactory::create(std::string obj)
{
	ObjTypeName.insert( ObjTypeName.end(),obj );
	if (obj == "cube") return new Cubes();
	if (obj == "circle") return new Circles();
	if (obj == "cone") return new Cones();
	if (obj == "cylinder") return new Cylinder();
	if (obj == "sphere") return new Sphere();
	if (obj == "pyramid") return new Pyramid();
	return nullptr;
}

void ObjectFactory::PopTopOfNameList()
{
	ObjTypeName.pop_back();
}

void ObjectFactory::SetValues(double xPos, double yPos, double zPos, double xScale, double yScale, double zScale, double rCol, double gCol, double bCol, float zoomAmount)
{
	XPos = xPos;
	YPos = yPos;
	ZPos = zPos;
	XScale = xScale;
	YScale = yScale;
	ZScale = zScale;
	RCol = rCol;
	GCol = gCol;
	BCol = bCol;
}

string ObjectFactory::GetObjTypeName(int i) 
{
	return ObjTypeName.at(i);
}

void ObjectFactory::SetBottomLeftFront(double x, double y, double z)
{
	BottomLeftFront.x = x;
	BottomLeftFront.y = y;
	BottomLeftFront.z = z;
}
void ObjectFactory::SetBottomLeftBack(double x, double y, double z)
{
	BottomLeftBack.x = x;
	BottomLeftBack.y = y;
	BottomLeftBack.z = z;
}
void ObjectFactory::SetTopLeftFront(double x, double y, double z)
{
	TopLeftFront.x = x;
	TopLeftFront.y = y;
	TopLeftFront.z = z;
}
void ObjectFactory::SetTopLeftBack(double x, double y, double z)
{
	TopLeftBack.x = x;
	TopLeftBack.y = y;
	TopLeftBack.z = z;
}
void ObjectFactory::SetTopRightFront(double x, double y, double z)
{
	TopRightFront.x = x;
	TopRightFront.y = y;
	TopRightFront.z = z;
}
void ObjectFactory::SetTopRightBack(double x, double y, double z)
{
	TopRightBack.x = x;
	TopRightBack.y = y;
	TopRightBack.z = z;
}
void ObjectFactory::SetBottomRightFront(double x, double y, double z)
{
	BottomRightFront.x = x;
	BottomRightFront.y = y;
	BottomRightFront.z = z;
}
void ObjectFactory::SetBottomRightBack(double x, double y, double z)
{
	BottomRightBack.x = x;
	BottomRightBack.y = y;
	BottomRightBack.z = z;
}