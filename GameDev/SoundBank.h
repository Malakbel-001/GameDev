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

	const int musicVolume = 64; // [0 - 128]
	const int sfxVolume = 64; // [0 - 128]
	bool musicEnabled = true;
	bool sfxEnabled = true;
	SoundBgmType currentBGM;
public:
	~SoundBank();
	static SoundBank* GetInstance();

	void Play(SoundEffectType type);
	void PlayBGM(SoundBgmType type);
	void PauseOrResume();
	void StopMusic(); //arguably not needed
	void FreeMemory();

	void ToggleMusic();
	bool IsEnabledMusic();
	void ToggleSFX();
	bool IsEnabledSFX();
};