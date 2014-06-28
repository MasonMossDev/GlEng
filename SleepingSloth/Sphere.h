#include "ObjectFactory.h"

class Sphere : public ObjectFactory
{
public:
	void DrawSphere();
	void Draw();
	friend class ObjectFactory;

private:
	void DrawCollisionBox();
};