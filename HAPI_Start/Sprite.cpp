#include "Sprite.h"

bool Sprite::LoadSprite(std::string TextureFilepath)
{
	if (!HAPI.LoadTexture(TextureFilepath, &Texture, TextureWidth, TextureHeight))
	{
		HAPI.UserMessage("LOADING TEXTURE: " + TextureFilepath,"ERROR");
		return false;
	}
	return true;
}



void Sprite::BlitClip(BYTE* Screen, int TexturePosX, int TexturePosY, int Height, int Width)
{
	Rectangle ScreenRect(0, Height, Width, 0);
	Rectangle TextureRect(0, TextureHeight, TextureWidth, 0);
	//Clipping
	Rectangle ClippedRect(TextureRect);
	ClippedRect.Translate(TexturePosX, TexturePosY);
	ClippedRect.ClipToOtherRect(ScreenRect);
	ClippedRect.Translate(-TexturePosX, -TexturePosY);
	if (TexturePosX < 0)
		TexturePosX = 0;
	if (TexturePosY < 0)
		TexturePosY = 0;

	BYTE* tempTexture{ Texture + (ClippedRect.LeftFace + ClippedRect.TopFace * (size_t)TextureRect.GetWidth()) * 4 };
	BYTE* tempScreen{ Screen + (TexturePosX + TexturePosY * size_t(ScreenRect.GetWidth())) * 4 };
	int TestHeight = ClippedRect.GetHeight();
	int TestWidth = ClippedRect.GetWidth();
	int ScreenOffset = (ScreenRect.GetWidth() - ClippedRect.GetWidth()) * 4;
	int EndofLineOffset = (TextureRect.GetWidth() - ClippedRect.GetWidth()) * 4;
	for (int i = 0; i < ClippedRect.GetHeight(); i++)
	{
		for (int x = 0; x < ClippedRect.GetWidth(); x++)
		{
			BYTE AlphaChannel = tempTexture[3];
			if (AlphaChannel != 0)
			{
				if (AlphaChannel == 255)
				{
					memcpy(tempScreen, tempTexture, 4);
				}
				else
				{
					float Alpha = AlphaChannel / 255.f;

					tempScreen[0] = Alpha * tempTexture[0] + (1.0f - Alpha) * tempScreen[0];
					tempScreen[1] = Alpha * tempTexture[1] + (1.0f - Alpha) * tempScreen[1];
					tempScreen[2] = Alpha * tempTexture[2] + (1.0f - Alpha) * tempScreen[2];
				}
			}
			tempTexture += 4;
			tempScreen += 4;
		}
		tempScreen += ScreenOffset;
		tempTexture += EndofLineOffset;
	}
}

void Sprite::BlitBackground(BYTE* Screen, int TexturePosX, int TexturePosY, int Height, int width)
{
	BYTE* tempTexture{ Texture };
	BYTE* tempScreen{ Screen + (TexturePosX + TexturePosY * size_t(width) * 4) };
	int ScreenOffset = (width - TextureWidth) * 4;
	for (int i = 1; i < TextureHeight; i++)
	{
		for (int i = 0; i < TextureWidth; i++)
		{
			memcpy(Screen, Texture, 4);
			tempTexture += 4;
			tempScreen += 4;
		}
		tempScreen += ScreenOffset;
	}
}

Rectangle Sprite::GetRectangle()
{
	//std::string PathCheck = SpritePath;
	Rectangle ColisonRectangle(0, TextureHeight, TextureWidth, 0);

	
	return Rectangle(ColisonRectangle);
}





