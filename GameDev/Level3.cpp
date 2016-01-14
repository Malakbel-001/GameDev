#include "Level3.h"

Level3::Level3(int _lvlWidth, int _lvlHeight) : Level(_lvlWidth, _lvlHeight)
{
	levelId = 3;
	bossCount = 0;
}

void Level3::CreateMap() {
	entityFactory->CreateEntity(0, 400, 135, 10, EntityType::SMALLDESERTFLOOR);
	entityFactory->CreateEntity(135, 400, 135, 10, EntityType::SMALLDESERTFLOOR);
	entityFactory->CreateEntity(270, 400, 135, 10, EntityType::SMALLDESERTFLOOR);
	entityFactory->CreateEntity(500, 280, 135, 10, EntityType::SMALLDESERTFLOOR);

	entityFactory->CreateEntity(700, 250, 135, 10, EntityType::SMALLDESERTFLOOR);
	entityFactory->CreateEntity(1000, 250, 135, 10, EntityType::SMALLDESERTFLOOR);
	entityFactory->CreateEntity(1350, 250, 135, 10, EntityType::SMALLDESERTFLOOR);
	entityFactory->CreateEntity(1700, 250, 135, 10, EntityType::SMALLDESERTFLOOR);
	entityFactory->CreateEntity(2050, 250, 135, 10, EntityType::SMALLDESERTFLOOR);
	entityFactory->CreateEntity(0, 570, 1075, 30, EntityType::DESERTFLOOR);
	entityFactory->CreateEntity(1075, 570, 1075, 30, EntityType::DESERTFLOOR);
}

void Level3::CreateNPCs() {
	entityFactory->CreateActor(120, 350, EntityType::MECH);

	entityFactory->CreateActor(970, 150, EntityType::APC);
	bossCount++;

	entityFactory->CreateActor(1220, 150, EntityType::APC);
	bossCount++;

	entityFactory->CreateActor(1670, 150, EntityType::APC);
	bossCount++;

	entityFactory->CreateActor(2020, 150, EntityType::APC);
	bossCount++;
	//entityFactory->CreateActor(1200, 450, EntityType::MINIGUNNER);
}

void Level3::CreateParallaxBackground(BehaviourFactory* bf) {
	parallaxBackground = bf->CreateEmptyParallaxBehaviour();
	parallaxBackground->SetLayer("Resources/backgrounds/game/level3/desert-bg.png", 0, 0.9f, 255);
	parallaxBackground->SetLayer("Resources/backgrounds/game/level3/desert-foreground.png", 0, 3, 255);
}

Level* Level3::CreateLevel()
{
	return new Level3(lvlWidth, lvlHeight);
}

Player* Level3::SetPlayer(Player* _player) {
	currentPlayer = Level::SetPlayerPosition(_player, 20, 100);

	Weapon* wep = entityFactory->CreateWeapon(0, 0, EntityType::WEAPON);
	wep->Pickup(currentPlayer, b2Vec2(1000, 0));
	Weapon* shot = entityFactory->CreateWeapon(0, 0, EntityType::SHOTGUN);
	shot->Pickup(currentPlayer, b2Vec2(1000, 0));
	currentPlayer->AddWeapon(wep);
	currentPlayer->AddWeapon(shot);

	return currentPlayer;
}
void Level3::Cleanup() {}


void Level3::HandleEvents(SDL_Event mainEvent) { }

//void Level3::LoadParallaxBackgroundSettings() {
//	parallaxBackground->SetLayer("Resources/backgrounds/game/level1/parallax-forest-back-trees.png", 0, 0.9f, 255);
//	parallaxBackground->SetLayer("Resources/backgrounds/game/level1/parallax-forest-lights.png", 0, 0.7f, 120); //cool transparency feature
//	parallaxBackground->SetLayer("Resources/backgrounds/game/level1/parallax-forest-middle-trees.png", 0, 1.2f, 255);
//	parallaxBackground->SetLayer("Resources/backgrounds/game/level1/parallax-forest-front-trees.png", 0, 1.5f, 255);
//}

ParallaxBackground* Level3::GetParallaxBackGround() {
	return parallaxBackground;
}

int Level3::GetBossCount()
{
	return bossCount;
}

void Level3::DecrementBossCount()
{
	bossCount--;
}

Level3::~Level3()
{
}
