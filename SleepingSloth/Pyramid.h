#include "ObjectFactory.h"

class Pyramid : public ObjectFactory
{
public:
	void DrawPyramid();
	void Draw();
	friend class ObjectFactory;

protected:
	void DrawFront();
	void DrawBack();
	void DrawLeft();
	void DrawRight();
	void DrawBottom();

private:
};