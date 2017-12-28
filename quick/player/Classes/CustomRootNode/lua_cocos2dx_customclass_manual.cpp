#include "lua_cocos2dx_customclass_auto.hpp"
#include "CustomRootNodeReader.h"
#include "tolua_fix.h"
#include "LuaBasicConversions.h"
#include "CCLuaStack.h"
#include "CCLuaEngine.h"

static int handleUIEvent(int handler, cocos2d::Ref* sender, int eventType)
{
	LuaStack* stack = LuaEngine::getInstance()->getLuaStack();

	stack->pushObject(sender, "cc.Ref");
	stack->pushInt(eventType);

	stack->executeFunctionByHandler(handler, 2);
	stack->clean();

	return 0;
}
static bool handleCustomLocator(int handler, const std::string &arg, LUA_FUNCTION &ref_func_handler)
{
	LuaStack* stack = LuaEngine::getInstance()->getLuaStack();
	lua_State *tolua_S = stack->getLuaState();

	stack->pushString(arg.c_str());

	int ret = stack->executeFunction(handler,1,1,[&](lua_State *L,int num)
	{
		int top = lua_gettop(tolua_S);
		if (lua_isfunction(tolua_S,top))
		{
			ref_func_handler = toluafix_ref_function(tolua_S,top,0);
		}
		lua_pop(tolua_S,1);
	});
	if (ref_func_handler > 0)
	{
		return true;
	}
	return false;
}

int lua_CustomNode_CustomRootNodeReader_setClickLocator(lua_State* tolua_S)
{
    int argc = 0;
    CustomRootNodeReader* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"CustomRootNodeReader",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (CustomRootNodeReader*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_CustomNode_CustomRootNodeReader_setClickLocator'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
	if (argc == 1) 
	{
		LUA_FUNCTION handler = toluafix_ref_function(tolua_S,2,0);

		CustomRootNode::ClickCallbackLocator locator = nullptr;
		locator = [=](const std::string &callback_name)
		{
			LUA_FUNCTION event_handler = 0;
			cocos2d::ui::Widget::ccWidgetClickCallback cb = nullptr;

			if (handleCustomLocator(handler,callback_name,event_handler))
				cb = ([=](cocos2d::Ref* ref){
					handleUIEvent(event_handler, ref, (int)0);
			});

			return cb;
		};

        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_CustomNode_CustomRootNodeReader_setClickLocator'", nullptr);
            return 0;
		}
		cobj->setClickLocator(locator);
        return 0;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "CustomRootNodeReader:setClickLocator",argc, 1);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_CustomNode_CustomRootNodeReader_setClickLocator'.",&tolua_err);
#endif

    return 0;
}
int lua_CustomNode_CustomRootNodeReader_setTouchLocator(lua_State* tolua_S)
{
    int argc = 0;
    CustomRootNodeReader* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"CustomRootNodeReader",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (CustomRootNodeReader*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_CustomNode_CustomRootNodeReader_setTouchLocator'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 1) 
    {
		LUA_FUNCTION handler = toluafix_ref_function(tolua_S,2,0);

		CustomRootNode::TouchCallbackLocator locator = nullptr;
		locator = [=](const std::string &callback_name)
		{
			LUA_FUNCTION event_handler = 0;
			cocos2d::ui::Widget::ccWidgetTouchCallback cb = nullptr;

			if (handleCustomLocator(handler,callback_name,event_handler))
				cb = ([=](cocos2d::Ref* ref,cocos2d::ui::Widget::TouchEventType e){
					handleUIEvent(event_handler, ref, (int)e);
			});

			return cb;
		};

		if(!ok)
		{
			tolua_error(tolua_S,"invalid arguments in function 'lua_CustomNode_CustomRootNodeReader_setTouchLocator'", nullptr);
			return 0;
		}
		cobj->setTouchLocator(locator);
        return 0;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "CustomRootNodeReader:setTouchLocator",argc, 1);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_CustomNode_CustomRootNodeReader_setTouchLocator'.",&tolua_err);
#endif

    return 0;
}
int lua_CustomNode_CustomRootNodeReader_setEventLocator(lua_State* tolua_S)
{
    int argc = 0;
    CustomRootNodeReader* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"CustomRootNodeReader",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (CustomRootNodeReader*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_CustomNode_CustomRootNodeReader_setEventLocator'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 1) 
    {
		LUA_FUNCTION handler = toluafix_ref_function(tolua_S,2,0);

		CustomRootNode::EventCallbackLocator locator = nullptr;
		locator = [=](const std::string &callback_name)
		{
			LUA_FUNCTION event_handler = 0;
			cocos2d::ui::Widget::ccWidgetEventCallback cb = nullptr;

			if (handleCustomLocator(handler,callback_name,event_handler))
				cb = ([=](cocos2d::Ref* ref,int e){
					handleUIEvent(event_handler, ref, (int)e);
			});

			return cb;
		};

		if(!ok)
		{
			tolua_error(tolua_S,"invalid arguments in function 'lua_CustomNode_CustomRootNodeReader_setEventLocator'", nullptr);
			return 0;
		}
		cobj->setEventLocator(locator);
        return 0;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "CustomRootNodeReader:setEventLocator",argc, 1);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_CustomNode_CustomRootNodeReader_setEventLocator'.",&tolua_err);
#endif

    return 0;
}

int lua_register_CustomNode_CustomRootNodeReader_manual(lua_State* tolua_S)
{
	lua_pushstring(tolua_S, "CustomRootNodeReader");
	lua_rawget(tolua_S, LUA_REGISTRYINDEX);
	if (lua_istable(tolua_S,-1))
	{
		tolua_function(tolua_S, "setClickLocator", lua_CustomNode_CustomRootNodeReader_setClickLocator);
		tolua_function(tolua_S, "setTouchLocator", lua_CustomNode_CustomRootNodeReader_setTouchLocator);
		tolua_function(tolua_S, "setEventLocator", lua_CustomNode_CustomRootNodeReader_setEventLocator);
	}
	lua_pop(tolua_S, 1);

	return 0;
}
TOLUA_API int register_all_CustomNode_manual(lua_State* tolua_S)
{
	tolua_open(tolua_S);
	
	tolua_module(tolua_S,"CustomNode",0);
	tolua_beginmodule(tolua_S,"CustomNode");

	lua_register_CustomNode_CustomRootNodeReader_manual(tolua_S);

	tolua_endmodule(tolua_S);
	return 1;
}

