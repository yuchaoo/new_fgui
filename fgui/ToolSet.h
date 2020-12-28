#pragma once
#include "base/ccTypes.h"

namespace fgui {
	class ToolSet
	{
	public:
		static cocos2d::Color4B convertFromHtmlColor(const char* str);
		static cocos2d::Rect intersection(const cocos2d::Rect& rect1, const cocos2d::Rect& rect2);
		static int findInStringArray(const std::vector<std::string>& arr, const std::string& str);
	};

	class FastSplitter
	{
	public:
		FastSplitter();
		void start(const char* data, size_t dataLength, char delimiter);
		bool next();
		const char* getText();
		int getTextLength();
		void getKeyValuePair(char* keyBuf, size_t keyBufSize, char* valueBuf, size_t valueBufSize);

	private:
		const char* data;
		int dataLength;
		int textLength;
		char delimiter;
	};
}


