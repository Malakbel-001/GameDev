#include "TestLevel.h"

TestLevel::TestLevel(int _lvlWidth, int _lvlHeight, PlayState* play)
	: Level(_lvlWidth, _lvlHeight, play)
{
	this->tileLoader = new TileLoader(this);
}

void TestLevel::Init(BehaviourFactory* bf)
{

	entityFactory = new EntityFactory(*world, bf, drawableContainer);

	//obstacles--------------
	entityFactory->CreateEntity(363, 450, 137, 120, EntityType::GROUND2);
	entityFactory->CreateEntity(750, 450, 250, 120, EntityType::GROUND);
	entityFactory->CreateEntity(1500, 450, 250, 10, EntityType::BAR);
	entityFactory->CreateEntity(2000, 300, 137, 140, EntityType::GROUND2);
	entityFactory->CreateEntity(2113, 300, 250, 140, EntityType::GROUND);
	entityFactory->CreateEntity(2750, 450, 250, 120, EntityType::GROUND);
	entityFactory->CreateEntity(3000, 450, 250, 120, EntityType::GROUND);
	entityFactory->CreateEntity(3500, 450, 250, 10, EntityType::BAR);
	entityFactory->CreateEntity(4000, 450, 250, 10, EntityType::BAR);
	entityFactory->CreateEntity(4363, 450, 137, 120, EntityType::GROUND2);
	entityFactory->CreateEntity(4495, 450, 250, 120, EntityType::GROUND);

	//ground------------------
	entityFactory->CreateEntity(0, 570, 250, 140, EntityType::GROUND);
	entityFactory->CreateEntity(250, 570, 250, 140, EntityType::GROUND);
	entityFactory->CreateEntity(500, 570, 250, 140, EntityType::GROUND);
	entityFactory->CreateEntity(750, 570, 250, 140, EntityType::GROUND);

	entityFactory->CreateEntity(1000, 570, 250, 140, EntityType::GROUND);
	entityFactory->CreateEntity(1250, 570, 250, 140, EntityType::GROUND);
	entityFactory->CreateEntity(1500, 570, 250, 140, EntityType::GROUND);
	entityFactory->CreateEntity(1750, 570, 250, 140, EntityType::GROUND);
	entityFactory->CreateEntity(2000, 570, 250, 140, EntityType::GROUND);
	entityFactory->CreateEntity(2250, 570, 250, 140, EntityType::GROUND);
	entityFactory->CreateEntity(2500, 570, 250, 140, EntityType::GROUND);
	entityFactory->CreateEntity(2750, 570, 250, 140, EntityType::GROUND);
	entityFactory->CreateEntity(3000, 570, 250, 140, EntityType::GROUND);
	entityFactory->CreateEntity(3250, 570, 250, 140, EntityType::GROUND);
	entityFactory->CreateEntity(3500, 570, 250, 140, EntityType::GROUND);
	entityFactory->CreateEntity(3750, 570, 250, 140, EntityType::GROUND);
	entityFactory->CreateEntity(4000, 570, 250, 140, EntityType::GROUND);
	entityFactory->CreateEntity(4250, 570, 250, 140, EntityType::GROUND);
	entityFactory->CreateEntity(4500, 570, 250, 140, EntityType::GROUND);
	entityFactory->CreateEntity(4750, 570, 250, 140, EntityType::GROUND);
	//enemies-----------------
	
	entityFactory->CreateEntity(800, 450, 40, 45, EntityType::PLANT);
	entityFactory->CreateEntity(900, 450, 40, 45, EntityType::PLANT);
	entityFactory->CreateEntity(1200, 300, 40, 45, EntityType::PLANT);
	entityFactory->CreateEntity(1300, 300, 40, 45, EntityType::PLANT);

	// enemies on top------------------------------------------------
	entityFactory->CreateEntity(2050, 300, 40, 45, EntityType::PLANT);
	entityFactory->CreateEntity(2150, 300, 40, 45, EntityType::PLANT);
	entityFactory->CreateEntity(2250, 300, 40, 45, EntityType::PLANT);

	// enemies on below------------------------------------------------
	entityFactory->CreateEntity(2050, 600, 40, 45, EntityType::PLANT);
	entityFactory->CreateEntity(2150, 600, 40, 45, EntityType::PLANT);
	entityFactory->CreateEntity(2250, 400, 40, 45, EntityType::PLANT);

	entityFactory->CreateEntity(2900, 300, 40, 45, EntityType::PLANT);
	entityFactory->CreateEntity(3000, 300, 40, 45, EntityType::PLANT);

	entityFactory->CreateEntity(3500, 300, 40, 45, EntityType::PLANT);
	entityFactory->CreateEntity(3600, 300, 40, 45, EntityType::PLANT);
	entityFactory->CreateEntity(3700, 0, 40, 45, EntityType::PLANT);
	entityFactory->CreateEntity(3800, 0, 40, 45, EntityType::PLANT);
	entityFactory->CreateEntity(3900, 0, 40, 45, EntityType::PLANT);
	entityFactory->CreateEntity(4000, 0, 40, 45, EntityType::PLANT);
	entityFactory->CreateEntity(4100, 0, 40, 45, EntityType::PLANT);
	entityFactory->CreateEntity(4200, 0, 40, 45, EntityType::PLANT);
}

TestLevel::~TestLevel()
{
	delete tileLoader;
}

Level* TestLevel::CreateLevel()
{

	return new TestLevel(lvlWidth, lvlHeight, playState);
}
void TestLevel::Cleanup() {}


void TestLevel::HandleEvents(SDL_Event mainEvent) { }
