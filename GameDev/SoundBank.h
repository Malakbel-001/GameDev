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

	int musicVolume = 64; // [0 - 128]
	int sfxVolume = 64; // [0 - 128]
	bool musicEnabled;
	bool sfxEnabled;
public:
	~SoundBank();
	static SoundBank* GetInstance();

	void Play(SoundEffectType type);
	void PlayBGM(SoundBgmType type); //TODO
	void PauseOrResume();
	void StopMusic(); //arguably not needed
	void FreeMemory();

	/*void SetMusicVolume(int newVolume);
	void SetSfxVolume(int newVolume);*/
	void DisableOrEnableMusic();
	bool IsEnabledMusic();
	void DisableOrEnableSFX();
	bool IsEnabledSFX();
};