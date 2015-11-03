#pragma once
#include <SDL.h>
#include <SDL_mixer.h>
#include <unordered_map>
#include "SoundEffectType.h"
#include "SoundBgmType.h"
#include "SoundChunk.h"

class SoundBank {
private:
	SoundBank();
	std::unordered_map<SoundEffectType, char*> soundPathList;
	std::unordered_map<SoundBgmType, char*> bgmPathList;
	std::unordered_map<SoundEffectType, SoundChunk*> playingChunks;
	static SoundBank* instance;

	//Mix_Chunk currentlyPlaying;
public:
	~SoundBank();
	static SoundBank* getInstance();
	void Play(SoundEffectType type);
	void PlayBGM(SoundBgmType type); //TODO
	void FreeMemory();
};