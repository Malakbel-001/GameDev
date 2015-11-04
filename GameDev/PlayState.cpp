#include "PlayState.h"




void PlayState::Init(GameStateManager* gsm, BehaviourFactory* bf)
{
	this->gsm = gsm;

	this->gameOver = false;

	//TODO LOAD PLAYER FROM FILE
	player = new Player();
	
	

	SetCurrentLevel(LevelFactory::GetFirstLevel());
	// flush userinput to prevent crash during loadscreen


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


void PlayState::HandleEvents(SDL_Event mainEvent)
{
	//Retrieve input
	int x = 0;
	int y = 0;
	switch (mainEvent.type) 
	{
	case SDL_KEYDOWN:
		switch (mainEvent.key.keysym.sym)
		{
		case SDLK_SPACE:
			std::cout << "PlayState handleInput spacebar switch \n";
			break;
		case SDL_BUTTON_LEFT:
			std::cout << "PlayState handleInput left mouse clicked switch \n";
			break;
		default:
			std::cout << "Playstate handleInput default switch \n";
			break;
		}
		break;
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
