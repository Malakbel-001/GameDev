#pragma once
#include <SDL.h>
#include <SDL_image.h>
#include <stdio.h>
#include <string>
#include "EntityState.h"

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
	void render(SDL_Renderer* renderer, float x, float y, double angle, SDL_Rect* clip);
	void render(SDL_Renderer* renderer, float x, float y, double angle, SDL_Rect* clip, EntityState state);

	//Gets image dimensions 
	int getWidth(); int getHeight();

private:
	//The actual hardware texture 
	SDL_Texture* texture;

	//Image dimensions 
	int mWidth;
	int mHeight;
};

