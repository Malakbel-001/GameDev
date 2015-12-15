#include "Level2.h"


Level2::Level2(int _lvlWidth, int _lvlHeight, PlayState* play) : Level(_lvlWidth, _lvlHeight, play)
{
	levelId = 2;
}

void Level2::CreateMap() {
	//obstacles--------------------
	entityFactory->CreateEntity(1375, 450, 250, 120, EntityType::GROUNDLVL2);
	entityFactory->CreateEntity(1625, 450, 250, 120, EntityType::GROUNDLVL2);
	entityFactory->CreateEntity(1875, 450, 250, 120, EntityType::GROUNDLVL2);
	entityFactory->CreateEntity(4600, 350, 250, 250, EntityType::GROUND2LVL2);
	entityFactory->CreateEntity(4600, 210, 250, 120, EntityType::GROUNDLVL2);

	entityFactory->CreateEntity(4250, 90, 250, 250, EntityType::GROUND2LVL2);
	entityFactory->CreateEntity(4250, -50, 250, 120, EntityType::GROUNDLVL2);

	entityFactory->CreateEntity(4500, -30, 250, 120, EntityType::GROUNDLVL2);
	entityFactory->CreateEntity(4750, -30, 250, 120, EntityType::GROUNDLVL2);
	entityFactory->CreateEntity(5250, 450, 250, 120, EntityType::GROUNDLVL2);
	entityFactory->CreateEntity(5250, 365, 250, 250, EntityType::GROUND2LVL2);
	entityFactory->CreateEntity(5250, 110, 250, 250, EntityType::GROUND2LVL2);
	entityFactory->CreateEntity(5000, -30, 250, 120, EntityType::GROUNDLVL2);
	entityFactory->CreateEntity(5250, -30, 250, 120, EntityType::GROUNDLVL2);

	//0,363
	//256*269
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
	entityFactory->CreateEntity(3000, 570, 250, 140, EntityType::GROUNDLVL2);
	entityFactory->CreateEntity(3250, 570, 250, 140, EntityType::GROUNDLVL2);
	entityFactory->CreateEntity(3500, 570, 250, 140, EntityType::GROUNDLVL2);
	entityFactory->CreateEntity(3750, 570, 250, 140, EntityType::GROUNDLVL2);
	entityFactory->CreateEntity(4000, 570, 250, 140, EntityType::GROUNDLVL2);
	entityFactory->CreateEntity(4250, 570, 250, 140, EntityType::GROUNDLVL2);
	entityFactory->CreateEntity(4500, 570, 250, 140, EntityType::GROUNDLVL2);
	entityFactory->CreateEntity(4750, 570, 250, 140, EntityType::GROUNDLVL2);
	entityFactory->CreateEntity(5000, 570, 250, 140, EntityType::GROUNDLVL2);
	entityFactory->CreateEntity(5250, 570, 250, 140, EntityType::GROUNDLVL2);
}

void Level2::CreateNPCs() {
	//enemy pinguin
	/*entityFactory->CreateActor(400, 450, EntityType::PINGUIN);
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
	//enemy yeti
	entityFactory->CreateActor(800, 450, EntityType::SNOWMAN);
	entityFactory->CreateActor(850, 450, EntityType::SNOWMAN);
	entityFactory->CreateActor(900, 450, EntityType::SNOWMAN);
	entityFactory->CreateActor(950, 450, EntityType::SNOWMAN);
	entityFactory->CreateActor(1170, 450, EntityType::SNOWMAN);
	entityFactory->CreateActor(1300, 450, EntityType::SNOWMAN);
	entityFactory->CreateActor(1370, 450, EntityType::SNOWMAN);
	entityFactory->CreateActor(3000, 450, EntityType::SNOWMAN);
	entityFactory->CreateActor(3050, 450, EntityType::SNOWMAN);
	entityFactory->CreateActor(3300, 450, EntityType::SNOWMAN);
	entityFactory->CreateActor(3420, 450, EntityType::SNOWMAN);*/
	//boss
	entityFactory->CreateActor(5000, 350, EntityType::SNOWBOSS);
	//entityFactory->CreateActor(200, 0, EntityType::SNOWBOSS);
}

void Level2::CreateParallaxBackground(BehaviourFactory* bf) {
	parallaxBackground = bf->CreateEmptyParallaxBehaviour();
	parallaxBackground->SetLayer("Resources/backgrounds/game/level2/parallax-mountain-bg.png", 0, 0, 255);
	parallaxBackground->SetLayer("Resources/backgrounds/game/level2/parallax-mountain-mountain-far.png", 0, 0.5f, 255);
	parallaxBackground->SetLayer("Resources/backgrounds/game/level2/parallax-mountain-mountains.png", 0, 1, 255);
	parallaxBackground->SetLayer("Resources/backgrounds/game/level2/parallax-mountain-trees.png", 0, 2, 255);
	parallaxBackground->SetLayer("Resources/backgrounds/game/level2/parallax-mountain-foreground-trees.png", 0, 3, 255);
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


Level2::~Level2() { }
void Level2::Cleanup() { }
void Level2::HandleEvents(SDL_Event mainEvent) { }