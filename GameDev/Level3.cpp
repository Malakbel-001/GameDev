#include "Level3.h"

Level3::Level3(int _lvlWidth, int _lvlHeight, PlayState* play) : Level(_lvlWidth, _lvlHeight, play)
{
	levelId = 3;
}

void Level3::Init(BehaviourFactory* bf)
{
	backgroundPath = "level1.jpg";
	entityFactory = new EntityFactory(*world, actors, entities, bf, this, drawableContainer, moveableContainer);

	entityFactory->CreateEntity(0, 570, 1075, 30, EntityType::DESERTFLOOR);
	entityFactory->CreateActor(700, 450, EntityType::MECH);
}

Level* Level3::CreateLevel()
{
	return new Level3(lvlWidth, lvlHeight, playState);
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



Level3::~Level3()
{
}
