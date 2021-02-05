#include "scripting/lua-bindings/auto/lua_cocos2dx_fgui_auto.hpp"
#include "FGui.h"
#include "scripting/lua-bindings/manual/LuaCustomConversions.h"
#include "scripting/lua-bindings/manual/tolua_fix.h"
#include "scripting/lua-bindings/manual/LuaBasicConversions.h"

int lua_cocos2dx_fgui_PackageManager_parseURL(lua_State* tolua_S)
{
    int argc = 0;
    fgui::PackageManager* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"fgui::PackageManager",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (fgui::PackageManager*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_fgui_PackageManager_parseURL'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 4) 
    {
        std::string arg0;
        std::string arg1;
        std::string arg2;
        bool arg3;

        ok &= luaval_to_std_string(tolua_S, 2,&arg0, "fgui::PackageManager:parseURL");

        ok &= luaval_to_std_string(tolua_S, 3,&arg1, "fgui::PackageManager:parseURL");

        ok &= luaval_to_std_string(tolua_S, 4,&arg2, "fgui::PackageManager:parseURL");

        ok &= luaval_to_boolean(tolua_S, 5,&arg3, "fgui::PackageManager:parseURL");
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_cocos2dx_fgui_PackageManager_parseURL'", nullptr);
            return 0;
        }
        bool ret = cobj->parseURL(arg0, arg1, arg2, arg3);
        tolua_pushboolean(tolua_S,(bool)ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "fgui::PackageManager:parseURL",argc, 4);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_fgui_PackageManager_parseURL'.",&tolua_err);
#endif

    return 0;
}
int lua_cocos2dx_fgui_PackageManager_createPkg(lua_State* tolua_S)
{
    int argc = 0;
    fgui::PackageManager* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"fgui::PackageManager",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (fgui::PackageManager*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_fgui_PackageManager_createPkg'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 2) 
    {
        std::string arg0;
        std::string arg1;

        ok &= luaval_to_std_string(tolua_S, 2,&arg0, "fgui::PackageManager:createPkg");

        ok &= luaval_to_std_string(tolua_S, 3,&arg1, "fgui::PackageManager:createPkg");
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_cocos2dx_fgui_PackageManager_createPkg'", nullptr);
            return 0;
        }
        fgui::Package* ret = cobj->createPkg(arg0, arg1);
        object_to_luaval<fgui::Package>(tolua_S, "fgui::Package",(fgui::Package*)ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "fgui::PackageManager:createPkg",argc, 2);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_fgui_PackageManager_createPkg'.",&tolua_err);
#endif

    return 0;
}
int lua_cocos2dx_fgui_PackageManager_getPkgByName(lua_State* tolua_S)
{
    int argc = 0;
    fgui::PackageManager* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"fgui::PackageManager",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (fgui::PackageManager*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_fgui_PackageManager_getPkgByName'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 1) 
    {
        std::string arg0;

        ok &= luaval_to_std_string(tolua_S, 2,&arg0, "fgui::PackageManager:getPkgByName");
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_cocos2dx_fgui_PackageManager_getPkgByName'", nullptr);
            return 0;
        }
        fgui::Package* ret = cobj->getPkgByName(arg0);
        object_to_luaval<fgui::Package>(tolua_S, "fgui::Package",(fgui::Package*)ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "fgui::PackageManager:getPkgByName",argc, 1);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_fgui_PackageManager_getPkgByName'.",&tolua_err);
#endif

    return 0;
}
int lua_cocos2dx_fgui_PackageManager_init(lua_State* tolua_S)
{
    int argc = 0;
    fgui::PackageManager* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"fgui::PackageManager",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (fgui::PackageManager*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_fgui_PackageManager_init'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_cocos2dx_fgui_PackageManager_init'", nullptr);
            return 0;
        }
        cobj->init();
        lua_settop(tolua_S, 1);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "fgui::PackageManager:init",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_fgui_PackageManager_init'.",&tolua_err);
#endif

    return 0;
}
int lua_cocos2dx_fgui_PackageManager_createNodeById(lua_State* tolua_S)
{
    int argc = 0;
    fgui::PackageManager* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"fgui::PackageManager",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (fgui::PackageManager*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_fgui_PackageManager_createNodeById'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 2) 
    {
        std::string arg0;
        std::string arg1;

        ok &= luaval_to_std_string(tolua_S, 2,&arg0, "fgui::PackageManager:createNodeById");

        ok &= luaval_to_std_string(tolua_S, 3,&arg1, "fgui::PackageManager:createNodeById");
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_cocos2dx_fgui_PackageManager_createNodeById'", nullptr);
            return 0;
        }
        cocos2d::Node* ret = cobj->createNodeById(arg0, arg1);
        object_to_luaval<cocos2d::Node>(tolua_S, "cc.Node",(cocos2d::Node*)ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "fgui::PackageManager:createNodeById",argc, 2);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_fgui_PackageManager_createNodeById'.",&tolua_err);
#endif

    return 0;
}
int lua_cocos2dx_fgui_PackageManager_getItemByUrl(lua_State* tolua_S)
{
    int argc = 0;
    fgui::PackageManager* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"fgui::PackageManager",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (fgui::PackageManager*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_fgui_PackageManager_getItemByUrl'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 1) 
    {
        std::string arg0;

        ok &= luaval_to_std_string(tolua_S, 2,&arg0, "fgui::PackageManager:getItemByUrl");
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_cocos2dx_fgui_PackageManager_getItemByUrl'", nullptr);
            return 0;
        }
        fgui::PkgItem* ret = cobj->getItemByUrl(arg0);
        object_to_luaval<fgui::PkgItem>(tolua_S, "fgui::PkgItem",(fgui::PkgItem*)ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "fgui::PackageManager:getItemByUrl",argc, 1);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_fgui_PackageManager_getItemByUrl'.",&tolua_err);
#endif

    return 0;
}
int lua_cocos2dx_fgui_PackageManager_createNodeByName(lua_State* tolua_S)
{
    int argc = 0;
    fgui::PackageManager* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"fgui::PackageManager",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (fgui::PackageManager*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_fgui_PackageManager_createNodeByName'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 2) 
    {
        std::string arg0;
        std::string arg1;

        ok &= luaval_to_std_string(tolua_S, 2,&arg0, "fgui::PackageManager:createNodeByName");

        ok &= luaval_to_std_string(tolua_S, 3,&arg1, "fgui::PackageManager:createNodeByName");
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_cocos2dx_fgui_PackageManager_createNodeByName'", nullptr);
            return 0;
        }
        cocos2d::Node* ret = cobj->createNodeByName(arg0, arg1);
        object_to_luaval<cocos2d::Node>(tolua_S, "cc.Node",(cocos2d::Node*)ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "fgui::PackageManager:createNodeByName",argc, 2);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_fgui_PackageManager_createNodeByName'.",&tolua_err);
#endif

    return 0;
}
int lua_cocos2dx_fgui_PackageManager_getPkg(lua_State* tolua_S)
{
    int argc = 0;
    fgui::PackageManager* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"fgui::PackageManager",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (fgui::PackageManager*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_fgui_PackageManager_getPkg'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 1) 
    {
        std::string arg0;

        ok &= luaval_to_std_string(tolua_S, 2,&arg0, "fgui::PackageManager:getPkg");
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_cocos2dx_fgui_PackageManager_getPkg'", nullptr);
            return 0;
        }
        fgui::Package* ret = cobj->getPkg(arg0);
        object_to_luaval<fgui::Package>(tolua_S, "fgui::Package",(fgui::Package*)ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "fgui::PackageManager:getPkg",argc, 1);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_fgui_PackageManager_getPkg'.",&tolua_err);
#endif

    return 0;
}
int lua_cocos2dx_fgui_PackageManager_createNodeByUrl(lua_State* tolua_S)
{
    int argc = 0;
    fgui::PackageManager* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"fgui::PackageManager",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (fgui::PackageManager*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_fgui_PackageManager_createNodeByUrl'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 1) 
    {
        std::string arg0;

        ok &= luaval_to_std_string(tolua_S, 2,&arg0, "fgui::PackageManager:createNodeByUrl");
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_cocos2dx_fgui_PackageManager_createNodeByUrl'", nullptr);
            return 0;
        }
        cocos2d::Node* ret = cobj->createNodeByUrl(arg0);
        object_to_luaval<cocos2d::Node>(tolua_S, "cc.Node",(cocos2d::Node*)ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "fgui::PackageManager:createNodeByUrl",argc, 1);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_fgui_PackageManager_createNodeByUrl'.",&tolua_err);
#endif

    return 0;
}
int lua_cocos2dx_fgui_PackageManager_getInstance(lua_State* tolua_S)
{
    int argc = 0;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif

#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertable(tolua_S,1,"fgui::PackageManager",0,&tolua_err)) goto tolua_lerror;
#endif

    argc = lua_gettop(tolua_S) - 1;

    if (argc == 0)
    {
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_cocos2dx_fgui_PackageManager_getInstance'", nullptr);
            return 0;
        }
        fgui::PackageManager* ret = fgui::PackageManager::getInstance();
        object_to_luaval<fgui::PackageManager>(tolua_S, "fgui::PackageManager",(fgui::PackageManager*)ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d\n ", "fgui::PackageManager:getInstance",argc, 0);
    return 0;
#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_fgui_PackageManager_getInstance'.",&tolua_err);
#endif
    return 0;
}
static int lua_cocos2dx_fgui_PackageManager_finalize(lua_State* tolua_S)
{
    printf("luabindings: finalizing LUA object (PackageManager)");
    return 0;
}

int lua_register_cocos2dx_fgui_PackageManager(lua_State* tolua_S)
{
    tolua_usertype(tolua_S,"fgui::PackageManager");
    tolua_cclass(tolua_S,"PackageManager","fgui::PackageManager","cc.Ref",nullptr);

    tolua_beginmodule(tolua_S,"PackageManager");
        tolua_function(tolua_S,"parseURL",lua_cocos2dx_fgui_PackageManager_parseURL);
        tolua_function(tolua_S,"createPkg",lua_cocos2dx_fgui_PackageManager_createPkg);
        tolua_function(tolua_S,"getPkgByName",lua_cocos2dx_fgui_PackageManager_getPkgByName);
        tolua_function(tolua_S,"init",lua_cocos2dx_fgui_PackageManager_init);
        tolua_function(tolua_S,"createNodeById",lua_cocos2dx_fgui_PackageManager_createNodeById);
        tolua_function(tolua_S,"getItemByUrl",lua_cocos2dx_fgui_PackageManager_getItemByUrl);
        tolua_function(tolua_S,"createNodeByName",lua_cocos2dx_fgui_PackageManager_createNodeByName);
        tolua_function(tolua_S,"getPkg",lua_cocos2dx_fgui_PackageManager_getPkg);
        tolua_function(tolua_S,"createNodeByUrl",lua_cocos2dx_fgui_PackageManager_createNodeByUrl);
        tolua_function(tolua_S,"getInstance", lua_cocos2dx_fgui_PackageManager_getInstance);
    tolua_endmodule(tolua_S);
    std::string typeName = typeid(fgui::PackageManager).name();
    g_luaType[typeName] = "fgui::PackageManager";
    g_typeCast["PackageManager"] = "fgui::PackageManager";
    return 1;
}

int lua_cocos2dx_fgui_Package_load(lua_State* tolua_S)
{
    int argc = 0;
    fgui::Package* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"fgui::Package",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (fgui::Package*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_fgui_Package_load'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 1) 
    {
        std::string arg0;

        ok &= luaval_to_std_string(tolua_S, 2,&arg0, "fgui::Package:load");
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_cocos2dx_fgui_Package_load'", nullptr);
            return 0;
        }
        bool ret = cobj->load(arg0);
        tolua_pushboolean(tolua_S,(bool)ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "fgui::Package:load",argc, 1);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_fgui_Package_load'.",&tolua_err);
#endif

    return 0;
}
int lua_cocos2dx_fgui_Package_getPkgItemById(lua_State* tolua_S)
{
    int argc = 0;
    fgui::Package* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"fgui::Package",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (fgui::Package*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_fgui_Package_getPkgItemById'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 1) 
    {
        std::string arg0;

        ok &= luaval_to_std_string(tolua_S, 2,&arg0, "fgui::Package:getPkgItemById");
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_cocos2dx_fgui_Package_getPkgItemById'", nullptr);
            return 0;
        }
        fgui::PkgItem* ret = cobj->getPkgItemById(arg0);
        object_to_luaval<fgui::PkgItem>(tolua_S, "fgui::PkgItem",(fgui::PkgItem*)ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "fgui::Package:getPkgItemById",argc, 1);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_fgui_Package_getPkgItemById'.",&tolua_err);
#endif

    return 0;
}
int lua_cocos2dx_fgui_Package_getName(lua_State* tolua_S)
{
    int argc = 0;
    fgui::Package* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"fgui::Package",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (fgui::Package*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_fgui_Package_getName'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_cocos2dx_fgui_Package_getName'", nullptr);
            return 0;
        }
        const std::string& ret = cobj->getName();
        lua_pushlstring(tolua_S,ret.c_str(),ret.length());
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "fgui::Package:getName",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_fgui_Package_getName'.",&tolua_err);
#endif

    return 0;
}
int lua_cocos2dx_fgui_Package_createNodeByName(lua_State* tolua_S)
{
    int argc = 0;
    fgui::Package* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"fgui::Package",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (fgui::Package*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_fgui_Package_createNodeByName'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 1) 
    {
        std::string arg0;

        ok &= luaval_to_std_string(tolua_S, 2,&arg0, "fgui::Package:createNodeByName");
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_cocos2dx_fgui_Package_createNodeByName'", nullptr);
            return 0;
        }
        cocos2d::Node* ret = cobj->createNodeByName(arg0);
        object_to_luaval<cocos2d::Node>(tolua_S, "cc.Node",(cocos2d::Node*)ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "fgui::Package:createNodeByName",argc, 1);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_fgui_Package_createNodeByName'.",&tolua_err);
#endif

    return 0;
}
int lua_cocos2dx_fgui_Package_getId(lua_State* tolua_S)
{
    int argc = 0;
    fgui::Package* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"fgui::Package",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (fgui::Package*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_fgui_Package_getId'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_cocos2dx_fgui_Package_getId'", nullptr);
            return 0;
        }
        const std::string& ret = cobj->getId();
        lua_pushlstring(tolua_S,ret.c_str(),ret.length());
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "fgui::Package:getId",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_fgui_Package_getId'.",&tolua_err);
#endif

    return 0;
}
int lua_cocos2dx_fgui_Package_getAssetsPath(lua_State* tolua_S)
{
    int argc = 0;
    fgui::Package* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"fgui::Package",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (fgui::Package*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_fgui_Package_getAssetsPath'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_cocos2dx_fgui_Package_getAssetsPath'", nullptr);
            return 0;
        }
        const std::string& ret = cobj->getAssetsPath();
        lua_pushlstring(tolua_S,ret.c_str(),ret.length());
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "fgui::Package:getAssetsPath",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_fgui_Package_getAssetsPath'.",&tolua_err);
#endif

    return 0;
}
int lua_cocos2dx_fgui_Package_createNodeById(lua_State* tolua_S)
{
    int argc = 0;
    fgui::Package* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"fgui::Package",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (fgui::Package*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_fgui_Package_createNodeById'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 1) 
    {
        std::string arg0;

        ok &= luaval_to_std_string(tolua_S, 2,&arg0, "fgui::Package:createNodeById");
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_cocos2dx_fgui_Package_createNodeById'", nullptr);
            return 0;
        }
        cocos2d::Node* ret = cobj->createNodeById(arg0);
        object_to_luaval<cocos2d::Node>(tolua_S, "cc.Node",(cocos2d::Node*)ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "fgui::Package:createNodeById",argc, 1);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_fgui_Package_createNodeById'.",&tolua_err);
#endif

    return 0;
}
int lua_cocos2dx_fgui_Package_addPkgItem(lua_State* tolua_S)
{
    int argc = 0;
    fgui::Package* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"fgui::Package",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (fgui::Package*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_fgui_Package_addPkgItem'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 1) 
    {
        fgui::PkgItem* arg0;

        ok &= luaval_to_object<fgui::PkgItem>(tolua_S, 2, "fgui::PkgItem",&arg0, "fgui::Package:addPkgItem");
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_cocos2dx_fgui_Package_addPkgItem'", nullptr);
            return 0;
        }
        cobj->addPkgItem(arg0);
        lua_settop(tolua_S, 1);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "fgui::Package:addPkgItem",argc, 1);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_fgui_Package_addPkgItem'.",&tolua_err);
#endif

    return 0;
}
int lua_cocos2dx_fgui_Package_release(lua_State* tolua_S)
{
    int argc = 0;
    fgui::Package* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"fgui::Package",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (fgui::Package*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_fgui_Package_release'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_cocos2dx_fgui_Package_release'", nullptr);
            return 0;
        }
        cobj->release();
        lua_settop(tolua_S, 1);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "fgui::Package:release",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_fgui_Package_release'.",&tolua_err);
#endif

    return 0;
}
int lua_cocos2dx_fgui_Package_retain(lua_State* tolua_S)
{
    int argc = 0;
    fgui::Package* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"fgui::Package",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (fgui::Package*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_fgui_Package_retain'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_cocos2dx_fgui_Package_retain'", nullptr);
            return 0;
        }
        cobj->retain();
        lua_settop(tolua_S, 1);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "fgui::Package:retain",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_fgui_Package_retain'.",&tolua_err);
#endif

    return 0;
}
int lua_cocos2dx_fgui_Package_getLastReleaseTime(lua_State* tolua_S)
{
    int argc = 0;
    fgui::Package* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"fgui::Package",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (fgui::Package*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_fgui_Package_getLastReleaseTime'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_cocos2dx_fgui_Package_getLastReleaseTime'", nullptr);
            return 0;
        }
        double ret = cobj->getLastReleaseTime();
        tolua_pushnumber(tolua_S,(lua_Number)ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "fgui::Package:getLastReleaseTime",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_fgui_Package_getLastReleaseTime'.",&tolua_err);
#endif

    return 0;
}
int lua_cocos2dx_fgui_Package_getPkgItemByName(lua_State* tolua_S)
{
    int argc = 0;
    fgui::Package* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"fgui::Package",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (fgui::Package*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_fgui_Package_getPkgItemByName'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 1) 
    {
        std::string arg0;

        ok &= luaval_to_std_string(tolua_S, 2,&arg0, "fgui::Package:getPkgItemByName");
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_cocos2dx_fgui_Package_getPkgItemByName'", nullptr);
            return 0;
        }
        fgui::PkgItem* ret = cobj->getPkgItemByName(arg0);
        object_to_luaval<fgui::PkgItem>(tolua_S, "fgui::PkgItem",(fgui::PkgItem*)ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "fgui::Package:getPkgItemByName",argc, 1);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_fgui_Package_getPkgItemByName'.",&tolua_err);
#endif

    return 0;
}
int lua_cocos2dx_fgui_Package_constructor(lua_State* tolua_S)
{
    int argc = 0;
    fgui::Package* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif



    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_cocos2dx_fgui_Package_constructor'", nullptr);
            return 0;
        }
        cobj = new fgui::Package();
        cobj->autorelease();
        int ID =  (int)cobj->_ID ;
        int* luaID =  &cobj->_luaID ;
        toluafix_pushusertype_ccobject(tolua_S, ID, luaID, (void*)cobj,"fgui::Package");
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "fgui::Package:Package",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_fgui_Package_constructor'.",&tolua_err);
#endif

    return 0;
}

static int lua_cocos2dx_fgui_Package_finalize(lua_State* tolua_S)
{
    printf("luabindings: finalizing LUA object (Package)");
    return 0;
}

int lua_register_cocos2dx_fgui_Package(lua_State* tolua_S)
{
    tolua_usertype(tolua_S,"fgui::Package");
    tolua_cclass(tolua_S,"Package","fgui::Package","cc.Ref",nullptr);

    tolua_beginmodule(tolua_S,"Package");
        tolua_function(tolua_S,"new",lua_cocos2dx_fgui_Package_constructor);
        tolua_function(tolua_S,"load",lua_cocos2dx_fgui_Package_load);
        tolua_function(tolua_S,"getPkgItemById",lua_cocos2dx_fgui_Package_getPkgItemById);
        tolua_function(tolua_S,"getName",lua_cocos2dx_fgui_Package_getName);
        tolua_function(tolua_S,"createNodeByName",lua_cocos2dx_fgui_Package_createNodeByName);
        tolua_function(tolua_S,"getId",lua_cocos2dx_fgui_Package_getId);
        tolua_function(tolua_S,"getAssetsPath",lua_cocos2dx_fgui_Package_getAssetsPath);
        tolua_function(tolua_S,"createNodeById",lua_cocos2dx_fgui_Package_createNodeById);
        tolua_function(tolua_S,"addPkgItem",lua_cocos2dx_fgui_Package_addPkgItem);
        tolua_function(tolua_S,"release",lua_cocos2dx_fgui_Package_release);
        tolua_function(tolua_S,"retain",lua_cocos2dx_fgui_Package_retain);
        tolua_function(tolua_S,"getLastReleaseTime",lua_cocos2dx_fgui_Package_getLastReleaseTime);
        tolua_function(tolua_S,"getPkgItemByName",lua_cocos2dx_fgui_Package_getPkgItemByName);
    tolua_endmodule(tolua_S);
    std::string typeName = typeid(fgui::Package).name();
    g_luaType[typeName] = "fgui::Package";
    g_typeCast["Package"] = "fgui::Package";
    return 1;
}

int lua_cocos2dx_fgui_PkgItem_getFileName(lua_State* tolua_S)
{
    int argc = 0;
    fgui::PkgItem* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"fgui::PkgItem",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (fgui::PkgItem*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_fgui_PkgItem_getFileName'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_cocos2dx_fgui_PkgItem_getFileName'", nullptr);
            return 0;
        }
        const std::string& ret = cobj->getFileName();
        lua_pushlstring(tolua_S,ret.c_str(),ret.length());
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "fgui::PkgItem:getFileName",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_fgui_PkgItem_getFileName'.",&tolua_err);
#endif

    return 0;
}
int lua_cocos2dx_fgui_PkgItem_setName(lua_State* tolua_S)
{
    int argc = 0;
    fgui::PkgItem* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"fgui::PkgItem",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (fgui::PkgItem*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_fgui_PkgItem_setName'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 1) 
    {
        std::string arg0;

        ok &= luaval_to_std_string(tolua_S, 2,&arg0, "fgui::PkgItem:setName");
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_cocos2dx_fgui_PkgItem_setName'", nullptr);
            return 0;
        }
        cobj->setName(arg0);
        lua_settop(tolua_S, 1);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "fgui::PkgItem:setName",argc, 1);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_fgui_PkgItem_setName'.",&tolua_err);
#endif

    return 0;
}
int lua_cocos2dx_fgui_PkgItem_getObjType(lua_State* tolua_S)
{
    int argc = 0;
    fgui::PkgItem* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"fgui::PkgItem",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (fgui::PkgItem*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_fgui_PkgItem_getObjType'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_cocos2dx_fgui_PkgItem_getObjType'", nullptr);
            return 0;
        }
        int ret = (int)cobj->getObjType();
        tolua_pushnumber(tolua_S,(lua_Number)ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "fgui::PkgItem:getObjType",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_fgui_PkgItem_getObjType'.",&tolua_err);
#endif

    return 0;
}
int lua_cocos2dx_fgui_PkgItem_getName(lua_State* tolua_S)
{
    int argc = 0;
    fgui::PkgItem* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"fgui::PkgItem",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (fgui::PkgItem*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_fgui_PkgItem_getName'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_cocos2dx_fgui_PkgItem_getName'", nullptr);
            return 0;
        }
        const std::string& ret = cobj->getName();
        lua_pushlstring(tolua_S,ret.c_str(),ret.length());
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "fgui::PkgItem:getName",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_fgui_PkgItem_getName'.",&tolua_err);
#endif

    return 0;
}
int lua_cocos2dx_fgui_PkgItem_getType(lua_State* tolua_S)
{
    int argc = 0;
    fgui::PkgItem* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"fgui::PkgItem",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (fgui::PkgItem*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_fgui_PkgItem_getType'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_cocos2dx_fgui_PkgItem_getType'", nullptr);
            return 0;
        }
        int ret = (int)cobj->getType();
        tolua_pushnumber(tolua_S,(lua_Number)ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "fgui::PkgItem:getType",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_fgui_PkgItem_getType'.",&tolua_err);
#endif

    return 0;
}
int lua_cocos2dx_fgui_PkgItem_getId(lua_State* tolua_S)
{
    int argc = 0;
    fgui::PkgItem* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"fgui::PkgItem",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (fgui::PkgItem*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_fgui_PkgItem_getId'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_cocos2dx_fgui_PkgItem_getId'", nullptr);
            return 0;
        }
        const std::string& ret = cobj->getId();
        lua_pushlstring(tolua_S,ret.c_str(),ret.length());
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "fgui::PkgItem:getId",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_fgui_PkgItem_getId'.",&tolua_err);
#endif

    return 0;
}
int lua_cocos2dx_fgui_PkgItem_getSize(lua_State* tolua_S)
{
    int argc = 0;
    fgui::PkgItem* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"fgui::PkgItem",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (fgui::PkgItem*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_fgui_PkgItem_getSize'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_cocos2dx_fgui_PkgItem_getSize'", nullptr);
            return 0;
        }
        const cocos2d::Size& ret = cobj->getSize();
        size_to_luaval(tolua_S, ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "fgui::PkgItem:getSize",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_fgui_PkgItem_getSize'.",&tolua_err);
#endif

    return 0;
}
int lua_cocos2dx_fgui_PkgItem_getOwner(lua_State* tolua_S)
{
    int argc = 0;
    fgui::PkgItem* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"fgui::PkgItem",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (fgui::PkgItem*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_fgui_PkgItem_getOwner'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_cocos2dx_fgui_PkgItem_getOwner'", nullptr);
            return 0;
        }
        fgui::Package* ret = cobj->getOwner();
        object_to_luaval<fgui::Package>(tolua_S, "fgui::Package",(fgui::Package*)ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "fgui::PkgItem:getOwner",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_fgui_PkgItem_getOwner'.",&tolua_err);
#endif

    return 0;
}
int lua_cocos2dx_fgui_PkgItem_loadRes(lua_State* tolua_S)
{
    int argc = 0;
    fgui::PkgItem* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"fgui::PkgItem",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (fgui::PkgItem*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_fgui_PkgItem_loadRes'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_cocos2dx_fgui_PkgItem_loadRes'", nullptr);
            return 0;
        }
        cobj->loadRes();
        lua_settop(tolua_S, 1);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "fgui::PkgItem:loadRes",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_fgui_PkgItem_loadRes'.",&tolua_err);
#endif

    return 0;
}
int lua_cocos2dx_fgui_PkgItem_setOwner(lua_State* tolua_S)
{
    int argc = 0;
    fgui::PkgItem* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"fgui::PkgItem",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (fgui::PkgItem*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_fgui_PkgItem_setOwner'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 1) 
    {
        fgui::Package* arg0;

        ok &= luaval_to_object<fgui::Package>(tolua_S, 2, "fgui::Package",&arg0, "fgui::PkgItem:setOwner");
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_cocos2dx_fgui_PkgItem_setOwner'", nullptr);
            return 0;
        }
        cobj->setOwner(arg0);
        lua_settop(tolua_S, 1);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "fgui::PkgItem:setOwner",argc, 1);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_fgui_PkgItem_setOwner'.",&tolua_err);
#endif

    return 0;
}
int lua_cocos2dx_fgui_PkgItem_setId(lua_State* tolua_S)
{
    int argc = 0;
    fgui::PkgItem* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"fgui::PkgItem",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (fgui::PkgItem*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_fgui_PkgItem_setId'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 1) 
    {
        std::string arg0;

        ok &= luaval_to_std_string(tolua_S, 2,&arg0, "fgui::PkgItem:setId");
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_cocos2dx_fgui_PkgItem_setId'", nullptr);
            return 0;
        }
        cobj->setId(arg0);
        lua_settop(tolua_S, 1);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "fgui::PkgItem:setId",argc, 1);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_fgui_PkgItem_setId'.",&tolua_err);
#endif

    return 0;
}
int lua_cocos2dx_fgui_PkgItem_setup(lua_State* tolua_S)
{
    int argc = 0;
    fgui::PkgItem* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"fgui::PkgItem",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (fgui::PkgItem*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_fgui_PkgItem_setup'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 1) 
    {
        fgui::ByteBuffer* arg0;

        ok &= luaval_to_object<fgui::ByteBuffer>(tolua_S, 2, "fgui::ByteBuffer",&arg0, "fgui::PkgItem:setup");
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_cocos2dx_fgui_PkgItem_setup'", nullptr);
            return 0;
        }
        cobj->setup(arg0);
        lua_settop(tolua_S, 1);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "fgui::PkgItem:setup",argc, 1);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_fgui_PkgItem_setup'.",&tolua_err);
#endif

    return 0;
}
int lua_cocos2dx_fgui_PkgItem_setType(lua_State* tolua_S)
{
    int argc = 0;
    fgui::PkgItem* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"fgui::PkgItem",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (fgui::PkgItem*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_fgui_PkgItem_setType'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 1) 
    {
        fgui::PackageItemType arg0;

        ok &= luaval_to_int32(tolua_S, 2,(int *)&arg0, "fgui::PkgItem:setType");
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_cocos2dx_fgui_PkgItem_setType'", nullptr);
            return 0;
        }
        cobj->setType(arg0);
        lua_settop(tolua_S, 1);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "fgui::PkgItem:setType",argc, 1);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_fgui_PkgItem_setType'.",&tolua_err);
#endif

    return 0;
}
int lua_cocos2dx_fgui_PkgItem_constructor(lua_State* tolua_S)
{
    int argc = 0;
    fgui::PkgItem* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif



    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_cocos2dx_fgui_PkgItem_constructor'", nullptr);
            return 0;
        }
        cobj = new fgui::PkgItem();
        cobj->autorelease();
        int ID =  (int)cobj->_ID ;
        int* luaID =  &cobj->_luaID ;
        toluafix_pushusertype_ccobject(tolua_S, ID, luaID, (void*)cobj,"fgui::PkgItem");
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "fgui::PkgItem:PkgItem",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_fgui_PkgItem_constructor'.",&tolua_err);
#endif

    return 0;
}

static int lua_cocos2dx_fgui_PkgItem_finalize(lua_State* tolua_S)
{
    printf("luabindings: finalizing LUA object (PkgItem)");
    return 0;
}

int lua_register_cocos2dx_fgui_PkgItem(lua_State* tolua_S)
{
    tolua_usertype(tolua_S,"fgui::PkgItem");
    tolua_cclass(tolua_S,"PkgItem","fgui::PkgItem","cc.Ref",nullptr);

    tolua_beginmodule(tolua_S,"PkgItem");
        tolua_function(tolua_S,"new",lua_cocos2dx_fgui_PkgItem_constructor);
        tolua_function(tolua_S,"getFileName",lua_cocos2dx_fgui_PkgItem_getFileName);
        tolua_function(tolua_S,"setName",lua_cocos2dx_fgui_PkgItem_setName);
        tolua_function(tolua_S,"getObjType",lua_cocos2dx_fgui_PkgItem_getObjType);
        tolua_function(tolua_S,"getName",lua_cocos2dx_fgui_PkgItem_getName);
        tolua_function(tolua_S,"getType",lua_cocos2dx_fgui_PkgItem_getType);
        tolua_function(tolua_S,"getId",lua_cocos2dx_fgui_PkgItem_getId);
        tolua_function(tolua_S,"getSize",lua_cocos2dx_fgui_PkgItem_getSize);
        tolua_function(tolua_S,"getOwner",lua_cocos2dx_fgui_PkgItem_getOwner);
        tolua_function(tolua_S,"loadRes",lua_cocos2dx_fgui_PkgItem_loadRes);
        tolua_function(tolua_S,"setOwner",lua_cocos2dx_fgui_PkgItem_setOwner);
        tolua_function(tolua_S,"setId",lua_cocos2dx_fgui_PkgItem_setId);
        tolua_function(tolua_S,"setup",lua_cocos2dx_fgui_PkgItem_setup);
        tolua_function(tolua_S,"setType",lua_cocos2dx_fgui_PkgItem_setType);
    tolua_endmodule(tolua_S);
    std::string typeName = typeid(fgui::PkgItem).name();
    g_luaType[typeName] = "fgui::PkgItem";
    g_typeCast["PkgItem"] = "fgui::PkgItem";
    return 1;
}

int lua_cocos2dx_fgui_GController_runActions(lua_State* tolua_S)
{
    int argc = 0;
    fgui::GController* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"fgui::GController",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (fgui::GController*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_fgui_GController_runActions'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_cocos2dx_fgui_GController_runActions'", nullptr);
            return 0;
        }
        cobj->runActions();
        lua_settop(tolua_S, 1);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "fgui::GController:runActions",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_fgui_GController_runActions'.",&tolua_err);
#endif

    return 0;
}
int lua_cocos2dx_fgui_GController_setSelectedPage(lua_State* tolua_S)
{
    int argc = 0;
    fgui::GController* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"fgui::GController",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (fgui::GController*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_fgui_GController_setSelectedPage'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 1) 
    {
        std::string arg0;

        ok &= luaval_to_std_string(tolua_S, 2,&arg0, "fgui::GController:setSelectedPage");
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_cocos2dx_fgui_GController_setSelectedPage'", nullptr);
            return 0;
        }
        cobj->setSelectedPage(arg0);
        lua_settop(tolua_S, 1);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "fgui::GController:setSelectedPage",argc, 1);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_fgui_GController_setSelectedPage'.",&tolua_err);
#endif

    return 0;
}
int lua_cocos2dx_fgui_GController_setup(lua_State* tolua_S)
{
    int argc = 0;
    fgui::GController* cobj = nullptr;
    bool ok  = true;
#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif

#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"fgui::GController",0,&tolua_err)) goto tolua_lerror;
#endif
    cobj = (fgui::GController*)tolua_tousertype(tolua_S,1,0);
#if COCOS2D_DEBUG >= 1
    if (!cobj)
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_fgui_GController_setup'", nullptr);
        return 0;
    }
#endif
    argc = lua_gettop(tolua_S)-1;
    do{
        if (argc == 1) {
            const fgui::ControlerInfo* arg0;
            #pragma warning NO CONVERSION TO NATIVE FOR ControlerInfo*
		ok = false;

            if (!ok) { break; }
            cobj->setup(arg0);
            lua_settop(tolua_S, 1);
            return 1;
        }
    }while(0);
    ok  = true;
    do{
        if (argc == 1) {
            fgui::ByteBuffer* arg0;
            ok &= luaval_to_object<fgui::ByteBuffer>(tolua_S, 2, "fgui::ByteBuffer",&arg0, "fgui::GController:setup");

            if (!ok) { break; }
            cobj->setup(arg0);
            lua_settop(tolua_S, 1);
            return 1;
        }
    }while(0);
    ok  = true;
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n",  "fgui::GController:setup",argc, 1);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_fgui_GController_setup'.",&tolua_err);
#endif

    return 0;
}
int lua_cocos2dx_fgui_GController_getPrevisousIndex(lua_State* tolua_S)
{
    int argc = 0;
    fgui::GController* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"fgui::GController",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (fgui::GController*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_fgui_GController_getPrevisousIndex'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_cocos2dx_fgui_GController_getPrevisousIndex'", nullptr);
            return 0;
        }
        int ret = cobj->getPrevisousIndex();
        tolua_pushnumber(tolua_S,(lua_Number)ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "fgui::GController:getPrevisousIndex",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_fgui_GController_getPrevisousIndex'.",&tolua_err);
#endif

    return 0;
}
int lua_cocos2dx_fgui_GController_setSelectedIndex(lua_State* tolua_S)
{
    int argc = 0;
    fgui::GController* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"fgui::GController",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (fgui::GController*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_fgui_GController_setSelectedIndex'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 1) 
    {
        int arg0;

        ok &= luaval_to_int32(tolua_S, 2,(int *)&arg0, "fgui::GController:setSelectedIndex");
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_cocos2dx_fgui_GController_setSelectedIndex'", nullptr);
            return 0;
        }
        cobj->setSelectedIndex(arg0);
        lua_settop(tolua_S, 1);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "fgui::GController:setSelectedIndex",argc, 1);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_fgui_GController_setSelectedIndex'.",&tolua_err);
#endif

    return 0;
}
int lua_cocos2dx_fgui_GController_getPageId(lua_State* tolua_S)
{
    int argc = 0;
    fgui::GController* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"fgui::GController",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (fgui::GController*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_fgui_GController_getPageId'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 1) 
    {
        int arg0;

        ok &= luaval_to_int32(tolua_S, 2,(int *)&arg0, "fgui::GController:getPageId");
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_cocos2dx_fgui_GController_getPageId'", nullptr);
            return 0;
        }
        const std::string& ret = cobj->getPageId(arg0);
        lua_pushlstring(tolua_S,ret.c_str(),ret.length());
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "fgui::GController:getPageId",argc, 1);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_fgui_GController_getPageId'.",&tolua_err);
#endif

    return 0;
}
int lua_cocos2dx_fgui_GController_getSelectedPageId(lua_State* tolua_S)
{
    int argc = 0;
    fgui::GController* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"fgui::GController",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (fgui::GController*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_fgui_GController_getSelectedPageId'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_cocos2dx_fgui_GController_getSelectedPageId'", nullptr);
            return 0;
        }
        const std::string& ret = cobj->getSelectedPageId();
        lua_pushlstring(tolua_S,ret.c_str(),ret.length());
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "fgui::GController:getSelectedPageId",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_fgui_GController_getSelectedPageId'.",&tolua_err);
#endif

    return 0;
}
int lua_cocos2dx_fgui_GController_setParent(lua_State* tolua_S)
{
    int argc = 0;
    fgui::GController* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"fgui::GController",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (fgui::GController*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_fgui_GController_setParent'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 1) 
    {
        fgui::GComponent* arg0;

        ok &= luaval_to_object<fgui::GComponent>(tolua_S, 2, "fgui::GComponent",&arg0, "fgui::GController:setParent");
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_cocos2dx_fgui_GController_setParent'", nullptr);
            return 0;
        }
        cobj->setParent(arg0);
        lua_settop(tolua_S, 1);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "fgui::GController:setParent",argc, 1);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_fgui_GController_setParent'.",&tolua_err);
#endif

    return 0;
}
int lua_cocos2dx_fgui_GController_getName(lua_State* tolua_S)
{
    int argc = 0;
    fgui::GController* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"fgui::GController",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (fgui::GController*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_fgui_GController_getName'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_cocos2dx_fgui_GController_getName'", nullptr);
            return 0;
        }
        const std::string& ret = cobj->getName();
        lua_pushlstring(tolua_S,ret.c_str(),ret.length());
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "fgui::GController:getName",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_fgui_GController_getName'.",&tolua_err);
#endif

    return 0;
}
int lua_cocos2dx_fgui_GController_getPageIndexById(lua_State* tolua_S)
{
    int argc = 0;
    fgui::GController* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"fgui::GController",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (fgui::GController*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_fgui_GController_getPageIndexById'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 1) 
    {
        std::string arg0;

        ok &= luaval_to_std_string(tolua_S, 2,&arg0, "fgui::GController:getPageIndexById");
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_cocos2dx_fgui_GController_getPageIndexById'", nullptr);
            return 0;
        }
        int ret = cobj->getPageIndexById(arg0);
        tolua_pushnumber(tolua_S,(lua_Number)ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "fgui::GController:getPageIndexById",argc, 1);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_fgui_GController_getPageIndexById'.",&tolua_err);
#endif

    return 0;
}
int lua_cocos2dx_fgui_GController_setOppositePageId(lua_State* tolua_S)
{
    int argc = 0;
    fgui::GController* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"fgui::GController",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (fgui::GController*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_fgui_GController_setOppositePageId'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 1) 
    {
        std::string arg0;

        ok &= luaval_to_std_string(tolua_S, 2,&arg0, "fgui::GController:setOppositePageId");
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_cocos2dx_fgui_GController_setOppositePageId'", nullptr);
            return 0;
        }
        cobj->setOppositePageId(arg0);
        lua_settop(tolua_S, 1);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "fgui::GController:setOppositePageId",argc, 1);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_fgui_GController_setOppositePageId'.",&tolua_err);
#endif

    return 0;
}
int lua_cocos2dx_fgui_GController_hasPage(lua_State* tolua_S)
{
    int argc = 0;
    fgui::GController* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"fgui::GController",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (fgui::GController*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_fgui_GController_hasPage'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 1) 
    {
        std::string arg0;

        ok &= luaval_to_std_string(tolua_S, 2,&arg0, "fgui::GController:hasPage");
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_cocos2dx_fgui_GController_hasPage'", nullptr);
            return 0;
        }
        bool ret = cobj->hasPage(arg0);
        tolua_pushboolean(tolua_S,(bool)ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "fgui::GController:hasPage",argc, 1);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_fgui_GController_hasPage'.",&tolua_err);
#endif

    return 0;
}
int lua_cocos2dx_fgui_GController_getPageNameById(lua_State* tolua_S)
{
    int argc = 0;
    fgui::GController* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"fgui::GController",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (fgui::GController*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_fgui_GController_getPageNameById'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 1) 
    {
        std::string arg0;

        ok &= luaval_to_std_string(tolua_S, 2,&arg0, "fgui::GController:getPageNameById");
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_cocos2dx_fgui_GController_getPageNameById'", nullptr);
            return 0;
        }
        const std::string& ret = cobj->getPageNameById(arg0);
        lua_pushlstring(tolua_S,ret.c_str(),ret.length());
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "fgui::GController:getPageNameById",argc, 1);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_fgui_GController_getPageNameById'.",&tolua_err);
#endif

    return 0;
}
int lua_cocos2dx_fgui_GController_getPreviousPageId(lua_State* tolua_S)
{
    int argc = 0;
    fgui::GController* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"fgui::GController",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (fgui::GController*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_fgui_GController_getPreviousPageId'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_cocos2dx_fgui_GController_getPreviousPageId'", nullptr);
            return 0;
        }
        const std::string& ret = cobj->getPreviousPageId();
        lua_pushlstring(tolua_S,ret.c_str(),ret.length());
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "fgui::GController:getPreviousPageId",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_fgui_GController_getPreviousPageId'.",&tolua_err);
#endif

    return 0;
}
int lua_cocos2dx_fgui_GController_getPageCount(lua_State* tolua_S)
{
    int argc = 0;
    fgui::GController* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"fgui::GController",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (fgui::GController*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_fgui_GController_getPageCount'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_cocos2dx_fgui_GController_getPageCount'", nullptr);
            return 0;
        }
        int ret = cobj->getPageCount();
        tolua_pushnumber(tolua_S,(lua_Number)ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "fgui::GController:getPageCount",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_fgui_GController_getPageCount'.",&tolua_err);
#endif

    return 0;
}
int lua_cocos2dx_fgui_GController_getSelectedIndex(lua_State* tolua_S)
{
    int argc = 0;
    fgui::GController* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"fgui::GController",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (fgui::GController*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_fgui_GController_getSelectedIndex'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_cocos2dx_fgui_GController_getSelectedIndex'", nullptr);
            return 0;
        }
        int ret = cobj->getSelectedIndex();
        tolua_pushnumber(tolua_S,(lua_Number)ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "fgui::GController:getSelectedIndex",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_fgui_GController_getSelectedIndex'.",&tolua_err);
#endif

    return 0;
}
int lua_cocos2dx_fgui_GController_getPreviousPage(lua_State* tolua_S)
{
    int argc = 0;
    fgui::GController* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"fgui::GController",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (fgui::GController*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_fgui_GController_getPreviousPage'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_cocos2dx_fgui_GController_getPreviousPage'", nullptr);
            return 0;
        }
        const std::string& ret = cobj->getPreviousPage();
        lua_pushlstring(tolua_S,ret.c_str(),ret.length());
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "fgui::GController:getPreviousPage",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_fgui_GController_getPreviousPage'.",&tolua_err);
#endif

    return 0;
}
int lua_cocos2dx_fgui_GController_setSelectedPageId(lua_State* tolua_S)
{
    int argc = 0;
    fgui::GController* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"fgui::GController",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (fgui::GController*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_fgui_GController_setSelectedPageId'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 1) 
    {
        std::string arg0;

        ok &= luaval_to_std_string(tolua_S, 2,&arg0, "fgui::GController:setSelectedPageId");
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_cocos2dx_fgui_GController_setSelectedPageId'", nullptr);
            return 0;
        }
        cobj->setSelectedPageId(arg0);
        lua_settop(tolua_S, 1);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "fgui::GController:setSelectedPageId",argc, 1);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_fgui_GController_setSelectedPageId'.",&tolua_err);
#endif

    return 0;
}
int lua_cocos2dx_fgui_GController_getSelectedPage(lua_State* tolua_S)
{
    int argc = 0;
    fgui::GController* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"fgui::GController",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (fgui::GController*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_fgui_GController_getSelectedPage'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_cocos2dx_fgui_GController_getSelectedPage'", nullptr);
            return 0;
        }
        const std::string& ret = cobj->getSelectedPage();
        lua_pushlstring(tolua_S,ret.c_str(),ret.length());
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "fgui::GController:getSelectedPage",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_fgui_GController_getSelectedPage'.",&tolua_err);
#endif

    return 0;
}
int lua_cocos2dx_fgui_GController_getParent(lua_State* tolua_S)
{
    int argc = 0;
    fgui::GController* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"fgui::GController",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (fgui::GController*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_fgui_GController_getParent'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_cocos2dx_fgui_GController_getParent'", nullptr);
            return 0;
        }
        fgui::GComponent* ret = cobj->getParent();
        object_to_luaval<fgui::GComponent>(tolua_S, "fgui::GComponent",(fgui::GComponent*)ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "fgui::GController:getParent",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_fgui_GController_getParent'.",&tolua_err);
#endif

    return 0;
}
static int lua_cocos2dx_fgui_GController_finalize(lua_State* tolua_S)
{
    printf("luabindings: finalizing LUA object (GController)");
    return 0;
}

int lua_register_cocos2dx_fgui_GController(lua_State* tolua_S)
{
    tolua_usertype(tolua_S,"fgui::GController");
    tolua_cclass(tolua_S,"GController","fgui::GController","cc.Ref",nullptr);

    tolua_beginmodule(tolua_S,"GController");
        tolua_function(tolua_S,"runActions",lua_cocos2dx_fgui_GController_runActions);
        tolua_function(tolua_S,"setSelectedPage",lua_cocos2dx_fgui_GController_setSelectedPage);
        tolua_function(tolua_S,"setup",lua_cocos2dx_fgui_GController_setup);
        tolua_function(tolua_S,"getPrevisousIndex",lua_cocos2dx_fgui_GController_getPrevisousIndex);
        tolua_function(tolua_S,"setSelectedIndex",lua_cocos2dx_fgui_GController_setSelectedIndex);
        tolua_function(tolua_S,"getPageId",lua_cocos2dx_fgui_GController_getPageId);
        tolua_function(tolua_S,"getSelectedPageId",lua_cocos2dx_fgui_GController_getSelectedPageId);
        tolua_function(tolua_S,"setParent",lua_cocos2dx_fgui_GController_setParent);
        tolua_function(tolua_S,"getName",lua_cocos2dx_fgui_GController_getName);
        tolua_function(tolua_S,"getPageIndexById",lua_cocos2dx_fgui_GController_getPageIndexById);
        tolua_function(tolua_S,"setOppositePageId",lua_cocos2dx_fgui_GController_setOppositePageId);
        tolua_function(tolua_S,"hasPage",lua_cocos2dx_fgui_GController_hasPage);
        tolua_function(tolua_S,"getPageNameById",lua_cocos2dx_fgui_GController_getPageNameById);
        tolua_function(tolua_S,"getPreviousPageId",lua_cocos2dx_fgui_GController_getPreviousPageId);
        tolua_function(tolua_S,"getPageCount",lua_cocos2dx_fgui_GController_getPageCount);
        tolua_function(tolua_S,"getSelectedIndex",lua_cocos2dx_fgui_GController_getSelectedIndex);
        tolua_function(tolua_S,"getPreviousPage",lua_cocos2dx_fgui_GController_getPreviousPage);
        tolua_function(tolua_S,"setSelectedPageId",lua_cocos2dx_fgui_GController_setSelectedPageId);
        tolua_function(tolua_S,"getSelectedPage",lua_cocos2dx_fgui_GController_getSelectedPage);
        tolua_function(tolua_S,"getParent",lua_cocos2dx_fgui_GController_getParent);
    tolua_endmodule(tolua_S);
    std::string typeName = typeid(fgui::GController).name();
    g_luaType[typeName] = "fgui::GController";
    g_typeCast["GController"] = "fgui::GController";
    return 1;
}

int lua_cocos2dx_fgui_GTransition_setTimeScale(lua_State* tolua_S)
{
    int argc = 0;
    fgui::GTransition* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"fgui::GTransition",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (fgui::GTransition*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_fgui_GTransition_setTimeScale'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 1) 
    {
        double arg0;

        ok &= luaval_to_number(tolua_S, 2,&arg0, "fgui::GTransition:setTimeScale");
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_cocos2dx_fgui_GTransition_setTimeScale'", nullptr);
            return 0;
        }
        cobj->setTimeScale(arg0);
        lua_settop(tolua_S, 1);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "fgui::GTransition:setTimeScale",argc, 1);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_fgui_GTransition_setTimeScale'.",&tolua_err);
#endif

    return 0;
}
int lua_cocos2dx_fgui_GTransition_changePlayTimes(lua_State* tolua_S)
{
    int argc = 0;
    fgui::GTransition* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"fgui::GTransition",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (fgui::GTransition*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_fgui_GTransition_changePlayTimes'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 1) 
    {
        int arg0;

        ok &= luaval_to_int32(tolua_S, 2,(int *)&arg0, "fgui::GTransition:changePlayTimes");
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_cocos2dx_fgui_GTransition_changePlayTimes'", nullptr);
            return 0;
        }
        cobj->changePlayTimes(arg0);
        lua_settop(tolua_S, 1);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "fgui::GTransition:changePlayTimes",argc, 1);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_fgui_GTransition_changePlayTimes'.",&tolua_err);
#endif

    return 0;
}
int lua_cocos2dx_fgui_GTransition_getName(lua_State* tolua_S)
{
    int argc = 0;
    fgui::GTransition* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"fgui::GTransition",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (fgui::GTransition*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_fgui_GTransition_getName'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_cocos2dx_fgui_GTransition_getName'", nullptr);
            return 0;
        }
        const std::string& ret = cobj->getName();
        lua_pushlstring(tolua_S,ret.c_str(),ret.length());
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "fgui::GTransition:getName",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_fgui_GTransition_getName'.",&tolua_err);
#endif

    return 0;
}
int lua_cocos2dx_fgui_GTransition_clearHooks(lua_State* tolua_S)
{
    int argc = 0;
    fgui::GTransition* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"fgui::GTransition",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (fgui::GTransition*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_fgui_GTransition_clearHooks'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_cocos2dx_fgui_GTransition_clearHooks'", nullptr);
            return 0;
        }
        cobj->clearHooks();
        lua_settop(tolua_S, 1);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "fgui::GTransition:clearHooks",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_fgui_GTransition_clearHooks'.",&tolua_err);
#endif

    return 0;
}
int lua_cocos2dx_fgui_GTransition_setAutoPlay(lua_State* tolua_S)
{
    int argc = 0;
    fgui::GTransition* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"fgui::GTransition",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (fgui::GTransition*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_fgui_GTransition_setAutoPlay'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 3) 
    {
        bool arg0;
        int arg1;
        double arg2;

        ok &= luaval_to_boolean(tolua_S, 2,&arg0, "fgui::GTransition:setAutoPlay");

        ok &= luaval_to_int32(tolua_S, 3,(int *)&arg1, "fgui::GTransition:setAutoPlay");

        ok &= luaval_to_number(tolua_S, 4,&arg2, "fgui::GTransition:setAutoPlay");
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_cocos2dx_fgui_GTransition_setAutoPlay'", nullptr);
            return 0;
        }
        cobj->setAutoPlay(arg0, arg1, arg2);
        lua_settop(tolua_S, 1);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "fgui::GTransition:setAutoPlay",argc, 3);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_fgui_GTransition_setAutoPlay'.",&tolua_err);
#endif

    return 0;
}
int lua_cocos2dx_fgui_GTransition_updateFromRelations(lua_State* tolua_S)
{
    int argc = 0;
    fgui::GTransition* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"fgui::GTransition",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (fgui::GTransition*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_fgui_GTransition_updateFromRelations'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 3) 
    {
        cocos2d::Node* arg0;
        double arg1;
        double arg2;

        ok &= luaval_to_object<cocos2d::Node>(tolua_S, 2, "cc.Node",&arg0, "fgui::GTransition:updateFromRelations");

        ok &= luaval_to_number(tolua_S, 3,&arg1, "fgui::GTransition:updateFromRelations");

        ok &= luaval_to_number(tolua_S, 4,&arg2, "fgui::GTransition:updateFromRelations");
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_cocos2dx_fgui_GTransition_updateFromRelations'", nullptr);
            return 0;
        }
        cobj->updateFromRelations(arg0, arg1, arg2);
        lua_settop(tolua_S, 1);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "fgui::GTransition:updateFromRelations",argc, 3);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_fgui_GTransition_updateFromRelations'.",&tolua_err);
#endif

    return 0;
}
int lua_cocos2dx_fgui_GTransition_setValue(lua_State* tolua_S)
{
    int argc = 0;
    fgui::GTransition* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"fgui::GTransition",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (fgui::GTransition*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_fgui_GTransition_setValue'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 2) 
    {
        std::string arg0;
        cocos2d::ValueVector arg1;

        ok &= luaval_to_std_string(tolua_S, 2,&arg0, "fgui::GTransition:setValue");

        ok &= luaval_to_ccvaluevector(tolua_S, 3, &arg1, "fgui::GTransition:setValue");
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_cocos2dx_fgui_GTransition_setValue'", nullptr);
            return 0;
        }
        cobj->setValue(arg0, arg1);
        lua_settop(tolua_S, 1);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "fgui::GTransition:setValue",argc, 2);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_fgui_GTransition_setValue'.",&tolua_err);
#endif

    return 0;
}
int lua_cocos2dx_fgui_GTransition_getLabelTime(lua_State* tolua_S)
{
    int argc = 0;
    fgui::GTransition* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"fgui::GTransition",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (fgui::GTransition*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_fgui_GTransition_getLabelTime'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 1) 
    {
        std::string arg0;

        ok &= luaval_to_std_string(tolua_S, 2,&arg0, "fgui::GTransition:getLabelTime");
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_cocos2dx_fgui_GTransition_getLabelTime'", nullptr);
            return 0;
        }
        double ret = cobj->getLabelTime(arg0);
        tolua_pushnumber(tolua_S,(lua_Number)ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "fgui::GTransition:getLabelTime",argc, 1);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_fgui_GTransition_getLabelTime'.",&tolua_err);
#endif

    return 0;
}
int lua_cocos2dx_fgui_GTransition_onOwnerRemovedFromStage(lua_State* tolua_S)
{
    int argc = 0;
    fgui::GTransition* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"fgui::GTransition",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (fgui::GTransition*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_fgui_GTransition_onOwnerRemovedFromStage'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_cocos2dx_fgui_GTransition_onOwnerRemovedFromStage'", nullptr);
            return 0;
        }
        cobj->onOwnerRemovedFromStage();
        lua_settop(tolua_S, 1);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "fgui::GTransition:onOwnerRemovedFromStage",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_fgui_GTransition_onOwnerRemovedFromStage'.",&tolua_err);
#endif

    return 0;
}
int lua_cocos2dx_fgui_GTransition_setTarget(lua_State* tolua_S)
{
    int argc = 0;
    fgui::GTransition* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"fgui::GTransition",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (fgui::GTransition*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_fgui_GTransition_setTarget'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 2) 
    {
        std::string arg0;
        fgui::GObject* arg1;

        ok &= luaval_to_std_string(tolua_S, 2,&arg0, "fgui::GTransition:setTarget");

        ok &= luaval_to_object<fgui::GObject>(tolua_S, 3, "fgui::GObject",&arg1, "fgui::GTransition:setTarget");
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_cocos2dx_fgui_GTransition_setTarget'", nullptr);
            return 0;
        }
        cobj->setTarget(arg0, arg1);
        lua_settop(tolua_S, 1);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "fgui::GTransition:setTarget",argc, 2);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_fgui_GTransition_setTarget'.",&tolua_err);
#endif

    return 0;
}
int lua_cocos2dx_fgui_GTransition_stop(lua_State* tolua_S)
{
    int argc = 0;
    fgui::GTransition* cobj = nullptr;
    bool ok  = true;
#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif

#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"fgui::GTransition",0,&tolua_err)) goto tolua_lerror;
#endif
    cobj = (fgui::GTransition*)tolua_tousertype(tolua_S,1,0);
#if COCOS2D_DEBUG >= 1
    if (!cobj)
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_fgui_GTransition_stop'", nullptr);
        return 0;
    }
#endif
    argc = lua_gettop(tolua_S)-1;
    do{
        if (argc == 2) {
            bool arg0;
            ok &= luaval_to_boolean(tolua_S, 2,&arg0, "fgui::GTransition:stop");

            if (!ok) { break; }
            bool arg1;
            ok &= luaval_to_boolean(tolua_S, 3,&arg1, "fgui::GTransition:stop");

            if (!ok) { break; }
            cobj->stop(arg0, arg1);
            lua_settop(tolua_S, 1);
            return 1;
        }
    }while(0);
    ok  = true;
    do{
        if (argc == 0) {
            cobj->stop();
            lua_settop(tolua_S, 1);
            return 1;
        }
    }while(0);
    ok  = true;
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n",  "fgui::GTransition:stop",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_fgui_GTransition_stop'.",&tolua_err);
#endif

    return 0;
}
int lua_cocos2dx_fgui_GTransition_isPlaying(lua_State* tolua_S)
{
    int argc = 0;
    fgui::GTransition* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"fgui::GTransition",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (fgui::GTransition*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_fgui_GTransition_isPlaying'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_cocos2dx_fgui_GTransition_isPlaying'", nullptr);
            return 0;
        }
        bool ret = cobj->isPlaying();
        tolua_pushboolean(tolua_S,(bool)ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "fgui::GTransition:isPlaying",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_fgui_GTransition_isPlaying'.",&tolua_err);
#endif

    return 0;
}
int lua_cocos2dx_fgui_GTransition_getTimeScale(lua_State* tolua_S)
{
    int argc = 0;
    fgui::GTransition* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"fgui::GTransition",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (fgui::GTransition*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_fgui_GTransition_getTimeScale'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_cocos2dx_fgui_GTransition_getTimeScale'", nullptr);
            return 0;
        }
        double ret = cobj->getTimeScale();
        tolua_pushnumber(tolua_S,(lua_Number)ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "fgui::GTransition:getTimeScale",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_fgui_GTransition_getTimeScale'.",&tolua_err);
#endif

    return 0;
}
int lua_cocos2dx_fgui_GTransition_onOwnerAddedToStage(lua_State* tolua_S)
{
    int argc = 0;
    fgui::GTransition* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"fgui::GTransition",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (fgui::GTransition*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_fgui_GTransition_onOwnerAddedToStage'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_cocos2dx_fgui_GTransition_onOwnerAddedToStage'", nullptr);
            return 0;
        }
        cobj->onOwnerAddedToStage();
        lua_settop(tolua_S, 1);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "fgui::GTransition:onOwnerAddedToStage",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_fgui_GTransition_onOwnerAddedToStage'.",&tolua_err);
#endif

    return 0;
}
int lua_cocos2dx_fgui_GTransition_setup(lua_State* tolua_S)
{
    int argc = 0;
    fgui::GTransition* cobj = nullptr;
    bool ok  = true;
#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif

#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"fgui::GTransition",0,&tolua_err)) goto tolua_lerror;
#endif
    cobj = (fgui::GTransition*)tolua_tousertype(tolua_S,1,0);
#if COCOS2D_DEBUG >= 1
    if (!cobj)
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_fgui_GTransition_setup'", nullptr);
        return 0;
    }
#endif
    argc = lua_gettop(tolua_S)-1;
    do{
        if (argc == 1) {
            const fgui::TransitionInfo* arg0;
            #pragma warning NO CONVERSION TO NATIVE FOR TransitionInfo*
		ok = false;

            if (!ok) { break; }
            cobj->setup(arg0);
            lua_settop(tolua_S, 1);
            return 1;
        }
    }while(0);
    ok  = true;
    do{
        if (argc == 1) {
            fgui::ByteBuffer* arg0;
            ok &= luaval_to_object<fgui::ByteBuffer>(tolua_S, 2, "fgui::ByteBuffer",&arg0, "fgui::GTransition:setup");

            if (!ok) { break; }
            cobj->setup(arg0);
            lua_settop(tolua_S, 1);
            return 1;
        }
    }while(0);
    ok  = true;
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n",  "fgui::GTransition:setup",argc, 1);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_fgui_GTransition_setup'.",&tolua_err);
#endif

    return 0;
}
int lua_cocos2dx_fgui_GTransition_getOwner(lua_State* tolua_S)
{
    int argc = 0;
    fgui::GTransition* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"fgui::GTransition",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (fgui::GTransition*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_fgui_GTransition_getOwner'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_cocos2dx_fgui_GTransition_getOwner'", nullptr);
            return 0;
        }
        fgui::GComponent* ret = cobj->getOwner();
        object_to_luaval<fgui::GComponent>(tolua_S, "fgui::GComponent",(fgui::GComponent*)ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "fgui::GTransition:getOwner",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_fgui_GTransition_getOwner'.",&tolua_err);
#endif

    return 0;
}
int lua_cocos2dx_fgui_GTransition_setDuration(lua_State* tolua_S)
{
    int argc = 0;
    fgui::GTransition* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"fgui::GTransition",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (fgui::GTransition*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_fgui_GTransition_setDuration'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 2) 
    {
        std::string arg0;
        double arg1;

        ok &= luaval_to_std_string(tolua_S, 2,&arg0, "fgui::GTransition:setDuration");

        ok &= luaval_to_number(tolua_S, 3,&arg1, "fgui::GTransition:setDuration");
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_cocos2dx_fgui_GTransition_setDuration'", nullptr);
            return 0;
        }
        cobj->setDuration(arg0, arg1);
        lua_settop(tolua_S, 1);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "fgui::GTransition:setDuration",argc, 2);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_fgui_GTransition_setDuration'.",&tolua_err);
#endif

    return 0;
}
int lua_cocos2dx_fgui_GTransition_setPaused(lua_State* tolua_S)
{
    int argc = 0;
    fgui::GTransition* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"fgui::GTransition",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (fgui::GTransition*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_fgui_GTransition_setPaused'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 1) 
    {
        bool arg0;

        ok &= luaval_to_boolean(tolua_S, 2,&arg0, "fgui::GTransition:setPaused");
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_cocos2dx_fgui_GTransition_setPaused'", nullptr);
            return 0;
        }
        cobj->setPaused(arg0);
        lua_settop(tolua_S, 1);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "fgui::GTransition:setPaused",argc, 1);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_fgui_GTransition_setPaused'.",&tolua_err);
#endif

    return 0;
}
int lua_cocos2dx_fgui_GTransition_constructor(lua_State* tolua_S)
{
    int argc = 0;
    fgui::GTransition* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif



    argc = lua_gettop(tolua_S)-1;
    if (argc == 1) 
    {
        fgui::GComponent* arg0;

        ok &= luaval_to_object<fgui::GComponent>(tolua_S, 2, "fgui::GComponent",&arg0, "fgui::GTransition:GTransition");
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_cocos2dx_fgui_GTransition_constructor'", nullptr);
            return 0;
        }
        cobj = new fgui::GTransition(arg0);
        cobj->autorelease();
        int ID =  (int)cobj->_ID ;
        int* luaID =  &cobj->_luaID ;
        toluafix_pushusertype_ccobject(tolua_S, ID, luaID, (void*)cobj,"fgui::GTransition");
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "fgui::GTransition:GTransition",argc, 1);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_fgui_GTransition_constructor'.",&tolua_err);
#endif

    return 0;
}

static int lua_cocos2dx_fgui_GTransition_finalize(lua_State* tolua_S)
{
    printf("luabindings: finalizing LUA object (GTransition)");
    return 0;
}

int lua_register_cocos2dx_fgui_GTransition(lua_State* tolua_S)
{
    tolua_usertype(tolua_S,"fgui::GTransition");
    tolua_cclass(tolua_S,"GTransition","fgui::GTransition","cc.Ref",nullptr);

    tolua_beginmodule(tolua_S,"GTransition");
        tolua_function(tolua_S,"new",lua_cocos2dx_fgui_GTransition_constructor);
        tolua_function(tolua_S,"setTimeScale",lua_cocos2dx_fgui_GTransition_setTimeScale);
        tolua_function(tolua_S,"changePlayTimes",lua_cocos2dx_fgui_GTransition_changePlayTimes);
        tolua_function(tolua_S,"getName",lua_cocos2dx_fgui_GTransition_getName);
        tolua_function(tolua_S,"clearHooks",lua_cocos2dx_fgui_GTransition_clearHooks);
        tolua_function(tolua_S,"setAutoPlay",lua_cocos2dx_fgui_GTransition_setAutoPlay);
        tolua_function(tolua_S,"updateFromRelations",lua_cocos2dx_fgui_GTransition_updateFromRelations);
        tolua_function(tolua_S,"setValue",lua_cocos2dx_fgui_GTransition_setValue);
        tolua_function(tolua_S,"getLabelTime",lua_cocos2dx_fgui_GTransition_getLabelTime);
        tolua_function(tolua_S,"onOwnerRemovedFromStage",lua_cocos2dx_fgui_GTransition_onOwnerRemovedFromStage);
        tolua_function(tolua_S,"setTarget",lua_cocos2dx_fgui_GTransition_setTarget);
        tolua_function(tolua_S,"stop",lua_cocos2dx_fgui_GTransition_stop);
        tolua_function(tolua_S,"isPlaying",lua_cocos2dx_fgui_GTransition_isPlaying);
        tolua_function(tolua_S,"getTimeScale",lua_cocos2dx_fgui_GTransition_getTimeScale);
        tolua_function(tolua_S,"onOwnerAddedToStage",lua_cocos2dx_fgui_GTransition_onOwnerAddedToStage);
        tolua_function(tolua_S,"setup",lua_cocos2dx_fgui_GTransition_setup);
        tolua_function(tolua_S,"getOwner",lua_cocos2dx_fgui_GTransition_getOwner);
        tolua_function(tolua_S,"setDuration",lua_cocos2dx_fgui_GTransition_setDuration);
        tolua_function(tolua_S,"setPaused",lua_cocos2dx_fgui_GTransition_setPaused);
    tolua_endmodule(tolua_S);
    std::string typeName = typeid(fgui::GTransition).name();
    g_luaType[typeName] = "fgui::GTransition";
    g_typeCast["GTransition"] = "fgui::GTransition";
    return 1;
}

int lua_cocos2dx_fgui_GTweener_setTimeScale(lua_State* tolua_S)
{
    int argc = 0;
    fgui::GTweener* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"fgui::GTweener",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (fgui::GTweener*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_fgui_GTweener_setTimeScale'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 1) 
    {
        double arg0;

        ok &= luaval_to_number(tolua_S, 2,&arg0, "fgui::GTweener:setTimeScale");
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_cocos2dx_fgui_GTweener_setTimeScale'", nullptr);
            return 0;
        }
        fgui::GTweener* ret = cobj->setTimeScale(arg0);
        object_to_luaval<fgui::GTweener>(tolua_S, "fgui::GTweener",(fgui::GTweener*)ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "fgui::GTweener:setTimeScale",argc, 1);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_fgui_GTweener_setTimeScale'.",&tolua_err);
#endif

    return 0;
}
int lua_cocos2dx_fgui_GTweener_toVec3(lua_State* tolua_S)
{
    int argc = 0;
    fgui::GTweener* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"fgui::GTweener",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (fgui::GTweener*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_fgui_GTweener_toVec3'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 3) 
    {
        cocos2d::Vec3 arg0;
        cocos2d::Vec3 arg1;
        double arg2;

        ok &= luaval_to_vec3(tolua_S, 2, &arg0, "fgui::GTweener:toVec3");

        ok &= luaval_to_vec3(tolua_S, 3, &arg1, "fgui::GTweener:toVec3");

        ok &= luaval_to_number(tolua_S, 4,&arg2, "fgui::GTweener:toVec3");
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_cocos2dx_fgui_GTweener_toVec3'", nullptr);
            return 0;
        }
        fgui::GTweener* ret = cobj->toVec3(arg0, arg1, arg2);
        object_to_luaval<fgui::GTweener>(tolua_S, "fgui::GTweener",(fgui::GTweener*)ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "fgui::GTweener:toVec3",argc, 3);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_fgui_GTweener_toVec3'.",&tolua_err);
#endif

    return 0;
}
int lua_cocos2dx_fgui_GTweener_toVec2(lua_State* tolua_S)
{
    int argc = 0;
    fgui::GTweener* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"fgui::GTweener",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (fgui::GTweener*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_fgui_GTweener_toVec2'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 3) 
    {
        cocos2d::Vec2 arg0;
        cocos2d::Vec2 arg1;
        double arg2;

        ok &= luaval_to_vec2(tolua_S, 2, &arg0, "fgui::GTweener:toVec2");

        ok &= luaval_to_vec2(tolua_S, 3, &arg1, "fgui::GTweener:toVec2");

        ok &= luaval_to_number(tolua_S, 4,&arg2, "fgui::GTweener:toVec2");
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_cocos2dx_fgui_GTweener_toVec2'", nullptr);
            return 0;
        }
        fgui::GTweener* ret = cobj->toVec2(arg0, arg1, arg2);
        object_to_luaval<fgui::GTweener>(tolua_S, "fgui::GTweener",(fgui::GTweener*)ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "fgui::GTweener:toVec2",argc, 3);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_fgui_GTweener_toVec2'.",&tolua_err);
#endif

    return 0;
}
int lua_cocos2dx_fgui_GTweener_getRepeat(lua_State* tolua_S)
{
    int argc = 0;
    fgui::GTweener* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"fgui::GTweener",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (fgui::GTweener*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_fgui_GTweener_getRepeat'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_cocos2dx_fgui_GTweener_getRepeat'", nullptr);
            return 0;
        }
        int ret = cobj->getRepeat();
        tolua_pushnumber(tolua_S,(lua_Number)ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "fgui::GTweener:getRepeat",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_fgui_GTweener_getRepeat'.",&tolua_err);
#endif

    return 0;
}
int lua_cocos2dx_fgui_GTweener_setEase(lua_State* tolua_S)
{
    int argc = 0;
    fgui::GTweener* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"fgui::GTweener",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (fgui::GTweener*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_fgui_GTweener_setEase'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 1) 
    {
        fgui::EaseType arg0;

        ok &= luaval_to_int32(tolua_S, 2,(int *)&arg0, "fgui::GTweener:setEase");
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_cocos2dx_fgui_GTweener_setEase'", nullptr);
            return 0;
        }
        fgui::GTweener* ret = cobj->setEase(arg0);
        object_to_luaval<fgui::GTweener>(tolua_S, "fgui::GTweener",(fgui::GTweener*)ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "fgui::GTweener:setEase",argc, 1);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_fgui_GTweener_setEase'.",&tolua_err);
#endif

    return 0;
}
int lua_cocos2dx_fgui_GTweener_getDuration(lua_State* tolua_S)
{
    int argc = 0;
    fgui::GTweener* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"fgui::GTweener",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (fgui::GTweener*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_fgui_GTweener_getDuration'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_cocos2dx_fgui_GTweener_getDuration'", nullptr);
            return 0;
        }
        double ret = cobj->getDuration();
        tolua_pushnumber(tolua_S,(lua_Number)ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "fgui::GTweener:getDuration",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_fgui_GTweener_getDuration'.",&tolua_err);
#endif

    return 0;
}
int lua_cocos2dx_fgui_GTweener_getTarget(lua_State* tolua_S)
{
    int argc = 0;
    fgui::GTweener* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"fgui::GTweener",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (fgui::GTweener*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_fgui_GTweener_getTarget'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_cocos2dx_fgui_GTweener_getTarget'", nullptr);
            return 0;
        }
        void* ret = cobj->getTarget();
        #pragma warning NO CONVERSION FROM NATIVE FOR void*;
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "fgui::GTweener:getTarget",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_fgui_GTweener_getTarget'.",&tolua_err);
#endif

    return 0;
}
int lua_cocos2dx_fgui_GTweener_toVec4(lua_State* tolua_S)
{
    int argc = 0;
    fgui::GTweener* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"fgui::GTweener",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (fgui::GTweener*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_fgui_GTweener_toVec4'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 3) 
    {
        cocos2d::Vec4 arg0;
        cocos2d::Vec4 arg1;
        double arg2;

        ok &= luaval_to_vec4(tolua_S, 2, &arg0, "fgui::GTweener:toVec4");

        ok &= luaval_to_vec4(tolua_S, 3, &arg1, "fgui::GTweener:toVec4");

        ok &= luaval_to_number(tolua_S, 4,&arg2, "fgui::GTweener:toVec4");
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_cocos2dx_fgui_GTweener_toVec4'", nullptr);
            return 0;
        }
        fgui::GTweener* ret = cobj->toVec4(arg0, arg1, arg2);
        object_to_luaval<fgui::GTweener>(tolua_S, "fgui::GTweener",(fgui::GTweener*)ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "fgui::GTweener:toVec4",argc, 3);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_fgui_GTweener_toVec4'.",&tolua_err);
#endif

    return 0;
}
int lua_cocos2dx_fgui_GTweener_kill(lua_State* tolua_S)
{
    int argc = 0;
    fgui::GTweener* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"fgui::GTweener",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (fgui::GTweener*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_fgui_GTweener_kill'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_cocos2dx_fgui_GTweener_kill'", nullptr);
            return 0;
        }
        cobj->kill();
        lua_settop(tolua_S, 1);
        return 1;
    }
    if (argc == 1) 
    {
        bool arg0;

        ok &= luaval_to_boolean(tolua_S, 2,&arg0, "fgui::GTweener:kill");
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_cocos2dx_fgui_GTweener_kill'", nullptr);
            return 0;
        }
        cobj->kill(arg0);
        lua_settop(tolua_S, 1);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "fgui::GTweener:kill",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_fgui_GTweener_kill'.",&tolua_err);
#endif

    return 0;
}
int lua_cocos2dx_fgui_GTweener_shake(lua_State* tolua_S)
{
    int argc = 0;
    fgui::GTweener* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"fgui::GTweener",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (fgui::GTweener*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_fgui_GTweener_shake'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 3) 
    {
        cocos2d::Vec2 arg0;
        double arg1;
        double arg2;

        ok &= luaval_to_vec2(tolua_S, 2, &arg0, "fgui::GTweener:shake");

        ok &= luaval_to_number(tolua_S, 3,&arg1, "fgui::GTweener:shake");

        ok &= luaval_to_number(tolua_S, 4,&arg2, "fgui::GTweener:shake");
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_cocos2dx_fgui_GTweener_shake'", nullptr);
            return 0;
        }
        fgui::GTweener* ret = cobj->shake(arg0, arg1, arg2);
        object_to_luaval<fgui::GTweener>(tolua_S, "fgui::GTweener",(fgui::GTweener*)ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "fgui::GTweener:shake",argc, 3);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_fgui_GTweener_shake'.",&tolua_err);
#endif

    return 0;
}
int lua_cocos2dx_fgui_GTweener_allCompleted(lua_State* tolua_S)
{
    int argc = 0;
    fgui::GTweener* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"fgui::GTweener",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (fgui::GTweener*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_fgui_GTweener_allCompleted'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_cocos2dx_fgui_GTweener_allCompleted'", nullptr);
            return 0;
        }
        bool ret = cobj->allCompleted();
        tolua_pushboolean(tolua_S,(bool)ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "fgui::GTweener:allCompleted",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_fgui_GTweener_allCompleted'.",&tolua_err);
#endif

    return 0;
}
int lua_cocos2dx_fgui_GTweener_seek(lua_State* tolua_S)
{
    int argc = 0;
    fgui::GTweener* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"fgui::GTweener",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (fgui::GTweener*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_fgui_GTweener_seek'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 1) 
    {
        double arg0;

        ok &= luaval_to_number(tolua_S, 2,&arg0, "fgui::GTweener:seek");
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_cocos2dx_fgui_GTweener_seek'", nullptr);
            return 0;
        }
        cobj->seek(arg0);
        lua_settop(tolua_S, 1);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "fgui::GTweener:seek",argc, 1);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_fgui_GTweener_seek'.",&tolua_err);
#endif

    return 0;
}
int lua_cocos2dx_fgui_GTweener_setDelay(lua_State* tolua_S)
{
    int argc = 0;
    fgui::GTweener* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"fgui::GTweener",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (fgui::GTweener*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_fgui_GTweener_setDelay'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 1) 
    {
        double arg0;

        ok &= luaval_to_number(tolua_S, 2,&arg0, "fgui::GTweener:setDelay");
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_cocos2dx_fgui_GTweener_setDelay'", nullptr);
            return 0;
        }
        fgui::GTweener* ret = cobj->setDelay(arg0);
        object_to_luaval<fgui::GTweener>(tolua_S, "fgui::GTweener",(fgui::GTweener*)ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "fgui::GTweener:setDelay",argc, 1);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_fgui_GTweener_setDelay'.",&tolua_err);
#endif

    return 0;
}
int lua_cocos2dx_fgui_GTweener_toValue(lua_State* tolua_S)
{
    int argc = 0;
    fgui::GTweener* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"fgui::GTweener",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (fgui::GTweener*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_fgui_GTweener_toValue'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 3) 
    {
        double arg0;
        double arg1;
        double arg2;

        ok &= luaval_to_number(tolua_S, 2,&arg0, "fgui::GTweener:toValue");

        ok &= luaval_to_number(tolua_S, 3,&arg1, "fgui::GTweener:toValue");

        ok &= luaval_to_number(tolua_S, 4,&arg2, "fgui::GTweener:toValue");
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_cocos2dx_fgui_GTweener_toValue'", nullptr);
            return 0;
        }
        fgui::GTweener* ret = cobj->toValue(arg0, arg1, arg2);
        object_to_luaval<fgui::GTweener>(tolua_S, "fgui::GTweener",(fgui::GTweener*)ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "fgui::GTweener:toValue",argc, 3);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_fgui_GTweener_toValue'.",&tolua_err);
#endif

    return 0;
}
int lua_cocos2dx_fgui_GTweener_getUserData(lua_State* tolua_S)
{
    int argc = 0;
    fgui::GTweener* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"fgui::GTweener",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (fgui::GTweener*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_fgui_GTweener_getUserData'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_cocos2dx_fgui_GTweener_getUserData'", nullptr);
            return 0;
        }
        const cocos2d::Value& ret = cobj->getUserData();
        ccvalue_to_luaval(tolua_S, ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "fgui::GTweener:getUserData",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_fgui_GTweener_getUserData'.",&tolua_err);
#endif

    return 0;
}
int lua_cocos2dx_fgui_GTweener_setRepeat(lua_State* tolua_S)
{
    int argc = 0;
    fgui::GTweener* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"fgui::GTweener",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (fgui::GTweener*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_fgui_GTweener_setRepeat'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 1) 
    {
        int arg0;

        ok &= luaval_to_int32(tolua_S, 2,(int *)&arg0, "fgui::GTweener:setRepeat");
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_cocos2dx_fgui_GTweener_setRepeat'", nullptr);
            return 0;
        }
        fgui::GTweener* ret = cobj->setRepeat(arg0);
        object_to_luaval<fgui::GTweener>(tolua_S, "fgui::GTweener",(fgui::GTweener*)ret);
        return 1;
    }
    if (argc == 2) 
    {
        int arg0;
        bool arg1;

        ok &= luaval_to_int32(tolua_S, 2,(int *)&arg0, "fgui::GTweener:setRepeat");

        ok &= luaval_to_boolean(tolua_S, 3,&arg1, "fgui::GTweener:setRepeat");
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_cocos2dx_fgui_GTweener_setRepeat'", nullptr);
            return 0;
        }
        fgui::GTweener* ret = cobj->setRepeat(arg0, arg1);
        object_to_luaval<fgui::GTweener>(tolua_S, "fgui::GTweener",(fgui::GTweener*)ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "fgui::GTweener:setRepeat",argc, 1);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_fgui_GTweener_setRepeat'.",&tolua_err);
#endif

    return 0;
}
int lua_cocos2dx_fgui_GTweener_setBreakpoint(lua_State* tolua_S)
{
    int argc = 0;
    fgui::GTweener* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"fgui::GTweener",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (fgui::GTweener*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_fgui_GTweener_setBreakpoint'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 1) 
    {
        double arg0;

        ok &= luaval_to_number(tolua_S, 2,&arg0, "fgui::GTweener:setBreakpoint");
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_cocos2dx_fgui_GTweener_setBreakpoint'", nullptr);
            return 0;
        }
        fgui::GTweener* ret = cobj->setBreakpoint(arg0);
        object_to_luaval<fgui::GTweener>(tolua_S, "fgui::GTweener",(fgui::GTweener*)ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "fgui::GTweener:setBreakpoint",argc, 1);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_fgui_GTweener_setBreakpoint'.",&tolua_err);
#endif

    return 0;
}
int lua_cocos2dx_fgui_GTweener_toColor(lua_State* tolua_S)
{
    int argc = 0;
    fgui::GTweener* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"fgui::GTweener",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (fgui::GTweener*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_fgui_GTweener_toColor'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 3) 
    {
        cocos2d::Color4B arg0;
        cocos2d::Color4B arg1;
        double arg2;

        ok &=luaval_to_color4b(tolua_S, 2, &arg0, "fgui::GTweener:toColor");

        ok &=luaval_to_color4b(tolua_S, 3, &arg1, "fgui::GTweener:toColor");

        ok &= luaval_to_number(tolua_S, 4,&arg2, "fgui::GTweener:toColor");
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_cocos2dx_fgui_GTweener_toColor'", nullptr);
            return 0;
        }
        fgui::GTweener* ret = cobj->toColor(arg0, arg1, arg2);
        object_to_luaval<fgui::GTweener>(tolua_S, "fgui::GTweener",(fgui::GTweener*)ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "fgui::GTweener:toColor",argc, 3);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_fgui_GTweener_toColor'.",&tolua_err);
#endif

    return 0;
}
int lua_cocos2dx_fgui_GTweener_setEasePeriod(lua_State* tolua_S)
{
    int argc = 0;
    fgui::GTweener* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"fgui::GTweener",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (fgui::GTweener*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_fgui_GTweener_setEasePeriod'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 1) 
    {
        double arg0;

        ok &= luaval_to_number(tolua_S, 2,&arg0, "fgui::GTweener:setEasePeriod");
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_cocos2dx_fgui_GTweener_setEasePeriod'", nullptr);
            return 0;
        }
        fgui::GTweener* ret = cobj->setEasePeriod(arg0);
        object_to_luaval<fgui::GTweener>(tolua_S, "fgui::GTweener",(fgui::GTweener*)ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "fgui::GTweener:setEasePeriod",argc, 1);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_fgui_GTweener_setEasePeriod'.",&tolua_err);
#endif

    return 0;
}
int lua_cocos2dx_fgui_GTweener_isCompleted(lua_State* tolua_S)
{
    int argc = 0;
    fgui::GTweener* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"fgui::GTweener",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (fgui::GTweener*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_fgui_GTweener_isCompleted'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_cocos2dx_fgui_GTweener_isCompleted'", nullptr);
            return 0;
        }
        bool ret = cobj->isCompleted();
        tolua_pushboolean(tolua_S,(bool)ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "fgui::GTweener:isCompleted",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_fgui_GTweener_isCompleted'.",&tolua_err);
#endif

    return 0;
}
int lua_cocos2dx_fgui_GTweener_getNormalizedTime(lua_State* tolua_S)
{
    int argc = 0;
    fgui::GTweener* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"fgui::GTweener",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (fgui::GTweener*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_fgui_GTweener_getNormalizedTime'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_cocos2dx_fgui_GTweener_getNormalizedTime'", nullptr);
            return 0;
        }
        double ret = cobj->getNormalizedTime();
        tolua_pushnumber(tolua_S,(lua_Number)ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "fgui::GTweener:getNormalizedTime",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_fgui_GTweener_getNormalizedTime'.",&tolua_err);
#endif

    return 0;
}
int lua_cocos2dx_fgui_GTweener_setTarget(lua_State* tolua_S)
{
    int argc = 0;
    fgui::GTweener* cobj = nullptr;
    bool ok  = true;
#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif

#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"fgui::GTweener",0,&tolua_err)) goto tolua_lerror;
#endif
    cobj = (fgui::GTweener*)tolua_tousertype(tolua_S,1,0);
#if COCOS2D_DEBUG >= 1
    if (!cobj)
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_fgui_GTweener_setTarget'", nullptr);
        return 0;
    }
#endif
    argc = lua_gettop(tolua_S)-1;
    do{
        if (argc == 2) {
            cocos2d::Ref* arg0;
            ok &= luaval_to_object<cocos2d::Ref>(tolua_S, 2, "cc.Ref",&arg0, "fgui::GTweener:setTarget");

            if (!ok) { break; }
            fgui::TweenPropType arg1;
            ok &= luaval_to_int32(tolua_S, 3,(int *)&arg1, "fgui::GTweener:setTarget");

            if (!ok) { break; }
            fgui::GTweener* ret = cobj->setTarget(arg0, arg1);
            object_to_luaval<fgui::GTweener>(tolua_S, "fgui::GTweener",(fgui::GTweener*)ret);
            return 1;
        }
    }while(0);
    ok  = true;
    do{
        if (argc == 1) {
            cocos2d::Ref* arg0;
            ok &= luaval_to_object<cocos2d::Ref>(tolua_S, 2, "cc.Ref",&arg0, "fgui::GTweener:setTarget");

            if (!ok) { break; }
            fgui::GTweener* ret = cobj->setTarget(arg0);
            object_to_luaval<fgui::GTweener>(tolua_S, "fgui::GTweener",(fgui::GTweener*)ret);
            return 1;
        }
    }while(0);
    ok  = true;
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n",  "fgui::GTweener:setTarget",argc, 1);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_fgui_GTweener_setTarget'.",&tolua_err);
#endif

    return 0;
}
int lua_cocos2dx_fgui_GTweener_setEaseOvershootOrAmplitude(lua_State* tolua_S)
{
    int argc = 0;
    fgui::GTweener* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"fgui::GTweener",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (fgui::GTweener*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_fgui_GTweener_setEaseOvershootOrAmplitude'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 1) 
    {
        double arg0;

        ok &= luaval_to_number(tolua_S, 2,&arg0, "fgui::GTweener:setEaseOvershootOrAmplitude");
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_cocos2dx_fgui_GTweener_setEaseOvershootOrAmplitude'", nullptr);
            return 0;
        }
        fgui::GTweener* ret = cobj->setEaseOvershootOrAmplitude(arg0);
        object_to_luaval<fgui::GTweener>(tolua_S, "fgui::GTweener",(fgui::GTweener*)ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "fgui::GTweener:setEaseOvershootOrAmplitude",argc, 1);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_fgui_GTweener_setEaseOvershootOrAmplitude'.",&tolua_err);
#endif

    return 0;
}
int lua_cocos2dx_fgui_GTweener_setSnapping(lua_State* tolua_S)
{
    int argc = 0;
    fgui::GTweener* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"fgui::GTweener",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (fgui::GTweener*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_fgui_GTweener_setSnapping'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 1) 
    {
        bool arg0;

        ok &= luaval_to_boolean(tolua_S, 2,&arg0, "fgui::GTweener:setSnapping");
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_cocos2dx_fgui_GTweener_setSnapping'", nullptr);
            return 0;
        }
        fgui::GTweener* ret = cobj->setSnapping(arg0);
        object_to_luaval<fgui::GTweener>(tolua_S, "fgui::GTweener",(fgui::GTweener*)ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "fgui::GTweener:setSnapping",argc, 1);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_fgui_GTweener_setSnapping'.",&tolua_err);
#endif

    return 0;
}
int lua_cocos2dx_fgui_GTweener_setTargetAny(lua_State* tolua_S)
{
    int argc = 0;
    fgui::GTweener* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"fgui::GTweener",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (fgui::GTweener*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_fgui_GTweener_setTargetAny'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 1) 
    {
        void* arg0;

        #pragma warning NO CONVERSION TO NATIVE FOR void*
		ok = false;
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_cocos2dx_fgui_GTweener_setTargetAny'", nullptr);
            return 0;
        }
        fgui::GTweener* ret = cobj->setTargetAny(arg0);
        object_to_luaval<fgui::GTweener>(tolua_S, "fgui::GTweener",(fgui::GTweener*)ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "fgui::GTweener:setTargetAny",argc, 1);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_fgui_GTweener_setTargetAny'.",&tolua_err);
#endif

    return 0;
}
int lua_cocos2dx_fgui_GTweener_getDelay(lua_State* tolua_S)
{
    int argc = 0;
    fgui::GTweener* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"fgui::GTweener",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (fgui::GTweener*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_fgui_GTweener_getDelay'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_cocos2dx_fgui_GTweener_getDelay'", nullptr);
            return 0;
        }
        double ret = cobj->getDelay();
        tolua_pushnumber(tolua_S,(lua_Number)ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "fgui::GTweener:getDelay",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_fgui_GTweener_getDelay'.",&tolua_err);
#endif

    return 0;
}
int lua_cocos2dx_fgui_GTweener_setUserData(lua_State* tolua_S)
{
    int argc = 0;
    fgui::GTweener* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"fgui::GTweener",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (fgui::GTweener*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_fgui_GTweener_setUserData'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 1) 
    {
        cocos2d::Value arg0;

        ok &= luaval_to_ccvalue(tolua_S, 2, &arg0, "fgui::GTweener:setUserData");
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_cocos2dx_fgui_GTweener_setUserData'", nullptr);
            return 0;
        }
        fgui::GTweener* ret = cobj->setUserData(arg0);
        object_to_luaval<fgui::GTweener>(tolua_S, "fgui::GTweener",(fgui::GTweener*)ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "fgui::GTweener:setUserData",argc, 1);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_fgui_GTweener_setUserData'.",&tolua_err);
#endif

    return 0;
}
int lua_cocos2dx_fgui_GTweener_toDouble(lua_State* tolua_S)
{
    int argc = 0;
    fgui::GTweener* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"fgui::GTweener",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (fgui::GTweener*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_fgui_GTweener_toDouble'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 3) 
    {
        double arg0;
        double arg1;
        double arg2;

        ok &= luaval_to_number(tolua_S, 2,&arg0, "fgui::GTweener:toDouble");

        ok &= luaval_to_number(tolua_S, 3,&arg1, "fgui::GTweener:toDouble");

        ok &= luaval_to_number(tolua_S, 4,&arg2, "fgui::GTweener:toDouble");
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_cocos2dx_fgui_GTweener_toDouble'", nullptr);
            return 0;
        }
        fgui::GTweener* ret = cobj->toDouble(arg0, arg1, arg2);
        object_to_luaval<fgui::GTweener>(tolua_S, "fgui::GTweener",(fgui::GTweener*)ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "fgui::GTweener:toDouble",argc, 3);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_fgui_GTweener_toDouble'.",&tolua_err);
#endif

    return 0;
}
int lua_cocos2dx_fgui_GTweener_setDuration(lua_State* tolua_S)
{
    int argc = 0;
    fgui::GTweener* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"fgui::GTweener",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (fgui::GTweener*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_fgui_GTweener_setDuration'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 1) 
    {
        double arg0;

        ok &= luaval_to_number(tolua_S, 2,&arg0, "fgui::GTweener:setDuration");
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_cocos2dx_fgui_GTweener_setDuration'", nullptr);
            return 0;
        }
        fgui::GTweener* ret = cobj->setDuration(arg0);
        object_to_luaval<fgui::GTweener>(tolua_S, "fgui::GTweener",(fgui::GTweener*)ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "fgui::GTweener:setDuration",argc, 1);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_fgui_GTweener_setDuration'.",&tolua_err);
#endif

    return 0;
}
int lua_cocos2dx_fgui_GTweener_setPaused(lua_State* tolua_S)
{
    int argc = 0;
    fgui::GTweener* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"fgui::GTweener",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (fgui::GTweener*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_fgui_GTweener_setPaused'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 1) 
    {
        bool arg0;

        ok &= luaval_to_boolean(tolua_S, 2,&arg0, "fgui::GTweener:setPaused");
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_cocos2dx_fgui_GTweener_setPaused'", nullptr);
            return 0;
        }
        fgui::GTweener* ret = cobj->setPaused(arg0);
        object_to_luaval<fgui::GTweener>(tolua_S, "fgui::GTweener",(fgui::GTweener*)ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "fgui::GTweener:setPaused",argc, 1);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_fgui_GTweener_setPaused'.",&tolua_err);
#endif

    return 0;
}
int lua_cocos2dx_fgui_GTweener_constructor(lua_State* tolua_S)
{
    int argc = 0;
    fgui::GTweener* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif



    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_cocos2dx_fgui_GTweener_constructor'", nullptr);
            return 0;
        }
        cobj = new fgui::GTweener();
        cobj->autorelease();
        int ID =  (int)cobj->_ID ;
        int* luaID =  &cobj->_luaID ;
        toluafix_pushusertype_ccobject(tolua_S, ID, luaID, (void*)cobj,"fgui::GTweener");
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "fgui::GTweener:GTweener",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_fgui_GTweener_constructor'.",&tolua_err);
#endif

    return 0;
}

static int lua_cocos2dx_fgui_GTweener_finalize(lua_State* tolua_S)
{
    printf("luabindings: finalizing LUA object (GTweener)");
    return 0;
}

int lua_register_cocos2dx_fgui_GTweener(lua_State* tolua_S)
{
    tolua_usertype(tolua_S,"fgui::GTweener");
    tolua_cclass(tolua_S,"GTweener","fgui::GTweener","cc.Ref",nullptr);

    tolua_beginmodule(tolua_S,"GTweener");
        tolua_function(tolua_S,"new",lua_cocos2dx_fgui_GTweener_constructor);
        tolua_function(tolua_S,"setTimeScale",lua_cocos2dx_fgui_GTweener_setTimeScale);
        tolua_function(tolua_S,"toVec3",lua_cocos2dx_fgui_GTweener_toVec3);
        tolua_function(tolua_S,"toVec2",lua_cocos2dx_fgui_GTweener_toVec2);
        tolua_function(tolua_S,"getRepeat",lua_cocos2dx_fgui_GTweener_getRepeat);
        tolua_function(tolua_S,"setEase",lua_cocos2dx_fgui_GTweener_setEase);
        tolua_function(tolua_S,"getDuration",lua_cocos2dx_fgui_GTweener_getDuration);
        tolua_function(tolua_S,"getTarget",lua_cocos2dx_fgui_GTweener_getTarget);
        tolua_function(tolua_S,"toVec4",lua_cocos2dx_fgui_GTweener_toVec4);
        tolua_function(tolua_S,"kill",lua_cocos2dx_fgui_GTweener_kill);
        tolua_function(tolua_S,"shake",lua_cocos2dx_fgui_GTweener_shake);
        tolua_function(tolua_S,"allCompleted",lua_cocos2dx_fgui_GTweener_allCompleted);
        tolua_function(tolua_S,"seek",lua_cocos2dx_fgui_GTweener_seek);
        tolua_function(tolua_S,"setDelay",lua_cocos2dx_fgui_GTweener_setDelay);
        tolua_function(tolua_S,"toValue",lua_cocos2dx_fgui_GTweener_toValue);
        tolua_function(tolua_S,"getUserData",lua_cocos2dx_fgui_GTweener_getUserData);
        tolua_function(tolua_S,"setRepeat",lua_cocos2dx_fgui_GTweener_setRepeat);
        tolua_function(tolua_S,"setBreakpoint",lua_cocos2dx_fgui_GTweener_setBreakpoint);
        tolua_function(tolua_S,"toColor",lua_cocos2dx_fgui_GTweener_toColor);
        tolua_function(tolua_S,"setEasePeriod",lua_cocos2dx_fgui_GTweener_setEasePeriod);
        tolua_function(tolua_S,"isCompleted",lua_cocos2dx_fgui_GTweener_isCompleted);
        tolua_function(tolua_S,"getNormalizedTime",lua_cocos2dx_fgui_GTweener_getNormalizedTime);
        tolua_function(tolua_S,"setTarget",lua_cocos2dx_fgui_GTweener_setTarget);
        tolua_function(tolua_S,"setEaseOvershootOrAmplitude",lua_cocos2dx_fgui_GTweener_setEaseOvershootOrAmplitude);
        tolua_function(tolua_S,"setSnapping",lua_cocos2dx_fgui_GTweener_setSnapping);
        tolua_function(tolua_S,"setTargetAny",lua_cocos2dx_fgui_GTweener_setTargetAny);
        tolua_function(tolua_S,"getDelay",lua_cocos2dx_fgui_GTweener_getDelay);
        tolua_function(tolua_S,"setUserData",lua_cocos2dx_fgui_GTweener_setUserData);
        tolua_function(tolua_S,"toDouble",lua_cocos2dx_fgui_GTweener_toDouble);
        tolua_function(tolua_S,"setDuration",lua_cocos2dx_fgui_GTweener_setDuration);
        tolua_function(tolua_S,"setPaused",lua_cocos2dx_fgui_GTweener_setPaused);
    tolua_endmodule(tolua_S);
    std::string typeName = typeid(fgui::GTweener).name();
    g_luaType[typeName] = "fgui::GTweener";
    g_typeCast["GTweener"] = "fgui::GTweener";
    return 1;
}

int lua_cocos2dx_fgui_GObject_onEnter(lua_State* tolua_S)
{
    int argc = 0;
    fgui::GObject* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"fgui::GObject",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (fgui::GObject*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_fgui_GObject_onEnter'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_cocos2dx_fgui_GObject_onEnter'", nullptr);
            return 0;
        }
        cobj->onEnter();
        lua_settop(tolua_S, 1);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "fgui::GObject:onEnter",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_fgui_GObject_onEnter'.",&tolua_err);
#endif

    return 0;
}
int lua_cocos2dx_fgui_GObject_setHSVValue(lua_State* tolua_S)
{
    int argc = 0;
    fgui::GObject* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"fgui::GObject",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (fgui::GObject*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_fgui_GObject_setHSVValue'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 4) 
    {
        double arg0;
        double arg1;
        double arg2;
        double arg3;

        ok &= luaval_to_number(tolua_S, 2,&arg0, "fgui::GObject:setHSVValue");

        ok &= luaval_to_number(tolua_S, 3,&arg1, "fgui::GObject:setHSVValue");

        ok &= luaval_to_number(tolua_S, 4,&arg2, "fgui::GObject:setHSVValue");

        ok &= luaval_to_number(tolua_S, 5,&arg3, "fgui::GObject:setHSVValue");
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_cocos2dx_fgui_GObject_setHSVValue'", nullptr);
            return 0;
        }
        cobj->setHSVValue(arg0, arg1, arg2, arg3);
        lua_settop(tolua_S, 1);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "fgui::GObject:setHSVValue",argc, 4);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_fgui_GObject_setHSVValue'.",&tolua_err);
#endif

    return 0;
}
int lua_cocos2dx_fgui_GObject_setHSVMode(lua_State* tolua_S)
{
    int argc = 0;
    fgui::GObject* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"fgui::GObject",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (fgui::GObject*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_fgui_GObject_setHSVMode'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 1) 
    {
        bool arg0;

        ok &= luaval_to_boolean(tolua_S, 2,&arg0, "fgui::GObject:setHSVMode");
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_cocos2dx_fgui_GObject_setHSVMode'", nullptr);
            return 0;
        }
        cobj->setHSVMode(arg0);
        lua_settop(tolua_S, 1);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "fgui::GObject:setHSVMode",argc, 1);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_fgui_GObject_setHSVMode'.",&tolua_err);
#endif

    return 0;
}
int lua_cocos2dx_fgui_GObject_setTouchable(lua_State* tolua_S)
{
    int argc = 0;
    fgui::GObject* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"fgui::GObject",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (fgui::GObject*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_fgui_GObject_setTouchable'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 1) 
    {
        bool arg0;

        ok &= luaval_to_boolean(tolua_S, 2,&arg0, "fgui::GObject:setTouchable");
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_cocos2dx_fgui_GObject_setTouchable'", nullptr);
            return 0;
        }
        cobj->setTouchable(arg0);
        lua_settop(tolua_S, 1);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "fgui::GObject:setTouchable",argc, 1);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_fgui_GObject_setTouchable'.",&tolua_err);
#endif

    return 0;
}
int lua_cocos2dx_fgui_GObject_isGrayed(lua_State* tolua_S)
{
    int argc = 0;
    fgui::GObject* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"fgui::GObject",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (fgui::GObject*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_fgui_GObject_isGrayed'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_cocos2dx_fgui_GObject_isGrayed'", nullptr);
            return 0;
        }
        bool ret = cobj->isGrayed();
        tolua_pushboolean(tolua_S,(bool)ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "fgui::GObject:isGrayed",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_fgui_GObject_isGrayed'.",&tolua_err);
#endif

    return 0;
}
int lua_cocos2dx_fgui_GObject_isSwallowTouch(lua_State* tolua_S)
{
    int argc = 0;
    fgui::GObject* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"fgui::GObject",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (fgui::GObject*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_fgui_GObject_isSwallowTouch'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_cocos2dx_fgui_GObject_isSwallowTouch'", nullptr);
            return 0;
        }
        bool ret = cobj->isSwallowTouch();
        tolua_pushboolean(tolua_S,(bool)ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "fgui::GObject:isSwallowTouch",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_fgui_GObject_isSwallowTouch'.",&tolua_err);
#endif

    return 0;
}
int lua_cocos2dx_fgui_GObject_getId(lua_State* tolua_S)
{
    int argc = 0;
    fgui::GObject* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"fgui::GObject",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (fgui::GObject*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_fgui_GObject_getId'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_cocos2dx_fgui_GObject_getId'", nullptr);
            return 0;
        }
        const std::string& ret = cobj->getId();
        lua_pushlstring(tolua_S,ret.c_str(),ret.length());
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "fgui::GObject:getId",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_fgui_GObject_getId'.",&tolua_err);
#endif

    return 0;
}
int lua_cocos2dx_fgui_GObject_getObjectInfo(lua_State* tolua_S)
{
    int argc = 0;
    fgui::GObject* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"fgui::GObject",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (fgui::GObject*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_fgui_GObject_getObjectInfo'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_cocos2dx_fgui_GObject_getObjectInfo'", nullptr);
            return 0;
        }
        const fgui::ObjectInfo* ret = cobj->getObjectInfo();
        #pragma warning NO CONVERSION FROM NATIVE FOR ObjectInfo*;
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "fgui::GObject:getObjectInfo",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_fgui_GObject_getObjectInfo'.",&tolua_err);
#endif

    return 0;
}
int lua_cocos2dx_fgui_GObject_isTouchable(lua_State* tolua_S)
{
    int argc = 0;
    fgui::GObject* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"fgui::GObject",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (fgui::GObject*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_fgui_GObject_isTouchable'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_cocos2dx_fgui_GObject_isTouchable'", nullptr);
            return 0;
        }
        bool ret = cobj->isTouchable();
        tolua_pushboolean(tolua_S,(bool)ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "fgui::GObject:isTouchable",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_fgui_GObject_isTouchable'.",&tolua_err);
#endif

    return 0;
}
int lua_cocos2dx_fgui_GObject_setSwallowTouch(lua_State* tolua_S)
{
    int argc = 0;
    fgui::GObject* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"fgui::GObject",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (fgui::GObject*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_fgui_GObject_setSwallowTouch'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 1) 
    {
        bool arg0;

        ok &= luaval_to_boolean(tolua_S, 2,&arg0, "fgui::GObject:setSwallowTouch");
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_cocos2dx_fgui_GObject_setSwallowTouch'", nullptr);
            return 0;
        }
        cobj->setSwallowTouch(arg0);
        lua_settop(tolua_S, 1);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "fgui::GObject:setSwallowTouch",argc, 1);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_fgui_GObject_setSwallowTouch'.",&tolua_err);
#endif

    return 0;
}
int lua_cocos2dx_fgui_GObject_getObjType(lua_State* tolua_S)
{
    int argc = 0;
    fgui::GObject* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"fgui::GObject",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (fgui::GObject*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_fgui_GObject_getObjType'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_cocos2dx_fgui_GObject_getObjType'", nullptr);
            return 0;
        }
        int ret = (int)cobj->getObjType();
        tolua_pushnumber(tolua_S,(lua_Number)ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "fgui::GObject:getObjType",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_fgui_GObject_getObjType'.",&tolua_err);
#endif

    return 0;
}
int lua_cocos2dx_fgui_GObject_setBlendMode(lua_State* tolua_S)
{
    int argc = 0;
    fgui::GObject* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"fgui::GObject",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (fgui::GObject*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_fgui_GObject_setBlendMode'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 1) 
    {
        fgui::BlendMode arg0;

        ok &= luaval_to_int32(tolua_S, 2,(int *)&arg0, "fgui::GObject:setBlendMode");
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_cocos2dx_fgui_GObject_setBlendMode'", nullptr);
            return 0;
        }
        cobj->setBlendMode(arg0);
        lua_settop(tolua_S, 1);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "fgui::GObject:setBlendMode",argc, 1);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_fgui_GObject_setBlendMode'.",&tolua_err);
#endif

    return 0;
}
int lua_cocos2dx_fgui_GObject_getHSVValue(lua_State* tolua_S)
{
    int argc = 0;
    fgui::GObject* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"fgui::GObject",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (fgui::GObject*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_fgui_GObject_getHSVValue'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_cocos2dx_fgui_GObject_getHSVValue'", nullptr);
            return 0;
        }
        const cocos2d::Vec4& ret = cobj->getHSVValue();
        vec4_to_luaval(tolua_S, ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "fgui::GObject:getHSVValue",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_fgui_GObject_getHSVValue'.",&tolua_err);
#endif

    return 0;
}
int lua_cocos2dx_fgui_GObject_setGrayed(lua_State* tolua_S)
{
    int argc = 0;
    fgui::GObject* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"fgui::GObject",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (fgui::GObject*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_fgui_GObject_setGrayed'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 1) 
    {
        bool arg0;

        ok &= luaval_to_boolean(tolua_S, 2,&arg0, "fgui::GObject:setGrayed");
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_cocos2dx_fgui_GObject_setGrayed'", nullptr);
            return 0;
        }
        cobj->setGrayed(arg0);
        lua_settop(tolua_S, 1);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "fgui::GObject:setGrayed",argc, 1);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_fgui_GObject_setGrayed'.",&tolua_err);
#endif

    return 0;
}
int lua_cocos2dx_fgui_GObject_addRelationObserver(lua_State* tolua_S)
{
    int argc = 0;
    fgui::GObject* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"fgui::GObject",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (fgui::GObject*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_fgui_GObject_addRelationObserver'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 1) 
    {
        fgui::RelationObserver* arg0;

        ok &= luaval_to_object<fgui::RelationObserver>(tolua_S, 2, "fgui::RelationObserver",&arg0, "fgui::GObject:addRelationObserver");
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_cocos2dx_fgui_GObject_addRelationObserver'", nullptr);
            return 0;
        }
        cobj->addRelationObserver(arg0);
        lua_settop(tolua_S, 1);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "fgui::GObject:addRelationObserver",argc, 1);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_fgui_GObject_addRelationObserver'.",&tolua_err);
#endif

    return 0;
}
int lua_cocos2dx_fgui_GObject_removeRelationObserver(lua_State* tolua_S)
{
    int argc = 0;
    fgui::GObject* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"fgui::GObject",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (fgui::GObject*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_fgui_GObject_removeRelationObserver'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 1) 
    {
        fgui::RelationObserver* arg0;

        ok &= luaval_to_object<fgui::RelationObserver>(tolua_S, 2, "fgui::RelationObserver",&arg0, "fgui::GObject:removeRelationObserver");
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_cocos2dx_fgui_GObject_removeRelationObserver'", nullptr);
            return 0;
        }
        cobj->removeRelationObserver(arg0);
        lua_settop(tolua_S, 1);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "fgui::GObject:removeRelationObserver",argc, 1);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_fgui_GObject_removeRelationObserver'.",&tolua_err);
#endif

    return 0;
}
int lua_cocos2dx_fgui_GObject_onExit(lua_State* tolua_S)
{
    int argc = 0;
    fgui::GObject* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"fgui::GObject",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (fgui::GObject*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_fgui_GObject_onExit'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_cocos2dx_fgui_GObject_onExit'", nullptr);
            return 0;
        }
        cobj->onExit();
        lua_settop(tolua_S, 1);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "fgui::GObject:onExit",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_fgui_GObject_onExit'.",&tolua_err);
#endif

    return 0;
}
int lua_cocos2dx_fgui_GObject_isHSVMode(lua_State* tolua_S)
{
    int argc = 0;
    fgui::GObject* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"fgui::GObject",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (fgui::GObject*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_fgui_GObject_isHSVMode'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_cocos2dx_fgui_GObject_isHSVMode'", nullptr);
            return 0;
        }
        bool ret = cobj->isHSVMode();
        tolua_pushboolean(tolua_S,(bool)ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "fgui::GObject:isHSVMode",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_fgui_GObject_isHSVMode'.",&tolua_err);
#endif

    return 0;
}
int lua_cocos2dx_fgui_GObject_setRelationIsValid(lua_State* tolua_S)
{
    int argc = 0;
    fgui::GObject* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"fgui::GObject",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (fgui::GObject*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_fgui_GObject_setRelationIsValid'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 1) 
    {
        bool arg0;

        ok &= luaval_to_boolean(tolua_S, 2,&arg0, "fgui::GObject:setRelationIsValid");
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_cocos2dx_fgui_GObject_setRelationIsValid'", nullptr);
            return 0;
        }
        cobj->setRelationIsValid(arg0);
        lua_settop(tolua_S, 1);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "fgui::GObject:setRelationIsValid",argc, 1);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_fgui_GObject_setRelationIsValid'.",&tolua_err);
#endif

    return 0;
}
int lua_cocos2dx_fgui_GObject_getBlendMode(lua_State* tolua_S)
{
    int argc = 0;
    fgui::GObject* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"fgui::GObject",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (fgui::GObject*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_fgui_GObject_getBlendMode'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_cocos2dx_fgui_GObject_getBlendMode'", nullptr);
            return 0;
        }
        int ret = (int)cobj->getBlendMode();
        tolua_pushnumber(tolua_S,(lua_Number)ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "fgui::GObject:getBlendMode",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_fgui_GObject_getBlendMode'.",&tolua_err);
#endif

    return 0;
}
int lua_cocos2dx_fgui_GObject_setupOverflow(lua_State* tolua_S)
{
    int argc = 0;
    fgui::GObject* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"fgui::GObject",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (fgui::GObject*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_fgui_GObject_setupOverflow'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 1) 
    {
        fgui::OverflowType arg0;

        ok &= luaval_to_int32(tolua_S, 2,(int *)&arg0, "fgui::GObject:setupOverflow");
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_cocos2dx_fgui_GObject_setupOverflow'", nullptr);
            return 0;
        }
        cobj->setupOverflow(arg0);
        lua_settop(tolua_S, 1);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "fgui::GObject:setupOverflow",argc, 1);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_fgui_GObject_setupOverflow'.",&tolua_err);
#endif

    return 0;
}
static int lua_cocos2dx_fgui_GObject_finalize(lua_State* tolua_S)
{
    printf("luabindings: finalizing LUA object (GObject)");
    return 0;
}

int lua_register_cocos2dx_fgui_GObject(lua_State* tolua_S)
{
    tolua_usertype(tolua_S,"fgui::GObject");
    tolua_cclass(tolua_S,"GObject","fgui::GObject","",nullptr);

    tolua_beginmodule(tolua_S,"GObject");
        tolua_function(tolua_S,"onEnter",lua_cocos2dx_fgui_GObject_onEnter);
        tolua_function(tolua_S,"setHSVValue",lua_cocos2dx_fgui_GObject_setHSVValue);
        tolua_function(tolua_S,"setHSVMode",lua_cocos2dx_fgui_GObject_setHSVMode);
        tolua_function(tolua_S,"setTouchable",lua_cocos2dx_fgui_GObject_setTouchable);
        tolua_function(tolua_S,"isGrayed",lua_cocos2dx_fgui_GObject_isGrayed);
        tolua_function(tolua_S,"isSwallowTouch",lua_cocos2dx_fgui_GObject_isSwallowTouch);
        tolua_function(tolua_S,"getId",lua_cocos2dx_fgui_GObject_getId);
        tolua_function(tolua_S,"getObjectInfo",lua_cocos2dx_fgui_GObject_getObjectInfo);
        tolua_function(tolua_S,"isTouchable",lua_cocos2dx_fgui_GObject_isTouchable);
        tolua_function(tolua_S,"setSwallowTouch",lua_cocos2dx_fgui_GObject_setSwallowTouch);
        tolua_function(tolua_S,"getObjType",lua_cocos2dx_fgui_GObject_getObjType);
        tolua_function(tolua_S,"setBlendMode",lua_cocos2dx_fgui_GObject_setBlendMode);
        tolua_function(tolua_S,"getHSVValue",lua_cocos2dx_fgui_GObject_getHSVValue);
        tolua_function(tolua_S,"setGrayed",lua_cocos2dx_fgui_GObject_setGrayed);
        tolua_function(tolua_S,"addRelationObserver",lua_cocos2dx_fgui_GObject_addRelationObserver);
        tolua_function(tolua_S,"removeRelationObserver",lua_cocos2dx_fgui_GObject_removeRelationObserver);
        tolua_function(tolua_S,"onExit",lua_cocos2dx_fgui_GObject_onExit);
        tolua_function(tolua_S,"isHSVMode",lua_cocos2dx_fgui_GObject_isHSVMode);
        tolua_function(tolua_S,"setRelationIsValid",lua_cocos2dx_fgui_GObject_setRelationIsValid);
        tolua_function(tolua_S,"getBlendMode",lua_cocos2dx_fgui_GObject_getBlendMode);
        tolua_function(tolua_S,"setupOverflow",lua_cocos2dx_fgui_GObject_setupOverflow);
    tolua_endmodule(tolua_S);
    std::string typeName = typeid(fgui::GObject).name();
    g_luaType[typeName] = "fgui::GObject";
    g_typeCast["GObject"] = "fgui::GObject";
    return 1;
}

int lua_cocos2dx_fgui_TextFormat_hasEffect(lua_State* tolua_S)
{
    int argc = 0;
    fgui::TextFormat* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"fgui::TextFormat",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (fgui::TextFormat*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_fgui_TextFormat_hasEffect'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 1) 
    {
        int arg0;

        ok &= luaval_to_int32(tolua_S, 2,(int *)&arg0, "fgui::TextFormat:hasEffect");
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_cocos2dx_fgui_TextFormat_hasEffect'", nullptr);
            return 0;
        }
        bool ret = cobj->hasEffect(arg0);
        tolua_pushboolean(tolua_S,(bool)ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "fgui::TextFormat:hasEffect",argc, 1);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_fgui_TextFormat_hasEffect'.",&tolua_err);
#endif

    return 0;
}
int lua_cocos2dx_fgui_TextFormat_enableEffect(lua_State* tolua_S)
{
    int argc = 0;
    fgui::TextFormat* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"fgui::TextFormat",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (fgui::TextFormat*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_fgui_TextFormat_enableEffect'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 1) 
    {
        int arg0;

        ok &= luaval_to_int32(tolua_S, 2,(int *)&arg0, "fgui::TextFormat:enableEffect");
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_cocos2dx_fgui_TextFormat_enableEffect'", nullptr);
            return 0;
        }
        cobj->enableEffect(arg0);
        lua_settop(tolua_S, 1);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "fgui::TextFormat:enableEffect",argc, 1);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_fgui_TextFormat_enableEffect'.",&tolua_err);
#endif

    return 0;
}
int lua_cocos2dx_fgui_TextFormat_disableEffect(lua_State* tolua_S)
{
    int argc = 0;
    fgui::TextFormat* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"fgui::TextFormat",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (fgui::TextFormat*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_fgui_TextFormat_disableEffect'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 1) 
    {
        int arg0;

        ok &= luaval_to_int32(tolua_S, 2,(int *)&arg0, "fgui::TextFormat:disableEffect");
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_cocos2dx_fgui_TextFormat_disableEffect'", nullptr);
            return 0;
        }
        cobj->disableEffect(arg0);
        lua_settop(tolua_S, 1);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "fgui::TextFormat:disableEffect",argc, 1);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_fgui_TextFormat_disableEffect'.",&tolua_err);
#endif

    return 0;
}
int lua_cocos2dx_fgui_TextFormat_constructor(lua_State* tolua_S)
{
    int argc = 0;
    fgui::TextFormat* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif



    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_cocos2dx_fgui_TextFormat_constructor'", nullptr);
            return 0;
        }
        cobj = new fgui::TextFormat();
        cobj->autorelease();
        int ID =  (int)cobj->_ID ;
        int* luaID =  &cobj->_luaID ;
        toluafix_pushusertype_ccobject(tolua_S, ID, luaID, (void*)cobj,"fgui::TextFormat");
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "fgui::TextFormat:TextFormat",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_fgui_TextFormat_constructor'.",&tolua_err);
#endif

    return 0;
}

static int lua_cocos2dx_fgui_TextFormat_finalize(lua_State* tolua_S)
{
    printf("luabindings: finalizing LUA object (TextFormat)");
    return 0;
}

int lua_register_cocos2dx_fgui_TextFormat(lua_State* tolua_S)
{
    tolua_usertype(tolua_S,"fgui::TextFormat");
    tolua_cclass(tolua_S,"TextFormat","fgui::TextFormat","cc.Ref",nullptr);

    tolua_beginmodule(tolua_S,"TextFormat");
        tolua_function(tolua_S,"new",lua_cocos2dx_fgui_TextFormat_constructor);
        tolua_function(tolua_S,"hasEffect",lua_cocos2dx_fgui_TextFormat_hasEffect);
        tolua_function(tolua_S,"enableEffect",lua_cocos2dx_fgui_TextFormat_enableEffect);
        tolua_function(tolua_S,"disableEffect",lua_cocos2dx_fgui_TextFormat_disableEffect);
    tolua_endmodule(tolua_S);
    std::string typeName = typeid(fgui::TextFormat).name();
    g_luaType[typeName] = "fgui::TextFormat";
    g_typeCast["TextFormat"] = "fgui::TextFormat";
    return 1;
}

int lua_cocos2dx_fgui_TweenManager_getTween(lua_State* tolua_S)
{
    int argc = 0;
    fgui::TweenManager* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"fgui::TweenManager",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (fgui::TweenManager*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_fgui_TweenManager_getTween'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 2) 
    {
        cocos2d::Ref* arg0;
        fgui::TweenPropType arg1;

        ok &= luaval_to_object<cocos2d::Ref>(tolua_S, 2, "cc.Ref",&arg0, "fgui::TweenManager:getTween");

        ok &= luaval_to_int32(tolua_S, 3,(int *)&arg1, "fgui::TweenManager:getTween");
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_cocos2dx_fgui_TweenManager_getTween'", nullptr);
            return 0;
        }
        fgui::GTweener* ret = cobj->getTween(arg0, arg1);
        object_to_luaval<fgui::GTweener>(tolua_S, "fgui::GTweener",(fgui::GTweener*)ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "fgui::TweenManager:getTween",argc, 2);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_fgui_TweenManager_getTween'.",&tolua_err);
#endif

    return 0;
}
int lua_cocos2dx_fgui_TweenManager_clean(lua_State* tolua_S)
{
    int argc = 0;
    fgui::TweenManager* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"fgui::TweenManager",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (fgui::TweenManager*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_fgui_TweenManager_clean'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_cocos2dx_fgui_TweenManager_clean'", nullptr);
            return 0;
        }
        cobj->clean();
        lua_settop(tolua_S, 1);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "fgui::TweenManager:clean",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_fgui_TweenManager_clean'.",&tolua_err);
#endif

    return 0;
}
int lua_cocos2dx_fgui_TweenManager_update(lua_State* tolua_S)
{
    int argc = 0;
    fgui::TweenManager* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"fgui::TweenManager",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (fgui::TweenManager*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_fgui_TweenManager_update'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 1) 
    {
        double arg0;

        ok &= luaval_to_number(tolua_S, 2,&arg0, "fgui::TweenManager:update");
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_cocos2dx_fgui_TweenManager_update'", nullptr);
            return 0;
        }
        cobj->update(arg0);
        lua_settop(tolua_S, 1);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "fgui::TweenManager:update",argc, 1);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_fgui_TweenManager_update'.",&tolua_err);
#endif

    return 0;
}
int lua_cocos2dx_fgui_TweenManager_isTweening(lua_State* tolua_S)
{
    int argc = 0;
    fgui::TweenManager* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"fgui::TweenManager",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (fgui::TweenManager*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_fgui_TweenManager_isTweening'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 2) 
    {
        cocos2d::Ref* arg0;
        fgui::TweenPropType arg1;

        ok &= luaval_to_object<cocos2d::Ref>(tolua_S, 2, "cc.Ref",&arg0, "fgui::TweenManager:isTweening");

        ok &= luaval_to_int32(tolua_S, 3,(int *)&arg1, "fgui::TweenManager:isTweening");
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_cocos2dx_fgui_TweenManager_isTweening'", nullptr);
            return 0;
        }
        bool ret = cobj->isTweening(arg0, arg1);
        tolua_pushboolean(tolua_S,(bool)ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "fgui::TweenManager:isTweening",argc, 2);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_fgui_TweenManager_isTweening'.",&tolua_err);
#endif

    return 0;
}
int lua_cocos2dx_fgui_TweenManager_init(lua_State* tolua_S)
{
    int argc = 0;
    fgui::TweenManager* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"fgui::TweenManager",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (fgui::TweenManager*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_fgui_TweenManager_init'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_cocos2dx_fgui_TweenManager_init'", nullptr);
            return 0;
        }
        cobj->init();
        lua_settop(tolua_S, 1);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "fgui::TweenManager:init",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_fgui_TweenManager_init'.",&tolua_err);
#endif

    return 0;
}
int lua_cocos2dx_fgui_TweenManager_killTweens(lua_State* tolua_S)
{
    int argc = 0;
    fgui::TweenManager* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"fgui::TweenManager",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (fgui::TweenManager*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_fgui_TweenManager_killTweens'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 3) 
    {
        cocos2d::Ref* arg0;
        fgui::TweenPropType arg1;
        bool arg2;

        ok &= luaval_to_object<cocos2d::Ref>(tolua_S, 2, "cc.Ref",&arg0, "fgui::TweenManager:killTweens");

        ok &= luaval_to_int32(tolua_S, 3,(int *)&arg1, "fgui::TweenManager:killTweens");

        ok &= luaval_to_boolean(tolua_S, 4,&arg2, "fgui::TweenManager:killTweens");
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_cocos2dx_fgui_TweenManager_killTweens'", nullptr);
            return 0;
        }
        bool ret = cobj->killTweens(arg0, arg1, arg2);
        tolua_pushboolean(tolua_S,(bool)ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "fgui::TweenManager:killTweens",argc, 3);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_fgui_TweenManager_killTweens'.",&tolua_err);
#endif

    return 0;
}
int lua_cocos2dx_fgui_TweenManager_createTween(lua_State* tolua_S)
{
    int argc = 0;
    fgui::TweenManager* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"fgui::TweenManager",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (fgui::TweenManager*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_fgui_TweenManager_createTween'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_cocos2dx_fgui_TweenManager_createTween'", nullptr);
            return 0;
        }
        fgui::GTweener* ret = cobj->createTween();
        object_to_luaval<fgui::GTweener>(tolua_S, "fgui::GTweener",(fgui::GTweener*)ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "fgui::TweenManager:createTween",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_fgui_TweenManager_createTween'.",&tolua_err);
#endif

    return 0;
}
int lua_cocos2dx_fgui_TweenManager_getInstance(lua_State* tolua_S)
{
    int argc = 0;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif

#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertable(tolua_S,1,"fgui::TweenManager",0,&tolua_err)) goto tolua_lerror;
#endif

    argc = lua_gettop(tolua_S) - 1;

    if (argc == 0)
    {
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_cocos2dx_fgui_TweenManager_getInstance'", nullptr);
            return 0;
        }
        fgui::TweenManager* ret = fgui::TweenManager::getInstance();
        object_to_luaval<fgui::TweenManager>(tolua_S, "fgui::TweenManager",(fgui::TweenManager*)ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d\n ", "fgui::TweenManager:getInstance",argc, 0);
    return 0;
#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_fgui_TweenManager_getInstance'.",&tolua_err);
#endif
    return 0;
}
static int lua_cocos2dx_fgui_TweenManager_finalize(lua_State* tolua_S)
{
    printf("luabindings: finalizing LUA object (TweenManager)");
    return 0;
}

int lua_register_cocos2dx_fgui_TweenManager(lua_State* tolua_S)
{
    tolua_usertype(tolua_S,"fgui::TweenManager");
    tolua_cclass(tolua_S,"TweenManager","fgui::TweenManager","",nullptr);

    tolua_beginmodule(tolua_S,"TweenManager");
        tolua_function(tolua_S,"getTween",lua_cocos2dx_fgui_TweenManager_getTween);
        tolua_function(tolua_S,"clean",lua_cocos2dx_fgui_TweenManager_clean);
        tolua_function(tolua_S,"update",lua_cocos2dx_fgui_TweenManager_update);
        tolua_function(tolua_S,"isTweening",lua_cocos2dx_fgui_TweenManager_isTweening);
        tolua_function(tolua_S,"init",lua_cocos2dx_fgui_TweenManager_init);
        tolua_function(tolua_S,"killTweens",lua_cocos2dx_fgui_TweenManager_killTweens);
        tolua_function(tolua_S,"createTween",lua_cocos2dx_fgui_TweenManager_createTween);
        tolua_function(tolua_S,"getInstance", lua_cocos2dx_fgui_TweenManager_getInstance);
    tolua_endmodule(tolua_S);
    std::string typeName = typeid(fgui::TweenManager).name();
    g_luaType[typeName] = "fgui::TweenManager";
    g_typeCast["TweenManager"] = "fgui::TweenManager";
    return 1;
}

int lua_cocos2dx_fgui_GContainer_addChild(lua_State* tolua_S)
{
    int argc = 0;
    fgui::GContainer* cobj = nullptr;
    bool ok  = true;
#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif

#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"fgui::GContainer",0,&tolua_err)) goto tolua_lerror;
#endif
    cobj = (fgui::GContainer*)tolua_tousertype(tolua_S,1,0);
#if COCOS2D_DEBUG >= 1
    if (!cobj)
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_fgui_GContainer_addChild'", nullptr);
        return 0;
    }
#endif
    argc = lua_gettop(tolua_S)-1;
    do{
        if (argc == 3) {
            cocos2d::Node* arg0;
            ok &= luaval_to_object<cocos2d::Node>(tolua_S, 2, "cc.Node",&arg0, "fgui::GContainer:addChild");

            if (!ok) { break; }
            int arg1;
            ok &= luaval_to_int32(tolua_S, 3,(int *)&arg1, "fgui::GContainer:addChild");

            if (!ok) { break; }
            int arg2;
            ok &= luaval_to_int32(tolua_S, 4,(int *)&arg2, "fgui::GContainer:addChild");

            if (!ok) { break; }
            cobj->addChild(arg0, arg1, arg2);
            lua_settop(tolua_S, 1);
            return 1;
        }
    }while(0);
    ok  = true;
    do{
        if (argc == 3) {
            cocos2d::Node* arg0;
            ok &= luaval_to_object<cocos2d::Node>(tolua_S, 2, "cc.Node",&arg0, "fgui::GContainer:addChild");

            if (!ok) { break; }
            int arg1;
            ok &= luaval_to_int32(tolua_S, 3,(int *)&arg1, "fgui::GContainer:addChild");

            if (!ok) { break; }
            std::string arg2;
            ok &= luaval_to_std_string(tolua_S, 4,&arg2, "fgui::GContainer:addChild");

            if (!ok) { break; }
            cobj->addChild(arg0, arg1, arg2);
            lua_settop(tolua_S, 1);
            return 1;
        }
    }while(0);
    ok  = true;
    do{
        if (argc == 2) {
            cocos2d::Node* arg0;
            ok &= luaval_to_object<cocos2d::Node>(tolua_S, 2, "cc.Node",&arg0, "fgui::GContainer:addChild");

            if (!ok) { break; }
            int arg1;
            ok &= luaval_to_int32(tolua_S, 3,(int *)&arg1, "fgui::GContainer:addChild");

            if (!ok) { break; }
            cobj->addChild(arg0, arg1);
            lua_settop(tolua_S, 1);
            return 1;
        }
    }while(0);
    ok  = true;
    do{
        if (argc == 1) {
            cocos2d::Node* arg0;
            ok &= luaval_to_object<cocos2d::Node>(tolua_S, 2, "cc.Node",&arg0, "fgui::GContainer:addChild");

            if (!ok) { break; }
            cobj->addChild(arg0);
            lua_settop(tolua_S, 1);
            return 1;
        }
    }while(0);
    ok  = true;
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n",  "fgui::GContainer:addChild",argc, 1);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_fgui_GContainer_addChild'.",&tolua_err);
#endif

    return 0;
}
int lua_cocos2dx_fgui_GContainer_getColumnGap(lua_State* tolua_S)
{
    int argc = 0;
    fgui::GContainer* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"fgui::GContainer",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (fgui::GContainer*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_fgui_GContainer_getColumnGap'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_cocos2dx_fgui_GContainer_getColumnGap'", nullptr);
            return 0;
        }
        int ret = cobj->getColumnGap();
        tolua_pushnumber(tolua_S,(lua_Number)ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "fgui::GContainer:getColumnGap",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_fgui_GContainer_getColumnGap'.",&tolua_err);
#endif

    return 0;
}
int lua_cocos2dx_fgui_GContainer_getLineCount(lua_State* tolua_S)
{
    int argc = 0;
    fgui::GContainer* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"fgui::GContainer",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (fgui::GContainer*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_fgui_GContainer_getLineCount'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_cocos2dx_fgui_GContainer_getLineCount'", nullptr);
            return 0;
        }
        int ret = cobj->getLineCount();
        tolua_pushnumber(tolua_S,(lua_Number)ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "fgui::GContainer:getLineCount",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_fgui_GContainer_getLineCount'.",&tolua_err);
#endif

    return 0;
}
int lua_cocos2dx_fgui_GContainer_updateCommonLayout(lua_State* tolua_S)
{
    int argc = 0;
    fgui::GContainer* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"fgui::GContainer",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (fgui::GContainer*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_fgui_GContainer_updateCommonLayout'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_cocos2dx_fgui_GContainer_updateCommonLayout'", nullptr);
            return 0;
        }
        cobj->updateCommonLayout();
        lua_settop(tolua_S, 1);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "fgui::GContainer:updateCommonLayout",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_fgui_GContainer_updateCommonLayout'.",&tolua_err);
#endif

    return 0;
}
int lua_cocos2dx_fgui_GContainer_visit(lua_State* tolua_S)
{
    int argc = 0;
    fgui::GContainer* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"fgui::GContainer",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (fgui::GContainer*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_fgui_GContainer_visit'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 3) 
    {
        cocos2d::Renderer* arg0;
        cocos2d::Mat4 arg1;
        unsigned int arg2;

        ok &= luaval_to_object<cocos2d::Renderer>(tolua_S, 2, "cc.Renderer",&arg0, "fgui::GContainer:visit");

        ok &= luaval_to_mat4(tolua_S, 3, &arg1, "fgui::GContainer:visit");

        ok &= luaval_to_uint32(tolua_S, 4,&arg2, "fgui::GContainer:visit");
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_cocos2dx_fgui_GContainer_visit'", nullptr);
            return 0;
        }
        cobj->visit(arg0, arg1, arg2);
        lua_settop(tolua_S, 1);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "fgui::GContainer:visit",argc, 3);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_fgui_GContainer_visit'.",&tolua_err);
#endif

    return 0;
}
int lua_cocos2dx_fgui_GContainer_setColumnGap(lua_State* tolua_S)
{
    int argc = 0;
    fgui::GContainer* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"fgui::GContainer",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (fgui::GContainer*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_fgui_GContainer_setColumnGap'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 1) 
    {
        int arg0;

        ok &= luaval_to_int32(tolua_S, 2,(int *)&arg0, "fgui::GContainer:setColumnGap");
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_cocos2dx_fgui_GContainer_setColumnGap'", nullptr);
            return 0;
        }
        cobj->setColumnGap(arg0);
        lua_settop(tolua_S, 1);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "fgui::GContainer:setColumnGap",argc, 1);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_fgui_GContainer_setColumnGap'.",&tolua_err);
#endif

    return 0;
}
int lua_cocos2dx_fgui_GContainer_getColumnCount(lua_State* tolua_S)
{
    int argc = 0;
    fgui::GContainer* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"fgui::GContainer",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (fgui::GContainer*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_fgui_GContainer_getColumnCount'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_cocos2dx_fgui_GContainer_getColumnCount'", nullptr);
            return 0;
        }
        int ret = cobj->getColumnCount();
        tolua_pushnumber(tolua_S,(lua_Number)ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "fgui::GContainer:getColumnCount",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_fgui_GContainer_getColumnCount'.",&tolua_err);
#endif

    return 0;
}
int lua_cocos2dx_fgui_GContainer_setVirtual(lua_State* tolua_S)
{
    int argc = 0;
    fgui::GContainer* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"fgui::GContainer",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (fgui::GContainer*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_fgui_GContainer_setVirtual'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_cocos2dx_fgui_GContainer_setVirtual'", nullptr);
            return 0;
        }
        cobj->setVirtual();
        lua_settop(tolua_S, 1);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "fgui::GContainer:setVirtual",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_fgui_GContainer_setVirtual'.",&tolua_err);
#endif

    return 0;
}
int lua_cocos2dx_fgui_GContainer_getEdgeRectangle(lua_State* tolua_S)
{
    int argc = 0;
    fgui::GContainer* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"fgui::GContainer",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (fgui::GContainer*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_fgui_GContainer_getEdgeRectangle'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_cocos2dx_fgui_GContainer_getEdgeRectangle'", nullptr);
            return 0;
        }
        const cocos2d::Rect& ret = cobj->getEdgeRectangle();
        rect_to_luaval(tolua_S, ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "fgui::GContainer:getEdgeRectangle",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_fgui_GContainer_getEdgeRectangle'.",&tolua_err);
#endif

    return 0;
}
int lua_cocos2dx_fgui_GContainer_setColumnCount(lua_State* tolua_S)
{
    int argc = 0;
    fgui::GContainer* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"fgui::GContainer",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (fgui::GContainer*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_fgui_GContainer_setColumnCount'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 1) 
    {
        int arg0;

        ok &= luaval_to_int32(tolua_S, 2,(int *)&arg0, "fgui::GContainer:setColumnCount");
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_cocos2dx_fgui_GContainer_setColumnCount'", nullptr);
            return 0;
        }
        cobj->setColumnCount(arg0);
        lua_settop(tolua_S, 1);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "fgui::GContainer:setColumnCount",argc, 1);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_fgui_GContainer_setColumnCount'.",&tolua_err);
#endif

    return 0;
}
int lua_cocos2dx_fgui_GContainer_getVAlignment(lua_State* tolua_S)
{
    int argc = 0;
    fgui::GContainer* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"fgui::GContainer",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (fgui::GContainer*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_fgui_GContainer_getVAlignment'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_cocos2dx_fgui_GContainer_getVAlignment'", nullptr);
            return 0;
        }
        int ret = (int)cobj->getVAlignment();
        tolua_pushnumber(tolua_S,(lua_Number)ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "fgui::GContainer:getVAlignment",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_fgui_GContainer_getVAlignment'.",&tolua_err);
#endif

    return 0;
}
int lua_cocos2dx_fgui_GContainer_init(lua_State* tolua_S)
{
    int argc = 0;
    fgui::GContainer* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"fgui::GContainer",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (fgui::GContainer*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_fgui_GContainer_init'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_cocos2dx_fgui_GContainer_init'", nullptr);
            return 0;
        }
        bool ret = cobj->init();
        tolua_pushboolean(tolua_S,(bool)ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "fgui::GContainer:init",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_fgui_GContainer_init'.",&tolua_err);
#endif

    return 0;
}
int lua_cocos2dx_fgui_GContainer_setHAlignment(lua_State* tolua_S)
{
    int argc = 0;
    fgui::GContainer* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"fgui::GContainer",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (fgui::GContainer*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_fgui_GContainer_setHAlignment'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 1) 
    {
        cocos2d::TextHAlignment arg0;

        ok &= luaval_to_int32(tolua_S, 2,(int *)&arg0, "fgui::GContainer:setHAlignment");
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_cocos2dx_fgui_GContainer_setHAlignment'", nullptr);
            return 0;
        }
        cobj->setHAlignment(arg0);
        lua_settop(tolua_S, 1);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "fgui::GContainer:setHAlignment",argc, 1);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_fgui_GContainer_setHAlignment'.",&tolua_err);
#endif

    return 0;
}
int lua_cocos2dx_fgui_GContainer_setLineCount(lua_State* tolua_S)
{
    int argc = 0;
    fgui::GContainer* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"fgui::GContainer",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (fgui::GContainer*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_fgui_GContainer_setLineCount'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 1) 
    {
        int arg0;

        ok &= luaval_to_int32(tolua_S, 2,(int *)&arg0, "fgui::GContainer:setLineCount");
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_cocos2dx_fgui_GContainer_setLineCount'", nullptr);
            return 0;
        }
        cobj->setLineCount(arg0);
        lua_settop(tolua_S, 1);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "fgui::GContainer:setLineCount",argc, 1);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_fgui_GContainer_setLineCount'.",&tolua_err);
#endif

    return 0;
}
int lua_cocos2dx_fgui_GContainer_clearAllChildren(lua_State* tolua_S)
{
    int argc = 0;
    fgui::GContainer* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"fgui::GContainer",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (fgui::GContainer*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_fgui_GContainer_clearAllChildren'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_cocos2dx_fgui_GContainer_clearAllChildren'", nullptr);
            return 0;
        }
        cobj->clearAllChildren();
        lua_settop(tolua_S, 1);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "fgui::GContainer:clearAllChildren",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_fgui_GContainer_clearAllChildren'.",&tolua_err);
#endif

    return 0;
}
int lua_cocos2dx_fgui_GContainer_setVirtualItemCount(lua_State* tolua_S)
{
    int argc = 0;
    fgui::GContainer* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"fgui::GContainer",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (fgui::GContainer*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_fgui_GContainer_setVirtualItemCount'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 1) 
    {
        int arg0;

        ok &= luaval_to_int32(tolua_S, 2,(int *)&arg0, "fgui::GContainer:setVirtualItemCount");
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_cocos2dx_fgui_GContainer_setVirtualItemCount'", nullptr);
            return 0;
        }
        cobj->setVirtualItemCount(arg0);
        lua_settop(tolua_S, 1);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "fgui::GContainer:setVirtualItemCount",argc, 1);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_fgui_GContainer_setVirtualItemCount'.",&tolua_err);
#endif

    return 0;
}
int lua_cocos2dx_fgui_GContainer_isVirtual(lua_State* tolua_S)
{
    int argc = 0;
    fgui::GContainer* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"fgui::GContainer",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (fgui::GContainer*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_fgui_GContainer_isVirtual'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_cocos2dx_fgui_GContainer_isVirtual'", nullptr);
            return 0;
        }
        bool ret = cobj->isVirtual();
        tolua_pushboolean(tolua_S,(bool)ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "fgui::GContainer:isVirtual",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_fgui_GContainer_isVirtual'.",&tolua_err);
#endif

    return 0;
}
int lua_cocos2dx_fgui_GContainer_getLayoutType(lua_State* tolua_S)
{
    int argc = 0;
    fgui::GContainer* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"fgui::GContainer",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (fgui::GContainer*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_fgui_GContainer_getLayoutType'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_cocos2dx_fgui_GContainer_getLayoutType'", nullptr);
            return 0;
        }
        int ret = (int)cobj->getLayoutType();
        tolua_pushnumber(tolua_S,(lua_Number)ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "fgui::GContainer:getLayoutType",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_fgui_GContainer_getLayoutType'.",&tolua_err);
#endif

    return 0;
}
int lua_cocos2dx_fgui_GContainer_setMargin(lua_State* tolua_S)
{
    int argc = 0;
    fgui::GContainer* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"fgui::GContainer",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (fgui::GContainer*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_fgui_GContainer_setMargin'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 1) 
    {
        fgui::Margin arg0;

        ok &= luaval_to_fgui_margin(tolua_S, 2,&arg0, "fgui::GContainer:setMargin");
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_cocos2dx_fgui_GContainer_setMargin'", nullptr);
            return 0;
        }
        cobj->setMargin(arg0);
        lua_settop(tolua_S, 1);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "fgui::GContainer:setMargin",argc, 1);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_fgui_GContainer_setMargin'.",&tolua_err);
#endif

    return 0;
}
int lua_cocos2dx_fgui_GContainer_getLineGap(lua_State* tolua_S)
{
    int argc = 0;
    fgui::GContainer* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"fgui::GContainer",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (fgui::GContainer*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_fgui_GContainer_getLineGap'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_cocos2dx_fgui_GContainer_getLineGap'", nullptr);
            return 0;
        }
        int ret = cobj->getLineGap();
        tolua_pushnumber(tolua_S,(lua_Number)ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "fgui::GContainer:getLineGap",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_fgui_GContainer_getLineGap'.",&tolua_err);
#endif

    return 0;
}
int lua_cocos2dx_fgui_GContainer_getVirtualItemCount(lua_State* tolua_S)
{
    int argc = 0;
    fgui::GContainer* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"fgui::GContainer",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (fgui::GContainer*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_fgui_GContainer_getVirtualItemCount'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_cocos2dx_fgui_GContainer_getVirtualItemCount'", nullptr);
            return 0;
        }
        int ret = cobj->getVirtualItemCount();
        tolua_pushnumber(tolua_S,(lua_Number)ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "fgui::GContainer:getVirtualItemCount",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_fgui_GContainer_getVirtualItemCount'.",&tolua_err);
#endif

    return 0;
}
int lua_cocos2dx_fgui_GContainer_getHAlignment(lua_State* tolua_S)
{
    int argc = 0;
    fgui::GContainer* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"fgui::GContainer",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (fgui::GContainer*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_fgui_GContainer_getHAlignment'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_cocos2dx_fgui_GContainer_getHAlignment'", nullptr);
            return 0;
        }
        int ret = (int)cobj->getHAlignment();
        tolua_pushnumber(tolua_S,(lua_Number)ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "fgui::GContainer:getHAlignment",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_fgui_GContainer_getHAlignment'.",&tolua_err);
#endif

    return 0;
}
int lua_cocos2dx_fgui_GContainer_setContentSize(lua_State* tolua_S)
{
    int argc = 0;
    fgui::GContainer* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"fgui::GContainer",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (fgui::GContainer*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_fgui_GContainer_setContentSize'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 1) 
    {
        cocos2d::Size arg0;

        ok &= luaval_to_size(tolua_S, 2, &arg0, "fgui::GContainer:setContentSize");
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_cocos2dx_fgui_GContainer_setContentSize'", nullptr);
            return 0;
        }
        cobj->setContentSize(arg0);
        lua_settop(tolua_S, 1);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "fgui::GContainer:setContentSize",argc, 1);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_fgui_GContainer_setContentSize'.",&tolua_err);
#endif

    return 0;
}
int lua_cocos2dx_fgui_GContainer_setVAlignment(lua_State* tolua_S)
{
    int argc = 0;
    fgui::GContainer* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"fgui::GContainer",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (fgui::GContainer*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_fgui_GContainer_setVAlignment'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 1) 
    {
        cocos2d::TextVAlignment arg0;

        ok &= luaval_to_int32(tolua_S, 2,(int *)&arg0, "fgui::GContainer:setVAlignment");
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_cocos2dx_fgui_GContainer_setVAlignment'", nullptr);
            return 0;
        }
        cobj->setVAlignment(arg0);
        lua_settop(tolua_S, 1);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "fgui::GContainer:setVAlignment",argc, 1);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_fgui_GContainer_setVAlignment'.",&tolua_err);
#endif

    return 0;
}
int lua_cocos2dx_fgui_GContainer_updateVirtualLayout(lua_State* tolua_S)
{
    int argc = 0;
    fgui::GContainer* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"fgui::GContainer",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (fgui::GContainer*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_fgui_GContainer_updateVirtualLayout'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_cocos2dx_fgui_GContainer_updateVirtualLayout'", nullptr);
            return 0;
        }
        cobj->updateVirtualLayout();
        lua_settop(tolua_S, 1);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "fgui::GContainer:updateVirtualLayout",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_fgui_GContainer_updateVirtualLayout'.",&tolua_err);
#endif

    return 0;
}
int lua_cocos2dx_fgui_GContainer_setNodeUrl(lua_State* tolua_S)
{
    int argc = 0;
    fgui::GContainer* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"fgui::GContainer",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (fgui::GContainer*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_fgui_GContainer_setNodeUrl'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 1) 
    {
        std::string arg0;

        ok &= luaval_to_std_string(tolua_S, 2,&arg0, "fgui::GContainer:setNodeUrl");
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_cocos2dx_fgui_GContainer_setNodeUrl'", nullptr);
            return 0;
        }
        cobj->setNodeUrl(arg0);
        lua_settop(tolua_S, 1);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "fgui::GContainer:setNodeUrl",argc, 1);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_fgui_GContainer_setNodeUrl'.",&tolua_err);
#endif

    return 0;
}
int lua_cocos2dx_fgui_GContainer_setLineGap(lua_State* tolua_S)
{
    int argc = 0;
    fgui::GContainer* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"fgui::GContainer",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (fgui::GContainer*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_fgui_GContainer_setLineGap'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 1) 
    {
        int arg0;

        ok &= luaval_to_int32(tolua_S, 2,(int *)&arg0, "fgui::GContainer:setLineGap");
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_cocos2dx_fgui_GContainer_setLineGap'", nullptr);
            return 0;
        }
        cobj->setLineGap(arg0);
        lua_settop(tolua_S, 1);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "fgui::GContainer:setLineGap",argc, 1);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_fgui_GContainer_setLineGap'.",&tolua_err);
#endif

    return 0;
}
int lua_cocos2dx_fgui_GContainer_setLayoutType(lua_State* tolua_S)
{
    int argc = 0;
    fgui::GContainer* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"fgui::GContainer",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (fgui::GContainer*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_fgui_GContainer_setLayoutType'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 1) 
    {
        fgui::ListLayoutType arg0;

        ok &= luaval_to_int32(tolua_S, 2,(int *)&arg0, "fgui::GContainer:setLayoutType");
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_cocos2dx_fgui_GContainer_setLayoutType'", nullptr);
            return 0;
        }
        cobj->setLayoutType(arg0);
        lua_settop(tolua_S, 1);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "fgui::GContainer:setLayoutType",argc, 1);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_fgui_GContainer_setLayoutType'.",&tolua_err);
#endif

    return 0;
}
int lua_cocos2dx_fgui_GContainer_create(lua_State* tolua_S)
{
    int argc = 0;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif

#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertable(tolua_S,1,"fgui::GContainer",0,&tolua_err)) goto tolua_lerror;
#endif

    argc = lua_gettop(tolua_S) - 1;

    if (argc == 0)
    {
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_cocos2dx_fgui_GContainer_create'", nullptr);
            return 0;
        }
        fgui::GContainer* ret = fgui::GContainer::create();
        object_to_luaval<fgui::GContainer>(tolua_S, "fgui::GContainer",(fgui::GContainer*)ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d\n ", "fgui::GContainer:create",argc, 0);
    return 0;
#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_fgui_GContainer_create'.",&tolua_err);
#endif
    return 0;
}
int lua_cocos2dx_fgui_GContainer_constructor(lua_State* tolua_S)
{
    int argc = 0;
    fgui::GContainer* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif



    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_cocos2dx_fgui_GContainer_constructor'", nullptr);
            return 0;
        }
        cobj = new fgui::GContainer();
        cobj->autorelease();
        int ID =  (int)cobj->_ID ;
        int* luaID =  &cobj->_luaID ;
        toluafix_pushusertype_ccobject(tolua_S, ID, luaID, (void*)cobj,"fgui::GContainer");
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "fgui::GContainer:GContainer",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_fgui_GContainer_constructor'.",&tolua_err);
#endif

    return 0;
}

static int lua_cocos2dx_fgui_GContainer_finalize(lua_State* tolua_S)
{
    printf("luabindings: finalizing LUA object (GContainer)");
    return 0;
}

int lua_register_cocos2dx_fgui_GContainer(lua_State* tolua_S)
{
    tolua_usertype(tolua_S,"fgui::GContainer");
    tolua_cclass(tolua_S,"GContainer","fgui::GContainer","cc.Node",nullptr);

    tolua_beginmodule(tolua_S,"GContainer");
        tolua_function(tolua_S,"new",lua_cocos2dx_fgui_GContainer_constructor);
        tolua_function(tolua_S,"addChild",lua_cocos2dx_fgui_GContainer_addChild);
        tolua_function(tolua_S,"getColumnGap",lua_cocos2dx_fgui_GContainer_getColumnGap);
        tolua_function(tolua_S,"getLineCount",lua_cocos2dx_fgui_GContainer_getLineCount);
        tolua_function(tolua_S,"updateCommonLayout",lua_cocos2dx_fgui_GContainer_updateCommonLayout);
        tolua_function(tolua_S,"visit",lua_cocos2dx_fgui_GContainer_visit);
        tolua_function(tolua_S,"setColumnGap",lua_cocos2dx_fgui_GContainer_setColumnGap);
        tolua_function(tolua_S,"getColumnCount",lua_cocos2dx_fgui_GContainer_getColumnCount);
        tolua_function(tolua_S,"setVirtual",lua_cocos2dx_fgui_GContainer_setVirtual);
        tolua_function(tolua_S,"getEdgeRectangle",lua_cocos2dx_fgui_GContainer_getEdgeRectangle);
        tolua_function(tolua_S,"setColumnCount",lua_cocos2dx_fgui_GContainer_setColumnCount);
        tolua_function(tolua_S,"getVAlignment",lua_cocos2dx_fgui_GContainer_getVAlignment);
        tolua_function(tolua_S,"init",lua_cocos2dx_fgui_GContainer_init);
        tolua_function(tolua_S,"setHAlignment",lua_cocos2dx_fgui_GContainer_setHAlignment);
        tolua_function(tolua_S,"setLineCount",lua_cocos2dx_fgui_GContainer_setLineCount);
        tolua_function(tolua_S,"clearAllChildren",lua_cocos2dx_fgui_GContainer_clearAllChildren);
        tolua_function(tolua_S,"setVirtualItemCount",lua_cocos2dx_fgui_GContainer_setVirtualItemCount);
        tolua_function(tolua_S,"isVirtual",lua_cocos2dx_fgui_GContainer_isVirtual);
        tolua_function(tolua_S,"getLayoutType",lua_cocos2dx_fgui_GContainer_getLayoutType);
        tolua_function(tolua_S,"setMargin",lua_cocos2dx_fgui_GContainer_setMargin);
        tolua_function(tolua_S,"getLineGap",lua_cocos2dx_fgui_GContainer_getLineGap);
        tolua_function(tolua_S,"getVirtualItemCount",lua_cocos2dx_fgui_GContainer_getVirtualItemCount);
        tolua_function(tolua_S,"getHAlignment",lua_cocos2dx_fgui_GContainer_getHAlignment);
        tolua_function(tolua_S,"setContentSize",lua_cocos2dx_fgui_GContainer_setContentSize);
        tolua_function(tolua_S,"setVAlignment",lua_cocos2dx_fgui_GContainer_setVAlignment);
        tolua_function(tolua_S,"updateVirtualLayout",lua_cocos2dx_fgui_GContainer_updateVirtualLayout);
        tolua_function(tolua_S,"setNodeUrl",lua_cocos2dx_fgui_GContainer_setNodeUrl);
        tolua_function(tolua_S,"setLineGap",lua_cocos2dx_fgui_GContainer_setLineGap);
        tolua_function(tolua_S,"setLayoutType",lua_cocos2dx_fgui_GContainer_setLayoutType);
        tolua_function(tolua_S,"create", lua_cocos2dx_fgui_GContainer_create);
    tolua_endmodule(tolua_S);
    std::string typeName = typeid(fgui::GContainer).name();
    g_luaType[typeName] = "fgui::GContainer";
    g_typeCast["GContainer"] = "fgui::GContainer";
    return 1;
}

int lua_cocos2dx_fgui_GComponent_applyAllControllers(lua_State* tolua_S)
{
    int argc = 0;
    fgui::GComponent* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"fgui::GComponent",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (fgui::GComponent*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_fgui_GComponent_applyAllControllers'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_cocos2dx_fgui_GComponent_applyAllControllers'", nullptr);
            return 0;
        }
        cobj->applyAllControllers();
        lua_settop(tolua_S, 1);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "fgui::GComponent:applyAllControllers",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_fgui_GComponent_applyAllControllers'.",&tolua_err);
#endif

    return 0;
}
int lua_cocos2dx_fgui_GComponent_onEnter(lua_State* tolua_S)
{
    int argc = 0;
    fgui::GComponent* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"fgui::GComponent",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (fgui::GComponent*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_fgui_GComponent_onEnter'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_cocos2dx_fgui_GComponent_onEnter'", nullptr);
            return 0;
        }
        cobj->onEnter();
        lua_settop(tolua_S, 1);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "fgui::GComponent:onEnter",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_fgui_GComponent_onEnter'.",&tolua_err);
#endif

    return 0;
}
int lua_cocos2dx_fgui_GComponent_setHSVValue(lua_State* tolua_S)
{
    int argc = 0;
    fgui::GComponent* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"fgui::GComponent",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (fgui::GComponent*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_fgui_GComponent_setHSVValue'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 4) 
    {
        double arg0;
        double arg1;
        double arg2;
        double arg3;

        ok &= luaval_to_number(tolua_S, 2,&arg0, "fgui::GComponent:setHSVValue");

        ok &= luaval_to_number(tolua_S, 3,&arg1, "fgui::GComponent:setHSVValue");

        ok &= luaval_to_number(tolua_S, 4,&arg2, "fgui::GComponent:setHSVValue");

        ok &= luaval_to_number(tolua_S, 5,&arg3, "fgui::GComponent:setHSVValue");
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_cocos2dx_fgui_GComponent_setHSVValue'", nullptr);
            return 0;
        }
        cobj->setHSVValue(arg0, arg1, arg2, arg3);
        lua_settop(tolua_S, 1);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "fgui::GComponent:setHSVValue",argc, 4);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_fgui_GComponent_setHSVValue'.",&tolua_err);
#endif

    return 0;
}
int lua_cocos2dx_fgui_GComponent_setHSVMode(lua_State* tolua_S)
{
    int argc = 0;
    fgui::GComponent* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"fgui::GComponent",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (fgui::GComponent*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_fgui_GComponent_setHSVMode'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 1) 
    {
        bool arg0;

        ok &= luaval_to_boolean(tolua_S, 2,&arg0, "fgui::GComponent:setHSVMode");
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_cocos2dx_fgui_GComponent_setHSVMode'", nullptr);
            return 0;
        }
        cobj->setHSVMode(arg0);
        lua_settop(tolua_S, 1);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "fgui::GComponent:setHSVMode",argc, 1);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_fgui_GComponent_setHSVMode'.",&tolua_err);
#endif

    return 0;
}
int lua_cocos2dx_fgui_GComponent_setStencil(lua_State* tolua_S)
{
    int argc = 0;
    fgui::GComponent* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"fgui::GComponent",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (fgui::GComponent*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_fgui_GComponent_setStencil'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 1) 
    {
        cocos2d::Node* arg0;

        ok &= luaval_to_object<cocos2d::Node>(tolua_S, 2, "cc.Node",&arg0, "fgui::GComponent:setStencil");
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_cocos2dx_fgui_GComponent_setStencil'", nullptr);
            return 0;
        }
        cobj->setStencil(arg0);
        lua_settop(tolua_S, 1);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "fgui::GComponent:setStencil",argc, 1);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_fgui_GComponent_setStencil'.",&tolua_err);
#endif

    return 0;
}
int lua_cocos2dx_fgui_GComponent_getEdgeRectangle(lua_State* tolua_S)
{
    int argc = 0;
    fgui::GComponent* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"fgui::GComponent",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (fgui::GComponent*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_fgui_GComponent_getEdgeRectangle'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_cocos2dx_fgui_GComponent_getEdgeRectangle'", nullptr);
            return 0;
        }
        cocos2d::Rect ret = cobj->getEdgeRectangle();
        rect_to_luaval(tolua_S, ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "fgui::GComponent:getEdgeRectangle",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_fgui_GComponent_getEdgeRectangle'.",&tolua_err);
#endif

    return 0;
}
int lua_cocos2dx_fgui_GComponent_getController(lua_State* tolua_S)
{
    int argc = 0;
    fgui::GComponent* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"fgui::GComponent",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (fgui::GComponent*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_fgui_GComponent_getController'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 1) 
    {
        std::string arg0;

        ok &= luaval_to_std_string(tolua_S, 2,&arg0, "fgui::GComponent:getController");
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_cocos2dx_fgui_GComponent_getController'", nullptr);
            return 0;
        }
        fgui::GController* ret = cobj->getController(arg0);
        object_to_luaval<fgui::GController>(tolua_S, "fgui::GController",(fgui::GController*)ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "fgui::GComponent:getController",argc, 1);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_fgui_GComponent_getController'.",&tolua_err);
#endif

    return 0;
}
int lua_cocos2dx_fgui_GComponent_getStencil(lua_State* tolua_S)
{
    int argc = 0;
    fgui::GComponent* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"fgui::GComponent",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (fgui::GComponent*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_fgui_GComponent_getStencil'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_cocos2dx_fgui_GComponent_getStencil'", nullptr);
            return 0;
        }
        cocos2d::Node* ret = cobj->getStencil();
        object_to_luaval<cocos2d::Node>(tolua_S, "cc.Node",(cocos2d::Node*)ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "fgui::GComponent:getStencil",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_fgui_GComponent_getStencil'.",&tolua_err);
#endif

    return 0;
}
int lua_cocos2dx_fgui_GComponent_setContentSize(lua_State* tolua_S)
{
    int argc = 0;
    fgui::GComponent* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"fgui::GComponent",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (fgui::GComponent*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_fgui_GComponent_setContentSize'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 1) 
    {
        cocos2d::Size arg0;

        ok &= luaval_to_size(tolua_S, 2, &arg0, "fgui::GComponent:setContentSize");
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_cocos2dx_fgui_GComponent_setContentSize'", nullptr);
            return 0;
        }
        cobj->setContentSize(arg0);
        lua_settop(tolua_S, 1);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "fgui::GComponent:setContentSize",argc, 1);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_fgui_GComponent_setContentSize'.",&tolua_err);
#endif

    return 0;
}
int lua_cocos2dx_fgui_GComponent_isStencilInverted(lua_State* tolua_S)
{
    int argc = 0;
    fgui::GComponent* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"fgui::GComponent",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (fgui::GComponent*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_fgui_GComponent_isStencilInverted'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_cocos2dx_fgui_GComponent_isStencilInverted'", nullptr);
            return 0;
        }
        bool ret = cobj->isStencilInverted();
        tolua_pushboolean(tolua_S,(bool)ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "fgui::GComponent:isStencilInverted",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_fgui_GComponent_isStencilInverted'.",&tolua_err);
#endif

    return 0;
}
int lua_cocos2dx_fgui_GComponent_getTransition(lua_State* tolua_S)
{
    int argc = 0;
    fgui::GComponent* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"fgui::GComponent",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (fgui::GComponent*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_fgui_GComponent_getTransition'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 1) 
    {
        std::string arg0;

        ok &= luaval_to_std_string(tolua_S, 2,&arg0, "fgui::GComponent:getTransition");
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_cocos2dx_fgui_GComponent_getTransition'", nullptr);
            return 0;
        }
        fgui::GTransition* ret = cobj->getTransition(arg0);
        object_to_luaval<fgui::GTransition>(tolua_S, "fgui::GTransition",(fgui::GTransition*)ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "fgui::GComponent:getTransition",argc, 1);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_fgui_GComponent_getTransition'.",&tolua_err);
#endif

    return 0;
}
int lua_cocos2dx_fgui_GComponent_init(lua_State* tolua_S)
{
    int argc = 0;
    fgui::GComponent* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"fgui::GComponent",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (fgui::GComponent*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_fgui_GComponent_init'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_cocos2dx_fgui_GComponent_init'", nullptr);
            return 0;
        }
        bool ret = cobj->init();
        tolua_pushboolean(tolua_S,(bool)ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "fgui::GComponent:init",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_fgui_GComponent_init'.",&tolua_err);
#endif

    return 0;
}
int lua_cocos2dx_fgui_GComponent_applyController(lua_State* tolua_S)
{
    int argc = 0;
    fgui::GComponent* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"fgui::GComponent",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (fgui::GComponent*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_fgui_GComponent_applyController'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 1) 
    {
        fgui::GController* arg0;

        ok &= luaval_to_object<fgui::GController>(tolua_S, 2, "fgui::GController",&arg0, "fgui::GComponent:applyController");
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_cocos2dx_fgui_GComponent_applyController'", nullptr);
            return 0;
        }
        cobj->applyController(arg0);
        lua_settop(tolua_S, 1);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "fgui::GComponent:applyController",argc, 1);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_fgui_GComponent_applyController'.",&tolua_err);
#endif

    return 0;
}
int lua_cocos2dx_fgui_GComponent_isConstructing(lua_State* tolua_S)
{
    int argc = 0;
    fgui::GComponent* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"fgui::GComponent",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (fgui::GComponent*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_fgui_GComponent_isConstructing'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_cocos2dx_fgui_GComponent_isConstructing'", nullptr);
            return 0;
        }
        bool ret = cobj->isConstructing();
        tolua_pushboolean(tolua_S,(bool)ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "fgui::GComponent:isConstructing",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_fgui_GComponent_isConstructing'.",&tolua_err);
#endif

    return 0;
}
int lua_cocos2dx_fgui_GComponent_getChildById(lua_State* tolua_S)
{
    int argc = 0;
    fgui::GComponent* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"fgui::GComponent",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (fgui::GComponent*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_fgui_GComponent_getChildById'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 1) 
    {
        std::string arg0;

        ok &= luaval_to_std_string(tolua_S, 2,&arg0, "fgui::GComponent:getChildById");
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_cocos2dx_fgui_GComponent_getChildById'", nullptr);
            return 0;
        }
        cocos2d::Node* ret = cobj->getChildById(arg0);
        object_to_luaval<cocos2d::Node>(tolua_S, "cc.Node",(cocos2d::Node*)ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "fgui::GComponent:getChildById",argc, 1);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_fgui_GComponent_getChildById'.",&tolua_err);
#endif

    return 0;
}
int lua_cocos2dx_fgui_GComponent_getControllerAt(lua_State* tolua_S)
{
    int argc = 0;
    fgui::GComponent* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"fgui::GComponent",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (fgui::GComponent*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_fgui_GComponent_getControllerAt'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 1) 
    {
        int arg0;

        ok &= luaval_to_int32(tolua_S, 2,(int *)&arg0, "fgui::GComponent:getControllerAt");
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_cocos2dx_fgui_GComponent_getControllerAt'", nullptr);
            return 0;
        }
        fgui::GController* ret = cobj->getControllerAt(arg0);
        object_to_luaval<fgui::GController>(tolua_S, "fgui::GController",(fgui::GController*)ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "fgui::GComponent:getControllerAt",argc, 1);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_fgui_GComponent_getControllerAt'.",&tolua_err);
#endif

    return 0;
}
int lua_cocos2dx_fgui_GComponent_onEixt(lua_State* tolua_S)
{
    int argc = 0;
    fgui::GComponent* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"fgui::GComponent",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (fgui::GComponent*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_fgui_GComponent_onEixt'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_cocos2dx_fgui_GComponent_onEixt'", nullptr);
            return 0;
        }
        cobj->onEixt();
        lua_settop(tolua_S, 1);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "fgui::GComponent:onEixt",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_fgui_GComponent_onEixt'.",&tolua_err);
#endif

    return 0;
}
int lua_cocos2dx_fgui_GComponent_setBlendMode(lua_State* tolua_S)
{
    int argc = 0;
    fgui::GComponent* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"fgui::GComponent",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (fgui::GComponent*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_fgui_GComponent_setBlendMode'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 1) 
    {
        fgui::BlendMode arg0;

        ok &= luaval_to_int32(tolua_S, 2,(int *)&arg0, "fgui::GComponent:setBlendMode");
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_cocos2dx_fgui_GComponent_setBlendMode'", nullptr);
            return 0;
        }
        cobj->setBlendMode(arg0);
        lua_settop(tolua_S, 1);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "fgui::GComponent:setBlendMode",argc, 1);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_fgui_GComponent_setBlendMode'.",&tolua_err);
#endif

    return 0;
}
int lua_cocos2dx_fgui_GComponent_setGrayed(lua_State* tolua_S)
{
    int argc = 0;
    fgui::GComponent* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"fgui::GComponent",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (fgui::GComponent*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_fgui_GComponent_setGrayed'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 1) 
    {
        bool arg0;

        ok &= luaval_to_boolean(tolua_S, 2,&arg0, "fgui::GComponent:setGrayed");
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_cocos2dx_fgui_GComponent_setGrayed'", nullptr);
            return 0;
        }
        cobj->setGrayed(arg0);
        lua_settop(tolua_S, 1);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "fgui::GComponent:setGrayed",argc, 1);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_fgui_GComponent_setGrayed'.",&tolua_err);
#endif

    return 0;
}
int lua_cocos2dx_fgui_GComponent_setStencilInverted(lua_State* tolua_S)
{
    int argc = 0;
    fgui::GComponent* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"fgui::GComponent",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (fgui::GComponent*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_fgui_GComponent_setStencilInverted'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 1) 
    {
        bool arg0;

        ok &= luaval_to_boolean(tolua_S, 2,&arg0, "fgui::GComponent:setStencilInverted");
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_cocos2dx_fgui_GComponent_setStencilInverted'", nullptr);
            return 0;
        }
        cobj->setStencilInverted(arg0);
        lua_settop(tolua_S, 1);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "fgui::GComponent:setStencilInverted",argc, 1);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_fgui_GComponent_setStencilInverted'.",&tolua_err);
#endif

    return 0;
}
int lua_cocos2dx_fgui_GComponent_setPosition(lua_State* tolua_S)
{
    int argc = 0;
    fgui::GComponent* cobj = nullptr;
    bool ok  = true;
#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif

#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"fgui::GComponent",0,&tolua_err)) goto tolua_lerror;
#endif
    cobj = (fgui::GComponent*)tolua_tousertype(tolua_S,1,0);
#if COCOS2D_DEBUG >= 1
    if (!cobj)
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_fgui_GComponent_setPosition'", nullptr);
        return 0;
    }
#endif
    argc = lua_gettop(tolua_S)-1;
    do{
        if (argc == 2) {
            double arg0;
            ok &= luaval_to_number(tolua_S, 2,&arg0, "fgui::GComponent:setPosition");

            if (!ok) { break; }
            double arg1;
            ok &= luaval_to_number(tolua_S, 3,&arg1, "fgui::GComponent:setPosition");

            if (!ok) { break; }
            cobj->setPosition(arg0, arg1);
            lua_settop(tolua_S, 1);
            return 1;
        }
    }while(0);
    ok  = true;
    do{
        if (argc == 1) {
            cocos2d::Vec2 arg0;
            ok &= luaval_to_vec2(tolua_S, 2, &arg0, "fgui::GComponent:setPosition");

            if (!ok) { break; }
            cobj->setPosition(arg0);
            lua_settop(tolua_S, 1);
            return 1;
        }
    }while(0);
    ok  = true;
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n",  "fgui::GComponent:setPosition",argc, 1);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_fgui_GComponent_setPosition'.",&tolua_err);
#endif

    return 0;
}
int lua_cocos2dx_fgui_GComponent_setAlphaThreshold(lua_State* tolua_S)
{
    int argc = 0;
    fgui::GComponent* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"fgui::GComponent",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (fgui::GComponent*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_fgui_GComponent_setAlphaThreshold'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 1) 
    {
        double arg0;

        ok &= luaval_to_number(tolua_S, 2,&arg0, "fgui::GComponent:setAlphaThreshold");
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_cocos2dx_fgui_GComponent_setAlphaThreshold'", nullptr);
            return 0;
        }
        cobj->setAlphaThreshold(arg0);
        lua_settop(tolua_S, 1);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "fgui::GComponent:setAlphaThreshold",argc, 1);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_fgui_GComponent_setAlphaThreshold'.",&tolua_err);
#endif

    return 0;
}
int lua_cocos2dx_fgui_GComponent_onTransionPositionChanged(lua_State* tolua_S)
{
    int argc = 0;
    fgui::GComponent* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"fgui::GComponent",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (fgui::GComponent*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_fgui_GComponent_onTransionPositionChanged'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 3) 
    {
        cocos2d::Node* arg0;
        double arg1;
        double arg2;

        ok &= luaval_to_object<cocos2d::Node>(tolua_S, 2, "cc.Node",&arg0, "fgui::GComponent:onTransionPositionChanged");

        ok &= luaval_to_number(tolua_S, 3,&arg1, "fgui::GComponent:onTransionPositionChanged");

        ok &= luaval_to_number(tolua_S, 4,&arg2, "fgui::GComponent:onTransionPositionChanged");
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_cocos2dx_fgui_GComponent_onTransionPositionChanged'", nullptr);
            return 0;
        }
        cobj->onTransionPositionChanged(arg0, arg1, arg2);
        lua_settop(tolua_S, 1);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "fgui::GComponent:onTransionPositionChanged",argc, 3);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_fgui_GComponent_onTransionPositionChanged'.",&tolua_err);
#endif

    return 0;
}
int lua_cocos2dx_fgui_GComponent_setCameraMask(lua_State* tolua_S)
{
    int argc = 0;
    fgui::GComponent* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"fgui::GComponent",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (fgui::GComponent*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_fgui_GComponent_setCameraMask'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 1) 
    {
        unsigned short arg0;

        ok &= luaval_to_ushort(tolua_S, 2, &arg0, "fgui::GComponent:setCameraMask");
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_cocos2dx_fgui_GComponent_setCameraMask'", nullptr);
            return 0;
        }
        cobj->setCameraMask(arg0);
        lua_settop(tolua_S, 1);
        return 1;
    }
    if (argc == 2) 
    {
        unsigned short arg0;
        bool arg1;

        ok &= luaval_to_ushort(tolua_S, 2, &arg0, "fgui::GComponent:setCameraMask");

        ok &= luaval_to_boolean(tolua_S, 3,&arg1, "fgui::GComponent:setCameraMask");
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_cocos2dx_fgui_GComponent_setCameraMask'", nullptr);
            return 0;
        }
        cobj->setCameraMask(arg0, arg1);
        lua_settop(tolua_S, 1);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "fgui::GComponent:setCameraMask",argc, 1);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_fgui_GComponent_setCameraMask'.",&tolua_err);
#endif

    return 0;
}
int lua_cocos2dx_fgui_GComponent_setHitArea(lua_State* tolua_S)
{
    int argc = 0;
    fgui::GComponent* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"fgui::GComponent",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (fgui::GComponent*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_fgui_GComponent_setHitArea'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 1) 
    {
        fgui::IHitTest* arg0;

        ok &= luaval_to_object<fgui::IHitTest>(tolua_S, 2, "fgui::IHitTest",&arg0, "fgui::GComponent:setHitArea");
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_cocos2dx_fgui_GComponent_setHitArea'", nullptr);
            return 0;
        }
        cobj->setHitArea(arg0);
        lua_settop(tolua_S, 1);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "fgui::GComponent:setHitArea",argc, 1);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_fgui_GComponent_setHitArea'.",&tolua_err);
#endif

    return 0;
}
int lua_cocos2dx_fgui_GComponent_getAlphaThreshold(lua_State* tolua_S)
{
    int argc = 0;
    fgui::GComponent* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"fgui::GComponent",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (fgui::GComponent*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_fgui_GComponent_getAlphaThreshold'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_cocos2dx_fgui_GComponent_getAlphaThreshold'", nullptr);
            return 0;
        }
        double ret = cobj->getAlphaThreshold();
        tolua_pushnumber(tolua_S,(lua_Number)ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "fgui::GComponent:getAlphaThreshold",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_fgui_GComponent_getAlphaThreshold'.",&tolua_err);
#endif

    return 0;
}
int lua_cocos2dx_fgui_GComponent_create(lua_State* tolua_S)
{
    int argc = 0;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif

#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertable(tolua_S,1,"fgui::GComponent",0,&tolua_err)) goto tolua_lerror;
#endif

    argc = lua_gettop(tolua_S) - 1;

    if (argc == 0)
    {
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_cocos2dx_fgui_GComponent_create'", nullptr);
            return 0;
        }
        fgui::GComponent* ret = fgui::GComponent::create();
        object_to_luaval<fgui::GComponent>(tolua_S, "fgui::GComponent",(fgui::GComponent*)ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d\n ", "fgui::GComponent:create",argc, 0);
    return 0;
#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_fgui_GComponent_create'.",&tolua_err);
#endif
    return 0;
}
static int lua_cocos2dx_fgui_GComponent_finalize(lua_State* tolua_S)
{
    printf("luabindings: finalizing LUA object (GComponent)");
    return 0;
}

int lua_register_cocos2dx_fgui_GComponent(lua_State* tolua_S)
{
    tolua_usertype(tolua_S,"fgui::GComponent");
    tolua_cclass(tolua_S,"GComponent","fgui::GComponent","cc.Node",nullptr);

    tolua_beginmodule(tolua_S,"GComponent");
        tolua_function(tolua_S,"applyAllControllers",lua_cocos2dx_fgui_GComponent_applyAllControllers);
        tolua_function(tolua_S,"onEnter",lua_cocos2dx_fgui_GComponent_onEnter);
        tolua_function(tolua_S,"setHSVValue",lua_cocos2dx_fgui_GComponent_setHSVValue);
        tolua_function(tolua_S,"setHSVMode",lua_cocos2dx_fgui_GComponent_setHSVMode);
        tolua_function(tolua_S,"setStencil",lua_cocos2dx_fgui_GComponent_setStencil);
        tolua_function(tolua_S,"getEdgeRectangle",lua_cocos2dx_fgui_GComponent_getEdgeRectangle);
        tolua_function(tolua_S,"getController",lua_cocos2dx_fgui_GComponent_getController);
        tolua_function(tolua_S,"getStencil",lua_cocos2dx_fgui_GComponent_getStencil);
        tolua_function(tolua_S,"setContentSize",lua_cocos2dx_fgui_GComponent_setContentSize);
        tolua_function(tolua_S,"isStencilInverted",lua_cocos2dx_fgui_GComponent_isStencilInverted);
        tolua_function(tolua_S,"getTransition",lua_cocos2dx_fgui_GComponent_getTransition);
        tolua_function(tolua_S,"init",lua_cocos2dx_fgui_GComponent_init);
        tolua_function(tolua_S,"applyController",lua_cocos2dx_fgui_GComponent_applyController);
        tolua_function(tolua_S,"isConstructing",lua_cocos2dx_fgui_GComponent_isConstructing);
        tolua_function(tolua_S,"getChildById",lua_cocos2dx_fgui_GComponent_getChildById);
        tolua_function(tolua_S,"getControllerAt",lua_cocos2dx_fgui_GComponent_getControllerAt);
        tolua_function(tolua_S,"onEixt",lua_cocos2dx_fgui_GComponent_onEixt);
        tolua_function(tolua_S,"setBlendMode",lua_cocos2dx_fgui_GComponent_setBlendMode);
        tolua_function(tolua_S,"setGrayed",lua_cocos2dx_fgui_GComponent_setGrayed);
        tolua_function(tolua_S,"setStencilInverted",lua_cocos2dx_fgui_GComponent_setStencilInverted);
        tolua_function(tolua_S,"setPosition",lua_cocos2dx_fgui_GComponent_setPosition);
        tolua_function(tolua_S,"setAlphaThreshold",lua_cocos2dx_fgui_GComponent_setAlphaThreshold);
        tolua_function(tolua_S,"onTransionPositionChanged",lua_cocos2dx_fgui_GComponent_onTransionPositionChanged);
        tolua_function(tolua_S,"setCameraMask",lua_cocos2dx_fgui_GComponent_setCameraMask);
        tolua_function(tolua_S,"setHitArea",lua_cocos2dx_fgui_GComponent_setHitArea);
        tolua_function(tolua_S,"getAlphaThreshold",lua_cocos2dx_fgui_GComponent_getAlphaThreshold);
        tolua_function(tolua_S,"create", lua_cocos2dx_fgui_GComponent_create);
    tolua_endmodule(tolua_S);
    std::string typeName = typeid(fgui::GComponent).name();
    g_luaType[typeName] = "fgui::GComponent";
    g_typeCast["GComponent"] = "fgui::GComponent";
    return 1;
}

int lua_cocos2dx_fgui_GButton_setSelectedTitle(lua_State* tolua_S)
{
    int argc = 0;
    fgui::GButton* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"fgui::GButton",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (fgui::GButton*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_fgui_GButton_setSelectedTitle'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 1) 
    {
        std::string arg0;

        ok &= luaval_to_std_string(tolua_S, 2,&arg0, "fgui::GButton:setSelectedTitle");
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_cocos2dx_fgui_GButton_setSelectedTitle'", nullptr);
            return 0;
        }
        cobj->setSelectedTitle(arg0);
        lua_settop(tolua_S, 1);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "fgui::GButton:setSelectedTitle",argc, 1);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_fgui_GButton_setSelectedTitle'.",&tolua_err);
#endif

    return 0;
}
int lua_cocos2dx_fgui_GButton_setSelected(lua_State* tolua_S)
{
    int argc = 0;
    fgui::GButton* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"fgui::GButton",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (fgui::GButton*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_fgui_GButton_setSelected'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 1) 
    {
        bool arg0;

        ok &= luaval_to_boolean(tolua_S, 2,&arg0, "fgui::GButton:setSelected");
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_cocos2dx_fgui_GButton_setSelected'", nullptr);
            return 0;
        }
        cobj->setSelected(arg0);
        lua_settop(tolua_S, 1);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "fgui::GButton:setSelected",argc, 1);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_fgui_GButton_setSelected'.",&tolua_err);
#endif

    return 0;
}
int lua_cocos2dx_fgui_GButton_setTitle(lua_State* tolua_S)
{
    int argc = 0;
    fgui::GButton* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"fgui::GButton",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (fgui::GButton*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_fgui_GButton_setTitle'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 1) 
    {
        std::string arg0;

        ok &= luaval_to_std_string(tolua_S, 2,&arg0, "fgui::GButton:setTitle");
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_cocos2dx_fgui_GButton_setTitle'", nullptr);
            return 0;
        }
        cobj->setTitle(arg0);
        lua_settop(tolua_S, 1);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "fgui::GButton:setTitle",argc, 1);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_fgui_GButton_setTitle'.",&tolua_err);
#endif

    return 0;
}
int lua_cocos2dx_fgui_GButton_setSelectedIcon(lua_State* tolua_S)
{
    int argc = 0;
    fgui::GButton* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"fgui::GButton",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (fgui::GButton*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_fgui_GButton_setSelectedIcon'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 1) 
    {
        std::string arg0;

        ok &= luaval_to_std_string(tolua_S, 2,&arg0, "fgui::GButton:setSelectedIcon");
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_cocos2dx_fgui_GButton_setSelectedIcon'", nullptr);
            return 0;
        }
        cobj->setSelectedIcon(arg0);
        lua_settop(tolua_S, 1);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "fgui::GButton:setSelectedIcon",argc, 1);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_fgui_GButton_setSelectedIcon'.",&tolua_err);
#endif

    return 0;
}
int lua_cocos2dx_fgui_GButton_setIcon(lua_State* tolua_S)
{
    int argc = 0;
    fgui::GButton* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"fgui::GButton",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (fgui::GButton*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_fgui_GButton_setIcon'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 1) 
    {
        std::string arg0;

        ok &= luaval_to_std_string(tolua_S, 2,&arg0, "fgui::GButton:setIcon");
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_cocos2dx_fgui_GButton_setIcon'", nullptr);
            return 0;
        }
        cobj->setIcon(arg0);
        lua_settop(tolua_S, 1);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "fgui::GButton:setIcon",argc, 1);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_fgui_GButton_setIcon'.",&tolua_err);
#endif

    return 0;
}
int lua_cocos2dx_fgui_GButton_setTitleFontSize(lua_State* tolua_S)
{
    int argc = 0;
    fgui::GButton* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"fgui::GButton",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (fgui::GButton*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_fgui_GButton_setTitleFontSize'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 1) 
    {
        int arg0;

        ok &= luaval_to_int32(tolua_S, 2,(int *)&arg0, "fgui::GButton:setTitleFontSize");
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_cocos2dx_fgui_GButton_setTitleFontSize'", nullptr);
            return 0;
        }
        cobj->setTitleFontSize(arg0);
        lua_settop(tolua_S, 1);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "fgui::GButton:setTitleFontSize",argc, 1);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_fgui_GButton_setTitleFontSize'.",&tolua_err);
#endif

    return 0;
}
int lua_cocos2dx_fgui_GButton_setTitleColor(lua_State* tolua_S)
{
    int argc = 0;
    fgui::GButton* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"fgui::GButton",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (fgui::GButton*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_fgui_GButton_setTitleColor'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 1) 
    {
        cocos2d::Color4B arg0;

        ok &=luaval_to_color4b(tolua_S, 2, &arg0, "fgui::GButton:setTitleColor");
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_cocos2dx_fgui_GButton_setTitleColor'", nullptr);
            return 0;
        }
        cobj->setTitleColor(arg0);
        lua_settop(tolua_S, 1);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "fgui::GButton:setTitleColor",argc, 1);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_fgui_GButton_setTitleColor'.",&tolua_err);
#endif

    return 0;
}
int lua_cocos2dx_fgui_GButton_create(lua_State* tolua_S)
{
    int argc = 0;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif

#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertable(tolua_S,1,"fgui::GButton",0,&tolua_err)) goto tolua_lerror;
#endif

    argc = lua_gettop(tolua_S) - 1;

    if (argc == 0)
    {
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_cocos2dx_fgui_GButton_create'", nullptr);
            return 0;
        }
        fgui::GButton* ret = fgui::GButton::create();
        object_to_luaval<fgui::GButton>(tolua_S, "fgui::GButton",(fgui::GButton*)ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d\n ", "fgui::GButton:create",argc, 0);
    return 0;
#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_fgui_GButton_create'.",&tolua_err);
#endif
    return 0;
}
static int lua_cocos2dx_fgui_GButton_finalize(lua_State* tolua_S)
{
    printf("luabindings: finalizing LUA object (GButton)");
    return 0;
}

int lua_register_cocos2dx_fgui_GButton(lua_State* tolua_S)
{
    tolua_usertype(tolua_S,"fgui::GButton");
    tolua_cclass(tolua_S,"GButton","fgui::GButton","fgui::GComponent",nullptr);

    tolua_beginmodule(tolua_S,"GButton");
        tolua_function(tolua_S,"setSelectedTitle",lua_cocos2dx_fgui_GButton_setSelectedTitle);
        tolua_function(tolua_S,"setSelected",lua_cocos2dx_fgui_GButton_setSelected);
        tolua_function(tolua_S,"setTitle",lua_cocos2dx_fgui_GButton_setTitle);
        tolua_function(tolua_S,"setSelectedIcon",lua_cocos2dx_fgui_GButton_setSelectedIcon);
        tolua_function(tolua_S,"setIcon",lua_cocos2dx_fgui_GButton_setIcon);
        tolua_function(tolua_S,"setTitleFontSize",lua_cocos2dx_fgui_GButton_setTitleFontSize);
        tolua_function(tolua_S,"setTitleColor",lua_cocos2dx_fgui_GButton_setTitleColor);
        tolua_function(tolua_S,"create", lua_cocos2dx_fgui_GButton_create);
    tolua_endmodule(tolua_S);
    std::string typeName = typeid(fgui::GButton).name();
    g_luaType[typeName] = "fgui::GButton";
    g_typeCast["GButton"] = "fgui::GButton";
    return 1;
}

int lua_cocos2dx_fgui_GSlider_setPercent(lua_State* tolua_S)
{
    int argc = 0;
    fgui::GSlider* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"fgui::GSlider",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (fgui::GSlider*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_fgui_GSlider_setPercent'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 1) 
    {
        double arg0;

        ok &= luaval_to_number(tolua_S, 2,&arg0, "fgui::GSlider:setPercent");
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_cocos2dx_fgui_GSlider_setPercent'", nullptr);
            return 0;
        }
        cobj->setPercent(arg0);
        lua_settop(tolua_S, 1);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "fgui::GSlider:setPercent",argc, 1);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_fgui_GSlider_setPercent'.",&tolua_err);
#endif

    return 0;
}
int lua_cocos2dx_fgui_GSlider_setValue(lua_State* tolua_S)
{
    int argc = 0;
    fgui::GSlider* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"fgui::GSlider",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (fgui::GSlider*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_fgui_GSlider_setValue'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 1) 
    {
        double arg0;

        ok &= luaval_to_number(tolua_S, 2,&arg0, "fgui::GSlider:setValue");
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_cocos2dx_fgui_GSlider_setValue'", nullptr);
            return 0;
        }
        cobj->setValue(arg0);
        lua_settop(tolua_S, 1);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "fgui::GSlider:setValue",argc, 1);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_fgui_GSlider_setValue'.",&tolua_err);
#endif

    return 0;
}
int lua_cocos2dx_fgui_GSlider_setMax(lua_State* tolua_S)
{
    int argc = 0;
    fgui::GSlider* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"fgui::GSlider",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (fgui::GSlider*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_fgui_GSlider_setMax'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 1) 
    {
        double arg0;

        ok &= luaval_to_number(tolua_S, 2,&arg0, "fgui::GSlider:setMax");
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_cocos2dx_fgui_GSlider_setMax'", nullptr);
            return 0;
        }
        cobj->setMax(arg0);
        lua_settop(tolua_S, 1);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "fgui::GSlider:setMax",argc, 1);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_fgui_GSlider_setMax'.",&tolua_err);
#endif

    return 0;
}
int lua_cocos2dx_fgui_GSlider_create(lua_State* tolua_S)
{
    int argc = 0;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif

#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertable(tolua_S,1,"fgui::GSlider",0,&tolua_err)) goto tolua_lerror;
#endif

    argc = lua_gettop(tolua_S) - 1;

    if (argc == 0)
    {
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_cocos2dx_fgui_GSlider_create'", nullptr);
            return 0;
        }
        fgui::GSlider* ret = fgui::GSlider::create();
        object_to_luaval<fgui::GSlider>(tolua_S, "fgui::GSlider",(fgui::GSlider*)ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d\n ", "fgui::GSlider:create",argc, 0);
    return 0;
#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_fgui_GSlider_create'.",&tolua_err);
#endif
    return 0;
}
int lua_cocos2dx_fgui_GSlider_constructor(lua_State* tolua_S)
{
    int argc = 0;
    fgui::GSlider* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif



    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_cocos2dx_fgui_GSlider_constructor'", nullptr);
            return 0;
        }
        cobj = new fgui::GSlider();
        cobj->autorelease();
        int ID =  (int)cobj->_ID ;
        int* luaID =  &cobj->_luaID ;
        toluafix_pushusertype_ccobject(tolua_S, ID, luaID, (void*)cobj,"fgui::GSlider");
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "fgui::GSlider:GSlider",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_fgui_GSlider_constructor'.",&tolua_err);
#endif

    return 0;
}

static int lua_cocos2dx_fgui_GSlider_finalize(lua_State* tolua_S)
{
    printf("luabindings: finalizing LUA object (GSlider)");
    return 0;
}

int lua_register_cocos2dx_fgui_GSlider(lua_State* tolua_S)
{
    tolua_usertype(tolua_S,"fgui::GSlider");
    tolua_cclass(tolua_S,"GSlider","fgui::GSlider","fgui::GComponent",nullptr);

    tolua_beginmodule(tolua_S,"GSlider");
        tolua_function(tolua_S,"new",lua_cocos2dx_fgui_GSlider_constructor);
        tolua_function(tolua_S,"setPercent",lua_cocos2dx_fgui_GSlider_setPercent);
        tolua_function(tolua_S,"setValue",lua_cocos2dx_fgui_GSlider_setValue);
        tolua_function(tolua_S,"setMax",lua_cocos2dx_fgui_GSlider_setMax);
        tolua_function(tolua_S,"create", lua_cocos2dx_fgui_GSlider_create);
    tolua_endmodule(tolua_S);
    std::string typeName = typeid(fgui::GSlider).name();
    g_luaType[typeName] = "fgui::GSlider";
    g_typeCast["GSlider"] = "fgui::GSlider";
    return 1;
}

int lua_cocos2dx_fgui_GAnimation_setIsSwing(lua_State* tolua_S)
{
    int argc = 0;
    fgui::GAnimation* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"fgui::GAnimation",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (fgui::GAnimation*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_fgui_GAnimation_setIsSwing'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 1) 
    {
        bool arg0;

        ok &= luaval_to_boolean(tolua_S, 2,&arg0, "fgui::GAnimation:setIsSwing");
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_cocos2dx_fgui_GAnimation_setIsSwing'", nullptr);
            return 0;
        }
        cobj->setIsSwing(arg0);
        lua_settop(tolua_S, 1);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "fgui::GAnimation:setIsSwing",argc, 1);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_fgui_GAnimation_setIsSwing'.",&tolua_err);
#endif

    return 0;
}
int lua_cocos2dx_fgui_GAnimation_pause(lua_State* tolua_S)
{
    int argc = 0;
    fgui::GAnimation* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"fgui::GAnimation",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (fgui::GAnimation*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_fgui_GAnimation_pause'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_cocos2dx_fgui_GAnimation_pause'", nullptr);
            return 0;
        }
        cobj->pause();
        lua_settop(tolua_S, 1);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "fgui::GAnimation:pause",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_fgui_GAnimation_pause'.",&tolua_err);
#endif

    return 0;
}
int lua_cocos2dx_fgui_GAnimation_play(lua_State* tolua_S)
{
    int argc = 0;
    fgui::GAnimation* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"fgui::GAnimation",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (fgui::GAnimation*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_fgui_GAnimation_play'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_cocos2dx_fgui_GAnimation_play'", nullptr);
            return 0;
        }
        cobj->play();
        lua_settop(tolua_S, 1);
        return 1;
    }
    if (argc == 1) 
    {
        int arg0;

        ok &= luaval_to_int32(tolua_S, 2,(int *)&arg0, "fgui::GAnimation:play");
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_cocos2dx_fgui_GAnimation_play'", nullptr);
            return 0;
        }
        cobj->play(arg0);
        lua_settop(tolua_S, 1);
        return 1;
    }
    if (argc == 2) 
    {
        int arg0;
        int arg1;

        ok &= luaval_to_int32(tolua_S, 2,(int *)&arg0, "fgui::GAnimation:play");

        ok &= luaval_to_int32(tolua_S, 3,(int *)&arg1, "fgui::GAnimation:play");
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_cocos2dx_fgui_GAnimation_play'", nullptr);
            return 0;
        }
        cobj->play(arg0, arg1);
        lua_settop(tolua_S, 1);
        return 1;
    }
    if (argc == 3) 
    {
        int arg0;
        int arg1;
        int arg2;

        ok &= luaval_to_int32(tolua_S, 2,(int *)&arg0, "fgui::GAnimation:play");

        ok &= luaval_to_int32(tolua_S, 3,(int *)&arg1, "fgui::GAnimation:play");

        ok &= luaval_to_int32(tolua_S, 4,(int *)&arg2, "fgui::GAnimation:play");
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_cocos2dx_fgui_GAnimation_play'", nullptr);
            return 0;
        }
        cobj->play(arg0, arg1, arg2);
        lua_settop(tolua_S, 1);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "fgui::GAnimation:play",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_fgui_GAnimation_play'.",&tolua_err);
#endif

    return 0;
}
int lua_cocos2dx_fgui_GAnimation_setTimeScale(lua_State* tolua_S)
{
    int argc = 0;
    fgui::GAnimation* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"fgui::GAnimation",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (fgui::GAnimation*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_fgui_GAnimation_setTimeScale'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 1) 
    {
        double arg0;

        ok &= luaval_to_number(tolua_S, 2,&arg0, "fgui::GAnimation:setTimeScale");
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_cocos2dx_fgui_GAnimation_setTimeScale'", nullptr);
            return 0;
        }
        cobj->setTimeScale(arg0);
        lua_settop(tolua_S, 1);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "fgui::GAnimation:setTimeScale",argc, 1);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_fgui_GAnimation_setTimeScale'.",&tolua_err);
#endif

    return 0;
}
int lua_cocos2dx_fgui_GAnimation_setHSVValue(lua_State* tolua_S)
{
    int argc = 0;
    fgui::GAnimation* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"fgui::GAnimation",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (fgui::GAnimation*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_fgui_GAnimation_setHSVValue'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 4) 
    {
        double arg0;
        double arg1;
        double arg2;
        double arg3;

        ok &= luaval_to_number(tolua_S, 2,&arg0, "fgui::GAnimation:setHSVValue");

        ok &= luaval_to_number(tolua_S, 3,&arg1, "fgui::GAnimation:setHSVValue");

        ok &= luaval_to_number(tolua_S, 4,&arg2, "fgui::GAnimation:setHSVValue");

        ok &= luaval_to_number(tolua_S, 5,&arg3, "fgui::GAnimation:setHSVValue");
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_cocos2dx_fgui_GAnimation_setHSVValue'", nullptr);
            return 0;
        }
        cobj->setHSVValue(arg0, arg1, arg2, arg3);
        lua_settop(tolua_S, 1);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "fgui::GAnimation:setHSVValue",argc, 4);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_fgui_GAnimation_setHSVValue'.",&tolua_err);
#endif

    return 0;
}
int lua_cocos2dx_fgui_GAnimation_resume(lua_State* tolua_S)
{
    int argc = 0;
    fgui::GAnimation* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"fgui::GAnimation",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (fgui::GAnimation*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_fgui_GAnimation_resume'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_cocos2dx_fgui_GAnimation_resume'", nullptr);
            return 0;
        }
        cobj->resume();
        lua_settop(tolua_S, 1);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "fgui::GAnimation:resume",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_fgui_GAnimation_resume'.",&tolua_err);
#endif

    return 0;
}
int lua_cocos2dx_fgui_GAnimation_setCurFrame(lua_State* tolua_S)
{
    int argc = 0;
    fgui::GAnimation* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"fgui::GAnimation",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (fgui::GAnimation*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_fgui_GAnimation_setCurFrame'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 1) 
    {
        int arg0;

        ok &= luaval_to_int32(tolua_S, 2,(int *)&arg0, "fgui::GAnimation:setCurFrame");
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_cocos2dx_fgui_GAnimation_setCurFrame'", nullptr);
            return 0;
        }
        cobj->setCurFrame(arg0);
        lua_settop(tolua_S, 1);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "fgui::GAnimation:setCurFrame",argc, 1);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_fgui_GAnimation_setCurFrame'.",&tolua_err);
#endif

    return 0;
}
int lua_cocos2dx_fgui_GAnimation_setHSVMode(lua_State* tolua_S)
{
    int argc = 0;
    fgui::GAnimation* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"fgui::GAnimation",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (fgui::GAnimation*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_fgui_GAnimation_setHSVMode'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 1) 
    {
        bool arg0;

        ok &= luaval_to_boolean(tolua_S, 2,&arg0, "fgui::GAnimation:setHSVMode");
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_cocos2dx_fgui_GAnimation_setHSVMode'", nullptr);
            return 0;
        }
        cobj->setHSVMode(arg0);
        lua_settop(tolua_S, 1);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "fgui::GAnimation:setHSVMode",argc, 1);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_fgui_GAnimation_setHSVMode'.",&tolua_err);
#endif

    return 0;
}
int lua_cocos2dx_fgui_GAnimation_update(lua_State* tolua_S)
{
    int argc = 0;
    fgui::GAnimation* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"fgui::GAnimation",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (fgui::GAnimation*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_fgui_GAnimation_update'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 1) 
    {
        double arg0;

        ok &= luaval_to_number(tolua_S, 2,&arg0, "fgui::GAnimation:update");
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_cocos2dx_fgui_GAnimation_update'", nullptr);
            return 0;
        }
        cobj->update(arg0);
        lua_settop(tolua_S, 1);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "fgui::GAnimation:update",argc, 1);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_fgui_GAnimation_update'.",&tolua_err);
#endif

    return 0;
}
int lua_cocos2dx_fgui_GAnimation_setIsPlaying(lua_State* tolua_S)
{
    int argc = 0;
    fgui::GAnimation* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"fgui::GAnimation",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (fgui::GAnimation*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_fgui_GAnimation_setIsPlaying'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 1) 
    {
        bool arg0;

        ok &= luaval_to_boolean(tolua_S, 2,&arg0, "fgui::GAnimation:setIsPlaying");
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_cocos2dx_fgui_GAnimation_setIsPlaying'", nullptr);
            return 0;
        }
        cobj->setIsPlaying(arg0);
        lua_settop(tolua_S, 1);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "fgui::GAnimation:setIsPlaying",argc, 1);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_fgui_GAnimation_setIsPlaying'.",&tolua_err);
#endif

    return 0;
}
int lua_cocos2dx_fgui_GAnimation_setLoops(lua_State* tolua_S)
{
    int argc = 0;
    fgui::GAnimation* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"fgui::GAnimation",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (fgui::GAnimation*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_fgui_GAnimation_setLoops'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 1) 
    {
        unsigned int arg0;

        ok &= luaval_to_uint32(tolua_S, 2,&arg0, "fgui::GAnimation:setLoops");
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_cocos2dx_fgui_GAnimation_setLoops'", nullptr);
            return 0;
        }
        cobj->setLoops(arg0);
        lua_settop(tolua_S, 1);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "fgui::GAnimation:setLoops",argc, 1);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_fgui_GAnimation_setLoops'.",&tolua_err);
#endif

    return 0;
}
int lua_cocos2dx_fgui_GAnimation_getLoops(lua_State* tolua_S)
{
    int argc = 0;
    fgui::GAnimation* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"fgui::GAnimation",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (fgui::GAnimation*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_fgui_GAnimation_getLoops'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_cocos2dx_fgui_GAnimation_getLoops'", nullptr);
            return 0;
        }
        unsigned int ret = cobj->getLoops();
        tolua_pushnumber(tolua_S,(lua_Number)ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "fgui::GAnimation:getLoops",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_fgui_GAnimation_getLoops'.",&tolua_err);
#endif

    return 0;
}
int lua_cocos2dx_fgui_GAnimation_setPlayTime(lua_State* tolua_S)
{
    int argc = 0;
    fgui::GAnimation* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"fgui::GAnimation",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (fgui::GAnimation*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_fgui_GAnimation_setPlayTime'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 1) 
    {
        double arg0;

        ok &= luaval_to_number(tolua_S, 2,&arg0, "fgui::GAnimation:setPlayTime");
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_cocos2dx_fgui_GAnimation_setPlayTime'", nullptr);
            return 0;
        }
        cobj->setPlayTime(arg0);
        lua_settop(tolua_S, 1);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "fgui::GAnimation:setPlayTime",argc, 1);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_fgui_GAnimation_setPlayTime'.",&tolua_err);
#endif

    return 0;
}
int lua_cocos2dx_fgui_GAnimation_isPlaying(lua_State* tolua_S)
{
    int argc = 0;
    fgui::GAnimation* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"fgui::GAnimation",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (fgui::GAnimation*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_fgui_GAnimation_isPlaying'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_cocos2dx_fgui_GAnimation_isPlaying'", nullptr);
            return 0;
        }
        bool ret = cobj->isPlaying();
        tolua_pushboolean(tolua_S,(bool)ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "fgui::GAnimation:isPlaying",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_fgui_GAnimation_isPlaying'.",&tolua_err);
#endif

    return 0;
}
int lua_cocos2dx_fgui_GAnimation_setIsStopAtLastFrame(lua_State* tolua_S)
{
    int argc = 0;
    fgui::GAnimation* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"fgui::GAnimation",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (fgui::GAnimation*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_fgui_GAnimation_setIsStopAtLastFrame'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 1) 
    {
        bool arg0;

        ok &= luaval_to_boolean(tolua_S, 2,&arg0, "fgui::GAnimation:setIsStopAtLastFrame");
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_cocos2dx_fgui_GAnimation_setIsStopAtLastFrame'", nullptr);
            return 0;
        }
        cobj->setIsStopAtLastFrame(arg0);
        lua_settop(tolua_S, 1);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "fgui::GAnimation:setIsStopAtLastFrame",argc, 1);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_fgui_GAnimation_setIsStopAtLastFrame'.",&tolua_err);
#endif

    return 0;
}
int lua_cocos2dx_fgui_GAnimation_getCurFrame(lua_State* tolua_S)
{
    int argc = 0;
    fgui::GAnimation* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"fgui::GAnimation",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (fgui::GAnimation*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_fgui_GAnimation_getCurFrame'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_cocos2dx_fgui_GAnimation_getCurFrame'", nullptr);
            return 0;
        }
        int ret = cobj->getCurFrame();
        tolua_pushnumber(tolua_S,(lua_Number)ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "fgui::GAnimation:getCurFrame",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_fgui_GAnimation_getCurFrame'.",&tolua_err);
#endif

    return 0;
}
int lua_cocos2dx_fgui_GAnimation_setAutoUpdate(lua_State* tolua_S)
{
    int argc = 0;
    fgui::GAnimation* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"fgui::GAnimation",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (fgui::GAnimation*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_fgui_GAnimation_setAutoUpdate'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 1) 
    {
        bool arg0;

        ok &= luaval_to_boolean(tolua_S, 2,&arg0, "fgui::GAnimation:setAutoUpdate");
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_cocos2dx_fgui_GAnimation_setAutoUpdate'", nullptr);
            return 0;
        }
        cobj->setAutoUpdate(arg0);
        lua_settop(tolua_S, 1);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "fgui::GAnimation:setAutoUpdate",argc, 1);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_fgui_GAnimation_setAutoUpdate'.",&tolua_err);
#endif

    return 0;
}
int lua_cocos2dx_fgui_GAnimation_create(lua_State* tolua_S)
{
    int argc = 0;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif

#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertable(tolua_S,1,"fgui::GAnimation",0,&tolua_err)) goto tolua_lerror;
#endif

    argc = lua_gettop(tolua_S) - 1;

    if (argc == 0)
    {
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_cocos2dx_fgui_GAnimation_create'", nullptr);
            return 0;
        }
        fgui::GAnimation* ret = fgui::GAnimation::create();
        object_to_luaval<fgui::GAnimation>(tolua_S, "fgui::GAnimation",(fgui::GAnimation*)ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d\n ", "fgui::GAnimation:create",argc, 0);
    return 0;
#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_fgui_GAnimation_create'.",&tolua_err);
#endif
    return 0;
}
int lua_cocos2dx_fgui_GAnimation_constructor(lua_State* tolua_S)
{
    int argc = 0;
    fgui::GAnimation* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif



    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_cocos2dx_fgui_GAnimation_constructor'", nullptr);
            return 0;
        }
        cobj = new fgui::GAnimation();
        cobj->autorelease();
        int ID =  (int)cobj->_ID ;
        int* luaID =  &cobj->_luaID ;
        toluafix_pushusertype_ccobject(tolua_S, ID, luaID, (void*)cobj,"fgui::GAnimation");
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "fgui::GAnimation:GAnimation",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_fgui_GAnimation_constructor'.",&tolua_err);
#endif

    return 0;
}

static int lua_cocos2dx_fgui_GAnimation_finalize(lua_State* tolua_S)
{
    printf("luabindings: finalizing LUA object (GAnimation)");
    return 0;
}

int lua_register_cocos2dx_fgui_GAnimation(lua_State* tolua_S)
{
    tolua_usertype(tolua_S,"fgui::GAnimation");
    tolua_cclass(tolua_S,"GAnimation","fgui::GAnimation","cc.Sprite",nullptr);

    tolua_beginmodule(tolua_S,"GAnimation");
        tolua_function(tolua_S,"new",lua_cocos2dx_fgui_GAnimation_constructor);
        tolua_function(tolua_S,"setIsSwing",lua_cocos2dx_fgui_GAnimation_setIsSwing);
        tolua_function(tolua_S,"pause",lua_cocos2dx_fgui_GAnimation_pause);
        tolua_function(tolua_S,"play",lua_cocos2dx_fgui_GAnimation_play);
        tolua_function(tolua_S,"setTimeScale",lua_cocos2dx_fgui_GAnimation_setTimeScale);
        tolua_function(tolua_S,"setHSVValue",lua_cocos2dx_fgui_GAnimation_setHSVValue);
        tolua_function(tolua_S,"resume",lua_cocos2dx_fgui_GAnimation_resume);
        tolua_function(tolua_S,"setCurFrame",lua_cocos2dx_fgui_GAnimation_setCurFrame);
        tolua_function(tolua_S,"setHSVMode",lua_cocos2dx_fgui_GAnimation_setHSVMode);
        tolua_function(tolua_S,"update",lua_cocos2dx_fgui_GAnimation_update);
        tolua_function(tolua_S,"setIsPlaying",lua_cocos2dx_fgui_GAnimation_setIsPlaying);
        tolua_function(tolua_S,"setLoops",lua_cocos2dx_fgui_GAnimation_setLoops);
        tolua_function(tolua_S,"getLoops",lua_cocos2dx_fgui_GAnimation_getLoops);
        tolua_function(tolua_S,"setPlayTime",lua_cocos2dx_fgui_GAnimation_setPlayTime);
        tolua_function(tolua_S,"isPlaying",lua_cocos2dx_fgui_GAnimation_isPlaying);
        tolua_function(tolua_S,"setIsStopAtLastFrame",lua_cocos2dx_fgui_GAnimation_setIsStopAtLastFrame);
        tolua_function(tolua_S,"getCurFrame",lua_cocos2dx_fgui_GAnimation_getCurFrame);
        tolua_function(tolua_S,"setAutoUpdate",lua_cocos2dx_fgui_GAnimation_setAutoUpdate);
        tolua_function(tolua_S,"create", lua_cocos2dx_fgui_GAnimation_create);
    tolua_endmodule(tolua_S);
    std::string typeName = typeid(fgui::GAnimation).name();
    g_luaType[typeName] = "fgui::GAnimation";
    g_typeCast["GAnimation"] = "fgui::GAnimation";
    return 1;
}

int lua_cocos2dx_fgui_GGroup_addNode(lua_State* tolua_S)
{
    int argc = 0;
    fgui::GGroup* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"fgui::GGroup",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (fgui::GGroup*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_fgui_GGroup_addNode'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 1) 
    {
        cocos2d::Node* arg0;

        ok &= luaval_to_object<cocos2d::Node>(tolua_S, 2, "cc.Node",&arg0, "fgui::GGroup:addNode");
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_cocos2dx_fgui_GGroup_addNode'", nullptr);
            return 0;
        }
        cobj->addNode(arg0);
        lua_settop(tolua_S, 1);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "fgui::GGroup:addNode",argc, 1);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_fgui_GGroup_addNode'.",&tolua_err);
#endif

    return 0;
}
int lua_cocos2dx_fgui_GGroup_removeNode(lua_State* tolua_S)
{
    int argc = 0;
    fgui::GGroup* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"fgui::GGroup",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (fgui::GGroup*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_fgui_GGroup_removeNode'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 1) 
    {
        cocos2d::Node* arg0;

        ok &= luaval_to_object<cocos2d::Node>(tolua_S, 2, "cc.Node",&arg0, "fgui::GGroup:removeNode");
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_cocos2dx_fgui_GGroup_removeNode'", nullptr);
            return 0;
        }
        cobj->removeNode(arg0);
        lua_settop(tolua_S, 1);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "fgui::GGroup:removeNode",argc, 1);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_fgui_GGroup_removeNode'.",&tolua_err);
#endif

    return 0;
}
int lua_cocos2dx_fgui_GGroup_setGap(lua_State* tolua_S)
{
    int argc = 0;
    fgui::GGroup* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"fgui::GGroup",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (fgui::GGroup*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_fgui_GGroup_setGap'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 2) 
    {
        int arg0;
        int arg1;

        ok &= luaval_to_int32(tolua_S, 2,(int *)&arg0, "fgui::GGroup:setGap");

        ok &= luaval_to_int32(tolua_S, 3,(int *)&arg1, "fgui::GGroup:setGap");
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_cocos2dx_fgui_GGroup_setGap'", nullptr);
            return 0;
        }
        cobj->setGap(arg0, arg1);
        lua_settop(tolua_S, 1);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "fgui::GGroup:setGap",argc, 2);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_fgui_GGroup_setGap'.",&tolua_err);
#endif

    return 0;
}
int lua_cocos2dx_fgui_GGroup_setOpacity(lua_State* tolua_S)
{
    int argc = 0;
    fgui::GGroup* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"fgui::GGroup",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (fgui::GGroup*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_fgui_GGroup_setOpacity'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 1) 
    {
        uint16_t arg0;

        ok &= luaval_to_uint16(tolua_S, 2,&arg0, "fgui::GGroup:setOpacity");
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_cocos2dx_fgui_GGroup_setOpacity'", nullptr);
            return 0;
        }
        cobj->setOpacity(arg0);
        lua_settop(tolua_S, 1);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "fgui::GGroup:setOpacity",argc, 1);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_fgui_GGroup_setOpacity'.",&tolua_err);
#endif

    return 0;
}
int lua_cocos2dx_fgui_GGroup_setBgVisible(lua_State* tolua_S)
{
    int argc = 0;
    fgui::GGroup* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"fgui::GGroup",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (fgui::GGroup*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_fgui_GGroup_setBgVisible'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 1) 
    {
        bool arg0;

        ok &= luaval_to_boolean(tolua_S, 2,&arg0, "fgui::GGroup:setBgVisible");
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_cocos2dx_fgui_GGroup_setBgVisible'", nullptr);
            return 0;
        }
        cobj->setBgVisible(arg0);
        lua_settop(tolua_S, 1);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "fgui::GGroup:setBgVisible",argc, 1);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_fgui_GGroup_setBgVisible'.",&tolua_err);
#endif

    return 0;
}
int lua_cocos2dx_fgui_GGroup_setContentSize(lua_State* tolua_S)
{
    int argc = 0;
    fgui::GGroup* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"fgui::GGroup",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (fgui::GGroup*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_fgui_GGroup_setContentSize'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 1) 
    {
        cocos2d::Size arg0;

        ok &= luaval_to_size(tolua_S, 2, &arg0, "fgui::GGroup:setContentSize");
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_cocos2dx_fgui_GGroup_setContentSize'", nullptr);
            return 0;
        }
        cobj->setContentSize(arg0);
        lua_settop(tolua_S, 1);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "fgui::GGroup:setContentSize",argc, 1);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_fgui_GGroup_setContentSize'.",&tolua_err);
#endif

    return 0;
}
int lua_cocos2dx_fgui_GGroup_setVisible(lua_State* tolua_S)
{
    int argc = 0;
    fgui::GGroup* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"fgui::GGroup",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (fgui::GGroup*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_fgui_GGroup_setVisible'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 1) 
    {
        bool arg0;

        ok &= luaval_to_boolean(tolua_S, 2,&arg0, "fgui::GGroup:setVisible");
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_cocos2dx_fgui_GGroup_setVisible'", nullptr);
            return 0;
        }
        cobj->setVisible(arg0);
        lua_settop(tolua_S, 1);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "fgui::GGroup:setVisible",argc, 1);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_fgui_GGroup_setVisible'.",&tolua_err);
#endif

    return 0;
}
int lua_cocos2dx_fgui_GGroup_setPosition(lua_State* tolua_S)
{
    int argc = 0;
    fgui::GGroup* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"fgui::GGroup",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (fgui::GGroup*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_fgui_GGroup_setPosition'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 2) 
    {
        double arg0;
        double arg1;

        ok &= luaval_to_number(tolua_S, 2,&arg0, "fgui::GGroup:setPosition");

        ok &= luaval_to_number(tolua_S, 3,&arg1, "fgui::GGroup:setPosition");
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_cocos2dx_fgui_GGroup_setPosition'", nullptr);
            return 0;
        }
        cobj->setPosition(arg0, arg1);
        lua_settop(tolua_S, 1);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "fgui::GGroup:setPosition",argc, 2);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_fgui_GGroup_setPosition'.",&tolua_err);
#endif

    return 0;
}
int lua_cocos2dx_fgui_GGroup_updateLayout(lua_State* tolua_S)
{
    int argc = 0;
    fgui::GGroup* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"fgui::GGroup",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (fgui::GGroup*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_fgui_GGroup_updateLayout'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_cocos2dx_fgui_GGroup_updateLayout'", nullptr);
            return 0;
        }
        cobj->updateLayout();
        lua_settop(tolua_S, 1);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "fgui::GGroup:updateLayout",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_fgui_GGroup_updateLayout'.",&tolua_err);
#endif

    return 0;
}
int lua_cocos2dx_fgui_GGroup_create(lua_State* tolua_S)
{
    int argc = 0;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif

#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertable(tolua_S,1,"fgui::GGroup",0,&tolua_err)) goto tolua_lerror;
#endif

    argc = lua_gettop(tolua_S) - 1;

    if (argc == 0)
    {
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_cocos2dx_fgui_GGroup_create'", nullptr);
            return 0;
        }
        fgui::GGroup* ret = fgui::GGroup::create();
        object_to_luaval<fgui::GGroup>(tolua_S, "fgui::GGroup",(fgui::GGroup*)ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d\n ", "fgui::GGroup:create",argc, 0);
    return 0;
#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_fgui_GGroup_create'.",&tolua_err);
#endif
    return 0;
}
int lua_cocos2dx_fgui_GGroup_constructor(lua_State* tolua_S)
{
    int argc = 0;
    fgui::GGroup* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif



    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_cocos2dx_fgui_GGroup_constructor'", nullptr);
            return 0;
        }
        cobj = new fgui::GGroup();
        cobj->autorelease();
        int ID =  (int)cobj->_ID ;
        int* luaID =  &cobj->_luaID ;
        toluafix_pushusertype_ccobject(tolua_S, ID, luaID, (void*)cobj,"fgui::GGroup");
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "fgui::GGroup:GGroup",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_fgui_GGroup_constructor'.",&tolua_err);
#endif

    return 0;
}

static int lua_cocos2dx_fgui_GGroup_finalize(lua_State* tolua_S)
{
    printf("luabindings: finalizing LUA object (GGroup)");
    return 0;
}

int lua_register_cocos2dx_fgui_GGroup(lua_State* tolua_S)
{
    tolua_usertype(tolua_S,"fgui::GGroup");
    tolua_cclass(tolua_S,"GGroup","fgui::GGroup","cc.Node",nullptr);

    tolua_beginmodule(tolua_S,"GGroup");
        tolua_function(tolua_S,"new",lua_cocos2dx_fgui_GGroup_constructor);
        tolua_function(tolua_S,"addNode",lua_cocos2dx_fgui_GGroup_addNode);
        tolua_function(tolua_S,"removeNode",lua_cocos2dx_fgui_GGroup_removeNode);
        tolua_function(tolua_S,"setGap",lua_cocos2dx_fgui_GGroup_setGap);
        tolua_function(tolua_S,"setOpacity",lua_cocos2dx_fgui_GGroup_setOpacity);
        tolua_function(tolua_S,"setBgVisible",lua_cocos2dx_fgui_GGroup_setBgVisible);
        tolua_function(tolua_S,"setContentSize",lua_cocos2dx_fgui_GGroup_setContentSize);
        tolua_function(tolua_S,"setVisible",lua_cocos2dx_fgui_GGroup_setVisible);
        tolua_function(tolua_S,"setPosition",lua_cocos2dx_fgui_GGroup_setPosition);
        tolua_function(tolua_S,"updateLayout",lua_cocos2dx_fgui_GGroup_updateLayout);
        tolua_function(tolua_S,"create", lua_cocos2dx_fgui_GGroup_create);
    tolua_endmodule(tolua_S);
    std::string typeName = typeid(fgui::GGroup).name();
    g_luaType[typeName] = "fgui::GGroup";
    g_typeCast["GGroup"] = "fgui::GGroup";
    return 1;
}

int lua_cocos2dx_fgui_GGraph_getFillColor(lua_State* tolua_S)
{
    int argc = 0;
    fgui::GGraph* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"fgui::GGraph",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (fgui::GGraph*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_fgui_GGraph_getFillColor'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_cocos2dx_fgui_GGraph_getFillColor'", nullptr);
            return 0;
        }
        const cocos2d::Color4F& ret = cobj->getFillColor();
        color4f_to_luaval(tolua_S, ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "fgui::GGraph:getFillColor",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_fgui_GGraph_getFillColor'.",&tolua_err);
#endif

    return 0;
}
int lua_cocos2dx_fgui_GGraph_getLineColor(lua_State* tolua_S)
{
    int argc = 0;
    fgui::GGraph* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"fgui::GGraph",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (fgui::GGraph*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_fgui_GGraph_getLineColor'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_cocos2dx_fgui_GGraph_getLineColor'", nullptr);
            return 0;
        }
        const cocos2d::Color4F& ret = cobj->getLineColor();
        color4f_to_luaval(tolua_S, ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "fgui::GGraph:getLineColor",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_fgui_GGraph_getLineColor'.",&tolua_err);
#endif

    return 0;
}
int lua_cocos2dx_fgui_GGraph_setLineSize(lua_State* tolua_S)
{
    int argc = 0;
    fgui::GGraph* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"fgui::GGraph",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (fgui::GGraph*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_fgui_GGraph_setLineSize'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 1) 
    {
        int arg0;

        ok &= luaval_to_int32(tolua_S, 2,(int *)&arg0, "fgui::GGraph:setLineSize");
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_cocos2dx_fgui_GGraph_setLineSize'", nullptr);
            return 0;
        }
        cobj->setLineSize(arg0);
        lua_settop(tolua_S, 1);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "fgui::GGraph:setLineSize",argc, 1);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_fgui_GGraph_setLineSize'.",&tolua_err);
#endif

    return 0;
}
int lua_cocos2dx_fgui_GGraph_getType(lua_State* tolua_S)
{
    int argc = 0;
    fgui::GGraph* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"fgui::GGraph",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (fgui::GGraph*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_fgui_GGraph_getType'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_cocos2dx_fgui_GGraph_getType'", nullptr);
            return 0;
        }
        int ret = cobj->getType();
        tolua_pushnumber(tolua_S,(lua_Number)ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "fgui::GGraph:getType",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_fgui_GGraph_getType'.",&tolua_err);
#endif

    return 0;
}
int lua_cocos2dx_fgui_GGraph_getLineSize(lua_State* tolua_S)
{
    int argc = 0;
    fgui::GGraph* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"fgui::GGraph",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (fgui::GGraph*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_fgui_GGraph_getLineSize'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_cocos2dx_fgui_GGraph_getLineSize'", nullptr);
            return 0;
        }
        int ret = cobj->getLineSize();
        tolua_pushnumber(tolua_S,(lua_Number)ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "fgui::GGraph:getLineSize",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_fgui_GGraph_getLineSize'.",&tolua_err);
#endif

    return 0;
}
int lua_cocos2dx_fgui_GGraph_setFillColor(lua_State* tolua_S)
{
    int argc = 0;
    fgui::GGraph* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"fgui::GGraph",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (fgui::GGraph*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_fgui_GGraph_setFillColor'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 1) 
    {
        cocos2d::Color4B arg0;

        ok &=luaval_to_color4b(tolua_S, 2, &arg0, "fgui::GGraph:setFillColor");
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_cocos2dx_fgui_GGraph_setFillColor'", nullptr);
            return 0;
        }
        cobj->setFillColor(arg0);
        lua_settop(tolua_S, 1);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "fgui::GGraph:setFillColor",argc, 1);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_fgui_GGraph_setFillColor'.",&tolua_err);
#endif

    return 0;
}
int lua_cocos2dx_fgui_GGraph_setLineColor(lua_State* tolua_S)
{
    int argc = 0;
    fgui::GGraph* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"fgui::GGraph",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (fgui::GGraph*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_fgui_GGraph_setLineColor'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 1) 
    {
        cocos2d::Color4B arg0;

        ok &=luaval_to_color4b(tolua_S, 2, &arg0, "fgui::GGraph:setLineColor");
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_cocos2dx_fgui_GGraph_setLineColor'", nullptr);
            return 0;
        }
        cobj->setLineColor(arg0);
        lua_settop(tolua_S, 1);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "fgui::GGraph:setLineColor",argc, 1);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_fgui_GGraph_setLineColor'.",&tolua_err);
#endif

    return 0;
}
int lua_cocos2dx_fgui_GGraph_setType(lua_State* tolua_S)
{
    int argc = 0;
    fgui::GGraph* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"fgui::GGraph",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (fgui::GGraph*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_fgui_GGraph_setType'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 1) 
    {
        int arg0;

        ok &= luaval_to_int32(tolua_S, 2,(int *)&arg0, "fgui::GGraph:setType");
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_cocos2dx_fgui_GGraph_setType'", nullptr);
            return 0;
        }
        cobj->setType(arg0);
        lua_settop(tolua_S, 1);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "fgui::GGraph:setType",argc, 1);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_fgui_GGraph_setType'.",&tolua_err);
#endif

    return 0;
}
int lua_cocos2dx_fgui_GGraph_create(lua_State* tolua_S)
{
    int argc = 0;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif

#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertable(tolua_S,1,"fgui::GGraph",0,&tolua_err)) goto tolua_lerror;
#endif

    argc = lua_gettop(tolua_S) - 1;

    if (argc == 0)
    {
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_cocos2dx_fgui_GGraph_create'", nullptr);
            return 0;
        }
        fgui::GGraph* ret = fgui::GGraph::create();
        object_to_luaval<fgui::GGraph>(tolua_S, "fgui::GGraph",(fgui::GGraph*)ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d\n ", "fgui::GGraph:create",argc, 0);
    return 0;
#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_fgui_GGraph_create'.",&tolua_err);
#endif
    return 0;
}
int lua_cocos2dx_fgui_GGraph_constructor(lua_State* tolua_S)
{
    int argc = 0;
    fgui::GGraph* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif



    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_cocos2dx_fgui_GGraph_constructor'", nullptr);
            return 0;
        }
        cobj = new fgui::GGraph();
        cobj->autorelease();
        int ID =  (int)cobj->_ID ;
        int* luaID =  &cobj->_luaID ;
        toluafix_pushusertype_ccobject(tolua_S, ID, luaID, (void*)cobj,"fgui::GGraph");
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "fgui::GGraph:GGraph",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_fgui_GGraph_constructor'.",&tolua_err);
#endif

    return 0;
}

static int lua_cocos2dx_fgui_GGraph_finalize(lua_State* tolua_S)
{
    printf("luabindings: finalizing LUA object (GGraph)");
    return 0;
}

int lua_register_cocos2dx_fgui_GGraph(lua_State* tolua_S)
{
    tolua_usertype(tolua_S,"fgui::GGraph");
    tolua_cclass(tolua_S,"GGraph","fgui::GGraph","cc.DrawNode",nullptr);

    tolua_beginmodule(tolua_S,"GGraph");
        tolua_function(tolua_S,"new",lua_cocos2dx_fgui_GGraph_constructor);
        tolua_function(tolua_S,"getFillColor",lua_cocos2dx_fgui_GGraph_getFillColor);
        tolua_function(tolua_S,"getLineColor",lua_cocos2dx_fgui_GGraph_getLineColor);
        tolua_function(tolua_S,"setLineSize",lua_cocos2dx_fgui_GGraph_setLineSize);
        tolua_function(tolua_S,"getType",lua_cocos2dx_fgui_GGraph_getType);
        tolua_function(tolua_S,"getLineSize",lua_cocos2dx_fgui_GGraph_getLineSize);
        tolua_function(tolua_S,"setFillColor",lua_cocos2dx_fgui_GGraph_setFillColor);
        tolua_function(tolua_S,"setLineColor",lua_cocos2dx_fgui_GGraph_setLineColor);
        tolua_function(tolua_S,"setType",lua_cocos2dx_fgui_GGraph_setType);
        tolua_function(tolua_S,"create", lua_cocos2dx_fgui_GGraph_create);
    tolua_endmodule(tolua_S);
    std::string typeName = typeid(fgui::GGraph).name();
    g_luaType[typeName] = "fgui::GGraph";
    g_typeCast["GGraph"] = "fgui::GGraph";
    return 1;
}

int lua_cocos2dx_fgui_GLabel_getFontSize(lua_State* tolua_S)
{
    int argc = 0;
    fgui::GLabel* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"fgui::GLabel",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (fgui::GLabel*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_fgui_GLabel_getFontSize'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_cocos2dx_fgui_GLabel_getFontSize'", nullptr);
            return 0;
        }
        int ret = cobj->getFontSize();
        tolua_pushnumber(tolua_S,(lua_Number)ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "fgui::GLabel:getFontSize",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_fgui_GLabel_getFontSize'.",&tolua_err);
#endif

    return 0;
}
int lua_cocos2dx_fgui_GLabel_onEnter(lua_State* tolua_S)
{
    int argc = 0;
    fgui::GLabel* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"fgui::GLabel",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (fgui::GLabel*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_fgui_GLabel_onEnter'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_cocos2dx_fgui_GLabel_onEnter'", nullptr);
            return 0;
        }
        cobj->onEnter();
        lua_settop(tolua_S, 1);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "fgui::GLabel:onEnter",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_fgui_GLabel_onEnter'.",&tolua_err);
#endif

    return 0;
}
int lua_cocos2dx_fgui_GLabel_isBold(lua_State* tolua_S)
{
    int argc = 0;
    fgui::GLabel* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"fgui::GLabel",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (fgui::GLabel*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_fgui_GLabel_isBold'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_cocos2dx_fgui_GLabel_isBold'", nullptr);
            return 0;
        }
        bool ret = cobj->isBold();
        tolua_pushboolean(tolua_S,(bool)ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "fgui::GLabel:isBold",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_fgui_GLabel_isBold'.",&tolua_err);
#endif

    return 0;
}
int lua_cocos2dx_fgui_GLabel_setUnderLine(lua_State* tolua_S)
{
    int argc = 0;
    fgui::GLabel* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"fgui::GLabel",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (fgui::GLabel*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_fgui_GLabel_setUnderLine'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 1) 
    {
        bool arg0;

        ok &= luaval_to_boolean(tolua_S, 2,&arg0, "fgui::GLabel:setUnderLine");
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_cocos2dx_fgui_GLabel_setUnderLine'", nullptr);
            return 0;
        }
        cobj->setUnderLine(arg0);
        lua_settop(tolua_S, 1);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "fgui::GLabel:setUnderLine",argc, 1);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_fgui_GLabel_setUnderLine'.",&tolua_err);
#endif

    return 0;
}
int lua_cocos2dx_fgui_GLabel_setTextFormat(lua_State* tolua_S)
{
    int argc = 0;
    fgui::GLabel* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"fgui::GLabel",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (fgui::GLabel*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_fgui_GLabel_setTextFormat'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 1) 
    {
        const fgui::TextFormat* arg0;

        ok &= luaval_to_object<const fgui::TextFormat>(tolua_S, 2, "fgui::TextFormat",&arg0, "fgui::GLabel:setTextFormat");
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_cocos2dx_fgui_GLabel_setTextFormat'", nullptr);
            return 0;
        }
        cobj->setTextFormat(arg0);
        lua_settop(tolua_S, 1);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "fgui::GLabel:setTextFormat",argc, 1);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_fgui_GLabel_setTextFormat'.",&tolua_err);
#endif

    return 0;
}
int lua_cocos2dx_fgui_GLabel_getTextFormat(lua_State* tolua_S)
{
    int argc = 0;
    fgui::GLabel* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"fgui::GLabel",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (fgui::GLabel*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_fgui_GLabel_getTextFormat'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_cocos2dx_fgui_GLabel_getTextFormat'", nullptr);
            return 0;
        }
        fgui::TextFormat* ret = cobj->getTextFormat();
        object_to_luaval<fgui::TextFormat>(tolua_S, "fgui::TextFormat",(fgui::TextFormat*)ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "fgui::GLabel:getTextFormat",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_fgui_GLabel_getTextFormat'.",&tolua_err);
#endif

    return 0;
}
int lua_cocos2dx_fgui_GLabel_isItalics(lua_State* tolua_S)
{
    int argc = 0;
    fgui::GLabel* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"fgui::GLabel",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (fgui::GLabel*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_fgui_GLabel_isItalics'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_cocos2dx_fgui_GLabel_isItalics'", nullptr);
            return 0;
        }
        bool ret = cobj->isItalics();
        tolua_pushboolean(tolua_S,(bool)ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "fgui::GLabel:isItalics",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_fgui_GLabel_isItalics'.",&tolua_err);
#endif

    return 0;
}
int lua_cocos2dx_fgui_GLabel_setBold(lua_State* tolua_S)
{
    int argc = 0;
    fgui::GLabel* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"fgui::GLabel",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (fgui::GLabel*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_fgui_GLabel_setBold'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 1) 
    {
        bool arg0;

        ok &= luaval_to_boolean(tolua_S, 2,&arg0, "fgui::GLabel:setBold");
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_cocos2dx_fgui_GLabel_setBold'", nullptr);
            return 0;
        }
        cobj->setBold(arg0);
        lua_settop(tolua_S, 1);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "fgui::GLabel:setBold",argc, 1);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_fgui_GLabel_setBold'.",&tolua_err);
#endif

    return 0;
}
int lua_cocos2dx_fgui_GLabel_isUnderLine(lua_State* tolua_S)
{
    int argc = 0;
    fgui::GLabel* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"fgui::GLabel",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (fgui::GLabel*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_fgui_GLabel_isUnderLine'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_cocos2dx_fgui_GLabel_isUnderLine'", nullptr);
            return 0;
        }
        bool ret = cobj->isUnderLine();
        tolua_pushboolean(tolua_S,(bool)ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "fgui::GLabel:isUnderLine",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_fgui_GLabel_isUnderLine'.",&tolua_err);
#endif

    return 0;
}
int lua_cocos2dx_fgui_GLabel_setPosition(lua_State* tolua_S)
{
    int argc = 0;
    fgui::GLabel* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"fgui::GLabel",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (fgui::GLabel*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_fgui_GLabel_setPosition'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 2) 
    {
        double arg0;
        double arg1;

        ok &= luaval_to_number(tolua_S, 2,&arg0, "fgui::GLabel:setPosition");

        ok &= luaval_to_number(tolua_S, 3,&arg1, "fgui::GLabel:setPosition");
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_cocos2dx_fgui_GLabel_setPosition'", nullptr);
            return 0;
        }
        cobj->setPosition(arg0, arg1);
        lua_settop(tolua_S, 1);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "fgui::GLabel:setPosition",argc, 2);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_fgui_GLabel_setPosition'.",&tolua_err);
#endif

    return 0;
}
int lua_cocos2dx_fgui_GLabel_setString(lua_State* tolua_S)
{
    int argc = 0;
    fgui::GLabel* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"fgui::GLabel",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (fgui::GLabel*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_fgui_GLabel_setString'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 1) 
    {
        std::string arg0;

        ok &= luaval_to_std_string(tolua_S, 2,&arg0, "fgui::GLabel:setString");
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_cocos2dx_fgui_GLabel_setString'", nullptr);
            return 0;
        }
        cobj->setString(arg0);
        lua_settop(tolua_S, 1);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "fgui::GLabel:setString",argc, 1);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_fgui_GLabel_setString'.",&tolua_err);
#endif

    return 0;
}
int lua_cocos2dx_fgui_GLabel_setSingleLine(lua_State* tolua_S)
{
    int argc = 0;
    fgui::GLabel* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"fgui::GLabel",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (fgui::GLabel*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_fgui_GLabel_setSingleLine'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 1) 
    {
        bool arg0;

        ok &= luaval_to_boolean(tolua_S, 2,&arg0, "fgui::GLabel:setSingleLine");
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_cocos2dx_fgui_GLabel_setSingleLine'", nullptr);
            return 0;
        }
        cobj->setSingleLine(arg0);
        lua_settop(tolua_S, 1);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "fgui::GLabel:setSingleLine",argc, 1);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_fgui_GLabel_setSingleLine'.",&tolua_err);
#endif

    return 0;
}
int lua_cocos2dx_fgui_GLabel_setOutline(lua_State* tolua_S)
{
    int argc = 0;
    fgui::GLabel* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"fgui::GLabel",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (fgui::GLabel*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_fgui_GLabel_setOutline'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 2) 
    {
        cocos2d::Color4B arg0;
        int arg1;

        ok &=luaval_to_color4b(tolua_S, 2, &arg0, "fgui::GLabel:setOutline");

        ok &= luaval_to_int32(tolua_S, 3,(int *)&arg1, "fgui::GLabel:setOutline");
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_cocos2dx_fgui_GLabel_setOutline'", nullptr);
            return 0;
        }
        cobj->setOutline(arg0, arg1);
        lua_settop(tolua_S, 1);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "fgui::GLabel:setOutline",argc, 2);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_fgui_GLabel_setOutline'.",&tolua_err);
#endif

    return 0;
}
int lua_cocos2dx_fgui_GLabel_setBMFontFilePath(lua_State* tolua_S)
{
    int argc = 0;
    fgui::GLabel* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"fgui::GLabel",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (fgui::GLabel*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_fgui_GLabel_setBMFontFilePath'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 1) 
    {
        std::string arg0;

        ok &= luaval_to_std_string(tolua_S, 2,&arg0, "fgui::GLabel:setBMFontFilePath");
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_cocos2dx_fgui_GLabel_setBMFontFilePath'", nullptr);
            return 0;
        }
        bool ret = cobj->setBMFontFilePath(arg0);
        tolua_pushboolean(tolua_S,(bool)ret);
        return 1;
    }
    if (argc == 2) 
    {
        std::string arg0;
        cocos2d::Vec2 arg1;

        ok &= luaval_to_std_string(tolua_S, 2,&arg0, "fgui::GLabel:setBMFontFilePath");

        ok &= luaval_to_vec2(tolua_S, 3, &arg1, "fgui::GLabel:setBMFontFilePath");
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_cocos2dx_fgui_GLabel_setBMFontFilePath'", nullptr);
            return 0;
        }
        bool ret = cobj->setBMFontFilePath(arg0, arg1);
        tolua_pushboolean(tolua_S,(bool)ret);
        return 1;
    }
    if (argc == 3) 
    {
        std::string arg0;
        cocos2d::Vec2 arg1;
        double arg2;

        ok &= luaval_to_std_string(tolua_S, 2,&arg0, "fgui::GLabel:setBMFontFilePath");

        ok &= luaval_to_vec2(tolua_S, 3, &arg1, "fgui::GLabel:setBMFontFilePath");

        ok &= luaval_to_number(tolua_S, 4,&arg2, "fgui::GLabel:setBMFontFilePath");
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_cocos2dx_fgui_GLabel_setBMFontFilePath'", nullptr);
            return 0;
        }
        bool ret = cobj->setBMFontFilePath(arg0, arg1, arg2);
        tolua_pushboolean(tolua_S,(bool)ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "fgui::GLabel:setBMFontFilePath",argc, 1);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_fgui_GLabel_setBMFontFilePath'.",&tolua_err);
#endif

    return 0;
}
int lua_cocos2dx_fgui_GLabel_setShadow(lua_State* tolua_S)
{
    int argc = 0;
    fgui::GLabel* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"fgui::GLabel",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (fgui::GLabel*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_fgui_GLabel_setShadow'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 1) 
    {
        cocos2d::Color4B arg0;

        ok &=luaval_to_color4b(tolua_S, 2, &arg0, "fgui::GLabel:setShadow");
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_cocos2dx_fgui_GLabel_setShadow'", nullptr);
            return 0;
        }
        cobj->setShadow(arg0);
        lua_settop(tolua_S, 1);
        return 1;
    }
    if (argc == 2) 
    {
        cocos2d::Color4B arg0;
        cocos2d::Size arg1;

        ok &=luaval_to_color4b(tolua_S, 2, &arg0, "fgui::GLabel:setShadow");

        ok &= luaval_to_size(tolua_S, 3, &arg1, "fgui::GLabel:setShadow");
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_cocos2dx_fgui_GLabel_setShadow'", nullptr);
            return 0;
        }
        cobj->setShadow(arg0, arg1);
        lua_settop(tolua_S, 1);
        return 1;
    }
    if (argc == 3) 
    {
        cocos2d::Color4B arg0;
        cocos2d::Size arg1;
        int arg2;

        ok &=luaval_to_color4b(tolua_S, 2, &arg0, "fgui::GLabel:setShadow");

        ok &= luaval_to_size(tolua_S, 3, &arg1, "fgui::GLabel:setShadow");

        ok &= luaval_to_int32(tolua_S, 4,(int *)&arg2, "fgui::GLabel:setShadow");
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_cocos2dx_fgui_GLabel_setShadow'", nullptr);
            return 0;
        }
        cobj->setShadow(arg0, arg1, arg2);
        lua_settop(tolua_S, 1);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "fgui::GLabel:setShadow",argc, 1);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_fgui_GLabel_setShadow'.",&tolua_err);
#endif

    return 0;
}
int lua_cocos2dx_fgui_GLabel_setFontColor(lua_State* tolua_S)
{
    int argc = 0;
    fgui::GLabel* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"fgui::GLabel",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (fgui::GLabel*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_fgui_GLabel_setFontColor'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 1) 
    {
        cocos2d::Color4B arg0;

        ok &=luaval_to_color4b(tolua_S, 2, &arg0, "fgui::GLabel:setFontColor");
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_cocos2dx_fgui_GLabel_setFontColor'", nullptr);
            return 0;
        }
        cobj->setFontColor(arg0);
        lua_settop(tolua_S, 1);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "fgui::GLabel:setFontColor",argc, 1);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_fgui_GLabel_setFontColor'.",&tolua_err);
#endif

    return 0;
}
int lua_cocos2dx_fgui_GLabel_getFontName(lua_State* tolua_S)
{
    int argc = 0;
    fgui::GLabel* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"fgui::GLabel",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (fgui::GLabel*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_fgui_GLabel_getFontName'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_cocos2dx_fgui_GLabel_getFontName'", nullptr);
            return 0;
        }
        const std::string& ret = cobj->getFontName();
        lua_pushlstring(tolua_S,ret.c_str(),ret.length());
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "fgui::GLabel:getFontName",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_fgui_GLabel_getFontName'.",&tolua_err);
#endif

    return 0;
}
int lua_cocos2dx_fgui_GLabel_setHAlign(lua_State* tolua_S)
{
    int argc = 0;
    fgui::GLabel* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"fgui::GLabel",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (fgui::GLabel*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_fgui_GLabel_setHAlign'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 1) 
    {
        cocos2d::TextHAlignment arg0;

        ok &= luaval_to_int32(tolua_S, 2,(int *)&arg0, "fgui::GLabel:setHAlign");
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_cocos2dx_fgui_GLabel_setHAlign'", nullptr);
            return 0;
        }
        cobj->setHAlign(arg0);
        lua_settop(tolua_S, 1);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "fgui::GLabel:setHAlign",argc, 1);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_fgui_GLabel_setHAlign'.",&tolua_err);
#endif

    return 0;
}
int lua_cocos2dx_fgui_GLabel_isGlow(lua_State* tolua_S)
{
    int argc = 0;
    fgui::GLabel* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"fgui::GLabel",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (fgui::GLabel*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_fgui_GLabel_isGlow'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_cocos2dx_fgui_GLabel_isGlow'", nullptr);
            return 0;
        }
        bool ret = cobj->isGlow();
        tolua_pushboolean(tolua_S,(bool)ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "fgui::GLabel:isGlow",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_fgui_GLabel_isGlow'.",&tolua_err);
#endif

    return 0;
}
int lua_cocos2dx_fgui_GLabel_setFontName(lua_State* tolua_S)
{
    int argc = 0;
    fgui::GLabel* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"fgui::GLabel",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (fgui::GLabel*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_fgui_GLabel_setFontName'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 1) 
    {
        std::string arg0;

        ok &= luaval_to_std_string(tolua_S, 2,&arg0, "fgui::GLabel:setFontName");
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_cocos2dx_fgui_GLabel_setFontName'", nullptr);
            return 0;
        }
        cobj->setFontName(arg0);
        lua_settop(tolua_S, 1);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "fgui::GLabel:setFontName",argc, 1);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_fgui_GLabel_setFontName'.",&tolua_err);
#endif

    return 0;
}
int lua_cocos2dx_fgui_GLabel_getFontColor(lua_State* tolua_S)
{
    int argc = 0;
    fgui::GLabel* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"fgui::GLabel",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (fgui::GLabel*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_fgui_GLabel_getFontColor'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_cocos2dx_fgui_GLabel_getFontColor'", nullptr);
            return 0;
        }
        const cocos2d::Color4B& ret = cobj->getFontColor();
        color4b_to_luaval(tolua_S, ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "fgui::GLabel:getFontColor",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_fgui_GLabel_getFontColor'.",&tolua_err);
#endif

    return 0;
}
int lua_cocos2dx_fgui_GLabel_setItalics(lua_State* tolua_S)
{
    int argc = 0;
    fgui::GLabel* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"fgui::GLabel",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (fgui::GLabel*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_fgui_GLabel_setItalics'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 1) 
    {
        bool arg0;

        ok &= luaval_to_boolean(tolua_S, 2,&arg0, "fgui::GLabel:setItalics");
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_cocos2dx_fgui_GLabel_setItalics'", nullptr);
            return 0;
        }
        cobj->setItalics(arg0);
        lua_settop(tolua_S, 1);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "fgui::GLabel:setItalics",argc, 1);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_fgui_GLabel_setItalics'.",&tolua_err);
#endif

    return 0;
}
int lua_cocos2dx_fgui_GLabel_updateBMFontScale(lua_State* tolua_S)
{
    int argc = 0;
    fgui::GLabel* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"fgui::GLabel",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (fgui::GLabel*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_fgui_GLabel_updateBMFontScale'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_cocos2dx_fgui_GLabel_updateBMFontScale'", nullptr);
            return 0;
        }
        cobj->updateBMFontScale();
        lua_settop(tolua_S, 1);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "fgui::GLabel:updateBMFontScale",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_fgui_GLabel_updateBMFontScale'.",&tolua_err);
#endif

    return 0;
}
int lua_cocos2dx_fgui_GLabel_setGrayed(lua_State* tolua_S)
{
    int argc = 0;
    fgui::GLabel* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"fgui::GLabel",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (fgui::GLabel*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_fgui_GLabel_setGrayed'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 1) 
    {
        bool arg0;

        ok &= luaval_to_boolean(tolua_S, 2,&arg0, "fgui::GLabel:setGrayed");
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_cocos2dx_fgui_GLabel_setGrayed'", nullptr);
            return 0;
        }
        cobj->setGrayed(arg0);
        lua_settop(tolua_S, 1);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "fgui::GLabel:setGrayed",argc, 1);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_fgui_GLabel_setGrayed'.",&tolua_err);
#endif

    return 0;
}
int lua_cocos2dx_fgui_GLabel_setFontSize(lua_State* tolua_S)
{
    int argc = 0;
    fgui::GLabel* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"fgui::GLabel",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (fgui::GLabel*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_fgui_GLabel_setFontSize'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 1) 
    {
        int arg0;

        ok &= luaval_to_int32(tolua_S, 2,(int *)&arg0, "fgui::GLabel:setFontSize");
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_cocos2dx_fgui_GLabel_setFontSize'", nullptr);
            return 0;
        }
        cobj->setFontSize(arg0);
        lua_settop(tolua_S, 1);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "fgui::GLabel:setFontSize",argc, 1);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_fgui_GLabel_setFontSize'.",&tolua_err);
#endif

    return 0;
}
int lua_cocos2dx_fgui_GLabel_setContentSize(lua_State* tolua_S)
{
    int argc = 0;
    fgui::GLabel* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"fgui::GLabel",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (fgui::GLabel*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_fgui_GLabel_setContentSize'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 1) 
    {
        cocos2d::Size arg0;

        ok &= luaval_to_size(tolua_S, 2, &arg0, "fgui::GLabel:setContentSize");
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_cocos2dx_fgui_GLabel_setContentSize'", nullptr);
            return 0;
        }
        cobj->setContentSize(arg0);
        lua_settop(tolua_S, 1);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "fgui::GLabel:setContentSize",argc, 1);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_fgui_GLabel_setContentSize'.",&tolua_err);
#endif

    return 0;
}
int lua_cocos2dx_fgui_GLabel_applyTextFormat(lua_State* tolua_S)
{
    int argc = 0;
    fgui::GLabel* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"fgui::GLabel",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (fgui::GLabel*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_fgui_GLabel_applyTextFormat'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_cocos2dx_fgui_GLabel_applyTextFormat'", nullptr);
            return 0;
        }
        cobj->applyTextFormat();
        lua_settop(tolua_S, 1);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "fgui::GLabel:applyTextFormat",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_fgui_GLabel_applyTextFormat'.",&tolua_err);
#endif

    return 0;
}
int lua_cocos2dx_fgui_GLabel_hasShadow(lua_State* tolua_S)
{
    int argc = 0;
    fgui::GLabel* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"fgui::GLabel",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (fgui::GLabel*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_fgui_GLabel_hasShadow'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_cocos2dx_fgui_GLabel_hasShadow'", nullptr);
            return 0;
        }
        bool ret = cobj->hasShadow();
        tolua_pushboolean(tolua_S,(bool)ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "fgui::GLabel:hasShadow",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_fgui_GLabel_hasShadow'.",&tolua_err);
#endif

    return 0;
}
int lua_cocos2dx_fgui_GLabel_hasOutline(lua_State* tolua_S)
{
    int argc = 0;
    fgui::GLabel* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"fgui::GLabel",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (fgui::GLabel*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_fgui_GLabel_hasOutline'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_cocos2dx_fgui_GLabel_hasOutline'", nullptr);
            return 0;
        }
        bool ret = cobj->hasOutline();
        tolua_pushboolean(tolua_S,(bool)ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "fgui::GLabel:hasOutline",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_fgui_GLabel_hasOutline'.",&tolua_err);
#endif

    return 0;
}
int lua_cocos2dx_fgui_GLabel_setAutoSize(lua_State* tolua_S)
{
    int argc = 0;
    fgui::GLabel* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"fgui::GLabel",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (fgui::GLabel*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_fgui_GLabel_setAutoSize'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 1) 
    {
        fgui::AutoSizeType arg0;

        ok &= luaval_to_int32(tolua_S, 2,(int *)&arg0, "fgui::GLabel:setAutoSize");
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_cocos2dx_fgui_GLabel_setAutoSize'", nullptr);
            return 0;
        }
        cobj->setAutoSize(arg0);
        lua_settop(tolua_S, 1);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "fgui::GLabel:setAutoSize",argc, 1);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_fgui_GLabel_setAutoSize'.",&tolua_err);
#endif

    return 0;
}
int lua_cocos2dx_fgui_GLabel_onExit(lua_State* tolua_S)
{
    int argc = 0;
    fgui::GLabel* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"fgui::GLabel",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (fgui::GLabel*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_fgui_GLabel_onExit'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_cocos2dx_fgui_GLabel_onExit'", nullptr);
            return 0;
        }
        cobj->onExit();
        lua_settop(tolua_S, 1);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "fgui::GLabel:onExit",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_fgui_GLabel_onExit'.",&tolua_err);
#endif

    return 0;
}
int lua_cocos2dx_fgui_GLabel_setGlow(lua_State* tolua_S)
{
    int argc = 0;
    fgui::GLabel* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"fgui::GLabel",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (fgui::GLabel*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_fgui_GLabel_setGlow'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 1) 
    {
        cocos2d::Color4B arg0;

        ok &=luaval_to_color4b(tolua_S, 2, &arg0, "fgui::GLabel:setGlow");
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_cocos2dx_fgui_GLabel_setGlow'", nullptr);
            return 0;
        }
        cobj->setGlow(arg0);
        lua_settop(tolua_S, 1);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "fgui::GLabel:setGlow",argc, 1);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_fgui_GLabel_setGlow'.",&tolua_err);
#endif

    return 0;
}
int lua_cocos2dx_fgui_GLabel_setVAlign(lua_State* tolua_S)
{
    int argc = 0;
    fgui::GLabel* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"fgui::GLabel",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (fgui::GLabel*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_fgui_GLabel_setVAlign'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 1) 
    {
        cocos2d::TextVAlignment arg0;

        ok &= luaval_to_int32(tolua_S, 2,(int *)&arg0, "fgui::GLabel:setVAlign");
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_cocos2dx_fgui_GLabel_setVAlign'", nullptr);
            return 0;
        }
        cobj->setVAlign(arg0);
        lua_settop(tolua_S, 1);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "fgui::GLabel:setVAlign",argc, 1);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_fgui_GLabel_setVAlign'.",&tolua_err);
#endif

    return 0;
}
int lua_cocos2dx_fgui_GLabel_create(lua_State* tolua_S)
{
    int argc = 0;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif

#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertable(tolua_S,1,"fgui::GLabel",0,&tolua_err)) goto tolua_lerror;
#endif

    argc = lua_gettop(tolua_S) - 1;

    if (argc == 0)
    {
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_cocos2dx_fgui_GLabel_create'", nullptr);
            return 0;
        }
        fgui::GLabel* ret = fgui::GLabel::create();
        object_to_luaval<fgui::GLabel>(tolua_S, "fgui::GLabel",(fgui::GLabel*)ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d\n ", "fgui::GLabel:create",argc, 0);
    return 0;
#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_fgui_GLabel_create'.",&tolua_err);
#endif
    return 0;
}
static int lua_cocos2dx_fgui_GLabel_finalize(lua_State* tolua_S)
{
    printf("luabindings: finalizing LUA object (GLabel)");
    return 0;
}

int lua_register_cocos2dx_fgui_GLabel(lua_State* tolua_S)
{
    tolua_usertype(tolua_S,"fgui::GLabel");
    tolua_cclass(tolua_S,"GLabel","fgui::GLabel","cc.Label",nullptr);

    tolua_beginmodule(tolua_S,"GLabel");
        tolua_function(tolua_S,"getFontSize",lua_cocos2dx_fgui_GLabel_getFontSize);
        tolua_function(tolua_S,"onEnter",lua_cocos2dx_fgui_GLabel_onEnter);
        tolua_function(tolua_S,"isBold",lua_cocos2dx_fgui_GLabel_isBold);
        tolua_function(tolua_S,"setUnderLine",lua_cocos2dx_fgui_GLabel_setUnderLine);
        tolua_function(tolua_S,"setTextFormat",lua_cocos2dx_fgui_GLabel_setTextFormat);
        tolua_function(tolua_S,"getTextFormat",lua_cocos2dx_fgui_GLabel_getTextFormat);
        tolua_function(tolua_S,"isItalics",lua_cocos2dx_fgui_GLabel_isItalics);
        tolua_function(tolua_S,"setBold",lua_cocos2dx_fgui_GLabel_setBold);
        tolua_function(tolua_S,"isUnderLine",lua_cocos2dx_fgui_GLabel_isUnderLine);
        tolua_function(tolua_S,"setPosition",lua_cocos2dx_fgui_GLabel_setPosition);
        tolua_function(tolua_S,"setString",lua_cocos2dx_fgui_GLabel_setString);
        tolua_function(tolua_S,"setSingleLine",lua_cocos2dx_fgui_GLabel_setSingleLine);
        tolua_function(tolua_S,"setOutline",lua_cocos2dx_fgui_GLabel_setOutline);
        tolua_function(tolua_S,"setBMFontFilePath",lua_cocos2dx_fgui_GLabel_setBMFontFilePath);
        tolua_function(tolua_S,"setShadow",lua_cocos2dx_fgui_GLabel_setShadow);
        tolua_function(tolua_S,"setFontColor",lua_cocos2dx_fgui_GLabel_setFontColor);
        tolua_function(tolua_S,"getFontName",lua_cocos2dx_fgui_GLabel_getFontName);
        tolua_function(tolua_S,"setHAlign",lua_cocos2dx_fgui_GLabel_setHAlign);
        tolua_function(tolua_S,"isGlow",lua_cocos2dx_fgui_GLabel_isGlow);
        tolua_function(tolua_S,"setFontName",lua_cocos2dx_fgui_GLabel_setFontName);
        tolua_function(tolua_S,"getFontColor",lua_cocos2dx_fgui_GLabel_getFontColor);
        tolua_function(tolua_S,"setItalics",lua_cocos2dx_fgui_GLabel_setItalics);
        tolua_function(tolua_S,"updateBMFontScale",lua_cocos2dx_fgui_GLabel_updateBMFontScale);
        tolua_function(tolua_S,"setGrayed",lua_cocos2dx_fgui_GLabel_setGrayed);
        tolua_function(tolua_S,"setFontSize",lua_cocos2dx_fgui_GLabel_setFontSize);
        tolua_function(tolua_S,"setContentSize",lua_cocos2dx_fgui_GLabel_setContentSize);
        tolua_function(tolua_S,"applyTextFormat",lua_cocos2dx_fgui_GLabel_applyTextFormat);
        tolua_function(tolua_S,"hasShadow",lua_cocos2dx_fgui_GLabel_hasShadow);
        tolua_function(tolua_S,"hasOutline",lua_cocos2dx_fgui_GLabel_hasOutline);
        tolua_function(tolua_S,"setAutoSize",lua_cocos2dx_fgui_GLabel_setAutoSize);
        tolua_function(tolua_S,"onExit",lua_cocos2dx_fgui_GLabel_onExit);
        tolua_function(tolua_S,"setGlow",lua_cocos2dx_fgui_GLabel_setGlow);
        tolua_function(tolua_S,"setVAlign",lua_cocos2dx_fgui_GLabel_setVAlign);
        tolua_function(tolua_S,"create", lua_cocos2dx_fgui_GLabel_create);
    tolua_endmodule(tolua_S);
    std::string typeName = typeid(fgui::GLabel).name();
    g_luaType[typeName] = "fgui::GLabel";
    g_typeCast["GLabel"] = "fgui::GLabel";
    return 1;
}

int lua_cocos2dx_fgui_GList_addChild(lua_State* tolua_S)
{
    int argc = 0;
    fgui::GList* cobj = nullptr;
    bool ok  = true;
#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif

#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"fgui::GList",0,&tolua_err)) goto tolua_lerror;
#endif
    cobj = (fgui::GList*)tolua_tousertype(tolua_S,1,0);
#if COCOS2D_DEBUG >= 1
    if (!cobj)
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_fgui_GList_addChild'", nullptr);
        return 0;
    }
#endif
    argc = lua_gettop(tolua_S)-1;
    do{
        if (argc == 3) {
            cocos2d::Node* arg0;
            ok &= luaval_to_object<cocos2d::Node>(tolua_S, 2, "cc.Node",&arg0, "fgui::GList:addChild");

            if (!ok) { break; }
            int arg1;
            ok &= luaval_to_int32(tolua_S, 3,(int *)&arg1, "fgui::GList:addChild");

            if (!ok) { break; }
            int arg2;
            ok &= luaval_to_int32(tolua_S, 4,(int *)&arg2, "fgui::GList:addChild");

            if (!ok) { break; }
            cobj->addChild(arg0, arg1, arg2);
            lua_settop(tolua_S, 1);
            return 1;
        }
    }while(0);
    ok  = true;
    do{
        if (argc == 3) {
            cocos2d::Node* arg0;
            ok &= luaval_to_object<cocos2d::Node>(tolua_S, 2, "cc.Node",&arg0, "fgui::GList:addChild");

            if (!ok) { break; }
            int arg1;
            ok &= luaval_to_int32(tolua_S, 3,(int *)&arg1, "fgui::GList:addChild");

            if (!ok) { break; }
            std::string arg2;
            ok &= luaval_to_std_string(tolua_S, 4,&arg2, "fgui::GList:addChild");

            if (!ok) { break; }
            cobj->addChild(arg0, arg1, arg2);
            lua_settop(tolua_S, 1);
            return 1;
        }
    }while(0);
    ok  = true;
    do{
        if (argc == 2) {
            cocos2d::Node* arg0;
            ok &= luaval_to_object<cocos2d::Node>(tolua_S, 2, "cc.Node",&arg0, "fgui::GList:addChild");

            if (!ok) { break; }
            int arg1;
            ok &= luaval_to_int32(tolua_S, 3,(int *)&arg1, "fgui::GList:addChild");

            if (!ok) { break; }
            cobj->addChild(arg0, arg1);
            lua_settop(tolua_S, 1);
            return 1;
        }
    }while(0);
    ok  = true;
    do{
        if (argc == 1) {
            cocos2d::Node* arg0;
            ok &= luaval_to_object<cocos2d::Node>(tolua_S, 2, "cc.Node",&arg0, "fgui::GList:addChild");

            if (!ok) { break; }
            cobj->addChild(arg0);
            lua_settop(tolua_S, 1);
            return 1;
        }
    }while(0);
    ok  = true;
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n",  "fgui::GList:addChild",argc, 1);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_fgui_GList_addChild'.",&tolua_err);
#endif

    return 0;
}
int lua_cocos2dx_fgui_GList_setVirtualItemCount(lua_State* tolua_S)
{
    int argc = 0;
    fgui::GList* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"fgui::GList",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (fgui::GList*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_fgui_GList_setVirtualItemCount'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 1) 
    {
        int arg0;

        ok &= luaval_to_int32(tolua_S, 2,(int *)&arg0, "fgui::GList:setVirtualItemCount");
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_cocos2dx_fgui_GList_setVirtualItemCount'", nullptr);
            return 0;
        }
        cobj->setVirtualItemCount(arg0);
        lua_settop(tolua_S, 1);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "fgui::GList:setVirtualItemCount",argc, 1);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_fgui_GList_setVirtualItemCount'.",&tolua_err);
#endif

    return 0;
}
int lua_cocos2dx_fgui_GList_setVirtual(lua_State* tolua_S)
{
    int argc = 0;
    fgui::GList* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"fgui::GList",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (fgui::GList*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_fgui_GList_setVirtual'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_cocos2dx_fgui_GList_setVirtual'", nullptr);
            return 0;
        }
        cobj->setVirtual();
        lua_settop(tolua_S, 1);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "fgui::GList:setVirtual",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_fgui_GList_setVirtual'.",&tolua_err);
#endif

    return 0;
}
int lua_cocos2dx_fgui_GList_isVirtual(lua_State* tolua_S)
{
    int argc = 0;
    fgui::GList* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"fgui::GList",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (fgui::GList*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_fgui_GList_isVirtual'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_cocos2dx_fgui_GList_isVirtual'", nullptr);
            return 0;
        }
        bool ret = cobj->isVirtual();
        tolua_pushboolean(tolua_S,(bool)ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "fgui::GList:isVirtual",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_fgui_GList_isVirtual'.",&tolua_err);
#endif

    return 0;
}
int lua_cocos2dx_fgui_GList_setNodeUrl(lua_State* tolua_S)
{
    int argc = 0;
    fgui::GList* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"fgui::GList",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (fgui::GList*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_fgui_GList_setNodeUrl'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 1) 
    {
        std::string arg0;

        ok &= luaval_to_std_string(tolua_S, 2,&arg0, "fgui::GList:setNodeUrl");
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_cocos2dx_fgui_GList_setNodeUrl'", nullptr);
            return 0;
        }
        cobj->setNodeUrl(arg0);
        lua_settop(tolua_S, 1);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "fgui::GList:setNodeUrl",argc, 1);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_fgui_GList_setNodeUrl'.",&tolua_err);
#endif

    return 0;
}
int lua_cocos2dx_fgui_GList_getVirtualItemCount(lua_State* tolua_S)
{
    int argc = 0;
    fgui::GList* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"fgui::GList",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (fgui::GList*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_fgui_GList_getVirtualItemCount'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_cocos2dx_fgui_GList_getVirtualItemCount'", nullptr);
            return 0;
        }
        int ret = cobj->getVirtualItemCount();
        tolua_pushnumber(tolua_S,(lua_Number)ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "fgui::GList:getVirtualItemCount",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_fgui_GList_getVirtualItemCount'.",&tolua_err);
#endif

    return 0;
}
int lua_cocos2dx_fgui_GList_setLayoutInfo(lua_State* tolua_S)
{
    int argc = 0;
    fgui::GList* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"fgui::GList",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (fgui::GList*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_fgui_GList_setLayoutInfo'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 1) 
    {
        fgui::ListLayoutInfo arg0;

        #pragma warning NO CONVERSION TO NATIVE FOR ListLayoutInfo
		ok = false;
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_cocos2dx_fgui_GList_setLayoutInfo'", nullptr);
            return 0;
        }
        cobj->setLayoutInfo(arg0);
        lua_settop(tolua_S, 1);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "fgui::GList:setLayoutInfo",argc, 1);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_fgui_GList_setLayoutInfo'.",&tolua_err);
#endif

    return 0;
}
int lua_cocos2dx_fgui_GList_init(lua_State* tolua_S)
{
    int argc = 0;
    fgui::GList* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"fgui::GList",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (fgui::GList*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_fgui_GList_init'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_cocos2dx_fgui_GList_init'", nullptr);
            return 0;
        }
        bool ret = cobj->init();
        tolua_pushboolean(tolua_S,(bool)ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "fgui::GList:init",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_fgui_GList_init'.",&tolua_err);
#endif

    return 0;
}
int lua_cocos2dx_fgui_GList_create(lua_State* tolua_S)
{
    int argc = 0;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif

#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertable(tolua_S,1,"fgui::GList",0,&tolua_err)) goto tolua_lerror;
#endif

    argc = lua_gettop(tolua_S) - 1;

    if (argc == 0)
    {
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_cocos2dx_fgui_GList_create'", nullptr);
            return 0;
        }
        fgui::GList* ret = fgui::GList::create();
        object_to_luaval<fgui::GList>(tolua_S, "fgui::GList",(fgui::GList*)ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d\n ", "fgui::GList:create",argc, 0);
    return 0;
#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_fgui_GList_create'.",&tolua_err);
#endif
    return 0;
}
int lua_cocos2dx_fgui_GList_constructor(lua_State* tolua_S)
{
    int argc = 0;
    fgui::GList* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif



    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_cocos2dx_fgui_GList_constructor'", nullptr);
            return 0;
        }
        cobj = new fgui::GList();
        cobj->autorelease();
        int ID =  (int)cobj->_ID ;
        int* luaID =  &cobj->_luaID ;
        toluafix_pushusertype_ccobject(tolua_S, ID, luaID, (void*)cobj,"fgui::GList");
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "fgui::GList:GList",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_fgui_GList_constructor'.",&tolua_err);
#endif

    return 0;
}

static int lua_cocos2dx_fgui_GList_finalize(lua_State* tolua_S)
{
    printf("luabindings: finalizing LUA object (GList)");
    return 0;
}

int lua_register_cocos2dx_fgui_GList(lua_State* tolua_S)
{
    tolua_usertype(tolua_S,"fgui::GList");
    tolua_cclass(tolua_S,"GList","fgui::GList","fgui::GComponent",nullptr);

    tolua_beginmodule(tolua_S,"GList");
        tolua_function(tolua_S,"new",lua_cocos2dx_fgui_GList_constructor);
        tolua_function(tolua_S,"addChild",lua_cocos2dx_fgui_GList_addChild);
        tolua_function(tolua_S,"setVirtualItemCount",lua_cocos2dx_fgui_GList_setVirtualItemCount);
        tolua_function(tolua_S,"setVirtual",lua_cocos2dx_fgui_GList_setVirtual);
        tolua_function(tolua_S,"isVirtual",lua_cocos2dx_fgui_GList_isVirtual);
        tolua_function(tolua_S,"setNodeUrl",lua_cocos2dx_fgui_GList_setNodeUrl);
        tolua_function(tolua_S,"getVirtualItemCount",lua_cocos2dx_fgui_GList_getVirtualItemCount);
        tolua_function(tolua_S,"setLayoutInfo",lua_cocos2dx_fgui_GList_setLayoutInfo);
        tolua_function(tolua_S,"init",lua_cocos2dx_fgui_GList_init);
        tolua_function(tolua_S,"create", lua_cocos2dx_fgui_GList_create);
    tolua_endmodule(tolua_S);
    std::string typeName = typeid(fgui::GList).name();
    g_luaType[typeName] = "fgui::GList";
    g_typeCast["GList"] = "fgui::GList";
    return 1;
}

int lua_cocos2dx_fgui_GLoader_getURL(lua_State* tolua_S)
{
    int argc = 0;
    fgui::GLoader* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"fgui::GLoader",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (fgui::GLoader*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_fgui_GLoader_getURL'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_cocos2dx_fgui_GLoader_getURL'", nullptr);
            return 0;
        }
        const std::string& ret = cobj->getURL();
        lua_pushlstring(tolua_S,ret.c_str(),ret.length());
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "fgui::GLoader:getURL",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_fgui_GLoader_getURL'.",&tolua_err);
#endif

    return 0;
}
int lua_cocos2dx_fgui_GLoader_onEnter(lua_State* tolua_S)
{
    int argc = 0;
    fgui::GLoader* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"fgui::GLoader",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (fgui::GLoader*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_fgui_GLoader_onEnter'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_cocos2dx_fgui_GLoader_onEnter'", nullptr);
            return 0;
        }
        cobj->onEnter();
        lua_settop(tolua_S, 1);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "fgui::GLoader:onEnter",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_fgui_GLoader_onEnter'.",&tolua_err);
#endif

    return 0;
}
int lua_cocos2dx_fgui_GLoader_setHSVValue(lua_State* tolua_S)
{
    int argc = 0;
    fgui::GLoader* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"fgui::GLoader",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (fgui::GLoader*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_fgui_GLoader_setHSVValue'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 4) 
    {
        double arg0;
        double arg1;
        double arg2;
        double arg3;

        ok &= luaval_to_number(tolua_S, 2,&arg0, "fgui::GLoader:setHSVValue");

        ok &= luaval_to_number(tolua_S, 3,&arg1, "fgui::GLoader:setHSVValue");

        ok &= luaval_to_number(tolua_S, 4,&arg2, "fgui::GLoader:setHSVValue");

        ok &= luaval_to_number(tolua_S, 5,&arg3, "fgui::GLoader:setHSVValue");
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_cocos2dx_fgui_GLoader_setHSVValue'", nullptr);
            return 0;
        }
        cobj->setHSVValue(arg0, arg1, arg2, arg3);
        lua_settop(tolua_S, 1);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "fgui::GLoader:setHSVValue",argc, 4);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_fgui_GLoader_setHSVValue'.",&tolua_err);
#endif

    return 0;
}
int lua_cocos2dx_fgui_GLoader_setLayout(lua_State* tolua_S)
{
    int argc = 0;
    fgui::GLoader* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"fgui::GLoader",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (fgui::GLoader*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_fgui_GLoader_setLayout'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 3) 
    {
        fgui::LoaderFillType arg0;
        cocos2d::TextHAlignment arg1;
        cocos2d::TextVAlignment arg2;

        ok &= luaval_to_int32(tolua_S, 2,(int *)&arg0, "fgui::GLoader:setLayout");

        ok &= luaval_to_int32(tolua_S, 3,(int *)&arg1, "fgui::GLoader:setLayout");

        ok &= luaval_to_int32(tolua_S, 4,(int *)&arg2, "fgui::GLoader:setLayout");
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_cocos2dx_fgui_GLoader_setLayout'", nullptr);
            return 0;
        }
        cobj->setLayout(arg0, arg1, arg2);
        lua_settop(tolua_S, 1);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "fgui::GLoader:setLayout",argc, 3);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_fgui_GLoader_setLayout'.",&tolua_err);
#endif

    return 0;
}
int lua_cocos2dx_fgui_GLoader_setHSVMode(lua_State* tolua_S)
{
    int argc = 0;
    fgui::GLoader* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"fgui::GLoader",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (fgui::GLoader*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_fgui_GLoader_setHSVMode'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 1) 
    {
        bool arg0;

        ok &= luaval_to_boolean(tolua_S, 2,&arg0, "fgui::GLoader:setHSVMode");
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_cocos2dx_fgui_GLoader_setHSVMode'", nullptr);
            return 0;
        }
        cobj->setHSVMode(arg0);
        lua_settop(tolua_S, 1);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "fgui::GLoader:setHSVMode",argc, 1);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_fgui_GLoader_setHSVMode'.",&tolua_err);
#endif

    return 0;
}
int lua_cocos2dx_fgui_GLoader_getFillAmount(lua_State* tolua_S)
{
    int argc = 0;
    fgui::GLoader* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"fgui::GLoader",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (fgui::GLoader*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_fgui_GLoader_getFillAmount'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_cocos2dx_fgui_GLoader_getFillAmount'", nullptr);
            return 0;
        }
        double ret = cobj->getFillAmount();
        tolua_pushnumber(tolua_S,(lua_Number)ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "fgui::GLoader:getFillAmount",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_fgui_GLoader_getFillAmount'.",&tolua_err);
#endif

    return 0;
}
int lua_cocos2dx_fgui_GLoader_getFillOrigin(lua_State* tolua_S)
{
    int argc = 0;
    fgui::GLoader* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"fgui::GLoader",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (fgui::GLoader*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_fgui_GLoader_getFillOrigin'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_cocos2dx_fgui_GLoader_getFillOrigin'", nullptr);
            return 0;
        }
        int ret = (int)cobj->getFillOrigin();
        tolua_pushnumber(tolua_S,(lua_Number)ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "fgui::GLoader:getFillOrigin",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_fgui_GLoader_getFillOrigin'.",&tolua_err);
#endif

    return 0;
}
int lua_cocos2dx_fgui_GLoader_getHAlign(lua_State* tolua_S)
{
    int argc = 0;
    fgui::GLoader* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"fgui::GLoader",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (fgui::GLoader*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_fgui_GLoader_getHAlign'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_cocos2dx_fgui_GLoader_getHAlign'", nullptr);
            return 0;
        }
        int ret = (int)cobj->getHAlign();
        tolua_pushnumber(tolua_S,(lua_Number)ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "fgui::GLoader:getHAlign",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_fgui_GLoader_getHAlign'.",&tolua_err);
#endif

    return 0;
}
int lua_cocos2dx_fgui_GLoader_getOriginContentSize(lua_State* tolua_S)
{
    int argc = 0;
    fgui::GLoader* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"fgui::GLoader",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (fgui::GLoader*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_fgui_GLoader_getOriginContentSize'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_cocos2dx_fgui_GLoader_getOriginContentSize'", nullptr);
            return 0;
        }
        const cocos2d::Size& ret = cobj->getOriginContentSize();
        size_to_luaval(tolua_S, ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "fgui::GLoader:getOriginContentSize",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_fgui_GLoader_getOriginContentSize'.",&tolua_err);
#endif

    return 0;
}
int lua_cocos2dx_fgui_GLoader_setLoadFillType(lua_State* tolua_S)
{
    int argc = 0;
    fgui::GLoader* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"fgui::GLoader",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (fgui::GLoader*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_fgui_GLoader_setLoadFillType'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 1) 
    {
        fgui::LoaderFillType arg0;

        ok &= luaval_to_int32(tolua_S, 2,(int *)&arg0, "fgui::GLoader:setLoadFillType");
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_cocos2dx_fgui_GLoader_setLoadFillType'", nullptr);
            return 0;
        }
        cobj->setLoadFillType(arg0);
        lua_settop(tolua_S, 1);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "fgui::GLoader:setLoadFillType",argc, 1);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_fgui_GLoader_setLoadFillType'.",&tolua_err);
#endif

    return 0;
}
int lua_cocos2dx_fgui_GLoader_setFillMethod(lua_State* tolua_S)
{
    int argc = 0;
    fgui::GLoader* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"fgui::GLoader",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (fgui::GLoader*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_fgui_GLoader_setFillMethod'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 1) 
    {
        fgui::FillMethod arg0;

        ok &= luaval_to_int32(tolua_S, 2,(int *)&arg0, "fgui::GLoader:setFillMethod");
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_cocos2dx_fgui_GLoader_setFillMethod'", nullptr);
            return 0;
        }
        cobj->setFillMethod(arg0);
        lua_settop(tolua_S, 1);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "fgui::GLoader:setFillMethod",argc, 1);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_fgui_GLoader_setFillMethod'.",&tolua_err);
#endif

    return 0;
}
int lua_cocos2dx_fgui_GLoader_setFillClockwise(lua_State* tolua_S)
{
    int argc = 0;
    fgui::GLoader* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"fgui::GLoader",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (fgui::GLoader*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_fgui_GLoader_setFillClockwise'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 1) 
    {
        bool arg0;

        ok &= luaval_to_boolean(tolua_S, 2,&arg0, "fgui::GLoader:setFillClockwise");
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_cocos2dx_fgui_GLoader_setFillClockwise'", nullptr);
            return 0;
        }
        cobj->setFillClockwise(arg0);
        lua_settop(tolua_S, 1);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "fgui::GLoader:setFillClockwise",argc, 1);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_fgui_GLoader_setFillClockwise'.",&tolua_err);
#endif

    return 0;
}
int lua_cocos2dx_fgui_GLoader_getFillMethod(lua_State* tolua_S)
{
    int argc = 0;
    fgui::GLoader* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"fgui::GLoader",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (fgui::GLoader*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_fgui_GLoader_getFillMethod'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_cocos2dx_fgui_GLoader_getFillMethod'", nullptr);
            return 0;
        }
        int ret = (int)cobj->getFillMethod();
        tolua_pushnumber(tolua_S,(lua_Number)ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "fgui::GLoader:getFillMethod",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_fgui_GLoader_getFillMethod'.",&tolua_err);
#endif

    return 0;
}
int lua_cocos2dx_fgui_GLoader_isFillClockwise(lua_State* tolua_S)
{
    int argc = 0;
    fgui::GLoader* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"fgui::GLoader",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (fgui::GLoader*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_fgui_GLoader_isFillClockwise'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_cocos2dx_fgui_GLoader_isFillClockwise'", nullptr);
            return 0;
        }
        bool ret = cobj->isFillClockwise();
        tolua_pushboolean(tolua_S,(bool)ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "fgui::GLoader:isFillClockwise",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_fgui_GLoader_isFillClockwise'.",&tolua_err);
#endif

    return 0;
}
int lua_cocos2dx_fgui_GLoader_getContent(lua_State* tolua_S)
{
    int argc = 0;
    fgui::GLoader* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"fgui::GLoader",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (fgui::GLoader*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_fgui_GLoader_getContent'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_cocos2dx_fgui_GLoader_getContent'", nullptr);
            return 0;
        }
        cocos2d::Node* ret = cobj->getContent();
        object_to_luaval<cocos2d::Node>(tolua_S, "cc.Node",(cocos2d::Node*)ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "fgui::GLoader:getContent",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_fgui_GLoader_getContent'.",&tolua_err);
#endif

    return 0;
}
int lua_cocos2dx_fgui_GLoader_setFillOrigin(lua_State* tolua_S)
{
    int argc = 0;
    fgui::GLoader* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"fgui::GLoader",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (fgui::GLoader*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_fgui_GLoader_setFillOrigin'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 1) 
    {
        fgui::FillOrigin arg0;

        ok &= luaval_to_int32(tolua_S, 2,(int *)&arg0, "fgui::GLoader:setFillOrigin");
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_cocos2dx_fgui_GLoader_setFillOrigin'", nullptr);
            return 0;
        }
        cobj->setFillOrigin(arg0);
        lua_settop(tolua_S, 1);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "fgui::GLoader:setFillOrigin",argc, 1);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_fgui_GLoader_setFillOrigin'.",&tolua_err);
#endif

    return 0;
}
int lua_cocos2dx_fgui_GLoader_setAlign(lua_State* tolua_S)
{
    int argc = 0;
    fgui::GLoader* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"fgui::GLoader",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (fgui::GLoader*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_fgui_GLoader_setAlign'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 2) 
    {
        cocos2d::TextHAlignment arg0;
        cocos2d::TextVAlignment arg1;

        ok &= luaval_to_int32(tolua_S, 2,(int *)&arg0, "fgui::GLoader:setAlign");

        ok &= luaval_to_int32(tolua_S, 3,(int *)&arg1, "fgui::GLoader:setAlign");
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_cocos2dx_fgui_GLoader_setAlign'", nullptr);
            return 0;
        }
        cobj->setAlign(arg0, arg1);
        lua_settop(tolua_S, 1);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "fgui::GLoader:setAlign",argc, 2);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_fgui_GLoader_setAlign'.",&tolua_err);
#endif

    return 0;
}
int lua_cocos2dx_fgui_GLoader_setURL(lua_State* tolua_S)
{
    int argc = 0;
    fgui::GLoader* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"fgui::GLoader",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (fgui::GLoader*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_fgui_GLoader_setURL'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 1) 
    {
        std::string arg0;

        ok &= luaval_to_std_string(tolua_S, 2,&arg0, "fgui::GLoader:setURL");
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_cocos2dx_fgui_GLoader_setURL'", nullptr);
            return 0;
        }
        cobj->setURL(arg0);
        lua_settop(tolua_S, 1);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "fgui::GLoader:setURL",argc, 1);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_fgui_GLoader_setURL'.",&tolua_err);
#endif

    return 0;
}
int lua_cocos2dx_fgui_GLoader_setBlendMode(lua_State* tolua_S)
{
    int argc = 0;
    fgui::GLoader* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"fgui::GLoader",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (fgui::GLoader*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_fgui_GLoader_setBlendMode'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 1) 
    {
        fgui::BlendMode arg0;

        ok &= luaval_to_int32(tolua_S, 2,(int *)&arg0, "fgui::GLoader:setBlendMode");
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_cocos2dx_fgui_GLoader_setBlendMode'", nullptr);
            return 0;
        }
        cobj->setBlendMode(arg0);
        lua_settop(tolua_S, 1);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "fgui::GLoader:setBlendMode",argc, 1);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_fgui_GLoader_setBlendMode'.",&tolua_err);
#endif

    return 0;
}
int lua_cocos2dx_fgui_GLoader_setGrayed(lua_State* tolua_S)
{
    int argc = 0;
    fgui::GLoader* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"fgui::GLoader",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (fgui::GLoader*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_fgui_GLoader_setGrayed'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 1) 
    {
        bool arg0;

        ok &= luaval_to_boolean(tolua_S, 2,&arg0, "fgui::GLoader:setGrayed");
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_cocos2dx_fgui_GLoader_setGrayed'", nullptr);
            return 0;
        }
        cobj->setGrayed(arg0);
        lua_settop(tolua_S, 1);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "fgui::GLoader:setGrayed",argc, 1);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_fgui_GLoader_setGrayed'.",&tolua_err);
#endif

    return 0;
}
int lua_cocos2dx_fgui_GLoader_setPosition(lua_State* tolua_S)
{
    int argc = 0;
    fgui::GLoader* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"fgui::GLoader",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (fgui::GLoader*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_fgui_GLoader_setPosition'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 2) 
    {
        double arg0;
        double arg1;

        ok &= luaval_to_number(tolua_S, 2,&arg0, "fgui::GLoader:setPosition");

        ok &= luaval_to_number(tolua_S, 3,&arg1, "fgui::GLoader:setPosition");
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_cocos2dx_fgui_GLoader_setPosition'", nullptr);
            return 0;
        }
        cobj->setPosition(arg0, arg1);
        lua_settop(tolua_S, 1);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "fgui::GLoader:setPosition",argc, 2);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_fgui_GLoader_setPosition'.",&tolua_err);
#endif

    return 0;
}
int lua_cocos2dx_fgui_GLoader_onExit(lua_State* tolua_S)
{
    int argc = 0;
    fgui::GLoader* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"fgui::GLoader",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (fgui::GLoader*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_fgui_GLoader_onExit'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_cocos2dx_fgui_GLoader_onExit'", nullptr);
            return 0;
        }
        cobj->onExit();
        lua_settop(tolua_S, 1);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "fgui::GLoader:onExit",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_fgui_GLoader_onExit'.",&tolua_err);
#endif

    return 0;
}
int lua_cocos2dx_fgui_GLoader_setColor(lua_State* tolua_S)
{
    int argc = 0;
    fgui::GLoader* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"fgui::GLoader",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (fgui::GLoader*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_fgui_GLoader_setColor'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 1) 
    {
        cocos2d::Color3B arg0;

        ok &= luaval_to_color3b(tolua_S, 2, &arg0, "fgui::GLoader:setColor");
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_cocos2dx_fgui_GLoader_setColor'", nullptr);
            return 0;
        }
        cobj->setColor(arg0);
        lua_settop(tolua_S, 1);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "fgui::GLoader:setColor",argc, 1);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_fgui_GLoader_setColor'.",&tolua_err);
#endif

    return 0;
}
int lua_cocos2dx_fgui_GLoader_getVAlign(lua_State* tolua_S)
{
    int argc = 0;
    fgui::GLoader* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"fgui::GLoader",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (fgui::GLoader*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_fgui_GLoader_getVAlign'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_cocos2dx_fgui_GLoader_getVAlign'", nullptr);
            return 0;
        }
        int ret = (int)cobj->getVAlign();
        tolua_pushnumber(tolua_S,(lua_Number)ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "fgui::GLoader:getVAlign",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_fgui_GLoader_getVAlign'.",&tolua_err);
#endif

    return 0;
}
int lua_cocos2dx_fgui_GLoader_hitTest(lua_State* tolua_S)
{
    int argc = 0;
    fgui::GLoader* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"fgui::GLoader",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (fgui::GLoader*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_fgui_GLoader_hitTest'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 2) 
    {
        cocos2d::Vec2 arg0;
        const cocos2d::Camera* arg1;

        ok &= luaval_to_vec2(tolua_S, 2, &arg0, "fgui::GLoader:hitTest");

        ok &= luaval_to_object<const cocos2d::Camera>(tolua_S, 3, "cc.Camera",&arg1, "fgui::GLoader:hitTest");
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_cocos2dx_fgui_GLoader_hitTest'", nullptr);
            return 0;
        }
        cocos2d::Node* ret = cobj->hitTest(arg0, arg1);
        object_to_luaval<cocos2d::Node>(tolua_S, "cc.Node",(cocos2d::Node*)ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "fgui::GLoader:hitTest",argc, 2);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_fgui_GLoader_hitTest'.",&tolua_err);
#endif

    return 0;
}
int lua_cocos2dx_fgui_GLoader_setFillAmount(lua_State* tolua_S)
{
    int argc = 0;
    fgui::GLoader* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"fgui::GLoader",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (fgui::GLoader*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_fgui_GLoader_setFillAmount'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 1) 
    {
        double arg0;

        ok &= luaval_to_number(tolua_S, 2,&arg0, "fgui::GLoader:setFillAmount");
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_cocos2dx_fgui_GLoader_setFillAmount'", nullptr);
            return 0;
        }
        cobj->setFillAmount(arg0);
        lua_settop(tolua_S, 1);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "fgui::GLoader:setFillAmount",argc, 1);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_fgui_GLoader_setFillAmount'.",&tolua_err);
#endif

    return 0;
}
int lua_cocos2dx_fgui_GLoader_create(lua_State* tolua_S)
{
    int argc = 0;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif

#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertable(tolua_S,1,"fgui::GLoader",0,&tolua_err)) goto tolua_lerror;
#endif

    argc = lua_gettop(tolua_S) - 1;

    if (argc == 0)
    {
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_cocos2dx_fgui_GLoader_create'", nullptr);
            return 0;
        }
        fgui::GLoader* ret = fgui::GLoader::create();
        object_to_luaval<fgui::GLoader>(tolua_S, "fgui::GLoader",(fgui::GLoader*)ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d\n ", "fgui::GLoader:create",argc, 0);
    return 0;
#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_fgui_GLoader_create'.",&tolua_err);
#endif
    return 0;
}
int lua_cocos2dx_fgui_GLoader_constructor(lua_State* tolua_S)
{
    int argc = 0;
    fgui::GLoader* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif



    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_cocos2dx_fgui_GLoader_constructor'", nullptr);
            return 0;
        }
        cobj = new fgui::GLoader();
        cobj->autorelease();
        int ID =  (int)cobj->_ID ;
        int* luaID =  &cobj->_luaID ;
        toluafix_pushusertype_ccobject(tolua_S, ID, luaID, (void*)cobj,"fgui::GLoader");
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "fgui::GLoader:GLoader",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_fgui_GLoader_constructor'.",&tolua_err);
#endif

    return 0;
}

static int lua_cocos2dx_fgui_GLoader_finalize(lua_State* tolua_S)
{
    printf("luabindings: finalizing LUA object (GLoader)");
    return 0;
}

int lua_register_cocos2dx_fgui_GLoader(lua_State* tolua_S)
{
    tolua_usertype(tolua_S,"fgui::GLoader");
    tolua_cclass(tolua_S,"GLoader","fgui::GLoader","cc.Node",nullptr);

    tolua_beginmodule(tolua_S,"GLoader");
        tolua_function(tolua_S,"new",lua_cocos2dx_fgui_GLoader_constructor);
        tolua_function(tolua_S,"getURL",lua_cocos2dx_fgui_GLoader_getURL);
        tolua_function(tolua_S,"onEnter",lua_cocos2dx_fgui_GLoader_onEnter);
        tolua_function(tolua_S,"setHSVValue",lua_cocos2dx_fgui_GLoader_setHSVValue);
        tolua_function(tolua_S,"setLayout",lua_cocos2dx_fgui_GLoader_setLayout);
        tolua_function(tolua_S,"setHSVMode",lua_cocos2dx_fgui_GLoader_setHSVMode);
        tolua_function(tolua_S,"getFillAmount",lua_cocos2dx_fgui_GLoader_getFillAmount);
        tolua_function(tolua_S,"getFillOrigin",lua_cocos2dx_fgui_GLoader_getFillOrigin);
        tolua_function(tolua_S,"getHAlign",lua_cocos2dx_fgui_GLoader_getHAlign);
        tolua_function(tolua_S,"getOriginContentSize",lua_cocos2dx_fgui_GLoader_getOriginContentSize);
        tolua_function(tolua_S,"setLoadFillType",lua_cocos2dx_fgui_GLoader_setLoadFillType);
        tolua_function(tolua_S,"setFillMethod",lua_cocos2dx_fgui_GLoader_setFillMethod);
        tolua_function(tolua_S,"setFillClockwise",lua_cocos2dx_fgui_GLoader_setFillClockwise);
        tolua_function(tolua_S,"getFillMethod",lua_cocos2dx_fgui_GLoader_getFillMethod);
        tolua_function(tolua_S,"isFillClockwise",lua_cocos2dx_fgui_GLoader_isFillClockwise);
        tolua_function(tolua_S,"getContent",lua_cocos2dx_fgui_GLoader_getContent);
        tolua_function(tolua_S,"setFillOrigin",lua_cocos2dx_fgui_GLoader_setFillOrigin);
        tolua_function(tolua_S,"setAlign",lua_cocos2dx_fgui_GLoader_setAlign);
        tolua_function(tolua_S,"setURL",lua_cocos2dx_fgui_GLoader_setURL);
        tolua_function(tolua_S,"setBlendMode",lua_cocos2dx_fgui_GLoader_setBlendMode);
        tolua_function(tolua_S,"setGrayed",lua_cocos2dx_fgui_GLoader_setGrayed);
        tolua_function(tolua_S,"setPosition",lua_cocos2dx_fgui_GLoader_setPosition);
        tolua_function(tolua_S,"onExit",lua_cocos2dx_fgui_GLoader_onExit);
        tolua_function(tolua_S,"setColor",lua_cocos2dx_fgui_GLoader_setColor);
        tolua_function(tolua_S,"getVAlign",lua_cocos2dx_fgui_GLoader_getVAlign);
        tolua_function(tolua_S,"hitTest",lua_cocos2dx_fgui_GLoader_hitTest);
        tolua_function(tolua_S,"setFillAmount",lua_cocos2dx_fgui_GLoader_setFillAmount);
        tolua_function(tolua_S,"create", lua_cocos2dx_fgui_GLoader_create);
    tolua_endmodule(tolua_S);
    std::string typeName = typeid(fgui::GLoader).name();
    g_luaType[typeName] = "fgui::GLoader";
    g_typeCast["GLoader"] = "fgui::GLoader";
    return 1;
}

int lua_cocos2dx_fgui_GProgressBar_setValue(lua_State* tolua_S)
{
    int argc = 0;
    fgui::GProgressBar* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"fgui::GProgressBar",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (fgui::GProgressBar*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_fgui_GProgressBar_setValue'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 1) 
    {
        double arg0;

        ok &= luaval_to_number(tolua_S, 2,&arg0, "fgui::GProgressBar:setValue");
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_cocos2dx_fgui_GProgressBar_setValue'", nullptr);
            return 0;
        }
        cobj->setValue(arg0);
        lua_settop(tolua_S, 1);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "fgui::GProgressBar:setValue",argc, 1);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_fgui_GProgressBar_setValue'.",&tolua_err);
#endif

    return 0;
}
int lua_cocos2dx_fgui_GProgressBar_setIsReverse(lua_State* tolua_S)
{
    int argc = 0;
    fgui::GProgressBar* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"fgui::GProgressBar",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (fgui::GProgressBar*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_fgui_GProgressBar_setIsReverse'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 1) 
    {
        bool arg0;

        ok &= luaval_to_boolean(tolua_S, 2,&arg0, "fgui::GProgressBar:setIsReverse");
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_cocos2dx_fgui_GProgressBar_setIsReverse'", nullptr);
            return 0;
        }
        cobj->setIsReverse(arg0);
        lua_settop(tolua_S, 1);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "fgui::GProgressBar:setIsReverse",argc, 1);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_fgui_GProgressBar_setIsReverse'.",&tolua_err);
#endif

    return 0;
}
int lua_cocos2dx_fgui_GProgressBar_setMax(lua_State* tolua_S)
{
    int argc = 0;
    fgui::GProgressBar* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"fgui::GProgressBar",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (fgui::GProgressBar*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_fgui_GProgressBar_setMax'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 1) 
    {
        double arg0;

        ok &= luaval_to_number(tolua_S, 2,&arg0, "fgui::GProgressBar:setMax");
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_cocos2dx_fgui_GProgressBar_setMax'", nullptr);
            return 0;
        }
        cobj->setMax(arg0);
        lua_settop(tolua_S, 1);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "fgui::GProgressBar:setMax",argc, 1);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_fgui_GProgressBar_setMax'.",&tolua_err);
#endif

    return 0;
}
int lua_cocos2dx_fgui_GProgressBar_update(lua_State* tolua_S)
{
    int argc = 0;
    fgui::GProgressBar* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"fgui::GProgressBar",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (fgui::GProgressBar*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_fgui_GProgressBar_update'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 1) 
    {
        double arg0;

        ok &= luaval_to_number(tolua_S, 2,&arg0, "fgui::GProgressBar:update");
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_cocos2dx_fgui_GProgressBar_update'", nullptr);
            return 0;
        }
        cobj->update(arg0);
        lua_settop(tolua_S, 1);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "fgui::GProgressBar:update",argc, 1);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_fgui_GProgressBar_update'.",&tolua_err);
#endif

    return 0;
}
int lua_cocos2dx_fgui_GProgressBar_tweenValue(lua_State* tolua_S)
{
    int argc = 0;
    fgui::GProgressBar* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"fgui::GProgressBar",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (fgui::GProgressBar*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_fgui_GProgressBar_tweenValue'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 2) 
    {
        double arg0;
        double arg1;

        ok &= luaval_to_number(tolua_S, 2,&arg0, "fgui::GProgressBar:tweenValue");

        ok &= luaval_to_number(tolua_S, 3,&arg1, "fgui::GProgressBar:tweenValue");
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_cocos2dx_fgui_GProgressBar_tweenValue'", nullptr);
            return 0;
        }
        fgui::GTweener* ret = cobj->tweenValue(arg0, arg1);
        object_to_luaval<fgui::GTweener>(tolua_S, "fgui::GTweener",(fgui::GTweener*)ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "fgui::GProgressBar:tweenValue",argc, 2);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_fgui_GProgressBar_tweenValue'.",&tolua_err);
#endif

    return 0;
}
int lua_cocos2dx_fgui_GProgressBar_setTitleType(lua_State* tolua_S)
{
    int argc = 0;
    fgui::GProgressBar* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"fgui::GProgressBar",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (fgui::GProgressBar*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_fgui_GProgressBar_setTitleType'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 1) 
    {
        fgui::ProgressTitleType arg0;

        ok &= luaval_to_int32(tolua_S, 2,(int *)&arg0, "fgui::GProgressBar:setTitleType");
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_cocos2dx_fgui_GProgressBar_setTitleType'", nullptr);
            return 0;
        }
        cobj->setTitleType(arg0);
        lua_settop(tolua_S, 1);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "fgui::GProgressBar:setTitleType",argc, 1);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_fgui_GProgressBar_setTitleType'.",&tolua_err);
#endif

    return 0;
}
int lua_cocos2dx_fgui_GProgressBar_create(lua_State* tolua_S)
{
    int argc = 0;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif

#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertable(tolua_S,1,"fgui::GProgressBar",0,&tolua_err)) goto tolua_lerror;
#endif

    argc = lua_gettop(tolua_S) - 1;

    if (argc == 0)
    {
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_cocos2dx_fgui_GProgressBar_create'", nullptr);
            return 0;
        }
        fgui::GProgressBar* ret = fgui::GProgressBar::create();
        object_to_luaval<fgui::GProgressBar>(tolua_S, "fgui::GProgressBar",(fgui::GProgressBar*)ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d\n ", "fgui::GProgressBar:create",argc, 0);
    return 0;
#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_fgui_GProgressBar_create'.",&tolua_err);
#endif
    return 0;
}
int lua_cocos2dx_fgui_GProgressBar_constructor(lua_State* tolua_S)
{
    int argc = 0;
    fgui::GProgressBar* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif



    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_cocos2dx_fgui_GProgressBar_constructor'", nullptr);
            return 0;
        }
        cobj = new fgui::GProgressBar();
        cobj->autorelease();
        int ID =  (int)cobj->_ID ;
        int* luaID =  &cobj->_luaID ;
        toluafix_pushusertype_ccobject(tolua_S, ID, luaID, (void*)cobj,"fgui::GProgressBar");
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "fgui::GProgressBar:GProgressBar",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_fgui_GProgressBar_constructor'.",&tolua_err);
#endif

    return 0;
}

static int lua_cocos2dx_fgui_GProgressBar_finalize(lua_State* tolua_S)
{
    printf("luabindings: finalizing LUA object (GProgressBar)");
    return 0;
}

int lua_register_cocos2dx_fgui_GProgressBar(lua_State* tolua_S)
{
    tolua_usertype(tolua_S,"fgui::GProgressBar");
    tolua_cclass(tolua_S,"GProgressBar","fgui::GProgressBar","fgui::GComponent",nullptr);

    tolua_beginmodule(tolua_S,"GProgressBar");
        tolua_function(tolua_S,"new",lua_cocos2dx_fgui_GProgressBar_constructor);
        tolua_function(tolua_S,"setValue",lua_cocos2dx_fgui_GProgressBar_setValue);
        tolua_function(tolua_S,"setIsReverse",lua_cocos2dx_fgui_GProgressBar_setIsReverse);
        tolua_function(tolua_S,"setMax",lua_cocos2dx_fgui_GProgressBar_setMax);
        tolua_function(tolua_S,"update",lua_cocos2dx_fgui_GProgressBar_update);
        tolua_function(tolua_S,"tweenValue",lua_cocos2dx_fgui_GProgressBar_tweenValue);
        tolua_function(tolua_S,"setTitleType",lua_cocos2dx_fgui_GProgressBar_setTitleType);
        tolua_function(tolua_S,"create", lua_cocos2dx_fgui_GProgressBar_create);
    tolua_endmodule(tolua_S);
    std::string typeName = typeid(fgui::GProgressBar).name();
    g_luaType[typeName] = "fgui::GProgressBar";
    g_typeCast["GProgressBar"] = "fgui::GProgressBar";
    return 1;
}

int lua_cocos2dx_fgui_GRichText_setAutoSize(lua_State* tolua_S)
{
    int argc = 0;
    fgui::GRichText* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"fgui::GRichText",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (fgui::GRichText*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_fgui_GRichText_setAutoSize'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 1) 
    {
        fgui::AutoSizeType arg0;

        ok &= luaval_to_int32(tolua_S, 2,(int *)&arg0, "fgui::GRichText:setAutoSize");
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_cocos2dx_fgui_GRichText_setAutoSize'", nullptr);
            return 0;
        }
        cobj->setAutoSize(arg0);
        lua_settop(tolua_S, 1);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "fgui::GRichText:setAutoSize",argc, 1);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_fgui_GRichText_setAutoSize'.",&tolua_err);
#endif

    return 0;
}
int lua_cocos2dx_fgui_GRichText_setDimensions(lua_State* tolua_S)
{
    int argc = 0;
    fgui::GRichText* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"fgui::GRichText",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (fgui::GRichText*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_fgui_GRichText_setDimensions'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 2) 
    {
        double arg0;
        double arg1;

        ok &= luaval_to_number(tolua_S, 2,&arg0, "fgui::GRichText:setDimensions");

        ok &= luaval_to_number(tolua_S, 3,&arg1, "fgui::GRichText:setDimensions");
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_cocos2dx_fgui_GRichText_setDimensions'", nullptr);
            return 0;
        }
        cobj->setDimensions(arg0, arg1);
        lua_settop(tolua_S, 1);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "fgui::GRichText:setDimensions",argc, 2);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_fgui_GRichText_setDimensions'.",&tolua_err);
#endif

    return 0;
}
int lua_cocos2dx_fgui_GRichText_setTextUnderline(lua_State* tolua_S)
{
    int argc = 0;
    fgui::GRichText* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"fgui::GRichText",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (fgui::GRichText*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_fgui_GRichText_setTextUnderline'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 1) 
    {
        bool arg0;

        ok &= luaval_to_boolean(tolua_S, 2,&arg0, "fgui::GRichText:setTextUnderline");
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_cocos2dx_fgui_GRichText_setTextUnderline'", nullptr);
            return 0;
        }
        cobj->setTextUnderline(arg0);
        lua_settop(tolua_S, 1);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "fgui::GRichText:setTextUnderline",argc, 1);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_fgui_GRichText_setTextUnderline'.",&tolua_err);
#endif

    return 0;
}
int lua_cocos2dx_fgui_GRichText_onEnter(lua_State* tolua_S)
{
    int argc = 0;
    fgui::GRichText* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"fgui::GRichText",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (fgui::GRichText*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_fgui_GRichText_onEnter'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_cocos2dx_fgui_GRichText_onEnter'", nullptr);
            return 0;
        }
        cobj->onEnter();
        lua_settop(tolua_S, 1);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "fgui::GRichText:onEnter",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_fgui_GRichText_onEnter'.",&tolua_err);
#endif

    return 0;
}
int lua_cocos2dx_fgui_GRichText_onExit(lua_State* tolua_S)
{
    int argc = 0;
    fgui::GRichText* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"fgui::GRichText",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (fgui::GRichText*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_fgui_GRichText_onExit'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_cocos2dx_fgui_GRichText_onExit'", nullptr);
            return 0;
        }
        cobj->onExit();
        lua_settop(tolua_S, 1);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "fgui::GRichText:onExit",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_fgui_GRichText_onExit'.",&tolua_err);
#endif

    return 0;
}
int lua_cocos2dx_fgui_GRichText_getTextFormat(lua_State* tolua_S)
{
    int argc = 0;
    fgui::GRichText* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"fgui::GRichText",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (fgui::GRichText*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_fgui_GRichText_getTextFormat'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_cocos2dx_fgui_GRichText_getTextFormat'", nullptr);
            return 0;
        }
        fgui::TextFormat* ret = cobj->getTextFormat();
        object_to_luaval<fgui::TextFormat>(tolua_S, "fgui::TextFormat",(fgui::TextFormat*)ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "fgui::GRichText:getTextFormat",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_fgui_GRichText_getTextFormat'.",&tolua_err);
#endif

    return 0;
}
int lua_cocos2dx_fgui_GRichText_getFontColor(lua_State* tolua_S)
{
    int argc = 0;
    fgui::GRichText* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"fgui::GRichText",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (fgui::GRichText*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_fgui_GRichText_getFontColor'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_cocos2dx_fgui_GRichText_getFontColor'", nullptr);
            return 0;
        }
        const cocos2d::Color4B& ret = cobj->getFontColor();
        color4b_to_luaval(tolua_S, ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "fgui::GRichText:getFontColor",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_fgui_GRichText_getFontColor'.",&tolua_err);
#endif

    return 0;
}
int lua_cocos2dx_fgui_GRichText_setString(lua_State* tolua_S)
{
    int argc = 0;
    fgui::GRichText* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"fgui::GRichText",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (fgui::GRichText*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_fgui_GRichText_setString'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 1) 
    {
        std::string arg0;

        ok &= luaval_to_std_string(tolua_S, 2,&arg0, "fgui::GRichText:setString");
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_cocos2dx_fgui_GRichText_setString'", nullptr);
            return 0;
        }
        cobj->setString(arg0);
        lua_settop(tolua_S, 1);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "fgui::GRichText:setString",argc, 1);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_fgui_GRichText_setString'.",&tolua_err);
#endif

    return 0;
}
int lua_cocos2dx_fgui_GRichText_setPosition(lua_State* tolua_S)
{
    int argc = 0;
    fgui::GRichText* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"fgui::GRichText",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (fgui::GRichText*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_fgui_GRichText_setPosition'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 2) 
    {
        double arg0;
        double arg1;

        ok &= luaval_to_number(tolua_S, 2,&arg0, "fgui::GRichText:setPosition");

        ok &= luaval_to_number(tolua_S, 3,&arg1, "fgui::GRichText:setPosition");
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_cocos2dx_fgui_GRichText_setPosition'", nullptr);
            return 0;
        }
        cobj->setPosition(arg0, arg1);
        lua_settop(tolua_S, 1);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "fgui::GRichText:setPosition",argc, 2);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_fgui_GRichText_setPosition'.",&tolua_err);
#endif

    return 0;
}
int lua_cocos2dx_fgui_GRichText_getDimensions(lua_State* tolua_S)
{
    int argc = 0;
    fgui::GRichText* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"fgui::GRichText",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (fgui::GRichText*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_fgui_GRichText_getDimensions'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_cocos2dx_fgui_GRichText_getDimensions'", nullptr);
            return 0;
        }
        const cocos2d::Size& ret = cobj->getDimensions();
        size_to_luaval(tolua_S, ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "fgui::GRichText:getDimensions",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_fgui_GRichText_getDimensions'.",&tolua_err);
#endif

    return 0;
}
int lua_cocos2dx_fgui_GRichText_isTextUnderline(lua_State* tolua_S)
{
    int argc = 0;
    fgui::GRichText* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"fgui::GRichText",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (fgui::GRichText*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_fgui_GRichText_isTextUnderline'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_cocos2dx_fgui_GRichText_isTextUnderline'", nullptr);
            return 0;
        }
        bool ret = cobj->isTextUnderline();
        tolua_pushboolean(tolua_S,(bool)ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "fgui::GRichText:isTextUnderline",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_fgui_GRichText_isTextUnderline'.",&tolua_err);
#endif

    return 0;
}
int lua_cocos2dx_fgui_GRichText_getContentSize(lua_State* tolua_S)
{
    int argc = 0;
    fgui::GRichText* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"fgui::GRichText",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (fgui::GRichText*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_fgui_GRichText_getContentSize'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_cocos2dx_fgui_GRichText_getContentSize'", nullptr);
            return 0;
        }
        const cocos2d::Size& ret = cobj->getContentSize();
        size_to_luaval(tolua_S, ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "fgui::GRichText:getContentSize",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_fgui_GRichText_getContentSize'.",&tolua_err);
#endif

    return 0;
}
int lua_cocos2dx_fgui_GRichText_setContentSize(lua_State* tolua_S)
{
    int argc = 0;
    fgui::GRichText* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"fgui::GRichText",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (fgui::GRichText*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_fgui_GRichText_setContentSize'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 1) 
    {
        cocos2d::Size arg0;

        ok &= luaval_to_size(tolua_S, 2, &arg0, "fgui::GRichText:setContentSize");
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_cocos2dx_fgui_GRichText_setContentSize'", nullptr);
            return 0;
        }
        cobj->setContentSize(arg0);
        lua_settop(tolua_S, 1);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "fgui::GRichText:setContentSize",argc, 1);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_fgui_GRichText_setContentSize'.",&tolua_err);
#endif

    return 0;
}
int lua_cocos2dx_fgui_GRichText_setFontColor(lua_State* tolua_S)
{
    int argc = 0;
    fgui::GRichText* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"fgui::GRichText",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (fgui::GRichText*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_fgui_GRichText_setFontColor'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 1) 
    {
        cocos2d::Color4B arg0;

        ok &=luaval_to_color4b(tolua_S, 2, &arg0, "fgui::GRichText:setFontColor");
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_cocos2dx_fgui_GRichText_setFontColor'", nullptr);
            return 0;
        }
        cobj->setFontColor(arg0);
        lua_settop(tolua_S, 1);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "fgui::GRichText:setFontColor",argc, 1);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_fgui_GRichText_setFontColor'.",&tolua_err);
#endif

    return 0;
}
int lua_cocos2dx_fgui_GRichText_setTextFormat(lua_State* tolua_S)
{
    int argc = 0;
    fgui::GRichText* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"fgui::GRichText",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (fgui::GRichText*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_fgui_GRichText_setTextFormat'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 1) 
    {
        const fgui::TextFormat* arg0;

        ok &= luaval_to_object<const fgui::TextFormat>(tolua_S, 2, "fgui::TextFormat",&arg0, "fgui::GRichText:setTextFormat");
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_cocos2dx_fgui_GRichText_setTextFormat'", nullptr);
            return 0;
        }
        cobj->setTextFormat(arg0);
        lua_settop(tolua_S, 1);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "fgui::GRichText:setTextFormat",argc, 1);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_fgui_GRichText_setTextFormat'.",&tolua_err);
#endif

    return 0;
}
int lua_cocos2dx_fgui_GRichText_create(lua_State* tolua_S)
{
    int argc = 0;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif

#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertable(tolua_S,1,"fgui::GRichText",0,&tolua_err)) goto tolua_lerror;
#endif

    argc = lua_gettop(tolua_S) - 1;

    if (argc == 0)
    {
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_cocos2dx_fgui_GRichText_create'", nullptr);
            return 0;
        }
        fgui::GRichText* ret = fgui::GRichText::create();
        object_to_luaval<fgui::GRichText>(tolua_S, "fgui::GRichText",(fgui::GRichText*)ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d\n ", "fgui::GRichText:create",argc, 0);
    return 0;
#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_fgui_GRichText_create'.",&tolua_err);
#endif
    return 0;
}
int lua_cocos2dx_fgui_GRichText_constructor(lua_State* tolua_S)
{
    int argc = 0;
    fgui::GRichText* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif



    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_cocos2dx_fgui_GRichText_constructor'", nullptr);
            return 0;
        }
        cobj = new fgui::GRichText();
        cobj->autorelease();
        int ID =  (int)cobj->_ID ;
        int* luaID =  &cobj->_luaID ;
        toluafix_pushusertype_ccobject(tolua_S, ID, luaID, (void*)cobj,"fgui::GRichText");
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "fgui::GRichText:GRichText",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_fgui_GRichText_constructor'.",&tolua_err);
#endif

    return 0;
}

static int lua_cocos2dx_fgui_GRichText_finalize(lua_State* tolua_S)
{
    printf("luabindings: finalizing LUA object (GRichText)");
    return 0;
}

int lua_register_cocos2dx_fgui_GRichText(lua_State* tolua_S)
{
    tolua_usertype(tolua_S,"fgui::GRichText");
    tolua_cclass(tolua_S,"GRichText","fgui::GRichText","cc.Node",nullptr);

    tolua_beginmodule(tolua_S,"GRichText");
        tolua_function(tolua_S,"new",lua_cocos2dx_fgui_GRichText_constructor);
        tolua_function(tolua_S,"setAutoSize",lua_cocos2dx_fgui_GRichText_setAutoSize);
        tolua_function(tolua_S,"setDimensions",lua_cocos2dx_fgui_GRichText_setDimensions);
        tolua_function(tolua_S,"setTextUnderline",lua_cocos2dx_fgui_GRichText_setTextUnderline);
        tolua_function(tolua_S,"onEnter",lua_cocos2dx_fgui_GRichText_onEnter);
        tolua_function(tolua_S,"onExit",lua_cocos2dx_fgui_GRichText_onExit);
        tolua_function(tolua_S,"getTextFormat",lua_cocos2dx_fgui_GRichText_getTextFormat);
        tolua_function(tolua_S,"getFontColor",lua_cocos2dx_fgui_GRichText_getFontColor);
        tolua_function(tolua_S,"setString",lua_cocos2dx_fgui_GRichText_setString);
        tolua_function(tolua_S,"setPosition",lua_cocos2dx_fgui_GRichText_setPosition);
        tolua_function(tolua_S,"getDimensions",lua_cocos2dx_fgui_GRichText_getDimensions);
        tolua_function(tolua_S,"isTextUnderline",lua_cocos2dx_fgui_GRichText_isTextUnderline);
        tolua_function(tolua_S,"getContentSize",lua_cocos2dx_fgui_GRichText_getContentSize);
        tolua_function(tolua_S,"setContentSize",lua_cocos2dx_fgui_GRichText_setContentSize);
        tolua_function(tolua_S,"setFontColor",lua_cocos2dx_fgui_GRichText_setFontColor);
        tolua_function(tolua_S,"setTextFormat",lua_cocos2dx_fgui_GRichText_setTextFormat);
        tolua_function(tolua_S,"create", lua_cocos2dx_fgui_GRichText_create);
    tolua_endmodule(tolua_S);
    std::string typeName = typeid(fgui::GRichText).name();
    g_luaType[typeName] = "fgui::GRichText";
    g_typeCast["GRichText"] = "fgui::GRichText";
    return 1;
}

int lua_cocos2dx_fgui_GSprite_onEnter(lua_State* tolua_S)
{
    int argc = 0;
    fgui::GSprite* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"fgui::GSprite",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (fgui::GSprite*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_fgui_GSprite_onEnter'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_cocos2dx_fgui_GSprite_onEnter'", nullptr);
            return 0;
        }
        cobj->onEnter();
        lua_settop(tolua_S, 1);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "fgui::GSprite:onEnter",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_fgui_GSprite_onEnter'.",&tolua_err);
#endif

    return 0;
}
int lua_cocos2dx_fgui_GSprite_setHSVValue(lua_State* tolua_S)
{
    int argc = 0;
    fgui::GSprite* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"fgui::GSprite",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (fgui::GSprite*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_fgui_GSprite_setHSVValue'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 4) 
    {
        double arg0;
        double arg1;
        double arg2;
        double arg3;

        ok &= luaval_to_number(tolua_S, 2,&arg0, "fgui::GSprite:setHSVValue");

        ok &= luaval_to_number(tolua_S, 3,&arg1, "fgui::GSprite:setHSVValue");

        ok &= luaval_to_number(tolua_S, 4,&arg2, "fgui::GSprite:setHSVValue");

        ok &= luaval_to_number(tolua_S, 5,&arg3, "fgui::GSprite:setHSVValue");
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_cocos2dx_fgui_GSprite_setHSVValue'", nullptr);
            return 0;
        }
        cobj->setHSVValue(arg0, arg1, arg2, arg3);
        lua_settop(tolua_S, 1);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "fgui::GSprite:setHSVValue",argc, 4);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_fgui_GSprite_setHSVValue'.",&tolua_err);
#endif

    return 0;
}
int lua_cocos2dx_fgui_GSprite_setHSVMode(lua_State* tolua_S)
{
    int argc = 0;
    fgui::GSprite* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"fgui::GSprite",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (fgui::GSprite*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_fgui_GSprite_setHSVMode'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 1) 
    {
        bool arg0;

        ok &= luaval_to_boolean(tolua_S, 2,&arg0, "fgui::GSprite:setHSVMode");
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_cocos2dx_fgui_GSprite_setHSVMode'", nullptr);
            return 0;
        }
        cobj->setHSVMode(arg0);
        lua_settop(tolua_S, 1);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "fgui::GSprite:setHSVMode",argc, 1);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_fgui_GSprite_setHSVMode'.",&tolua_err);
#endif

    return 0;
}
int lua_cocos2dx_fgui_GSprite_getFillAmount(lua_State* tolua_S)
{
    int argc = 0;
    fgui::GSprite* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"fgui::GSprite",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (fgui::GSprite*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_fgui_GSprite_getFillAmount'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_cocos2dx_fgui_GSprite_getFillAmount'", nullptr);
            return 0;
        }
        double ret = cobj->getFillAmount();
        tolua_pushnumber(tolua_S,(lua_Number)ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "fgui::GSprite:getFillAmount",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_fgui_GSprite_getFillAmount'.",&tolua_err);
#endif

    return 0;
}
int lua_cocos2dx_fgui_GSprite_getFillOrigin(lua_State* tolua_S)
{
    int argc = 0;
    fgui::GSprite* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"fgui::GSprite",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (fgui::GSprite*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_fgui_GSprite_getFillOrigin'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_cocos2dx_fgui_GSprite_getFillOrigin'", nullptr);
            return 0;
        }
        int ret = (int)cobj->getFillOrigin();
        tolua_pushnumber(tolua_S,(lua_Number)ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "fgui::GSprite:getFillOrigin",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_fgui_GSprite_getFillOrigin'.",&tolua_err);
#endif

    return 0;
}
int lua_cocos2dx_fgui_GSprite_setContentSize(lua_State* tolua_S)
{
    int argc = 0;
    fgui::GSprite* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"fgui::GSprite",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (fgui::GSprite*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_fgui_GSprite_setContentSize'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 1) 
    {
        cocos2d::Size arg0;

        ok &= luaval_to_size(tolua_S, 2, &arg0, "fgui::GSprite:setContentSize");
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_cocos2dx_fgui_GSprite_setContentSize'", nullptr);
            return 0;
        }
        cobj->setContentSize(arg0);
        lua_settop(tolua_S, 1);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "fgui::GSprite:setContentSize",argc, 1);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_fgui_GSprite_setContentSize'.",&tolua_err);
#endif

    return 0;
}
int lua_cocos2dx_fgui_GSprite_setFillMethod(lua_State* tolua_S)
{
    int argc = 0;
    fgui::GSprite* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"fgui::GSprite",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (fgui::GSprite*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_fgui_GSprite_setFillMethod'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 1) 
    {
        fgui::FillMethod arg0;

        ok &= luaval_to_int32(tolua_S, 2,(int *)&arg0, "fgui::GSprite:setFillMethod");
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_cocos2dx_fgui_GSprite_setFillMethod'", nullptr);
            return 0;
        }
        cobj->setFillMethod(arg0);
        lua_settop(tolua_S, 1);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "fgui::GSprite:setFillMethod",argc, 1);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_fgui_GSprite_setFillMethod'.",&tolua_err);
#endif

    return 0;
}
int lua_cocos2dx_fgui_GSprite_setFillClockwise(lua_State* tolua_S)
{
    int argc = 0;
    fgui::GSprite* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"fgui::GSprite",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (fgui::GSprite*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_fgui_GSprite_setFillClockwise'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 1) 
    {
        bool arg0;

        ok &= luaval_to_boolean(tolua_S, 2,&arg0, "fgui::GSprite:setFillClockwise");
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_cocos2dx_fgui_GSprite_setFillClockwise'", nullptr);
            return 0;
        }
        cobj->setFillClockwise(arg0);
        lua_settop(tolua_S, 1);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "fgui::GSprite:setFillClockwise",argc, 1);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_fgui_GSprite_setFillClockwise'.",&tolua_err);
#endif

    return 0;
}
int lua_cocos2dx_fgui_GSprite_setScale9Sprite(lua_State* tolua_S)
{
    int argc = 0;
    fgui::GSprite* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"fgui::GSprite",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (fgui::GSprite*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_fgui_GSprite_setScale9Sprite'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 1) 
    {
        const cocos2d::Rect* arg0;

        ok &= luaval_to_object<const cocos2d::Rect>(tolua_S, 2, "cc.Rect",&arg0, "fgui::GSprite:setScale9Sprite");
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_cocos2dx_fgui_GSprite_setScale9Sprite'", nullptr);
            return 0;
        }
        cobj->setScale9Sprite(arg0);
        lua_settop(tolua_S, 1);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "fgui::GSprite:setScale9Sprite",argc, 1);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_fgui_GSprite_setScale9Sprite'.",&tolua_err);
#endif

    return 0;
}
int lua_cocos2dx_fgui_GSprite_getFillMethod(lua_State* tolua_S)
{
    int argc = 0;
    fgui::GSprite* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"fgui::GSprite",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (fgui::GSprite*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_fgui_GSprite_getFillMethod'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_cocos2dx_fgui_GSprite_getFillMethod'", nullptr);
            return 0;
        }
        int ret = (int)cobj->getFillMethod();
        tolua_pushnumber(tolua_S,(lua_Number)ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "fgui::GSprite:getFillMethod",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_fgui_GSprite_getFillMethod'.",&tolua_err);
#endif

    return 0;
}
int lua_cocos2dx_fgui_GSprite_isFillClockwise(lua_State* tolua_S)
{
    int argc = 0;
    fgui::GSprite* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"fgui::GSprite",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (fgui::GSprite*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_fgui_GSprite_isFillClockwise'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_cocos2dx_fgui_GSprite_isFillClockwise'", nullptr);
            return 0;
        }
        bool ret = cobj->isFillClockwise();
        tolua_pushboolean(tolua_S,(bool)ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "fgui::GSprite:isFillClockwise",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_fgui_GSprite_isFillClockwise'.",&tolua_err);
#endif

    return 0;
}
int lua_cocos2dx_fgui_GSprite_setFillOrigin(lua_State* tolua_S)
{
    int argc = 0;
    fgui::GSprite* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"fgui::GSprite",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (fgui::GSprite*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_fgui_GSprite_setFillOrigin'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 1) 
    {
        fgui::FillOrigin arg0;

        ok &= luaval_to_int32(tolua_S, 2,(int *)&arg0, "fgui::GSprite:setFillOrigin");
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_cocos2dx_fgui_GSprite_setFillOrigin'", nullptr);
            return 0;
        }
        cobj->setFillOrigin(arg0);
        lua_settop(tolua_S, 1);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "fgui::GSprite:setFillOrigin",argc, 1);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_fgui_GSprite_setFillOrigin'.",&tolua_err);
#endif

    return 0;
}
int lua_cocos2dx_fgui_GSprite_setFlipType(lua_State* tolua_S)
{
    int argc = 0;
    fgui::GSprite* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"fgui::GSprite",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (fgui::GSprite*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_fgui_GSprite_setFlipType'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 1) 
    {
        fgui::FlipType arg0;

        ok &= luaval_to_int32(tolua_S, 2,(int *)&arg0, "fgui::GSprite:setFlipType");
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_cocos2dx_fgui_GSprite_setFlipType'", nullptr);
            return 0;
        }
        cobj->setFlipType(arg0);
        lua_settop(tolua_S, 1);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "fgui::GSprite:setFlipType",argc, 1);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_fgui_GSprite_setFlipType'.",&tolua_err);
#endif

    return 0;
}
int lua_cocos2dx_fgui_GSprite_setBlendMode(lua_State* tolua_S)
{
    int argc = 0;
    fgui::GSprite* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"fgui::GSprite",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (fgui::GSprite*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_fgui_GSprite_setBlendMode'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 1) 
    {
        fgui::BlendMode arg0;

        ok &= luaval_to_int32(tolua_S, 2,(int *)&arg0, "fgui::GSprite:setBlendMode");
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_cocos2dx_fgui_GSprite_setBlendMode'", nullptr);
            return 0;
        }
        cobj->setBlendMode(arg0);
        lua_settop(tolua_S, 1);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "fgui::GSprite:setBlendMode",argc, 1);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_fgui_GSprite_setBlendMode'.",&tolua_err);
#endif

    return 0;
}
int lua_cocos2dx_fgui_GSprite_clearContent(lua_State* tolua_S)
{
    int argc = 0;
    fgui::GSprite* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"fgui::GSprite",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (fgui::GSprite*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_fgui_GSprite_clearContent'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_cocos2dx_fgui_GSprite_clearContent'", nullptr);
            return 0;
        }
        cobj->clearContent();
        lua_settop(tolua_S, 1);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "fgui::GSprite:clearContent",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_fgui_GSprite_clearContent'.",&tolua_err);
#endif

    return 0;
}
int lua_cocos2dx_fgui_GSprite_setGrayed(lua_State* tolua_S)
{
    int argc = 0;
    fgui::GSprite* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"fgui::GSprite",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (fgui::GSprite*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_fgui_GSprite_setGrayed'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 1) 
    {
        bool arg0;

        ok &= luaval_to_boolean(tolua_S, 2,&arg0, "fgui::GSprite:setGrayed");
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_cocos2dx_fgui_GSprite_setGrayed'", nullptr);
            return 0;
        }
        cobj->setGrayed(arg0);
        lua_settop(tolua_S, 1);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "fgui::GSprite:setGrayed",argc, 1);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_fgui_GSprite_setGrayed'.",&tolua_err);
#endif

    return 0;
}
int lua_cocos2dx_fgui_GSprite_setPosition(lua_State* tolua_S)
{
    int argc = 0;
    fgui::GSprite* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"fgui::GSprite",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (fgui::GSprite*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_fgui_GSprite_setPosition'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 2) 
    {
        double arg0;
        double arg1;

        ok &= luaval_to_number(tolua_S, 2,&arg0, "fgui::GSprite:setPosition");

        ok &= luaval_to_number(tolua_S, 3,&arg1, "fgui::GSprite:setPosition");
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_cocos2dx_fgui_GSprite_setPosition'", nullptr);
            return 0;
        }
        cobj->setPosition(arg0, arg1);
        lua_settop(tolua_S, 1);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "fgui::GSprite:setPosition",argc, 2);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_fgui_GSprite_setPosition'.",&tolua_err);
#endif

    return 0;
}
int lua_cocos2dx_fgui_GSprite_getFlipType(lua_State* tolua_S)
{
    int argc = 0;
    fgui::GSprite* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"fgui::GSprite",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (fgui::GSprite*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_fgui_GSprite_getFlipType'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_cocos2dx_fgui_GSprite_getFlipType'", nullptr);
            return 0;
        }
        int ret = (int)cobj->getFlipType();
        tolua_pushnumber(tolua_S,(lua_Number)ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "fgui::GSprite:getFlipType",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_fgui_GSprite_getFlipType'.",&tolua_err);
#endif

    return 0;
}
int lua_cocos2dx_fgui_GSprite_onExit(lua_State* tolua_S)
{
    int argc = 0;
    fgui::GSprite* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"fgui::GSprite",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (fgui::GSprite*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_fgui_GSprite_onExit'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_cocos2dx_fgui_GSprite_onExit'", nullptr);
            return 0;
        }
        cobj->onExit();
        lua_settop(tolua_S, 1);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "fgui::GSprite:onExit",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_fgui_GSprite_onExit'.",&tolua_err);
#endif

    return 0;
}
int lua_cocos2dx_fgui_GSprite_setFillAmount(lua_State* tolua_S)
{
    int argc = 0;
    fgui::GSprite* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"fgui::GSprite",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (fgui::GSprite*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_fgui_GSprite_setFillAmount'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 1) 
    {
        double arg0;

        ok &= luaval_to_number(tolua_S, 2,&arg0, "fgui::GSprite:setFillAmount");
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_cocos2dx_fgui_GSprite_setFillAmount'", nullptr);
            return 0;
        }
        cobj->setFillAmount(arg0);
        lua_settop(tolua_S, 1);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "fgui::GSprite:setFillAmount",argc, 1);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_fgui_GSprite_setFillAmount'.",&tolua_err);
#endif

    return 0;
}
int lua_cocos2dx_fgui_GSprite_getBlendMode(lua_State* tolua_S)
{
    int argc = 0;
    fgui::GSprite* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"fgui::GSprite",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (fgui::GSprite*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_fgui_GSprite_getBlendMode'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_cocos2dx_fgui_GSprite_getBlendMode'", nullptr);
            return 0;
        }
        int ret = (int)cobj->getBlendMode();
        tolua_pushnumber(tolua_S,(lua_Number)ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "fgui::GSprite:getBlendMode",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_fgui_GSprite_getBlendMode'.",&tolua_err);
#endif

    return 0;
}
int lua_cocos2dx_fgui_GSprite_setScale9SpriteWithSpace(lua_State* tolua_S)
{
    int argc = 0;
    fgui::GSprite* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"fgui::GSprite",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (fgui::GSprite*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_fgui_GSprite_setScale9SpriteWithSpace'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 4) 
    {
        double arg0;
        double arg1;
        double arg2;
        double arg3;

        ok &= luaval_to_number(tolua_S, 2,&arg0, "fgui::GSprite:setScale9SpriteWithSpace");

        ok &= luaval_to_number(tolua_S, 3,&arg1, "fgui::GSprite:setScale9SpriteWithSpace");

        ok &= luaval_to_number(tolua_S, 4,&arg2, "fgui::GSprite:setScale9SpriteWithSpace");

        ok &= luaval_to_number(tolua_S, 5,&arg3, "fgui::GSprite:setScale9SpriteWithSpace");
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_cocos2dx_fgui_GSprite_setScale9SpriteWithSpace'", nullptr);
            return 0;
        }
        cobj->setScale9SpriteWithSpace(arg0, arg1, arg2, arg3);
        lua_settop(tolua_S, 1);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "fgui::GSprite:setScale9SpriteWithSpace",argc, 4);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_fgui_GSprite_setScale9SpriteWithSpace'.",&tolua_err);
#endif

    return 0;
}
int lua_cocos2dx_fgui_GSprite_createWithFileName(lua_State* tolua_S)
{
    int argc = 0;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif

#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertable(tolua_S,1,"fgui::GSprite",0,&tolua_err)) goto tolua_lerror;
#endif

    argc = lua_gettop(tolua_S) - 1;

    if (argc == 1)
    {
        std::string arg0;
        ok &= luaval_to_std_string(tolua_S, 2,&arg0, "fgui::GSprite:createWithFileName");
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_cocos2dx_fgui_GSprite_createWithFileName'", nullptr);
            return 0;
        }
        fgui::GSprite* ret = fgui::GSprite::createWithFileName(arg0);
        object_to_luaval<fgui::GSprite>(tolua_S, "fgui::GSprite",(fgui::GSprite*)ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d\n ", "fgui::GSprite:createWithFileName",argc, 1);
    return 0;
#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_fgui_GSprite_createWithFileName'.",&tolua_err);
#endif
    return 0;
}
int lua_cocos2dx_fgui_GSprite_create(lua_State* tolua_S)
{
    int argc = 0;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif

#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertable(tolua_S,1,"fgui::GSprite",0,&tolua_err)) goto tolua_lerror;
#endif

    argc = lua_gettop(tolua_S) - 1;

    if (argc == 0)
    {
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_cocos2dx_fgui_GSprite_create'", nullptr);
            return 0;
        }
        fgui::GSprite* ret = fgui::GSprite::create();
        object_to_luaval<fgui::GSprite>(tolua_S, "fgui::GSprite",(fgui::GSprite*)ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d\n ", "fgui::GSprite:create",argc, 0);
    return 0;
#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_fgui_GSprite_create'.",&tolua_err);
#endif
    return 0;
}
int lua_cocos2dx_fgui_GSprite_createWithTexture(lua_State* tolua_S)
{
    int argc = 0;
    bool ok  = true;
#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif

#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertable(tolua_S,1,"fgui::GSprite",0,&tolua_err)) goto tolua_lerror;
#endif

    argc = lua_gettop(tolua_S)-1;

    do 
    {
        if (argc == 2)
        {
            cocos2d::Texture2D* arg0;
            ok &= luaval_to_object<cocos2d::Texture2D>(tolua_S, 2, "cc.Texture2D",&arg0, "fgui::GSprite:createWithTexture");
            if (!ok) { break; }
            cocos2d::Rect arg1;
            ok &= luaval_to_rect(tolua_S, 3, &arg1, "fgui::GSprite:createWithTexture");
            if (!ok) { break; }
            fgui::GSprite* ret = fgui::GSprite::createWithTexture(arg0, arg1);
            object_to_luaval<fgui::GSprite>(tolua_S, "fgui::GSprite",(fgui::GSprite*)ret);
            return 1;
        }
    } while (0);
    ok  = true;
    do 
    {
        if (argc == 3)
        {
            cocos2d::Texture2D* arg0;
            ok &= luaval_to_object<cocos2d::Texture2D>(tolua_S, 2, "cc.Texture2D",&arg0, "fgui::GSprite:createWithTexture");
            if (!ok) { break; }
            cocos2d::Rect arg1;
            ok &= luaval_to_rect(tolua_S, 3, &arg1, "fgui::GSprite:createWithTexture");
            if (!ok) { break; }
            bool arg2;
            ok &= luaval_to_boolean(tolua_S, 4,&arg2, "fgui::GSprite:createWithTexture");
            if (!ok) { break; }
            fgui::GSprite* ret = fgui::GSprite::createWithTexture(arg0, arg1, arg2);
            object_to_luaval<fgui::GSprite>(tolua_S, "fgui::GSprite",(fgui::GSprite*)ret);
            return 1;
        }
    } while (0);
    ok  = true;
    do 
    {
        if (argc == 1)
        {
            cocos2d::Texture2D* arg0;
            ok &= luaval_to_object<cocos2d::Texture2D>(tolua_S, 2, "cc.Texture2D",&arg0, "fgui::GSprite:createWithTexture");
            if (!ok) { break; }
            fgui::GSprite* ret = fgui::GSprite::createWithTexture(arg0);
            object_to_luaval<fgui::GSprite>(tolua_S, "fgui::GSprite",(fgui::GSprite*)ret);
            return 1;
        }
    } while (0);
    ok  = true;
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d", "fgui::GSprite:createWithTexture",argc, 1);
    return 0;
#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_fgui_GSprite_createWithTexture'.",&tolua_err);
#endif
    return 0;
}
int lua_cocos2dx_fgui_GSprite_createWithSpriteFrameName(lua_State* tolua_S)
{
    int argc = 0;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif

#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertable(tolua_S,1,"fgui::GSprite",0,&tolua_err)) goto tolua_lerror;
#endif

    argc = lua_gettop(tolua_S) - 1;

    if (argc == 1)
    {
        std::string arg0;
        ok &= luaval_to_std_string(tolua_S, 2,&arg0, "fgui::GSprite:createWithSpriteFrameName");
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_cocos2dx_fgui_GSprite_createWithSpriteFrameName'", nullptr);
            return 0;
        }
        fgui::GSprite* ret = fgui::GSprite::createWithSpriteFrameName(arg0);
        object_to_luaval<fgui::GSprite>(tolua_S, "fgui::GSprite",(fgui::GSprite*)ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d\n ", "fgui::GSprite:createWithSpriteFrameName",argc, 1);
    return 0;
#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_fgui_GSprite_createWithSpriteFrameName'.",&tolua_err);
#endif
    return 0;
}
int lua_cocos2dx_fgui_GSprite_createWithSpriteFrame(lua_State* tolua_S)
{
    int argc = 0;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif

#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertable(tolua_S,1,"fgui::GSprite",0,&tolua_err)) goto tolua_lerror;
#endif

    argc = lua_gettop(tolua_S) - 1;

    if (argc == 1)
    {
        cocos2d::SpriteFrame* arg0;
        ok &= luaval_to_object<cocos2d::SpriteFrame>(tolua_S, 2, "cc.SpriteFrame",&arg0, "fgui::GSprite:createWithSpriteFrame");
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_cocos2dx_fgui_GSprite_createWithSpriteFrame'", nullptr);
            return 0;
        }
        fgui::GSprite* ret = fgui::GSprite::createWithSpriteFrame(arg0);
        object_to_luaval<fgui::GSprite>(tolua_S, "fgui::GSprite",(fgui::GSprite*)ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d\n ", "fgui::GSprite:createWithSpriteFrame",argc, 1);
    return 0;
#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_fgui_GSprite_createWithSpriteFrame'.",&tolua_err);
#endif
    return 0;
}
int lua_cocos2dx_fgui_GSprite_constructor(lua_State* tolua_S)
{
    int argc = 0;
    fgui::GSprite* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif



    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_cocos2dx_fgui_GSprite_constructor'", nullptr);
            return 0;
        }
        cobj = new fgui::GSprite();
        cobj->autorelease();
        int ID =  (int)cobj->_ID ;
        int* luaID =  &cobj->_luaID ;
        toluafix_pushusertype_ccobject(tolua_S, ID, luaID, (void*)cobj,"fgui::GSprite");
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "fgui::GSprite:GSprite",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_fgui_GSprite_constructor'.",&tolua_err);
#endif

    return 0;
}

static int lua_cocos2dx_fgui_GSprite_finalize(lua_State* tolua_S)
{
    printf("luabindings: finalizing LUA object (GSprite)");
    return 0;
}

int lua_register_cocos2dx_fgui_GSprite(lua_State* tolua_S)
{
    tolua_usertype(tolua_S,"fgui::GSprite");
    tolua_cclass(tolua_S,"GSprite","fgui::GSprite","cc.Sprite",nullptr);

    tolua_beginmodule(tolua_S,"GSprite");
        tolua_function(tolua_S,"new",lua_cocos2dx_fgui_GSprite_constructor);
        tolua_function(tolua_S,"onEnter",lua_cocos2dx_fgui_GSprite_onEnter);
        tolua_function(tolua_S,"setHSVValue",lua_cocos2dx_fgui_GSprite_setHSVValue);
        tolua_function(tolua_S,"setHSVMode",lua_cocos2dx_fgui_GSprite_setHSVMode);
        tolua_function(tolua_S,"getFillAmount",lua_cocos2dx_fgui_GSprite_getFillAmount);
        tolua_function(tolua_S,"getFillOrigin",lua_cocos2dx_fgui_GSprite_getFillOrigin);
        tolua_function(tolua_S,"setContentSize",lua_cocos2dx_fgui_GSprite_setContentSize);
        tolua_function(tolua_S,"setFillMethod",lua_cocos2dx_fgui_GSprite_setFillMethod);
        tolua_function(tolua_S,"setFillClockwise",lua_cocos2dx_fgui_GSprite_setFillClockwise);
        tolua_function(tolua_S,"setScale9Sprite",lua_cocos2dx_fgui_GSprite_setScale9Sprite);
        tolua_function(tolua_S,"getFillMethod",lua_cocos2dx_fgui_GSprite_getFillMethod);
        tolua_function(tolua_S,"isFillClockwise",lua_cocos2dx_fgui_GSprite_isFillClockwise);
        tolua_function(tolua_S,"setFillOrigin",lua_cocos2dx_fgui_GSprite_setFillOrigin);
        tolua_function(tolua_S,"setFlipType",lua_cocos2dx_fgui_GSprite_setFlipType);
        tolua_function(tolua_S,"setBlendMode",lua_cocos2dx_fgui_GSprite_setBlendMode);
        tolua_function(tolua_S,"clearContent",lua_cocos2dx_fgui_GSprite_clearContent);
        tolua_function(tolua_S,"setGrayed",lua_cocos2dx_fgui_GSprite_setGrayed);
        tolua_function(tolua_S,"setPosition",lua_cocos2dx_fgui_GSprite_setPosition);
        tolua_function(tolua_S,"getFlipType",lua_cocos2dx_fgui_GSprite_getFlipType);
        tolua_function(tolua_S,"onExit",lua_cocos2dx_fgui_GSprite_onExit);
        tolua_function(tolua_S,"setFillAmount",lua_cocos2dx_fgui_GSprite_setFillAmount);
        tolua_function(tolua_S,"getBlendMode",lua_cocos2dx_fgui_GSprite_getBlendMode);
        tolua_function(tolua_S,"setScale9SpriteWithSpace",lua_cocos2dx_fgui_GSprite_setScale9SpriteWithSpace);
        tolua_function(tolua_S,"createWithFileName", lua_cocos2dx_fgui_GSprite_createWithFileName);
        tolua_function(tolua_S,"create", lua_cocos2dx_fgui_GSprite_create);
        tolua_function(tolua_S,"createWithTexture", lua_cocos2dx_fgui_GSprite_createWithTexture);
        tolua_function(tolua_S,"createWithSpriteFrameName", lua_cocos2dx_fgui_GSprite_createWithSpriteFrameName);
        tolua_function(tolua_S,"createWithSpriteFrame", lua_cocos2dx_fgui_GSprite_createWithSpriteFrame);
    tolua_endmodule(tolua_S);
    std::string typeName = typeid(fgui::GSprite).name();
    g_luaType[typeName] = "fgui::GSprite";
    g_typeCast["GSprite"] = "fgui::GSprite";
    return 1;
}

int lua_cocos2dx_fgui_GText_setTitle(lua_State* tolua_S)
{
    int argc = 0;
    fgui::GText* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"fgui::GText",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (fgui::GText*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_fgui_GText_setTitle'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 1) 
    {
        std::string arg0;

        ok &= luaval_to_std_string(tolua_S, 2,&arg0, "fgui::GText:setTitle");
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_cocos2dx_fgui_GText_setTitle'", nullptr);
            return 0;
        }
        cobj->setTitle(arg0);
        lua_settop(tolua_S, 1);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "fgui::GText:setTitle",argc, 1);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_fgui_GText_setTitle'.",&tolua_err);
#endif

    return 0;
}
int lua_cocos2dx_fgui_GText_setIcon(lua_State* tolua_S)
{
    int argc = 0;
    fgui::GText* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"fgui::GText",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (fgui::GText*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_fgui_GText_setIcon'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 1) 
    {
        std::string arg0;

        ok &= luaval_to_std_string(tolua_S, 2,&arg0, "fgui::GText:setIcon");
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_cocos2dx_fgui_GText_setIcon'", nullptr);
            return 0;
        }
        cobj->setIcon(arg0);
        lua_settop(tolua_S, 1);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "fgui::GText:setIcon",argc, 1);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_fgui_GText_setIcon'.",&tolua_err);
#endif

    return 0;
}
int lua_cocos2dx_fgui_GText_setTitleFontSize(lua_State* tolua_S)
{
    int argc = 0;
    fgui::GText* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"fgui::GText",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (fgui::GText*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_fgui_GText_setTitleFontSize'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 1) 
    {
        int arg0;

        ok &= luaval_to_int32(tolua_S, 2,(int *)&arg0, "fgui::GText:setTitleFontSize");
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_cocos2dx_fgui_GText_setTitleFontSize'", nullptr);
            return 0;
        }
        cobj->setTitleFontSize(arg0);
        lua_settop(tolua_S, 1);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "fgui::GText:setTitleFontSize",argc, 1);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_fgui_GText_setTitleFontSize'.",&tolua_err);
#endif

    return 0;
}
int lua_cocos2dx_fgui_GText_setTitleColor(lua_State* tolua_S)
{
    int argc = 0;
    fgui::GText* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"fgui::GText",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (fgui::GText*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_fgui_GText_setTitleColor'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 1) 
    {
        cocos2d::Color4B arg0;

        ok &=luaval_to_color4b(tolua_S, 2, &arg0, "fgui::GText:setTitleColor");
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_cocos2dx_fgui_GText_setTitleColor'", nullptr);
            return 0;
        }
        cobj->setTitleColor(arg0);
        lua_settop(tolua_S, 1);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "fgui::GText:setTitleColor",argc, 1);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_fgui_GText_setTitleColor'.",&tolua_err);
#endif

    return 0;
}
int lua_cocos2dx_fgui_GText_create(lua_State* tolua_S)
{
    int argc = 0;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif

#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertable(tolua_S,1,"fgui::GText",0,&tolua_err)) goto tolua_lerror;
#endif

    argc = lua_gettop(tolua_S) - 1;

    if (argc == 0)
    {
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_cocos2dx_fgui_GText_create'", nullptr);
            return 0;
        }
        fgui::GText* ret = fgui::GText::create();
        object_to_luaval<fgui::GText>(tolua_S, "fgui::GText",(fgui::GText*)ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d\n ", "fgui::GText:create",argc, 0);
    return 0;
#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_fgui_GText_create'.",&tolua_err);
#endif
    return 0;
}
int lua_cocos2dx_fgui_GText_constructor(lua_State* tolua_S)
{
    int argc = 0;
    fgui::GText* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif



    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_cocos2dx_fgui_GText_constructor'", nullptr);
            return 0;
        }
        cobj = new fgui::GText();
        cobj->autorelease();
        int ID =  (int)cobj->_ID ;
        int* luaID =  &cobj->_luaID ;
        toluafix_pushusertype_ccobject(tolua_S, ID, luaID, (void*)cobj,"fgui::GText");
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "fgui::GText:GText",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_fgui_GText_constructor'.",&tolua_err);
#endif

    return 0;
}

static int lua_cocos2dx_fgui_GText_finalize(lua_State* tolua_S)
{
    printf("luabindings: finalizing LUA object (GText)");
    return 0;
}

int lua_register_cocos2dx_fgui_GText(lua_State* tolua_S)
{
    tolua_usertype(tolua_S,"fgui::GText");
    tolua_cclass(tolua_S,"GText","fgui::GText","fgui::GComponent",nullptr);

    tolua_beginmodule(tolua_S,"GText");
        tolua_function(tolua_S,"new",lua_cocos2dx_fgui_GText_constructor);
        tolua_function(tolua_S,"setTitle",lua_cocos2dx_fgui_GText_setTitle);
        tolua_function(tolua_S,"setIcon",lua_cocos2dx_fgui_GText_setIcon);
        tolua_function(tolua_S,"setTitleFontSize",lua_cocos2dx_fgui_GText_setTitleFontSize);
        tolua_function(tolua_S,"setTitleColor",lua_cocos2dx_fgui_GText_setTitleColor);
        tolua_function(tolua_S,"create", lua_cocos2dx_fgui_GText_create);
    tolua_endmodule(tolua_S);
    std::string typeName = typeid(fgui::GText).name();
    g_luaType[typeName] = "fgui::GText";
    g_typeCast["GText"] = "fgui::GText";
    return 1;
}

int lua_cocos2dx_fgui_GTextInput_getString(lua_State* tolua_S)
{
    int argc = 0;
    fgui::GTextInput* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"fgui::GTextInput",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (fgui::GTextInput*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_fgui_GTextInput_getString'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_cocos2dx_fgui_GTextInput_getString'", nullptr);
            return 0;
        }
        std::string ret = cobj->getString();
        lua_pushlstring(tolua_S,ret.c_str(),ret.length());
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "fgui::GTextInput:getString",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_fgui_GTextInput_getString'.",&tolua_err);
#endif

    return 0;
}
int lua_cocos2dx_fgui_GTextInput_setSingleLine(lua_State* tolua_S)
{
    int argc = 0;
    fgui::GTextInput* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"fgui::GTextInput",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (fgui::GTextInput*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_fgui_GTextInput_setSingleLine'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 1) 
    {
        bool arg0;

        ok &= luaval_to_boolean(tolua_S, 2,&arg0, "fgui::GTextInput:setSingleLine");
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_cocos2dx_fgui_GTextInput_setSingleLine'", nullptr);
            return 0;
        }
        cobj->setSingleLine(arg0);
        lua_settop(tolua_S, 1);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "fgui::GTextInput:setSingleLine",argc, 1);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_fgui_GTextInput_setSingleLine'.",&tolua_err);
#endif

    return 0;
}
int lua_cocos2dx_fgui_GTextInput_setString(lua_State* tolua_S)
{
    int argc = 0;
    fgui::GTextInput* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"fgui::GTextInput",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (fgui::GTextInput*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_fgui_GTextInput_setString'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 1) 
    {
        std::string arg0;

        ok &= luaval_to_std_string(tolua_S, 2,&arg0, "fgui::GTextInput:setString");
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_cocos2dx_fgui_GTextInput_setString'", nullptr);
            return 0;
        }
        cobj->setString(arg0);
        lua_settop(tolua_S, 1);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "fgui::GTextInput:setString",argc, 1);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_fgui_GTextInput_setString'.",&tolua_err);
#endif

    return 0;
}
int lua_cocos2dx_fgui_GTextInput_init(lua_State* tolua_S)
{
    int argc = 0;
    fgui::GTextInput* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"fgui::GTextInput",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (fgui::GTextInput*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_fgui_GTextInput_init'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_cocos2dx_fgui_GTextInput_init'", nullptr);
            return 0;
        }
        bool ret = cobj->init();
        tolua_pushboolean(tolua_S,(bool)ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "fgui::GTextInput:init",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_fgui_GTextInput_init'.",&tolua_err);
#endif

    return 0;
}
int lua_cocos2dx_fgui_GTextInput_setPassword(lua_State* tolua_S)
{
    int argc = 0;
    fgui::GTextInput* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"fgui::GTextInput",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (fgui::GTextInput*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_fgui_GTextInput_setPassword'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 1) 
    {
        bool arg0;

        ok &= luaval_to_boolean(tolua_S, 2,&arg0, "fgui::GTextInput:setPassword");
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_cocos2dx_fgui_GTextInput_setPassword'", nullptr);
            return 0;
        }
        cobj->setPassword(arg0);
        lua_settop(tolua_S, 1);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "fgui::GTextInput:setPassword",argc, 1);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_fgui_GTextInput_setPassword'.",&tolua_err);
#endif

    return 0;
}
int lua_cocos2dx_fgui_GTextInput_applyTextFormat(lua_State* tolua_S)
{
    int argc = 0;
    fgui::GTextInput* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"fgui::GTextInput",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (fgui::GTextInput*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_fgui_GTextInput_applyTextFormat'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_cocos2dx_fgui_GTextInput_applyTextFormat'", nullptr);
            return 0;
        }
        cobj->applyTextFormat();
        lua_settop(tolua_S, 1);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "fgui::GTextInput:applyTextFormat",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_fgui_GTextInput_applyTextFormat'.",&tolua_err);
#endif

    return 0;
}
int lua_cocos2dx_fgui_GTextInput_isSingleLine(lua_State* tolua_S)
{
    int argc = 0;
    fgui::GTextInput* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"fgui::GTextInput",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (fgui::GTextInput*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_fgui_GTextInput_isSingleLine'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_cocos2dx_fgui_GTextInput_isSingleLine'", nullptr);
            return 0;
        }
        bool ret = cobj->isSingleLine();
        tolua_pushboolean(tolua_S,(bool)ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "fgui::GTextInput:isSingleLine",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_fgui_GTextInput_isSingleLine'.",&tolua_err);
#endif

    return 0;
}
int lua_cocos2dx_fgui_GTextInput_create(lua_State* tolua_S)
{
    int argc = 0;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif

#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertable(tolua_S,1,"fgui::GTextInput",0,&tolua_err)) goto tolua_lerror;
#endif

    argc = lua_gettop(tolua_S) - 1;

    if (argc == 0)
    {
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_cocos2dx_fgui_GTextInput_create'", nullptr);
            return 0;
        }
        fgui::GTextInput* ret = fgui::GTextInput::create();
        object_to_luaval<fgui::GTextInput>(tolua_S, "fgui::GTextInput",(fgui::GTextInput*)ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d\n ", "fgui::GTextInput:create",argc, 0);
    return 0;
#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_fgui_GTextInput_create'.",&tolua_err);
#endif
    return 0;
}
int lua_cocos2dx_fgui_GTextInput_constructor(lua_State* tolua_S)
{
    int argc = 0;
    fgui::GTextInput* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif



    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_cocos2dx_fgui_GTextInput_constructor'", nullptr);
            return 0;
        }
        cobj = new fgui::GTextInput();
        cobj->autorelease();
        int ID =  (int)cobj->_ID ;
        int* luaID =  &cobj->_luaID ;
        toluafix_pushusertype_ccobject(tolua_S, ID, luaID, (void*)cobj,"fgui::GTextInput");
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "fgui::GTextInput:GTextInput",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_fgui_GTextInput_constructor'.",&tolua_err);
#endif

    return 0;
}

static int lua_cocos2dx_fgui_GTextInput_finalize(lua_State* tolua_S)
{
    printf("luabindings: finalizing LUA object (GTextInput)");
    return 0;
}

int lua_register_cocos2dx_fgui_GTextInput(lua_State* tolua_S)
{
    tolua_usertype(tolua_S,"fgui::GTextInput");
    tolua_cclass(tolua_S,"GTextInput","fgui::GTextInput","ccui.EditBox",nullptr);

    tolua_beginmodule(tolua_S,"GTextInput");
        tolua_function(tolua_S,"new",lua_cocos2dx_fgui_GTextInput_constructor);
        tolua_function(tolua_S,"getString",lua_cocos2dx_fgui_GTextInput_getString);
        tolua_function(tolua_S,"setSingleLine",lua_cocos2dx_fgui_GTextInput_setSingleLine);
        tolua_function(tolua_S,"setString",lua_cocos2dx_fgui_GTextInput_setString);
        tolua_function(tolua_S,"init",lua_cocos2dx_fgui_GTextInput_init);
        tolua_function(tolua_S,"setPassword",lua_cocos2dx_fgui_GTextInput_setPassword);
        tolua_function(tolua_S,"applyTextFormat",lua_cocos2dx_fgui_GTextInput_applyTextFormat);
        tolua_function(tolua_S,"isSingleLine",lua_cocos2dx_fgui_GTextInput_isSingleLine);
        tolua_function(tolua_S,"create", lua_cocos2dx_fgui_GTextInput_create);
    tolua_endmodule(tolua_S);
    std::string typeName = typeid(fgui::GTextInput).name();
    g_luaType[typeName] = "fgui::GTextInput";
    g_typeCast["GTextInput"] = "fgui::GTextInput";
    return 1;
}

int lua_cocos2dx_fgui_UIConfig_registerFont(lua_State* tolua_S)
{
    int argc = 0;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif

#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertable(tolua_S,1,"fgui::UIConfig",0,&tolua_err)) goto tolua_lerror;
#endif

    argc = lua_gettop(tolua_S) - 1;

    if (argc == 2)
    {
        std::string arg0;
        std::string arg1;
        ok &= luaval_to_std_string(tolua_S, 2,&arg0, "fgui::UIConfig:registerFont");
        ok &= luaval_to_std_string(tolua_S, 3,&arg1, "fgui::UIConfig:registerFont");
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_cocos2dx_fgui_UIConfig_registerFont'", nullptr);
            return 0;
        }
        fgui::UIConfig::registerFont(arg0, arg1);
        lua_settop(tolua_S, 1);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d\n ", "fgui::UIConfig:registerFont",argc, 2);
    return 0;
#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_fgui_UIConfig_registerFont'.",&tolua_err);
#endif
    return 0;
}
int lua_cocos2dx_fgui_UIConfig_getRealFontName(lua_State* tolua_S)
{
    int argc = 0;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif

#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertable(tolua_S,1,"fgui::UIConfig",0,&tolua_err)) goto tolua_lerror;
#endif

    argc = lua_gettop(tolua_S) - 1;

    if (argc == 1)
    {
        std::string arg0;
        ok &= luaval_to_std_string(tolua_S, 2,&arg0, "fgui::UIConfig:getRealFontName");
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_cocos2dx_fgui_UIConfig_getRealFontName'", nullptr);
            return 0;
        }
        const std::string& ret = fgui::UIConfig::getRealFontName(arg0);
        lua_pushlstring(tolua_S,ret.c_str(),ret.length());
        return 1;
    }
    if (argc == 2)
    {
        std::string arg0;
        bool* arg1;
        ok &= luaval_to_std_string(tolua_S, 2,&arg0, "fgui::UIConfig:getRealFontName");
        #pragma warning NO CONVERSION TO NATIVE FOR bool*
		ok = false;
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_cocos2dx_fgui_UIConfig_getRealFontName'", nullptr);
            return 0;
        }
        const std::string& ret = fgui::UIConfig::getRealFontName(arg0, arg1);
        lua_pushlstring(tolua_S,ret.c_str(),ret.length());
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d\n ", "fgui::UIConfig:getRealFontName",argc, 1);
    return 0;
#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_fgui_UIConfig_getRealFontName'.",&tolua_err);
#endif
    return 0;
}
static int lua_cocos2dx_fgui_UIConfig_finalize(lua_State* tolua_S)
{
    printf("luabindings: finalizing LUA object (UIConfig)");
    return 0;
}

int lua_register_cocos2dx_fgui_UIConfig(lua_State* tolua_S)
{
    tolua_usertype(tolua_S,"fgui::UIConfig");
    tolua_cclass(tolua_S,"UIConfig","fgui::UIConfig","",nullptr);

    tolua_beginmodule(tolua_S,"UIConfig");
        tolua_function(tolua_S,"registerFont", lua_cocos2dx_fgui_UIConfig_registerFont);
        tolua_function(tolua_S,"getRealFontName", lua_cocos2dx_fgui_UIConfig_getRealFontName);
    tolua_endmodule(tolua_S);
    std::string typeName = typeid(fgui::UIConfig).name();
    g_luaType[typeName] = "fgui::UIConfig";
    g_typeCast["UIConfig"] = "fgui::UIConfig";
    return 1;
}
TOLUA_API int register_all_cocos2dx_fgui(lua_State* tolua_S)
{
	tolua_open(tolua_S);
	
	tolua_module(tolua_S,"fgui",0);
	tolua_beginmodule(tolua_S,"fgui");

	lua_register_cocos2dx_fgui_GObject(tolua_S);
	lua_register_cocos2dx_fgui_GContainer(tolua_S);
	lua_register_cocos2dx_fgui_TweenManager(tolua_S);
	lua_register_cocos2dx_fgui_GAnimation(tolua_S);
	lua_register_cocos2dx_fgui_TextFormat(tolua_S);
	lua_register_cocos2dx_fgui_GComponent(tolua_S);
	lua_register_cocos2dx_fgui_GButton(tolua_S);
	lua_register_cocos2dx_fgui_GGroup(tolua_S);
	lua_register_cocos2dx_fgui_UIConfig(tolua_S);
	lua_register_cocos2dx_fgui_GText(tolua_S);
	lua_register_cocos2dx_fgui_PackageManager(tolua_S);
	lua_register_cocos2dx_fgui_GTweener(tolua_S);
	lua_register_cocos2dx_fgui_GSprite(tolua_S);
	lua_register_cocos2dx_fgui_PkgItem(tolua_S);
	lua_register_cocos2dx_fgui_Package(tolua_S);
	lua_register_cocos2dx_fgui_GGraph(tolua_S);
	lua_register_cocos2dx_fgui_GController(tolua_S);
	lua_register_cocos2dx_fgui_GRichText(tolua_S);
	lua_register_cocos2dx_fgui_GList(tolua_S);
	lua_register_cocos2dx_fgui_GLabel(tolua_S);
	lua_register_cocos2dx_fgui_GSlider(tolua_S);
	lua_register_cocos2dx_fgui_GTextInput(tolua_S);
	lua_register_cocos2dx_fgui_GTransition(tolua_S);
	lua_register_cocos2dx_fgui_GLoader(tolua_S);
	lua_register_cocos2dx_fgui_GProgressBar(tolua_S);

	tolua_endmodule(tolua_S);
	return 1;
}

