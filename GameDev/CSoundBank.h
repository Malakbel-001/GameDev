#ifndef _CSOUNDBANK_H_
#define _CSOUNDBANK_H_

#pragma once
#include <SDL.h>
#include <SDL_mixer.h>
#include <vector>

class CSoundBank {
public:
	static CSoundBank           SoundControl;

	CSoundBank();

	int OnLoad(char* file);

	void OnCleanup();

	void Play(int ID);

	void PlayBGM(char* file);

	Mix_Music*					currentBGM; //TODO set to private somehow?
private:
	std::vector<Mix_Chunk*>     soundList;
};

#endif