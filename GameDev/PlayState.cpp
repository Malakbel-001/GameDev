#include "PlayState.h"
PlayState::PlayState(int lvl){
	levelToLoad = lvl;
}
void PlayState::Init(GameStateManager* gsm)
{

	levelConfig = LevelConfig();
 	this->gsm = gsm;

	this->gameOver = false;
	currentLevel = nullptr;
	//TODO LOAD PLAYER FROM FILE
	player = new Player();
	
	
	
	background = LTexture();

	hud = new HUD();
	//SetCurrentLevel(LevelFactory::GetFirstLevel(this));
	SetCurrentLevel(LevelFactory::GetSpecificLevel(this, levelToLoad));
	// flush userinput to prevent crash during loadscreen

	//SDL_SetRenderDrawColor(gsm->GetBehaviour()->GetRenderer(), 80, 30, 30, 255);

	SoundBank::GetInstance()->PlaySFX(SoundEffectType::LETSROCK);
	std::cout << "PlayState \n";
	hud->Initialize(gsm->GetBehaviour()->GetRenderer(), player);
}

void PlayState::InitStartLevel(int lvl){
	SetCurrentLevel(LevelFactory::GetSpecificLevel(this, lvl));
}

void PlayState::GameOver(){
	SoundBank::GetInstance()->StopMusic();
	gsm->CreateGameState(GameStateType::GameOverState,0);
}

void PlayState::Victory(){
	SoundBank::GetInstance()->StopMusic();
	levelConfig.SaveLevelProgress("Level" + to_string(currentLevel->GetLevelId() + 1));
	gsm->CreateGameState(GameStateType::VictoryState,0);
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
	gsm->CreateGameState(GameStateType::PauseState,0);
}

void PlayState::Resume()
{
	//if screen changed, reload all layerContainers
	currentLevel->GetParallaxBackGround()->CheckIfScreenSizeChanged();
	hud->ResumeChecks();
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
					if (currentLevel->GetPlayer()->GetNumFootContacts() >  0){
						if (!(currentLevel->GetPlayer()->GetJumpTimeOut() > 0)){

							jump = true;
							impulse = 100;
							//SoundBank::GetInstance()->Play(SoundEffectType::CORRECT);

							currentLevel->GetPlayer()->GetBody()->ApplyLinearImpulse(b2Vec2(0, -impulse), currentLevel->GetPlayer()->GetBody()->GetWorldCenter(), true);
							currentLevel->GetPlayer()->SetJumpTimeOut(15);
						}
				

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
				case SDLK_UP:
					currentLevel->GetPlayer()->GetCurrentWeapon()->SetYVec(-1000);

						break;
				case SDLK_DOWN:
					currentLevel->GetPlayer()->GetCurrentWeapon()->SetYVec(+1000);
					break;

				case SDLK_LEFT:
					currentLevel->GetPlayer()->GetCurrentWeapon()->SetXVec(-1000);
					break;

				case SDLK_RIGHT:
					currentLevel->GetPlayer()->GetCurrentWeapon()->SetXVec(+1000);

					break;

				case SDLK_1:
					currentLevel->GetPlayer()->SwitchWeapon(0);
					break;
				case SDLK_2:
					currentLevel->GetPlayer()->SwitchWeapon(1);
					break;
				case SDLK_3:
					currentLevel->GetPlayer()->SwitchWeapon(2);
					break;
				case SDLK_4:
					currentLevel->GetPlayer()->SwitchWeapon(3);
					break;
				case SDLK_5:
					currentLevel->GetPlayer()->SwitchWeapon(4);
					break;
				case SDLK_6:
					currentLevel->GetPlayer()->SwitchWeapon(5);
					break;
				case SDLK_7:
					currentLevel->GetPlayer()->SwitchWeapon(6);
					break;
				case SDLK_8:
					currentLevel->GetPlayer()->SwitchWeapon(7);
					break;
				case SDLK_9:
					currentLevel->GetPlayer()->SwitchWeapon(8);
					break;
				
				case SDLK_ESCAPE:
					pause = true;
					
					break;

				case SDLK_l:
					SetCurrentLevel(LevelFactory::GetNextLevel(currentLevel, this));
					break;
				case SDLK_k:
					Victory();
					break;

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
					break;
				case SDLK_UP:
					if (currentLevel->GetPlayer()->GetCurrentWeapon()->GetVec().y == -1000){
						currentLevel->GetPlayer()->GetCurrentWeapon()->SetYVec(0);
					}

					break;
				case SDLK_DOWN:
					if (currentLevel->GetPlayer()->GetCurrentWeapon()->GetVec().y == 1000){
						currentLevel->GetPlayer()->GetCurrentWeapon()->SetYVec(0);
					}
				
					break;

				case SDLK_LEFT:
					if (currentLevel->GetPlayer()->GetCurrentWeapon()->GetVec().x == -1000){
						currentLevel->GetPlayer()->GetCurrentWeapon()->SetXVec(0);
					}
					break;

				case SDLK_RIGHT:
					if (currentLevel->GetPlayer()->GetCurrentWeapon()->GetVec().x == 1000 && currentLevel->GetPlayer()->GetCurrentWeapon()->GetVec().y != 0){
						currentLevel->GetPlayer()->GetCurrentWeapon()->SetXVec(0);
					}
					
					

					break;
				}
			}

		}
		
		if (!jump){
			vel.Set(x, y);
			//	currentLevel->GetPlayer()->GetBody()->ApplyForce(vel, currentLevel->GetPlayer()->GetBody()->GetWorldCenter(), true);
			currentLevel->GetPlayer()->GetBody()->SetLinearVelocity(vel);
		}
	
		if (currentLevel->GetPlayer()->GetJumpTimeOut() > 0){
			currentLevel->GetPlayer()->SetJumpTimeOut(currentLevel->GetPlayer()->GetJumpTimeOut() - 1);
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
	currentLevel->GetParallaxBackGround()->Draw();
	currentLevel->GetDrawableContainer()->Draw();
	hud->Draw();
}

Level* PlayState::GetCurrentLevel()
{
	return this->currentLevel;
}

void PlayState::SetCurrentLevel(Level* lvl)
{
	BehaviourFactory* bf = gsm->GetBehaviour();
	if (currentLevel != nullptr){
		delete currentLevel;
		currentLevel = nullptr;
	}
	this->currentLevel = lvl;

	//Note CurrentLevel is now new level
	this->currentLevel->Init(bf);
	gsm->SetBehaviour(bf);
	player = this->currentLevel->SetPlayer(player);
	this->gsm->GetBehaviour()->SetLevelToCamera(player, currentLevel->GetLvlHeight(), currentLevel->GetLvlWidth());
	this->currentLevel->GetParallaxBackGround()->InitializeFixXPos(); //use this to fix XPos after the player is set in the current level
	this->hud->SetTimer(currentLevel->GetTimer());
	SoundBank::GetInstance()->PlayBGM(SoundBgmType::REDALERT1);
}


Player* PlayState::GetPlayer()
{
	return this->player;
}


void PlayState::Cleanup()
{
	gsm->GetBehaviour()->ClearCamera();
	delete player;
	
	delete currentLevel;

	delete hud;

	
	player = nullptr;

	currentLevel = nullptr;

	hud = nullptr;
}

PlayState::~PlayState()
{
	this->Cleanup();
}

