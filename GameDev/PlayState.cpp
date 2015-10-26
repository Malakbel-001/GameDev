#include "PlayState.h"

PlayState PlayState::m_PlayState;

PlayState::PlayState() { }

void PlayState::Init(GameStateManager *gsm)
{
	this->gsm = gsm;

	this->gameOver = false;
	this->timesUpdate = 0;

	SetCurrentLevel(LevelFactory::GetFirstLevel());
	p = new Player();
	camera = new Camera(0, 0, ScreenWidth, ScreenHeight, currentLevel->GetLvlWidth(), currentLevel->GetLvlHeight(), p);

	// flush userinput to prevent crash during loadscreen
	// GameStateManager::Instance()->FlushEvents();

	std::cout << "PlayState \n";
}

void PlayState::LoadGame()
{
	
}

void PlayState::SetFileToLoad(std::string fileName)
{
	this->fileToLoad = fileName;
}

void PlayState::Pause()
{
	
}

void PlayState::Resume()
{

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

void PlayState::Update(double dt)
{
	currentLevel->Update(dt);

	// TODO: fix dinemic FPS count
	// do last
	currentLevel->GetWorld()->Step(1.0 / 60.0, 5, 5);
}

void PlayState::Draw()
{
	currentLevel->Draw();
	p->Draw();
}

Level* PlayState::GetCurrentLevel()
{
	return this->currentLevel;
}

void PlayState::SetCurrentLevel(Level* lvl)
{
	this->currentLevel = lvl;
}

void PlayState::SetGameOver(bool gameOver)
{
	this->gameOver = gameOver;
}

Player* PlayState::GetPlayer()
{
	return this->p;
}

Camera* PlayState::GetCamera()
{
	return this->camera;
}

void PlayState::Cleanup()
{
	delete p;
	delete camera;
	delete currentLevel;

	p = nullptr;
	camera = nullptr;
	currentLevel = nullptr;
}

PlayState::~PlayState()
{
	this->Cleanup();
}
