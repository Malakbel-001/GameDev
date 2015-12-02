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
class Level //abstract class now because of pure virtual method: SetPlayer() and CreateLevel(), this class cannot be instantiated anymore
{
private:
	MoveableContainer* moveableContainer;
	


	float startXpos;
	float startYpos;

protected:
	int levelId;
	EntityFactory* entityFactory;
	int tileWidth, tileHeight;
	int lvlWidth, lvlHeight;
	DrawableContainer* drawableContainer;
	b2World* world;
	SDL_Texture* tileSheet;

	PlayState* playState;
	
	std::vector<Actor*>* actors;
	Player* player;
	std::string backgroundPath;
public:
	Player* GetPlayer();

	DrawableContainer* GetDrawableContainer();
	Level(int _lvlWidth, int _lvlHeight, PlayState* ps);
	virtual void Init(BehaviourFactory* bf);
	virtual ~Level();

	virtual Player* SetPlayer(Player* _player) = 0; //pure virtual
	virtual Level* CreateLevel() = 0;				//pure virtual

	Player* SetPlayerPosition(Player* _player, float x, float y);
	virtual void SetLvlWidth(int _lvlWidth);
	virtual void SetLvlHeight(int _lvlHeight);

	SDL_Texture* GetTileSheet();

	int GetLvlWidth();
	int GetLvlHeight();
	int GetTotalTiles();
	int GetTotalDiffrentTiles();
	EntityFactory* GetEntityFactory();
	std::vector<SDL_Rect> getTileCrops();
	std::vector<Entity*>* entities;
	void Draw();
	void Update(float dt);
	void GameOver();
	void Victory();
	virtual b2World* GetWorld();

	int GetLevelId() { return levelId; };
	std::string GetBackgroundPath() { return backgroundPath; };
};
