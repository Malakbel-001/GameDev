#pragma once
#include <vector>
#include "SDL.h"
#include "Container.h"
#include "DrawableBehaviour.h"


using namespace std;
class Entity;
class DrawableContainer :
	public Container
{
public:
	DrawableContainer();
	virtual ~DrawableContainer();
		
	void Add(DrawableBehaviour* behaviour);
	void Draw(float dt, float manipulatorSpeed);
	void Delete(Entity* behaviour);
private:
	vector<DrawableBehaviour*> behaviours;

	bool CycleFrames(float dt, float manipulatorSpeed);
	//target FPS = 16ms, (60fps) times 3 for smooth amount of cycling on the frames
	const float dtCycleFrame = 3 * 16;
	float dtAccumulator;
};

