#include "HUD.h"

HUD::HUD(SDL_Renderer* renderer, Player* player) {
	this->renderer = renderer;
	this->player = player;

	SetHPBarRectangle(20, 20, 200, 20);
	SetHUDFont("Resources/fonts/manaspc.tff", 12);
}

HUD::~HUD() {
	this->Cleanup();
}

//setDrawRect & fillRect
void HUD::SetHPBarRectangle(int x, int y, int width, int height) {
	drawRect = { x, y, width, height };
	fillRect = { x, y, width, height };
}

void HUD::SetHUDFont(char* path, int ptsize) {
	if (TTF_Init() == -1) //initialize TTF
		std::cout << " Failed to initialize TTF : " << TTF_GetError() << std::endl;

	hudFont = TTF_OpenFont("Resources/fonts/manaspc.ttf", 12);

	if (hudFont == nullptr)
		std::cout << " Failed to load font : " << TTF_GetError() << std::endl;
}

void HUD::Draw() {
	//amount to diminish hpBar
	float diminisher = (float)player->GetHealth() / player->GetMaxHealth();
	DrawHPBar(diminisher, Color(75, 205, 50, 255));

	DrawAmmo();

	DrawScore();

	//Optional: Draw Timer
}

void HUD::DrawHPBar(float diminisher, SDL_Color hpColor) {
	SDL_GetRenderDrawColor(renderer, &oldColor.r, &oldColor.g, &oldColor.g, &oldColor.a); //keep old draw color for later
	
	int width = drawRect.w;
	int newWidth = Clamp(diminisher * width, 0, width); //clamping just in case
	fillRect.w = newWidth; //update width

	SDL_SetRenderDrawColor(renderer, hpColor.r, hpColor.g * diminisher, hpColor.b, hpColor.a);
	SDL_RenderFillRect(renderer, &fillRect); //draw HP with the right color

	SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
	SDL_RenderDrawRect(renderer, &drawRect); //draw HPBar Border/Container

	SDL_SetRenderDrawColor(renderer, oldColor.r, oldColor.g, oldColor.b, oldColor.a); //set old draw color back
}

void HUD::DrawAmmo() {

}

void HUD::DrawScore() {

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
	
	//fonts
	TTF_CloseFont(hudFont);
}