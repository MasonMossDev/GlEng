#include "ObjectFactory.h"

class Cones : public ObjectFactory
{
public:
	void DrawCone();
	void Draw();
	friend class ObjectFactory;

private:
};