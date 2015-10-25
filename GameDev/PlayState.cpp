#include "PlayState.h"

PlayState PlayState::m_PlayState;

PlayState::PlayState() { }

void PlayState::init(GameStateManager *gsm)
{
	this->gsm = gsm;

	this->gameOver = false;
	this->timesUpdate = 0;

	setCurrentLevel(LevelFactory::GetFirstLevel());
	camera = new Camera(0, 0, ScreenWidth, ScreenHeight, currentLevel->getLvlWidth(), currentLevel->getLvlHeight());
	p = new Player(camera);

	// flush userinput to prevent crash during loadscreen
	GameStateManager::Instance()->flushEvents();

	std::cout << "PlayState \n";
}

void PlayState::loadGame()
{
	
}

void PlayState::setFileToLoad(std::string fileName)
{
	this->fileToLoad = fileName;
}

void PlayState::pause()
{
	
}

void PlayState::resume()
{

}


void PlayState::handleEvents(SDL_Event mainEvent)
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

void PlayState::update(double dt)
{
	currentLevel->update(dt);
}

void PlayState::draw()
{
	currentLevel->draw();
	p->draw();
}

Level* PlayState::getCurrentLevel()
{
	return this->currentLevel;
}

void PlayState::setCurrentLevel(Level* lvl)
{
	this->currentLevel = lvl;
}

void PlayState::setGameOver(bool gameOver)
{
	this->gameOver = gameOver;
}

Player* PlayState::getPlayer()
{
	return this->p;
}

Camera* PlayState::getCamera()
{
	return this->camera;
}


void PlayState::cleanup()
{
	delete p;
	delete currentLevel;

	p = nullptr;
	camera = nullptr;
}

PlayState::~PlayState()
{
	this->cleanup();
}
