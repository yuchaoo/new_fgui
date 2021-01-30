#pragma once
#ifdef __cplusplus
extern "C" {
#endif
#include "tolua++.h"
#ifdef __cplusplus
}
#endif

int register_fgui_manual(lua_State* L);
int register_fgui_module(lua_State* L);
