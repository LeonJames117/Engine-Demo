#pragma once
#include <HAPI_lib.h>
#include "Rectangle.h"

using namespace HAPISPACE;
class Sprite
{
public:
	bool LoadSprite(std::string TextureFilepath);
	void BlitClip(BYTE* Screen, int TexturePosX, int TexturePosY, int Height, int Width);
	void BlitBackground(BYTE* Screen, int TexturePosX, int TexturePosY, int Height, int Width);
	Rectangle GetRectangle();
	~Sprite() 
	{
		delete[] Texture;
	}
	
private:
	BYTE* Texture{ nullptr };
	Rectangle ColisonRect;
	int TextureWidth{ 0 };
	int TextureHeight{ 0 };
	int PosX;
	int PosY;
};

