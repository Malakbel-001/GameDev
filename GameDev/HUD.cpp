#include "HUD.h"
#include <iostream> //temp
using namespace std;

HUD::HUD(SDL_Renderer* renderer, Player* player) {
	this->renderer = renderer;
	this->player = player;
}

HUD::~HUD() {

}

void HUD::Draw() {
	//amount to diminish hpBar
	float diminisher = (float)player->GetHealth() / player->GetMaxHealth();
	DrawHPBar(20, 20, 200, 20, diminisher, Color(75, 205, 50, 255));
	cout << "Top fucking percentage: " << diminisher << endl;
	cout << "HP: " << player->GetHealth() << " MaxHP: " << player->GetMaxHealth() << endl;

	DrawAmmo();

	DrawScore();

	//Optional: Draw Timer
}



void HUD::DrawHPBar(int x, int y, int width, int height, float diminisher, SDL_Color hpColor) {
	SDL_Color oldColor;
	SDL_GetRenderDrawColor(renderer, &oldColor.r, &oldColor.g, &oldColor.g, &oldColor.a);

	int newWidth = Clamp(diminisher * width, 0, width); //clamping just in case

	SDL_SetRenderDrawColor(renderer, hpColor.r, hpColor.g * diminisher, hpColor.b, hpColor.a);
	SDL_Rect fillRect = { x, y, newWidth, height };
	SDL_RenderFillRect(renderer, &fillRect);

	SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
	SDL_Rect drawRect = { x, y, width, height };
	SDL_RenderDrawRect(renderer, &drawRect);

	SDL_SetRenderDrawColor(renderer, oldColor.r, oldColor.g, oldColor.b, oldColor.a); //set old draw color
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