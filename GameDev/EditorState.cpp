#include "EditorState.h"

EditorState::EditorState() {
	newLevel = LevelFactory::GetEmptyLevel();
	editorDrawableContainer = new DrawableContainer();
}

EditorState::~EditorState() {

}

void EditorState::Cleanup() {

}

void EditorState::Init(GameStateManager *gsm) {
	behaviourFactory = gsm->GetBehaviour(); //need this to create (temporary) drawableBehaviours

	newLevel->SetEntityFactory(gsm->GetBehaviour());
	actorTypeList = newLevel->GetEntityFactory()->GetActorTypeList();
	entityTypeList = newLevel->GetEntityFactory()->GetEntityTypeList();

	manualCamera = behaviourFactory->SetManualCamera(newLevel->GetLvlWidth(), newLevel->GetLvlHeight());

	selectedEntity = new BareEntity();
	selectedEntity->Init(0, 0, 0, EntityState::DEFAULT, entityTypeList->at(0), behaviourFactory, editorDrawableContainer);
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
			break;
		}
		//case scroll
		//scroll entity type list -> drawableBehaviour
		case SDL_MOUSEBUTTONDOWN: {
			//place entity
			break;
		}
	}

}

void EditorState::HandleKeyEvents(std::unordered_map<SDL_Keycode, bool>* _events) {
	//move camera using arrowkeys

	
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