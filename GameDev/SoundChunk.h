#pragma once
#include "SDL_mixer.h"

class SoundChunk {
private:
	Mix_Chunk* chunk;
	int* channel;
public:
	SoundChunk(Mix_Chunk* newChunk);
	~SoundChunk();

	void Play();

	int* GetChannel();
	//void SetChannel(int* newChannel);
};