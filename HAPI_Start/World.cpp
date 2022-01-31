#include "World.h"
#include "Entity.h"
#include "Entity_Player.h"
#include "Entity_Enemy.h"
#include "Entity_Arrow.h"
#include "Graphics.h"
#include "Sprite.h"
#include <HAPI_lib.h>


void World::ShootArrow(Entity* Caster)
{
	for (size_t i = ArrowStart; i < EntityList.size(); i++)
	{
		if (!EntityList[i]->GetIsAlive())
		{
			EntityList[i]->SetFacing(Caster->GetFacing());
			EntityList[i]->SetSide(Caster->GetSide());
			if (Caster->GetFacing() == Facing::Right)
			{
				EntityList[i]->SetPosX((Caster->GetPosX()+50));
			}
			else
			{
				EntityList[i]->SetPosX(Caster->GetPosX());
			}
			EntityList[i]->SetPosY((Caster->GetPosY()+10));
			EntityList[i]->SetTravelTime(0);
			EntityList[i]->SetIsAlive(true);
			HAPI.PlaySound("Data\\Sounds\\01_Explosion_v3.WAV");
		}
	}

}




void World::Run()
{
	Graphics Vis;
	World Sim;
	Entity_Player Player;
	WorldPlayer = &Player;
	EntityList.push_back(&Player);



	Entity_Enemy Enemy(rand()%500+200, rand() % 700 + 200,true);
	EntityList.push_back(&Enemy);
	
	Entity_Enemy Enemy1(rand() % 500 + 200, rand() % 700 + 200, true);
	EntityList.push_back(&Enemy1);
	
	Entity_Enemy Enemy2(rand() % 500 + 200, rand() % 700 + 200, true);
	EntityList.push_back(&Enemy2);
	
	Entity_Enemy Enemy3(rand() % 500 + 200, rand() % 700 + 200, true);
	EntityList.push_back(&Enemy3);

	EnemyCount = 4;

	ArrowStart = EntityList.size();


	for (size_t i = 0; i < 10; i++)
	{
		Entity_Arrow Arrow;
		EntityList.push_back(&Arrow);
	}
	
	Vis.ScreenSetup();
	Rectangle ScreenRect(0, 1024, 768, 0);

//Enemy Attack Left
	Vis.GetSprite("Bandit_Attack_0", "Data\\Bandits\\Sprites\\Light Bandit\\Attack\\LightBandit_Attack_0.PNG");
	Vis.GetSprite("Bandit_Attack_1", "Data\\Bandits\\Sprites\\Light Bandit\\Attack\\LightBandit_Attack_1.PNG");
	Vis.GetSprite("Bandit_Attack_2", "Data\\Bandits\\Sprites\\Light Bandit\\Attack\\LightBandit_Attack_2.PNG");
	Vis.GetSprite("Bandit_Attack_3", "Data\\Bandits\\Sprites\\Light Bandit\\Attack\\LightBandit_Attack_3.PNG");
	Vis.GetSprite("Bandit_Attack_4", "Data\\Bandits\\Sprites\\Light Bandit\\Attack\\LightBandit_Attack_4.PNG");
	Vis.GetSprite("Bandit_Attack_5", "Data\\Bandits\\Sprites\\Light Bandit\\Attack\\LightBandit_Attack_5.PNG");
	Vis.GetSprite("Bandit_Attack_6", "Data\\Bandits\\Sprites\\Light Bandit\\Attack\\LightBandit_Attack_6.PNG");
	Vis.GetSprite("Bandit_Attack_7", "Data\\Bandits\\Sprites\\Light Bandit\\Attack\\LightBandit_Attack_7.PNG");
//Enemy Attack Right
	Vis.GetSprite("Bandit_Right_Attack_0", "Data\\Bandits\\Sprites\\Light Bandit\\Attack\\LightBandit_Right_Attack_0.PNG");
	Vis.GetSprite("Bandit_Right_Attack_1", "Data\\Bandits\\Sprites\\Light Bandit\\Attack\\LightBandit_Right_Attack_1.PNG");
	Vis.GetSprite("Bandit_Right_Attack_2", "Data\\Bandits\\Sprites\\Light Bandit\\Attack\\LightBandit_Right_Attack_2.PNG");
	Vis.GetSprite("Bandit_Right_Attack_3", "Data\\Bandits\\Sprites\\Light Bandit\\Attack\\LightBandit_Right_Attack_3.PNG");
	Vis.GetSprite("Bandit_Right_Attack_4", "Data\\Bandits\\Sprites\\Light Bandit\\Attack\\LightBandit_Right_Attack_4.PNG");
	Vis.GetSprite("Bandit_Right_Attack_5", "Data\\Bandits\\Sprites\\Light Bandit\\Attack\\LightBandit_Right_Attack_5.PNG");
	Vis.GetSprite("Bandit_Right_Attack_6", "Data\\Bandits\\Sprites\\Light Bandit\\Attack\\LightBandit_Right_Attack_6.PNG");
	Vis.GetSprite("Bandit_Right_Attack_7", "Data\\Bandits\\Sprites\\Light Bandit\\Attack\\LightBandit_Right_Attack_7.PNG");
//Enemy Run Left
	Vis.GetSprite("Bandit_Run_0", "Data\\Bandits\\Sprites\\Light Bandit\\Run\\LightBandit_Run_0.PNG");
	Vis.GetSprite("Bandit_Run_1", "Data\\Bandits\\Sprites\\Light Bandit\\Run\\LightBandit_Run_1.PNG");
	Vis.GetSprite("Bandit_Run_2", "Data\\Bandits\\Sprites\\Light Bandit\\Run\\LightBandit_Run_2.PNG");
	Vis.GetSprite("Bandit_Run_3", "Data\\Bandits\\Sprites\\Light Bandit\\Run\\LightBandit_Run_3.PNG");
	Vis.GetSprite("Bandit_Run_4", "Data\\Bandits\\Sprites\\Light Bandit\\Run\\LightBandit_Run_4.PNG");
	Vis.GetSprite("Bandit_Run_5", "Data\\Bandits\\Sprites\\Light Bandit\\Run\\LightBandit_Run_5.PNG");
	Vis.GetSprite("Bandit_Run_6", "Data\\Bandits\\Sprites\\Light Bandit\\Run\\LightBandit_Run_6.PNG");
	Vis.GetSprite("Bandit_Run_7", "Data\\Bandits\\Sprites\\Light Bandit\\Run\\LightBandit_Run_7.PNG");
//Enemy Run Right
	Vis.GetSprite("Bandit_Right_Run_0", "Data\\Bandits\\Sprites\\Light Bandit\\Run\\LightBandit_Right_Run_0.PNG");
	Vis.GetSprite("Bandit_Right_Run_1", "Data\\Bandits\\Sprites\\Light Bandit\\Run\\LightBandit_Right_Run_1.PNG");
	Vis.GetSprite("Bandit_Right_Run_2", "Data\\Bandits\\Sprites\\Light Bandit\\Run\\LightBandit_Right_Run_2.PNG");
	Vis.GetSprite("Bandit_Right_Run_3", "Data\\Bandits\\Sprites\\Light Bandit\\Run\\LightBandit_Right_Run_3.PNG");
	Vis.GetSprite("Bandit_Right_Run_4", "Data\\Bandits\\Sprites\\Light Bandit\\Run\\LightBandit_Right_Run_4.PNG");
	Vis.GetSprite("Bandit_Right_Run_5", "Data\\Bandits\\Sprites\\Light Bandit\\Run\\LightBandit_Right_Run_5.PNG");
	Vis.GetSprite("Bandit_Right_Run_6", "Data\\Bandits\\Sprites\\Light Bandit\\Run\\LightBandit_Right_Run_6.PNG");
	Vis.GetSprite("Bandit_Right_Run_7", "Data\\Bandits\\Sprites\\Light Bandit\\Run\\LightBandit_Right_Run_7.PNG");
//Player Idle Right
	Vis.GetSprite("Player_Idle_0", "Data\\Hero Knight\\Sprites\\HeroKnight\\Idle\\HeroKnight_Idle_0.PNG");
	Vis.GetSprite("Player_Idle_1", "Data\\Hero Knight\\Sprites\\HeroKnight\\Idle\\HeroKnight_Idle_1.PNG");
	Vis.GetSprite("Player_Idle_2", "Data\\Hero Knight\\Sprites\\HeroKnight\\Idle\\HeroKnight_Idle_2.PNG");
	Vis.GetSprite("Player_Idle_3", "Data\\Hero Knight\\Sprites\\HeroKnight\\Idle\\HeroKnight_Idle_3.PNG");
	Vis.GetSprite("Player_Idle_4", "Data\\Hero Knight\\Sprites\\HeroKnight\\Idle\\HeroKnight_Idle_4.PNG");
	Vis.GetSprite("Player_Idle_5", "Data\\Hero Knight\\Sprites\\HeroKnight\\Idle\\HeroKnight_Idle_5.PNG");
	Vis.GetSprite("Player_Idle_6", "Data\\Hero Knight\\Sprites\\HeroKnight\\Idle\\HeroKnight_Idle_6.PNG");
	Vis.GetSprite("Player_Idle_7", "Data\\Hero Knight\\Sprites\\HeroKnight\\Idle\\HeroKnight_Idle_7.PNG");
//Player Idle Left
	Vis.GetSprite("Player_Idle_Left_0", "Data\\Hero Knight\\Sprites\\HeroKnight\\Idle\\HeroKnight_Idle_Left_0.PNG");
	Vis.GetSprite("Player_Idle_Left_1", "Data\\Hero Knight\\Sprites\\HeroKnight\\Idle\\HeroKnight_Idle_Left_1.PNG");
	Vis.GetSprite("Player_Idle_Left_2", "Data\\Hero Knight\\Sprites\\HeroKnight\\Idle\\HeroKnight_Idle_Left_2.PNG");
	Vis.GetSprite("Player_Idle_Left_3", "Data\\Hero Knight\\Sprites\\HeroKnight\\Idle\\HeroKnight_Idle_Left_3.PNG");
	Vis.GetSprite("Player_Idle_Left_4", "Data\\Hero Knight\\Sprites\\HeroKnight\\Idle\\HeroKnight_Idle_Left_4.PNG");
	Vis.GetSprite("Player_Idle_Left_5", "Data\\Hero Knight\\Sprites\\HeroKnight\\Idle\\HeroKnight_Idle_Left_5.PNG");
	Vis.GetSprite("Player_Idle_Left_6", "Data\\Hero Knight\\Sprites\\HeroKnight\\Idle\\HeroKnight_Idle_Left_6.PNG");
	Vis.GetSprite("Player_Idle_Left_7", "Data\\Hero Knight\\Sprites\\HeroKnight\\Idle\\HeroKnight_Idle_Left_7.PNG");
//Player Run Right
	Vis.GetSprite("Player_Run_0", "Data\\Hero Knight\\Sprites\\HeroKnight\\Run\\HeroKnight_Run_0.PNG");
	Vis.GetSprite("Player_Run_1", "Data\\Hero Knight\\Sprites\\HeroKnight\\Run\\HeroKnight_Run_1.PNG");
	Vis.GetSprite("Player_Run_2", "Data\\Hero Knight\\Sprites\\HeroKnight\\Run\\HeroKnight_Run_2.PNG");
	Vis.GetSprite("Player_Run_3", "Data\\Hero Knight\\Sprites\\HeroKnight\\Run\\HeroKnight_Run_3.PNG");
	Vis.GetSprite("Player_Run_4", "Data\\Hero Knight\\Sprites\\HeroKnight\\Run\\HeroKnight_Run_4.PNG");
	Vis.GetSprite("Player_Run_5", "Data\\Hero Knight\\Sprites\\HeroKnight\\Run\\HeroKnight_Run_5.PNG");
	Vis.GetSprite("Player_Run_6", "Data\\Hero Knight\\Sprites\\HeroKnight\\Run\\HeroKnight_Run_6.PNG");
	Vis.GetSprite("Player_Run_7", "Data\\Hero Knight\\Sprites\\HeroKnight\\Run\\HeroKnight_Run_7.PNG");
	Vis.GetSprite("Player_Run_8", "Data\\Hero Knight\\Sprites\\HeroKnight\\Run\\HeroKnight_Run_8.PNG");
	Vis.GetSprite("Player_Run_9", "Data\\Hero Knight\\Sprites\\HeroKnight\\Run\\HeroKnight_Run_9.PNG");
//Player Run Left
	Vis.GetSprite("Player_Left_Run_0", "Data\\Hero Knight\\Sprites\\HeroKnight\\Run\\HeroKnight_Left_Run_0.PNG");
	Vis.GetSprite("Player_Left_Run_1", "Data\\Hero Knight\\Sprites\\HeroKnight\\Run\\HeroKnight_Left_Run_1.PNG");
	Vis.GetSprite("Player_Left_Run_2", "Data\\Hero Knight\\Sprites\\HeroKnight\\Run\\HeroKnight_Left_Run_2.PNG");
	Vis.GetSprite("Player_Left_Run_3", "Data\\Hero Knight\\Sprites\\HeroKnight\\Run\\HeroKnight_Left_Run_3.PNG");
	Vis.GetSprite("Player_Left_Run_4", "Data\\Hero Knight\\Sprites\\HeroKnight\\Run\\HeroKnight_Left_Run_4.PNG");
	Vis.GetSprite("Player_Left_Run_5", "Data\\Hero Knight\\Sprites\\HeroKnight\\Run\\HeroKnight_Left_Run_5.PNG");
	Vis.GetSprite("Player_Left_Run_6", "Data\\Hero Knight\\Sprites\\HeroKnight\\Run\\HeroKnight_Left_Run_6.PNG");
	Vis.GetSprite("Player_Left_Run_7", "Data\\Hero Knight\\Sprites\\HeroKnight\\Run\\HeroKnight_Left_Run_7.PNG");
	Vis.GetSprite("Player_Left_Run_8", "Data\\Hero Knight\\Sprites\\HeroKnight\\Run\\HeroKnight_Left_Run_8.PNG");
	Vis.GetSprite("Player_Left_Run_9", "Data\\Hero Knight\\Sprites\\HeroKnight\\Run\\HeroKnight_Left_Run_9.PNG");
//Player Attack	
	Vis.GetSprite("Player_Attack_0", "Data\\Hero Knight\\Sprites\\HeroKnight\\Attack1\\HeroKnight_Attack1_0.PNG");
	Vis.GetSprite("Player_Attack_1", "Data\\Hero Knight\\Sprites\\HeroKnight\\Attack1\\HeroKnight_Attack1_1.PNG");
	Vis.GetSprite("Player_Attack_2", "Data\\Hero Knight\\Sprites\\HeroKnight\\Attack1\\HeroKnight_Attack1_2.PNG");
	Vis.GetSprite("Player_Attack_3", "Data\\Hero Knight\\Sprites\\HeroKnight\\Attack1\\HeroKnight_Attack1_3.PNG");
	Vis.GetSprite("Player_Attack_4", "Data\\Hero Knight\\Sprites\\HeroKnight\\Attack1\\HeroKnight_Attack1_4.PNG");
	Vis.GetSprite("Player_Attack_5", "Data\\Hero Knight\\Sprites\\HeroKnight\\Attack1\\HeroKnight_Attack1_5.PNG");
//Player Attack Left
	Vis.GetSprite("Player_Attack_Left_0", "Data\\Hero Knight\\Sprites\\HeroKnight\\Attack1\\HeroKnight_Attack1_Left_0.PNG");
	Vis.GetSprite("Player_Attack_Left_1", "Data\\Hero Knight\\Sprites\\HeroKnight\\Attack1\\HeroKnight_Attack1_Left_1.PNG");
	Vis.GetSprite("Player_Attack_Left_2", "Data\\Hero Knight\\Sprites\\HeroKnight\\Attack1\\HeroKnight_Attack1_Left_2.PNG");
	Vis.GetSprite("Player_Attack_Left_3", "Data\\Hero Knight\\Sprites\\HeroKnight\\Attack1\\HeroKnight_Attack1_Left_3.PNG");
	Vis.GetSprite("Player_Attack_Left_4", "Data\\Hero Knight\\Sprites\\HeroKnight\\Attack1\\HeroKnight_Attack1_Left_4.PNG");
	Vis.GetSprite("Player_Attack_Left_5", "Data\\Hero Knight\\Sprites\\HeroKnight\\Attack1\\HeroKnight_Attack1_Left_5.PNG");
//Arrow and Left Arrow
	Vis.GetSprite("Arrow", "Data\\Arrows\\Basic Arrow.PNG");
	Vis.GetSprite("Left Arrow", "Data\\Arrows\\Basic Arrow Left.PNG");//Animation Image Load Calls



	if (!Vis.GetSprite("Background", "Data\\Terrain+Buildings\\Grass.PNG"))
	{
		HAPI.UserMessage("ERROR", "LOADING BACKGROUND TEXTURE");
		return;
	}

	//Game Loop
	while (HAPI.Update())
	{
		//Vis.SettoColour();
		Vis.SpriteGraphics("Background", 0, 0);

		for each (Entity* i in EntityList)
			i->Update(Vis,*this);
		
		if (DeadEnemies >= EnemyCount)
		{
			HAPI.UserMessage("You Have Killed All The Bandits!", "CONGRATULATIONS!");
			return;
			
		}

		else if (Player.GetHealth() <= 0)
		{
			HAPI.UserMessage("You Have Been Killed, The Castle will soon fall without you", "It's Over");
			return;
		}

		for (int x = 0; x < EntityList.size(); x++)
		{
			if (EntityList[x]->GetSide() != Side::Neutral)
			{
				for (int y = size_t (x+1); y < EntityList.size(); y++)
				{
					Entity* Entity1 = EntityList[x];
					Entity* Entity2 = EntityList[y];
					if (Entity1->GetIsAlive() && Entity2->GetIsAlive())
					{
						if (Entity1->GetSide() != Entity2->GetSide())
						{
							std::string Entity1Sprite = Entity1->GetCurrentSprite();
							Rectangle Ent1Rect = Vis.GetRectangle(Entity1Sprite);
							Ent1Rect.Translate(Entity1->GetPosX(), Entity1->GetPosY());
							Ent1Rect.ClipToOtherRect(ScreenRect);


							std::string Entity2Sprite = Entity2->GetCurrentSprite();
							Rectangle Ent2Rect = Vis.GetRectangle(Entity2Sprite);
							Ent2Rect.Translate(Entity2->GetPosX(), Entity2->GetPosY());
							Ent2Rect.ClipToOtherRect(ScreenRect);

							int Entity2PosX = Entity2->GetPosX();
							int Entity2PosY = Entity2->GetPosY();


							if ((Ent1Rect.RightFace < Ent2Rect.LeftFace || Ent1Rect.RightFace > Ent2Rect.RightFace) || (Ent1Rect.BottomFace<Ent2Rect.TopFace || Ent1Rect.TopFace>Ent2Rect.BottomFace))
							{
								//No Colison
							}
							else
							{
								if (Entity1->GetSide() != Side::Neutral && Entity2->GetSide() != Side::Neutral) //Neutral Entity Check
								{
									if (Entity1->GetSide() != Entity2->GetSide())//Enemy Side Check
									{

										Side Ent1Side = Entity1->GetSide();
										bool Ent2IsAlive = Entity2->GetIsAlive();
										Type Ent1Type = Entity1->GetType();

										if (Entity1->GetType() == Type::Arrow)
										{
											if (Entity2->GetHealth() <= 0)
											{

											}
											else
											{
												Entity2->SetHealth(10);
												Entity1->SetIsAlive(false);
												
											}
											
										}
										else if (Entity2->GetType() == Type::Arrow)
										{
											if (Entity1->GetHealth() <= 0)
											{

											}
											else
											{
												Entity1->SetHealth(10);
												Entity2->SetIsAlive(false);
											
											}
										}

									}
								}


							}
						}
					}
					
				}
			}
		}

	}
}




