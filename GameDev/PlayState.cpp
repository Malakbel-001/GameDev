#include "PlayState.h"
//CustomLevelMode
PlayState::PlayState(Level* lvl) {
	customLevelMode = true;
	this->currentLevel = lvl;
}
//Standard Mode
PlayState::PlayState(int lvl){
	customLevelMode = false;
	levelToLoad = lvl;
}

void PlayState::Init(GameStateManager* gsm)
{
 	this->gsm = gsm;

	this->gameOver = false;
	//TODO LOAD PLAYER FROM FILE
	player = new Player();
	accumulatedDtWeapon = 0;
	hud = new HUD();

	if (!customLevelMode) {
		customLevelMode = false;
		levelConfig = LevelConfig();
		currentLevel = nullptr;
		SetCurrentLevel(LevelFactory::GetSpecificLevel(this, levelToLoad));
	}
	else {
		SetCustomLevel();
	}

	hud->Initialize(gsm->GetBehaviour()->GetRenderer(), player);
}

void PlayState::InitStartLevel(int lvl){
	SetCurrentLevel(LevelFactory::GetSpecificLevel(this, lvl));
}

void PlayState::GameOver(){
	if (!customLevelMode) {
		//SoundBank::GetInstance()->StopMusic(); //not needed
		currentLevel->GetPlayer()->AddPlayTime(currentLevel->GetTimer()->GetCurrentMinutes(), currentLevel->GetTimer()->GetCurrentSeconds());
		gsm->CreateGameState(GameStateType::GameOverState);
	}
	else {
		SoundBank::GetInstance()->PlaySFX(SoundEffectType::GAMEOVER);
		gsm->PopState(); //go back to editor
	}
}

void PlayState::Victory(){
	if (!customLevelMode) {
		levelConfig.SaveLevelProgress("Level" + to_string(currentLevel->GetLevelId() + 1));
		currentLevel->GetPlayer()->AddPlayTime(currentLevel->GetTimer()->GetCurrentMinutes(), currentLevel->GetTimer()->GetCurrentSeconds());
		gsm->CreateGameState(GameStateType::VictoryState);
	}
	else { //customLevelMode - level editor
		SoundBank::GetInstance()->PlaySFX(SoundEffectType::WIN);
		gsm->PopState(); //go back to editor
	}
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
	SoundBank::GetInstance()->PlaySFX(SoundEffectType::LETSROCK);
	SoundBank::GetInstance()->PlayBGM(SoundBgmType::REDALERT1);

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
		Vehicle* vehicle = nullptr;
		for (auto it = _events->begin(); it != _events->end(); ++it){

			if (it->second)
			{
				switch (it->first)
				{
				case SDLK_w:
					if (currentLevel->GetPlayer()->GetNumFootContacts() >  0){
						if (!(currentLevel->GetPlayer()->GetJumpTimeOut() > 0)){

							jump = true;
							impulse = 210; //temp
							//SoundBank::GetInstance()->Play(SoundEffectType::CORRECT);

							currentLevel->GetPlayer()->GetBody()->ApplyLinearImpulse(b2Vec2(0, -impulse), currentLevel->GetPlayer()->GetBody()->GetWorldCenter(), true);
							currentLevel->GetPlayer()->SetJumpTimeOut(15);

							//TODO fix bounce effect -> jumping higher than intended! Not good.
						}
				

					}
					break;
				case SDLK_a:
					currentLevel->GetPlayer()->SetState(EntityState::WALKINGLEFT);
					currentLevel->GetPlayer()->SetFlipped(true);
					x = -25;

					break;
				case SDLK_s:
					//disabled for player
					break;
				case SDLK_d:
					currentLevel->GetPlayer()->SetState(EntityState::WALKINGRIGHT);
					currentLevel->GetPlayer()->SetFlipped(false);
					x = 25;
					break;
				case SDLK_e:
						if (currentLevel->GetPlayer()->GetType() == EntityType::PLAYER) {
							currentLevel->EnterVehicle();
						}
						else if (currentLevel->GetPlayer()->GetType() == EntityType::MECH) {
							currentLevel->ExitVehicle();
						}
						hud->SetPlayer(currentLevel->GetPlayer());

						it->second = false;
					break;
				case SDLK_SPACE: //temp changed W -> SPACE =P. Until remapping
					if (currentLevel->GetPlayer()->GetCurrentWeapon()->Shoot(currentLevel->GetEntityFactory(),
						accumulatedDtWeapon, currentManipulatorSpeed)) 
					{
						accumulatedDtWeapon = 0;
					}
					break;
				case SDLK_UP:
					currentLevel->GetPlayer()->GetCurrentWeapon()->SetYVec(-100);
					break;

				case SDLK_DOWN:
					currentLevel->GetPlayer()->GetCurrentWeapon()->SetYVec(+100);
					break;

				case SDLK_LEFT:
					currentLevel->GetPlayer()->GetCurrentWeapon()->SetXVec(-100);
					break;

				case SDLK_RIGHT:
					currentLevel->GetPlayer()->GetCurrentWeapon()->SetXVec(+100);
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
				case SDLK_F13:
					currentLevel->GetPlayer()->GodMode(true);
						break;
				case SDLK_F14:
					currentLevel->GetPlayer()->GetCurrentWeapon()->SetWeaponDmg(1000000);
					break;
				case SDLK_F15:
					currentLevel->GetWorld()->SetGravity(b2Vec2(0.0, static_cast<float>(2)));
					break;
				case SDLK_F16:
					if (currentLevel->GetPlayer()->GetCurrentWeapon()->GetFireSpeed() > 10){
						currentLevel->GetPlayer()->GetCurrentWeapon()->SetFireSpeed(currentLevel->GetPlayer()->GetCurrentWeapon()->GetFireSpeed() / 10);
					}
					
					break;
				case SDLK_F17:
					currentLevel->GetPlayer()->GetCurrentWeapon()->AddAmmo(1000);
					break;
				case SDLK_F18:			
					if (!customLevelMode) {
						SetCurrentLevel(LevelFactory::GetNextLevel(currentLevel, this));
					}
					break;

				case SDLK_ESCAPE:
					pause = true;
					break;

			
				

				}
			}
			else
			{
				switch (it->first)
				{
				case SDLK_F13:
					currentLevel->GetPlayer()->GodMode(false);
					break;				
				case SDLK_F14:
					currentLevel->GetPlayer()->GetCurrentWeapon()->SetWeaponDmg(20);
					break;
				case SDLK_F15:
					currentLevel->GetWorld()->SetGravity(b2Vec2(0.0, static_cast<float>(50)));
					break;
				case SDLK_F16:
					if (currentLevel->GetPlayer()->GetCurrentWeapon()->GetFireSpeed() < 250){
						currentLevel->GetPlayer()->GetCurrentWeapon()->SetFireSpeed(currentLevel->GetPlayer()->GetCurrentWeapon()->GetFireSpeed() * 10);
					}
					break;
				case SDLK_F17:
			

					break;
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
					if (currentLevel->GetPlayer()->GetCurrentWeapon()->GetVec().y == -100){
						currentLevel->GetPlayer()->GetCurrentWeapon()->SetYVec(0);
					}

					break;
				case SDLK_DOWN:
					if (currentLevel->GetPlayer()->GetCurrentWeapon()->GetVec().y == 100){
						currentLevel->GetPlayer()->GetCurrentWeapon()->SetYVec(0);
					}
				
					break;

				case SDLK_LEFT:
					if (currentLevel->GetPlayer()->GetCurrentWeapon()->GetVec().x == -100){
						currentLevel->GetPlayer()->GetCurrentWeapon()->SetXVec(0);
					}

					break;

				case SDLK_RIGHT:
					if (currentLevel->GetPlayer()->GetCurrentWeapon()->GetVec().x == 100 && currentLevel->GetPlayer()->GetCurrentWeapon()->GetVec().y != 0){
						currentLevel->GetPlayer()->GetCurrentWeapon()->SetXVec(0);
					}

					break;

				}
			}

		}
		
		if (!jump){
			//temporary solution. Makes controlling player lot easier
			if (currentLevel->GetPlayer()->GetState() == EntityState::IDLE) { 
				x = 0;
			}
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

void PlayState::HandleTextInputEvents(SDL_Event event) {

}

void PlayState::Update(float dt, float manipulatorSpeed) {
	accumulatedDtWeapon += dt; //accumulate Dt
	currentManipulatorSpeed = manipulatorSpeed;

	Move(dt);
	currentLevel->Update(dt, manipulatorSpeed);
}

void PlayState::Draw(float dt, float manipulatorSpeed)
{
	//TODO use manipulatorSpeed

	currentLevel->GetParallaxBackGround()->Draw();
	currentLevel->GetDrawableContainer()->Draw(dt, manipulatorSpeed);
	hud->Draw(dt, manipulatorSpeed);
}

void PlayState::Move(float dt){
	currentLevel->GetMoveableContainer()->Move(dt);
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

	this->currentLevel = lvl;// LevelFactory::LoadLevel(this, bf, "test");
	//Note CurrentLevel is now new level

	this->currentLevel->Init(bf,this);
	//LevelFactory::SaveLevel(lvl, "test");
	gsm->SetBehaviour(bf);
	player = this->currentLevel->SetPlayer(player);
	this->gsm->GetBehaviour()->SetLevelToCamera(player, currentLevel->GetLvlHeight(), currentLevel->GetLvlWidth());

	SoundBank::GetInstance()->PlayBGM(SoundBgmType::REDALERT1);


	this->currentLevel->GetParallaxBackGround()->InitializeFixXPos(); //use this to fix XPos after the player is set in the current level
	this->hud->SetTimer(currentLevel->GetTimer());

}

void PlayState::SetCustomLevel() {
	BehaviourFactory* bf = gsm->GetBehaviour();
	gsm->SetBehaviour(bf);
	player = this->currentLevel->SetPlayer(player);
	this->gsm->GetBehaviour()->SetLevelToCamera(player, currentLevel->GetLvlHeight(), currentLevel->GetLvlWidth());
	SoundBank::GetInstance()->PlayBGM(SoundBgmType::REDALERT1);
	//this->currentLevel->GetParallaxBackGround()->InitializeFixXPos(); //not needed, already set in editor mode
	this->hud->SetTimer(currentLevel->GetTimer());

	//do not forget
	this->currentLevel->SetPlayState(this);
}


Player* PlayState::GetPlayer()
{
	return currentLevel->GetPlayer();
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

bool PlayState::IsCustomLevelModeActivated() {
	return customLevelMode;
}
