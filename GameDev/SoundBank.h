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
	std::string* checkValidPath(char* path); //error handling something
	std::unordered_map<SoundEffectType, SoundChunk*> playingChunks;
	static SoundBank* instance;


	//std::vector<Mix_Chunk*>     soundList;
	/*std::unordered_map<SoundEffectType, Sound>	soundList;
	std::unordered_map<SoundBgmType, Sound>		soundBGMList;*/
	

public:
	~SoundBank();
	static SoundBank* getInstance();
	void Play(SoundEffectType type);
	void PlayBGM(char* file); //TODO
	void FreeMemory();

	//CSoundBank();

	/*void OnLoad(SoundEffectType type);
	void OnCleanup();*/





};