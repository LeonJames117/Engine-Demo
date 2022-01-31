#include "Entity_Arrow.h"

void Entity_Arrow::Update(Graphics& Vis, World& world)
{
	if (IsAlive)
	{
		Render(Vis);
		if (!ArrowHit)
		{
			if (Ent_Facing == Facing::Right)
			{
				PosX = PosX + 1;
			}
			else if (Ent_Facing == Facing::Left)
			{
				PosX = PosX-1;
			}
			TravelTime++;
			if (TravelTime >= 500)
			{
				IsAlive = false;
				return;
			}
		}
		
	}

	
}

void Entity_Arrow::Render(Graphics& Vis)
{
	if (Ent_Facing == Facing::Right)
	{
		Vis.SpriteGraphics("Arrow", PosX, PosY);
		CurrentSprite = "Arrow";
	}
	else if (Ent_Facing == Facing::Left)
	{
		Vis.SpriteGraphics("Left Arrow", PosX, PosY);
		CurrentSprite = "Left Arrow";
	}
}

void Entity_Arrow::Kill(World& world)
{
}

void Entity_Arrow::SetHealth(int Value)
{
}

void Entity_Arrow::SetFacing(Facing Value)
{
	Ent_Facing = Value;
}

void Entity_Arrow::SetSide(Side Value)
{
	Ent_Side = Value;
}

void Entity_Arrow::SetPosX(int Value)
{
	PosX = Value;
}

void Entity_Arrow::SetPosY(int Value)
{
	PosY = Value;
}

void Entity_Arrow::SetIsAlive(bool Value)
{
	IsAlive = Value;
}

void Entity_Arrow::SetTravelTime(int Value)
{
	TravelTime = Value;
}

void Entity_Arrow::ShootArrow(Entity* Caster)
{
	
}

void Entity_Arrow::ArrowColision(Entity* Victim)
{
	ArrowHit = true;
}
