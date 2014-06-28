#include "ObjectList.h"

ObjectList* ObjectList::onlyInstance = nullptr;

ObjectList* ObjectList::GetInstance()
{
	if (onlyInstance == nullptr)
		onlyInstance = new ObjectList();
	return onlyInstance;
}

int ObjectList::Size()
{
	return objectList->size();
}

ObjectList::ObjectList()
{
	objectList = new vector<ObjectFactory*>;
}

void AddObject(ObjectFactory* objFac);
vector<ObjectFactory*>* objectList;
void ObjectList::AddObject(ObjectFactory* objFac)
{
	objectList->insert(objectList->end(), objFac);
}

vector<ObjectFactory*>* ObjectList::ReturnFactoryList() const
{
	return objectList;
}

ObjectFactory* ObjectList::GetObjectFactoryItem(int i) const
{
	return objectList->at(i);
}

void ObjectList::SwapAndClear()
{
	vector<ObjectFactory*>* swapVec = nullptr;
	objectList->clear();
	objectList->swap(*swapVec);
}

void ObjectList::RemoveTopOfList()
{
	objectList->pop_back();
}