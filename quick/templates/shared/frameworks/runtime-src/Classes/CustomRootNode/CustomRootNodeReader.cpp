#include "CustomRootNodeReader.h"
#include "CustomRootNode.h"
#include "2d\CCNode.h"
#include "cocostudio\ActionTimeline\CSLoader.h"

cocos2d::Node* CustomRootNodeReader::createNodeWithFlatBuffers(const flatbuffers::Table* nodeOptions)
{
	CustomRootNode* node = CustomRootNode::create(_touchLocator,_clickLocator,_eventLocator);

	setPropsWithFlatBuffers(node, nodeOptions);

	return node;
}

cocos2d::Node * CustomRootNodeReader::createNode(const std::string &customClassName,const std::string &filename)
{
	auto factory = cocos2d::ObjectFactory::getInstance();
	cocos2d::ObjectFactory::TInfo t;
	t._func = [this]()->cocos2d::Ref*{return this;};
	t._class = customClassName+"Reader";

	factory->registerType(t);

	return cocos2d::CSLoader::createNode(filename);
}

CustomRootNodeReader* CustomRootNodeReader::create()
{
	auto instance = new CustomRootNodeReader();
	instance->autorelease();
	return instance;
}
