#pragma once
#include <SDL.h>
#include <SDL_image.h>
#include <stdio.h>
#include <string>

class LTexture
{
public:
	//Initializes variables 
	LTexture();

	//Deallocates memory 
	~LTexture();

	//Loads image at specified path 
	bool loadFromFile(SDL_Renderer* renderer, std::string path);

	//Deallocates texture 
	void free();

	//Renders texture at given point 
	void render(SDL_Renderer* renderer, int x, int y, SDL_Rect* clip = NULL);

	//Gets image dimensions 
	int getWidth(); int getHeight();

private:
	//The actual hardware texture 
	SDL_Texture* texture;

	//Image dimensions 
	int mWidth;
	int mHeight;
};

