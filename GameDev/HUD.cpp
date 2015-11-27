#include "HUD.h"

HUD::HUD(SDL_Renderer* renderer, Player* player) {
	this->renderer = renderer;
	this->player = player;
}

HUD::~HUD() {

}

void HUD::Draw() {
	float percentage = player->GetMaxHealth() / player->GetHealth();
	DrawHPBar(20, 20, 200, 20, percentage, Color(50, 205, 50, 255), Color(139, 0, 0, 255));

	DrawAmmo();

	DrawScore();

	//Optional: Draw Timer
}



void HUD::DrawHPBar(int x, int y, int w, int h, float Percent, SDL_Color FGColor, SDL_Color BGColor) {
	Percent = Percent > 1.f ? 1.f : Percent < 0.f ? 0.f : Percent;
	SDL_Color old;
	SDL_GetRenderDrawColor(renderer, &old.r, &old.g, &old.g, &old.a);
	SDL_Rect bgrect = { x, y, w, h };

	SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
	SDL_RenderDrawRect(renderer, &bgrect);

	SDL_SetRenderDrawColor(renderer, BGColor.r, BGColor.g, BGColor.b, BGColor.a);
	SDL_RenderFillRect(renderer, &bgrect);
	SDL_SetRenderDrawColor(renderer, FGColor.r, FGColor.g, FGColor.b, FGColor.a);
	int pw = (int)((float)w * Percent);
	int px = x + (w - pw);
	SDL_Rect fgrect = { px, y, pw, h };
	SDL_RenderFillRect(renderer, &fgrect);
	SDL_SetRenderDrawColor(renderer, old.r, old.g, old.b, old.a);
}

void HUD::DrawAmmo() {

}

void HUD::DrawScore() {

}

/*color - Returns an SDL_Color with the appropriate values*/
SDL_Color HUD::Color(Uint8 r, Uint8 g, Uint8 b, Uint8 a) {
	SDL_Color col = { r, g, b, a };
	return col;
}