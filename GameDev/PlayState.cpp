#include "PlayState.h"

void PlayState::Init(GameStateManager* gsm)
{
 	this->gsm = gsm;

	this->gameOver = false;
	currentLevel = nullptr;
	//TODO LOAD PLAYER FROM FILE
	player = new Player();
	
	
	
	background = LTexture();

	SetCurrentLevel(LevelFactory::GetFirstLevel(this));
	// flush userinput to prevent crash during loadscreen

	//SDL_SetRenderDrawColor(gsm->GetBehaviour()->GetRenderer(), 80, 30, 30, 255);

	SoundBank::GetInstance()->PlaySFX(SoundEffectType::LETSROCK);
	hud = new HUD(gsm->GetBehaviour()->GetRenderer(), player);
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

	//background.render(gsm->GetBehaviour()->GetRenderer(), 0, -450,0, &backgroundRect); //TEMP!

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
	this->currentLevel->Init(bf);
	gsm->SetBehaviour(bf);
	player = this->currentLevel->SetPlayer(player);
	this->gsm->GetBehaviour()->SetLevelToCamera(player, currentLevel->GetLvlHeight(), currentLevel->GetLvlWidth());
	this->currentLevel->GetParallaxBackGround()->InitializeFixXPos(); //use this to fix XPos after the player is set in the current level
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

