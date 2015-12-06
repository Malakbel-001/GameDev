#include "ParallaxBackground.h"
#include <iostream> //temp
using namespace std; //tmep

ParallaxBackground::ParallaxBackground(SDL_Renderer* _renderer, Camera* _camera) {
	renderer = _renderer;
	//sets screenWidth and screenHeight, WTB dynamically - TODO
	screenWidth = SDL_GetWindowSurface(SDL_GetWindowFromID(1))->w; //temporary solution!
	screenHeight = SDL_GetWindowSurface(SDL_GetWindowFromID(1))->h; //temporary solution!

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
}

//keep in mind the sequence you set the layers
void ParallaxBackground::SetLayer(char* path, int yOffset, float scrollingSpeed) {
	layerContainers.push_back(new LayerContainer(renderer, path, yOffset, scrollingSpeed));
}

void ParallaxBackground::Draw() {
	int drawPosition = 0;

	int addX = camera->GetX() - previousXPos;
	int modAddX;
	//loop and draw layers
	for (auto layerContainer : layerContainers) {
		//every layer has its own Rectangle
		SDL_Rect bgRect = { 0, 0, layerContainer->GetTextureLayer()->getWidth(), layerContainer->GetTextureLayer()->getHeight() };

		if (addX != 0) {
			cout << "here we go" << endl;
		}

		modAddX = addX * layerContainer->GetScrollingSpeed();
		layerContainer->AddX(- modAddX); //negative modAddX
		drawPosition = layerContainer->GetDrawPosition();

		//keep repeating the background to fill the screen
		while (drawPosition < screenWidth) {
			cout << drawPosition << endl;
			//Draw Background
			layerContainer->GetTextureLayer()->render(renderer, drawPosition, layerContainer->GetYOffset(), 0, &bgRect);

			//setNewDrawPosition
			drawPosition = drawPosition + layerContainer->GetTextureLayer()->getWidth();
		}
	}

	previousXPos = camera->GetX();
}