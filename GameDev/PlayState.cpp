#include "PlayState.h"




void PlayState::Init(GameStateManager* gsm)
{
	this->gsm = gsm;

	this->gameOver = false;

	//TODO LOAD PLAYER FROM FILE
	player = new Player();
	
	

	SetCurrentLevel(LevelFactory::GetFirstLevel());
	// flush userinput to prevent crash during loadscreen

	// Set color of renderer to red
	SDL_SetRenderDrawColor(gsm->GetBehaviour()->GetRenderer(), 80, 30, 30, 255);

	std::cout << "PlayState \n";
}

void PlayState::LoadGame()
{
	
}

void PlayState::SetFileToLoad(std::string fileName)
{
	std::cout << "SetFileToLoad not implemented yet";
}

void PlayState::Pause()
{
	std::cout << "Pause not implemented yet";
}

void PlayState::Resume()
{
	std::cout << "Resume not implemented yet";
}

void PlayState::HandleMouseEvents(SDL_Event mainEvent)
{
	std::cout << "Mouse events not implemented yet";
}

void PlayState::HandleKeyEvents(std::unordered_map<SDL_Keycode, bool>* _events)
{
	if (currentLevel->GetPlayer() != nullptr){
		b2Vec2 vel = currentLevel->GetPlayer()->GetBody()->GetLinearVelocity();


		float x = vel.x;
		float y = vel.y;
		
		for (auto it = _events->begin(); it != _events->end(); ++it){
		
			if (it->second)
			{
				switch (it->first)
				{
				case SDLK_w:
				
					y = y - 1000000;
				
					break;
				case SDLK_a:
					x = x - 1000;
					break;
				case SDLK_s:
					y = y + 1000;
					break;
				case SDLK_d:
					x = x + 1000;
					break;
				}
			}
		}
		vel.Set(x, y);
		currentLevel->GetPlayer()->GetBody()->SetLinearVelocity(vel);
	}

}

void PlayState::Update(float dt)
{
	currentLevel->Update(dt);

	// TODO: fix dinemic FPS count
	// do last
	
	
}

void PlayState::Draw()
{

	currentLevel->GetDrawableContainer()->Draw();

}

Level* PlayState::GetCurrentLevel()
{
	return this->currentLevel;
}

void PlayState::SetCurrentLevel(Level* lvl)
{
	this->currentLevel = lvl;
	this->currentLevel->init(gsm->GetBehaviour());
	this->currentLevel->SetPlayer(player);
}


Player* PlayState::GetPlayer()
{
	return this->player;
}


void PlayState::Cleanup()
{
	delete player;
	
	delete currentLevel;

	player = nullptr;

	currentLevel = nullptr;
}

PlayState::~PlayState()
{
	this->Cleanup();
}
