#include "Sphere.h"

vector<string> ObjectFactory::ObjTypeName;

ObjectFactory * ObjectFactory::create(std::string obj)
{
	ObjTypeName.insert( ObjTypeName.end(),obj );
	if (obj == "Cube") return new Cubes();
	if (obj == "Circle") return new Circles();
	if (obj == "Cone") return new Cones();
	if (obj == "Cylinder") return new Cylinder();
	if (obj == "Sphere") return new Sphere();
	return nullptr;
}

void ObjectFactory::SetValues(double xPos, double yPos, double zPos, double xScale, double yScale, double zScale, double rCol, double gCol, double bCol)
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

