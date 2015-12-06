#pragma once
#include "LTexture.h"

class LayerContainer {
	private:
		LTexture* textureLayer;
		
		float yOffset;
		float scrollingSpeed;

		float drawPosition;

	public:
		LayerContainer(SDL_Renderer* _renderer, char* path, float _yOffset, float _scrollingSpeed);
		~LayerContainer();

		LTexture* GetTextureLayer();
		float GetYOffset();
		float GetScrollingSpeed();
		
		void AddX(float);
		float GetDrawPosition();
};