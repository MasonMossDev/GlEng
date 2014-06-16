#include "Cones.h"

class Cylinder : public ObjectFactory
{
public:
	void DrawCylinder();
	void Draw();
	friend class ObjectFactory;

private:
};