#include "Cylinder.h"

class Sphere : public ObjectFactory
{
public:
	void DrawSphere();
	void Draw();
	friend class ObjectFactory;

private:
};