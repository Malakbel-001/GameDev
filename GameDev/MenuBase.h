#pragma once
#include <SDL.h>
#include <unordered_map>
#include <SDL_ttf.h>
#include "SoundBank.h"
#include "MenuEnum.h"
class MenuBase
{
protected:
	MenuBase(){}
	SDL_Renderer* renderer;
public:
	virtual void Init() = 0;
	virtual void Update(float dt) = 0;
	virtual void Draw() = 0;
	virtual void HandleMouseEvents(SDL_Event mainEvent) = 0;
	virtual void HandleKeyEvents(std::unordered_map<SDL_Keycode, bool>* _events) = 0;
	virtual void HandleTextInputEvents(SDL_Event event) = 0;
	virtual ~MenuBase();

	void Highlight(int);
};

