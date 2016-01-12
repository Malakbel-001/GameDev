#pragma once
#include <vector>
#include <SDL.h>
#include "Behaviour.h"
#include "Camera.h"
#include "Sprite.h"



using namespace std;

class Object;	

class DrawableBehaviour :
	public Behaviour
{
protected:
	SDL_Renderer* renderer;
	Object* entity;
	Camera* camera;
	Sprite* sprite;

	int currentFrame;
	int screenWidth;
	int screenHeight;
	
	float Ratio = 1.0F / 10.0F;

public:
	DrawableBehaviour(SDL_Renderer* sdl_renderer, Sprite* _sprite, int screenwidth, int screenheight);
	virtual ~DrawableBehaviour();
	Sprite* GetSprite();
	void SetEntity(Object* _entity);
	Object* GetEntity();
	virtual DrawableBehaviour* EmptyClone();
	void SetCamera(Camera* _camera);
	Camera* GetCamera();
	void SetSprite(Sprite* _sprite);
	virtual void Draw(bool cycle) = 0; //pure virtual
	
};

