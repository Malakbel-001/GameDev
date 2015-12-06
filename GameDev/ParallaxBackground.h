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
		ParallaxBackground(SDL_Renderer* _renderer);
		~ParallaxBackground();
		void LoadMedia(char* pathFirstLayer, char* pathLastLayer);
		void SetSettings(int _yOffset);
		void SetCamera(Camera* _camera);
		void Cleanup();
		void Draw();

};