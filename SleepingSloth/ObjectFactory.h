#include <stdlib.h>
#include <iostream>
#include <vector>

using namespace std;

class ObjectFactory
{
public:
	static ObjectFactory * create(string obj);
	virtual void Draw() = 0;
	void SetValues(double xPos, double yPos, double zPos, double xScale, double yScale, double zScale, double rCol, double gCol, double bCol);

	string GetObjTypeName(int i);

	inline double getXpos() const;
	inline double getYpos() const;
	inline double getZpos() const;
	inline double getXscale() const;
	inline double getYscale() const;
	inline double getZscale() const;
	inline double getRcol() const;
	inline double getGcol() const;
	inline double getBcol() const;

protected:
	double XPos, YPos, ZPos;
	double XScale, YScale, ZScale;
	double RCol, GCol, BCol;
	static vector<string> ObjTypeName;
};

double ObjectFactory::getXpos() const
{
	return XPos;
}

inline double ObjectFactory::getYpos() const
{
	return YPos;
}

inline double ObjectFactory::getZpos() const
{
	return ZPos;
}

inline double ObjectFactory::getXscale() const
{
	return XScale;
}

inline double ObjectFactory::getYscale() const
{
	return YScale;
}

inline double ObjectFactory::getZscale() const
{
	return ZScale;
}

inline double ObjectFactory::getRcol() const
{
	return RCol;
}

inline double ObjectFactory::getGcol() const
{
	return GCol;
}

inline double ObjectFactory::getBcol() const
{
	return BCol;
}