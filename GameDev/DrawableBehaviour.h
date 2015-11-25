#pragma once
#include <vector>
#include <SDL.h>
#include "Behaviour.h"
#include "LTexture.h"
#include "Camera.h"
#include "Sprite.h"



using namespace std;

class Entity;	

class DrawableBehaviour :
	public Behaviour
{
protected:
	SDL_Renderer* renderer;
	Entity* entity;
	Camera* camera;
	Sprite* sprite;

	int currentFrame;
	int screenWidth;
	int screenHeight;

	float x = 1;
	float y = 10;
	float Ratio = x / y;


public:
	DrawableBehaviour(SDL_Renderer* sdl_renderer, Sprite* _sprite, int screenwidth, int screenheight);
	virtual ~DrawableBehaviour();

	void SetEntity(Entity* _entity);
	Entity* GetEntity();
	virtual DrawableBehaviour* EmptyClone();
	void SetCamera(Camera* _camera);
	void SetSprite(Sprite* _sprite);
	virtual void Draw();	
};

