#include "Level2.h"


Level2::Level2(int _lvlWidth, int _lvlHeight, PlayState* play) : Level(_lvlWidth, _lvlHeight, play)
{
	levelId = 2;
}

void Level2::Init(BehaviourFactory* bf)
{
	backgroundPath = "level2.jpg";
	entityFactory = new EntityFactory(*world, actors, bf, drawableContainer);
	//obstacles--------------------
	entityFactory->CreateEntity(1375, 450, 250, 120, EntityType::GROUNDLVL2);
	entityFactory->CreateEntity(1625, 450, 250, 120, EntityType::GROUNDLVL2);
	entityFactory->CreateEntity(1875, 450, 250, 120, EntityType::GROUNDLVL2);
	//ground---------------------
	entityFactory->CreateEntity(0, 570, 250, 140, EntityType::GROUNDLVL2);
	entityFactory->CreateEntity(250, 570, 250, 140, EntityType::GROUNDLVL2);
	entityFactory->CreateEntity(500, 570, 250, 140, EntityType::GROUNDLVL2);
	entityFactory->CreateEntity(750, 570, 250, 140, EntityType::GROUNDLVL2);
	entityFactory->CreateEntity(1000, 570, 250, 140, EntityType::GROUNDLVL2);
	entityFactory->CreateEntity(1250, 570, 250, 140, EntityType::GROUNDLVL2);
	entityFactory->CreateEntity(1500, 570, 250, 140, EntityType::GROUNDLVL2);
	entityFactory->CreateEntity(1750, 570, 250, 140, EntityType::GROUNDLVL2);
	entityFactory->CreateEntity(2000, 570, 250, 140, EntityType::GROUNDLVL2);
	entityFactory->CreateEntity(2250, 570, 250, 140, EntityType::GROUNDLVL2);
	entityFactory->CreateEntity(2500, 570, 250, 140, EntityType::GROUNDLVL2);
	entityFactory->CreateEntity(2750, 570, 250, 140, EntityType::GROUNDLVL2);
	entityFactory->CreateEntity(3000, 570, 250, 140, EntityType::GROUNDLVL2);
	entityFactory->CreateEntity(3250, 570, 250, 140, EntityType::GROUNDLVL2);
	//enemy
	entityFactory->CreateActor(400, 450, EntityType::PINGUIN);
	entityFactory->CreateActor(450, 450, EntityType::PINGUIN);
	entityFactory->CreateActor(500, 450, EntityType::PINGUIN);
	entityFactory->CreateActor(550, 450, EntityType::PINGUIN);
	entityFactory->CreateActor(1000, 450, EntityType::PINGUIN);
	entityFactory->CreateActor(1070, 450, EntityType::PINGUIN);
	entityFactory->CreateActor(1200, 450, EntityType::PINGUIN);
	entityFactory->CreateActor(1500, 450, EntityType::PINGUIN);
	entityFactory->CreateActor(1550, 450, EntityType::PINGUIN);
	entityFactory->CreateActor(2000, 450, EntityType::PINGUIN);
	entityFactory->CreateActor(2300, 450, EntityType::PINGUIN);
	entityFactory->CreateActor(2500, 450, EntityType::PINGUIN);
	entityFactory->CreateActor(2550, 450, EntityType::PINGUIN);
}

Level* Level2::CreateLevel()
{

	return new Level2(lvlWidth, lvlHeight, playState);
}
Player* Level2::SetPlayer(Player* _player) {
	player = Level::SetPlayerPosition(_player, 20, 100);

	Weapon* wep = entityFactory->CreateWeapon(0, 0, EntityType::WEAPON);
	wep->Pickup(player, b2Vec2(1000, 0));
	Weapon* shot = entityFactory->CreateWeapon(0, 0, EntityType::SHOTGUN);
	shot->Pickup(player, b2Vec2(1000, 0));
	player->AddWeapon(wep);
	player->AddWeapon(shot);

	return player;
}
void Level2::Cleanup() {}


void Level2::HandleEvents(SDL_Event mainEvent) { }


Level2::~Level2()
{
}
