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

		int screenWidth;
		int screenHeight;
		int xOffset;
		int yOffset;

		void DrawBackground(LayerContainer*, SDL_Rect, int xDrawPos);

	public:
		ParallaxBackground(SDL_Renderer*, Camera*);
		~ParallaxBackground();
		void SetLayer(char* path, int _yOffset, float _scrollingSpeed);
		void Cleanup();
		void Draw();

};