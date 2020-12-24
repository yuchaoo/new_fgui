#pragma once

#include "GObject.h"

namespace fgui {
	class ByteBuffer;

	class IHitTest
	{
	public:
		virtual bool hitTest(cocos2d::Node* node, const cocos2d::Vec2& localPoint)
		{
			return true;
		}
	};

	class PixelHitTestData
	{
	public:
		int pixelWidth;
		float scale;
		unsigned char* pixels;
		size_t pixelsLength;

		PixelHitTestData();
		~PixelHitTestData();

		void load(ByteBuffer* buffer);
	};

	class PixelHitTest : public IHitTest, public cocos2d::Ref
	{
	public:
		PixelHitTest(PixelHitTestData* data, int offsetX, int offsetY);

		virtual bool hitTest(cocos2d::Node* node, const cocos2d::Vec2& localPoint);

		int offsetX;
		int offsetY;
		float scaleX;
		float scaleY;

	private:
		PixelHitTestData* _data;
	};

}

