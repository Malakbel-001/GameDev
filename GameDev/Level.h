#pragma message("level ")
#pragma once
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
	float startXpos;
	float startYpos;
	b2ContactListener* contact;
protected:
	b2World* world;
	EntityFactory* entityFactory;
	DrawableContainer* drawableContainer;
	MoveableContainer* moveableContainer;
	SDL_Texture* tileSheet;
	Timer* timer;

	int levelId;
	int lvlWidth, lvlHeight;

	PlayState* playState;
	
	std::vector<Actor*>* actors;
	std::vector<Entity*>* entities;
	Player* player;
	std::string backgroundPath;
	ParallaxBackground* parallaxBackground;
public:
	//Initialization / Create Level
	virtual void SetEntityFactory(BehaviourFactory*);			//needs to be public for level editor
private:
	virtual void CreateMap();									//before pure virtual function
	virtual void CreateNPCs();									//before pure virtual function
	virtual void CreateTimer();
	virtual void CreateParallaxBackground(BehaviourFactory*);	//before pure virtual function

	void ConstructorLevel();
public:
	Level(int _lvlWidth, int _lvlHeight); //clean level for level editor
	Level(int _lvlWidth, int _lvlHeight, b2Vec2 vec);


	Player* GetPlayer();
	std::vector<Actor*>* GetActors();
	std::vector<Entity*>* GetEntities();
	DrawableContainer* GetDrawableContainer();
	MoveableContainer* GetMoveableContainer();
	void SetPlayState(PlayState* play);
	virtual void Init(BehaviourFactory* bf, PlayState* play);
	virtual void Init(BehaviourFactory* bf);

	virtual ~Level();


	int GetLvlWidth();
	int GetLvlHeight();
	int GetTotalTiles();
	int GetTotalDiffrentTiles();
	EntityFactory* GetEntityFactory();
	std::vector<SDL_Rect> getTileCrops();
	
	void Draw();
	void Update(float dt, float manipulatorSpeed);
	void GameOver();
	void Victory();
	virtual b2World* GetWorld();

	virtual Player* SetPlayer(Player* _player);					//before pure virtual function
	virtual Level* CreateLevel();								//before pure virtual function
	ParallaxBackground* GetParallaxBackGround();
	Timer* GetTimer();

	Player* SetPlayerPosition(Player* _player, float x, float y);
	virtual void SetLvlWidth(int _lvlWidth);
	virtual void SetLvlHeight(int _lvlHeight);

	int GetLevelId() { return levelId; };

	void EnterVehicle();
};
