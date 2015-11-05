#pragma once
#include <vector>
#include <SDL.h>
#include "Behaviour.h"
#include "LTexture.h"


using namespace std;

class Entity;	

class DrawableBehaviour :
	public Behaviour
{
	protected:
		SDL_Renderer* renderer;
		Entity* entity;

		vector<SDL_Rect> sprites;
		int currentFrame;
		LTexture* spriteSheetTexture;
		string spritesheetPath;
		string spritesheetName;

		int screenWidth;
		int screenHeight;

	public:
		DrawableBehaviour(SDL_Renderer* sdl_renderer, int screenwidth, int screenheight);
		virtual ~DrawableBehaviour();

		virtual DrawableBehaviour* EmptyClone();

		virtual void Draw();
		virtual void SetSprites(vector<SDL_Rect> sdl_sprites);
		virtual bool LoadMedia();

		void SetEntity(Entity* _entity);
};

