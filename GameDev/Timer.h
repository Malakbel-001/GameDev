#pragma once
#include "SDL.h"

class Timer {
	private:
		float timeLapsedMilliSeconds;

	public:
		Timer();
		~Timer();
		void AddDeltaTime(float dt);
		int GetCurrentMinutes();
		int GetCurrentSeconds();

};