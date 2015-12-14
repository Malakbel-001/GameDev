#include "HUD.h"
#include "Weapon.h"

HUD::HUD(SDL_Renderer* renderer, Player* player) {
	this->renderer = renderer;
	this->player = player;
	timer = Timer();

	screenWidth = new int;
	screenHeight = new int;
	SDL_GetWindowSize(SDL_GetWindowFromID(1), screenWidth, screenHeight);
	wasFullScreen = Utilities::IsFullScreen();

	hudFont = Utilities::SetFont("Resources/fonts/manaspc.ttf", 12);
	timerFont = Utilities::SetFont("Resources/fonts/manaspc.ttf", 20);
	SetSurfacesAndTextures();
	SetRectangles();
}

HUD::~HUD() {
	this->Cleanup();
}

//setDrawRect & fillRect
void HUD::SetRectangles() {
	//HP Upper Left, Always Standard
	int leftX = 20;
	int allY = 20; //y to draw all
	int hpWidth = 200;
	int hpHeight = 30;

	drawHPRect = { leftX, allY, hpWidth, hpHeight };
	fillHPRect = { leftX, allY, hpWidth, hpHeight };

	amountHPRect =	{ drawHPRect.x + 20, drawHPRect.y + drawHPRect.h, drawHPRect.w - 40, 20 };
	hpRect =		{ amountHPRect.x + 30, amountHPRect.y + 5, hpSurface->w, hpSurface->h };

	//Stats Upper Middle, Calculate Width!
	int spaceFromStatsRect = 10;
	int spaceInBetween = 20;
	int calcWidthStats = spaceFromStatsRect + ammoSurface->w + spaceInBetween + scoreSurface->w + spaceFromStatsRect;
	//height = magic number, durr.

	int middleX = (*screenWidth / 2) - (calcWidthStats / 2);
	drawStatsRect =	{ middleX, allY, calcWidthStats, 50 };
	ammoRect = { drawStatsRect.x + spaceFromStatsRect, drawStatsRect.y + 10, ammoSurface->w, ammoSurface->h };
	scoreRect = { ammoRect.x + ammoRect.w + spaceInBetween, ammoRect.y, scoreSurface->w, scoreSurface->h };

	//Timer Upper Right
	int rightX = *screenWidth - 100;
	timerRect = { rightX, allY, 95, 35 };
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

	//Draw Timer Rectangle & Border
	SDL_SetRenderDrawColor(renderer, 0, 0, 0, 225);
	SDL_RenderFillRect(renderer, &timerRect);

	SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255); //white border
	SDL_RenderDrawRect(renderer, &timerRect);

	//Draw Timer
	if (timer.GetCurrentMinutes() < 10) {
		Utilities::DrawTextHelper(renderer, timerFont, "0" + std::to_string(timer.GetCurrentMinutes()), *screenWidth - 90,
			drawStatsRect.y + 10, Utilities::GetColor(255, 255, 255, 255));
	}
	else {
		Utilities::DrawTextHelper(renderer, timerFont, std::to_string(timer.GetCurrentMinutes()), *screenWidth - 90,
			drawStatsRect.y + 10, Utilities::GetColor(255, 255, 255, 255));
	}
	Utilities::DrawTextHelper(renderer, timerFont,":", *screenWidth - 60,
		drawStatsRect.y + 10, Utilities::GetColor(255, 255, 255, 255));
	if (timer.GetCurrentSeconds() < 10) {
		Utilities::DrawTextHelper(renderer, timerFont, "0"+std::to_string(timer.GetCurrentSeconds()), *screenWidth - 40,
			drawStatsRect.y + 10, Utilities::GetColor(255, 255, 255, 255));
	}
	else {
		Utilities::DrawTextHelper(renderer, timerFont, std::to_string(timer.GetCurrentSeconds()), *screenWidth - 40,
			drawStatsRect.y + 10, Utilities::GetColor(255, 255, 255, 255));
	}
}

void HUD::Cleanup() {
	//pointers
	SDL_FreeSurface(ammoSurface);
	SDL_DestroyTexture(ammoTexture);
	SDL_FreeSurface(scoreSurface);
	SDL_DestroyTexture(scoreTexture);
	SDL_FreeSurface(hpSurface);
	SDL_DestroyTexture(hpTexture);

	//fonts
	TTF_CloseFont(hudFont);
	TTF_CloseFont(timerFont);
}

void HUD::ResumeChecks() {
	timer.ResumeTimer();
	CheckIfScreenSizeChanged();
}

void HUD::CheckIfScreenSizeChanged() {
	//Screen Changed
	bool isFullScreen = Utilities::IsFullScreen();

	//check if the screen changed
	if (wasFullScreen != isFullScreen) {
		//set screenWidth & screenHeight
		SDL_GetWindowSize(SDL_GetWindowFromID(1), screenWidth, screenHeight);
		//this will also update the screenWidth and screenHeight inside the LayerContainers, because they have int pointers

		SetRectangles(); //set again on the right positions
	}

	wasFullScreen = isFullScreen; //keep the result for later check
}