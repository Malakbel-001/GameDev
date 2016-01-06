#include "ParallaxBackground.h"

ParallaxBackground::ParallaxBackground(SDL_Renderer* _renderer, Camera* _camera) {
	autoAdd = 0;
	camera = _camera;

	Initialize(_renderer);
}

ParallaxBackground::ParallaxBackground(SDL_Renderer* _renderer, float _autoAdd) {
	autoAdd = _autoAdd;
	camera = nullptr;

	Initialize(_renderer);
}

void ParallaxBackground::Initialize(SDL_Renderer* _renderer) {
	renderer = _renderer;

	previousXPos = 0; //nothing lost, just in case. Prevent endless loop in Draw.
	//Still, please use InitializeFixXPos()

	screenWidth = new int;
	screenHeight = new int;
	//set screenWidth & screenHeight
	SDL_GetWindowSize(SDL_GetWindowFromID(1), screenWidth, screenHeight);
	wasFullScreen = Utilities::IsFullScreen();

	layerContainers = std::vector<LayerContainer*>();
}

//Sets the previousXPos, activate this after the camera/player is set
//do not forget this, or you are going to have a BAD time.
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
	float addX;
	float modAddX;

	//when camera exists, use camera, else use autoscroll
	if (camera)	{ 
		addX = camera->GetX() - previousXPos; 
	}
	else { 
		addX = autoAdd; 
	}

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

	if (camera)
		previousXPos = camera->GetX();
}

//if screen changed, reload all layerContainers
void ParallaxBackground::CheckIfScreenSizeChanged() {
	bool isFullScreen = Utilities::IsFullScreen();

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