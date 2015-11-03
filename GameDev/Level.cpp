#include "Level.h"

Level::Level(int _lvlWidth, int _lvlHeight)
	: lvlWidth(_lvlWidth), lvlHeight(_lvlHeight)
{
	world = new b2World(b2Vec2(0.0, static_cast<float>(9.81) ));
	this->tileLoader = nullptr;

}
void Level::Init(){
	EntityFactory ent = EntityFactory(*world);
	BehaviourFactory fac = BehaviourFactory();
	drawableContainer->Add(fac.CreateDrawableBehaviour(BehaviourType::GROUNDDRAWABLEBEHAVIOUR, ent.CreateStaticEntity(100, 300, EntityType::PLAYER)));
}
b2World* Level::GetWorld()
{
	return world;
}

Level::~Level()
{
	// TODO: delete box2D pointer
	SDL_DestroyTexture(tileSheet);
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