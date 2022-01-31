#include "Entity_Player.h"
#include "World.h"
#include "Graphics.h"
void Entity_Player::ControlsUpdate()
{
		KeyData = HAPI.GetKeyboardData();
		ControllerData = HAPI.GetControllerData(0);
		int LeftThumbX = ControllerData.analogueButtons[HK_ANALOGUE_LEFT_THUMB_X];
		int LeftThumbY = ControllerData.analogueButtons[HK_ANALOGUE_LEFT_THUMB_Y];
		bool AttachCheck = ControllerData.isAttached;

		if (KeyData.scanCode[HK_SPACE] || ControllerData.digitalButtons[HK_DIGITAL_X])
		{
			Attacking = true;
			if (KeyData.scanCode['D'])
			{
				Ent_Facing=Facing::Right;
			}
			else if (KeyData.scanCode['A'])
			{
				Ent_Facing = Facing::Left;
			}
			else
			{
				Idle = true;
			}
		}
		else if (!KeyData.scanCode[HK_SPACE]|| ControllerData.digitalButtons[HK_DIGITAL_X])
		{
			Attacking = false;
			if (ControllerData.isAttached)
			{
				if (LeftThumbX > 7849 || LeftThumbX < -7849)//Outside X Deadzone
				{
					if (LeftThumbX > 7849)
					{
						PosX += NormalSpeed;
						Ent_Facing = Facing::Right;
						Idle = false;
					}
					if (LeftThumbX < 7849)
					{
						PosX -= NormalSpeed;
						Ent_Facing = Facing::Left;
						Idle = false;
					}
				

				}
				if (LeftThumbY > 7849 || LeftThumbY < -7849)//Outside Y DeadZone
				{
					if (LeftThumbY > 7849)
					{
						PosY -= NormalSpeed;
						Idle = false;
					}
					if (LeftThumbY < 7849)
					{
						PosY += NormalSpeed;
						Idle = false;
					}
				else
				{
					Idle = true;
				}
				}
			}
			//Diaginal Movement
			else if (KeyData.scanCode['W'] & KeyData.scanCode['D'])//North East
			{
				PosY -= DiagnalSpeed;
				PosX += DiagnalSpeed;
				Ent_Facing = Facing::Right;
				Idle = false;
			}
			else if (KeyData.scanCode['W'] & KeyData.scanCode['A'])//North West
			{
				PosY -= DiagnalSpeed;
				PosX -= DiagnalSpeed;
				Ent_Facing = Facing::Left;
				Idle = false;
			}
			else if (KeyData.scanCode['S'] & KeyData.scanCode['D'])//South East
			{
				PosY += DiagnalSpeed;
				PosX += DiagnalSpeed;
				Ent_Facing = Facing::Right;
				Idle = false;
			}
			else if (KeyData.scanCode['S'] & KeyData.scanCode['A'])//South West
			{
				PosY += DiagnalSpeed;
				PosX -= DiagnalSpeed;
				Ent_Facing = Facing::Left;
				Idle = false;
			}

			//Normal Movement
			else if (KeyData.scanCode['W'])
			{
				PosY -= NormalSpeed;
				Idle = false;
			}
			else if (KeyData.scanCode['S'])
			{
				PosY += NormalSpeed;
				Idle = false;
			}
			else if (KeyData.scanCode['A'])
			{
				Ent_Facing = Facing::Left;
				Idle = false;
				PosX -= NormalSpeed;
			}
			else if (KeyData.scanCode['D'])
			{
				Ent_Facing = Facing::Right;
				Idle = false;
				PosX += NormalSpeed;
			}
			else
			{
				Idle = true;
			}
		}
		
}

void Entity_Player::Update(Graphics& Vis, World& world)
{
	ControlsUpdate();
	Render(Vis);
	ShootCooldown++;
	if (Attacking)
	{
		if (ShootCooldown >= 200)
		{
			world.ShootArrow(this);
			ShootCooldown = 0;
		}
	}
}

void Entity_Player::Render(Graphics& Vis)
{
	if (Attacking)
	{
		if (AnimationCount > 50)
			AnimationCount = 0;
		if (Ent_Facing==Facing::Right)
		{
			if (AnimationCount == 0)
			{
				Vis.SpriteGraphics("Player_Attack_0", PosX, PosY);
				CurrentSprite = "Player_Attack_0";
				AnimationCount++;
			}
			else if (AnimationCount <= 10)
			{
				Vis.SpriteGraphics("Player_Attack_1", PosX, PosY);
				CurrentSprite = "Player_Attack_1";
				AnimationCount++;
			}
			else if (AnimationCount <= 20)
			{
				Vis.SpriteGraphics("Player_Attack_2", PosX, PosY);
				CurrentSprite = "Player_Attack_2";
				AnimationCount++;
			}
			else if (AnimationCount <= 30)
			{
				Vis.SpriteGraphics("Player_Attack_3", PosX, PosY);
				CurrentSprite = "Player_Attack_3";
				AnimationCount++;
			}
			else if (AnimationCount <= 40)
			{
				Vis.SpriteGraphics("Player_Attack_4", PosX, PosY);
				CurrentSprite = "Player_Attack_4";
				AnimationCount++;
			}
			else if (AnimationCount <= 50)
			{
				Vis.SpriteGraphics("Player_Attack_5", PosX, PosY);
				CurrentSprite = "Player_Attack_5";
				AnimationCount = 0;
			}
		}
		else
		{
			if (AnimationCount == 0)
			{
				Vis.SpriteGraphics("Player_Attack_Left_0", PosX, PosY);
				CurrentSprite = "Player_Attack_Left_0";
				AnimationCount++;
			}
			else if (AnimationCount <= 10)
			{
				Vis.SpriteGraphics("Player_Attack_Left_1", PosX, PosY);
				CurrentSprite = "Player_Attack_Left_1";
				AnimationCount++;
			}
			else if (AnimationCount <= 20)
			{
				Vis.SpriteGraphics("Player_Attack_Left_2", PosX, PosY);
				CurrentSprite = "Player_Attack_Left_2";
				AnimationCount++;
			}
			else if (AnimationCount <= 30)
			{
				Vis.SpriteGraphics("Player_Attack_Left_3", PosX, PosY);
				CurrentSprite = "Player_Attack_Left_3";
				AnimationCount++;
			}
			else if (AnimationCount <= 40)
			{
				Vis.SpriteGraphics("Player_Attack_Left_4", PosX, PosY);
				CurrentSprite = "Player_Attack_Left_4";
				AnimationCount++;
			}
			else if (AnimationCount <= 50)
			{
				Vis.SpriteGraphics("Player_Attack_Left_5", PosX, PosY);
				CurrentSprite = "Player_Attack_Left_5";
				AnimationCount = 0;
			}
		}
	}
	else if (Idle)
	{
		if (Ent_Facing == Facing::Right)
		{
			if (AnimationCount == 0)
			{
				Vis.SpriteGraphics("Player_Idle_0", PosX, PosY);
				CurrentSprite = "Player_Idle_0";
				AnimationCount++;
			}
			else if (AnimationCount <= 10)
			{
				Vis.SpriteGraphics("Player_Idle_1", PosX, PosY);
				CurrentSprite = "Player_Idle_1";
				AnimationCount++;
			}
			else if (AnimationCount <= 20)
			{
				Vis.SpriteGraphics("Player_Idle_2", PosX, PosY);
				CurrentSprite = "Player_Idle_2";
				AnimationCount++;
			}
			else if (AnimationCount <= 30)
			{
				Vis.SpriteGraphics("Player_Idle_3", PosX, PosY);
				CurrentSprite = "Player_Idle_3";
				AnimationCount++;
			}
			else if (AnimationCount <= 40)
			{
				Vis.SpriteGraphics("Player_Idle_4", PosX, PosY);
				CurrentSprite = "Player_Idle_4";
				AnimationCount++;
			}
			else if (AnimationCount <= 50)
			{
				Vis.SpriteGraphics("Player_Idle_5", PosX, PosY);
				CurrentSprite = "Player_Idle_5";
				AnimationCount++;
			}
			else if (AnimationCount <= 60)
			{
				Vis.SpriteGraphics("Player_Idle_6", PosX, PosY);
				CurrentSprite = "Player_Idle_6";
				AnimationCount++;
			}
			else if (AnimationCount <= 70)
			{
				Vis.SpriteGraphics("Player_Idle_7", PosX, PosY);
				CurrentSprite = "Player_Idle_7";
				AnimationCount = 0;
			}
		}
		else if (Ent_Facing == Facing::Left)
		{
			if (AnimationCount == 0)
			{
				Vis.SpriteGraphics("Player_Idle_Left_0", PosX, PosY);
				CurrentSprite = "Player_Idle_Left_0";
				AnimationCount++;
			}
			else if (AnimationCount <= 10)
			{
				Vis.SpriteGraphics("Player_Idle_Left_1", PosX, PosY);
				CurrentSprite = "Player_Idle_Left_1";
				AnimationCount++;
			}
			else if (AnimationCount <= 20)
			{
				Vis.SpriteGraphics("Player_Idle_Left_2", PosX, PosY);
				CurrentSprite = "Player_Idle_Left_2";
				AnimationCount++;
			}
			else if (AnimationCount <= 30)
			{
				Vis.SpriteGraphics("Player_Idle_Left_3", PosX, PosY);
				CurrentSprite = "Player_Idle_Left_3";
				AnimationCount++;
			}
			else if (AnimationCount <= 40)
			{
				Vis.SpriteGraphics("Player_Idle_Left_4", PosX, PosY);
				CurrentSprite = "Player_Idle_Left_4";
				AnimationCount++;
			}
			else if (AnimationCount <= 50)
			{
				Vis.SpriteGraphics("Player_Idle_Left_5", PosX, PosY);
				CurrentSprite = "Player_Idle_Left_5";
				AnimationCount++;
			}
			else if (AnimationCount <= 60)
			{
				Vis.SpriteGraphics("Player_Idle_Left_6", PosX, PosY);
				CurrentSprite = "Player_Idle_Left_6";
				AnimationCount++;
			}
			else if (AnimationCount <= 70)
			{
				Vis.SpriteGraphics("Player_Idle_Left_7", PosX, PosY);
				CurrentSprite = "Player_Idle_Left_7";
				AnimationCount = 0;
			}
		}

	}
	else
	{
		if (Ent_Facing == Facing::Right)
		{
			if (AnimationCount == 0)
			{
				Vis.SpriteGraphics("Player_Run_0", PosX, PosY);
				CurrentSprite = "Player_Run_0";
				AnimationCount++;
			}
			else if (AnimationCount <= 10)
			{
				Vis.SpriteGraphics("Player_Run_1", PosX, PosY);
				CurrentSprite = "Player_Run_1";
				AnimationCount++;
			}
			else if (AnimationCount <= 20)
			{
				Vis.SpriteGraphics("Player_Run_2", PosX, PosY);
				CurrentSprite = "Player_Run_2";
				AnimationCount++;
			}
			else if (AnimationCount <= 30)
			{
				Vis.SpriteGraphics("Player_Run_3", PosX, PosY);
				CurrentSprite = "Player_Run_3";
				AnimationCount++;
			}
			else if (AnimationCount <= 40)
			{
				Vis.SpriteGraphics("Player_Run_4", PosX, PosY);
				CurrentSprite = "Player_Run_4";
				AnimationCount++;
			}
			else if (AnimationCount <= 50)
			{
				Vis.SpriteGraphics("Player_Run_5", PosX, PosY);
				CurrentSprite = "Player_Run_5";
				AnimationCount++;
			}
			else if (AnimationCount <= 60)
			{
				Vis.SpriteGraphics("Player_Run_6", PosX, PosY);
				CurrentSprite = "Player_Run_6";
				AnimationCount++;
			}
			else if (AnimationCount <= 70)
			{
				Vis.SpriteGraphics("Player_Run_7", PosX, PosY);
				CurrentSprite = "Player_Run_7";
				AnimationCount++;
			}
			else if (AnimationCount <= 80)
			{
				Vis.SpriteGraphics("Player_Run_8", PosX, PosY);
				CurrentSprite = "Player_Run_8";
				AnimationCount++;
			}
			else if (AnimationCount <= 90)
			{
				Vis.SpriteGraphics("Player_Run_9", PosX, PosY);
				CurrentSprite = "Player_Run_9";
				AnimationCount = 0;
			}
		}
		else if (Ent_Facing == Facing::Left)
		{
			if (AnimationCount == 0)
			{
				Vis.SpriteGraphics("Player_Left_Run_0", PosX, PosY);
				CurrentSprite = "Player_Left_Run_0";
				AnimationCount++;
			}
			else if (AnimationCount <= 10)
			{
				Vis.SpriteGraphics("Player_Left_Run_1", PosX, PosY);
				CurrentSprite = "Player_Left_Run_1";
				AnimationCount++;
			}
			else if (AnimationCount <= 20)
			{
				Vis.SpriteGraphics("Player_Left_Run_2", PosX, PosY);
				CurrentSprite = "Player_Left_Run_2";
				AnimationCount++;
			}
			else if (AnimationCount <= 30)
			{
				Vis.SpriteGraphics("Player_Left_Run_3", PosX, PosY);
				CurrentSprite = "Player_Left_Run_3";
				AnimationCount++;
			}
			else if (AnimationCount <= 40)
			{
				Vis.SpriteGraphics("Player_Left_Run_4", PosX, PosY);
				CurrentSprite = "Player_Left_Run_4";
				AnimationCount++;
			}
			else if (AnimationCount <= 50)
			{
				Vis.SpriteGraphics("Player_Left_Run_5", PosX, PosY);
				CurrentSprite = "Player_Left_Run_5";
				AnimationCount++;
			}
			else if (AnimationCount <= 60)
			{
				Vis.SpriteGraphics("Player_Left_Run_6", PosX, PosY);
				CurrentSprite = "Player_Left_Run_6";
				AnimationCount++;
			}
			else if (AnimationCount <= 70)
			{
				Vis.SpriteGraphics("Player_Left_Run_7", PosX, PosY);
				CurrentSprite = "Player_Left_Run_7";
				AnimationCount++;
			}
			else if (AnimationCount <= 80)
			{
				Vis.SpriteGraphics("Player_Left_Run_8", PosX, PosY);
				CurrentSprite = "Player_Left_Run_8";
				AnimationCount++;
			}
			else if (AnimationCount <= 90)
			{
				Vis.SpriteGraphics("Player_Left_Run_9", PosX, PosY);
				CurrentSprite = "Player_Left_Run_9";
				AnimationCount = 0;
			}
			
		}
	} //Regular Movement
}

void Entity_Player::Kill(World& world)
{

}



bool Entity_Player::GetAttackStatus()
{
	return Attacking;
}

void Entity_Player::SetFacing(Facing Value)
{
	Ent_Facing = Value;
}

void Entity_Player::SetPosX(int Value)
{
	PosX = Value;
}

void Entity_Player::SetPosY(int Value)
{
	PosY = Value;
}

void Entity_Player::SetSide(Side Value)
{
}

void Entity_Player::SetHealth(int Value)
{
	Health = Health - Value;
}

void Entity_Player::SetIsAlive(bool Value)
{
	IsAlive = Value;
}

void Entity_Player::SetTravelTime(int Value)
{
}


	
