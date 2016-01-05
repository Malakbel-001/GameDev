#pragma once
#include <SDL.h>
#include "Camera.h"
#include "LTexture.h"
#include "LayerContainer.h"
#include <vector>
#include "Utitilies.h"

class ParallaxBackground {
	private:
		SDL_Renderer* renderer;

		Camera* camera;	//follow camera
		float autoAdd;	//autoscroll

		std::vector<LayerContainer*> layerContainers;

		int* screenWidth;
		int* screenHeight;
		int yOffset;
		float previousXPos;

		bool wasFullScreen; //was before

		void Initialize(SDL_Renderer*);

	public:
		ParallaxBackground(SDL_Renderer*, Camera*);
		ParallaxBackground(SDL_Renderer*, float _autoAdd);
		~ParallaxBackground();

		void InitializeFixXPos();

		void SetLayer(char* path, int yOffset, float scrollingSpeed, int alphaValue);
		void Cleanup();
		void Draw();

		void CheckIfScreenSizeChanged();
};