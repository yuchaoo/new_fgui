#include "GSprite.h"
#include <algorithm>
#include "ccShaderEx.h"
#include "ccExtend.h"
#include "PkgItem.h"

USING_NS_CC;

namespace fgui {
	#define kProgressTextureCoordsCount 4

	const char kProgressTextureCoords = 0x4b;

	GSprite::GSprite() :
		_fillMethod(FillMethod::None),
		_fillOrigin(FillOrigin::Left),
		_fillAmount(0),
		_fillClockwise(false),
		_vertexDataCount(0),
		_vertexData(nullptr),
		_vertexCapacity(0),
		_bFillDirty(false),
		_flipType(FlipType::NONE)
	{
		
	}

	GSprite::~GSprite()
	{
		if (_vertexData) {
			delete _vertexData;
		}
	}

	GSprite* GSprite::create() {
		GSprite* sprite = new GSprite();
		if (sprite && sprite->init()) {
			sprite->autorelease();
			return sprite;
		}
		CC_SAFE_DELETE(sprite);
		return nullptr;
	}

	GSprite* GSprite::createWithTexture(Texture2D* texture) {
		GSprite* sprite = new (std::nothrow) GSprite();
		if (sprite && sprite->initWithTexture(texture))
		{
			sprite->autorelease();
			return sprite;
		}
		CC_SAFE_DELETE(sprite);
		return nullptr;
	}

	GSprite* GSprite::createWithFileName(const std::string& filename) {
		GSprite* sprite = new (std::nothrow) GSprite();
		if (sprite && sprite->initWithFile(filename))
		{
			sprite->autorelease();
			return sprite;
		}
		CC_SAFE_DELETE(sprite);
		return nullptr;
	}

	GSprite* GSprite::createWithTexture(Texture2D* texture, const Rect& rect, bool rotated) {
		GSprite* sprite = new (std::nothrow) GSprite();
		if (sprite && sprite->initWithTexture(texture, rect, rotated))
		{
			sprite->autorelease();
			return sprite;
		}
		CC_SAFE_DELETE(sprite);
		return nullptr;
	}

	GSprite* GSprite::createWithSpriteFrameName(const std::string& spriteFrameName) {
		SpriteFrame* frame = SpriteFrameCache::getInstance()->getSpriteFrameByName(spriteFrameName);
		return createWithSpriteFrame(frame);
	}

	GSprite* GSprite::createWithSpriteFrame(SpriteFrame* spriteFrame) {
		GSprite* sprite = new (std::nothrow) GSprite();
		if (sprite && spriteFrame && sprite->initWithSpriteFrame(spriteFrame))
		{
			sprite->autorelease();
			return sprite;
		}
		CC_SAFE_DELETE(sprite);
		return nullptr;
	}

	void GSprite::onEnter() {
		Sprite::onEnter();
		GObject::onEnter();
	}

	void GSprite::onExit() {
		Sprite::onExit();
		GObject::onExit();
	}

	void GSprite::clearContent()
	{
		setTexture(nullptr);
		CC_SAFE_RELEASE_NULL(_spriteFrame);
		setCenterRectNormalized(Rect(0, 0, 1, 1));
	}

	void GSprite::setScale9SpriteWithSpace(float l, float r, float b, float t) {
		cocos2d::Rect rt;
		rt.origin.x = std::max(0.0f, std::min(l, _rect.size.width));
		rt.origin.y = std::max(0.0f, std::min(b, _rect.size.height));
		rt.size.width = std::max(1.0f, std::min(_rect.size.width - l - r, _rect.size.width));
		rt.size.height = std::max(1.0f, std::min(_rect.size.height - b - t, _rect.size.height));
		setCenterRect(rt);
	}

	void GSprite::setScale9Sprite(const Rect * value)
	{
		if (value == nullptr){
			setCenterRectNormalized(Rect(0, 0, 1, 1));
			return;
		}

		Rect insets = *value;
		insets.origin.x = std::min(std::max(insets.origin.x , 0.0f),_rect.size.width);
		insets.origin.y = std::min(std::max(insets.origin.y, 0.0f), _rect.size.height);
		insets.size.width = std::max(1.0f, std::min(insets.size.width, _rect.size.width));
		insets.size.height = std::max(1.0f, std::min(insets.size.height, _rect.size.height));
		setCenterRect(insets);
	}

	void GSprite::setGrayed(bool value)
	{
		GLProgramState *glState = nullptr;
		if (value) {
			glState = GLProgramState::getOrCreateWithGLProgramName(GLProgram::SHADER_NAME_POSITION_GRAYSCALE);
		}
		else {
			glState = GLProgramState::getOrCreateWithGLProgramName(GLProgram::SHADER_NAME_POSITION_TEXTURE_COLOR_NO_MVP);
		}
		setGLProgramState(glState);
	}

	void GSprite::setFillMethod(FillMethod value)
	{
		if (_fillMethod != value) {
			_fillMethod = value;
			if (_fillMethod == FillMethod::Radial90) {
				if (_fillOrigin == FillOrigin::Top) {
					_fillOrigin = FillOrigin::LeftTop;
				}
				else if (_fillOrigin == FillOrigin::Bottom) {
					_fillOrigin = FillOrigin::RightTop;
				}
				else if (_fillOrigin == FillOrigin::Left) {
					_fillOrigin = FillOrigin::LeftBottom;
				}
				else if (_fillOrigin == FillOrigin::Right) {
					_fillOrigin = FillOrigin::RightBottom;
				}
			}
			_bFillDirty = true;
		}
	}

	void GSprite::setFillOrigin(FillOrigin value)
	{
		if (_fillOrigin != value) {
			_fillOrigin = value;
			if (_fillMethod == FillMethod::Radial90) {
				if (_fillOrigin == FillOrigin::Top) {
					_fillOrigin = FillOrigin::LeftTop;
				}
				else if (_fillOrigin == FillOrigin::Bottom) {
					_fillOrigin = FillOrigin::RightTop;
				}
				else if (_fillOrigin == FillOrigin::Left) {
					_fillOrigin = FillOrigin::LeftBottom;
				}
				else if (_fillOrigin == FillOrigin::Right) {
					_fillOrigin = FillOrigin::RightBottom;
				}
			}
			_bFillDirty = true;
		}
	}

	void GSprite::setFillClockwise(bool value)
	{
		if (_fillClockwise != value) {
			_fillClockwise = value;
			_bFillDirty = true;
		}
	}

	void GSprite::setFillAmount(float value)
	{
		if (_fillAmount != value) {
			_fillAmount = value;
			_bFillDirty = true;
		}
	}

	void GSprite::setBlendMode(BlendMode mode) {
		if (_blendMode != mode) {
			switch (mode)
			{
			case BlendMode::ADD:
				setBlendFunc(cocos2d::BlendFunc::ADDITIVE);
				break;
			case BlendMode::MULTIPLY:
				setBlendFunc(cocos2d::BlendFunc::MUTIPLY);
				break;
			case BlendMode::SCREEN:
				setBlendFunc(cocos2d::BlendFunc::SCREEN);
				break;

			case BlendMode::NONE:
				setBlendFunc(cocos2d::BlendFunc::NONE);
				break;
			case BlendMode::NORMAL:
				setBlendFunc(cocos2d::BlendFunc::NORMAL);
				break;
			}
			_blendMode = mode;
		}
	}

	void GSprite::setFlipType(FlipType type) {
		setFlippedX(type == FlipType::HORIZONTAL || type == FlipType::BOTH);
		setFlippedY(type == FlipType::VERTICAL || type == FlipType::BOTH);
	}

	void GSprite::setHSVMode(bool isHsv) {
		if (_isHsvMode == isHsv) {
			return;
		}
		_isHsvMode = isHsv;
		if (_isHsvMode) {
			GLProgram* program = GLProgram::createWithByteArrays(ccPositionTextureColor_noMVP_vert, ccPositionTextureColor_noMVP_hsv_frag);
			if (program) {
				CHECK_GL_ERROR_DEBUG();
				GLProgramState* state = GLProgramState::getOrCreateWithGLProgram(program);
				state->setUniformFloat(HSV_HUE, 0.0f);
				state->setUniformFloat(HSV_BRIGHTNESS, 0.0f);
				state->setUniformFloat(HSV_CONTRAST, 0.0f);
				state->setUniformFloat(HSV_SATURATION, 0.0f);
				setGLProgram(program);
				setGLProgramState(state);
			}
		}
		else {
			GLProgram* program = GLProgramCache::getInstance()->getGLProgram(GLProgram::SHADER_NAME_POSITION_TEXTURE_COLOR_NO_MVP);
			setGLProgram(program);
		}
	}

	//色调 ，饱和度， 亮度， 对比度
	void GSprite::setHSVValue(float hue, float saturation, float brightness, float contrast) {
		GObject::setHSVValue(hue, saturation, brightness, contrast);
		if (_isHsvMode) {
			GLProgramState* state = getGLProgramState();
			state->setUniformFloat(HSV_HUE, hue);
			state->setUniformFloat(HSV_SATURATION, saturation);
			state->setUniformFloat(HSV_BRIGHTNESS, brightness);
			state->setUniformFloat(HSV_CONTRAST, contrast);
		}
	}

	void GSprite::setContentSize(const Size& size) {
		cocos2d::Size oldSize = getContentSize();
		if (oldSize.equals(size)) {
			return;
		}
		Sprite::setContentSize(size);
		onContentSizeChanged(this, oldSize, size);
	}

	void GSprite::setPosition(float x, float y) {
		cocos2d::Vec2 oldPos = getPosition();
		cocos2d::Vec2 pos(x, y);
		if (oldPos.equals(pos)) {
			return;
		}
		Sprite::setPosition(x,y);
		onPositionChanged(this, oldPos, pos);
	}

	void GSprite::constructFromResource(UIPackage* pkg, PackageItem* pt) {
		GObject::constructFromResource(pkg, pt);
		pkg->loadItemAsset(pt);
		setSpriteFrame(pt->spriteFrame);
		if (pt->scale9Grid) {
			setScale9Sprite(pt->scale9Grid);
		}
	}

	void GSprite::setupBefore(ByteBuffer* buffer, int beginPos, cocos2d::Node* parent) {
		GObject::setupBefore(buffer, beginPos,parent);
		buffer->Seek(beginPos, 5);
		if (buffer->ReadBool()) {
			setColor((Color3B)buffer->ReadColor());
		}
		FlipType type = (FlipType)buffer->ReadByte();
		setFlipType(type);
		int fillMethod = buffer->ReadByte();
		if (fillMethod != 0) {
			setFillMethod((FillMethod)fillMethod);
			setFillOrigin((FillOrigin)buffer->ReadByte());
			setFillClockwise(buffer->ReadBool());
			setFillAmount(buffer->ReadFloat());
		}
		setBlendMode(_blendMode);
	}

	void GSprite::constructFromItem(Package* pkg, PkgItem* item) {
		GObject::constructFromItem(pkg, item);
		ImageItem* spriteItem = dynamic_cast<ImageItem*>(item);
		setSpriteFrame(spriteItem->getSpriteFrame());
		const cocos2d::Rect* rt = spriteItem->getScale9Rect();
		if (rt) {
			setScale9Sprite(rt);
		}
		else if(spriteItem->isScaleByTile()){
			Texture2D::TexParams tp = { GL_LINEAR, GL_LINEAR, GL_REPEAT, GL_REPEAT };
			getTexture()->setTexParameters(tp);
		}
	}

	void GSprite::setup(const ObjectInfo* inf, cocos2d::Node* parent) {
		GObject::setup(inf, parent);
		const SpriteInfo* info = dynamic_cast<const SpriteInfo*>(inf);
		if (info->color) {
			setColor((cocos2d::Color3B)*(info->color));
		}
		if (info->flipType != FlipType::NONE) {
			setFlipType(info->flipType);
		}
		if (info->fillMethod != FillMethod::None) {
			setFillMethod(info->fillMethod);
		}
		setFillOrigin(info->fillOrigin);
		setFillClockwise(info->bClockwise);
		setFillAmount(info->fillAmount);
		setBlendMode(info->blendMode);
		if (info->hsv) {
			setHSVMode(true);
			setHSVValue(info->hsv->x, info->hsv->y, info->hsv->z, info->hsv->w);
		}

		ImageItem* spriteItem = dynamic_cast<ImageItem*>(_item);
		if (spriteItem->isScaleByTile()) {
			const cocos2d::Size& size = this->getContentSize();
			this->setTextureRect(cocos2d::Rect(0, 0, size.width, size.height));
		}
	}

	void GSprite::setupFill()
	{
		if (_fillMethod == FillMethod::Horizontal || _fillMethod == FillMethod::Vertical)
			updateBar();
		else
			updateRadial();
	}

	Tex2F GSprite::textureCoordFromAlphaPoint(Vec2 alpha)
	{
		Tex2F ret(0.0f, 0.0f);

		V3F_C4B_T2F_Quad quad = getQuad();
		Vec2 min(quad.bl.texCoords.u, quad.bl.texCoords.v);
		Vec2 max(quad.tr.texCoords.u, quad.tr.texCoords.v);
		//  Fix bug #1303 so that progress timer handles sprite frame texture rotation
		if (isTextureRectRotated()) {
			std::swap(alpha.x, alpha.y);
		}
		return Tex2F(min.x * (1.f - alpha.x) + max.x * alpha.x, min.y * (1.f - alpha.y) + max.y * alpha.y);
	}

	Vec2 GSprite::vertexFromAlphaPoint(Vec2 alpha)
	{
		Vec2 ret(0.0f, 0.0f);

		V3F_C4B_T2F_Quad quad = getQuad();
		Vec2 min(quad.bl.vertices.x, quad.bl.vertices.y);
		Vec2 max(quad.tr.vertices.x, quad.tr.vertices.y);
		ret.x = min.x * (1.f - alpha.x) + max.x * alpha.x;
		ret.y = min.y * (1.f - alpha.y) + max.y * alpha.y;
		return this->convertToWorldSpace(ret);
	}

	void GSprite::updateColor(void)
	{
		Sprite::updateColor();

		if (_vertexData)
		{
			Color4B sc = getQuad().tl.colors;
			for (int i = 0; i < _vertexDataCount; ++i)
			{
				_vertexData[i].colors = sc;
			}
		}
	}

	void GSprite::getFillVetextAndAOrigin(std::vector<cocos2d::Vec2>& vertex, cocos2d::Vec2& origin, float& angle) {
		if (_fillMethod == FillMethod::Radial360) {
			origin = cocos2d::Vec2(0.5f, 0.5f);
			angle = M_PI * 2 * (_fillClockwise ? (1 - _fillAmount) : _fillAmount);
			if (_fillOrigin == FillOrigin::Left) {
				vertex = std::vector<cocos2d::Vec2>{ { 0.0f,0.5f },{ 0.0f,0.0f },{ 1.0f,0.0f },{ 1.0f,1.0f },{ 0.0f,1.0f } };
			}
			else if (_fillOrigin == FillOrigin::Bottom) {
				vertex = std::vector<cocos2d::Vec2>{ { 0.5f,0.0f },{ 1.0f,0.0f },{ 1.0f,1.0f },{ 0.0f,1.0f },{ 0.0f,0.0f } };
			}
			else if (_fillOrigin == FillOrigin::Top) {
				vertex = std::vector<cocos2d::Vec2>{ { 0.5f,1.0f },{ 0.0f,1.0f },{ 0.0f,0.0f },{ 1.0f,0.0f },{ 1.0f,1.0f } };
			}
			else if (_fillOrigin == FillOrigin::Right) {
				vertex = std::vector<cocos2d::Vec2>{ { 1.0f,0.5f },{ 1.0f,1.0f },{ 0.0f,1.0f },{ 0.0f,0.0f },{ 1.0f,0.0f } };
			}
			else if (_fillOrigin == FillOrigin::LeftBottom) {
				vertex = std::vector<cocos2d::Vec2>{ { 0.0f,0.0f },{ 1.0f,0.0f },{ 1.0f,1.0f },{ 0.0f,1.0f } };
			}
			else if (_fillOrigin == FillOrigin::LeftTop) {
				vertex = std::vector<cocos2d::Vec2>{ { 0.0f,1.0f },{ 0.0f,0.0f },{ 1.0f,0.0f },{ 1.0f,1.0f } };
			}
			else if (_fillOrigin == FillOrigin::RightBottom) {
				vertex = std::vector<cocos2d::Vec2>{ { 1.0f, 0.0f },{ 1.0f,1.0f },{ 0.0f,1.0f },{ 0.0f,0.0f } };
			}
			else if (_fillOrigin == FillOrigin::RightTop) {
				vertex = std::vector<cocos2d::Vec2>{ { 1.0f, 1.0f },{ 0.0f,1.0f },{ 0.0f,0.0f },{ 1.0f,0.0f } };
			}
		}
		else if (_fillMethod == FillMethod::Radial180) {
			angle = M_PI * (_fillClockwise ? (1 - _fillAmount) : _fillAmount);
			if (_fillOrigin == FillOrigin::Bottom) {
				vertex = std::vector<cocos2d::Vec2>{ { 1.0f,0.0f },{ 1.0f,1.0f },{ 0.0f,1.0f },{ 0.0f,0.0f } };
				origin = cocos2d::Vec2(0.5f, 0.0f);
			}
			else if (_fillOrigin == FillOrigin::Left) {
				vertex = std::vector<cocos2d::Vec2>{ { 0.0f,0.0f },{ 1.0f,0.0f },{ 1.0f,1.0f },{ 0.0f,1.0f } };
				origin = cocos2d::Vec2(0.0f, 0.5f);
			}
			else if (_fillOrigin == FillOrigin::Top) {
				vertex = std::vector<cocos2d::Vec2>{ { 0.0f,1.0f },{ 0.0f,0.0f },{ 1.0f,0.0f },{ 1.0f,1.0f } };
				origin = cocos2d::Vec2(0.5f, 1.0f);
			}
			else if (_fillOrigin == FillOrigin::Right) {
				vertex = std::vector<cocos2d::Vec2>{ { 1.0f,1.0f },{ 0.0f,1.0f },{ 0.0f,0.0f },{ 1.0f,0.0f } };
				origin = cocos2d::Vec2(1.0f, 0.5f);
			}
		}
		else if (_fillMethod == FillMethod::Radial90) {
			angle = M_PI / 2 * (_fillClockwise ? (1 - _fillAmount) : _fillAmount);
			if (_fillOrigin == FillOrigin::LeftBottom) {
				vertex = std::vector<cocos2d::Vec2>{ { 1.0f,0.0f },{ 1.0f,1.0f },{ 0.0f,1.0f },{0.0f,0.0f} };
				origin = cocos2d::Vec2(0.0f, 0.0f);
			}
			else if (_fillOrigin == FillOrigin::RightBottom) {
				vertex = std::vector<cocos2d::Vec2>{ { 1.0f,1.0f },{ 0.0f,1.0f },{ 0.0f,0.0f },{1.0f,0.0f} };
				origin = cocos2d::Vec2(1.0f, 0.0f);
			}
			else if (_fillOrigin == FillOrigin::RightTop) {
				vertex = std::vector<cocos2d::Vec2>{ { 0.0f,1.0f },{ 0.0f,0.0f },{ 1.0f,0.0f },{1.0f,1.0f} };
				origin = cocos2d::Vec2(1.0f, 1.0f);
			}
			else if (_fillOrigin == FillOrigin::LeftTop) {
				vertex = std::vector<cocos2d::Vec2>{ { 0.0f,0.0f },{ 1.0f,0.0f },{ 1.0f,1.0f },{0.0f,1.0f} };
				origin = cocos2d::Vec2(0.0f, 1.0f);
			}
		}
	}

	void GSprite::updateRadial() {
		std::vector<cocos2d::Vec2> vertex;
		cocos2d::Vec2 origin, curVer, nexVer;
		float angle = 0.0f , T, S;
		int count = 0;

		getFillVetextAndAOrigin(vertex, origin, angle);
		_vertexDataCount = 0;
		if (vertex.size() < 2) {
			return;
		}
		
		cocos2d::Vec2 tmp = vertex[0].rotateByAngle(origin, angle);
		cocos2d::Vec2 intersect;
		const static double precis = 10e-6;
		for (size_t i = 0; i < vertex.size(); ++i) {
			count++;
			if (!_fillClockwise) {
				curVer = vertex[i];
				nexVer = (i < vertex.size() - 1) ? vertex[i + 1] : vertex[0];
			}
			else {
				int curIndex = (vertex.size() - i) % vertex.size();
				curVer = vertex[curIndex];
				int nexIndex = (vertex.size() - i - 1) % vertex.size();
				nexVer = vertex[nexIndex];
			}

			if (cocos2d::Vec2::isLineIntersect(origin, tmp, curVer, nexVer, &T, &S)) {
				if (T > 0 && S > 0) {
					cocos2d::Vec2 t = origin + (tmp - origin) * T;
					if (t.x >= 0.0f && t.x <= 1.0f && t.y >= 0.0f && t.y <= 1.0f) {
						intersect = curVer + (nexVer - curVer) * S;
						break;
					}
				}
			}
		}

		auto c = getColor();
		cocos2d::Color4B color(c.r, c.g, c.b, getOpacity());

		if (_fillAmount <= 0.0f || _fillAmount >= 1.0f) {
			if (_fillAmount <= 0) {
				_vertexDataCount = 0;
				CC_SAFE_FREE(_vertexData);
				_vertexCapacity = 0;
			}
			else {
				_vertexDataCount = 4;
				if (_vertexCapacity < _vertexDataCount) {
					CC_SAFE_FREE(_vertexData);
					_vertexCapacity = _vertexDataCount * 2;
					_vertexData = (V2F_C4B_T2F*)malloc(sizeof(V2F_C4B_T2F)*(_vertexCapacity));
				}

				_vertexData[0].texCoords = textureCoordFromAlphaPoint(cocos2d::Vec2(0.0f,0.0f));
				_vertexData[0].vertices = vertexFromAlphaPoint(cocos2d::Vec2(0.0f,0.0f));
				_vertexData[0].colors = color;

				_vertexData[1].texCoords = textureCoordFromAlphaPoint(cocos2d::Vec2(1.0f, 0.0f));
				_vertexData[1].vertices = vertexFromAlphaPoint(cocos2d::Vec2(1.0f, 0.0f));
				_vertexData[1].colors = color;

				_vertexData[2].texCoords = textureCoordFromAlphaPoint(cocos2d::Vec2(1.0f, 1.0f));
				_vertexData[2].vertices = vertexFromAlphaPoint(cocos2d::Vec2(1.0f, 1.0f));
				_vertexData[2].colors = color;

				_vertexData[3].texCoords = textureCoordFromAlphaPoint(cocos2d::Vec2(0.0f, 1.0f));
				_vertexData[3].vertices = vertexFromAlphaPoint(cocos2d::Vec2(0.0f, 1.0f));
				_vertexData[3].colors = color;
			}
		}
		else {
			_vertexDataCount = count + 2;
			if (_vertexCapacity < _vertexDataCount) {
				CC_SAFE_FREE(_vertexData);
				_vertexCapacity = _vertexDataCount * 2;
				_vertexData = (V2F_C4B_T2F*)malloc(sizeof(V2F_C4B_T2F)*(_vertexCapacity));
			}
			_vertexData[0].texCoords = textureCoordFromAlphaPoint(origin);
			_vertexData[0].vertices = vertexFromAlphaPoint(origin);
			_vertexData[0].colors = color;
			for (int i = 0; i < count; ++i) {
				if (_fillClockwise) {
					int index = (vertex.size() - i) % vertex.size();
					cocos2d::Vec2& v = vertex[index];
					_vertexData[i + 1].texCoords = textureCoordFromAlphaPoint(v);
					_vertexData[i + 1].vertices = vertexFromAlphaPoint(v);
					_vertexData[i + 1].colors = color;
				}
				else
				{
					cocos2d::Vec2& v = vertex[i];
					_vertexData[i + 1].texCoords = textureCoordFromAlphaPoint(v);
					_vertexData[i + 1].vertices = vertexFromAlphaPoint(v);
					_vertexData[i + 1].colors = color;
				}
			}
			_vertexData[count + 1].texCoords = textureCoordFromAlphaPoint(intersect);
			_vertexData[count + 1].vertices = vertexFromAlphaPoint(intersect);
			_vertexData[count + 1].colors = color;
		}
	}

	///
	//    Update does the work of mapping the texture onto the triangles for the bar
	//    It now doesn't occur the cost of free/alloc data every update cycle.
	//    It also only changes the percentage point but no other points if they have not
	//    been modified.
	//    
	//    It now deals with flipped texture. If you run into this problem, just use the
	//    sprite property and enable the methods flipX, flipY.
	///
	void GSprite::updateBar(void)
	{
		Vec2 min, max;

		if (_fillMethod == FillMethod::Horizontal)
		{
			if (_fillOrigin == FillOrigin::Left || _fillOrigin == FillOrigin::Top)
			{
				min = Vec2(0, 0);
				max = Vec2(_fillAmount, 1);
			}
			else
			{
				min = Vec2(1 - _fillAmount, 0);
				max = Vec2(1, 1);
			}
		}
		else
		{
			if (_fillOrigin == FillOrigin::Left || _fillOrigin == FillOrigin::Top)
			{
				min = Vec2(0, 1 - _fillAmount);
				max = Vec2(1, 1);
			}
			else
			{
				min = Vec2(0, 0);
				max = Vec2(1, _fillAmount);
			}
		}
		_vertexDataCount = 4;

		if (_vertexCapacity < _vertexDataCount) {
			CC_SAFE_FREE(_vertexData);
			_vertexCapacity = _vertexDataCount * 2;
			_vertexData = (V2F_C4B_T2F*)malloc(_vertexCapacity * sizeof(V2F_C4B_T2F));
		}

		//    TOPLEFT
		_vertexData[0].texCoords = textureCoordFromAlphaPoint(Vec2(min.x, max.y));
		_vertexData[0].vertices = vertexFromAlphaPoint(Vec2(min.x, max.y));

		//    BOTLEFT
		_vertexData[1].texCoords = textureCoordFromAlphaPoint(Vec2(min.x, min.y));
		_vertexData[1].vertices = vertexFromAlphaPoint(Vec2(min.x, min.y));

		//    TOPRIGHT
		_vertexData[2].texCoords = textureCoordFromAlphaPoint(Vec2(max.x, max.y));
		_vertexData[2].vertices = vertexFromAlphaPoint(Vec2(max.x, max.y));

		//    BOTRIGHT
		_vertexData[3].texCoords = textureCoordFromAlphaPoint(Vec2(max.x, min.y));
		_vertexData[3].vertices = vertexFromAlphaPoint(Vec2(max.x, min.y));

		updateColor();
	}

	Vec2 GSprite::boundaryTexCoord(char index)
	{
		if (index < kProgressTextureCoordsCount) {
			if (!_fillClockwise) {
				return Vec2((kProgressTextureCoords >> (7 - (index << 1))) & 1, (kProgressTextureCoords >> (7 - ((index << 1) + 1))) & 1);
			}
			else {
				return Vec2((kProgressTextureCoords >> ((index << 1) + 1)) & 1, (kProgressTextureCoords >> (index << 1)) & 1);
			}
		}
		return Vec2::ZERO;
	}

	void GSprite::onDraw(const Mat4 &transform, uint32_t /*flags*/)
	{
		GLProgramState* glState = getGLProgramState();
		if (glState) {
			GLProgram* program = glState->getGLProgram();
			program->use();
			program->setUniformsForBuiltins(transform);
		}

		GL::blendFunc(getBlendFunc().src, getBlendFunc().dst);

		GL::enableVertexAttribs(GL::VERTEX_ATTRIB_FLAG_POS_COLOR_TEX);
		GL::bindTexture2D(getTexture());
		glVertexAttribPointer(GLProgram::VERTEX_ATTRIB_POSITION, 2, GL_FLOAT, GL_FALSE, sizeof(_vertexData[0]), &_vertexData[0].vertices);
		glVertexAttribPointer(GLProgram::VERTEX_ATTRIB_TEX_COORD, 2, GL_FLOAT, GL_FALSE, sizeof(_vertexData[0]), &_vertexData[0].texCoords);
		glVertexAttribPointer(GLProgram::VERTEX_ATTRIB_COLOR, 4, GL_UNSIGNED_BYTE, GL_TRUE, sizeof(_vertexData[0]), &_vertexData[0].colors);

		if (_fillMethod == FillMethod::Horizontal || _fillMethod == FillMethod::Vertical)
		{
			glDrawArrays(GL_TRIANGLE_STRIP, 0, _vertexDataCount);
			CC_INCREMENT_GL_DRAWN_BATCHES_AND_VERTICES(1, _vertexDataCount);
		}
		else
		{
			glDrawArrays(GL_TRIANGLE_FAN, 0, _vertexDataCount);
			CC_INCREMENT_GL_DRAWN_BATCHES_AND_VERTICES(1, _vertexDataCount);
		}
	}

	void GSprite::draw(cocos2d::Renderer * renderer, const cocos2d::Mat4 & transform, uint32_t flags)
	{
		if (_fillMethod == FillMethod::None)
			Sprite::draw(renderer, transform, flags);
		else
		{
			if (_bFillDirty) {
				if (_fillMethod != FillMethod::None)
					setupFill();
				else {
					CC_SAFE_FREE(_vertexData);
				}
				_bFillDirty = false;
			}
			_customCommand.init(_globalZOrder, transform, flags);
			_customCommand.func = CC_CALLBACK_0(GSprite::onDraw, this, transform, flags);
			renderer->addCommand(&_customCommand);
		}
	}

}