#include "ParallaxBackground.h"

ParallaxBackground::ParallaxBackground(SDL_Renderer* _renderer, Camera* _camera) {
	renderer = _renderer;

	screenWidth = new int;
	screenHeight = new int;
	//set screenWidth & screenHeight
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

//Set Layer with the appropriate settings
//keep in mind the sequence you set the layers
void ParallaxBackground::SetLayer(char* path, int yOffset, float scrollingSpeed, int alphaValue) {
	layerContainers.push_back(new LayerContainer(renderer, screenWidth, screenHeight, path, yOffset, scrollingSpeed, alphaValue));
}

//Draw all LayerContainers
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

//returns boolean if the game is currently in fullscreen or not
bool ParallaxBackground::CheckFullScreen() {
	SDL_Window* window = SDL_GetWindowFromID(1); //works as long as we have only 1 window
	Uint32 flags = SDL_GetWindowFlags(window); //sdl window flags including fullscreen desktop flag

	bool isFullScreen = (flags & SDL_WINDOW_FULLSCREEN_DESKTOP) == SDL_WINDOW_FULLSCREEN_DESKTOP;

	return isFullScreen;
}

//if screen changed, reload all layerContainers
void ParallaxBackground::CheckIfScreenSizeChanged() {
	bool isFullScreen = CheckFullScreen();

	//check if the screen changed
	if (wasFullScreen != isFullScreen) {
		//set screenWidth & screenHeight
		SDL_GetWindowSize(SDL_GetWindowFromID(1), screenWidth, screenHeight);
		//this will also update the screenWidth and screenHeight inside the LayerContainers, because they have int pointers

		//load all layerContainers
		for (auto layerContainer : layerContainers) {
			layerContainer->LoadAgain(renderer);
		}
	}

	wasFullScreen = isFullScreen; //keep the result for later check
}