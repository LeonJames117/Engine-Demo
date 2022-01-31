#pragma once
#include "Entity.h"
class Entity_Enemy : public Entity
{
public:
	int PosX = 0,PosY = 0;
	bool IsAlive = 0;
	Entity_Enemy() = default;
	Entity_Enemy(int InputPosX, int InputPosY, bool InputIsAlive) :
		PosX(InputPosX), PosY(InputPosY), IsAlive(InputIsAlive) {};

	void Render(Graphics &Vis);
	void Update(Graphics& Vis, World& world)override;
	void Kill(World& world)override;

	Side GetSide() const override { return Side::Enemy; };
	Type GetType() const override { return Type::Bandit; };
	bool GetIsAlive() const override { return IsAlive; };

	std::string GetCurrentSprite() const override { return CurrentSprite; }
	int GetHealth() const override { return Health; }
	Facing GetFacing() const override { return Ent_Facing; }
	virtual int GetPosX() const override { return PosX; };
	virtual int GetPosY() const override { return PosY; };

	void SetFacing(Facing Value)override;
	void SetPosX(int Value)override;
	void SetPosY(int Value)override;
	void SetSide(Side Value)override;
	void SetHealth(int Value)override;
	void SetIsAlive(bool Value)override;
	void SetTravelTime(int Value)override;
private:
	int AnimationCount = 0;
	int SoundCount = 0;
	Facing Ent_Facing = Facing::Left;
	std::string CurrentSprite = "Bandit_Idle_Left__0";
	bool NotKilled = true;
	bool Attacking = true;
	int EnemyMoveSpeed = 2;
	int AttackCoolDown=20;
	int Health = 20;
};

