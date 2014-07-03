
#ifndef OBJECTFACTORY_H_INCLUDED
#define OBJECTFACTORY_H_INCLUDED

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
	static void PopTopOfNameList();
	
	struct CollisionBoxPoint
	{
		double x;
		double y;
		double z;
	};

	void SetBottomLeftFront		( double x, double y, double z );
	void SetBottomLeftBack		( double x, double y, double z );
	void SetTopLeftFront		( double x, double y, double z );
	void SetTopLeftBack			( double x, double y, double z );
	void SetTopRightFront		( double x, double y, double z );
	void SetTopRightBack		( double x, double y, double z );
	void SetBottomRightFront	( double x, double y, double z );
	void SetBottomRightBack		( double x, double y, double z );

	CollisionBoxPoint BottomLeftFront;
	CollisionBoxPoint BottomLeftBack;
	CollisionBoxPoint TopLeftFront;
	CollisionBoxPoint TopLeftBack;
	CollisionBoxPoint TopRightFront;
	CollisionBoxPoint TopRightBack;		
	CollisionBoxPoint BottomRightFront;
	CollisionBoxPoint BottomRightBack;


	inline double getXpos() const
	{
		return XPos;
	}

	inline double getYpos() const
	{
		return YPos;
	}

	inline double getZpos() const
	{
		return ZPos;
	}

	inline double getXscale() const
	{
		return XScale;
	}

	inline double getYscale() const
	{
		return YScale;
	}

	inline double getZscale() const
	{
		return ZScale;
	}

	inline double getRcol() const
	{
		return RCol;
	}

	inline double getGcol() const
	{
		return GCol;
	}

	inline double getBcol() const
	{
		return BCol;
	}


protected:
	double XPos, YPos, ZPos;
	double XScale, YScale, ZScale;
	double RCol, GCol, BCol;
	double ZoomAmount;
	static vector<string> ObjTypeName;
};

#endif 


