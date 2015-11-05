#include "TestLevel.h"

TestLevel::TestLevel(int _lvlWidth, int _lvlHeight)
	: Level(_lvlWidth, _lvlHeight)
{
	this->tileLoader = new TileLoader(this);

}

void TestLevel::Init(BehaviourFactory* bf){
	entityFactory = new EntityFactory(*world, bf, drawableContainer);
	entityFactory->CreateEntity(0, 400, 255, 140, EntityType::GROUND);
	entityFactory->CreateEntity(255, 400, 255, 140, EntityType::GROUND);
	//entityFactory->CreateEntity(510, 400, 255, 15, EntityType::GROUND);
	//entityFactory->CreateEntity(765, 400, 255, 15, EntityType::GROUND);
	entityFactory->CreateEntity(300, 270, 255, 140, EntityType::GROUND);

}

TestLevel::~TestLevel() {
	delete tileLoader;
}

void TestLevel::Cleanup() { }


void TestLevel::HandleEvents(SDL_Event mainEvent) { }


