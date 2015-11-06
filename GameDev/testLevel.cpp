#include "TestLevel.h"

TestLevel::TestLevel(int _lvlWidth, int _lvlHeight,PlayState* play)
	: Level(_lvlWidth, _lvlHeight,play)
{
	this->tileLoader = new TileLoader(this);

}

void TestLevel::Init(BehaviourFactory* bf){
	
	entityFactory = new EntityFactory(*world, bf, drawableContainer);
	entityFactory->CreateEntity(0, 400, 255, 140, EntityType::GROUND);
	entityFactory->CreateEntity(255, 400, 255, 140, EntityType::GROUND);
	entityFactory->CreateEntity(505, 400, 255, 140, EntityType::GROUND);
	entityFactory->CreateEntity(765, 400, 255, 140, EntityType::GROUND);
	entityFactory->CreateEntity(300, 100, 137, 140, EntityType::GROUND2);


}

TestLevel::~TestLevel() {
//	delete tileLoader;
}

Level* TestLevel::CreateLevel()
{

	return new TestLevel(lvlWidth, lvlHeight, playState);
}
void TestLevel::Cleanup() { }


void TestLevel::HandleEvents(SDL_Event mainEvent) { }

