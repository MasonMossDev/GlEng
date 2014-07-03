#include "tinyxml2.h"

class ObjectList;

using namespace tinyxml2;

class XmlSerializer
{
public:

	enum XmlMode
	{
		ModeWrite,
		ModeRead
	};

	XmlSerializer(XmlMode mode);
	void WriteToXml(ObjectList* objItem);
	void LoadFromXml(ObjectList& list);

private:

	XMLDocument Doc;
	XMLNode* Root;
	XMLNode* Declaration;
};