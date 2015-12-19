#pragma once
#include "SDL.h"

class Timer {
	private:
		//Uint32 timeLapsedMilliSeconds;
		float timeLapsedMilliSeconds;
		Uint32 previousTicks;

	public:
		Timer();
		~Timer();
		void ResumeTimer();
		void CalcDifference(float dt);
		int GetCurrentMinutes();
		int GetCurrentSeconds();

};