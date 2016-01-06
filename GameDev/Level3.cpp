#include "Level3.h"

Level3::Level3(int _lvlWidth, int _lvlHeight) : Level(_lvlWidth, _lvlHeight)
{
	levelId = 3;
}

void Level3::CreateMap() {
	entityFactory->CreateEntity(0, 570, 1075, 30, EntityType::DESERTFLOOR);
	entityFactory->CreateEntity(1075, 570, 1075, 30, EntityType::DESERTFLOOR);
}

void Level3::CreateNPCs() {
	entityFactory->CreateActor(700, 450, EntityType::MECH);
	entityFactory->CreateActor(1400, 450, EntityType::APC);
	//entityFactory->CreateActor(1200, 450, EntityType::MINIGUNNER);
}

void Level3::CreateParallaxBackground(BehaviourFactory* bf) {
	parallaxBackground = bf->CreateEmptyParallaxBehaviour();
	parallaxBackground->SetLayer("Resources/backgrounds/game/level2/parallax-mountain-bg.png", 0, 0, 255);
	parallaxBackground->SetLayer("Resources/backgrounds/game/level2/parallax-mountain-mountain-far.png", 0, 0.5f, 255);
	parallaxBackground->SetLayer("Resources/backgrounds/game/level2/parallax-mountain-mountains.png", 0, 1, 255);
	parallaxBackground->SetLayer("Resources/backgrounds/game/level2/parallax-mountain-trees.png", 0, 2, 255);
	parallaxBackground->SetLayer("Resources/backgrounds/game/level2/parallax-mountain-foreground-trees.png", 0, 3, 255);
}

Level* Level3::CreateLevel()
{
	return new Level3(lvlWidth, lvlHeight);
}

Player* Level3::SetPlayer(Player* _player) {
	player = Level::SetPlayerPosition(_player, 20, 100);

	Weapon* wep = entityFactory->CreateWeapon(0, 0, EntityType::WEAPON);
	wep->Pickup(player, b2Vec2(1000, 0));
	Weapon* shot = entityFactory->CreateWeapon(0, 0, EntityType::SHOTGUN);
	shot->Pickup(player, b2Vec2(1000, 0));
	player->AddWeapon(wep);
	player->AddWeapon(shot);

	return player;
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


Level3::~Level3()
{
}
