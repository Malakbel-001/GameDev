#include "HUD.h"

HUD::HUD(SDL_Renderer* renderer, Player* player) {
	this->renderer = renderer;
	this->player = player;

	SetHUDFont("Resources/fonts/manaspc.tff", 50);
	SetRectangles(20, 20);
}

HUD::~HUD() {
	this->Cleanup();
}

//setDrawRect & fillRect
void HUD::SetRectangles(int x, int y) {
	int hpWidth = 200;
	int hpHeight = 20;

	drawHPRect = { x, y, hpWidth, hpHeight };
	fillHPRect = { x, y, hpWidth, hpHeight };

	drawStatsRect = { drawHPRect.x + 50 + hpWidth, y, 120, 50 }; //temp width
	ammoRect =		{ drawStatsRect.x + 10, drawStatsRect.y + 10, ammoSurface->w, ammoSurface->h };
	scoreRect = { ammoRect.x + ammoRect.w + 20, ammoRect.y, scoreSurface->w, scoreSurface->h };

	drawStatsRect.w = (scoreRect.x + scoreRect.w + 10) - drawStatsRect.x; //dynamic / fix width
}

void HUD::SetHUDFont(char* path, int ptsize) {
	if (TTF_Init() == -1) //initialize TTF
		std::cout << " Failed to initialize TTF : " << TTF_GetError() << std::endl;

	hudFont = TTF_OpenFont("Resources/fonts/manaspc.ttf", 12);

	if (hudFont == nullptr)
		std::cout << " Failed to load font : " << TTF_GetError() << std::endl;

	//FWApplication would normally create use and SDL_FreeSurface() + SDL_DestroyTexture()
	//this is better for performance reasons (when it's possible), create once, reuse whenever, FreeSurface() and DestroyTexture() in Cleanup()
	ammoSurface = TTF_RenderText_Blended(hudFont, "Ammo", Color(0, 0, 0, 255));
	ammoTexture = SDL_CreateTextureFromSurface(renderer, ammoSurface); //set ammoTexture

	scoreSurface = TTF_RenderText_Blended(hudFont, "Score", Color(0, 0, 0, 255));
	scoreTexture = SDL_CreateTextureFromSurface(renderer, scoreSurface);
}

void HUD::Draw() {
	SDL_GetRenderDrawColor(renderer, &oldColor.r, &oldColor.g, &oldColor.g, &oldColor.a); //keep old draw color for later

	//amount to diminish hpBar
	float diminisher = (float)player->GetHealth() / player->GetMaxHealth();
	DrawHPBar(diminisher, Color(75, 205, 50, 255));

	//draw Stats Border/Container
	SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
	SDL_RenderDrawRect(renderer, &drawStatsRect);

	DrawAmmo();

	DrawScore();

	//Optional: Draw Timer

	SDL_SetRenderDrawColor(renderer, oldColor.r, oldColor.g, oldColor.b, oldColor.a); //set old draw color back
}

void HUD::DrawHPBar(float diminisher, SDL_Color hpColor) {
	int width = drawHPRect.w;
	int newWidth = Clamp(diminisher * width, 0, width); //clamping just in case
	fillHPRect.w = newWidth; //update width

	SDL_SetRenderDrawColor(renderer, hpColor.r, hpColor.g * diminisher, hpColor.b, hpColor.a);
	SDL_RenderFillRect(renderer, &fillHPRect); //draw HP with the right color

	SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
	SDL_RenderDrawRect(renderer, &drawHPRect); //draw HPBar Border/Container
}

void HUD::DrawAmmo() {
	//Draw Ammo
	SDL_SetTextureBlendMode(ammoTexture, SDL_BLENDMODE_BLEND);
	SDL_RenderCopy(renderer, ammoTexture, NULL, &ammoRect);

	//Draw AmmoCounter / Amount
	SDL_Surface* counterSurface = TTF_RenderText_Blended(hudFont, "0", Color(0, 0, 0, 255)); //temp until I can get to ammo counter
	SDL_Texture* counterTexture = SDL_CreateTextureFromSurface(renderer, counterSurface);
	SDL_Rect counterRect = { ammoRect.x, ammoRect.y + ammoRect.h + 5, counterSurface->w, counterSurface->h };

	SDL_SetTextureBlendMode(counterTexture, SDL_BLENDMODE_BLEND); //tbh not sure what this does nor if it is needed... the internetwebz didn't make it very clear to me either
	SDL_RenderCopy(renderer, counterTexture, NULL, &counterRect);

	//cleanup counter stuff after using them
	SDL_FreeSurface(counterSurface);
	SDL_DestroyTexture(counterTexture);

}

void HUD::DrawScore() {
	//Draw Score
	SDL_SetTextureBlendMode(scoreTexture, SDL_BLENDMODE_BLEND);
	SDL_RenderCopy(renderer, scoreTexture, NULL, &scoreRect);

	//Draw ScoreCounter / Amount
	SDL_Surface* counterSurface = TTF_RenderText_Blended(hudFont, "0", Color(0, 0, 0, 255)); //temp until I can get to ammo counter
	SDL_Texture* counterTexture = SDL_CreateTextureFromSurface(renderer, counterSurface);
	SDL_Rect counterRect = { scoreRect.x, scoreRect.y + scoreRect.h + 5, counterSurface->w, counterSurface->h };

	SDL_SetTextureBlendMode(counterTexture, SDL_BLENDMODE_BLEND); //tbh not sure what this does nor if it is needed... the internetwebz didn't make it very clear to me either
	SDL_RenderCopy(renderer, counterTexture, NULL, &counterRect);

	//cleanup counter stuff after using them
	SDL_FreeSurface(counterSurface);
	SDL_DestroyTexture(counterTexture);
}

//color - Returns an SDL_Color with the appropriate values
SDL_Color HUD::Color(Uint8 r, Uint8 g, Uint8 b, Uint8 a) {
	SDL_Color col = { r, g, b, a };
	return col;
}

//var not higher or lower than min and max
int HUD::Clamp(int var, int min, int max) {
	if (var >= max)
		return var = max;
	else if (var <= min)
		return var = min;
	else
		return var;
}

void HUD::Cleanup() {
	//pointers
	SDL_FreeSurface(ammoSurface);
	SDL_DestroyTexture(ammoTexture);
	
	//fonts
	TTF_CloseFont(hudFont);
}