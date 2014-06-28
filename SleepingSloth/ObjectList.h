#include "ObjectFactory.h"
#include <vector>



class ObjectList
{
public:
	static ObjectList* GetInstance();
	void AddObject( ObjectFactory* objFac );
	vector<ObjectFactory*>* ReturnFactoryList() const;
	ObjectFactory* GetObjectFactoryItem( int i ) const;
	void RemoveTopOfList();
	void SwapAndClear();
	int Size();

private:
	ObjectList();
	static ObjectList* onlyInstance;
	vector<ObjectFactory*>* objectList;
};