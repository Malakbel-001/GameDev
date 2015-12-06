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

	public:
		ParallaxBackground(SDL_Renderer* _renderer);
		~ParallaxBackground();
		void LoadMedia(char* pathFirstLayer, char* pathLastLayer);
		void SetCamera(Camera* _camera);
		void Cleanup();
		void Draw();

};