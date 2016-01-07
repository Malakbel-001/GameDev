#include "EditorState.h"

EditorState::EditorState() {
	newLevel = LevelFactory::GetEmptyLevel();
	//newLevel = LevelFactory::GetSpecificLevel(2);
	
	editorDrawableContainer = new DrawableContainer();
	selectedEntity = nullptr;
	scroll = 0;
	lockButtonTicks = SDL_GetTicks();
}

EditorState::~EditorState() {
	//Cleanup();
}

void EditorState::Cleanup() {
	//TODO don't forget!
}

void EditorState::Init(GameStateManager *gsm) {
	//beware!
	//newLevel->Init(gsm->GetBehaviour());

	behaviourFactory = gsm->GetBehaviour(); //need this to create (temporary) drawableBehaviours

	//newLevel->SetEntityFactory(gsm->GetBehaviour());
	newLevel->Init(gsm->GetBehaviour());
	actorTypeList = newLevel->GetEntityFactory()->GetActorTypeList();
	entityTypeList = newLevel->GetEntityFactory()->GetEntityTypeList();

	manualCamera = behaviourFactory->SetManualCamera(newLevel->GetLvlWidth(), newLevel->GetLvlHeight());
	newLevel->GetParallaxBackGround()->InitializeFixXPos(); //use this after PBG and the Camera is set

	//grab first entity from the list and set it
	SetSelectedEntity();
}

void EditorState::Pause() {
	//does nothing atm
}

void EditorState::Resume() {
	//nothing to resume yet
}

void EditorState::HandleMouseEvents(SDL_Event mainEvent) {
	//follow mouse movements, show level entity

	switch (mainEvent.type) {
		case SDL_MOUSEMOTION: {
			hoverX = mainEvent.motion.x;
			hoverY = mainEvent.motion.y;

			//debugging
			std::cout << "HoverX " << hoverX << std::endl;
			std::cout << "HoverY " << hoverY << std::endl;
			std::cout << std::endl;

			break;
		}
		case SDL_MOUSEWHEEL: { //TODO don't know how this works
			//scroll through list of entities

			std::cout << "scroll: " << mainEvent.wheel.y << std::endl; //doesn't work
			break;
		}
		case SDL_MOUSEBUTTONDOWN: {
			//place entity
			break;
		}
	}

}

void EditorState::HandleKeyEvents(std::unordered_map<SDL_Keycode, bool>* _events) {
	//move camera using arrowkeys

	for (auto it = _events->begin(); it != _events->end(); ++it) {

		if (it->second)	{
			switch (it->first) {
				case SDLK_w: {
					//move camera up
					manualCamera->SetY(manualCamera->GetY() + 1);
					break;
				}
				case SDLK_a: {
					//move camera left
					manualCamera->SetX(manualCamera->GetX() - 1);
				}
				case SDLK_s: {
					//move camera down
					manualCamera->SetY(manualCamera->GetY() - 1);
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
			std::cout << "camX: " << manualCamera->GetX() << std::endl;
			std::cout << "camY: " << manualCamera->GetY() << std::endl;
			std::cout << std::endl;
		}
	}
}

void EditorState::HandleTextInputEvents(SDL_Event event) {
	//new stuff hmm
}

void EditorState::Update(float dt, float gameSpeedManipulator) {
	//don't know what to update
}

void EditorState::Draw(float dt, float gameSpeedManipulator) {
	//display current level
	if (newLevel->GetParallaxBackGround()) {
		newLevel->GetParallaxBackGround()->Draw();
	}

	if (newLevel->GetDrawableContainer()) {
		newLevel->GetDrawableContainer()->Draw(dt, gameSpeedManipulator);
	}

	//selectedEntity->SetXpos(0);
	//selectedEntity->SetYpos(0);

	//std::cout << "Ypos: " << selectedEntity->GetYpos() << std::endl;

	selectedEntity->SetXpos(static_cast<float>(hoverX * Ratio)); //cast to float
	selectedEntity->SetYpos(static_cast<float>(hoverY * Ratio)); //cast to float

	editorDrawableContainer->Draw(dt, gameSpeedManipulator);

	//no HUD at the moment
}

void EditorState::SetSelectedEntity() {
	editorDrawableContainer->Cleanup();
	
	if (selectedEntity) {
		delete selectedEntity; //this one is important
		selectedEntity = nullptr; //just in case
	}

	selectedEntity = new BareEntity();
	selectedEntity->Init(0, 0, 0, EntityState::DEFAULT, entityTypeList->at(scroll), behaviourFactory, editorDrawableContainer);
}