#include "LayerContainer.h"

LayerContainer::LayerContainer(SDL_Renderer* _renderer, char* path, int _yOffset, float _scrollingSpeed) {
	textureLayer = new LTexture();
	textureLayer->loadFromFile(_renderer, path);

	yOffset = _yOffset;
	scrollingSpeed = scrollingSpeed;
}

LayerContainer::~LayerContainer() {
	delete textureLayer;
}

LTexture* LayerContainer::GetTextureLayer() {
	return textureLayer;
}

int LayerContainer::GetYOffset() {
	return yOffset;
}

int LayerContainer::GetScrollingSpeed() {
	return scrollingSpeed;
}