#include "LTexture.h"


LTexture::LTexture()
{
	//Initialize
	texture = nullptr;
	mWidth = 0;
	mHeight = 0;
}


LTexture::~LTexture()
{
	//Deallocate
	free();
}

bool LTexture::loadFromFile(SDL_Renderer* renderer, std::string path)
{
	//Get rid of preexisting texture
	free();

	//The final texture
	this->texture = IMG_LoadTexture(renderer, path.c_str());

	if (texture == nullptr)
		printf("Unable to load image %s! SDL_image Error: %s\n", path.c_str(), IMG_GetError());
	else
		SDL_QueryTexture(this->texture, NULL, NULL, &mWidth, &mHeight);

	return texture != nullptr;
}

void LTexture::free()
{
	//Free texture if it exists
	if (texture != nullptr)
	{
		SDL_DestroyTexture(texture);
		texture = nullptr;
		mWidth = 0;
		mHeight = 0;
	}
}

#pragma region render to screen
void LTexture::render(SDL_Renderer* renderer, int x, int y, SDL_Rect* clip)
{
	//Set rendering space and render to screen
	SDL_Rect renderQuad = { x, y, mWidth, mHeight };

	//Set clip rendering dimensions
	if (clip != NULL)
	{
		renderQuad.w = clip->w;
		renderQuad.h = clip->h;
	}

	//Render to screen
	SDL_RenderCopy(renderer, texture, clip, &renderQuad);
}

void LTexture::renderFlipVertical(SDL_Renderer* renderer, int x, int y, SDL_Rect* clip, double angle)
{
	//Set rendering space and render to screen
	SDL_Rect renderQuad = { x, y, mWidth, mHeight };
	SDL_Point point{ clip->w / 2, clip->h / 2 };

	//Set clip rendering dimensions
	if (clip != NULL)
	{
		renderQuad.w = clip->w;
		renderQuad.h = clip->h;
	}

	//Render to screen
		SDL_RenderCopyEx(renderer, texture, clip, &renderQuad, angle, &point, SDL_RendererFlip::SDL_FLIP_VERTICAL);
}

void LTexture::renderFlipHorizontal(SDL_Renderer* renderer, int x, int y, SDL_Rect* clip, double angle)
{
	//Set rendering space and render to screen
	SDL_Rect renderQuad = { x, y, mWidth, mHeight };
	SDL_Point point{ clip->w / 2, clip->h / 2 };

	//Set clip rendering dimensions
	if (clip != NULL)
	{
		renderQuad.w = clip->w;
		renderQuad.h = clip->h;
	}

	//Render to screen
	SDL_RenderCopyEx(renderer, texture, clip, &renderQuad, angle, &point, SDL_RendererFlip::SDL_FLIP_HORIZONTAL);
}
#pragma endregion

int LTexture::getWidth()
{
	return mWidth;
}

int LTexture::getHeight()
{
	return mHeight;
}