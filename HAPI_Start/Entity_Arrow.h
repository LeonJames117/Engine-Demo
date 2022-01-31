#pragma once
#include "Entity.h"
class Entity_Arrow :public Entity
{
public:
	int PosX = 0, PosY = 0;
	bool IsAlive = 0;
	

	void Update(Graphics& Vis, World& world);
	void Render(Graphics& Vis);
	void Kill(World& world)override;
	//Gets
		//Enums
		Side GetSide() const override { return Ent_Side; }
		Type GetType() const override { return Type::Arrow; }
		Facing GetFacing() const override { return Ent_Facing; }
		//Variables
		std::string GetCurrentSprite() const override { return CurrentSprite; }
		virtual int GetPosX() const override { return PosX; };
		virtual int GetPosY() const override { return PosY; };
		//Gameplay
		bool GetIsAlive() const override { return IsAlive; };
		int GetHealth() const override { return Health; }
	

	//Sets	
	void SetHealth(int Value)override;
	void SetFacing(Facing Value)override;
	void SetSide(Side Value)override;
	void SetPosX(int Value)override;
	void SetPosY(int Value)override;
	void SetIsAlive(bool Value)override;
	void SetTravelTime(int Value)override;
	

	void ShootArrow(Entity* Caster);
	void ArrowColision(Entity* Victim);

private:
	Facing Ent_Facing = Facing::Right;
	bool ArrowHit = false;
	Side Ent_Side;
	std::string CurrentSprite = "Arrow";
	int Health = 1;
	int TravelTime = 0;
};

