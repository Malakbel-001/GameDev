#pragma once
#include "IGameState.h"
#include "LevelFactory.h"
#include <vector>

class EditorState :	public IGameState {
	private:
		float Ratio = 1.0F / 10.0F; //TODO!!!

		Level* newLevel;
		BehaviourFactory* behaviourFactory;
		Camera* manualCamera;

		Uint32 lockButtonTicks;

		//not sure if to save this
		int hoverX;
		int hoverY;

		int scroll;

		std::vector<EntityType>* actorTypeList;
		std::vector<EntityType>* entityTypeList;

		DrawableContainer* editorDrawableContainer;
		BareEntity* selectedEntity;

	public:
		EditorState();
		~EditorState();

		void Init(GameStateManager *gsm);
		void Cleanup();

		void Pause();
		void Resume();

		void HandleMouseEvents(SDL_Event mainEvent);
		void HandleKeyEvents(std::unordered_map<SDL_Keycode, bool>* _events);
		void HandleTextInputEvents(SDL_Event event);
		void Update(float dt, float gameSpeedManipulator);
		void Draw(float dt, float gameSpeedManipulator);

	private:
		void SetSelectedEntity();

};