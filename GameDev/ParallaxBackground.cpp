#include "ParallaxBackground.h"
#include <iostream>

ParallaxBackground::ParallaxBackground(SDL_Renderer* _renderer) {
	renderer = _renderer;
	//sets screenWidth and screenHeight, dynamically
	screenWidth = SDL_GetWindowSurface(SDL_GetWindowFromID(1))->w; //temporary solution!
	screenHeight = SDL_GetWindowSurface(SDL_GetWindowFromID(1))->h; //temporary solution!

	firstLayer = new LTexture();
	lastLayer = new LTexture();
}

ParallaxBackground::~ParallaxBackground() {
	Cleanup();
}

void ParallaxBackground::Cleanup() {
	if (firstLayer == nullptr)
		delete firstLayer; //frees texture
	if (lastLayer == nullptr)
		delete lastLayer; //frees texture

	firstLayer = nullptr;
	lastLayer = nullptr;
}

void ParallaxBackground::LoadMedia(char* pathFirstLayer, char* pathLastLayer) {
	firstLayer->loadFromFile(renderer, pathFirstLayer);
	//lastLayer->loadFromFile(renderer, pathLastLayer);
}

void ParallaxBackground::SetSettings(int _yOffset) {
	yOffset = _yOffset;
}

void ParallaxBackground::SetCamera(Camera* _camera) {
	camera = _camera;
}

void ParallaxBackground::Draw() {
	//x = 250
	//
	int drawPosition = 0;

	while (drawPosition < screenWidth) {
		SDL_Rect bgRect = { 0, 0, firstLayer->getWidth(), firstLayer->getHeight() };
		if (-camera->GetX() + drawPosition < 0) { //draw one more to the left side if condition check, NOT WORKING YET!
			SDL_Rect leftRect = bgRect; //copy
			firstLayer->render(renderer, -camera->GetX() + drawPosition - firstLayer->getWidth(), yOffset, 0, &leftRect);
		}
		firstLayer->render(renderer, -camera->GetX() + drawPosition, yOffset, 0, &bgRect);
		drawPosition = drawPosition + firstLayer->getWidth();
	}
}