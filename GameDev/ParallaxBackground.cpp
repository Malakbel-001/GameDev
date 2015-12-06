#include "ParallaxBackground.h"
#include <iostream>
using namespace std;

ParallaxBackground::ParallaxBackground(SDL_Renderer* _renderer, Camera* _camera) {
	renderer = _renderer;
	//sets screenWidth and screenHeight, WTB dynamically - TODO
	screenWidth = SDL_GetWindowSurface(SDL_GetWindowFromID(1))->w; //temporary solution!
	screenHeight = SDL_GetWindowSurface(SDL_GetWindowFromID(1))->h; //temporary solution!

	camera = _camera;

	layerContainers = std::vector<LayerContainer*>();
}

ParallaxBackground::~ParallaxBackground() {
	Cleanup();
}

void ParallaxBackground::Cleanup() {
	for (auto layerContainer : layerContainers) {
		delete layerContainer;
		layerContainer = nullptr;
	}
	layerContainers.clear();
}

//keep in mind the sequence you set the layers
void ParallaxBackground::SetLayer(char* path, int yOffset, float scrollingSpeed) {
	layerContainers.push_back(new LayerContainer(renderer, path, yOffset, scrollingSpeed));
}

void ParallaxBackground::Draw() {
	int drawPosition = 0;

	//loop and draw layers
	for (auto layerContainer : layerContainers) {
		//keep repeating the background to fill the screen
		while (drawPosition - camera->GetX() < screenWidth) {
			SDL_Rect bgRect = { 0, 0, layerContainer->GetTextureLayer()->getWidth(), layerContainer->GetTextureLayer()->getHeight() };

			if (drawPosition - camera->GetX() > 0) { //if the current position to draw > 0 ----> draw another background to the left
				DrawBackground(layerContainer, bgRect, drawPosition - layerContainer->GetTextureLayer()->getWidth());
			}

			DrawBackground(layerContainer, bgRect, drawPosition);

			//setNewDrawPosition
			drawPosition = drawPosition + layerContainer->GetTextureLayer()->getWidth();
		}
		drawPosition = 0;
	}
}

void ParallaxBackground::DrawBackground(LayerContainer* layerContainer, SDL_Rect bgRect, int xDrawPos) {
	layerContainer->GetTextureLayer()->render(renderer, xDrawPos - camera->GetX(), layerContainer->GetYOffset(), 0, &bgRect);
}