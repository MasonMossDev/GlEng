#include <stdlib.h>
#include <iostream>

class ObjectFactory
{
public:
	static ObjectFactory * create(std::string obj);
	virtual void Draw() = 0;
	void SetValues(double xPos, double yPos, double zPos, double xScale, double yScale, double zScale, double rCol, double gCol, double bCol);
protected:
	double XPos, YPos, ZPos;
	double XScale, YScale, ZScale;
	double RCol, GCol, BCol;
};