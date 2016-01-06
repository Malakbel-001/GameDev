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
#include "ParallaxBackground.h"
#include "Timer.h"


class PlayState;
class Level //abstract class now because of pure virtual method: SetPlayer() and CreateLevel(), this class cannot be instantiated anymore
{
private:
	MoveableContainer* moveableContainer;

	float startXpos;
	float startYpos;
	b2ContactListener* contact;
protected:
	b2World* world;
	EntityFactory* entityFactory;
	DrawableContainer* drawableContainer;
	Timer* timer;

	int levelId;
	int lvlWidth, lvlHeight;

	PlayState* playState;
	
	std::vector<Actor*>* actors;
	std::vector<Entity*>* entities;
	Player* player;
	std::string backgroundPath;
	ParallaxBackground* parallaxBackground;
	//Initialization / Create Level
	virtual void SetEntityFactory(BehaviourFactory*);
	virtual void CreateMap() = 0;									//pure virtual
	virtual void CreateNPCs() = 0;									//pure virtual
	virtual void CreateTimer();
	virtual void CreateParallaxBackground(BehaviourFactory*) = 0;	//pure virtual

public:
	Player* GetPlayer();
	std::vector<Actor*>* GetActors();
	std::vector<Entity*>* GetEntities();
	DrawableContainer* GetDrawableContainer();
	Level(int _lvlWidth, int _lvlHeight);

	Level(int _lvlWidth, int _lvlHeight, b2Vec2 vec);
	virtual void Init(BehaviourFactory* bf, PlayState* play);
	virtual ~Level();


	int GetLvlWidth();
	int GetLvlHeight();
	int GetTotalTiles();
	int GetTotalDiffrentTiles();
	EntityFactory* GetEntityFactory();
	std::vector<SDL_Rect> getTileCrops();
	
					//TODO get this to work
	void Draw();
	void Update(float dt, float manipulatorSpeed);
	void GameOver();
	void Victory();
	virtual b2World* GetWorld();

							//probably not public!

	virtual Player* SetPlayer(Player* _player) = 0;					//pure virtual
	virtual Level* CreateLevel() = 0;								//pure virtual
	ParallaxBackground* GetParallaxBackGround();
	Timer* GetTimer();

	Player* SetPlayerPosition(Player* _player, float x, float y);
	virtual void SetLvlWidth(int _lvlWidth);
	virtual void SetLvlHeight(int _lvlHeight);

	int GetLevelId() { return levelId; };

};
