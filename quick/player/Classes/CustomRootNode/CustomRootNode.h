#ifndef __TestCpp__CustomRootNode__
#define __TestCpp__CustomRootNode__

#include "cocos2d.h"
#include "cocostudio/WidgetCallBackHandlerProtocol.h"

class CustomRootNode : public cocos2d::Node, public cocostudio::WidgetCallBackHandlerProtocol
{
public:
	typedef std::function<cocos2d::ui::Widget::ccWidgetTouchCallback(const std::string &)> TouchCallbackLocator;
	typedef std::function<cocos2d::ui::Widget::ccWidgetClickCallback(const std::string &)> ClickCallbackLocator;
	typedef std::function<cocos2d::ui::Widget::ccWidgetEventCallback(const std::string &)> EventCallbackLocator;

	static CustomRootNode *create(TouchCallbackLocator &touchLocator,ClickCallbackLocator &clickLocator,EventCallbackLocator &evenetLocator);

	CustomRootNode(TouchCallbackLocator &touchLocator,ClickCallbackLocator &clickLocator,EventCallbackLocator &eventLocator)
		:_touchLocator(touchLocator),_clickLocator(clickLocator),_eventLocator(eventLocator)
	{}

	virtual cocos2d::ui::Widget::ccWidgetTouchCallback onLocateTouchCallback(const std::string &callBackName)
	{
		if (_touchLocator)
			return _touchLocator(callBackName);
		else
			return nullptr;
	}
	virtual cocos2d::ui::Widget::ccWidgetClickCallback onLocateClickCallback(const std::string &callBackName)
	{
		if (_clickLocator)
			return _clickLocator(callBackName);
		else
			return nullptr;
	}

	virtual cocos2d::ui::Widget::ccWidgetEventCallback onLocateEventCallback(const std::string &callBackName)
	{
		if (_eventLocator)
			return _eventLocator(callBackName);
		else
			return nullptr;
	}

	void setTouchLocator(CustomRootNode::TouchCallbackLocator &locator){_touchLocator = locator;}
	void setClickLocator(CustomRootNode::ClickCallbackLocator &locator){_clickLocator = locator;}
	void setEventLocator(CustomRootNode::EventCallbackLocator &locator){_eventLocator = locator;}
private:

	TouchCallbackLocator&_touchLocator;
	ClickCallbackLocator&_clickLocator;
	EventCallbackLocator&_eventLocator;
};

#endif /* defined(__TestCpp__CustomRootNode__) */