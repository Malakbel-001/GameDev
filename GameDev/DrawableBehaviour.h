#pragma once
#include <vector>
#include <SDL.h>
#include "Behaviour.h"
#include "LTexture.h"
#include "Camera.h"




using namespace std;

class Entity;	

class DrawableBehaviour :
	public Behaviour
{
	protected:
		SDL_Renderer* renderer;
		Entity* entity;
		Camera* camera;

		vector<SDL_Rect> sprites;
		int currentFrame;
		LTexture* spriteSheetTexture;
		string spritesheetPath;
		string spritesheetName;

		int screenWidth;
		int screenHeight;

	float x = 1;
	float y = 10;
	float Ratio = x / y;


	public:
		DrawableBehaviour(SDL_Renderer* sdl_renderer, int screenwidth, int screenheight);
		virtual ~DrawableBehaviour();

		void SetEntity(Entity* _entity);
		Entity* GetEntity();
		virtual DrawableBehaviour* EmptyClone();
		void SetCamera(Camera* _camera);
		virtual void Draw();
		virtual void SetSprites(vector<SDL_Rect> sdl_sprites);
		virtual bool LoadMedia();
		

	
};

