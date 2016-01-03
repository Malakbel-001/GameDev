#include "EditorState.h"

EditorState::EditorState() {
	newLevel = LevelFactory::GetEmptyLevel();
	editorDrawableContainer = new DrawableContainer();
	selectedEntity = nullptr;
	scroll = 0;
}

EditorState::~EditorState() {
	//Cleanup();
}

void EditorState::Cleanup() {
	//TODO don't forget!
}

void EditorState::Init(GameStateManager *gsm) {
	behaviourFactory = gsm->GetBehaviour(); //need this to create (temporary) drawableBehaviours

	newLevel->SetEntityFactory(gsm->GetBehaviour());
	actorTypeList = newLevel->GetEntityFactory()->GetActorTypeList();
	entityTypeList = newLevel->GetEntityFactory()->GetEntityTypeList();

	manualCamera = behaviourFactory->SetManualCamera(newLevel->GetLvlWidth(), newLevel->GetLvlHeight());

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
					break;
				}
				case SDLK_a: {
					//move camera left
				}
				case SDLK_s: {
					//move camera down
					break;
				}
				case SDLK_d: {
					//move camera right
					break;
				}

				case SDLK_UP: {
					if (scroll < entityTypeList->size()) {
						scroll++;
					}
					else {
						scroll = 0;
					}
					SetSelectedEntity();
					break;
				}
				case SDLK_DOWN: {
					if (scroll > 0) {
						scroll--;
					}
					else {
						scroll = entityTypeList->size() - 1;
					}
					SetSelectedEntity();
					break;
				}
			}
		}
	}
}

void EditorState::HandleTextInputEvents(SDL_Event event) {
	//new stuff hmm
}

void EditorState::Update(float dt) {
	//don't know what to update
}

void EditorState::Draw() {
	//display current level
	if (newLevel->GetParallaxBackGround()) {
		newLevel->GetParallaxBackGround()->Draw();
	}

	if (newLevel->GetDrawableContainer()) {
		newLevel->GetDrawableContainer()->Draw();
	}

	//no HUD at the moment

	selectedEntity->SetXpos(0);
	selectedEntity->SetYpos(0);
	//selectedEntity->SetXpos(static_cast<float>(hoverX)); //cast to float
	//selectedEntity->SetYpos(static_cast<float>(hoverY)); //cast to float

	editorDrawableContainer->Draw();
}

void EditorState::SetSelectedEntity() {
	if (selectedEntity) {
		delete selectedEntity; //this one is important probably hehe
		selectedEntity = nullptr; //just in case
	}

	selectedEntity = new BareEntity();
	selectedEntity->Init(0, 0, 0, EntityState::DEFAULT, entityTypeList->at(scroll), behaviourFactory, editorDrawableContainer);
}