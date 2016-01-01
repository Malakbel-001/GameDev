#include "IGameState.h"

class EditorState :	public IGameState {
	private:


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
		void Update(float);
		void Draw();


};