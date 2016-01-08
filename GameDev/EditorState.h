#pragma once
#include "IGameState.h"
#include "LevelFactory.h"
#include <vector>

class EditorState :	public IGameState {
	private:
		float ratio = 1.0F / 10.0F; //magic numberino, TODO -> smarter solution.

		Level* newLevel;
		std::string loadLevel = ""; // equivalent of NULL I guess
		BehaviourFactory* behaviourFactory;
		Camera* manualCamera;

		Uint32 lockButtonTicks;

		int screenWidth = 1080; //temp!!! TODO

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
		EditorState(int level);
		EditorState(std::string loadLevel);

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
		float GetXPositionEntity();
		float GetYPositionEntity();
};