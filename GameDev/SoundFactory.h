#pragma once
#include "SDL_mixer.h"

class SoundFactory {
public:
	static void SetNextBGM(Mix_Music *bgm);
	static void SetSoundEffect(Mix_Chunk *soundEffect);
	static void LoopSoundEffect(Mix_Chunk *soundEffect);
	static void StopLoopingSoundEffect(Mix_Chunk *soundEffect);
private:
	//static Mix_Music *current_bgm;
	//std::unordered

	SoundFactory();
	~SoundFactory();
};