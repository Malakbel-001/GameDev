#include "Timer.h"
#include <iostream> //temp

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

void Timer::CalcDifference() {
	timeLapsedMilliSeconds += SDL_GetTicks() - previousTicks;
	previousTicks = SDL_GetTicks();

	std::cout << timeLapsedMilliSeconds << std::endl;
}

int Timer::GetCurrentMinutes() {
	return (timeLapsedMilliSeconds / 1000) / 60;
}

int Timer::GetCurrentSeconds() {
	return (timeLapsedMilliSeconds / 1000) % 60;
}