#include "LayerContainer.h"
#include <iostream> //temp
using namespace std;

LayerContainer::LayerContainer(SDL_Renderer* _renderer, char* path, int _yOffset, float _scrollingSpeed) {
	textureLayer = new LTexture();
	textureLayer->loadFromFile(_renderer, path);

	drawPosition = 0;
	yOffset = _yOffset;
	scrollingSpeed = _scrollingSpeed;
}

LayerContainer::~LayerContainer() {
	delete textureLayer;
}

void LayerContainer::AddX(int addX) {
	std::cout << "DPos: " << drawPosition << std::endl;
	
	//new drawPosition
	drawPosition = drawPosition + addX;

	if (addX != 0) {
		cout << "AddX: " << addX << endl;
		cout << "New Dpos: " << drawPosition << endl;
	}


	if (drawPosition > 0) //make sure to draw on 0 or lower so we don't have empty space on the left side
		drawPosition - textureLayer->getWidth();
	else if (drawPosition < (-textureLayer->getWidth())) //don't go to deep beneath 0 or we have to draw a lot of times eventually
		drawPosition + textureLayer->getWidth();

	std::cout << "New DPos: " << drawPosition << std::endl;
}

int LayerContainer::GetDrawPosition()		{ return drawPosition; }
LTexture* LayerContainer::GetTextureLayer() { return textureLayer; }
int LayerContainer::GetYOffset()			{ return yOffset; }
int LayerContainer::GetScrollingSpeed()		{ return scrollingSpeed; }