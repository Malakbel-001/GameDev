#include "Level.h"

Level::Level(int _lvlWidth, int _lvlHeight)
	: lvlWidth(_lvlWidth), lvlHeight(_lvlHeight)
{
	player = nullptr;
	startXpos = 100;
	startYpos = 10;

	world = new b2World(b2Vec2(0.0, static_cast<float>(1.81)));
	
	drawableContainer = new DrawableContainer();
	this->tileLoader = nullptr;
	this->camera = nullptr;

}

void Level::Init(BehaviourFactory* bf){
}

b2World* Level::GetWorld()
{
	return world;
}

void Level::Update(float dt)
{
	world->Step((dt/100), 5, 5);
	camera->UpdateCamaraPosition(player->GetXPos(), player->GetYPos(), player->GetWidth(), player->GetHeight());
}

#pragma region Get, Set
void Level::SetPlayer(Player* _player)
{
	//	player = _player;
	player = dynamic_cast<Player*>(entityFactory->CreateEntity(20, 100, 15, 15, EntityType::PLAYER));
	this->camera = new Camera(player->GetBody()->GetPosition().x, player->GetBody()->GetPosition().y,
		player->GetWidth(), player->GetHeight(), this->GetLvlWidth(), this->GetLvlHeight());
}
Player* Level::GetPlayer(){
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

	delete camera;

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

int Level::GetLvlWidth()
{
	return this->lvlWidth;
}



