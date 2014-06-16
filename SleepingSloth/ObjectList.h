#include "Sphere.h"
#include <stdlib.h>
#include <vector>
using namespace std;

class ObjectList
{
public:
	static ObjectList* GetInstance();
	void AddObject( ObjectFactory* objFac );
	vector<ObjectFactory*>* ReturnFactoryList() const;
	ObjectFactory* GetObjectFactoryItem( int i ) const;
	void SwapAndClear();
	int Size();

private:
	ObjectList();
	static ObjectList* onlyInstance;
	vector<ObjectFactory*>* objectList;
};