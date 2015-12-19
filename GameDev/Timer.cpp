#include "Timer.h"

Timer::Timer() {
	timeLapsedMilliSeconds = 0;
	previousTicks = SDL_GetTicks();
}

Timer::~Timer() {
	//nothing
}

void Timer::ResumeTimer() {
	previousTicks = SDL_GetTicks();
}

void Timer::CalcDifference(float dt) {
	timeLapsedMilliSeconds += dt;
	
	/*timeLapsedMilliSeconds += SDL_GetTicks() - previousTicks;
	previousTicks = SDL_GetTicks();*/
}

int Timer::GetCurrentMinutes() {
	return (int)(timeLapsedMilliSeconds / 1000) / 60;
}

int Timer::GetCurrentSeconds() {
	return (int)(timeLapsedMilliSeconds / 1000) % 60;
}