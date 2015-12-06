#include "LayerContainer.h"
#include <iostream> //temp
using namespace std;

LayerContainer::LayerContainer(SDL_Renderer* _renderer, char* path, float _yOffset, float _scrollingSpeed) {
	textureLayer = new LTexture();
	textureLayer->loadFromFile(_renderer, path);

	drawPosition = 0;
	yOffset = _yOffset;
	scrollingSpeed = _scrollingSpeed;
}

LayerContainer::~LayerContainer() {
	delete textureLayer;
}

void LayerContainer::AddX(float addX) {
	//new drawPosition
	drawPosition = drawPosition + addX;

	if (drawPosition >= 0) //make sure to draw on 0 or lower so we don't have empty space on the left side
		drawPosition - textureLayer->getWidth();
	else if (drawPosition < (-textureLayer->getWidth())) //don't go to deep beneath 0 or we have to draw a lot of times eventually
		drawPosition + textureLayer->getWidth();

	cout << "DPos: " << drawPosition << endl;
}

float LayerContainer::GetDrawPosition()		{ return drawPosition; }
LTexture* LayerContainer::GetTextureLayer() { return textureLayer; }
float LayerContainer::GetYOffset()			{ return yOffset; }
float LayerContainer::GetScrollingSpeed()	{ return scrollingSpeed; }