
#include "PlayState.h"




void PlayState::Init(GameStateManager* gsm)
{
	this->gsm = gsm;

	this->gameOver = false;

	//TODO LOAD PLAYER FROM FILE
	player = new Player();
	
	

	SetCurrentLevel(LevelFactory::GetFirstLevel());
	// flush userinput to prevent crash during loadscreen

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
//	std::cout << "Mouse events not implemented yet";
}

void PlayState::HandleKeyEvents(std::unordered_map<SDL_Keycode, bool>* _events)
{
	if (currentLevel->GetPlayer() != nullptr){
		b2Vec2 vel = currentLevel->GetPlayer()->GetBody()->GetLinearVelocity();

		bool jump = false;
		float x = vel.x;
		float y = vel.y;
		float impulse;
		for (auto it = _events->begin(); it != _events->end(); ++it){
		
			if (it->second)
			{
				switch (it->first)
				{
				case SDLK_w:

					
					if (!currentLevel->GetPlayer()->GetBody()->GetLinearVelocity().y > 0){
						jump = true;
						impulse = 100;
						currentLevel->GetPlayer()->GetBody()->ApplyLinearImpulse(b2Vec2(0, -impulse), currentLevel->GetPlayer()->GetBody()->GetWorldCenter(), true);

					}
					break;
				case SDLK_a:
					
			//		cout << "e" << x;
					x =  -5;
			//		cout << " - " << x;
			
					break;
				case SDLK_s:
					y = 5;
					break;
				case SDLK_d:
					x = 5;

				}
			}
		}
		if (!jump){
			vel.Set(x, y);
			//	currentLevel->GetPlayer()->GetBody()->ApplyForce(vel, currentLevel->GetPlayer()->GetBody()->GetWorldCenter(), true);


			currentLevel->GetPlayer()->GetBody()->SetLinearVelocity(vel);
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

	currentLevel->GetDrawableContainer()->Draw();

}

Level* PlayState::GetCurrentLevel()
{
	return this->currentLevel;
}

void PlayState::SetCurrentLevel(Level* lvl)
{
	this->currentLevel = lvl;
	this->currentLevel->Init(gsm->GetBehaviour());
	player = this->currentLevel->SetPlayer(player);
	this->gsm->GetBehaviour()->SetLevelToCamera(player, currentLevel->GetLvlHeight(), currentLevel->GetLvlWidth());
	SoundBank::GetInstance()->PlayBGM(SoundBgmType::THUNDERSTRUCK, 64);
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

