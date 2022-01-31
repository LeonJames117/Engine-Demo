#pragma once
#include"Entity.h"
#include "Entity_Arrow.h"
#include <HAPI_lib.h>
using namespace HAPISPACE;
class Graphics;
class Entity_Enemy;
class Entity_Player : public Entity
{
public:
	int PosX = 300;
	int PosY = 300;
	bool IsAlive;
	void ControlsUpdate();
	void Update(Graphics& Vis, World& world)override;
	void Render(Graphics &Vis);
	void Kill(World& world)override;

	Side GetSide() const override { return Side::Player; }
	Type GetType() const override { return Type::Player; }
	bool GetIsAlive() const override { return IsAlive; };
	virtual int GetPosX() const override { return PosX; };
	virtual int GetPosY() const override { return PosY; };
	std::string GetCurrentSprite() const override { return CurrentSprite; }
	int GetHealth() const override { return Health; }
	Facing GetFacing() const override { return Ent_Facing; }

	// Sets
	void SetFacing(Facing Value)override;
	void SetPosX(int Value)override;
	void SetPosY(int Value)override;
	void SetSide(Side Value)override;
	void SetHealth(int Value)override;
	void SetIsAlive(bool Value)override;
	void SetTravelTime(int Value)override;
	bool GetAttackStatus();

private:
	int Player_Attack_Power = 10;
	int Health = 50;
	HAPI_TKeyboardData KeyData;
	HAPI_TControllerData ControllerData;
	float NormalSpeed = 3.f;
	float DiagnalSpeed = NormalSpeed / 2.f;
	int ContPosX = PosX;
	int ContPosY = PosY;
	int AnimationCount=0;
	Facing Ent_Facing = Facing::Right;
	Side Ent_Side = Side::Player;
	bool Idle=true;
	bool Attacking=false;
	int ShootCooldown = 200;
	std::string CurrentSprite = "Player_Idle_Left_0";
	
};

