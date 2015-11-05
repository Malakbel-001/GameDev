#include "Level.h"

Level::Level(int _lvlWidth, int _lvlHeight)
	: lvlWidth(_lvlWidth), lvlHeight(_lvlHeight)
{
	player = nullptr;
	startXpos = 100;
	startYpos = 10;
<<<<<<< HEAD
	world = new b2World(b2Vec2(0.0, static_cast<float>(9.81)));
=======
	world = new b2World(b2Vec2(0.0, static_cast<float>(/*9.81*/0) ));
	
	drawableContainer = new DrawableContainer();
>>>>>>> refs/remotes/origin/Develop

	drawableContainer = new DrawableContainer();

	this->tileLoader = nullptr;
	this->camera = nullptr;
}

<<<<<<< HEAD
Level::~Level()
{
	delete world;
	delete drawableContainer;
	delete entityFactory;

	delete camera;
	delete tileLoader;
}

void Level::init(BehaviourFactory* bf)
{
	entityFactory = new EntityFactory(*world, bf, drawableContainer);
	entityFactory->CreateEntity(0, 400, 255, 15, EntityType::GROUND);
=======
void Level::Init(BehaviourFactory* bf){
>>>>>>> refs/remotes/origin/Develop
}

b2World* Level::GetWorld()
{
	return world;
}

void Level::Update(float dt)
{
	world->Step(dt, 5, 5);
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

Player* Level::GetPlayer()
{
<<<<<<< HEAD
	return player;
=======

	delete world;
	delete drawableContainer;
	delete entityFactory;
>>>>>>> refs/remotes/origin/Develop
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
<<<<<<< HEAD

int Level::GetTotalTiles()
{
	return this->lvlTotalTiles;
}

int Level::GetTotalDiffrentTiles()
{
	return this->lvlTotalDiffrentTiles;
}

DrawableContainer* Level::GetDrawableContainer()
{
=======
DrawableContainer* Level::GetDrawableContainer(){
>>>>>>> refs/remotes/origin/Develop
	return drawableContainer;
}
#pragma endregion Get, Set
