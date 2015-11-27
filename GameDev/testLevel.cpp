#include "TestLevel.h"

TestLevel::TestLevel(int _lvlWidth, int _lvlHeight, PlayState* play)
	: Level(_lvlWidth, _lvlHeight, play)
{

}

void TestLevel::Init(BehaviourFactory* bf)
{

	entityFactory = new EntityFactory(*world, actors, bf, drawableContainer);

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
	
	entityFactory->CreateActor(10, 50, 800, 450, 40, 45, EntityType::PLANT); //TEMP!!!!!!!!
	entityFactory->CreateActor(1000, 50, 900, 450, 40, 45, EntityType::PLANT);
	entityFactory->CreateActor(1000, 50, 1200, 300, 40, 45, EntityType::PLANT);
	entityFactory->CreateActor(1000, 50, 1300, 300, 40, 45, EntityType::PLANT);

	// enemies on top------------------------------------------------
	entityFactory->CreateActor(1000, 50, 2050, 300, 40, 45, EntityType::PLANT);
	entityFactory->CreateActor(1000, 50, 2150, 300, 40, 45, EntityType::PLANT);
	entityFactory->CreateActor(1000, 50, 2250, 300, 40, 45, EntityType::PLANT);

	// enemies on below------------------------------------------------
	entityFactory->CreateActor(1000, 50, 2050, 600, 40, 45, EntityType::PLANT);
	entityFactory->CreateActor(1000, 50, 2150, 600, 40, 45, EntityType::PLANT);
	entityFactory->CreateActor(1000, 50, 2250, 400, 40, 45, EntityType::PLANT);

	entityFactory->CreateActor(1000, 50, 2900, 300, 40, 45, EntityType::PLANT);
	entityFactory->CreateActor(1000, 50, 3000, 300, 40, 45, EntityType::PLANT);

	entityFactory->CreateActor(1000, 50, 3500, 300, 40, 45, EntityType::PLANT);
	entityFactory->CreateActor(1000, 50, 3600, 300, 40, 45, EntityType::PLANT);
	entityFactory->CreateActor(1000, 50, 3700, 0, 40, 45, EntityType::PLANT);
	entityFactory->CreateActor(1000, 50, 3800, 0, 40, 45, EntityType::PLANT);
	entityFactory->CreateActor(1000, 50, 3900, 0, 40, 45, EntityType::PLANT);
	entityFactory->CreateActor(1000, 50, 4000, 0, 40, 45, EntityType::PLANT);
	entityFactory->CreateActor(1000, 50, 4100, 0, 40, 45, EntityType::PLANT);
	entityFactory->CreateActor(1000, 50, 4200, 0, 40, 45, EntityType::PLANT);

	// Boss enemy
	entityFactory->CreateActor(1000, 500, 4500, 0, 100, 100, EntityType::PLANTBOSS);
}

TestLevel::~TestLevel()
{

}

Level* TestLevel::CreateLevel()
{

	return new TestLevel(lvlWidth, lvlHeight, playState);
}
void TestLevel::Cleanup() {}


void TestLevel::HandleEvents(SDL_Event mainEvent) { }
