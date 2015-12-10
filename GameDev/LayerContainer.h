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
		int alphaValue;
		float drawPosition;

		void SetTransparencyIfNeeded();

	public:
		LayerContainer(SDL_Renderer*, int* _screenWidth, int* _screenHeight, char* path, float _yOffset, float _scrollingSpeed, int _alphaValue);
		~LayerContainer();

		void LoadAgain(SDL_Renderer*);

		LTexture* GetTextureLayer();
		float GetYOffset();
		float GetScrollingSpeed();
		
		void AddX(float);
		float GetDrawPosition();
};