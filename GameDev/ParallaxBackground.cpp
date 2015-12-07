#include "ParallaxBackground.h"
#include <iostream> //temp
using namespace std; //tmep

ParallaxBackground::ParallaxBackground(SDL_Renderer* _renderer, Camera* _camera) {
	renderer = _renderer;
	//sets screenWidth and screenHeight, WTB dynamically - TODO
	screenWidth = new int;
	screenHeight = new int;

	SDL_GetWindowSize(SDL_GetWindowFromID(1), screenWidth, screenHeight);

	camera = _camera;

	layerContainers = std::vector<LayerContainer*>();
}

void ParallaxBackground::InitializeFixXPos() {
	previousXPos = camera->GetX();
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

	delete screenWidth;
	delete screenHeight;
	screenWidth = nullptr;
	screenHeight = nullptr;
}

//keep in mind the sequence you set the layers
void ParallaxBackground::SetLayer(char* path, int yOffset, float scrollingSpeed) {
	layerContainers.push_back(new LayerContainer(renderer, screenWidth, screenHeight, path, yOffset, scrollingSpeed));
}

void ParallaxBackground::Draw() {
	//IfScreenSizeChangedLoadAgainLayerContainers();

	float drawPosition = 0;

	float addX = camera->GetX() - previousXPos;
	float modAddX;

	//loop and draw layers
	for (auto layerContainer : layerContainers) {
		//every layer has its own Rectangle
		SDL_Rect bgRect = { 0, 0, *screenWidth, *screenHeight};

		modAddX = addX * layerContainer->GetScrollingSpeed();
		layerContainer->AddX(modAddX * -1); //negative modAddX
		drawPosition = layerContainer->GetDrawPosition();

		//keep repeating the background to fill the screen
		while (drawPosition < *screenWidth) {
			//Draw Background
			layerContainer->GetTextureLayer()->render(renderer, drawPosition, layerContainer->GetYOffset(), 0, &bgRect);

			//setNewDrawPosition
			drawPosition = drawPosition + bgRect.w;
		}
	}

	previousXPos = camera->GetX();
}