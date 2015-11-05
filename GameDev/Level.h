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
		
		EntityFactory* entityFactory;
		float startXpos;
		float startYpos;

	protected:
		int tileWidth, tileHeight;
		int lvlWidth, lvlHeight, lvlTotalTiles, lvlTotalDiffrentTiles;
		DrawableContainer* drawableContainer;
		b2World* world;
		Camera* camera;
		int LevelTiles;
		SDL_Texture* tileSheet;
		std::vector<SDL_Rect> tileCrops;

		TileLoader* tileLoader;

	public:
		DrawableContainer* GetDrawableContainer();
		Level(int _lvlWidth, int _lvlHeight);
		void init(BehaviourFactory* bf);
		virtual ~Level();

		virtual void SetPlayer(Player* _player);
		virtual void SetLvlWidth(int _lvlWidth);
		virtual void SetLvlHeight(int _lvlHeight);

		int GetLvlWidth();
		int GetLvlHeight();
		int GetTotalTiles();
		int GetTotalDiffrentTiles();
		std::vector<SDL_Rect> getTileCrops();

		void Draw();
		void Update(float dt);

		virtual b2World* GetWorld();
};
