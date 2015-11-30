#include "PlayState.h"




void PlayState::Init(GameStateManager* gsm)
{
	this->gsm = gsm;

	this->gameOver = false;

	//TODO LOAD PLAYER FROM FILE
	player = new Player();
	
	background = LTexture();
	//background.loadFromFile(gsm->GetBehaviour()->GetRenderer(), "level1.jpg");
	background.loadFromFile(gsm->GetBehaviour()->GetRenderer(), "level2.jpg");
	backgroundRect.h = background.getHeight()+100;
	backgroundRect.w = background.getWidth();
	backgroundRect.x = 0;
	backgroundRect.y = 0;

	SetCurrentLevel(LevelFactory::GetFirstLevel(this));
	// flush userinput to prevent crash during loadscreen

	//SDL_SetRenderDrawColor(gsm->GetBehaviour()->GetRenderer(), 80, 30, 30, 255);

	std::cout << "PlayState \n";
}

void PlayState::GameOver(){
	SoundBank::GetInstance()->StopMusic();
	gsm->CreateGameState(GameStateType::GameOverState);
}

void PlayState::Victory(){
	SoundBank::GetInstance()->StopMusic();
	gsm->CreateGameState(GameStateType::VictoryState);
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
	gsm->CreateGameState(GameStateType::PauseState);
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
		bool pause = false;
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
						SoundBank::GetInstance()->PlaySFX(SoundEffectType::CORRECT);
						currentLevel->GetPlayer()->GetBody()->ApplyLinearImpulse(b2Vec2(0, -impulse), currentLevel->GetPlayer()->GetBody()->GetWorldCenter(), true);
					}
					break;
				case SDLK_a:
					currentLevel->GetPlayer()->SetState(EntityState::WALKINGLEFT);
					//		cout << "e" << x;
					x = -5;
					//		cout << " - " << x;

					break;
				case SDLK_s:
					y = 5;
					break;
				case SDLK_d:
					currentLevel->GetPlayer()->SetState(EntityState::WALKINGRIGHT);
					x = 5;
					break;
				case SDLK_z:					
					currentLevel->GetPlayer()->GetCurrentWeapon()->Shoot(currentLevel->GetEntityFactory());
					break;
				case SDLK_ESCAPE:
					pause = true;
					
					break;
				case SDLK_l:
					SetCurrentLevel(LevelFactory::GetNextLevel(currentLevel, this));
				}
			}
			else
			{
				switch (it->first)
				{
				case SDLK_w:

					break;
				case SDLK_a:
					if (currentLevel->GetPlayer()->GetState() == EntityState::WALKINGLEFT)
						currentLevel->GetPlayer()->SetState(EntityState::IDLE);
					break;
				case SDLK_s:
					
					break;
				case SDLK_d:
					if (currentLevel->GetPlayer()->GetState() == EntityState::WALKINGRIGHT)
						currentLevel->GetPlayer()->SetState(EntityState::IDLE);
				}
			}

		}
		
		if (!jump){
			vel.Set(x, y);
			//	currentLevel->GetPlayer()->GetBody()->ApplyForce(vel, currentLevel->GetPlayer()->GetBody()->GetWorldCenter(), true);
			currentLevel->GetPlayer()->GetBody()->SetLinearVelocity(vel);
		}

		if (pause){
			Pause();
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
	SoundBank::GetInstance()->PlayBGM(SoundBgmType::REDALERT1);
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

