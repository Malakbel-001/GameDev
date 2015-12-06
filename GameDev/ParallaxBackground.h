#pragma once
#include <SDL.h>
#include "Camera.h"
#include "LTexture.h"

class ParallaxBackground {
	private:
		SDL_Renderer* renderer;
		Camera* camera;
		LTexture* firstLayer;
		LTexture* lastLayer;

		int screenWidth;
		int screenHeight;
		int xOffset;
		int yOffset;

	public:
		ParallaxBackground(SDL_Renderer*, Camera*);
		~ParallaxBackground();
		void LoadMedia(char* pathFirstLayer, char* pathLastLayer);
		void SetSettings(int _yOffset);
		void Cleanup();
		void Draw();

};