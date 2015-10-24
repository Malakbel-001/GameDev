#include "PlayState.h"


PlayState PlayState::m_PlayState;

PlayState::PlayState() { }

void PlayState::init(GameStateManager *gsm)
{
	this->gsm = gsm;

	this->gameOver = false;
	this->timesUpdate = 0;

	camera = new Camera(0, 0, ScreenWidth, ScreenHeight, /*levlWitdh*/100,/*levelHight*/100 );

	p = new Player();
	setCurrentLevel(LevelFactory::GetFirstLevel());
	GameStateManager::Instance()->flushEvents();

	std::cout << "PlayState";
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


void PlayState::handleEvents(SDL_Event mainEvent) {

	//Retrieve input
	int x = 0;
	int y = 0;
	switch (mainEvent.type) 
	{
	case SDLK_TAB:
		std::cout << "handleInput tab switch";
		break;
	default:
		std::cout << "handleInput default switch";
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
