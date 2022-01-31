#include "Entity_Enemy.h"
#include "World.h"
void Entity_Enemy::Render(Graphics &Vis)
{
	if (Attacking)
	{
		SoundCount++;
		if (SoundCount >= 70)
		{
			HAPI.PlaySound("Data\\Sounds\\01_Punch_v2.WAV");
			SoundCount = 0;
		}
		
		if (Ent_Facing == Facing::Left)
		{
			if (AnimationCount == 0)
			{
				Vis.SpriteGraphics("Bandit_Attack_0", PosX, PosY);
				CurrentSprite = "Bandit_Attack_0";
				AnimationCount++;
			}
			else if (AnimationCount <= 20)
			{
				Vis.SpriteGraphics("Bandit_Attack_1", PosX, PosY);
				CurrentSprite = "Bandit_Attack_1";
				AnimationCount++;
			}
			else if (AnimationCount <= 40)
			{
				Vis.SpriteGraphics("Bandit_Attack_2", PosX, PosY);
				CurrentSprite = "Bandit_Attack_1";
				AnimationCount++;
			}
			else if (AnimationCount <= 60)
			{
				Vis.SpriteGraphics("Bandit_Attack_3", PosX, PosY);
				CurrentSprite = "Bandit_Attack_3";
				AnimationCount++;
			}
			else if (AnimationCount <= 80)
			{
				Vis.SpriteGraphics("Bandit_Attack_4", PosX, PosY);
				CurrentSprite = "Bandit_Attack_3";
				AnimationCount++;
			}
			else if (AnimationCount <= 100)
			{
				Vis.SpriteGraphics("Bandit_Attack_5", PosX, PosY);
				CurrentSprite = "Bandit_Attack_3";
				AnimationCount++;
			}
			else if (AnimationCount <= 120)
			{
				Vis.SpriteGraphics("Bandit_Attack_6", PosX, PosY);
				CurrentSprite = "Bandit_Attack_6";
				AnimationCount++;
			}
			else if (AnimationCount <= 140)
			{
				Vis.SpriteGraphics("Bandit_Attack_7", PosX, PosY);
				CurrentSprite = "Bandit_Attack_7";
				AnimationCount = 0;
			}
		}
		else if (Ent_Facing == Facing::Right)
		{
			if (AnimationCount == 0)
			{
				Vis.SpriteGraphics("Bandit_Right_Attack_0", PosX, PosY);
				CurrentSprite = "Bandit_Right_Attack_0";
				AnimationCount++;
			}
			else if (AnimationCount <= 20)
			{
				Vis.SpriteGraphics("Bandit_Right_Attack_1", PosX, PosY);
				CurrentSprite = "Bandit_Right_Attack_1";
				AnimationCount++;
			}
			else if (AnimationCount <= 40)
			{
				Vis.SpriteGraphics("Bandit_Right_Attack_2", PosX, PosY);
				CurrentSprite = "Bandit_Right_Attack_1";
				AnimationCount++;
			}
			else if (AnimationCount <= 60)
			{
				Vis.SpriteGraphics("Bandit_Right_Attack_3", PosX, PosY);
				CurrentSprite = "Bandit_Right_Attack_3";
				AnimationCount++;
			}
			else if (AnimationCount <= 80)
			{
				Vis.SpriteGraphics("Bandit_Right_Attack_4", PosX, PosY);
				CurrentSprite = "Bandit_Right_Attack_3";
				AnimationCount++;
			}
			else if (AnimationCount <= 100)
			{
				Vis.SpriteGraphics("Bandit_Right_Attack_5", PosX, PosY);
				CurrentSprite = "Bandit_Right_Attack_3";
				AnimationCount++;
			}
			else if (AnimationCount <= 120)
			{
				Vis.SpriteGraphics("Bandit_Right_Attack_6", PosX, PosY);
				CurrentSprite = "Bandit_Right_Attack_6";
				AnimationCount++;
			}
			else if (AnimationCount <= 140)
			{
				Vis.SpriteGraphics("Bandit_Right_Attack_7", PosX, PosY);
				CurrentSprite = "Bandit_Right_Attack_7";
				AnimationCount = 0;
			}
		}
	
	}
	else
	{
	if (Ent_Facing == Facing::Left)
	{
		if (AnimationCount == 0)
		{
			Vis.SpriteGraphics("Bandit_Run_0", PosX, PosY);
			CurrentSprite = "Bandit_Attack_0";
			AnimationCount++;
		}
		else if (AnimationCount <= 20)
		{
			Vis.SpriteGraphics("Bandit_Run_1", PosX, PosY);
			CurrentSprite = "Bandit_Run_1";
			AnimationCount++;
		}
		else if (AnimationCount <= 40)
		{
			Vis.SpriteGraphics("Bandit_Run_2", PosX, PosY);
			CurrentSprite = "Bandit_Run_1";
			AnimationCount++;
		}
		else if (AnimationCount <= 60)
		{
			Vis.SpriteGraphics("Bandit_Run_3", PosX, PosY);
			CurrentSprite = "Bandit_Run_3";
			AnimationCount++;
		}
		else if (AnimationCount <= 80)
		{
			Vis.SpriteGraphics("Bandit_Run_4", PosX, PosY);
			CurrentSprite = "Bandit_Run_3";
			AnimationCount++;
		}
		else if (AnimationCount <= 100)
		{
			Vis.SpriteGraphics("Bandit_Run_5", PosX, PosY);
			CurrentSprite = "Bandit_Run_3";
			AnimationCount++;
		}
		else if (AnimationCount <= 120)
		{
			Vis.SpriteGraphics("Bandit_Run_6", PosX, PosY);
			CurrentSprite = "Bandit_Run_6";
			AnimationCount++;
		}
		else if (AnimationCount <= 140)
		{
			Vis.SpriteGraphics("Bandit_Run_7", PosX, PosY);
			CurrentSprite = "Bandit_Run_7";
			AnimationCount = 0;
		}
	}
	else if (Ent_Facing == Facing::Right)
	{
		if (AnimationCount == 0)
		{
			Vis.SpriteGraphics("Bandit_Right_Run_0", PosX, PosY);
			CurrentSprite = "Bandit_Right_Run_0";
			AnimationCount++;
		}
		else if (AnimationCount <= 20)
		{
			Vis.SpriteGraphics("Bandit_Right_Run_1", PosX, PosY);
			CurrentSprite = "Bandit_Right_Run_1";
			AnimationCount++;
		}
		else if (AnimationCount <= 40)
		{
			Vis.SpriteGraphics("Bandit_Right_Run_2", PosX, PosY);
			CurrentSprite = "Bandit_Right_Run_1";
			AnimationCount++;
		}
		else if (AnimationCount <= 60)
		{
			Vis.SpriteGraphics("Bandit_Right_Run_3", PosX, PosY);
			CurrentSprite = "Bandit_Right_Run_3";
			AnimationCount++;
		}
		else if (AnimationCount <= 80)
		{
			Vis.SpriteGraphics("Bandit_Right_Run_4", PosX, PosY);
			CurrentSprite = "Bandit_Right_Run_3";
			AnimationCount++;
		}
		else if (AnimationCount <= 100)
		{
			Vis.SpriteGraphics("Bandit_Right_Run_5", PosX, PosY);
			CurrentSprite = "Bandit_Right_Run_3";
			AnimationCount++;
		}
		else if (AnimationCount <= 120)
		{
			Vis.SpriteGraphics("Bandit_Right_Run_6", PosX, PosY);
			CurrentSprite = "Bandit_Right_Attack_6";
			AnimationCount++;
		}
		else if (AnimationCount <= 140)
		{
			Vis.SpriteGraphics("Bandit_Right_Run_7", PosX, PosY);
			CurrentSprite = "Bandit_Right_Attack_7";
			AnimationCount = 0;
		}
	}
	}
	
	
}

void Entity_Enemy::Update(Graphics& Vis, World& world)
{
	if (Health <= 0)
	{
		IsAlive = false;
		if (NotKilled)
		{
			world.DeadEnemies++;
			NotKilled = false;
		}
	
	}
	if (IsAlive)
	{
		if (PosX == world.GetPlayer()->GetPosX() + 50)
		{
			if (PosY > world.GetPlayer()->GetPosY()+5)
			{
				PosY = PosY - EnemyMoveSpeed;
				Attacking = false;
			}
			else if (PosY < world.GetPlayer()->GetPosY()+5)
			{
				PosY = PosY + EnemyMoveSpeed;
				Attacking = false;
			}
			else
			{
				Attacking = true;
			}
		}
				
		
		else if (PosX > world.GetPlayer()->GetPosX())
		{
			PosX = PosX - EnemyMoveSpeed;
			Ent_Facing = Facing::Left;
			Attacking = false;
		}
		else if (PosX < world.GetPlayer()->GetPosX())
		{
			PosX = PosX + EnemyMoveSpeed;
			Ent_Facing = Facing::Right;
			Attacking = false;
		}
		else if (PosY > world.GetPlayer()->GetPosY()+5)
		{
			PosY = PosY - EnemyMoveSpeed;
			Attacking = false;
		}
		else if (PosY < world.GetPlayer()->GetPosY()+5)
		{
			PosY = PosY + EnemyMoveSpeed;
			Attacking = false;
		}
		else
		{
			Attacking = true;
		}
		AttackCoolDown++;
		if (Attacking)
		{
			if (AttackCoolDown >= 20)
			{
				world.GetPlayer()->SetHealth(5);
				AttackCoolDown = 0;
			}
		}
		Render(Vis);
	}
}

void Entity_Enemy::Kill(World& world)
{
	world.DeadEnemies++;
}



void Entity_Enemy::SetFacing(Facing Value)
{
	Ent_Facing = Value;
}

void Entity_Enemy::SetPosX(int Value)
{
	PosX = Value;
}

void Entity_Enemy::SetPosY(int Value)
{
	PosY = Value;
}

void Entity_Enemy::SetSide(Side Value)
{
}

void Entity_Enemy::SetHealth(int Value)
{
	Health = Health - Value;
}

void Entity_Enemy::SetIsAlive(bool Value)
{
	IsAlive = Value;
}

void Entity_Enemy::SetTravelTime(int Value)
{
}
