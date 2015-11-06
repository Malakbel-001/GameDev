#include "TestLevel.h"

TestLevel::TestLevel(int _lvlWidth, int _lvlHeight)
	: Level(_lvlWidth, _lvlHeight)
{
	this->tileLoader = new TileLoader(this);

}

void TestLevel::Init(BehaviourFactory* bf){
	
	entityFactory = new EntityFactory(*world, bf, drawableContainer);
	//obstacles
	entityFactory->CreateEntity(363, 450, 137, 120, EntityType::GROUND2);
	entityFactory->CreateEntity(750, 450, 255, 120, EntityType::GROUND);
	//bar---
	entityFactory->CreateEntity(1500, 300, 255, 10, EntityType::BAR);
	//bar---
	entityFactory->CreateEntity(2000, 300, 255, 140, EntityType::GROUND);
	entityFactory->CreateEntity(2250, 300, 137, 140, EntityType::GROUND2);
	entityFactory->CreateEntity(2750, 450, 255, 120, EntityType::GROUND);
	entityFactory->CreateEntity(3000, 450, 255, 120, EntityType::GROUND);
	//bar---
	entityFactory->CreateEntity(3500, 300, 255, 10, EntityType::BAR);
	//bar---
	//bar---
	entityFactory->CreateEntity(4000, 300, 255, 10, EntityType::BAR);
	//bar---
	entityFactory->CreateEntity(4363, 450, 137, 120, EntityType::GROUND2);
	entityFactory->CreateEntity(4500, 450, 255, 120, EntityType::GROUND);
	//ground
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


}

TestLevel::~TestLevel() {
//	delete tileLoader;
}

void TestLevel::Cleanup() { }


void TestLevel::HandleEvents(SDL_Event mainEvent) { }

