#include "LoadedLevel.h"


LoadedLevel::LoadedLevel(int _lvlWidth, int _lvlHeight, b2Vec2 vec, PlayState* play)
	: Level(_lvlWidth, _lvlHeight, vec, play)
{

}

void LoadedLevel::Init(BehaviourFactory* bf){
	entityFactory = new EntityFactory(*world, actors, entities, bf, drawableContainer);


}

void LoadedLevel::AddEntity(Entity* ent){
	entities->push_back(ent);
}
void LoadedLevel::AddActor(Actor* act){
	actors->push_back(act);
}
LoadedLevel::~LoadedLevel()
{
}
Player* LoadedLevel::SetPlayer(Player* _player){
	player = Level::SetPlayerPosition(_player, 20, 100);

	Weapon* wep = entityFactory->CreateWeapon(0, 0, EntityType::WEAPON);
	wep->Pickup(player, b2Vec2(1000, 0));
	player->AddWeapon(wep);
	

	return player;

}
Level* LoadedLevel::CreateLevel(){
	return new LoadedLevel(lvlWidth, lvlHeight,world->GetGravity(), playState);
}