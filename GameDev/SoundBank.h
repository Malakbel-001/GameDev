#pragma once
#include <SDL.h>
#include <SDL_mixer.h>
#include <unordered_map>
#include "SoundEffectType.h"
#include "SoundBgmType.h"
#include "SoundChunk.h"
#include <iostream>
#include <string>

class SoundBank {
private:
	SoundBank();
	std::unordered_map<SoundEffectType, char*> soundPathList;
	std::unordered_map<SoundBgmType, char*> bgmPathList;
	std::unordered_map<SoundEffectType, SoundChunk*> playingChunks;
	static SoundBank* instance;
public:
	~SoundBank();
	static SoundBank* GetInstance();

	void Play(SoundEffectType type, int volume);
	void PlayBGM(SoundBgmType type, int volume); //TODO
	void PauseOrResume();
	void StopMusic(); //arguably not needed
	void FreeMemory();
};