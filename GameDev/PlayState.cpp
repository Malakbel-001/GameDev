#include "PlayState.h"

PlayState PlayState::m_PlayState;

PlayState::PlayState() { }

void PlayState::Init(GameStateManager *gsm)
{
	this->gsm = gsm;

	this->gameOver = false;
	this->timesUpdate = 0;


	SetCurrentLevel(LevelFactory::GetFirstLevel());
	factory = new BehaviourFactory();
	drawableContainer = new DrawableContainer();
	currentLevel->drawableContainer = drawableContainer;
	currentLevel->Init();
	//drawableContainer->Add(factory->CreateDrawableBehaviour(BehaviourType::DRAWABLEBEHAVIOUR));
	EntityFactory ent = EntityFactory(*currentLevel->GetWorld());
	BehaviourFactory fac = BehaviourFactory();
	p = ent.CreateEntity(100, 100, EntityType::PLAYER);
	drawableContainer->Add(fac.CreateDrawableBehaviour(BehaviourType::DRAWABLEBEHAVIOUR,p ));

	
	camera = new Camera(0, 0, ScreenWidth, ScreenHeight, currentLevel->GetLvlWidth(), currentLevel->GetLvlHeight());

	// flush userinput to prevent crash during loadscreen
	gsm->FlushEvents();

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
			
			break;
		}
		break;
	}
}

void PlayState::Update(double dt)
{
//	currentLevel->Update(dt);

	// TODO: fix dinemic FPS count
	// do last
	
	currentLevel->GetWorld()->Step(1, 5, 5);

}

void PlayState::Draw()
{
	
	currentLevel->Draw();
	
	drawableContainer->Draw(gsm->sdlInitializer->GetRenderer());
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
