#include "HighscoreMenu.h"
#include "MenuState.h"

HighscoreMenu::HighscoreMenu(MenuState* menu, SDL_Renderer* renderer, TTF_Font* textfont, TTF_Font* titlefont)
{
	highscoreConfig = HighscoreConfig();
	LoadScores();
	textColor = { 255, 255, 255, 255 }; // white
	hoverTextColor = { 255, 0, 0, 255 }; // red
	this->mainMenu = menu;
	this->renderer = renderer;
	this->textFont = textfont;
	this->titleFont = titlefont;
	MakeBackToMain(textColor);
	MakeHighscoreTitle(textColor);
	UpdateScore();
}

void HighscoreMenu::Init(){

}

void HighscoreMenu::UpdateScore(){
	MakeScore1(textColor);
	MakeScore2(textColor);
	MakeScore3(textColor);
	MakeScore4(textColor);
	MakeScore5(textColor);
	MakeScore6(textColor);
	MakeScore7(textColor);
	MakeScore8(textColor);
	MakeScore9(textColor);
	MakeScore10(textColor);
}

void HighscoreMenu::MakeBackToMain(SDL_Color color){
	SDL_Surface* backToMain = TTF_RenderText_Blended(textFont, "Back", color);
	backToMainTexture = SurfaceToTexture(backToMain);

	SDL_QueryTexture(backToMainTexture, NULL, NULL, &backToMainRect.w, &backToMainRect.h);
	backToMainRect.x = 5;
	backToMainRect.y = 5;
	pos[0] = backToMainRect;
}

void HighscoreMenu::MakeHighscoreTitle(SDL_Color color){
	SDL_Surface* highscoreTitle = TTF_RenderText_Blended(titleFont, "Highscores", color);
	highscoreTitleTexture = SurfaceToTexture(highscoreTitle);

	SDL_QueryTexture(highscoreTitleTexture, NULL, NULL, &highscoreTitleRect.w, &highscoreTitleRect.h);
	highscoreTitleRect.x = 540 - (highscoreTitleRect.w / 2);
	highscoreTitleRect.y = 5;
	pos[1] = highscoreTitleRect;
}

void HighscoreMenu::MakeScore1(SDL_Color color){
	string scores = GetScores(1);
	SDL_Surface* highscore = TTF_RenderText_Blended(textFont, scores.c_str(), color);
	score1Texture = SurfaceToTexture(highscore);

	SDL_QueryTexture(score1Texture, NULL, NULL, &score1Rect.w, &score1Rect.h);
	score1Rect.x = 5;
	score1Rect.y = 220;
	pos[2] = score1Rect;
}
void HighscoreMenu::MakeScore2(SDL_Color color){
	string scores = GetScores(2);
	SDL_Surface* highscore = TTF_RenderText_Blended(textFont, scores.c_str(), color);
	score2Texture = SurfaceToTexture(highscore);

	SDL_QueryTexture(score2Texture, NULL, NULL, &score2Rect.w, &score2Rect.h);
	score2Rect.x = 5;
	score2Rect.y = score1Rect.y + score1Rect.h + 10;
	pos[3] = score2Rect;
}
void HighscoreMenu::MakeScore3(SDL_Color color){
	string scores = GetScores(3);
	SDL_Surface* highscore = TTF_RenderText_Blended(textFont, scores.c_str(), color);
	score3Texture = SurfaceToTexture(highscore);

	SDL_QueryTexture(score3Texture, NULL, NULL, &score3Rect.w, &score3Rect.h);
	score3Rect.x = 5;
	score3Rect.y = score2Rect.y + score2Rect.h + 10;
	pos[4] = score3Rect;
}
void HighscoreMenu::MakeScore4(SDL_Color color){
	string scores = GetScores(4);
	SDL_Surface* highscore = TTF_RenderText_Blended(textFont, scores.c_str(), color);
	score4Texture = SurfaceToTexture(highscore);

	SDL_QueryTexture(score4Texture, NULL, NULL, &score4Rect.w, &score4Rect.h);
	score4Rect.x = 5;
	score4Rect.y = score3Rect.y + score3Rect.h + 10;
	pos[5] = score4Rect;
}
void HighscoreMenu::MakeScore5(SDL_Color color){
	string scores = GetScores(5);
	SDL_Surface* highscore = TTF_RenderText_Blended(textFont, scores.c_str(), color);
	score5Texture = SurfaceToTexture(highscore);

	SDL_QueryTexture(score5Texture, NULL, NULL, &score5Rect.w, &score5Rect.h);
	score5Rect.x = 5;
	score5Rect.y = score4Rect.y + score4Rect.h + 10;
	pos[6] = score5Rect;
}
void HighscoreMenu::MakeScore6(SDL_Color color){
	string scores = GetScores(6);
	SDL_Surface* highscore = TTF_RenderText_Blended(textFont, scores.c_str(), color);
	score6Texture = SurfaceToTexture(highscore);

	SDL_QueryTexture(score6Texture, NULL, NULL, &score6Rect.w, &score6Rect.h);
	score6Rect.x = 5;
	score6Rect.y = score5Rect.y + score5Rect.h + 10;
	pos[7] = score6Rect;
}
void HighscoreMenu::MakeScore7(SDL_Color color){
	string scores = GetScores(7);
	SDL_Surface* highscore = TTF_RenderText_Blended(textFont, scores.c_str(), color);
	score7Texture = SurfaceToTexture(highscore);

	SDL_QueryTexture(score7Texture, NULL, NULL, &score7Rect.w, &score7Rect.h);
	score7Rect.x = 5;
	score7Rect.y = score6Rect.y + score6Rect.h + 10;
	pos[8] = score7Rect;
}
void HighscoreMenu::MakeScore8(SDL_Color color){
	string scores = GetScores(8);
	SDL_Surface* highscore = TTF_RenderText_Blended(textFont, scores.c_str(), color);
	score8Texture = SurfaceToTexture(highscore);

	SDL_QueryTexture(score8Texture, NULL, NULL, &score8Rect.w, &score8Rect.h);
	score8Rect.x = 5;
	score8Rect.y = score7Rect.y + score7Rect.h + 10;
	pos[9] = score8Rect;
}
void HighscoreMenu::MakeScore9(SDL_Color color){
	string scores = GetScores(9);
	SDL_Surface* highscore = TTF_RenderText_Blended(textFont, scores.c_str(), color);
	score9Texture = SurfaceToTexture(highscore);

	SDL_QueryTexture(score9Texture, NULL, NULL, &score9Rect.w, &score9Rect.h);
	score9Rect.x = 5;
	score9Rect.y = score8Rect.y + score8Rect.h + 10;
	pos[10] = score9Rect;
}
void HighscoreMenu::MakeScore10(SDL_Color color){
	string scores = GetScores(10);
	SDL_Surface* highscore = TTF_RenderText_Blended(textFont, scores.c_str(), color);
	score10Texture = SurfaceToTexture(highscore);

	SDL_QueryTexture(score10Texture, NULL, NULL, &score10Rect.w, &score10Rect.h);
	score10Rect.x = 5;
	score10Rect.y = score9Rect.y + score9Rect.h + 10;
	pos[11] = score10Rect;
}

string HighscoreMenu::GetScores(int i){
	string returnString = "";
	if (i <= highscores->size()){
		string tempName = highscores->at(i-1).GetName();
		int tempScore = highscores->at(i - 1).GetScore();
		vector<string> tempTime = highscores->at(i - 1).GetTime();
		returnString += to_string(i) + ". " + tempName + " with " + to_string(tempScore).c_str() + " point in " + tempTime.at(0) + " minutes and " + tempTime.at(1) + " seconds!";
		////sort(highscores->begin(), highscores->end());
		//for (auto it = highscores->begin(); it != highscores->end(); ++it) {
		//	string tempName = it->GetName();
		//	int tempScore = it->GetScore();
		//	vector<string> tempTime = it->GetTime();
		//	returnString += "- " + tempName + " with " + to_string(tempScore).c_str() + " point in " + tempTime.at(0) + " minutes and " + tempTime.at(1) + " seconds!\p";
		//}
	}
	else{
		returnString += to_string(i) + ". .......";
	}
	return returnString;
}

SDL_Texture* HighscoreMenu::SurfaceToTexture(SDL_Surface* surf)
{
	SDL_Texture* text;

	text = SDL_CreateTextureFromSurface(renderer, surf);

	SDL_FreeSurface(surf);

	return text;
}

void HighscoreMenu::SetupRenderer(){

}

void HighscoreMenu::Draw(){
	SDL_RenderCopy(renderer, highscoreTitleTexture, nullptr, &highscoreTitleRect);
	SDL_RenderCopy(renderer, backToMainTexture, nullptr, &backToMainRect);
	SDL_RenderCopy(renderer, score1Texture, nullptr, &score1Rect);
	SDL_RenderCopy(renderer, score2Texture, nullptr, &score2Rect);
	SDL_RenderCopy(renderer, score3Texture, nullptr, &score3Rect);
	SDL_RenderCopy(renderer, score4Texture, nullptr, &score4Rect);
	SDL_RenderCopy(renderer, score5Texture, nullptr, &score5Rect);
	SDL_RenderCopy(renderer, score6Texture, nullptr, &score6Rect);
	SDL_RenderCopy(renderer, score7Texture, nullptr, &score7Rect);
	SDL_RenderCopy(renderer, score8Texture, nullptr, &score8Rect);
	SDL_RenderCopy(renderer, score9Texture, nullptr, &score9Rect);
	SDL_RenderCopy(renderer, score10Texture, nullptr, &score10Rect);
}

void HighscoreMenu::Update(float dt){

}

void HighscoreMenu::Highlight(int item){
	switch (item){
	case -1:
	{
		MakeBackToMain(textColor);
		break;
	}
	case 0:
	{
		MakeBackToMain(hoverTextColor);
		break;
	}
	}
}

void HighscoreMenu::LoadScores(){
	highscoreConfig.LoadHighscore();
	highscores = highscoreConfig.GetHighscore();
	highscores = SortScoreByScore();
}

vector<Score>* HighscoreMenu::SortScoreByScore(){
	vector<Score>* score_copy = highscores;
	sort(score_copy->begin(), score_copy->end());
	return score_copy;
}

void HighscoreMenu::HandleKeyEvents(std::unordered_map<SDL_Keycode, bool>* _events)
{
	//std::cout << "Key events not implemented yet";
}

void HighscoreMenu::HandleMouseEvents(SDL_Event mainEvent)
{
	switch (mainEvent.type)
	{

		break;
	case SDL_MOUSEMOTION:
	{hoverX = mainEvent.motion.x;
	hoverY = mainEvent.motion.y;
	for (int ii = 0; ii < 5; ii++)
	{
		if (hoverX >= pos[ii].x && hoverX <= pos[ii].x + pos[ii].w && hoverY >= pos[ii].y && hoverY <= pos[ii].y + pos[ii].h){
			Highlight(ii);
			break;
		}
		else {
			Highlight(-1);

		}
	}
	break;
	}
	case SDL_MOUSEBUTTONDOWN:
		int x = mainEvent.button.x;
		int y = mainEvent.button.y;
		for (int i = 0; i < 8; i++)
		{
			if (x >= pos[i].x && x <= pos[i].x + pos[i].w && y >= pos[i].y && y <= pos[i].y + pos[i].h){
				switch (i){
				case 0:
					//back to main
					SoundBank::GetInstance()->PlaySFX(SoundEffectType::CORRECT);
					mainMenu->updateMenu(MenuEnum::Previous);
					break;
				}
			}
		}
	}
}


HighscoreMenu::~HighscoreMenu()
{
	delete highscores;
}
