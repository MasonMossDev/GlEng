#include <sstream>
#include "XmlSerializer.h"
#include "ObjectList.h"
XmlSerializer::XmlSerializer(XmlMode mode)
{
	switch ( mode )
	{
	case ModeRead:
		Doc.LoadFile( "test.xml" );
		Declaration = Doc.FirstChild();
		Root = Declaration->NextSibling();
		break;
	case ModeWrite:
		Declaration = Doc.NewDeclaration();
		Doc.InsertEndChild( Declaration );
		Root = Doc.NewElement( "ObjectFactoryList" );
		Doc.InsertEndChild(Root);
		break;
	}
			
}

void XmlSerializer::LoadFromXml(ObjectList& list)
{
	XMLNode* objParentNode = nullptr;
	
	for (objParentNode = Root->FirstChild(); objParentNode; objParentNode = objParentNode->NextSibling())
	{
		XMLNode* typeNode = objParentNode->FirstChild();
		XMLElement* typeElement = typeNode->ToElement();
		const char * typeVal = typeElement->GetText();

		XMLNode* xCoordNode = typeNode->NextSibling()->FirstChild();
		XMLElement* xCoordElement = xCoordNode->ToElement();
		double xCoordVal = atof(xCoordElement->GetText());

		XMLNode* yCoordNode = xCoordNode->NextSibling();
		XMLElement* yCoordElement = yCoordNode->ToElement();
		double yCoordVal = atof(yCoordElement->GetText());

		XMLNode* zCoordNode = yCoordNode->NextSibling();
		XMLElement* zCoordElement = zCoordNode->ToElement();
		double zCoordVal = atof(zCoordElement->GetText());

		XMLNode* xScaleNode = typeNode->NextSibling()->NextSibling()->FirstChild();
		XMLElement* xScaleElement = xScaleNode->ToElement();
		double xScaleVal = atof(xScaleElement->GetText());

		XMLNode* yScaleNode = xScaleNode->NextSibling();
		XMLElement* yScaleElement = yScaleNode->ToElement();
		double yScaleVal = atof(yScaleElement->GetText());

		XMLNode* zScaleNode = yScaleNode->NextSibling();
		XMLElement* zScaleElement = zScaleNode->ToElement();
		double zScaleVal = atof(zScaleElement->GetText());

		XMLNode* rColNode = typeNode->NextSibling()->NextSibling()->NextSibling()->FirstChild();
		XMLElement* rColElement = rColNode->ToElement();
		double rColVal = atof(rColElement->GetText());

		XMLNode* gColNode = rColNode->NextSibling();;
		XMLElement* gColElement = gColNode->ToElement();
		double gColVal = atof(gColElement->GetText());

		XMLNode* bColNode = gColNode->NextSibling();;
		XMLElement* bColElement = bColNode->ToElement();
		double bColVal = atof(bColElement->GetText());

		ObjectFactory *newObj = ObjectFactory::create(typeVal);
		newObj->SetValues(xCoordVal, yCoordVal, zCoordVal, xScaleVal, yScaleVal, zScaleVal, rColVal, gColVal, bColVal);

		list = *ObjectList::GetInstance();
		list.AddObject(newObj);
	}
}

void XmlSerializer::WriteToXml(ObjectList* ObjStorageList)
{
	for (int i = 0; i < ObjStorageList->Size(); i++)
	{

		XMLNode *objParentNode = Doc.NewElement("Object");
		XMLNode *objType = Doc.NewElement("Type");
		XMLNode *objCoordinates = Doc.NewElement("Coordinates");
		XMLNode *objScale = Doc.NewElement("Scale");
		XMLNode *objColour = Doc.NewElement("Colour");

		XMLNode *objXcoord = Doc.NewElement("XCoord");
		XMLNode *objYcoord = Doc.NewElement("YCoord");
		XMLNode *objZcoord = Doc.NewElement("ZCoord");

		XMLNode *objXscale = Doc.NewElement("XScale");
		XMLNode *objYscale = Doc.NewElement("YScale");
		XMLNode *objZscale = Doc.NewElement("ZScale");

		XMLNode *objRcol = Doc.NewElement("RCol");
		XMLNode *objGcol = Doc.NewElement("GCol");
		XMLNode *objBcol = Doc.NewElement("BCol");

		stringstream xCoordStr, yCoordStr, zCoordStr, xScaleStr, yScaleStr, zScaleStr, rColStr, gColStr, bColStr;

		xCoordStr.str("");
		xCoordStr << ObjStorageList->GetObjectFactoryItem(i)->getXpos();

		yCoordStr.str("");
		yCoordStr << ObjStorageList->GetObjectFactoryItem(i)->getYpos();

		zCoordStr.str("");
		zCoordStr << ObjStorageList->GetObjectFactoryItem(i)->getZpos();

		xScaleStr.str("");
		xScaleStr << ObjStorageList->GetObjectFactoryItem(i)->getXscale();

		yScaleStr.str("");
		yScaleStr << ObjStorageList->GetObjectFactoryItem(i)->getYscale();

		zScaleStr.str("");
		zScaleStr << ObjStorageList->GetObjectFactoryItem(i)->getZscale();

		rColStr.str("");
		rColStr << ObjStorageList->GetObjectFactoryItem(i)->getRcol();

		gColStr.str("");
		gColStr << ObjStorageList->GetObjectFactoryItem(i)->getGcol();

		bColStr.str("");
		bColStr << ObjStorageList->GetObjectFactoryItem(i)->getBcol();

		XMLText *objTypeValue = Doc.NewText(ObjStorageList->GetObjectFactoryItem(i)->GetObjTypeName(i).c_str());
		XMLText *objXcoordValue = Doc.NewText(xCoordStr.str().c_str());
		XMLText *objYcoordValue = Doc.NewText(yCoordStr.str().c_str());
		XMLText *objZcoordValue = Doc.NewText(zCoordStr.str().c_str());
		XMLText *objXscaleValue = Doc.NewText(xScaleStr.str().c_str());
		XMLText *objYscaleValue = Doc.NewText(yScaleStr.str().c_str());
		XMLText *objZscaleValue = Doc.NewText(zScaleStr.str().c_str());
		XMLText *objRcolValue = Doc.NewText(rColStr.str().c_str());
		XMLText *objGcolValue = Doc.NewText(gColStr.str().c_str());
		XMLText *objBcolValue = Doc.NewText(bColStr.str().c_str());


		Root->InsertEndChild(objParentNode);
		objParentNode->InsertEndChild(objType);
		objType->InsertEndChild(objTypeValue);
		objParentNode->InsertEndChild(objCoordinates);
		objParentNode->InsertEndChild(objScale);
		objParentNode->InsertEndChild(objColour);

		objCoordinates->InsertEndChild(objXcoord);
		objXcoord->InsertEndChild(objXcoordValue);

		objCoordinates->InsertEndChild(objYcoord);
		objYcoord->InsertEndChild(objYcoordValue);

		objCoordinates->InsertEndChild(objZcoord);
		objZcoord->InsertEndChild(objZcoordValue);

		objScale->InsertEndChild(objXscale);
		objXscale->InsertEndChild(objXscaleValue);

		objScale->InsertEndChild(objYscale);
		objYscale->InsertEndChild(objYscaleValue);

		objScale->InsertEndChild(objZscale);
		objZscale->InsertEndChild(objZscaleValue);

		objColour->InsertEndChild(objRcol);
		objRcol->InsertEndChild(objRcolValue);

		objColour->InsertEndChild(objGcol);
		objGcol->InsertEndChild(objGcolValue);

		objColour->InsertEndChild(objBcol);
		objBcol->InsertEndChild(objBcolValue);
	}

	Doc.SaveFile("test.xml");
}