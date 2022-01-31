#include "Graphics.h"
#include "Sprite.h"
bool Graphics::ScreenSetup()
{
	if (!HAPI.Initialise(width, height))
		return false;
	Screen = HAPI.GetScreenPointer();
	HAPI.SetShowFPS(true);
	return true;
}
void Graphics::SettoColour()
{
	HAPI_TColour col(150, 150, 150);
	size_t Offset = (0 + 0 * (size_t) width) * 4;
	BYTE* PixlePoint = Screen + Offset;

	for (size_t i = 0; i < height; i++)
	{
		for (size_t x = 0; x < width; x++)
		{
			memcpy(PixlePoint, &col, 4);
			PixlePoint += 4;
		}
	}
}


bool Graphics::GetSprite(const std::string& SpriteName, const std::string& Filepath)
{
	std::shared_ptr<Sprite> NewSprite = std::make_shared <Sprite>();
	if (!NewSprite->LoadSprite(Filepath))
	{
		HAPI.UserMessage("ERROR", "LOADING TEXTURE");
		return false;
	}
	else
	{
		SpriteList[SpriteName] = NewSprite;
		return true;
	}
}

void Graphics::SpriteGraphics(const std::string& SpriteName, int Xpos, int Ypos)
{
	if (SpriteList.find(SpriteName) == SpriteList.end())
	{
		HAPI.UserMessage("ERROR", "LOADING TEXTURE");
		return;
	}
	SpriteList[SpriteName]->BlitClip(Screen, Xpos, Ypos, height, width);
}

void Graphics::BackgroundGraphics(const std::string& SpriteName, int Xpos, int Ypos)
{
	if (SpriteList.find(SpriteName) == SpriteList.end())
	{
		HAPI.UserMessage("ERROR", "LOADING TEXTURE");
		return;
	}
	SpriteList[SpriteName]->BlitBackground(Screen, Xpos, Ypos, height, width);
}

std::unordered_map<std::string, std::shared_ptr<Sprite>> Graphics::GetSpiteMap()
{
	return SpriteList;
}

Rectangle Graphics::GetRectangle(std::string SpriteName)
{
	Rectangle ColisonRect = SpriteList[SpriteName]->GetRectangle();
	return ColisonRect;
}





		


