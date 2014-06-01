#include "Cubes.h"

ObjectFactory * ObjectFactory::create(std::string obj)
{
	if (obj == "Cubes") return new Cubes();
	if (obj == "Circles") return new Circles();
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
