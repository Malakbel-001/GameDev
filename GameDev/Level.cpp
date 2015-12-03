#include "Level.h"
#include "PlayState.h"

Level::Level(int _lvlWidth, int _lvlHeight, PlayState* ps)
	: lvlWidth(_lvlWidth), lvlHeight(_lvlHeight), playState(ps)
{
	player = nullptr;
	startXpos = 100;
	startYpos = 10;
	actors = new std::vector<Actor*>();
	world = new b2World(b2Vec2(0.0, static_cast<float>(1.81)));
	world->SetContactListener(new ContactListener());
	drawableContainer = new DrawableContainer();



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
				delete actors->operator[](x);
				actors->erase(actors->begin() + x);
				x--;

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
		player->DeleteWeapons();
		player->SetNumFootContacts(0);
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
#pragma endregion Get, Set

Level::~Level()
{
	delete world;
	delete drawableContainer;
	delete entityFactory;
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