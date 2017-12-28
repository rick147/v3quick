#include "lua_cocos2dx_customclass_auto.hpp"
#include "CustomRootNodeReader.h"
#include "tolua_fix.h"
#include "LuaBasicConversions.h"


int lua_CustomNode_CustomRootNodeReader_createNode(lua_State* tolua_S)
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
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_CustomNode_CustomRootNodeReader_createNode'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 2) 
    {
        std::string arg0;
        std::string arg1;

        ok &= luaval_to_std_string(tolua_S, 2,&arg0, "CustomRootNodeReader:createNode");

        ok &= luaval_to_std_string(tolua_S, 3,&arg1, "CustomRootNodeReader:createNode");
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_CustomNode_CustomRootNodeReader_createNode'", nullptr);
            return 0;
        }
        cocos2d::Node* ret = cobj->createNode(arg0, arg1);
        object_to_luaval<cocos2d::Node>(tolua_S, "cc.Node",(cocos2d::Node*)ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "CustomRootNodeReader:createNode",argc, 2);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_CustomNode_CustomRootNodeReader_createNode'.",&tolua_err);
#endif

    return 0;
}
int lua_CustomNode_CustomRootNodeReader_create(lua_State* tolua_S)
{
    int argc = 0;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif

#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertable(tolua_S,1,"CustomRootNodeReader",0,&tolua_err)) goto tolua_lerror;
#endif

    argc = lua_gettop(tolua_S) - 1;

    if (argc == 0)
    {
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_CustomNode_CustomRootNodeReader_create'", nullptr);
            return 0;
        }
        CustomRootNodeReader* ret = CustomRootNodeReader::create();
        object_to_luaval<CustomRootNodeReader>(tolua_S, "CustomRootNodeReader",(CustomRootNodeReader*)ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d\n ", "CustomRootNodeReader:create",argc, 0);
    return 0;
#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_CustomNode_CustomRootNodeReader_create'.",&tolua_err);
#endif
    return 0;
}
int lua_CustomNode_CustomRootNodeReader_constructor(lua_State* tolua_S)
{
    int argc = 0;
    CustomRootNodeReader* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif



    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_CustomNode_CustomRootNodeReader_constructor'", nullptr);
            return 0;
        }
        cobj = new CustomRootNodeReader();
        cobj->autorelease();
        int ID =  (int)cobj->_ID ;
        int* luaID =  &cobj->_luaID ;
        toluafix_pushusertype_ccobject(tolua_S, ID, luaID, (void*)cobj,"CustomRootNodeReader");
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "CustomRootNodeReader:CustomRootNodeReader",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_error(tolua_S,"#ferror in function 'lua_CustomNode_CustomRootNodeReader_constructor'.",&tolua_err);
#endif

    return 0;
}

static int lua_CustomNode_CustomRootNodeReader_finalize(lua_State* tolua_S)
{
    printf("luabindings: finalizing LUA object (CustomRootNodeReader)");
    return 0;
}

int lua_register_CustomNode_CustomRootNodeReader(lua_State* tolua_S)
{
    tolua_usertype(tolua_S,"CustomRootNodeReader");
    tolua_cclass(tolua_S,"CustomRootNodeReader","CustomRootNodeReader","ccs.NodeReader",nullptr);

    tolua_beginmodule(tolua_S,"CustomRootNodeReader");
        tolua_function(tolua_S,"new",lua_CustomNode_CustomRootNodeReader_constructor);
        tolua_function(tolua_S,"createNode",lua_CustomNode_CustomRootNodeReader_createNode);
        tolua_function(tolua_S,"create", lua_CustomNode_CustomRootNodeReader_create);
    tolua_endmodule(tolua_S);
    std::string typeName = typeid(CustomRootNodeReader).name();
    g_luaType[typeName] = "CustomRootNodeReader";
    g_typeCast["CustomRootNodeReader"] = "CustomRootNodeReader";
    return 1;
}
TOLUA_API int register_all_CustomNode(lua_State* tolua_S)
{
	tolua_open(tolua_S);
	
	tolua_module(tolua_S,"CustomNode",0);
	tolua_beginmodule(tolua_S,"CustomNode");

	lua_register_CustomNode_CustomRootNodeReader(tolua_S);

	tolua_endmodule(tolua_S);
	return 1;
}

