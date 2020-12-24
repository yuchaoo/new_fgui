#pragma once
#include "cocos2d.h"

namespace cocos2d {
	const BlendFunc SCREEN = { GL_ONE,GL_ONE_MINUS_SRC_COLOR };
	const BlendFunc MUTIPLY = { GL_DST_COLOR,GL_ONE_MINUS_SRC_COLOR };
	const BlendFunc NONE = { GL_ONE,GL_ONE };
	const BlendFunc NORMAL = { GL_SRC_ALPHA,GL_ONE_MINUS_SRC_ALPHA };
	const BlendFunc MASK = { GL_ZERO,GL_SRC_ALPHA };
	const BlendFunc BELOW = { GL_ONE_MINUS_DST_ALPHA,GL_DST_ALPHA };
	const BlendFunc OFF = { GL_ONE,GL_ZERO };
}
