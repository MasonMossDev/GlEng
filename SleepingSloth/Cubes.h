#include "Circles.h"

class Cubes : public ObjectFactory
{
public:
	void DrawCube();
	void Draw();
	friend class ObjectFactory;

protected:
	void DrawFront();
	void DrawLeft();
	void DrawRight();
	void DrawBack();
	void DrawTop();
	void DrawBottom();

private:

};



