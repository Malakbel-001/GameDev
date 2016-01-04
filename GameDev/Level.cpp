#include "Level.h"
#include "PlayState.h"

Level::Level(int _lvlWidth, int _lvlHeight, PlayState* ps)
	: lvlWidth(_lvlWidth), lvlHeight(_lvlHeight), playState(ps)
{
	entityFactory = nullptr;
	player = nullptr;
	startXpos = 100;
	startYpos = 10;
	actors = new std::vector<Actor*>();
	world = new b2World(b2Vec2(0.0, static_cast<float>(1.81)));
	contact = new ContactListener();
	world->SetContactListener(contact);
	drawableContainer = new DrawableContainer();
	moveableContainer = new MoveableContainer();
	entities = new std::vector<Entity*>();


}

void Level::Init(BehaviourFactory* bf)
{
	cout << " jajaa ";
}

b2World* Level::GetWorld()
{
	return world;
}

void Level::Update(float dt)
{
	
	float _x = 1;
	float _y = 10;
	float Ratio = _x / _y;
	

	world->Step((dt / 100), 5, 5);
	if (player->GetYpos() > lvlHeight || player->IsDead())
	{

		GameOver();
	}
	else{
		
		for (int x = 0; actors->size() > x; x++)
		{
			if (actors->operator[](x)->IsDead()){
				if (actors->operator[](x)->GetType() == EntityType::PLANTBOSS)
				{
					Victory();

				}

				if (actors->operator[](x)->GetType() == EntityType::PLANT){
					float z = actors->operator[](x)->GetBody()->GetPosition().x /Ratio;
					float y = (actors->operator[](x)->GetBody()->GetPosition().y - 4) / Ratio;
					entityFactory->CreateActor(-10, 1, z,y, 7,7, EntityType::HEALTH);
					entityFactory->CreateActor(-10, 1, z, y, 7, 7, EntityType::HEALTH);
					entityFactory->CreateActor(-10, 1, z, y,7,7, EntityType::HEALTH);
					entityFactory->CreateActor(0, 1, z, y, 50,17, EntityType::AMMO);
			
				}
				player->AddScore(actors->operator[](x)->GetScore());
				world->DestroyBody(actors->operator[](x)->GetBody());
				drawableContainer->Delete(actors->operator[](x));
				moveableContainer->Delete(actors->operator[](x));
				delete actors->operator[](x);
				actors->operator[](x) = nullptr;
				actors->erase(actors->begin() + x);
			
			}
			else if (actors->operator[](x)->GetType() == EntityType::BULLET){
				actors->operator[](x)->GetBody()->SetLinearVelocity(actors->operator[](x)->GetDirection());
			}
		}
	}
}

#pragma region Get, Set
Player* Level::SetPlayerPosition(Player* _player, float x, float y) {
	if (!_player->GetBody() != NULL) {
		player = dynamic_cast<Player*>(entityFactory->CreateActor(0, 100, x, y, 15, 35, EntityType::PLAYER));
	}
	else {
		player = entityFactory->CreatePlayer(0, 100, x, y, 15, 35, _player);
		player->SetNumFootContacts(0);
		player->DeletePrevProp();
		
	}
	return player;
}
Player* Level::GetPlayer()
{
	return player;
}
DrawableContainer* Level::GetDrawableContainer()
{
	return drawableContainer;
}

MoveableContainer* Level::GetMoveableContainer()
{
	return moveableContainer;
}
#pragma endregion Get, Set

Level::~Level()
{
	delete contact;
	delete world;
	delete drawableContainer;
	if (entityFactory){
		delete entityFactory;
	}
	for each (Actor* var in *actors)
	{
		if (var){
			delete var;
			var = nullptr;
		}
	}
	delete actors;
	for each (Entity* var in *entities)
	{
		if (var){
			delete var;
			var = nullptr;
		}
	}
	delete entities;

	
}
void Level::SetLvlWidth(int _lvlWidth)
{
	this->lvlWidth = _lvlWidth;
}

void Level::SetLvlHeight(int _lvlHeight)
{
	this->lvlHeight = _lvlHeight;
}

SDL_Texture* Level::GetTileSheet()
{
	return this->tileSheet;
}

int Level::GetLvlHeight()
{
	return this->lvlHeight;
}

EntityFactory* Level::GetEntityFactory(){
	return entityFactory;
}

int Level::GetLvlWidth()
{
	return this->lvlWidth;
}

void Level::GameOver()
{
	playState->GameOver();
}

void Level::Victory()
{
	playState->Victory();
}

void Level::EnterVehicle()
{
	if (player->GetVehicle())
	{		
		auto vehicle = player->GetVehicle();

		for each (Weapon* var in player->GetWeapons())
		{
			drawableContainer->Delete(var);
			moveableContainer->Delete(var);
		}

		drawableContainer->Delete(player);		
		moveableContainer->Delete(player);
		player->setBody(vehicle->GetBody());
		player = vehicle;

		Weapon* wep = entityFactory->CreateWeapon(0, 0, EntityType::CANNON);
		wep->Pickup(player, b2Vec2(1000, 0));
		player->AddWeapon(wep);
		//drawableContainer->Delete(player->GetCurrentWeapon());
		
		////dynamic_cast<Vehicle*>(player->GetVehicle())->SetPassenger(player);
		//player->setBody(player->GetVehicle()->GetBody());
		//player->SetState(EntityState::IDLE);
	}
}