#include "PlayState.h"

void PlayState::Init(GameStateManager* gsm)
{
	this->gsm = gsm;

	this->gameOver = false;

	//TODO LOAD PLAYER FROM FILE
	player = new Player();

	background = LTexture();
	background.loadFromFile(gsm->GetBehaviour()->GetRenderer(), "level1.jpg");
	backgroundRect.h = background.getHeight();
	backgroundRect.w = background.getWidth();
	backgroundRect.x = 0;
	backgroundRect.y = 0;

	SetCurrentLevel(LevelFactory::GetFirstLevel(this));
	// flush userinput to prevent crash during loadscreen

	SDL_SetRenderDrawColor(gsm->GetBehaviour()->GetRenderer(), 80, 30, 30, 255);

	std::cout << "PlayState \n";
}

void PlayState::GameOver()
{
	SoundBank::GetInstance()->StopMusic();
	gsm->ChangeGameState();
}

void PlayState::LoadGame() { }

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
	//	std::cout << "Mouse events not implemented yet";
}

void PlayState::HandleKeyEvents(std::unordered_map<SDL_Keycode, bool>* _events)
{
	if (currentLevel->GetPlayer() != nullptr)
	{
		bool quit = false;

		for (auto it = _events->begin(); it != _events->end(); ++it)
		{
			if (it->second)
			{
				switch (it->first)
				{
					case SDLK_ESCAPE:
						quit = true;
						break;
					default:
						currentLevel->GetPlayer()->HandleKeyEvents(it->first);
						break;
				}
			}
		}
		if (quit)
		{
			GameOver();
		}
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
	background.render(gsm->GetBehaviour()->GetRenderer(), 0, -450, &backgroundRect); //TEMP!
	currentLevel->GetDrawableContainer()->Draw();
}

Level* PlayState::GetCurrentLevel()
{
	return this->currentLevel;
}

void PlayState::SetCurrentLevel(Level* lvl)
{

	BehaviourFactory* bf = gsm->GetBehaviour();
	this->currentLevel = lvl;
	this->currentLevel->Init(bf);
	gsm->SetBehaviour(bf);
	player = this->currentLevel->SetPlayer(player);
	this->gsm->GetBehaviour()->SetLevelToCamera(player, currentLevel->GetLvlHeight(), currentLevel->GetLvlWidth());
	SoundBank::GetInstance()->PlayBGM(SoundBgmType::THUNDERSTRUCK);
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
