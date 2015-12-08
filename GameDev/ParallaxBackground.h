#pragma once
#include <SDL.h>
#include "Camera.h"
#include "LTexture.h"
#include "LayerContainer.h"
#include <vector>

class ParallaxBackground {
	private:
		SDL_Renderer* renderer;
		Camera* camera;
		std::vector<LayerContainer*> layerContainers;

		int* screenWidth;
		int* screenHeight;
		int yOffset;
		float previousXPos;

		bool wasFullScreen; //was before
		bool CheckFullScreen();

	public:
		ParallaxBackground(SDL_Renderer*, Camera*);
		~ParallaxBackground();

		void InitializeFixXPos();

		void SetLayer(char* path, int yOffset, float scrollingSpeed, int alphaValue);
		void Cleanup();
		void Draw();

		void CheckIfScreenSizeChanged();
};