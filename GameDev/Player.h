#pragma once
#include "Actor.h"
#include "BehaviourFactory.h"
#include "DrawableContainer.h"
#include "DrawableBehaviour.h"
#include "SDL.h"

class Player :
	public Actor
{
public:
	Player(DrawableContainer dc, BehaviourFactory bf);
	virtual ~Player();

private:
	DrawableContainer drawableContainer;
	DrawableBehaviour drawableBehaviour;
};

