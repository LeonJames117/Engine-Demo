#pragma once
#include <HAPI_lib.h>
#include <unordered_map>
class Entity;
class Enity_Player;
class Graphics;
class Sprite;
using namespace HAPISPACE;
class World
{
public:
	void Run();
	void ShootArrow(Entity* Caster);
	Entity* GetPlayer() { return WorldPlayer; }
	int DeadEnemies = 0;
private:
	int EnemyCount;
	int ArrowStart;
	Entity* WorldPlayer;
	std::vector <Entity*> EntityList;
};

