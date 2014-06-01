#include "ObjectFactory.h"

class Circles : public ObjectFactory
{
public:
	void DrawCircle();
	void Draw();
	friend class ObjectFactory;

private:
};




