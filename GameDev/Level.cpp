#include "Level.h"

Level::Level(int _lvlWidth, int _lvlHeight)
	: lvlWidth(_lvlWidth), lvlHeight(_lvlHeight)
{
	startXpos = 100;
	startYpos = 10;
	world = new b2World(b2Vec2(0.0, static_cast<float>(9.81) ));

	drawableContainer = new DrawableContainer();


	this->tileLoader = nullptr;
}

void Level::init(BehaviourFactory* bf){
	entityFactory = new EntityFactory(*world, bf, drawableContainer);
	//entityFactory->CreateEntity(100, 100, 10, 10, EntityType::PLAYER);
	entityFactory->CreateEntity(0, 400, 100, 100, EntityType::GROUND);

}

b2World* Level::GetWorld()
{
	return world;
}
void Level::Update(float dt){
	
	world->Step(dt, 5, 5);
}
void Level::SetPlayer(Player* _player){
	
//	player = _player;
	entityFactory->CreateEntity(20, 100, 15, 15, EntityType::PLAYER);

}

Level::~Level()
{

	delete world;
	delete drawableContainer;
	delete entityFactory;

	delete tileLoader;
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

int Level::GetTotalTiles()
{
	return this->lvlTotalTiles;
}

int Level::GetTotalDiffrentTiles()
{
	return this->lvlTotalDiffrentTiles;
}
DrawableContainer* Level::GetDrawableContainer(){
	return drawableContainer;
}