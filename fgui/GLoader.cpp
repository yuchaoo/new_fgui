#include "GLoader.h"
#include "GComponent.h"
#include "ByteBuffer.h"
#include "GSprite.h"
#include "PackageManager.h"
#include "GAnimation.h"
#include "ComponentData.h"

namespace fgui {
	USING_NS_CC;

	GLoader::GLoader()
	:_sprite(NULL)
	,_urlItem(NULL)
	,_component(NULL)
	,_align(TextHAlignment::CENTER)
	,_verticalAlign(TextVAlignment::CENTER)
	, _fillMethod(FillMethod::None)
	, _fillOrigin(FillOrigin::Left)
	, _isFillClockwise(false)
	, _fillAmount(0.0f)
	, _shrinkOnly(false)
	, _autoSize(false)
	, _playing(false)
	, _frame(0)
	, _fill(LoaderFillType::NONE)
	, _bLayoutDirty(false)
	, _animation(NULL){

	}
	GLoader::~GLoader() {

	}

	void GLoader::onEnter() {
		Node::onEnter();
		GObject::onEnter();
	}

	void GLoader::onExit() {
		Node::onExit();
		GObject::onExit();
	}

	void GLoader::setURL(const std::string& value) {
		if (_url.compare(value) == 0) {
			return;
		}
		_url = value;
		loadContent();
	}

	void GLoader::loadContent() {
		if (_url.length() == 0) {
			return;
		}
		if (_url.compare(0, 5, "ui://") == 0) {
			loadFromPackage();
		}
		else {
			loadExternal();
		}
	}

	void GLoader::clearLayout() {
		if (_sprite) {
			_sprite->removeFromParent();
			_sprite = NULL;
		}
		if (_animation) {
			_animation->removeFromParent();
			_animation = NULL;
		}
		if (_component) {
			_component->removeFromParent();
			_component = NULL;
		}
	}

	void GLoader::loadFromPackage() {
		auto mgr = PackageManager::getInstance();
		cocos2d::Node* node = mgr->createNodeByUrl(_url);
		if (!node) {
			CCLOG("load content failed,%s",_url.c_str());
			return;
		}

		clearLayout();

		GSprite* sprite = dynamic_cast<GSprite*>(node);
		if (sprite) {
			if (_isHsvMode) {
				sprite->setHSVMode(_isHsvMode);
				sprite->setHSVValue(_hsvValue.x, _hsvValue.y, _hsvValue.z, _hsvValue.w);
			}
			if (_isGray) {
				sprite->setGrayed(true);
			}
			if (m_blendMode != BlendMode::NORMAL) {
				sprite->setBlendMode(m_blendMode);
			}
			_contentSourceSize = sprite->getContentSize();
			_sprite = sprite;
			addChild(_sprite);
		}

		GAnimation* animation = dynamic_cast<GAnimation*>(node);
		if (animation) {
			animation->setIsPlaying(true);
			if (_isHsvMode) {
				animation->setHSVMode(_isHsvMode);
				animation->setHSVValue(_hsvValue.x, _hsvValue.y, _hsvValue.z, _hsvValue.w);
			}
			if (_isGray) {
				animation->setGrayed(_isGray);
			}
			if (m_blendMode != BlendMode::NORMAL) {
				animation->setBlendMode(m_blendMode);
			}
			_contentSourceSize = animation->getContentSize();
			_animation = animation;
			addChild(_animation);
		}
		
		GComponent* comp = dynamic_cast<GComponent*>(node);

		if (comp) {
			if (_isHsvMode) {
				comp->setHSVMode(_isHsvMode);
				comp->setHSVValue(_hsvValue.x, _hsvValue.y, _hsvValue.z, _hsvValue.w);
			}
			if (_isGray) {
				comp->setGrayed(true);
			}
			if (m_blendMode != BlendMode::NORMAL) {
				comp->setBlendMode(m_blendMode);
			}
			_contentSourceSize = comp->getContentSize();
			_component = comp;
			addChild(_component);
		}
		updateLayout();
	}

	void GLoader::loadExternal() {
		auto tex = Director::getInstance()->getTextureCache()->addImage(_url);
		if (tex) {
			const cocos2d::Size& size = tex->getContentSizeInPixels();
			if (_sprite) {
				_sprite->setTexture(tex);
				_sprite->setTextureRect(cocos2d::Rect(0,0,size.width,size.height), false, size);
			}
			else {
				_sprite = GSprite::createWithTexture(tex, cocos2d::Rect(0, 0, size.width, size.height));
				addChild(_sprite);
				if (_isHsvMode) {
					_sprite->setHSVMode(_isHsvMode);
					_sprite->setHSVValue(_hsvValue.x, _hsvValue.y, _hsvValue.z, _hsvValue.w);
				}
				if (_isGray) {
					_sprite->setGrayed(true);
				}
				if (m_blendMode != BlendMode::NORMAL) {
					_sprite->setBlendMode(m_blendMode);
				}
			}
			_contentSourceSize = tex->getContentSize();
			updateLayout();
		}
	}

	void GLoader::updateLayout() {
		if (!_sprite && !_animation && !_component) {
			return;
		}
		cocos2d::Size size = _contentSourceSize;
		float sx = 1.0f, sy = 1.0f, nx = 0, ny = 0;
		const cocos2d::Size& size1 = this->getContentSize();

		if (_fill != LoaderFillType::NONE) {
			sx = size1.width / _contentSourceSize.width;
			sy = size1.height / _contentSourceSize.height;
			if (sx != 1 || sy != 1) {
				if (_fill == LoaderFillType::SCALE_MATCH_HEIGHT) {
					sx = sy;
				}
				else if (_fill == LoaderFillType::SCALE_MATCH_WIDTH) {
					sy = sx;
				}
				else if (_fill == LoaderFillType::SCALE) {
					sy = sx = std::min(sy, sx);
				}
				else if (_fill == LoaderFillType::SCALE_NO_BORDER) {
					sy = sx = std::max(sx, sy);
				}
				if(_shrinkOnly) {
					sx = std::min(sx, 1.0f);
					sy = std::min(sy, 1.0f);
				}
				size.width = std::floor(_contentSourceSize.width * sx);
				size.height = std::floor(_contentSourceSize.height * sy);
			}
		}

		if (_sprite) {
			_sprite->setContentSize(size);
			const cocos2d::Vec2& ap = _sprite->getAnchorPoint();
			if (_align == TextHAlignment::CENTER) {
				nx = size1.width / 2 + (ap.x - 0.5f) * size.width;
			}
			else if (_align == TextHAlignment::RIGHT) {
				nx = size1.width + (ap.x - 1.0f) * size.width;
			}
			else {
				nx = size.width * ap.x;
			}
			if (_verticalAlign == TextVAlignment::CENTER) {
				ny = size1.height / 2 + (ap.y - 0.5f) * size.height;
			}
			else if (_verticalAlign == TextVAlignment::TOP) {
				ny = size1.height + (ap.y - 1.0f) * size.height;
			}
			else {
				ny = size.height * ap.y;
			}
			_sprite->setPosition(nx, ny);
		}
		if (_component) {
			_component->setScale(sx,sy);
			const cocos2d::Vec2& ap = _component->getAnchorPoint();
			if (_align == TextHAlignment::CENTER) {
				nx = size1.width / 2 + (ap.x - 0.5f) * size.width;
			}
			else if (_align == TextHAlignment::RIGHT) {
				nx = size1.width + (ap.x - 1.0f) * size.width;
			}
			else {
				nx = ap.x * size.width;
			}
			if (_verticalAlign == TextVAlignment::CENTER) {
				ny = size1.height / 2 + (ap.y - 0.5f) * size.height;
			}
			else if (_verticalAlign == TextVAlignment::TOP) {
				ny = size1.height + (ap.y - 1.0f) * size.height;
			}
			else {
				ny = ap.y * size.height;
			}
			_component->setPosition(nx,ny);
		}
		if (_animation) {
			_animation->setScale(sx, sy);
			const cocos2d::Vec2& ap = _animation->getAnchorPoint();
			if (_align == TextHAlignment::CENTER) {
				nx = size1.width / 2 + (ap.x - 0.5f) * size.width;
			}
			else if (_align == TextHAlignment::RIGHT) {
				nx = size1.width + (ap.x - 1.0f) * size.width;
			}
			else {
				nx = ap.x * size.width;
			}
			if (_verticalAlign == TextVAlignment::CENTER) {
				ny = size1.height / 2 + (ap.y - 0.5f) * size.height;
			}
			else if (_verticalAlign == TextVAlignment::TOP) {
				ny = size1.height + (ap.y - 1.0f) * size.height;
			}
			else {
				ny = ap.y * size.height;
			}
			_animation->setPosition(nx, ny);
		}
	}

	void GLoader::setColor(const cocos2d::Color3B & value)
	{
		if (_sprite) {
			_sprite->setColor(value);
		}
		if (_component) {
			_component->setColor(value);
		}
		if (_animation) {
			_animation->setColor(value);
		}
	}

	FillMethod GLoader::getFillMethod() const {
		if (_sprite) {
			return _sprite->getFillMethod();
		}
		return FillMethod::None;
	}

	void GLoader::setFillMethod(FillMethod value) {
		if (_sprite) {
			_sprite->setFillMethod(value);
		}
	}

	FillOrigin GLoader::getFillOrigin() const {
		if (_sprite) {
			return _sprite->getFillOrigin();
		}
		return FillOrigin::Left;
	}
	void GLoader::setFillOrigin(FillOrigin value) {
		if (_sprite) {
			_sprite->setFillOrigin(value);
		}
	}

	bool GLoader::isFillClockwise() const {
		if (_sprite) {
			return _sprite->isFillClockwise();
		}
		return false;
	}
	void GLoader::setFillClockwise(bool value) {
		if (_sprite) {
			_sprite->setFillClockwise(value);
		}
	}

	float GLoader::getFillAmount() const {
		if (_sprite) {
			_sprite->getFillAmount();
		}
		return 0;
	}
	void GLoader::setFillAmount(float value) {
		if (_sprite) {
			_sprite->setFillAmount(value);
		}
	}

	void GLoader::setAlign(cocos2d::TextHAlignment hAlign, cocos2d::TextVAlignment vAlign) {
		_align = hAlign;
		_verticalAlign = vAlign;
		updateLayout();
	}

	void GLoader::setLoadFillType(LoaderFillType type) {
		_fill = type;
		updateLayout();
	}

	void GLoader::setLayout(LoaderFillType type, cocos2d::TextHAlignment hAlign, cocos2d::TextVAlignment vAlign) {
		_fill = type;
		_align = hAlign;
		_verticalAlign = vAlign;
		updateLayout();
	}

	const cocos2d::Size& GLoader::getOriginContentSize() {
		return _contentSourceSize;
	}

	cocos2d::Node* GLoader::getContent() {
		if (_sprite) {
			return _sprite;
		}
		if (_component) {
			return _component;
		}
		if (_animation) {
			return _animation;
		}
		return NULL;
	}

	void GLoader::setContentSize(const cocos2d::Size& size) {
		cocos2d::Size oldSize = getContentSize();
		if (oldSize.equals(size)) {
			return;
		}
		Node::setContentSize(size);
		updateLayout();
		onContentSizeChanged(this, oldSize, size);
	}

	void GLoader::setPosition(float x, float y) {
		cocos2d::Vec2 oldPos = getPosition();
		cocos2d::Vec2 pos(x, y);
		if (oldPos.equals(pos)) {
			return;
		}
		Node::setPosition(x,y);
		onPositionChanged(this, oldPos, pos);
	}

	void GLoader::setBlendMode(BlendMode blendMode) {
		if (_sprite) {
			_sprite->setBlendMode(blendMode);
		}
		if (_component) {
			_component->setBlendMode(blendMode);
		}
		if (_animation) {
			_animation->setBlendMode(blendMode);
		}
	}

	void GLoader::setGrayed(bool value) {
		GObject::setGrayed(value);
		if (_sprite) {
			_sprite->setGrayed(value);
		}
		if (_component) {
			_component->setGrayed(value);
		}
		if (_animation) {
			_animation->setGrayed(value);
		}
	}

	void GLoader::setHSVMode(bool isHsv) {
		GObject::setHSVMode(isHsv);
		if (_sprite) {
			_sprite->setHSVMode(isHsv);
		}
		if (_component) {
			_component->setHSVMode(isHsv);
		}
		if (_animation) {
			_animation->setHSVMode(isHsv);
		}
	}

	void GLoader::setHSVValue(float hue, float saturation, float brightness, float contrast) {
		GObject::setHSVValue(hue, saturation, brightness, contrast);
		if (_sprite) {
			_sprite->setHSVValue(hue,saturation,brightness,contrast);
		}
		if (_component) {
			_component->setHSVValue(hue, saturation, brightness, contrast);
		}
		if (_animation) {
			_animation->setHSVValue(hue, saturation, brightness, contrast);
		}
	}

	void GLoader::setup(const ObjectInfo* inf, cocos2d::Node* parent) {
		GObject::setup(inf, parent);
		const LoaderInfo* info = dynamic_cast<const LoaderInfo*>(inf);
		_url = info->url;
		_align = info->hAlign;
		_verticalAlign = info->vAlign;
		_fill = info->fillType;
		_shrinkOnly = info->bShrinkOnly;
		_autoSize = info->bAutoSize;
		_playing = info->bPlaying;
		_frame = info->frame;
		_fillMethod = info->fillMethod;
		_fillOrigin = info->fillOrign;
		_isFillClockwise = info->bFillClockwise;
		_fillAmount = info->fillAmount;

		if (info->color) {
			setColor((cocos2d::Color3B) * info->color);
		}
		if (info->size) {
			_contentSourceSize = *info->size;
		}

		loadContent();

		if (_sprite) {
			_sprite->setFillMethod(_fillMethod);
			_sprite->setFillOrigin(_fillOrigin);
			_sprite->setFillClockwise(_isFillClockwise);
			_sprite->setFillAmount(_fillAmount);
		}
		if (_component) {
			if (isCascadeOpacityEnabled()) {
				_component->setCascadeOpacityEnabled(true);
			}
		}

		if (info->opacity != 1) {
			setOpacity(info->opacity * 255);
		}

		if (info->blendMode != BlendMode::NORMAL) {
			setBlendMode(info->blendMode);
		}
		if (info->bGray) {
			setGrayed(info->bGray);
		}
		if (info->hsv) {
			setHSVMode(true);
			setHSVValue(info->hsv->x, info->hsv->y, info->hsv->z, info->hsv->w);
		}
	}

	cocos2d::Node* GLoader::hitTest(const Vec2 &worldPoint, const Camera* camera) {
		/*if (!this->isRunning())
			return nullptr;

		if (_sprite != nullptr){
			GObject* obj = _sprite->hitTest(worldPoint, camera);
			if (obj != nullptr)
				return obj;
		}

		Rect rect;
		rect.size = _size;
		if (rect.containsPoint(_displayObject->convertToNodeSpace(worldPoint)))
			return this;
		else
			return nullptr;*/
		return NULL;
	}

}