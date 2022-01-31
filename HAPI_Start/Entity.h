#pragma once
#include "Graphics.h"
#include <HAPI_lib.h>
class World;
enum class Side
{
	Player,
	Enemy,
	Neutral
};

enum class Type
{
	Player,
	Bandit,
	Arrow
};

enum class Facing
{
	Up,
	Down,
	Left,
	Right
};

class Entity
{

public:

	virtual void Update(Graphics& Vis,World& world) = 0;
	virtual void Kill(World& world) = 0;
	//Gets

	//Enums
	virtual Side GetSide() const = 0;
	virtual Type GetType() const = 0;
	virtual Facing GetFacing()const = 0;
	//Variables
	virtual int GetPosX()const = 0;
	virtual int GetPosY()const = 0;
	virtual std::string GetCurrentSprite() const = 0;
	//Gameplay
	virtual int GetHealth() const = 0;
	virtual bool GetIsAlive()const = 0;
	//Sets
	virtual void SetFacing(Facing Value) = 0;
	virtual void SetPosX(int Value) = 0;
	virtual void SetPosY(int Value) = 0;
	virtual void SetSide(Side Value) = 0;
	virtual void SetHealth(int Value) = 0;
	virtual void SetIsAlive(bool Value) = 0;
	virtual void SetTravelTime(int Value) = 0;

private:
	int PosX = 0;
	int PosY = 0;
protected:

};

