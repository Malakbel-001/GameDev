#pragma message("level ")
#pragma once
#include "Entity.h"
#include <vector>
#include "header_loader.h"
#include "Box2D\Box2D.h"
#include "DrawableContainer.h"
#include "MoveableContainer.h"
#include "EntityFactory.h"
#include "ContactListener.h"


class PlayState;
class Level
{
private:
	MoveableContainer* moveableContainer;
	


	float startXpos;
	float startYpos;

protected:
	EntityFactory* entityFactory;
	int tileWidth, tileHeight;
	int lvlWidth, lvlHeight;
	DrawableContainer* drawableContainer;
	b2World* world;
	SDL_Texture* tileSheet;

	PlayState* playState;
	
	std::vector<Actor*> actors;
	Player* player;
public:
	Player* GetPlayer();

	DrawableContainer* GetDrawableContainer();
	Level(int _lvlWidth, int _lvlHeight, PlayState* ps);
	virtual void Init(BehaviourFactory* bf);
	virtual ~Level();

	virtual Player* SetPlayer(Player* _player);
	virtual void SetLvlWidth(int _lvlWidth);
	virtual void SetLvlHeight(int _lvlHeight);
	virtual Level* CreateLevel();

	SDL_Texture* GetTileSheet();

	int GetLvlWidth();
	int GetLvlHeight();
	int GetTotalTiles();
	int GetTotalDiffrentTiles();
	std::vector<SDL_Rect> getTileCrops();

	void Draw();
	void Update(float dt);
	void GameOver();
	virtual b2World* GetWorld();
};
