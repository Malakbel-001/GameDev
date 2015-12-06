#include "TestLevel.h"

TestLevel::TestLevel(int _lvlWidth, int _lvlHeight, PlayState* play)
	: Level(_lvlWidth, _lvlHeight, play)
{
	levelId = 1;
}

void TestLevel::Init(BehaviourFactory* bf)
{
	backgroundPath = "level1.jpg"; //todo delete

	//background
	parallaxBackground = bf->CreateEmptyParallaxBehaviour();
	LoadParallaxBackgroundSettings();

	//Entities Initialization
	entityFactory = new EntityFactory(*world, actors,entities, bf, drawableContainer);

	//obstacles--------------
//	entityFactory->CreateWeapon(0, 500, EntityType::WEAPON);
//	entityFactory->CreateActor(-10, 1, 300, 100, 10, 10, EntityType::HEALTH);
	
	entityFactory->CreateEntity(363, 450, 137, 120, EntityType::GROUND2);
	entityFactory->CreateEntity(750, 450, 250, 120, EntityType::GROUND);
	entityFactory->CreateEntity(1500, 450, 250, 10, EntityType::BAR);
	entityFactory->CreateEntity(2000, 300, 137, 120, EntityType::GROUND2);
	entityFactory->CreateEntity(2113, 300, 250, 120, EntityType::GROUND);
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

	entityFactory->CreateActor(800, 450, EntityType::PLANT);

	entityFactory->CreateActor(900, 450, EntityType::PLANT);
	entityFactory->CreateActor(1200, 300, EntityType::PLANT);
	entityFactory->CreateActor(1300, 300, EntityType::PLANT);

	// enemies on top------------------------------------------------
	entityFactory->CreateActor(2050, 300, EntityType::PLANT);
	entityFactory->CreateActor(2150, 300, EntityType::PLANT);
	entityFactory->CreateActor(2250, 300, EntityType::PLANT);

	// enemies on below------------------------------------------------
	entityFactory->CreateActor(2050, 600, EntityType::PLANT);
	entityFactory->CreateActor(2150, 600, EntityType::PLANT);
	entityFactory->CreateActor(2250, 400, EntityType::PLANT);

	entityFactory->CreateActor(2900, 300, EntityType::PLANT);
	entityFactory->CreateActor(3000, 300, EntityType::PLANT);

	entityFactory->CreateActor(3500, 300, EntityType::PLANT);
	entityFactory->CreateActor(3600, 300, EntityType::PLANT);
	entityFactory->CreateActor(3700, 0, EntityType::PLANT);
	entityFactory->CreateActor(3800, 0, EntityType::PLANT);
	entityFactory->CreateActor(3900, 0, EntityType::PLANT);
	entityFactory->CreateActor(4000, 0, EntityType::PLANT);
	entityFactory->CreateActor(4100, 0, EntityType::PLANT);
	entityFactory->CreateActor(4200, 0, EntityType::PLANT);

	// Boss enemy
	entityFactory->CreateActor(4500, 0, EntityType::PLANTBOSS);
}

Level* TestLevel::CreateLevel()
{
	return new TestLevel(lvlWidth, lvlHeight, playState);
}

void TestLevel::LoadParallaxBackgroundSettings() {
	parallaxBackground->SetLayer("Resources/backgrounds/game/level1/parallax-forest-back-trees.png", 0, 0.5);
	parallaxBackground->SetLayer("Resources/backgrounds/game/level1/parallax-forest-lights.png", 0, 0);
	parallaxBackground->SetLayer("Resources/backgrounds/game/level1/parallax-forest-middle-trees.png", 0, 0.8);
	parallaxBackground->SetLayer("Resources/backgrounds/game/level1/parallax-forest-front-trees.png", 0, 1);
}

Player* TestLevel::SetPlayer(Player* _player) {
	player = Level::SetPlayerPosition(_player, 20, 100);

	Weapon* wep = entityFactory->CreateWeapon(0, 0, EntityType::WEAPON);
	wep->Pickup(player, b2Vec2(1000, 0));
	Weapon* shot = entityFactory->CreateWeapon(0, 0, EntityType::SHOTGUN);
	shot->Pickup(player, b2Vec2(1000, 0));
	player->AddWeapon(wep);
	player->AddWeapon(shot);

	return player;
}

ParallaxBackground* TestLevel::GetParallaxBackGround() {
	return parallaxBackground;
}

void TestLevel::Cleanup() { }

void TestLevel::HandleEvents(SDL_Event mainEvent) { }

TestLevel::~TestLevel() { }