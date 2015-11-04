#include "LTexture.h"

LTexture::LTexture()
{
	//Initialize
	this->texture = NULL;
	this->mWidth = 0;
	this->mHeight = 0;
}

LTexture::~LTexture()
{
	//Deallocate
	this->free();
}

bool LTexture::loadFromFile(SDL_Renderer* renderer, std::string path)
{
	//Get rid of preexisting texture
	this->free();

	//The final texture
	this->texture = IMG_LoadTexture(renderer, path.c_str());

	//Load image at specified path
	SDL_Surface* loadedSurface = IMG_Load(path.c_str());
	if (this->texture == NULL)
		printf("Unable to load image %s! SDL_image Error: %s\n", path.c_str(), IMG_GetError());
	else
		SDL_QueryTexture(this->texture, NULL, NULL, &mWidth, &mHeight);

	return this->texture != NULL;
}

void LTexture::free()
{
	//Free texture if it exists
	if (this->texture != NULL)
	{
		SDL_DestroyTexture(this->texture);
		this->texture = NULL;
		this->mWidth = 0;
		this->mHeight = 0;
	}
}

void LTexture::render(SDL_Renderer* renderer, int x, int y, SDL_Rect* clip)
{
	//Set rendering space and render to screen
	SDL_Rect renderQuad = { x, y, this->mWidth, this->mHeight };

	//Set clip rendering dimensions
	if (clip != NULL)
	{
		renderQuad.w = clip->w;
		renderQuad.h = clip->h;
	}

	//Render to screen
	SDL_RenderCopy(renderer, this->texture, clip, &renderQuad);
}

int LTexture::getWidth()
{
	return this->mWidth;
}

int LTexture::getHeight()
{
	return this->mHeight;
}