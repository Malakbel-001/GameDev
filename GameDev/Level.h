#pragma once
#include <vector>
#include "header_loader.h"
#include "Box2D\Box2D.h"
#include "Camera.h"
#include "TileLoader.h"
#include "DrawableContainer.h"
#include "MoveableContainer.h"
#include "EntityFactory.h"

class Level
{
private:
	MoveableContainer* moveableContainer;
	Player* player;


	float startXpos;
	float startYpos;

protected:
	EntityFactory* entityFactory;
	int tileWidth, tileHeight;
	int lvlWidth, lvlHeight;
	DrawableContainer* drawableContainer;
	b2World* world;
	Camera* camera;
	SDL_Texture* tileSheet;
	std::vector<SDL_Rect> tileCrops;

	TileLoader* tileLoader;

public:
	Player* GetPlayer();

	DrawableContainer* GetDrawableContainer();
	Level(int _lvlWidth, int _lvlHeight);
	virtual void Init(BehaviourFactory* bf);
	virtual ~Level();

	virtual void SetPlayer(Player* _player);
	virtual void SetLvlWidth(int _lvlWidth);
	virtual void SetLvlHeight(int _lvlHeight);

	SDL_Texture* GetTileSheet();

	int GetLvlWidth();
	int GetLvlHeight();
	int GetTotalTiles();
	int GetTotalDiffrentTiles();
	std::vector<SDL_Rect> getTileCrops();

	void Draw();
	void Update(float dt);

	virtual b2World* GetWorld();
};
