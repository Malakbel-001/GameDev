#include "Timer.h"

Timer::Timer() {
	timeLapsedMilliSeconds = 0;
}

Timer::~Timer() {
	//nothing
}

void Timer::AddDeltaTime(float dt) {
	timeLapsedMilliSeconds += dt;
}

int Timer::GetCurrentMinutes() {
	return (int)(timeLapsedMilliSeconds / 1000) / 60;
}

int Timer::GetCurrentSeconds() {
	return (int)(timeLapsedMilliSeconds / 1000) % 60;
}