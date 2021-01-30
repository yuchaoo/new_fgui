#include "scripting/lua-bindings/auto/lua_cocos2dx_fgui_auto.hpp"
#include "scripting/lua-bindings/manual/LuaBasicConversions.h"
#include "scripting/lua-bindings/manual/cocos2d/LuaScriptHandlerMgr.h"
#include "scripting/lua-bindings/manual/CCLuaEngine.h"
#include "lua_cocos2dx_fgui_manual.h"
#include "FGui.h"
#include "cocos2d.h"

enum FGUI_EVENT
{
	kGButtonClick = 101,
	kGSliderProgress = 102,
	kGlistUpdate = 103,
	kGTransitionPlay = 104,
	kGTransitionHook = 105,
	kTweenerOnComplete = 106,
	kTweenerOnUpdate = 107,
	kTweenerOnStart = 108,
	kGContainerUpdate = 109,
};

int lua_cocos2dx_fgui_GAnimation_setFrames(lua_State* tolua_S) {
	int argc = 0;
	fgui::GAnimation* cobj = nullptr;
	bool ok = true;
	std::vector<cocos2d::AnimationFrame*> frames;

#if COCOS2D_DEBUG >= 1
	tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
	if (!tolua_isusertype(tolua_S, 1, "fgui.GAnimation", 0, &tolua_err)) goto tolua_lerror;
#endif

	cobj = (fgui::GAnimation*)tolua_tousertype(tolua_S, 1, 0);

#if COCOS2D_DEBUG >= 1
	if (!cobj)
	{
		tolua_error(tolua_S, "invalid 'cobj' in function 'lua_cocos2dx_fgui_GAnimation_setFrames'", nullptr);
		return 0;
	}
#endif

	if (!lua_istable(tolua_S, 2)) {
		luaL_error(tolua_S, "args 2 is not table in 'lua_cocos2dx_fgui_GAnimation_setFrames'\n");
		return 0;
	}
	int len = lua_objlen(tolua_S, 2);
	frames.resize(len);
	for (int i = 0; i < len; ++i) {
		lua_rawgeti(tolua_S, 2, i + 1);
		luaval_to_object(tolua_S, -1, "cocos2d::AnimationFrame", &frames[i], "lua_cocos2dx_fgui_GAnimation_setFrames");
		lua_pop(tolua_S, 1);
	}
	cobj->setFrames(frames);
	return 1;

#if COCOS2D_DEBUG >= 1
	tolua_lerror:
	tolua_error(tolua_S, "#ferror in function 'lua_cocos2dx_fgui_GAnimation_setFrames'.", &tolua_err);
#endif

	return 0;
}

int lua_cocos2dx_fgui_GAnimation_getFrames(lua_State* tolua_S) {
	int argc = 0;
	fgui::GAnimation* cobj = nullptr;
	bool ok = true;

#if COCOS2D_DEBUG >= 1
	tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
	if (!tolua_isusertype(tolua_S, 1, "fgui.GAnimation", 0, &tolua_err)) goto tolua_lerror;
#endif

	cobj = (fgui::GAnimation*)tolua_tousertype(tolua_S, 1, 0);

#if COCOS2D_DEBUG >= 1
	if (!cobj)
	{
		tolua_error(tolua_S, "invalid 'cobj' in function 'lua_cocos2dx_fgui_GAnimation_getFrames'", nullptr);
		return 0;
	}
#endif
	
	lua_newtable(tolua_S);
	const auto& frames = cobj->getFrames();
	for (size_t i = 0; i < frames.size(); ++i) {
		object_to_luaval(tolua_S, "cocos2d::AnimationFrame", frames[i]);
		lua_rawseti(tolua_S, -1, i + 1);
	}
	return 1;

#if COCOS2D_DEBUG >= 1
	tolua_lerror:
	tolua_error(tolua_S, "#ferror in function 'lua_cocos2dx_fgui_GAnimation_getFrames'.", &tolua_err);
#endif

	return 0;
}

int register_fgui_GAnimation_manual(lua_State* L) {
	lua_pushstring(L, "fgui.GAnimation");
	lua_rawget(L, LUA_REGISTRYINDEX);
	if (lua_istable(L, -1))
	{
		tolua_function(L, "setFrames", lua_cocos2dx_fgui_GAnimation_setFrames);
		tolua_function(L, "getFrames", lua_cocos2dx_fgui_GAnimation_getFrames);
	}
	lua_pop(L, 1);
	return 1;
}


int lua_cocos2dx_fgui_GButton_setClickListener(lua_State* tolua_S) {
#if COCOS2D_DEBUG >= 1
	if (!tolua_isusertype(tolua_S, 1, "fgui::GButton", 0, NULL)) {
		CCLOG("arg1 is not fgui::GButton in 'lua_cocos2dx_fgui_GButton_setClickListener'");
		return 0;
	}
#endif
	fgui::GButton* btn = NULL;
	luaval_to_object(tolua_S, 1, "fgui::GButton", &btn, "lua_cocos2dx_fgui_GButton_setClickListener");
	if (!btn) {
		CCLOG("get arg1 empty, 'lua_cocos2dx_fgui_GButton_setClickListener'");
		return 0;
	}
#if COCOS2D_DEBUG >= 1 
	if (!toluafix_isfunction(tolua_S, 2, "LUA_FUNCTION", 0, NULL)) {
		CCLOG("arg2 is not lua function , in 'lua_cocos2dx_fgui_GButton_setClickListener'");
		return 0;
	}
#endif
	ScriptHandlerMgr* mgr = ScriptHandlerMgr::getInstance();
	mgr->removeObjectHandler(btn, (ScriptHandlerMgr::HandlerType)FGUI_EVENT::kGButtonClick);

	int handler = toluafix_ref_function(tolua_S, 2, 0);
	btn->setClickListener([handler]() {
		cocos2d::LuaEngine::getInstance()->getLuaStack()->executeFunctionByHandler(handler, 0);
	});
	mgr->addObjectHandler(btn, handler, (ScriptHandlerMgr::HandlerType)FGUI_EVENT::kGButtonClick);
	
	return 0;
}

int register_fgui_GButton_manual(lua_State* L) {
	lua_pushstring(L, "fgui.GButton");
	lua_rawget(L, LUA_REGISTRYINDEX);
	if (lua_istable(L, -1))
	{
		tolua_function(L, "setClickListener", lua_cocos2dx_fgui_GButton_setClickListener);
	}
	lua_pop(L, 1);
	return 1;
}

int lua_cocos2dx_fgui_GSlider_setSlidingCallback(lua_State* tolua_S) {
#if COCOS2D_DEBUG >= 1
	if (!tolua_isusertype(tolua_S, 1, "fgui::GSlider", 0, NULL)) {
		CCLOG("arg1 is not fgui::GSlider in 'lua_cocos2dx_fgui_GSlider_setSlidingCallback'");
		return 0;
	}
#endif
	fgui::GSlider* slider = NULL;
	luaval_to_object(tolua_S, 1, "fgui::GSlider", &slider, "lua_cocos2dx_fgui_GSlider_setSlidingCallback");
	if (!slider) {
		CCLOG("get arg1 empty, 'lua_cocos2dx_fgui_GSlider_setSlidingCallback'");
		return 0;
	}
#if COCOS2D_DEBUG >= 1 
	if (!toluafix_isfunction(tolua_S, 2, "LUA_FUNCTION", 0, NULL)) {
		CCLOG("arg2 is not lua function , in 'lua_cocos2dx_fgui_GSlider_setSlidingCallback'");
		return 0;
	}
#endif
	ScriptHandlerMgr* mgr = ScriptHandlerMgr::getInstance();
	mgr->removeObjectHandler(slider, (ScriptHandlerMgr::HandlerType)FGUI_EVENT::kGSliderProgress);

	int handler = toluafix_ref_function(tolua_S, 2, 0);
	slider->setSlidingCallback([handler](float percent) {
		auto luaStack = cocos2d::LuaEngine::getInstance()->getLuaStack();
		lua_pushnumber(luaStack->getLuaState(), percent);
		luaStack->executeFunctionByHandler(handler, 1);
	});
	mgr->addObjectHandler(slider, handler, (ScriptHandlerMgr::HandlerType)FGUI_EVENT::kGSliderProgress);

	return 0;
}

int register_fgui_GSlider_manual(lua_State* L) {
	lua_pushstring(L, "fgui.GSlider");
	lua_rawget(L, LUA_REGISTRYINDEX);
	if (lua_istable(L, -1))
	{
		tolua_function(L, "setSlidingCallback", lua_cocos2dx_fgui_GSlider_setSlidingCallback);
	}
	lua_pop(L, 1);
	return 1;
}

int lua_cocos2dx_fgui_GList_setUpdateNodeCallback(lua_State* tolua_S) {
#if COCOS2D_DEBUG >= 1
	if (!tolua_isusertype(tolua_S, 1, "fgui::GList", 0, NULL)) {
		CCLOG("arg1 is not fgui::GList in 'lua_cocos2dx_fgui_GList_setUpdateNodeCallback'");
		return 0;
	}
#endif
	fgui::GList* slider = NULL;
	luaval_to_object(tolua_S, 1, "fgui::GList", &slider, "lua_cocos2dx_fgui_GList_setUpdateNodeCallback");
	if (!slider) {
		CCLOG("get arg1 empty, 'lua_cocos2dx_fgui_GList_setUpdateNodeCallback'");
		return 0;
	}
#if COCOS2D_DEBUG >= 1 
	if (!toluafix_isfunction(tolua_S, 2, "LUA_FUNCTION", 0, NULL)) {
		CCLOG("arg2 is not lua function , in 'lua_cocos2dx_fgui_GList_setUpdateNodeCallback'");
		return 0;
	}
#endif
	ScriptHandlerMgr* mgr = ScriptHandlerMgr::getInstance();
	mgr->removeObjectHandler(slider, (ScriptHandlerMgr::HandlerType)FGUI_EVENT::kGlistUpdate);

	int handler = toluafix_ref_function(tolua_S, 2, 0);
	slider->setUpdateNodeCallback([handler](cocos2d::Node* node, int index) {
		auto luaStack = cocos2d::LuaEngine::getInstance()->getLuaStack();
		auto L = luaStack->getLuaState();
		object_to_luaval(L, "cc.Node", node);
		lua_pushinteger(L, index);
		luaStack->executeFunctionByHandler(handler, 2);
	});
	mgr->addObjectHandler(slider, handler, (ScriptHandlerMgr::HandlerType)FGUI_EVENT::kGlistUpdate);

	return 0;
}

int register_fgui_GList_manual(lua_State* L) {
	lua_pushstring(L, "fgui.GList");
	lua_rawget(L, LUA_REGISTRYINDEX);
	if (lua_istable(L, -1))
	{
		tolua_function(L, "setUpdateNodeCallback", lua_cocos2dx_fgui_GList_setUpdateNodeCallback);
	}
	lua_pop(L, 1);
	return 1;
}

int lua_cocos2dx_fgui_GTransition_play(lua_State* tolua_S) {
#if COCOS2D_DEBUG >= 1
	if (!tolua_isusertype(tolua_S, 1, "fgui::GTransition", 0, NULL)) {
		CCLOG("arg1 is not fgui::GTransition in 'lua_cocos2dx_fgui_GTransition_play'");
		return 0;
	}
#endif
	fgui::GTransition* transion = NULL;
	luaval_to_object(tolua_S, 1, "fgui::GTransition", &transion, "lua_cocos2dx_fgui_GTransition_play");
	if (!transion) {
		CCLOG("get arg1 empty, 'lua_cocos2dx_fgui_GTransition_play'");
		return 0;
	}
	ScriptHandlerMgr* mgr = ScriptHandlerMgr::getInstance();

	int n = lua_gettop(tolua_S) - 1;
	if (n == 0) {
		transion->play();
	}
	else if(n == 1){
#if COCOS2D_DEBUG >= 1 
		if (!toluafix_isfunction(tolua_S, 2, "LUA_FUNCTION", 0, NULL)) {
			CCLOG("arg2 is not lua function , in 'lua_cocos2dx_fgui_GTransition_play'");
			return 0;
		}
#endif
		mgr->removeObjectHandler(transion, (ScriptHandlerMgr::HandlerType)FGUI_EVENT::kGTransitionPlay);
		int handler = toluafix_ref_function(tolua_S, 2, 0);
		transion->play([handler]() {
			auto luaStack = cocos2d::LuaEngine::getInstance()->getLuaStack();
			auto L = luaStack->getLuaState();
			luaStack->executeFunctionByHandler(handler, 0);
		});
		mgr->addObjectHandler(transion, handler, (ScriptHandlerMgr::HandlerType)FGUI_EVENT::kGTransitionPlay);
	}
	else if (n == 2) {
		int times = luaL_checkinteger(tolua_S, 2);
		float delay = luaL_checknumber(tolua_S, 3);
		transion->play(times, delay);
	}
	else if (n == 3) {
		int times = luaL_checkinteger(tolua_S, 2);
		float delay = luaL_checknumber(tolua_S, 3);
#if COCOS2D_DEBUG >= 1 
		if (!toluafix_isfunction(tolua_S, 4, "LUA_FUNCTION", 0, NULL)) {
			CCLOG("arg4 is not lua function , in 'lua_cocos2dx_fgui_GTransition_play'");
			return 0;
		}
#endif
		mgr->removeObjectHandler(transion, (ScriptHandlerMgr::HandlerType)FGUI_EVENT::kGTransitionPlay);
		int handler = toluafix_ref_function(tolua_S, 4, 0);
		transion->play([handler]() {
			auto luaStack = cocos2d::LuaEngine::getInstance()->getLuaStack();
			auto L = luaStack->getLuaState();
			luaStack->executeFunctionByHandler(handler, 0);
		});
		mgr->addObjectHandler(transion, handler, (ScriptHandlerMgr::HandlerType)FGUI_EVENT::kGTransitionPlay);
	}
	else if (n == 4) {
		int times = luaL_checkinteger(tolua_S, 2);
		float delay = luaL_checknumber(tolua_S, 3);
		float startTime = luaL_checknumber(tolua_S, 4);
		float endTime = luaL_checknumber(tolua_S, 5);
		transion->play(times, delay, startTime, endTime);
	}
	else if (n == 5) {
		int times = luaL_checkinteger(tolua_S, 2);
		float delay = luaL_checknumber(tolua_S, 3);
		float startTime = luaL_checknumber(tolua_S, 4);
		float endTime = luaL_checknumber(tolua_S, 5);
#if COCOS2D_DEBUG >= 1 
		if (!toluafix_isfunction(tolua_S, 6, "LUA_FUNCTION", 0, NULL)) {
			CCLOG("arg6 is not lua function , in 'lua_cocos2dx_fgui_GTransition_play'");
			return 0;
		}
#endif
		mgr->removeObjectHandler(transion, (ScriptHandlerMgr::HandlerType)FGUI_EVENT::kGTransitionPlay);
		int handler = toluafix_ref_function(tolua_S, 6, 0);
		transion->play([handler]() {
			auto luaStack = cocos2d::LuaEngine::getInstance()->getLuaStack();
			auto L = luaStack->getLuaState();
			luaStack->executeFunctionByHandler(handler, 0);
		});
		mgr->addObjectHandler(transion, handler, (ScriptHandlerMgr::HandlerType)FGUI_EVENT::kGTransitionPlay);
	}

	return 0;
}

int lua_cocos2dx_fgui_GTransition_playReverse(lua_State* tolua_S) {
#if COCOS2D_DEBUG >= 1
	if (!tolua_isusertype(tolua_S, 1, "fgui::GTransition", 0, NULL)) {
		CCLOG("arg1 is not fgui::GTransition in 'lua_cocos2dx_fgui_GTransition_play'");
		return 0;
	}
#endif
	fgui::GTransition* transion = NULL;
	luaval_to_object(tolua_S, 1, "fgui::GTransition", &transion, "lua_cocos2dx_fgui_GTransition_play");
	if (!transion) {
		CCLOG("get arg1 empty, 'lua_cocos2dx_fgui_GTransition_play'");
		return 0;
	}
	ScriptHandlerMgr* mgr = ScriptHandlerMgr::getInstance();

	int n = lua_gettop(tolua_S) - 1;
	if (n == 0) {
		transion->playReverse();
	}
	else if (n == 1) {
#if COCOS2D_DEBUG >= 1 
		if (!toluafix_isfunction(tolua_S, 2, "LUA_FUNCTION", 0, NULL)) {
			CCLOG("arg2 is not lua function , in 'lua_cocos2dx_fgui_GTransition_play'");
			return 0;
		}
#endif
		mgr->removeObjectHandler(transion, (ScriptHandlerMgr::HandlerType)FGUI_EVENT::kGTransitionPlay);
		int handler = toluafix_ref_function(tolua_S, 2, 0);
		transion->play([handler]() {
			auto luaStack = cocos2d::LuaEngine::getInstance()->getLuaStack();
			auto L = luaStack->getLuaState();
			luaStack->executeFunctionByHandler(handler, 0);
			});
		mgr->addObjectHandler(transion, handler, (ScriptHandlerMgr::HandlerType)FGUI_EVENT::kGTransitionPlay);
	}
	else if (n == 2) {
		int times = luaL_checkinteger(tolua_S, 2);
		float delay = luaL_checknumber(tolua_S, 3);
		transion->playReverse(times, delay);
	}
	else if (n == 3) {
		int times = luaL_checkinteger(tolua_S, 2);
		float delay = luaL_checknumber(tolua_S, 3);
#if COCOS2D_DEBUG >= 1 
		if (!toluafix_isfunction(tolua_S, 4, "LUA_FUNCTION", 0, NULL)) {
			CCLOG("arg4 is not lua function , in 'lua_cocos2dx_fgui_GTransition_play'");
			return 0;
		}
#endif
		mgr->removeObjectHandler(transion, (ScriptHandlerMgr::HandlerType)FGUI_EVENT::kGTransitionPlay);
		int handler = toluafix_ref_function(tolua_S, 4, 0);
		transion->playReverse([handler]() {
			auto luaStack = cocos2d::LuaEngine::getInstance()->getLuaStack();
			auto L = luaStack->getLuaState();
			luaStack->executeFunctionByHandler(handler, 0);
		});
		mgr->addObjectHandler(transion, handler, (ScriptHandlerMgr::HandlerType)FGUI_EVENT::kGTransitionPlay);
	}
	return 0;
}

int lua_cocos2dx_fgui_GTransition_setHook(lua_State* tolua_S) {
#if COCOS2D_DEBUG >= 1
	if (!tolua_isusertype(tolua_S, 1, "fgui::GTransition", 0, NULL)) {
		CCLOG("arg1 is not fgui::GTransition in 'lua_cocos2dx_fgui_GTransition_setHook'");
		return 0;
	}
#endif
	fgui::GTransition* transion = NULL;
	luaval_to_object(tolua_S, 1, "fgui::GTransition", &transion, "lua_cocos2dx_fgui_GTransition_setHook");
	if (!transion) {
		CCLOG("get arg1 empty, 'lua_cocos2dx_fgui_GTransition_setHook'");
		return 0;
	}
	ScriptHandlerMgr* mgr = ScriptHandlerMgr::getInstance();

	int n = lua_gettop(tolua_S) - 1;
	if (n == 2) {
		const char* label = luaL_checkstring(tolua_S, 2);
#if COCOS2D_DEBUG >= 1 
		if (!toluafix_isfunction(tolua_S, 3, "LUA_FUNCTION", 0, NULL)) {
			CCLOG("arg3 is not lua function , in 'lua_cocos2dx_fgui_GTransition_setHook'");
			return 0;
		}
#endif
		mgr->removeObjectHandler(transion, (ScriptHandlerMgr::HandlerType)FGUI_EVENT::kGTransitionHook);
		int handler = toluafix_ref_function(tolua_S, 3, 0);
		transion->setHook(label,[handler]() {
			auto luaStack = cocos2d::LuaEngine::getInstance()->getLuaStack();
			auto L = luaStack->getLuaState();
			luaStack->executeFunctionByHandler(handler, 0);
		});
		mgr->addObjectHandler(transion, handler, (ScriptHandlerMgr::HandlerType)FGUI_EVENT::kGTransitionHook);
	}
	return 0;
}

int register_fgui_GTransition_manual(lua_State* L) {
	lua_pushstring(L, "fgui.GTransition");
	lua_rawget(L, LUA_REGISTRYINDEX);
	if (lua_istable(L, -1))
	{
		tolua_function(L, "play", lua_cocos2dx_fgui_GTransition_play);
		tolua_function(L, "playReverse", lua_cocos2dx_fgui_GTransition_playReverse);
		tolua_function(L, "setHook", lua_cocos2dx_fgui_GTransition_setHook);
	}
	lua_pop(L, 1);
	return 1;
}

int lua_cocos2dx_fgui_GTweener_onComplete(lua_State* tolua_S) {
#if COCOS2D_DEBUG >= 1
	if (!tolua_isusertype(tolua_S, 1, "fgui::GTweener", 0, NULL)) {
		CCLOG("arg1 is not fgui::GTweener in 'lua_cocos2dx_fgui_GTweener_onComplete'");
		return 0;
	}
#endif
	fgui::GTweener* tweener = NULL;
	luaval_to_object(tolua_S, 1, "fgui::GTweener", &tweener, "lua_cocos2dx_fgui_GTweener_onComplete");
	if (!tweener) {
		CCLOG("get arg1 empty, 'lua_cocos2dx_fgui_GTweener_onComplete'");
		return 0;
	}
	ScriptHandlerMgr* mgr = ScriptHandlerMgr::getInstance();

#if COCOS2D_DEBUG >= 1 
	if (!toluafix_isfunction(tolua_S, 2, "LUA_FUNCTION", 0, NULL)) {
		CCLOG("arg2 is not lua function , in 'lua_cocos2dx_fgui_GTweener_onComplete'");
		return 0;
	}
#endif
	mgr->removeObjectHandler(tweener, (ScriptHandlerMgr::HandlerType)FGUI_EVENT::kTweenerOnComplete);
	int handler = toluafix_ref_function(tolua_S, 2, 0);
	tweener->onComplete([handler]() {
		auto luaStack = cocos2d::LuaEngine::getInstance()->getLuaStack();
		auto L = luaStack->getLuaState();
		luaStack->executeFunctionByHandler(handler, 0);
	});
	mgr->addObjectHandler(tweener, handler, (ScriptHandlerMgr::HandlerType)FGUI_EVENT::kTweenerOnComplete);
	return 0;
}

int lua_cocos2dx_fgui_GTweener_onUpdate(lua_State* tolua_S) {
#if COCOS2D_DEBUG >= 1
	if (!tolua_isusertype(tolua_S, 1, "fgui::GTweener", 0, NULL)) {
		CCLOG("arg1 is not fgui::GTweener in 'lua_cocos2dx_fgui_GTweener_onUpdate'");
		return 0;
	}
#endif
	fgui::GTweener* tweener = NULL;
	luaval_to_object(tolua_S, 1, "fgui::GTweener", &tweener, "lua_cocos2dx_fgui_GTweener_onUpdate");
	if (!tweener) {
		CCLOG("get arg1 empty, 'lua_cocos2dx_fgui_GTweener_onUpdate'");
		return 0;
	}
	ScriptHandlerMgr* mgr = ScriptHandlerMgr::getInstance();

#if COCOS2D_DEBUG >= 1 
	if (!toluafix_isfunction(tolua_S, 2, "LUA_FUNCTION", 0, NULL)) {
		CCLOG("arg2 is not lua function , in 'lua_cocos2dx_fgui_GTweener_onUpdate'");
		return 0;
	}
#endif
	mgr->removeObjectHandler(tweener, (ScriptHandlerMgr::HandlerType)FGUI_EVENT::kTweenerOnUpdate);
	int handler = toluafix_ref_function(tolua_S, 2, 0);
	tweener->onUpdate([handler](fgui::GTweener*) {
		auto luaStack = cocos2d::LuaEngine::getInstance()->getLuaStack();
		auto L = luaStack->getLuaState();
		luaStack->executeFunctionByHandler(handler, 0);
	});
	mgr->addObjectHandler(tweener, handler, (ScriptHandlerMgr::HandlerType)FGUI_EVENT::kTweenerOnUpdate);
	return 0;
}

int lua_cocos2dx_fgui_GTweener_onStart(lua_State* tolua_S) {
#if COCOS2D_DEBUG >= 1
	if (!tolua_isusertype(tolua_S, 1, "fgui::GTweener", 0, NULL)) {
		CCLOG("arg1 is not fgui::GTweener in 'lua_cocos2dx_fgui_GTweener_onStart'");
		return 0;
	}
#endif
	fgui::GTweener* tweener = NULL;
	luaval_to_object(tolua_S, 1, "fgui::GTweener", &tweener, "lua_cocos2dx_fgui_GTweener_onStart");
	if (!tweener) {
		CCLOG("get arg1 empty, 'lua_cocos2dx_fgui_GTweener_onStart'");
		return 0;
	}
	ScriptHandlerMgr* mgr = ScriptHandlerMgr::getInstance();

#if COCOS2D_DEBUG >= 1 
	if (!toluafix_isfunction(tolua_S, 2, "LUA_FUNCTION", 0, NULL)) {
		CCLOG("arg2 is not lua function , in 'lua_cocos2dx_fgui_GTweener_onStart'");
		return 0;
	}
#endif
	mgr->removeObjectHandler(tweener, (ScriptHandlerMgr::HandlerType)FGUI_EVENT::kTweenerOnStart);
	int handler = toluafix_ref_function(tolua_S, 2, 0);
	tweener->onStart([handler](fgui::GTweener*) {
		auto luaStack = cocos2d::LuaEngine::getInstance()->getLuaStack();
		auto L = luaStack->getLuaState();
		luaStack->executeFunctionByHandler(handler, 0);
	});
	mgr->addObjectHandler(tweener, handler, (ScriptHandlerMgr::HandlerType)FGUI_EVENT::kTweenerOnStart);
	return 0;
}

int register_fgui_GTweener_manual(lua_State* L) {
	lua_pushstring(L, "fgui.GTweener");
	lua_rawget(L, LUA_REGISTRYINDEX);
	if (lua_istable(L, -1))
	{
		tolua_function(L, "onComplete", lua_cocos2dx_fgui_GTweener_onComplete);
		tolua_function(L, "onUpdate", lua_cocos2dx_fgui_GTweener_onUpdate);
		tolua_function(L, "onStart", lua_cocos2dx_fgui_GTweener_onStart);
	}
	lua_pop(L, 1);
	return 1;
}

int lua_cocos2dx_fgui_GContainer_setUpdateNodeCallback(lua_State* tolua_S) {
#if COCOS2D_DEBUG >= 1
	if (!tolua_isusertype(tolua_S, 1, "fgui::GContainer", 0, NULL)) {
		CCLOG("arg1 is not fgui::GList in 'lua_cocos2dx_fgui_GContainer_setUpdateNodeCallback'");
		return 0;
	}
#endif
	fgui::GContainer* container = NULL;
	luaval_to_object(tolua_S, 1, "fgui::GContainer", &container, "lua_cocos2dx_fgui_GContainer_setUpdateNodeCallback");
	if (!container) {
		CCLOG("get arg1 empty, 'lua_cocos2dx_fgui_GContainer_setUpdateNodeCallback'");
		return 0;
	}
#if COCOS2D_DEBUG >= 1 
	if (!toluafix_isfunction(tolua_S, 2, "LUA_FUNCTION", 0, NULL)) {
		CCLOG("arg2 is not lua function , in 'lua_cocos2dx_fgui_GContainer_setUpdateNodeCallback'");
		return 0;
	}
#endif
	ScriptHandlerMgr* mgr = ScriptHandlerMgr::getInstance();
	mgr->removeObjectHandler(container, (ScriptHandlerMgr::HandlerType)FGUI_EVENT::kGContainerUpdate);

	int handler = toluafix_ref_function(tolua_S, 2, 0);
	container->setUpdateNodeCallback([handler](cocos2d::Node* node, int index) {
		auto luaStack = cocos2d::LuaEngine::getInstance()->getLuaStack();
		auto L = luaStack->getLuaState();
		object_to_luaval(L, "cc.Node", node);
		lua_pushinteger(L, index);
		luaStack->executeFunctionByHandler(handler, 2);
	});
	mgr->addObjectHandler(container, handler, (ScriptHandlerMgr::HandlerType)FGUI_EVENT::kGContainerUpdate);

	return 0;
}

int register_fgui_GContainer_manual(lua_State* L) {
	lua_pushstring(L, "fgui.GContainer");
	lua_rawget(L, LUA_REGISTRYINDEX);
	if (lua_istable(L, -1))
	{
		tolua_function(L, "setUpdateNodeCallback", lua_cocos2dx_fgui_GContainer_setUpdateNodeCallback);
	}
	lua_pop(L, 1);
	return 1;
}

int register_fgui_manual(lua_State* L) {
	register_fgui_GAnimation_manual(L);
	register_fgui_GButton_manual(L);
	register_fgui_GSlider_manual(L);
	register_fgui_GList_manual(L);
	register_fgui_GTransition_manual(L);
	register_fgui_GTweener_manual(L);
	register_fgui_GContainer_manual(L);
	return 1;
}

int register_fgui_module(lua_State* L) {
	lua_getglobal(L, "_G");
	register_all_cocos2dx_fgui(L);
	register_fgui_manual(L);
	lua_pop(L, 1);
	return 1;
}