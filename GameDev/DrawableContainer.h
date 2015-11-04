#pragma once
#include <vector>
#include "SDL.h"
#include "Container.h"
#include "DrawableBehaviour.h"

using namespace std;

class DrawableContainer :
	public Container
{
public:
	DrawableContainer();
	virtual ~DrawableContainer();
		
	void Add(DrawableBehaviour* behaviour);
	void Draw();
private:
	vector<DrawableBehaviour*> behaviours;
};

