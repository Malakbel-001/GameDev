#pragma once
#include "LTexture.h"

class LayerContainer {
	private:
		LTexture* textureLayer;
		
		int yOffset;
		float scrollingSpeed;

	public:
		LayerContainer(SDL_Renderer* _renderer, char* path, int _yOffset, float _scrollingSpeed);
		~LayerContainer();

		LTexture* GetTextureLayer();
		int GetYOffset();
		int GetScrollingSpeed();
};