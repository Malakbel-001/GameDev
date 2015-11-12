#include "Level.h"
#include "PlayState.h"

Level::Level(int _lvlWidth, int _lvlHeight, PlayState* ps)
	: lvlWidth(_lvlWidth), lvlHeight(_lvlHeight), playState(ps)
{
	player = nullptr;
	startXpos = 100;
	startYpos = 10;

	world = new b2World(b2Vec2(0.0, static_cast<float>(1.81)));

	drawableContainer = new DrawableContainer();
	this->tileLoader = nullptr;

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
	world->Step((dt / 100), 5, 5);
	if (player->GetYPos() > lvlHeight)
	{

		GameOver();
	}
}

#pragma region Get, Set
Player* Level::SetPlayer(Player* _player)
{
	//	player = _player;
	player = dynamic_cast<Player*>(entityFactory->CreateEntity(20, 100, 15, 15, EntityType::PLAYER));
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

int Level::GetLvlWidth()
{
	return this->lvlWidth;
}
Level* Level::CreateLevel()
{

	return new Level(lvlWidth, lvlHeight, playState);
}
void Level::GameOver()
{
	playState->GameOver();
}