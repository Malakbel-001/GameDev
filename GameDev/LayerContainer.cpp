#include "LayerContainer.h"
#include <iostream> //temp
using namespace std;

LayerContainer::LayerContainer(SDL_Renderer* renderer, int* _screenWidth, int* _screenHeight, char* _path, float _yOffset, float _scrollingSpeed, int _alphaValue) {
	textureLayer = new LTexture();
	textureLayer->loadFromFile(renderer, _path);

	alphaValue = _alphaValue;
	if (alphaValue < 255) {
		textureLayer->SetTextureAlphaMod(alphaValue);
	}

	screenWidth = _screenWidth;
	screenHeight = _screenHeight;
	path = _path;
	drawPosition = 0;
	yOffset = _yOffset;
	scrollingSpeed = _scrollingSpeed;
}

LayerContainer::~LayerContainer() {
	delete textureLayer;
}

void LayerContainer::LoadAgain(SDL_Renderer* renderer) {
	textureLayer->loadFromFile(renderer, path);
}

void LayerContainer::AddX(float addX) {
	//new drawPosition
	drawPosition = drawPosition + addX;

	if (drawPosition > (float)0) { //make sure to draw on 0 or lower so we don't have empty space on the left side
		drawPosition = drawPosition - static_cast<float>(*screenWidth);
	}
	else if (drawPosition < static_cast<float>(*screenWidth * -1)) { //don't go to deep beneath 0 or we have to draw a lot of times eventually
		drawPosition = drawPosition + static_cast<float>(*screenWidth);
	}
	cout << "DPos: " << drawPosition << endl; //debug purposes
}


LTexture* LayerContainer::GetTextureLayer() { return textureLayer; }
float LayerContainer::GetDrawPosition()		{ return drawPosition; }
float LayerContainer::GetYOffset()			{ return yOffset; }
float LayerContainer::GetScrollingSpeed()	{ return scrollingSpeed; }