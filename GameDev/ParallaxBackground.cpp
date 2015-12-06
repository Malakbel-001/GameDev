#include "ParallaxBackground.h"
#include <iostream>
using namespace std;

ParallaxBackground::ParallaxBackground(SDL_Renderer* _renderer, Camera* _camera) {
	renderer = _renderer;
	//sets screenWidth and screenHeight, dynamically
	screenWidth = SDL_GetWindowSurface(SDL_GetWindowFromID(1))->w; //temporary solution!
	screenHeight = SDL_GetWindowSurface(SDL_GetWindowFromID(1))->h; //temporary solution!

	camera = _camera;

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

void ParallaxBackground::Draw() {
	//x = 250
	//
	int drawPosition = 0;

	while (drawPosition - camera->GetX() < screenWidth) {
		cout << "D:" << drawPosition << "math: " << drawPosition - camera->GetX() << endl;
		SDL_Rect bgRect = { 0, 0, firstLayer->getWidth(), firstLayer->getHeight() };
		if (drawPosition - camera->GetX() > 0) { //draw one more to the left side if condition check, NOT WORKING YET!
			cout << "inside" << endl;
			SDL_Rect leftRect = bgRect; //copy

			firstLayer->render(renderer, -camera->GetX() + drawPosition - firstLayer->getWidth(), yOffset, 0, &leftRect);
		}
		firstLayer->render(renderer, -camera->GetX() + drawPosition, yOffset, 0, &bgRect);
		drawPosition = drawPosition + firstLayer->getWidth();
	}

	/*SDL_Rect bgRect = { 0, 0, firstLayer->getWidth(), firstLayer->getHeight() };
	firstLayer->render(renderer, 0-firstLayer->getWidth(), yOffset, 0, &bgRect);*/
}