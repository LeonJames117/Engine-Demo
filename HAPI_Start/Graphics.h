#pragma once
#include <HAPI_lib.h>
#include "Rectangle.h"
#include <unordered_map>
using namespace HAPISPACE;
class Sprite;

class Graphics {

public:
	bool ScreenSetup();
	void SettoColour();
	bool GetSprite(const std::string& SpriteName, const std::string& Filepath);
	void SpriteGraphics(const std::string& SpriteName, int Xpos, int Ypos);
	void BackgroundGraphics(const std::string& SpriteName, int Xpos, int Ypos);
	std::unordered_map < std::string, std::shared_ptr <Sprite> > GetSpiteMap();
	Rectangle GetRectangle(std::string SpriteName);
private:

	int width{ 1024 };
	int height{ 768 };
	BYTE* Screen = nullptr;
	std::unordered_map<std::string, std::shared_ptr <Sprite> > SpriteList;

};





