#include "ParallaxBackground.h"
#include <iostream>

ParallaxBackground::ParallaxBackground(SDL_Renderer* _renderer) {
	renderer = _renderer;
	//sets screenWidth and screenHeight, dynamically
	screenWidth = SDL_GetWindowSurface(SDL_GetWindowFromID(1))->w;
	screenHeight = SDL_GetWindowSurface(SDL_GetWindowFromID(1))->h;

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

void ParallaxBackground::SetCamera(Camera* _camera) {
	camera = _camera;
}

void ParallaxBackground::Draw() {
	//x = 250
	//


	SDL_Rect bgRect = { camera->GetX(), 0, firstLayer->getWidth(), firstLayer->getHeight() };
	firstLayer->render(renderer, camera->GetX(), 0, 1, &bgRect);
}