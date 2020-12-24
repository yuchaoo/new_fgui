#pragma once
#include "cocos2d.h"
#include "GObject.h"
#include "fgui/GContainer.h"

namespace fgui {
	class GObject;
	class GController;
	class GTransition;
	class PkgItem;

	class GComponent : 
		public cocos2d::Node, 
		public fgui::GObject
	{
	public:
		CREATE_FUNC(GComponent);
		virtual bool init();
		virtual void onEnter();
		virtual void onEixt();
		virtual void onEnterTransitionDidFinish() override;
		virtual void onExitTransitionDidStart() override;

		GController* getController(const std::string& name);
		GController* getControllerAt(int index);
		bool isConstructing() const { return m_constructing; }
		virtual void setContentSize(const cocos2d::Size& size);
		virtual void setPosition(const cocos2d::Vec2& pos);
		virtual void setPosition(float x, float y);

		cocos2d::Node* getChildById(const std::string& name);
		cocos2d::Rect getEdgeRectangle();

		cocos2d::Node* getStencil();
		void setStencil(cocos2d::Node* node);
		GLfloat getAlphaThreshold() const;
		void setAlphaThreshold(GLfloat alphaThreshold);
		bool isStencilInverted() const;
		void setStencilInverted(bool inverted);
		void setCameraMask(unsigned short mask, bool applyChildren = true);
		void setHitArea(IHitTest* value);

		GTransition* getTransition(const std::string& name);
		void onTransionPositionChanged(cocos2d::Node* node, float dx, float dy);

		virtual void setGrayed(bool value);
		virtual void setBlendMode(BlendMode blendMode);
		virtual void applyController(GController* controller);
		virtual void applyAllControllers();
		virtual void setHSVMode(bool isHsv);
		virtual void setHSVValue(float hue, float saturation, float brightness, float contrast);
	protected:
		GComponent();
		~GComponent();

		virtual void setupScroll(ByteBuffer* buffer);
		virtual void setupOverflow(OverflowType overflow);
		virtual void constructFromResource(UIPackage* pkg, PackageItem* pt);
		virtual void setup(const ObjectInfo* info, cocos2d::Node* parent);

		virtual void setupBefore(ByteBuffer* buffer, int pos, cocos2d::Node* parent);
		virtual void setupAfter(ByteBuffer* buffer, int pos);
		virtual void setupExtend(ByteBuffer* buffer);
		virtual void visit(cocos2d::Renderer* renderer, const cocos2d::Mat4& parentTransform, uint32_t parentFlags) override;
		
		void onBeforeVisitScissor();
		void onAfterVisitScissor();
		void updateClippingRect();

		virtual bool onTouchBegin(cocos2d::Touch* touch, cocos2d::Event* event);
		virtual void onTouchMoved(cocos2d::Touch* touch, cocos2d::Event* event);
		virtual void onTouchEnded(cocos2d::Touch* touch, cocos2d::Event* event);
		bool checkTouchStencilClippingRegion(GComponent* comp,cocos2d::Touch* touch);
	protected:
		std::vector<GController*> m_controllers;
		GController* m_applyingController;
		bool m_constructing;
		OverflowType _overflowType;
		ScrollType _scrollType;
		bool _isInertiaEnabled;
		bool _bouncebackEffect;
		bool _isPageMode;
		Margin _margin;

		cocos2d::Rect _clippingRect;
		cocos2d::Rect _initEdgeRect;
		cocos2d::Node* _stencil;
		GLfloat _alphaThreshold;
		bool _isInverted;
		bool _scissorOldState;
		cocos2d::Rect _scissorOldRect;
		cocos2d::GLProgram* _stencilOldProgram;
		cocos2d::GroupCommand* _groupCommand;
		cocos2d::CustomCommand* _beforeVisitCmd;
		cocos2d::CustomCommand* _afterDrawStencilCmd;
		cocos2d::CustomCommand* _afterVisitCmd;
		cocos2d::CustomCommand* _beforeVisitCmdScissor;
		cocos2d::CustomCommand* _afterVisitCmdScissor;
		cocos2d::StencilStateManager* _stencilStateManager;
		IHitTest* _hitTest;
		std::vector<GTransition*> _transitions;
		
		friend class Relations;
	};
}