#include "DrawableBehaviour.h"


DrawableBehaviour::DrawableBehaviour()
{
}


DrawableBehaviour::~DrawableBehaviour()
{
}

DrawableBehaviour* DrawableBehaviour::EmptyClone()
{
	return new DrawableBehaviour();
}

void DrawableBehaviour::Draw(SDL_Renderer* renderer)
{

}