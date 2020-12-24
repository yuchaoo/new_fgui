#include "HitTest.h"
#include "GObject.h"
#include "ByteBuffer.h"


namespace fgui {

	PixelHitTestData::PixelHitTestData() :
		pixels(nullptr),
		pixelsLength(0),
		pixelWidth(0),
		scale(1)
	{
	}

	PixelHitTestData::~PixelHitTestData()
	{
		CC_SAFE_DELETE(pixels);
	}

	void PixelHitTestData::load(ByteBuffer* buffer)
	{
		buffer->Skip(4);
		pixelWidth = buffer->ReadInt();
		scale = 1.0f / buffer->ReadByte();
		pixelsLength = buffer->ReadInt();
		pixels = new unsigned char[pixelsLength];
		for (size_t i = 0; i < pixelsLength; i++)
			pixels[i] = buffer->ReadByte();
	}

	PixelHitTest::PixelHitTest(PixelHitTestData * data, int offsetX, int offsetY) :
		offsetX(offsetX),
		offsetY(offsetY),
		scaleX(1),
		scaleY(1),
		_data(data)
	{
	}

	bool PixelHitTest::hitTest(cocos2d::Node* node, const cocos2d::Vec2& localPoint)
	{
		float f1 = localPoint.x / node->getScaleX() - offsetX;
		float f2 = localPoint.y / node->getScaleY() - offsetY;
		int x = floor(f1 * _data->scale);
		int y = floor(f2 * _data->scale);
		if (x < 0 || y < 0 || x >= _data->pixelWidth) {
			return false;
		}
		int index = y * _data->pixelWidth + x;
		size_t index1 = index / 8;
		size_t index2 = index % 8;
		if (index1 >= 0 && index1 < _data->pixelsLength) {
			return ((_data->pixels[index1] >> index2) & 0x01) > 0;
		}
		return false;
	}
}
