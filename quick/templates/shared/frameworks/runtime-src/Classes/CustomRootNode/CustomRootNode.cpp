#include "CustomRootNode.h"

#include "ui/UIText.h"

USING_NS_CC;
using namespace std;
using namespace cocos2d::ui;


CustomRootNode * CustomRootNode::create(TouchCallbackLocator &touchLocator,ClickCallbackLocator &clickLocator,EventCallbackLocator &eventLocator)
{
	auto res = new CustomRootNode(touchLocator,clickLocator,eventLocator);
	if(res != nullptr && res->init())
	{
		res->autorelease();
		return res;
	}
	CC_SAFE_DELETE(res);
	return nullptr;
}
