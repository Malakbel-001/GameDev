#include "EditorState.h"

//get empty level / clean level
EditorState::EditorState() {
	newLevel = LevelFactory::GetEmptyLevel();
}

//load specific level 1 - 3
EditorState::EditorState(int level) {
	newLevel = LevelFactory::GetSpecificLevel(level);
}

//load level from file: HomeCooked Levels
EditorState::EditorState(std::string _loadLevel) {
	this->loadLevel = _loadLevel;
}

void EditorState::Init(GameStateManager *gsm) {
	//Standard @Initialization
	this->gsm = gsm;
	editorDrawableContainer = new DrawableContainer();
	uselessMoveableContainer = new MoveableContainer();
	selectedEntity = nullptr;
	scroll = 0;
	lockButtonTicks = SDL_GetTicks();

	behaviourFactory = gsm->GetBehaviour(); //need this to create (temporary) drawableBehaviours

	//Load a level if the loadLevel constructor was used
	if (loadLevel != "") {
		newLevel = LevelFactory::LoadLevel(behaviourFactory, loadLevel);
	}

	//initialize level
	newLevel->Init(gsm->GetBehaviour());

	//initialize entities for use in the level editor
	actorTypeList = newLevel->GetEntityFactory()->GetActorTypeList();
	entityTypeList = newLevel->GetEntityFactory()->GetEntityTypeList();

	//set the camera
	manualCamera = behaviourFactory->SetManualCamera(newLevel->GetLvlWidth(), newLevel->GetLvlHeight());

	//set the background
	newLevel->GetParallaxBackGround()->InitializeFixXPos(); //use this after PBG and the Camera is set

	//grab first entity from the list and set it
	SetSelectedEntity();
}

EditorState::~EditorState() {
	//Cleanup();
}

void EditorState::Cleanup() {
	//TODO don't forget!
}

void EditorState::Pause() {
	//does nothing atm
}

void EditorState::Resume() {
	//nothing to resume yet
}

void EditorState::HandleMouseEvents(SDL_Event mainEvent) {
	switch (mainEvent.type) {
		case SDL_MOUSEMOTION: {
			hoverX = mainEvent.motion.x;
			hoverY = mainEvent.motion.y;

			break;
		}
		case SDL_MOUSEWHEEL: { //TODO don't know how this works
			//scroll through list of entities
			if (mainEvent.wheel.y > 0) {
				if (scroll < entityTypeList->size() - 1) {
					scroll++;
				}
				else {
					scroll = 0;
				}
			}
			else {
				if (scroll > 0) {
					scroll--;
				}
				else {
					scroll = entityTypeList->size() - 1;
				}
			}
			SetSelectedEntity();
			break;
		}
		case SDL_MOUSEBUTTONDOWN: {
			if (mainEvent.button.button == SDL_BUTTON_LEFT) {
				//place entity
				newLevel->GetEntityFactory()->CreateEntity(static_cast<float>(hoverX - 400 + manualCamera->GetX() / ratio), 
					static_cast<float>(hoverY), entityTypeList->at(scroll));
			}
			else if (mainEvent.button.button == SDL_BUTTON_RIGHT) {
				//delete
				std::cout << "sdl_rightmousebutton" << std::endl;

				newLevel->GetEntityFactory()->ClickAndDeleteEntity(static_cast<float>(hoverX - 400 + manualCamera->GetX() / ratio),
					static_cast<float>(hoverY), newLevel->GetDrawableContainer(), newLevel->GetMoveableContainer(), nullptr);
			}
			break;
		}
	}

}

void EditorState::HandleKeyEvents(std::unordered_map<SDL_Keycode, bool>* _events) {
	//move camera using arrowkeys

	for (auto it = _events->begin(); it != _events->end(); ++it) {

		if (it->second)	{
			switch (it->first) {
				case SDLK_ESCAPE: {
					gsm->CreateGameState(GameStateType::EditorSubState);
					break;
					//go to the Level subMenu
					
					//in the subMenu, you can save the Level and set the name
					//or open another level

					//LevelFactory has the Save Function
				}

				case SDLK_w: {
					//move camera up - DISABLED
					//manualCamera->SetY(manualCamera->GetY() + 1);
					break;
				}
				case SDLK_a: {
					//move camera left
					manualCamera->SetX(manualCamera->GetX() - 1);
				}
				case SDLK_s: {
					//move camera down - DISABLED
					//manualCamera->SetY(manualCamera->GetY() - 1);
					break;
				}
				case SDLK_d: {
					//move camera right
					manualCamera->SetX(manualCamera->GetX() + 1);
					break;
				}

				case SDLK_UP: {
					if (lockButtonTicks + 100 < SDL_GetTicks()) {
						if (scroll < entityTypeList->size() - 1) {
							scroll++;
						}
						else {
							scroll = 0;
						}
						SetSelectedEntity();
						lockButtonTicks = SDL_GetTicks();
					}
					break;
				}
				case SDLK_DOWN: {
					if (lockButtonTicks + 100 < SDL_GetTicks()) {
						if (scroll > 0) {
							scroll--;
						}
						else {
							scroll = entityTypeList->size() - 1;
						}
						SetSelectedEntity();
						lockButtonTicks = SDL_GetTicks();
					}
					break;
				}
			}
		}
	}
}

void EditorState::HandleTextInputEvents(SDL_Event event) {
	//no input text to handle
}

void EditorState::Move(float dt) {
	//nothing to move
}

void EditorState::Update(float dt, float gameSpeedManipulator) {
	//nothing to update
}

void EditorState::Draw(float dt, float gameSpeedManipulator) {
	//display current level
	if (newLevel->GetParallaxBackGround()) {
		newLevel->GetParallaxBackGround()->Draw();
	}

	if (newLevel->GetDrawableContainer()) {
		newLevel->GetDrawableContainer()->Draw(dt, gameSpeedManipulator);
	}

	selectedEntity->SetXpos(GetXPositionEntity());
	selectedEntity->SetYpos(GetYPositionEntity());

	editorDrawableContainer->Draw(dt, gameSpeedManipulator);

	//no HUD at the moment
}

Level* EditorState::GetLevel(){
	return newLevel;
}

string EditorState::GetLevelPath(){
	return loadLevel;
}


void EditorState::SetSelectedEntity() {
	editorDrawableContainer->Cleanup();
	
	if (selectedEntity) {
		delete selectedEntity; //this one is important
		selectedEntity = nullptr; //just in case
	}

	selectedEntity = new BareEntity();
	selectedEntity->Init(0, 0, 0, EntityState::DEFAULT, entityTypeList->at(scroll), behaviourFactory, editorDrawableContainer, uselessMoveableContainer);
}

float EditorState::GetXPositionEntity() {
	//400 * ratio is temporary fix!
	return static_cast<float>((hoverX * ratio) + (manualCamera->GetX()) - 400 * ratio);
}
float EditorState::GetYPositionEntity() {
	return static_cast<float>(hoverY * ratio);
}