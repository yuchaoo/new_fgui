#include "ccShaderEx.h"
#include "renderer/CCGLProgram.h"
#include "renderer/CCGLProgramCache.h"
#include "renderer/ccShaders.h"

void loadShaderEx() {
	cocos2d::GLProgram* program = new cocos2d::GLProgram();
	program->createWithByteArrays(cocos2d::ccPositionTextureColor_noMVP_vert, ccPositionTexture_GrayScale_frag);
	cocos2d::GLProgramCache::getInstance()->addGLProgram(program, SHADER_NAME_POSITION_GRAYSCALE);
}

