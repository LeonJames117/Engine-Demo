#pragma once
class Rectangle
{
public:
	
	int TopFace{ 0 }, BottomFace{ 0 }, RightFace{ 0 }, LeftFace{ 0 };
	Rectangle() = default;
	Rectangle(int Top, int Bottom, int Right, int Left) :
		TopFace(Top), BottomFace(Bottom), RightFace(Right), LeftFace(Left) {};
	
	int GetWidth() const { return RightFace - LeftFace ; }
	int GetHeight() const { return BottomFace - TopFace; }

	void Translate(int X, int Y)
	{
		TopFace += Y;
		BottomFace += Y;
		RightFace += X;
		LeftFace += X;
	}

	void ClipToOtherRect(const Rectangle& otherRect)
	{
		if (LeftFace < otherRect.LeftFace)
			LeftFace = otherRect.LeftFace;

		if (RightFace > otherRect.RightFace)
			RightFace = otherRect.RightFace;

		if (TopFace < otherRect.TopFace)
			TopFace = otherRect.TopFace;

		if (BottomFace > otherRect.BottomFace)
			BottomFace = otherRect.BottomFace;
	}

	
};

