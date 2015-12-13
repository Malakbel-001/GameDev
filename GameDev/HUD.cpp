#include "HUD.h"
#include "Weapon.h"

HUD::HUD(SDL_Renderer* renderer, Player* player) {
	this->renderer = renderer;
	this->player = player;
	timer = Timer();

	hudFont = Utilities::SetFont("Resources/fonts/manaspc.ttf", 12);
	SetSurfacesAndTextures();
	SetRectangles(20, 20);
}

HUD::~HUD() {
	this->Cleanup();
}

//setDrawRect & fillRect
void HUD::SetRectangles(int x, int y) {
	int hpWidth = 200;
	int hpHeight = 30;

	drawHPRect = { x, y, hpWidth, hpHeight };
	fillHPRect = { x, y, hpWidth, hpHeight };

	amountHPRect =	{ drawHPRect.x + 20, drawHPRect.y + drawHPRect.h, drawHPRect.w - 40, 20 };
	hpRect =		{ amountHPRect.x + 30, amountHPRect.y + 5, hpSurface->w, hpSurface->h };

	drawStatsRect = { drawHPRect.x + 50 + hpWidth, y, 120, 50 }; //temp width
	ammoRect =		{ drawStatsRect.x + 10, drawStatsRect.y + 10, ammoSurface->w, ammoSurface->h };
	scoreRect =		{ ammoRect.x + ammoRect.w + 20, ammoRect.y, scoreSurface->w, scoreSurface->h };

	drawStatsRect.w = (scoreRect.x + scoreRect.w + 10) - drawStatsRect.x; //dynamic / fix width
}

void HUD::SetSurfacesAndTextures() {
	//FWApplication would normally create use and SDL_FreeSurface() + SDL_DestroyTexture()
	//this is better for performance reasons (when it's possible), create once, reuse whenever, FreeSurface() and DestroyTexture() in Cleanup()
	ammoSurface = TTF_RenderText_Blended(hudFont, "Ammo", Utilities::GetColor(255, 255, 255, 255));
	ammoTexture = SDL_CreateTextureFromSurface(renderer, ammoSurface); //set ammoTexture

	scoreSurface = TTF_RenderText_Blended(hudFont, "Score", Utilities::GetColor(255, 255, 255, 255));
	scoreTexture = SDL_CreateTextureFromSurface(renderer, scoreSurface);

	hpSurface = TTF_RenderText_Blended(hudFont, "Health:", Utilities::GetColor(255, 255, 255, 255));
	hpTexture = SDL_CreateTextureFromSurface(renderer, hpSurface);
}

void HUD::Draw() {
	SDL_SetRenderDrawBlendMode(renderer, SDL_BLENDMODE_BLEND); //enabling alpha values on (SDL)Render methods: Fill(Rect) and Line

	SDL_GetRenderDrawColor(renderer, &oldColor.r, &oldColor.g, &oldColor.g, &oldColor.a); //keep old draw color for later

	DrawHealth(); //NEW - little bit alpha

	//draw Stats Border/Container
	SDL_SetRenderDrawColor(renderer, 0, 0, 0, 100); //alpha number = 100 in order to make it transparent
	SDL_RenderFillRect(renderer, &drawStatsRect);

	SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255); //draw border
	SDL_RenderDrawRect(renderer, &drawStatsRect);

	DrawAmmo();
	DrawScore();
	DrawTimer();

	SDL_SetRenderDrawColor(renderer, oldColor.r, oldColor.g, oldColor.b, oldColor.a); //set old draw color back
}

void HUD::DrawHealth() {
	//Draw HealthBar ------------------
	float diminisher = (float)player->GetHealth() / player->GetMaxHealth(); //amount to diminish hpBar

	int width = drawHPRect.w;
	int newWidth = diminisher * width;
	fillHPRect.w = newWidth; //update width

	SDL_SetRenderDrawColor(renderer, 75, 205 * diminisher, 50, 225);
	SDL_RenderFillRect(renderer, &fillHPRect); //draw HP with the right color

	SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
	SDL_RenderDrawRect(renderer, &drawHPRect); //draw HPBar Border/Container

	//Draw HP Amount ------------------
	SDL_SetRenderDrawColor(renderer, 0, 0, 0, 225); //black + transparent
	SDL_RenderFillRect(renderer, &amountHPRect);

	SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255); //black border
	SDL_RenderDrawRect(renderer, &amountHPRect);

	SDL_RenderCopy(renderer, hpTexture, NULL, &hpRect);

	Utilities::DrawTextHelper(renderer, hudFont, std::to_string(player->GetHealth()), hpRect.x + hpRect.w + 10, 
		hpRect.y, Utilities::GetColor(255, 255, 255, 255));
}

void HUD::DrawAmmo() {
	//Draw Ammo
	SDL_RenderCopy(renderer, ammoTexture, NULL, &ammoRect);

	//Draw AmmoCounter / Amount
	Utilities::DrawTextHelper(renderer, hudFont, std::to_string(player->GetCurrentWeapon()->GetAmmo()), ammoRect.x, 
		ammoRect.y + ammoRect.h + 5, Utilities::GetColor(255, 255, 255, 255));
}

void HUD::DrawScore() {
	//Draw Score
	SDL_RenderCopy(renderer, scoreTexture, NULL, &scoreRect);

	//Draw ScoreCounter / Amount
	Utilities::DrawTextHelper(renderer, hudFont, std::to_string(player->GetScore()), scoreRect.x, 
		scoreRect.y + scoreRect.h + 5, Utilities::GetColor(255, 255, 255, 255));
}

void HUD::DrawTimer() {
	timer.CalcDifference();

	//Draw Timer
	//cheat
	Utilities::DrawTextHelper(renderer, hudFont, std::to_string(timer.GetCurrentMinutes()), drawStatsRect.x + drawStatsRect.w + 20,
		drawStatsRect.y, Utilities::GetColor(0, 0, 0, 0));

	Utilities::DrawTextHelper(renderer, hudFont, std::to_string(timer.GetCurrentSeconds()), drawStatsRect.x + drawStatsRect.w + 40,
		drawStatsRect.y, Utilities::GetColor(0, 0, 0, 0));
}

void HUD::Cleanup() {
	//pointers
	SDL_FreeSurface(ammoSurface);
	SDL_DestroyTexture(ammoTexture);
	
	//fonts
	TTF_CloseFont(hudFont);
}

void HUD::ResumeTimer() {
	timer.ResumeTimer();
}