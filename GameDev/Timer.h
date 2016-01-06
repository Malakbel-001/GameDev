#pragma once
#include "SDL.h"

class Timer {
	private:
		Uint32 timeLapsedMilliSeconds;
		Uint32 previousTicks;

	public:
		Timer();
		~Timer();
		void ResumeTimer();
		void CalcDifference();
		int GetCurrentMinutes();
		int GetCurrentSeconds();

};