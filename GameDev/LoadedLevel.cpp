#include "LoadedLevel.h"


LoadedLevel::LoadedLevel(int _lvlWidth, int _lvlHeight, b2Vec2 vec)
	: Level(_lvlWidth, _lvlHeight, vec)
{

}

LoadedLevel::~LoadedLevel()
{
}
Player* LoadedLevel::SetPlayer(Player* _player){
	currentPlayer = Level::SetPlayerPosition(_player, 20, 100);

	Weapon* wep = entityFactory->CreateWeapon(0, 0, EntityType::WEAPON);
	wep->Pickup(currentPlayer, b2Vec2(1000, 0));
	Weapon* shot = entityFactory->CreateWeapon(0, 0, EntityType::SHOTGUN);
	shot->Pickup(currentPlayer, b2Vec2(100, 0));
	currentPlayer->AddWeapon(wep);
	currentPlayer->AddWeapon(shot);

	return currentPlayer;
}
Level* LoadedLevel::CreateLevel(){
	return new LoadedLevel(lvlWidth, lvlHeight,world->GetGravity());
}


void LoadedLevel::CreateMap() {
	//obstacles--------------
	//	entityFactory->CreateWeapon(0, 500, EntityType::WEAPON);
	//	entityFactory->CreateActor(-10, 1, 300, 100, 10, 10, EntityType::HEALTH);

}

void LoadedLevel::CreateNPCs() {
	//enemies-----------------	


}

void LoadedLevel::CreateParallaxBackground(BehaviourFactory* bf) {
	parallaxBackground = bf->CreateEmptyParallaxBehaviour();
	parallaxBackground->SetLayer("Resources/backgrounds/game/level1/parallax-forest-back-trees.png", 0, 0.9f, 255);
	parallaxBackground->SetLayer("Resources/backgrounds/game/level1/parallax-forest-lights.png", 0, 0.7f, 120); //cool transparency feature
	parallaxBackground->SetLayer("Resources/backgrounds/game/level1/parallax-forest-middle-trees.png", 0, 1.2f, 255);
	parallaxBackground->SetLayer("Resources/backgrounds/game/level1/parallax-forest-front-trees.png", 0, 1.5f, 255);
}
