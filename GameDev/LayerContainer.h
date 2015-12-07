#pragma once
#include "LTexture.h"

class LayerContainer {
	private:
		LTexture* textureLayer;
		char* path;

		int* screenWidth;
		int* screenHeight;

		float yOffset;
		float scrollingSpeed;

		float drawPosition;

	public:
		LayerContainer(SDL_Renderer*, int* _screenWidth, int* _screenHeight, char* path, float _yOffset, float _scrollingSpeed);
		~LayerContainer();

		void LoadAgain(SDL_Renderer*);

		LTexture* GetTextureLayer();
		float GetYOffset();
		float GetScrollingSpeed();
		
		void AddX(float);
		float GetDrawPosition();
};